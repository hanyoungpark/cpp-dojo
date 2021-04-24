#include <iostream>
//#include <nlohmann/json.hpp>
//#include <restinio/all.hpp>
#include <fmt/core.h>

//using json = nlohmann::json;
//using namespace restinio;

//template<typename T>
//std::ostream & operator<<(std::ostream & to, const optional_t<T> & v) {
//    if(v) to << *v;
//    return to;
//}

int main() {
//    auto j3 = json::parse(R"({"happy": true, "pi": 3.141})");
//    std::cout << j3 << std::endl;
//
//    restinio::run(
//            restinio::on_this_thread()
//            .port(8080)
//            .address("localhost")
//            .request_handler([](auto req) {
//                return req->create_response().set_body("Hello, World!").done();
//            }));

    fmt::print("Hello, world!\n");

    return 0;
}
