cmake_minimum_required(VERSION 3.13)
project(NanaRo VERSION 0.4.3 LANGUAGES CXX)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE DEBUG)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_COLOR_MAKEFILE OFF)

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
# set(SFML_DIR "<sfml root prefix>/lib/cmake/SFML")

set(COMPILER_DEBUG_COMPILE_FLAG
  -g
  -Wall
  -Wextra)

set(COMPILER_DEBUG_COMMON_GCC_CLANG_COMPILE_FLAG
  -Werror
  -Og
  -Wshadow
  -Wnon-virtual-dtor
  -Wold-style-cast
  -Wcast-align
  -Wunused
  -Woverloaded-virtual
  -Wpedantic
  -Wconversion
  -Wsign-conversion
  -Wnull-dereference
  -Wdouble-promotion
  -Wformat=2)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  # using Clang
  set(COMPILER_DEBUG_COMPILE_FLAG
    ${COMPILER_DEBUG_COMPILE_FLAG}
    ${COMPILER_DEBUG_COMMON_GCC_CLANG_COMPILE_FLAG}
    )
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  # using GCC
  set(COMPILER_DEBUG_COMPILE_FLAG
    ${COMPILER_DEBUG_COMPILE_FLAG}
    ${COMPILER_DEBUG_COMMON_GCC_CLANG_COMPILE_FLAG}
    -Wduplicated-cond
    -Wduplicated-branches
    -Wlogical-op
    -Wuseless-cast)
else()
  message(WARNING "Non supported compiler (GCC / CLANG) is used. Debug mode compilation flag is limited to -g -Wall -Wextra")
endif()


#add_custom_target(link_font ALL
#  COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_CURRENT_SOURCE_DIR}/font ${CMAKE_BINARY_DIR}/font)

set(EXECUTABLE_NAME "d${PROJECT_NAME}"
  CACHE STRING "Executable's name")

find_package(Threads REQUIRED)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

set(INCLUDE_DIRECTORY
  #${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  )
add_subdirectory(src)
add_subdirectory(include)

set(SOURCE_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/sprite.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/sprite/draw.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/sprite/invalid.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/sprite/init/basic.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/sprite/init/numeric.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/sprite/init/moveable.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/block/colour.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/block/image.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/grid/wall.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/sys/random.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/ui/compose.cpp
  )

set(INCLUDE_FILES
  #${CMAKE_CURRENT_SOURCE_DIR}/include/Header.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/Block/PixCol.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/Block/Type.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/Block/Image.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/Block/Colour.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/Sprite/Draw.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/System/Random.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/Ui/Compose.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/Grid/Type.hpp
  )

add_executable(${EXECUTABLE_NAME}
  ${SOURCE_FILES}
  ${INCLUDE_FILES}
  )

target_compile_definitions(${EXECUTABLE_NAME}
  PRIVATE VER_MAJOR=${PROJECT_VERSION_MAJOR}
  PRIVATE VER_MINOR=${PROJECT_VERSION_MINOR}
  PRIVATE VER_PATCH=${PROJECT_VERSION_PATCH}
  )

target_include_directories(${EXECUTABLE_NAME}
  PRIVATE
  ${INCLUDE_DIRECTORY}
  )

target_link_libraries(${EXECUTABLE_NAME}
  PRIVATE
  sfml-graphics
  sfml-audio
  Threads::Threads
  m)

target_compile_features(${EXECUTABLE_NAME} PRIVATE cxx_std_17)
target_compile_options(${EXECUTABLE_NAME} PRIVATE $<$<CONFIG:DEBUG>:${COMPILER_DEBUG_COMPILE_FLAG}
  >)
