#include <iostream>
#include <string>
/*
Ссылки в C++
int main() {
    int number = 5;
    
    // Ссылка - это второе имя для переменной
    int& ref = number;  // ref теперь то же самое что number
    
    std::cout << "number = " << number << std::endl;
    std::cout << "ref = " << ref << std::endl;
    
    ref = 10;  // Меняем number через ref
    std::cout << "После ref = 10:" << std::endl;
    std::cout << "number = " << number << std::endl;
    
    return 0;
}
    */
/*
Константные ссылки 
    int main() {
    int age = 25;
    
    // Обычная ссылка - можно менять
    int& age_ref = age;
    age_ref = 30;  // Меняем возраст
    std::cout << "age = " << age << std::endl;
    
    // Константная ссылка - только читать
    const int& age_cref = age;
    // age_cref = 35;  // Ошибка! Нельзя менять
    std::cout << "age_cref = " << age_cref << std::endl;
    
    return 0;
}
    */
/*
Передача в функцию - 3 способа
// 1. По значению - получаем копию
void byValue(int x) {
    x = 100;  // Меняем только копию
    std::cout << "Внутри byValue: x = " << x << std::endl;
}

// 2. По ссылке - работаем с оригиналом
void byReference(int& x) {
    x = 200;  // Меняем оригинал
    std::cout << "Внутри byReference: x = " << x << std::endl;
}

// 3. Через указатель - работаем с адресом
void byPointer(int* x) {
    *x = 300;  // Меняем через указатель
    std::cout << "Внутри byPointer: *x = " << *x << std::endl;
}

int main() {
    int a = 5;
    
    std::cout << "Исходное a = " << a << std::endl;
    
    byValue(a);
    std::cout << "После byValue: a = " << a << std::endl;
    
    byReference(a);
    std::cout << "После byReference: a = " << a << std::endl;
    
    byPointer(&a);
    std::cout << "После byPointer: a = " << a << std::endl;
    
    return 0;
}
    */

/*
Передача по значению vs по ссылке
struct Book {
    std::string title;
    int pages;
};

// Плохо - создается копия всей структуры
void printBookByValue(Book b) {
    std::cout << "Книга: " << b.title << ", страниц: " << b.pages << std::endl;
}

// Хорошо - не создаем копию
void printBookByReference(const Book& b) {
    std::cout << "Книга: " << b.title << ", страниц: " << b.pages << std::endl;
}

int main() {
    Book myBook = {"Война и мир", 1000};
    
    printBookByValue(myBook);      // Создается копия
    printBookByReference(myBook);  // Копии нет - эффективно
    
    return 0;
}
    */
/*
Опасный возврат ссылки
// ОПАСНО! Возвращаем ссылку на временную переменную
int& badFunction() {
    int temp = 42;
    return temp;  // temp уничтожится после функции!
}

// Правильно - возвращаем копию
int goodFunction() {
    int temp = 42;
    return temp;  // Возвращаем копию temp
}

int main() {
    // Делайте так:
    int good = goodFunction();
    std::cout << "good = " << good << std::endl;  // Всегда работает
    
    return 0;
}
   */
/*
Указатели на функции
// Простые математические функции
int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int main() {
    // Указатель на функцию
    int (*operation)(int, int);
    
    // Присваиваем адрес функции add
    operation = add;
    std::cout << "5 + 3 = " << operation(5, 3) << std::endl;
    
    // Присваиваем адрес функции multiply
    operation = multiply;
    std::cout << "5 * 3 = " << operation(5, 3) << std::endl;
    
    return 0;
}
    */
/*
Лямбда-выражения
int main() {
    // Простая лямбда без параметров
    auto hello = []() {
        std::cout << "Привет, мир!" << std::endl;
    };
    hello();
    
    // Лямбда с параметрами
    auto sum = [](int a, int b) {
        return a + b;
    };
    std::cout << "2 + 3 = " << sum(2, 3) << std::endl;
    
    // Лямбда с захватом переменных
    int x = 10;
    int y = 5;
    
    // Захватываем x по значению, y по ссылке
    auto calculator = [x, &y]() {
        std::cout << "x = " << x << ", y = " << y << std::endl;
        y = 15;  // Можем менять y (захвачен по ссылке)
    };
    
    calculator();
    std::cout << "После лямбды: y = " << y << std::endl;
    
    return 0;
}
*/
/*
Функции обратного вызова (колбэки)
// Функция, которая принимает другую функцию как параметр
void processNumber(int num, void (*callback)(int)) {
    std::cout << "Обрабатываем число: " << num << std::endl;
    callback(num);  // Вызываем переданную функцию
}

// Несколько callback функций
void printSquare(int n) {
    std::cout << "Квадрат: " << n * n << std::endl;
}

void printCube(int n) {
    std::cout << "Куб: " << n * n * n << std::endl;
}

void checkEven(int n) {
    if (n % 2 == 0) {
        std::cout << n << " - четное" << std::endl;
    } else {
        std::cout << n << " - нечетное" << std::endl;
    }
}

int main() {
    int number = 5;
    
    processNumber(number, printSquare);
    processNumber(number, printCube);
    processNumber(number, checkEven);
    
    // Используем лямбду как callback
    processNumber(number, [](int n) {
        std::cout << "Лямбда: число + 10 = " << n + 10 << std::endl;
    });
    
    return 0;
}
    */
/*
!!!! const_cast
int main() {
    // Обычная переменная
    int normal = 100;
    
    // Константная ссылка на обычную переменную
    const int& const_ref = normal;
    
    // Снимаем const (это безопасно, т.к. original не const)
    int& mutable_ref = const_cast<int&>(const_ref);
    mutable_ref = 200;  // Меняем оригинальную переменную
    
    std::cout << "normal = " << normal << std::endl;
    
    return 0;
}
    */

