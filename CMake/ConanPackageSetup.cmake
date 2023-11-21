
# CImg package ( http://cimg.eu/reference/tutorial.html )
conan_cmake_configure(
    REQUIRES
      cimg/3.3.0
    GENERATORS
      cmake_find_package_multi
)

# Each config has to be set up for each package, so we'll loop through each (Debug, Release)
foreach(type ${CMAKE_CONFIGURATION_TYPES})
    message(STATUS "Configuring build type ${type}")
    conan_cmake_autodetect(settings BUILD_TYPE ${type})
    conan_cmake_install(PATH_OR_REFERENCE .
                        BUILD missing
                        REMOTE conancenter
                        SETTINGS ${settings})
endforeach()

# Now call find_package
find_package(CImg CONFIG)
