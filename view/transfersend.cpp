#include "transfersend.h"

namespace view {

json::json TransferSend::render() {
    return {{"result", result}};
}

}  // namespace view
