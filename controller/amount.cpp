#include "amount.h"

#include "model/user.h"

namespace controller {

json::json Amount::execute(const json::json& input) {
    model::User user;
    user.fetch(user.name = input["user"]);
    view_.amount = user.amount;
    return view_.render();
}

}  // namespace controller
