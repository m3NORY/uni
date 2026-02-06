# Создаем программу
add_executable(StatsApp main.cpp)

# Подключаем нашу библиотеку
target_link_libraries(StatsApp StatsLib)