#ifndef MODEL_USER_H
#define MODEL_USER_H

#include "field.h"
#include "entity.h"

namespace model {

class User : public Entity {
public:
    User() : Entity("user") {}
    Integer id{"id", this};
    Text name{"name", this};
    LongLong amount{"amount", this};
};

}  // namespace model

#endif // MODEL_USER_H
