#ifndef API_API_H
#define API_API_H

namespace api {

class Rpc;

class Api {
public:
    virtual void execute(Rpc& rpc) const = 0;
    virtual ~Api() = default;
};

}  // namespace api

#endif // API_API_H
