project(array_integr_test)

set(TEST_SOURCES
        app.cpp
        )
set(TEST_LIBRARIES
    ${ARRAY_LIBRARY}
)


add_executable(${PROJECT_NAME} ${TEST_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME}
    ${TEST_LIBRARIES}
)