#ifndef MODEL_ENTITY_H
#define MODEL_ENTITY_H

#include <string>
#include <string_view>
#include <vector>

#include <gsl/gsl>

#include "db/factory.h"

namespace model {

class BaseField;

class Entity {
public:
    explicit Entity(std::string_view name) : name_{name} {}
    bool save();
    bool fetch(const BaseField& condition);
    bool next();

protected:
    static gsl::not_null<db::Factory*> factory_;
    void registry(gsl::not_null<BaseField*> field);
    bool fetched_{false};

private:
    std::string name_;
    std::vector<gsl::not_null<BaseField*>> fields_;
    db::QueryPtr query_;

    friend class BaseField;
};

}  // namespace model

#endif // MODEL_ENTITY_H
