#ifndef MODEL_DB_QUERY_H
#define MODEL_DB_QUERY_H

namespace model::db {

class Query {
public:
    virtual void where() = 0;
    virtual void get() = 0;
    virtual void execute() = 0;
    virtual ~Query() = default;
};

}  // namespace model::db

#endif // MODEL_DB_QUERY_H
