# Лабораторная работа №4

## Название: "Основы метапрограммирования"

### Цель:

- Изучение основ работы с шаблонами (template) в С++

- Изучение шаблонов умных указателей

### Условие задачи (вариант 33):
ФИГУРЫ ДЛЯ ВАРИАНТА: треугольник, квадрат, прямоугольник
### Структура проекта

```
laba4_oop_kovalev/
├── include/
│   └── array.h
│   └── figure.h
│   └── rectangle.h
│   └── square.h
│   └── triangle.h
├── src/
|   └── main.cpp
├── tests/
│   └── array_test.cpp
|   └── point_test.cpp
│   └── rectangle_test.cpp
│   └── square_test.cpp
│   └── triangle_test.cpp
|   └── main_test.cpp
└── CMakeLists.txt
└── README.md
```

### Сборка проекта

```bash
# Создание директории для сборки
mkdir build
cd build

# Конфигурация проекта
cmake ..

# Сборка проекта
cmake --build .
```

### Запуск проекта

```bash
./figure
```

### Запуск тестов

```bash
./tests
```
или
```bash
ctest
```