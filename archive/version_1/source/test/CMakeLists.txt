
include(GoogleTest)

add_executable(mandelbrot_test "mandelbrot_test.cpp")

target_link_libraries(mandelbrot_test
    PRIVATE
        GTest::gtest
        GTest::gtest_main
)

gtest_add_tests(TARGET mandelbrot_test)
