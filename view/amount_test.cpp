#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "amount.h"

using ::testing::Eq;

namespace view {

TEST(AmountTest, Render) {
    Amount view;
    view.amount = 999777333;
    EXPECT_THAT(view.render().dump(),
                Eq(std::string{R"({"amount":999777333})"}));
}

}  // namespace view
