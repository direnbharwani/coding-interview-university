cmake_minimum_required(VERSION 3.10...3.22)
include(FetchContent)

project(coding-interview-university
    VERSION 0.1
    DESCRIPTION "Coding Interview University"
    LANGUAGES CXX
)

# Debugging for CMake
message(STATUS "CMake version: ${CMAKE_VERSION}")
message(STATUS "C++ compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "Compiler ID: ${CMAKE_CXX_COMPILER_ID}")

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)

# option(ENABLE_COVERAGE "Enable coverage reporting" ON)

# if(ENABLE_COVERAGE)
# if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
# message(STATUS "Enabling coverage for Clang/LLVM")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-instr-generate -fcoverage-mapping")
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-instr-generate -fcoverage-mapping")
# else()
# message(WARNING "Coverage enabled, but not using Clang/LLVM. This setup is configured for Clang/LLVM.")
# endif()

# # Custom target to generate and display coverage report
# add_custom_target(coverage
# COMMAND ${CMAKE_COMMAND} -E env LLVM_PROFILE_FILE=${CMAKE_BINARY_DIR}/coverage.profraw ${CMAKE_CTEST_COMMAND} --verbose
# COMMAND llvm-profdata merge -sparse ${CMAKE_BINARY_DIR}/coverage.profraw -o ${CMAKE_BINARY_DIR}/coverage.profdata
# COMMAND llvm-cov show ${CMAKE_BINARY_DIR}/tests -instr-profile=${CMAKE_BINARY_DIR}/coverage.profdata -format=html -output-dir=${CMAKE_BINARY_DIR}/coverage_report
# COMMAND ${CMAKE_COMMAND} -E echo "Coverage report generated at ${CMAKE_BINARY_DIR}/coverage_report/index.html"
# DEPENDS UnitTests
# WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
# COMMENT "Running tests and generating code coverage report with llvm-cov..."
# VERBATIM
# )
# endif()
