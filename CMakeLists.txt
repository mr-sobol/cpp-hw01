cmake_minimum_required(VERSION 3.10)

# set travis-ci build to 10000 if not defined
if(NOT DEFINED ENV{TRAVIS_BUILD_NUMBER})
    set(ENV{TRAVIS_BUILD_NUMBER} 10000)
endif()

# set the project name and version
project(otus-homework-01
    VERSION 0.5.$ENV{TRAVIS_BUILD_NUMBER}
)

# find packages
find_package(Boost
    REQUIRED
    COMPONENTS unit_test_framework
)

# configure a header file to pass the version number
configure_file(version.h.in version.h)

# add main executable
add_executable(helloworld src/main.cpp)

# specify version header file dir
target_include_directories(helloworld
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
)

# add unit tests executable
add_executable(unit_tests test/version.cpp)

# specify include dirs
target_include_directories(unit_tests
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
    PRIVATE ${Boost_INCLUDE_DIRS}
)

# specify linked libs
target_link_libraries(unit_tests ${Boost_LIBRARIES})

# specify install dir
install(TARGETS helloworld DESTINATION bin)

# enable testing support
enable_testing()

# enable unit tests
add_test(NAME Unit-Tests COMMAND unit_tests)

# cpack
set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_NAME helloworld)
set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
set(CPACK_PACKAGE_CONTACT "dengaleev at github.com")
set(CPACK_RESOURCE_FILE_LICENSE ${CMAKE_CURRENT_SOURCE_DIR}/LICENSE)
include(CPack)
