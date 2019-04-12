#ifndef TRANSFERSEND_H
#define TRANSFERSEND_H

#include "view.h"

namespace view {

struct TransferSend : public View {
    bool result;
    json::json render() override;
};

}  // namespace view

#endif // TRANSFERSEND_H
