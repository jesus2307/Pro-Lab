cmake_minimum_required(VERSION 3.16)
project(ActivityLogger)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH "C:/Qt/6.9.0/mingw_64")  # Ruta a tu instalación de Qt

# Buscar módulos de Qt necesarios
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# Ejecutable y archivos fuente
add_executable(test
    activity.cpp
    activitylog.cpp
    test.cpp
)

# Enlazar Qt
target_link_libraries(test
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

# Google Test
add_subdirectory(external/googletest)
target_include_directories(test PUBLIC ${gtest_SOURCE_DIR}/include)
target_link_libraries(test gtest gtest_main)

#Este archivo prepara todo para que puedas:
#Compilar tu aplicación con Qt.
#jecutar pruebas unitarias con Google Test.
