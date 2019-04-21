#ifndef MODEL_MOCK_FACTORY_H
#define MODEL_MOCK_FACTORY_H

#include <gmock/gmock.h>

#include "db/factory.h"

namespace model {

class MockFactory : public db::Factory {
public:
  MOCK_METHOD0(query, db::QueryPtr());
  MOCK_METHOD0(command, db::CommandPtr());
};

}  // namespace model

#endif // MODEL_MOCK_FACTORY_H
