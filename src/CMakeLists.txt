cmake_minimum_required(VERSION 3.1.0)

#project(PathCAD_Gui LANGUAGES CXX)
project(PathCAD_Gui)

#set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(${PROJECT_NAME}
    main.cpp

    MainWindow.cpp
    include/MainWindow.h

    Settings.cpp
    include/Settings.h

    SettingsDialog.cpp
    include/SettingsDialog.h

    res.qrc
)

target_link_libraries(${PROJECT_NAME}
    #PRIVATE PathCAD
    PRIVATE Qt5::Widgets
)

target_include_directories(${PROJECT_NAME}
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include
)

#add_subdirectory(PathCAD)
