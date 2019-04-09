#ifndef MODEL_MOCK_COMMAND_H
#define MODEL_MOCK_COMMAND_H

#include <gmock/gmock.h>

#include "db/command.h"

namespace model {

class MockCommand : public db::Command {
 public:
  MOCK_METHOD1(entity, void(const std::string& name));
  MOCK_METHOD2(set, void(const std::string& name, const db::Variant& value));
  MOCK_METHOD0(execute, void());
};

}  // namespace model

#endif // MODEL_MOCK_COMMAND_H