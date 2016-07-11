set(SYNTH  algosynth)

project(algosynth)
cmake_minimum_required(VERSION 3.0)

set(SYNTH_SOURCES
    src/main.cpp
    src/SoundEtude.cpp
    )

add_executable(${SYNTH} ${SYNTH_SOURCES})

set_property(TARGET ${SYNTH} PROPERTY CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    add_definitions("-DDEBUG")
endif()

find_package(etudes REQUIRED)

target_include_directories(${SYNTH}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/
    PUBLIC ${ETUDES_INCLUDE_DIRS}
    )

target_link_libraries(${SYNTH}
    PUBLIC ${ETUDES_LIBRARIES}
    )
