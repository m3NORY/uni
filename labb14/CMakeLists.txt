# Минимальная версия CMake
cmake_minimum_required(VERSION 3.10)

# Название проекта
project(labb14)

# Используем C++11
set(CMAKE_CXX_STANDARD 11)

# Добавляем библиотеку и программу
add_subdirectory(StatsLib)
add_subdirectory(App)