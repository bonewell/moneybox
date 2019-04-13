#ifndef MODEL_DB_QUERY_H
#define MODEL_DB_QUERY_H

#include <string>

#include "variant.h"

namespace model::db {

class Query {
public:
    virtual void entity(const std::string& name) = 0;
    virtual void where(const std::string& name, const Variant& condition) = 0;
    virtual void get(const std::string& name, Variant& value) = 0;
    virtual bool execute() = 0;
    virtual bool next() = 0;
    virtual ~Query() = default;
};

}  // namespace model::db

#endif // MODEL_DB_QUERY_H
