include(FetchContent)

FetchContent_Declare(
     googletest
     GIT_REPOSITORY https://github.com/google/googletest.git
     GIT_TAG release-1.11.0
)

FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

# Include the src directory to find headers
include_directories(${CMAKE_SOURCE_DIR}/src)

set(TEST_SOURCES
     main.cpp
     test_dynamicArray.cpp
)

add_executable(UnitTests ${TEST_SOURCES})

# Link the executable against Google Test and your interface library
target_link_libraries(UnitTests PRIVATE GTest::GTest CIU)

add_test(NAME UnitTests COMMAND UnitTests)
