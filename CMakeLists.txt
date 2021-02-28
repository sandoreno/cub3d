cmake_minimum_required(VERSION 3.17)
project(cub C)

set(CMAKE_C_STANDARD 99)

add_executable(cub main.c
        get_next_line.c
        parser_map.c)
#set(CMAKE_C_FLAGS "-Lmlx -lmlx -framework OpenGL -framework AppKit")
#
#link_directories(/usr/local/lib)
#include_directories(/usr/local/include)
target_link_libraries(cub
        "${PROJECT_SOURCE_DIR}/mlx/libmlx.a"
        "-framework OpenGL -framework AppKit")



add_subdirectory(libft)
target_link_libraries(cub libft)