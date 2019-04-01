#ifndef MODEL_TRANSFER_H
#define MODEL_TRANSFER_H

#include "field.h"
#include "table.h"

namespace model {

class Transfer : public Table {
public:
    Integer id{"id", this};
    Integer sender{"sender", this};
    Integer recipient{"recipient", this};
    LongLong amount{"amount", this};
    Text description{"description", this};
};

}  // namespace model

#endif // MODEL_TRANSFER_H
