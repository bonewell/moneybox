#include <gtest/gtest.h>

#include "transfersend.h"

namespace view {

TEST(TransferSendTest, Render) {
    TransferSend view;
    view.result = true;
    auto expect = R"({"result":true})"_json;
    EXPECT_TRUE(view.render() == expect);
}

}  // namespace view
