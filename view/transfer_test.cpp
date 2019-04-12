#include <gtest/gtest.h>

#include "transfer.h"

namespace view {

TEST(TransferTest, Render) {
    Transfer view;
    view.transfers.push_back({1, "me", "someone", 1000, "present"});
    view.transfers.push_back({2, "someone", "me", 10000, "salary"});
    auto expect = R"([
        {"id":1,"sender":"me","recipient":"someone","amount":1000,"description":"present"},
        {"id":2,"sender":"someone","recipient":"me","amount":10000,"description":"salary"}])"_json;
    EXPECT_TRUE(view.render() == expect);
}

}  // namespace view
