set (CONFIG_NAME "${PROJECT_NAME}Config.h")
set (INC_DIR "include")
set (SRC_LIST "main.c")

include_directories(${PROJECT_SOURCE_DIR}/${INC_DIR})

# configure_file(<input> <output>)
# Copy input file to output file and perform variable substitution.
configure_file (
    "${PROJECT_SOURCE_DIR}/${INC_DIR}/${CONFIG_NAME}.in"
    "${PROJECT_BINARY_DIR}/${INC_DIR}/${CONFIG_NAME}"
    )

# Include the generated config file in the project.
include_directories("${PROJECT_BINARY_DIR}")

add_executable(${PROJECT_NAME} ${SRC_LIST})
install (TARGETS ${PROJECT_NAME} DESTINATION "bin")
install (FILES "${PROJECT_BINARY_DIR}/${INC_DIR}/${CONFIG_NAME}" DESTINATION ${INC_DIR})
