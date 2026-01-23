#include <iostream>
#include <cmath>

class Point2D {


public: // публичные методы - доступны извне
    
    // 1. КОНСТРУКТОР ПО УМОЛЧАНИЮ
    // Вызывается при создании объекта без параметров: Point2D p1;
    Point2D() {
        x = 0.0;
        y = 0.0;
        std::cout << "Создана новая точка в (0, 0)" << std::endl;
    }
    
    // 2. КОНСТРУКТОР С ПАРАМЕТРАМИ (с использованием member initializer list)
    // Вызывается при создании: Point2D p2(3.5, 4.2);
    Point2D(double new_x, double new_y) : x(new_x), y(new_y) {
        std::cout << "Создана новая точка в (" << x << ", " << y << ")" << std::endl;
    }
    
    // 3. ДЕСТРУКТОР
    // Вызывается автоматически при удалении объекта
    ~Point2D() {
        std::cout << "Точка (" << x << ", " << y << ") удалена" << std::endl;
    }
    
    // 4. ГЕТТЕРЫ (методы для получения значений)
    double getX() const {
        return x;
    }
    
    double getY() const {
        return y;
    }
    
    // 5. СЕТТЕРЫ (методы для установки значений)
    void setX(double new_x) {
        x = new_x;
    }
    
    void setY(double new_y) {
        y = new_y;
    }
    
    // 6. МЕТОД: показать информацию о точке
    void showInfo() const {
        std::cout << "Координаты точки: (" << x << ", " << y << ")" << std::endl;
    }
    
    // 7. МЕТОД 1: вычислить расстояние от начала координат
    // Формула: √(x² + y²)
    double distanceFromOrigin() const {
        return std::sqrt(x * x + y * y);
    }
    
    // 8. МЕТОД 2: вычислить расстояние до другой точки
    // Формула: √((x1-x2)² + (y1-y2)²)
    double distanceTo(const Point2D& other_point) const {
        double diff_x = x - other_point.x;
        double diff_y = y - other_point.y;
        return std::sqrt(diff_x * diff_x + diff_y * diff_y);
    }
    
    // 9. МЕТОД 3: переместить точку на заданный вектор
    void move(double move_x, double move_y) {
        x = x + move_x;
        y = y + move_y;
        std::cout << "Точка перемещена на вектор (" << move_x << ", " << move_y << ")" << std::endl;
    }
    
    // 10. МЕТОД 4: проверить принадлежность заданной области (квадрат)
    // Проверяем, находится ли точка в квадрате с заданными границами
    bool isInArea(double area_left, double area_right, 
                  double area_bottom, double area_top) const {
        // Проверяем все четыре условия
        bool in_x = (x >= area_left) && (x <= area_right);
        bool in_y = (y >= area_bottom) && (y <= area_top);
        return in_x && in_y;
    }
private: // приватные поля - доступны только внутри класса
    double x; // координата X
    double y; // координата Y
};

