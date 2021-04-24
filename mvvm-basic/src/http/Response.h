//
// Created by HANYOUNG PARK on 4/15/21.
//

#ifndef MVVM_BASIC_RESPONSE_H
#define MVVM_BASIC_RESPONSE_H
#include <string>
#include <unordered_map>

namespace http {
    class Response {
    public:
        Response(int httpCode, std::unordered_map<std::string, std::string> headers,std::string body);
        auto getHttpCode() -> int;
        auto getHeader(const std::string& key) -> std::string;
        auto getBody() -> std::string;

    private:
        int httpCode;
        std::unordered_map<std::string, std::string> headers;
        std::string body;
    };
}


#endif //MVVM_BASIC_RESPONSE_H
