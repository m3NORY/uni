#include <iostream>
#include <cmath>

class Point2D {
public: 
    Point2D(double new_x, double new_y) : x(new_x), y(new_y) {
        std::cout << "Создана новая точка в (" << x << ", " << y << ")" << std::endl;
    }
    ~Point2D() {
        std::cout << "Точка (" << x << ", " << y << ") удалена" << std::endl;
    }
    
    //геттеры (методы для получения значений)
    double getX() const {
        return x;
    }
    
    double getY() const {
        return y;
    }
    
    //сеттеры (методы для установки значений)
    void setX(double new_x) {
        x = new_x;
    }
    
    void setY(double new_y) {
        y = new_y;
    }
    
    void showInfo() const {
        std::cout << "Координаты точки: (" << x << ", " << y << ")" << std::endl;
    }
    
    double distanceFromOrigin() const {
        return std::sqrt(x * x + y * y);
    }
    
    double distanceTo(const Point2D& other_point) const {
        double diff_x = x - other_point.x;
        double diff_y = y - other_point.y;
        return std::sqrt(diff_x * diff_x + diff_y * diff_y);
    }
    
    void move(double move_x, double move_y) {
        x = x + move_x;
        y = y + move_y;
        std::cout << "Точка перемещена на вектор (" << move_x << ", " << move_y << ")" << std::endl;
    }
    
    bool isInArea(double area_left, double area_right, 
                  double area_bottom, double area_top) const {
        // Проверяем все четыре условия
        bool in_x = (x >= area_left) && (x <= area_right);
        bool in_y = (y >= area_bottom) && (y <= area_top);
        return in_x && in_y;
    }
private: 
    double x; 
    double y; 
};

int main() {
    setlocale(LC_ALL, "Russian"); 
    Point2D point1(3.0, 4.0); 
    point1.showInfo();
    std::cout << std::endl;
    Point2D point2(-2.0, 5.0);
    point2.showInfo();
    std::cout << std::endl;
    
    std::cout << "Координата X точки 2: " << point2.getX() << std::endl;
    std::cout << "Координата Y точки 2: " << point2.getY() << std::endl;
    std::cout << std::endl;
    
    std::cout << "Было у точки 1: ";
    point1.showInfo();
    point1.setX(5.0);
    point1.setY(10.0);
    std::cout << "Стало у точки 1: ";
    point1.showInfo();
    std::cout << std::endl;
    
    std::cout << "Для точки (3, 4): " << point2.distanceFromOrigin() << std::endl;
    std::cout << "Для точки (5, 10): " << point1.distanceFromOrigin() << std::endl;
    std::cout << std::endl;
    
    std::cout << "Расстояние между точкой1 и точкой2: " << point1.distanceTo(point2) << std::endl;
    std::cout << std::endl;
    
    std::cout << "Было: ";
    point2.showInfo();
    point2.move(1.0, -2.0); // сдвигаем на вектор (1, -2)
    std::cout << "Стало: ";
    point2.showInfo();
    std::cout << std::endl;
    
    double left = -5.0, right = 5.0, bottom = -5.0, top = 5.0; // Область: квадрат от (-5,-5) до (5,5)
    std::cout << left << ", " << right << bottom << top << std::endl;
    
    std::cout << "Точка 1 ";
    point1.showInfo();
    if (point1.isInArea(left, right, bottom, top)) {
        std::cout << "Точка 1 находится внутри области" << std::endl;
    } else {
        std::cout << "Точка 1 НЕ находится внутри области" << std::endl;
    }
    std::cout << "Точка 2 ";
    point2.showInfo();
    if (point2.isInArea(left, right, bottom, top)) {
        std::cout << "Точка 2 находится внутри области" << std::endl;
    } else {
        std::cout << "Точка 2 НЕ находится внутри области" << std::endl;
    }
    std::cout << std::endl;
    
    
    Point2D* pointer_to_point = &point1;
    std::cout << "координаты через указатель: x = " << pointer_to_point->getX() << ", y = " << pointer_to_point->getY() << std::endl;
    std::cout << "Расстояние от нуля через указатель: " << pointer_to_point->distanceFromOrigin() << std::endl;
    
    pointer_to_point->setX(8.0);
    std::cout << "После изменения x через указатель: ";
    pointer_to_point->showInfo();
    std::cout << std::endl;
    return 0;
}