#include "server.h"

#include <restinio/all.hpp>

namespace http {

Server::Server(const api::Api& api)
    : api_{api} {}

void Server::run() {
    // TODO
}

}  // namespace http
