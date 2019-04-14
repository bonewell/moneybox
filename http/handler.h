#ifndef HTTP_HANDLER_H
#define HTTP_HANDLER_H

#include <string>

#include "api/rpc.h"

namespace http {

class Handler : public api::Rpc {
public:
    const std::string& name() override {
        return name_;
    }
    const std::string& request() override {
        return request_;
    }
    void response(const std::string& response) override {
        response_ = response;
    }
    void name(const std::string& name) {
        name_ = name;
    }
    void request(const std::string& request) {
        request_ = request;
    }
    const std::string& response() {
        return response_;
    }

private:
    std::string name_;
    std::string request_;
    std::string response_;
};

}  // namespace http

#endif // HTTP_HANDLER_H
