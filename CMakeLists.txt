cmake_minimum_required(VERSION 3.5)

project(vkBasalt-gui VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

set(TS_FILES vkBasalt-gui_en_GB.ts)

set(PROJECT_SOURCES
        ${TS_FILES}
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        vkbasalteffects.cpp
        vkbasalteffects.h
        vkbasalteffects.ui
        reshadefilters.cpp
        reshadefilters.h
        reshadefilters.ui
        casconfig.h
        casconfig.cpp
        casconfig.ui
        dlsconfig.cpp
        dlsconfig.h
        dlsconfig.ui
        fxaaconfig.cpp
        fxaaconfig.h
        fxaaconfig.ui
        lutconfig.cpp
        lutconfig.h
        lutconfig.ui
        smaaconfig.cpp
        smaaconfig.h
        smaaconfig.ui steamgamesmanager.cpp SteamGamesManager.h)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(vkBasalt-gui
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET vkBasalt-gui APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(vkBasalt-gui SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(vkBasalt-gui
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(vkBasalt-gui PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(vkBasalt-gui PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS vkBasalt-gui
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(vkBasalt-gui)
endif()
