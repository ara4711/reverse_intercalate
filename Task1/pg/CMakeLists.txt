cmake_minimum_required( VERSION 3.9.4 )

add_library(pg_list INTERFACE)

target_sources(pg_list INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}/node_tags.h
    ${CMAKE_CURRENT_SOURCE_DIR}/nodes.h
    ${CMAKE_CURRENT_SOURCE_DIR}/pg_list.h
)
target_include_directories(pg_list INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
