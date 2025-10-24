
include(GoogleTest)

add_executable(mandelbrotset_test "MandelbrotSet/MandelbrotSetTests.cpp")

target_link_libraries(mandelbrotset_test
    PRIVATE
        MandelbrotLib

        GTest::gtest
        GTest::gtest_main
        #GTest::gmock GTest::gmock_main
)

gtest_add_tests(TARGET mandelbrotset_test)
