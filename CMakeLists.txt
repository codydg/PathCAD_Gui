cmake_minimum_required(VERSION 3.1.0)

project(PathCAD_Gui LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(${PROJECT_NAME}
    src/main.cpp

    src/MainWindow.cpp
    include/MainWindow.h

    src/ModelTree.cpp
    include/ModelTree.h

    src/Settings.cpp
    include/Settings.h

    src/SettingsDialog.cpp
    include/SettingsDialog.h

    src/PathGroupItem.cpp
    include/PathGroupItem.h

    src/res.qrc
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE PathCAD_Lib
    PRIVATE Qt5::Widgets
    PRIVATE Threads::Threads
)

target_include_directories(${PROJECT_NAME}
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include
)

install(TARGETS ${PROJECT_NAME}
        DESTINATION bin
)

add_subdirectory(src/PathCAD_Lib)
