#ifndef MODEL_TESTING_ENTITY_H
#define MODEL_TESTING_ENTITY_H

#include "entity.h"

namespace model {

class TestingEntity : public Entity {
public:
    using Entity::factory_;
    using Entity::Entity;
    using Entity::registry;
};

}  // namespace model

#endif // MODEL_TESTING_ENTITY_H
