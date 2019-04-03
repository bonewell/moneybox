#ifndef MODEL_DB_QUERY_H
#define MODEL_DB_QUERY_H

namespace model {
class BaseField;
}  // namespace model

namespace model::db {

class Query {
public:
    virtual void where(const BaseField* condition) = 0;
    virtual void get(BaseField* field) = 0;
    virtual void execute() = 0;
    virtual ~Query() = default;
};

}  // namespace model::db

#endif // MODEL_DB_QUERY_H
