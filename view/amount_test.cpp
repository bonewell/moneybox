#include <gtest/gtest.h>

#include "amount.h"

namespace view {

TEST(AmountTest, Render) {
    Amount view;
    view.amount = 999777333;
    auto expect = R"({"amount" : 999777333})"_json;
    EXPECT_TRUE(view.render() == expect);
}

}  // namespace view
