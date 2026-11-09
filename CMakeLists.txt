cmake_minimum_required(VERSION 3.16)

project(PersonalFinanceManager LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Collect all header and source files
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

# Define executable target
add_executable(app ${SOURCES} ${HEADERS})

# Include headers directory
target_include_directories(app PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Compiler-specific warning flags to ensure clean and robust code
if(MSVC)
    target_compile_options(app PRIVATE /W4 /permissive-)
else()
    target_compile_options(app PRIVATE -Wall -Wextra -Wpedantic)
endif()