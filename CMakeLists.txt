cmake_minimum_required(VERSION 3.1.0)

project(PathCAD_Gui)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(SRC_FILES
    src/main.cpp
    src/MainWindow.cpp
    src/ModelTree.cpp
    src/Settings.cpp
    src/SettingsDialog.cpp
    src/res.qrc

    TreeItems/src/DataElementItem.cpp
    TreeItems/src/ModelTreeItem.cpp
    TreeItems/src/LinePathItem.cpp
    TreeItems/src/PathGroupItem.cpp
)

set(HEADER_FILES
    include/MainWindow.h
    include/ModelTree.h
    include/Settings.h
    include/SettingsDialog.h

    TreeItems/include/DataElementItem.h
    TreeItems/include/ModelTreeItem.h
    TreeItems/include/LinePathItem.h
    TreeItems/include/PathGroupItem.h
)

add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEADER_FILES})

target_link_libraries(${PROJECT_NAME}
    PRIVATE PathCAD_Lib
    PRIVATE Qt5::Widgets
    PRIVATE Threads::Threads
)

target_include_directories(${PROJECT_NAME}
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}/TreeItems/include
)

install(TARGETS ${PROJECT_NAME}
        DESTINATION bin
)

add_subdirectory(src/PathCAD_Lib)
