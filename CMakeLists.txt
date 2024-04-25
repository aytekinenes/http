cmake_minimum_required(VERSION 3.0)
project(myHttp)

# Curl kütüphanesini bulma
find_package(CURL REQUIRED)

# Projenize başlık dosyalarını ve kütüphane bağlantısını ekleme
include_directories(${CURL_INCLUDE_DIR})
add_executable(myHttp main.cpp)
target_link_libraries(myHttp ${CURL_LIBRARIES})
