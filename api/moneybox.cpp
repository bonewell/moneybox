#include "moneybox.h"

#include <nlohmann/json.hpp>

#include "rpc.h"
#include "controller/controller.h"

namespace json = nlohmann;

namespace api {

void MoneyBox::execute(Rpc& rpc) const {
    auto controller = factory_.create(rpc.name());
    if (controller) {
        auto request = json::json::parse(rpc.request());
        std::string response = controller->execute(request).dump();
        rpc.response(response);
    } else {
        rpc.error(404);
    }
}

}  // namespace api
