cmake_minimum_required(VERSION 3.1.0)

#project(PathCAD_Gui LANGUAGES CXX)
project(PathCAD_Gui)

#set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(${PROJECT_NAME}
    main.cpp

    MainWindow.cpp
    include/MainWindow.h

    ModelTree.cpp
    include/ModelTree.h

    Settings.cpp
    include/Settings.h

    SettingsDialog.cpp
    include/SettingsDialog.h

    PathGroupItem.cpp
    include/PathGroupItem.h

    res.qrc
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE PathCAD_Lib
    PRIVATE Qt5::Widgets
    PRIVATE Threads::Threads
)

target_include_directories(${PROJECT_NAME}
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include
)

add_subdirectory(PathCAD_Lib)
