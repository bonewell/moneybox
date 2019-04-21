#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "field.h"
#include "mock_command.h"
#include "mock_factory.h"
#include "mock_query.h"
#include "testing_entity.h"

using ::testing::_;
using ::testing::ByMove;
using ::testing::Eq;
using ::testing::NiceMock;
using ::testing::Return;
using ::testing::SetArgReferee;
using ::testing::Test;

namespace model {

class EntityTest : public Test {
public:
    void SetUp() override {
        factory = new NiceMock<MockFactory>{};
        TestingEntity::factory_ = gsl::make_not_null(factory);
        entity = TestingEntity{"test"};
    }
    void TearDown() override {
        delete factory;
    }
    TestingEntity entity{"test"};
    MockFactory* factory{nullptr};
};

TEST_F(EntityTest, GetCommand) {
    auto* command = new NiceMock<MockCommand>{};
    EXPECT_CALL(*factory, command())
            .WillOnce(Return(ByMove(db::CommandPtr{command})));
    entity.save();
}

TEST_F(EntityTest, SetEntityOfCommand) {
    auto* command = new NiceMock<MockCommand>{};
    ON_CALL(*factory, command())
            .WillByDefault(Return(ByMove(db::CommandPtr{command})));

    EXPECT_CALL(*command, entity("test"));
    entity.save();
}

TEST_F(EntityTest, SetConditionOfCommand) {
    Integer id{"id", &entity}; id = 2;

    auto* command = new NiceMock<MockCommand>{};
    ON_CALL(*factory, command())
            .WillByDefault(Return(ByMove(db::CommandPtr{command})));

    entity.fetched_ = true;
    db::Variant value = int32_t{2};
    EXPECT_CALL(*command, where("id", value));
    entity.save();
}

TEST_F(EntityTest, SetFieldOfDocument) {
    Integer id{"id", &entity}; id = 3;

    auto* command = new NiceMock<MockCommand>{};
    ON_CALL(*factory, command())
            .WillByDefault(Return(ByMove(db::CommandPtr{command})));

    db::Variant value = int32_t{3};
    EXPECT_CALL(*command, set("id", value));
    entity.save();
}

TEST_F(EntityTest, ExecuteCommand) {
    auto* command = new NiceMock<MockCommand>{};
    ON_CALL(*factory, command())
            .WillByDefault(Return(ByMove(db::CommandPtr{command})));

    EXPECT_CALL(*command, execute());
    entity.save();
}

TEST_F(EntityTest, GetQuery) {
    auto* query = new NiceMock<MockQuery>{};
    EXPECT_CALL(*factory, query())
            .WillOnce(Return(ByMove(db::QueryPtr{query})));;
    entity.fetch(Integer{"id", &entity});
}

TEST_F(EntityTest, SetEntityOfQuery) {
    auto* query = new NiceMock<MockQuery>{};
    ON_CALL(*factory, query())
            .WillByDefault(Return(ByMove(db::QueryPtr{query})));

    EXPECT_CALL(*query, entity("test"));
    entity.fetch(Integer{"id", &entity});
}

TEST_F(EntityTest, SetConditionOfQuery) {
    Integer id{"id", &entity};

    auto* query = new NiceMock<MockQuery>{};
    ON_CALL(*factory, query())
            .WillByDefault(Return(ByMove(db::QueryPtr{query})));

    db::Variant value = int32_t{5};
    EXPECT_CALL(*query, where("id", value));
    entity.fetch(id = 5);
}

TEST_F(EntityTest, ExecuteQuery) {
    auto* query = new NiceMock<MockQuery>{};
    ON_CALL(*factory, query())
            .WillByDefault(Return(ByMove(db::QueryPtr{query})));

    EXPECT_CALL(*query, execute());
    entity.fetch(Integer{"id", &entity});
}

TEST_F(EntityTest, GetFieldOfDocument) {
    Integer id{"id", &entity};

    auto* query = new NiceMock<MockQuery>{};
    ON_CALL(*factory, query())
            .WillByDefault(Return(ByMove(db::QueryPtr{query})));
    ON_CALL(*query, execute()).WillByDefault(Return(true));
    ON_CALL(*query, next()).WillByDefault(Return(true));

    db::Variant value = int32_t{3};
    EXPECT_CALL(*query, get("id", _)).WillOnce(SetArgReferee<1>(value));
    entity.fetch(id = 5);
    EXPECT_THAT(id, Eq(3));
}

TEST_F(EntityTest, NoInvokeGetFieldIfDocumentIsNotFound) {
    auto* query = new NiceMock<MockQuery>{};
    ON_CALL(*factory, query())
            .WillByDefault(Return(ByMove(db::QueryPtr{query})));
    ON_CALL(*query, execute()).WillByDefault(Return(false));

    EXPECT_CALL(*query, get(_, _)).Times(0);
    entity.fetch(Integer{"id", &entity});
}
}  // namespace model
