#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <mongocxx/client.hpp>
#include <mongocxx/cursor.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/pool.hpp>

#include "mongocommand.h"

using ::testing::Eq;
using ::testing::Test;

namespace model::db {
class MongoCommandTest : public Test {
public:
    mongocxx::pool pool{mongocxx::uri{}};
    mongocxx::database db() {
        return pool.acquire()->database("moneybox_test");
    }
    void TearDown() override {
        pool.acquire()->database("moneybox_test").drop();
    }
};

TEST_F(MongoCommandTest, SetInt32) {
    MongoCommand command{db()};
    command.entity("test_document");
    command.set("i32", Variant{int32_t{5}});
    command.execute();
    auto res = *db()["test_document"].find({}).begin();
    EXPECT_THAT(res["i32"].get_int32(), Eq(5));
}

TEST_F(MongoCommandTest, SetInt64) {
    MongoCommand command{db()};
    command.entity("test_document");
    command.set("i64", Variant{int64_t{5'000'000'000}});
    command.execute();
    auto res = *db()["test_document"].find({}).begin();
    EXPECT_THAT(res["i64"].get_int64(), Eq(5'000'000'000));
}

TEST_F(MongoCommandTest, SetString) {
    MongoCommand command{db()};
    command.entity("test_document");
    command.set("ss433", Variant{std::string{"Text"}});
    command.execute();
    auto res = *db()["test_document"].find({}).begin();
    EXPECT_THAT(res["ss433"].get_utf8().value.to_string(), Eq("Text"));
}
}  // namespace model::db
