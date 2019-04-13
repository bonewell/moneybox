#ifndef CONTROLLER_CONTROLLER_H
#define CONTROLLER_CONTROLLER_H

#include <nlohmann/json.hpp>

namespace json = nlohmann;

namespace controller {

class Controller {
public:
    virtual json::json execute(const json::json& input) = 0;
    virtual ~Controller() = default;
};

}  // namespace controller

#endif // CONTROLLER_CONTROLLER_H
