# Создаем статическую библиотеку
add_library(StatsLib STATIC src/Statistics.cpp)

# Говорим, где искать заголовочные файлы
target_include_directories(StatsLib PUBLIC include)