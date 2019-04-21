#ifndef MODEL_TRANSFER_H
#define MODEL_TRANSFER_H

#include "field.h"
#include "entity.h"

namespace model {

class Transfer : public Entity {
public:
    Transfer() : Entity("transfer") {}
    Text sender{"sender", this};
    Text recipient{"recipient", this};
    LongLong amount{"amount", this};
    Text description{"description", this};
};

}  // namespace model

#endif // MODEL_TRANSFER_H
