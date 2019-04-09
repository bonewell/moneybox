#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/pool.hpp>

#include "mongoquery.h"

using ::testing::Eq;
using ::testing::Test;

namespace model::db {

static mongocxx::instance instance;

class MongoQueryTest : public Test {
public:
    mongocxx::pool pool{mongocxx::uri{}};
    mongocxx::database db;
    void SetUp() override {
        db = pool.acquire()->database("moneybox_test");
        auto collection = db["user_test"];
        auto builder = bsoncxx::builder::stream::document{};
        bsoncxx::document::value document = builder
                << "name" << "Bone"
                << "i32" << int32_t{3}
                << "i64" << int64_t{5'000'000'000}
                << "ss433" << "Text"
                << bsoncxx::builder::stream::finalize;
        collection.insert_one(std::move(document));
    }
    void TearDown() override {
        pool.acquire()->database("moneybox_test").drop();
    }
};

TEST_F(MongoQueryTest, FindDocument) {
    MongoQuery query{std::move(db)};
    query.entity("user_test");
    query.where("name", "Bone");
    EXPECT_THAT(query.execute(), Eq(true));
}

TEST_F(MongoQueryTest, GetInt32) {
    MongoQuery query{std::move(db)};
    query.entity("user_test");
    query.where("name", "Bone");
    query.execute();
    Variant i32 = int32_t{};
    query.get("i32", i32);
    EXPECT_THAT(std::get<int32_t>(i32), Eq(3));
}

TEST_F(MongoQueryTest, GetInt64) {
    MongoQuery query{std::move(db)};
    query.entity("user_test");
    query.where("name", "Bone");
    query.execute();
    Variant i64 = int64_t{};
    query.get("i64", i64);
    EXPECT_THAT(std::get<int64_t>(i64), Eq(5'000'000'000));
}

TEST_F(MongoQueryTest, GetString) {
    MongoQuery query{std::move(db)};
    query.entity("user_test");
    query.where("name", "Bone");
    query.execute();
    Variant ss433 = std::string{};
    query.get("ss433", ss433);
    EXPECT_THAT(std::get<std::string>(ss433), Eq("Text"));
}

}  // namespace model::db
