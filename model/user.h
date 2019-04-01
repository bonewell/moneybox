#ifndef MODEL_USER_H
#define MODEL_USER_H

#include "field.h"
#include "table.h"

namespace model {

class User : public Table {
public:
    Integer id{"id", this};
    Text name{"name", this};
    LongLong amount{"amount", this};
};

}  // namespace model

#endif // MODEL_USER_H
