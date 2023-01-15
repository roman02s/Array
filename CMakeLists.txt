cmake_minimum_required(VERSION 3.16)
project(array_project)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Array)

file(GLOB INCLUDE_DIRS
        ${ARRAY_INCLUDE_DIRS}
)
file(GLOB SOURCE_FILES
)


message("PROJECT_SOURCE_FILES - ${SOURCE_FILES}")
message("PROJECT_INCLUDE_DIRS - ${INCLUDE_DIRS}")

add_executable(${PROJECT_NAME} main.cpp ${SOURCE_FILES} )

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC ${ARRAY_LIBRARY})

add_subdirectory(tests)
