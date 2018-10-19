cmake_minimum_required(VERSION 3.8)
project(menu-poc)

find_package(SFML 2.5 COMPONENTS REQUIRED graphics window system)

add_executable(menu-poc
    main.cpp
    menu.h
    menu.cpp
    menuitem.h
    menuitem.cpp
)

set_target_properties(menu-poc PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED TRUE
    CXX_EXTENSIONS OFF
)

target_link_libraries(menu-poc sfml-graphics sfml-window sfml-system)
