#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "transfersend.h"

using ::testing::Eq;

namespace view {

TEST(TransferSendTest, Render) {
    TransferSend view;
    view.result = true;
    EXPECT_THAT(view.render().dump(),
                Eq(std::string{R"({"result":true})"}));
}

}  // namespace view
