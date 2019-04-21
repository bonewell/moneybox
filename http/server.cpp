#include "server.h"

#include <restinio/all.hpp>

#include "api/api.h"
#include "handler.h"

namespace http {

Server::Server(const api::Api& api)
    : api_{api} {}

void Server::run() {
    restinio::run(restinio::on_this_thread()
                  .address("localhost").port(8080)
                  .request_handler([this](auto request) {
        Handler rpc;
        rpc.name(std::string{request->header().path()});
        rpc.request(request->body());
        try {
            api().execute(rpc);
        } catch(const std::exception& error) {
            std::cerr << error.what() << "\n";
            rpc.error(0);
        }

        switch (rpc.error()) {
        case restinio::status_code::ok.raw_code():
            return request->create_response()
                    .append_header(restinio::http_field_t::access_control_allow_origin, "*" )
                    .append_header(restinio::http_field_t::access_control_allow_methods, "*")
                    .append_header(restinio::http_field_t::access_control_allow_credentials, "true")
                    .append_header(restinio::http_field_t::content_type, "application/json")
                    .set_body(rpc.response()).done();
        case restinio::status_code::not_found.raw_code():
            return request->create_response(restinio::status_not_found())
                    .append_header(restinio::http_field_t::access_control_allow_origin, "*" )
                    .connection_close().done();
        default:
            return request->create_response(restinio::status_internal_server_error())
                    .append_header(restinio::http_field_t::access_control_allow_origin, "*" )
                    .connection_close().done();
        }
    }));
}

}  // namespace http
