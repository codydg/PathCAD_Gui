cmake_minimum_required(VERSION 3.1.0)

project(PathCAD)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(${PROJECT_NAME}
    main.cpp
    MainWindow.cpp
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE Qt5::Widgets
)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include
)
