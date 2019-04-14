#include "moneybox.h"

#include <nlohmann/json.hpp>

#include "rpc.h"
#include "controller/controller.h"

namespace json = nlohmann;

namespace api {

void MoneyBox::execute(Rpc& rpc) {
    auto controller = factory_.create(rpc.name());
    auto request = json::json::parse(rpc.request());
    std::string response = controller->execute(request).dump();
    rpc.response(response);
}

}  // namespace api
