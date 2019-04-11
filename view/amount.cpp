#include "amount.h"

namespace view {

json::json Amount::render() {
    return {{"amount", amount }};
}

}  // namespace view
