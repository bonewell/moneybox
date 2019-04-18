#include "server.h"

#include <restinio/all.hpp>

#include "api/api.h"
#include "handler.h"

namespace http {

Server::Server(const api::Api& api)
    : api_{api} {}

void Server::run() {
    restinio::run(restinio::on_this_thread().port(8080)
                  .request_handler([this](auto request) {
        Handler rpc;
        rpc.name(std::string{request->header().path()});
        rpc.request(request->body());
        api().execute(rpc);
        switch (rpc.error()) {
        case restinio::status_code::ok.raw_code():
            return request->create_response()
                    .set_body(rpc.response()).done();
        case restinio::status_code::not_found.raw_code():
            return request->create_response(restinio::status_not_found())
                    .connection_close().done();
        default:
            return request->create_response(restinio::status_internal_server_error())
                    .connection_close().done();
        }
    }));
}

}  // namespace http
