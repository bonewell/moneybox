#ifndef QUERY_H
#define QUERY_H

namespace model::db {

class Query {
public:
    virtual void where() = 0;
    virtual void get() = 0;
    virtual void execute() = 0;
    virtual ~Query() = default;
};

}  // namespace model::db

#endif // QUERY_H
