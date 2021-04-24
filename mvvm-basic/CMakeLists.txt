cmake_minimum_required(VERSION 3.17)
project(mvvm_basic)

set(CMAKE_CXX_STANDARD 20)
set(CONAN_CMAKE_CXX_STANDARD 20)

if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()

add_executable(mvvm_basic main.cpp APIService.cpp APIService.h src/APIService.cpp src/APIService.h src/http/HttpClient.cpp src/http/HttpClient.h src/http/Request.cpp src/http/Request.h src/http/Response.cpp src/http/Response.h)
target_link_libraries(mvvm_basic ${CONAN_LIBS})
