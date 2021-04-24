//
// Created by HANYOUNG PARK on 4/15/21.
//

#include "Request.h"

#include <utility>

using namespace http;

Request::Request(std::string url, HttpMethod method): url(std::move(url)), method(method) {
}

auto Request::addHeader(const std::string& key, std::string value) -> void {
    headers[key] = std::move(value);
}

auto Request::addField(const std::string& key, std::string value) -> void {
    fields[key] = std::move(value);
}
