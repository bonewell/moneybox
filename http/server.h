#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H

#include "api/api.h"

namespace http {

class Server {
public:
    explicit Server(const api::Api& api);
    void run();
    const api::Api& api() const { return api_; }

private:
    const api::Api& api_;
};

}  // namespace http

#endif // HTTP_SERVER_H
