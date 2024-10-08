cmake_minimum_required(VERSION 3.14)
project(3DViewer_v2.0)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -Wpedantic -std=c++17 -g -O0 --coverage")

file(GLOB TEST_SRC CONFIGURE_DEPENDS "tests/*.h" "tests/*.cpp")

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.13.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  model_test
  ${TEST_SRC}
)

target_link_libraries(
  model_test
  ${CMAKE_SOURCE_DIR}/libs/s21_3dviewer.a
  GTest::gtest
)

target_link_options(model_test PRIVATE "--coverage")

include(GoogleTest)
gtest_discover_tests(model_test)
