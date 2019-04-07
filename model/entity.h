#ifndef MODEL_ENTITY_H
#define MODEL_ENTITY_H

#include <string>
#include <vector>

namespace model {

namespace db {
class Factory;
}  // namespace db

class BaseField;

class Entity {
public:
    explicit Entity(const std::string& name) : name_{name} {}
    void save();
    bool fetch(const BaseField& condition);
protected:
    static db::Factory& factory_;
private:
    void registry(BaseField* field);
    std::string name_;
    std::vector<BaseField*> fields_;

    friend class BaseField;
};

}  // namespace model

#endif // MODEL_ENTITY_H