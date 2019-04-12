#ifndef VIEW_AMOUNT_H
#define VIEW_AMOUNT_H

#include "view.h"

namespace view {

struct Amount : public View {
    long long amount;
    json::json render() override;
};

}  // namespace view

#endif // VIEW_AMOUNT_H
