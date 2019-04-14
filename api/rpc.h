#ifndef API_RPC_H
#define API_RPC_H

#include <string>

namespace api {

class Rpc {
public:
    virtual const std::string& name() = 0;
    virtual const std::string& request() = 0;
    virtual void response(const std::string& response) = 0;
    virtual ~Rpc() = default;
};

}  // namespace api

#endif // API_RPC_H
