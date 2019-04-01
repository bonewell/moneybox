#ifndef MODEL_TABLE_H
#define MODEL_TABLE_H

#include <vector>

namespace model {

class BaseField;

class Table {
public:
    void registry(BaseField* field);
    void save();
    void fetch(const BaseField& condition);
private:
    std::vector<BaseField*> fields_;
};

}  // namespace model

#endif // MODEL_TABLE_H
