cmake_minimum_required(VERSION 3.14...3.22)

project(
  next-prayer
  VERSION 0.5.0
  LANGUAGES CXX C
)

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(
    FATAL_ERROR
    "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there."
  )
endif()

include(cmake/CPM.cmake)

CPMAddPackage("gh:TheLartians/PackageProject.cmake@1.8.0")

CPMAddPackage(
  NAME fmt
  GIT_TAG 8.1.1
  GITHUB_REPOSITORY fmtlib/fmt
  OPTIONS "FMT_INSTALL YES" # create an installable target
)

# ---- Create executable ----
add_executable(${PROJECT_NAME}
  ${CMAKE_CURRENT_SOURCE_DIR}/source/main.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/source/cJSON.c
  ${CMAKE_CURRENT_SOURCE_DIR}/include/constants.h
  ${CMAKE_CURRENT_SOURCE_DIR}/include/argh.h
  ${CMAKE_CURRENT_SOURCE_DIR}/include/cJSON.h
  ${CMAKE_CURRENT_SOURCE_DIR}/include/http.h
)

set_target_properties(${PROJECT_NAME} PROPERTIES
  CXX_STANDARD 17
)

# being a cross-platform target, we enforce standards conformance on MSVC
target_compile_options(${PROJECT_NAME} PUBLIC
  "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/permissive->"
)

# Link dependencies
target_link_libraries(${PROJECT_NAME} PRIVATE
  fmt::fmt
)

target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}-${PROJECT_VERSION}>
)