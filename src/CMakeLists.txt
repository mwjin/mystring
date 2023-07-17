file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cc
)

add_executable(mystring_main ${SRC_FILES})
target_link_libraries(mystring_main mystring)
target_compile_options(mystring_main PUBLIC -Wall -Werror)
