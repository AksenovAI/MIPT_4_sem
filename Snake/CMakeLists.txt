cmake_minimum_required(VERSION 3.15)
project(SnakeGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Настройка SFML (версия 3.0)
find_package(SFML 3.0 COMPONENTS Graphics Window System REQUIRED)

# Исходные файлы
set(SOURCES
    src/main.cpp
    src/config.cpp
    src/model.cpp
    src/controller.cpp
    src/game_objects.cpp
    src/console_view.cpp
    src/sfml_view.cpp
)

# Заголовочные файлы
include_directories(include)

# Создание исполняемого файла
add_executable(snake_game ${SOURCES})

# Подключение SFML (новые названия компонентов для версии 3.0)
target_link_libraries(snake_game 
    PRIVATE 
    SFML::Graphics 
    SFML::Window 
    SFML::System
)

# Копирование ресурсов
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})