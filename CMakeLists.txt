cmake_minimum_required(VERSION 3.16)

project(OneGame VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

set(TS_FILES
    1_zh_CN.ts
)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    images.qrc
    ${TS_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(OneGame
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    add_executable(OneGame
        ${PROJECT_SOURCES}
    )
endif()

target_link_libraries(OneGame PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

if(Qt_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(OneGame)
endif()
