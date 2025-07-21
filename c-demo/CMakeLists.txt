cmake_minimum_required(VERSION 3.15)
project(compressor C)

find_package(ZLIB REQUIRED)
find_package(nlohmann_json)
# find_package(nlohmann_json 3.2.0 REQUIRED)
# find_package(PostgreSQL REQUIRED)

add_executable(${PROJECT_NAME} src/simple.c)

target_link_libraries(${PROJECT_NAME} ZLIB::ZLIB)
target_link_libraries(${PROJECT_NAME} nlohmann_json::nlohmann_json)
# target_link_libraries(hello_world PRIVATE nlohmann_json::nlohmann_json)
# target_link_libraries(${PROJECT_NAME} PostgreSQL::PostgreSQL)

