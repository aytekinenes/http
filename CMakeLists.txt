cmake_minimum_required(VERSION 3.0)
project(myHttp)

# Curl kutuphanesi
find_package(CURL REQUIRED)


# JSON kutuphanesi
include_directories(include)


# Projeye baslik dosyasi ve kutuphane eklenmesi
include_directories(${CURL_INCLUDE_DIR})
add_executable(myHttp main.cpp)
target_link_libraries(${PROJECT_NAME} ${CURL_LIBRARIES})


# libcurl kutuphanesi
find_package(CURL REQUIRED)
if(CURL_FOUND)
    include_directories(${CURL_INCLUDE_DIR})
    target_link_libraries(myHttp ${CURL_LIBRARIES})
endif()


#sudo apt install libjsoncpp-dev