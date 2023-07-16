file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cc
)

add_executable(your_project ${SRC_FILES})
target_link_libraries(your_project shape)
target_compile_options(your_project PUBLIC -Wall -Werror)
