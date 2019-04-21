#include "server.h"

#include <restinio/all.hpp>

#include "api/api.h"
#include "handler.h"

namespace {
restinio::http_status_line_t getStatus(int code) {
    switch (code) {
    case restinio::status_code::ok.raw_code():
        return restinio::status_ok();
    case restinio::status_code::not_found.raw_code():
        return restinio::status_not_found();
    case restinio::status_code::internal_server_error.raw_code():
    default:
        return restinio::status_internal_server_error();
    }
}
}  // namespace

namespace http {

Server::Server(const api::Api& api)
    : api_{api} {}

void Server::run() {
    restinio::run(restinio::on_this_thread().port(8080)
                  .request_handler([this](auto request) {
        Handler rpc;
        rpc.name(std::string{request->header().path()});
        rpc.request(request->body());
        try {
            api().execute(rpc);
        } catch(const std::exception& error) {
            std::cerr << error.what() << "\n";
            rpc.error(500);
        }

        auto status = getStatus(rpc.error());
        auto response = request->create_response(status)
            .append_header(restinio::http_field_t::access_control_allow_origin, "*" )
            .append_header(restinio::http_field_t::access_control_allow_methods, "*")
            .append_header(restinio::http_field_t::access_control_allow_credentials, "true")
            .append_header(restinio::http_field_t::content_type, "application/json");
        if (rpc.error() == restinio::status_code::ok.raw_code()) {
            response.set_body(rpc.response());
        } else {
            response.connection_close();
        }

        return response.done();
    }));
}

}  // namespace http
