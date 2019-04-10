#ifndef MODEL_ENTITY_H
#define MODEL_ENTITY_H

#include <string>
#include <string_view>
#include <vector>

#include <gsl/gsl>

namespace model {

namespace db {
class Factory;
}  // namespace db

class BaseField;

class Entity {
public:
    explicit Entity(std::string_view name) : name_{name} {}
    void save();
    bool fetch(const BaseField& condition);
protected:
    static gsl::not_null<db::Factory*> factory_;
    void registry(gsl::not_null<BaseField*> field);
private:
    std::string name_;
    std::vector<gsl::not_null<BaseField*>> fields_;

    friend class BaseField;
};

}  // namespace model

#endif // MODEL_ENTITY_H
