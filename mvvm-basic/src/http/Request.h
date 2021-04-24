//
// Created by HANYOUNG PARK on 4/15/21.
//

#ifndef MVVM_BASIC_REQUEST_H
#define MVVM_BASIC_REQUEST_H
#include <string>
#include <unordered_map>

namespace http {
    enum HttpMethod {
        Get,
        Post
    };

    class Request {
    public:
        Request(std::string url, HttpMethod method);
        auto addHeader(const std::string& key, std::string value) -> void;
        auto addField(const std::string& key, std::string value) -> void;

    private:
        HttpMethod method;
        std::string url;
        std::unordered_map<std::string, std::string> headers;
        std::unordered_map<std::string, std::string> fields;
    };
};

#endif //MVVM_BASIC_REQUEST_H
