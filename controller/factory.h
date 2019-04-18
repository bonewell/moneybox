#ifndef FACTORY_H
#define FACTORY_H

#include <memory>
#include <string_view>

namespace controller {

class Controller;
using ControllerPtr = std::unique_ptr<Controller>;

class Factory
{
public:
    ControllerPtr create(std::string_view name) const;
};

}  // namespace controller

#endif // FACTORY_H