int main() {
    std::cout << "=== ПРОГРАММА ДЛЯ РАБОТЫ С ТОЧКАМИ НА ПЛОСКОСТИ ===" << std::endl << std::endl;
    
    // ДЕМОНСТРАЦИЯ: создание объектов разными способами
    
    // СПОСОБ 1: Создание через конструктор по умолчанию
    std::cout << "1. СОЗДАЕМ ТОЧКУ ЧЕРЕЗ КОНСТРУКТОР ПО УМОЛЧАНИЮ:" << std::endl;
    Point2D point1; // вызывается Point2D()
    point1.showInfo();
    std::cout << std::endl;
    
    // СПОСОБ 2: Создание через конструктор с параметрами (с member initializer list)
    std::cout << "2. СОЗДАЕМ ТОЧКУ ЧЕРЕЗ КОНСТРУКТОР С ПАРАМЕТРАМИ:" << std::endl;
    Point2D point2(3.0, 4.0); // вызывается Point2D(3.0, 4.0)
    point2.showInfo();
    std::cout << std::endl;
    
    // СПОСОБ 3: Еще одна точка для демонстрации
    std::cout << "3. СОЗДАЕМ ТРЕТЬЮ ТОЧКУ:" << std::endl;
    Point2D point3(-2.0, 5.0);
    point3.showInfo();
    std::cout << std::endl;
    
    // ДЕМОНСТРАЦИЯ: работа с геттерами и сеттерами
    
    std::cout << "4. РАБОТА С ГЕТТЕРАМИ (получение значений):" << std::endl;
    std::cout << "Координата X точки 2: " << point2.getX() << std::endl;
    std::cout << "Координата Y точки 2: " << point2.getY() << std::endl;
    std::cout << std::endl;
    
    std::cout << "5. РАБОТА С СЕТТЕРАМИ (изменение значений):" << std::endl;
    std::cout << "Было у точки 1: ";
    point1.showInfo();
    point1.setX(5.0);
    point1.setY(12.0);
    std::cout << "Стало у точки 1: ";
    point1.showInfo();
    std::cout << std::endl;
    
    // ДЕМОНСТРАЦИЯ: вызов методов для выполнения операций над данными
    
    std::cout << "6. МЕТОД 1: РАССТОЯНИЕ ОТ НАЧАЛА КООРДИНАТ:" << std::endl;
    std::cout << "Для точки (3, 4): " << point2.distanceFromOrigin() << std::endl;
    std::cout << "Для точки (5, 12): " << point1.distanceFromOrigin() << std::endl;
    std::cout << "Для точки (-2, 5): " << point3.distanceFromOrigin() << std::endl;
    std::cout << std::endl;
    
    std::cout << "7. МЕТОД 2: РАССТОЯНИЕ МЕЖДУ ТОЧКАМИ:" << std::endl;
    std::cout << "Расстояние между точкой1 и точкой2: " 
              << point1.distanceTo(point2) << std::endl;
    std::cout << "Расстояние между точкой2 и точкой3: " 
              << point2.distanceTo(point3) << std::endl;
    std::cout << std::endl;
    
    std::cout << "8. МЕТОД 3: ПЕРЕМЕЩЕНИЕ ТОЧКИ:" << std::endl;
    std::cout << "Было: ";
    point2.showInfo();
    point2.move(1.0, -2.0); // сдвигаем на вектор (1, -2)
    std::cout << "Стало: ";
    point2.showInfo();
    std::cout << std::endl;
    
    std::cout << "9. МЕТОД 4: ПРОВЕРКА ПРИНАДЛЕЖНОСТИ ОБЛАСТИ:" << std::endl;
    // Область: квадрат от (-5,-5) до (5,5)
    double left = -5.0, right = 5.0, bottom = -5.0, top = 5.0;
    
    std::cout << "Проверяем область: квадрат [" << left << ", " << right 
              << "] x [" << bottom << ", " << top << "]" << std::endl;
    
    std::cout << "Точка 1 ";
    point1.showInfo();
    if (point1.isInArea(left, right, bottom, top)) {
        std::cout << "Точка 1 находится внутри области!" << std::endl;
    } else {
        std::cout << "Точка 1 НЕ находится внутри области!" << std::endl;
    }
    
    std::cout << "Точка 3 ";
    point3.showInfo();
    if (point3.isInArea(left, right, bottom, top)) {
        std::cout << "Точка 3 находится внутри области!" << std::endl;
    } else {
        std::cout << "Точка 3 НЕ находится внутри области!" << std::endl;
    }
    std::cout << std::endl;
    
    // ДЕМОНСТРАЦИЯ: работа с указателями на объекты
    
    std::cout << "10. РАБОТА С УКАЗАТЕЛЯМИ НА ОБЪЕКТЫ:" << std::endl;
    
    // Способ 1: указатель на существующий объект
    Point2D* pointer_to_point = &point1;
    
    std::cout << "Доступ к методам через указатель (оператор ->):" << std::endl;
    std::cout << "Координаты через указатель: X = " << pointer_to_point->getX() 
              << ", Y = " << pointer_to_point->getY() << std::endl;
    
    // Вызов методов через указатель
    std::cout << "Расстояние от нуля через указатель: " 
              << pointer_to_point->distanceFromOrigin() << std::endl;
    
    // Изменение объекта через указатель
    pointer_to_point->setX(8.0);
    std::cout << "После изменения X через указатель: ";
    pointer_to_point->showInfo();
    std::cout << std::endl;
    
    // Способ 2: создание объекта в динамической памяти (куче)
    std::cout << "11. СОЗДАНИЕ ОБЪЕКТА В ДИНАМИЧЕСКОЙ ПАМЯТИ:" << std::endl;
    Point2D* dynamic_point = new Point2D(10.0, 20.0);
    
    // Работа с динамическим объектом через указатель
    dynamic_point->showInfo();
    std::cout << "Расстояние от начала координат: " 
              << dynamic_point->distanceFromOrigin() << std::endl;
    
    // Проверка области для динамического объекта
    if (dynamic_point->isInArea(0.0, 15.0, 15.0, 25.0)) {
        std::cout << "Динамическая точка находится в области [0,15]x[15,25]" << std::endl;
    }
    std::cout << std::endl;
    
    // Удаление динамического объекта
    std::cout << "12. УДАЛЕНИЕ ДИНАМИЧЕСКОГО ОБЪЕКТА:" << std::endl;
    delete dynamic_point; // здесь вызывается деструктор
    std::cout << std::endl;
    
    std::cout << "=== ПРОГРАММА ЗАВЕРШЕНА ===" << std::endl;
    // Объекты point1, point2, point3 удалятся автоматически при выходе из main()
    // Для каждого вызовется деструктор
    
    return 0;
}