#ifndef MODEL_MOCK_QUERY_H
#define MODEL_MOCK_QUERY_H

#include <gmock/gmock.h>

#include "db/query.h"

namespace model {

class MockQuery : public db::Query {
 public:
  MOCK_METHOD1(entity, void(const std::string& name));
  MOCK_METHOD2(where, void(const std::string& name, const db::Variant& condition));
  MOCK_METHOD2(get, void(const std::string& name, db::Variant& value));
  MOCK_METHOD0(execute, bool());
};

}  // namespace model

#endif // MODEL_MOCK_QUERY_H
