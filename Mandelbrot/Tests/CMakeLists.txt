
enable_testing()

# Add the test executable
add_executable(MandelbrotTests MandelbrotTests.cpp)

target_link_libraries(MandelbrotTests
    PRIVATE
        GTest::gtest
        GTest::gtest_main
)
