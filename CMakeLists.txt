cmake_minimum_required(VERSION 3.16)
project(SearchBroQt LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)        # Automatisches Generieren von Meta-Objekt-Code
set(CMAKE_AUTORCC ON)        # Automatisches Generieren von Ressourcen
set(CMAKE_AUTOUIC ON)        # Automatisches Generieren von UI-Code

# Qt6 finden
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Alle Quellen und Header
set(SOURCES
    src/Main.cpp
    src/MainWindow.cpp
)

set(HEADERS
    src/MainWindow.hpp
    src/InitMainWindow.hpp
)

# Executable
add_executable(SearchBro ${SOURCES} ${HEADERS})

# Include-Verzeichnisse
target_include_directories(SearchBro PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Mit Qt Widgets linken
target_link_libraries(SearchBro PRIVATE Qt6::Widgets)

find_package(Qt6 REQUIRED COMPONENTS Widgets Test)
target_link_libraries(SearchBro PRIVATE Qt6::Widgets Qt6::Test)

