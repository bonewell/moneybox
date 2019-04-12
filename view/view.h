#ifndef VIEW_VIEW_H
#define VIEW_VIEW_H

#include <nlohmann/json.hpp>

namespace json = nlohmann;

namespace view {

class View {
public:
    virtual json::json render() = 0;
    virtual ~View() = default;
};
}  // namespace view

#endif // VIEW_VIEW_H
