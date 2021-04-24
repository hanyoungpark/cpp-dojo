//
// Created by HANYOUNG PARK on 4/15/21.
//

#include "Response.h"

#include <utility>

using namespace http;

Response::Response(int httpCode, std::unordered_map<std::string, std::string> headers, std::string body):
    httpCode(httpCode),
    headers(std::move(headers)),
    body(std::move(body)) {
}

auto Response::getHeader(const std::string &key) -> std::string {
    if (!headers.contains(key)) {
        return nullptr;
    }
    return headers[key];
}

auto Response::getBody() -> std::string {
    return body;
}
