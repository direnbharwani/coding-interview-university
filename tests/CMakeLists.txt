# Include the src directory to find headers
include_directories(${CMAKE_SOURCE_DIR}/src)

set( TEST_SOURCES
     main.cpp
     test_dynamicArray.cpp
)

add_executable(UnitTests ${TEST_SOURCES})

# Link the executable against Google Test and your interface library
target_link_libraries(UnitTests PRIVATE gtest gtest_main CIU)

add_test(NAME UnitTests COMMAND UnitTests)

