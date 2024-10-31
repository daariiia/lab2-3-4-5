#include <iostream>
#include <cmath>

class TVector2D
{
private:
    double x, y; // Поля для зберігання координат вектора

public:
    // Конструктор без параметрів
    TVector2D() : x(0), y(0) {}

    // Конструктор з параметрами
    TVector2D(double x_val, double y_val) : x(x_val), y(y_val) {}

    // Конструктор копіювання
    TVector2D(const TVector2D &other) : x(other.x), y(other.y) {}

    // Введення елементів вектора
    void input()
    {
        std::cout << "Enter x and y: ";
        std::cin >> x >> y;
    }

    // Виведення елементів вектора
    void display() const
    {
        std::cout << "Vector: (" << x << ", " << y << ")" << std::endl;
    }

    // Визначення довжини вектора
    double length() const
    {
        return std::sqrt(x * x + y * y);
    }

    // Нормування вектора
    void normalize()
    {
        double len = length();
        if (len != 0)
        {
            x /= len;
            y /= len;
        }
    }

    // Оператор додавання векторів
    TVector2D operator+(const TVector2D &other) const
    {
        return TVector2D(x + other.x, y + other.y);
    }

    // Оператор віднімання векторів
    TVector2D operator-(const TVector2D &other) const
    {
        return TVector2D(x - other.x, y - other.y);
    }

    // Оператор порівняння векторів
    bool operator==(const TVector2D &other) const
    {
        return x == other.x && y == other.y;
    }

    // Оператор знаходження скалярного добутку
    double operator*(const TVector2D &other) const
    {
        return x * other.x + y * other.y;
    }
};

int main()
{
    // Створюємо два вектори
    TVector2D v1(3.0, 4.0), v2(1.0, 2.0);

    // Виводимо початкові вектори
    v1.display();
    v2.display();

    // Знаходимо довжину першого вектора
    std::cout << "Length v1: " << v1.length() << std::endl;

    // Нормуємо перший вектор і виводимо його
    v1.normalize();
    v1.display();

    // Додаємо і віднімаємо вектори
    TVector2D sum = v1 + v2;
    TVector2D diff = v1 - v2;

    std::cout << "Sum: ";
    sum.display();

    std::cout << "Difference: ";
    diff.display();

    // Порівнюємо два вектори
    if (v1 == v2)
    {
        std::cout << "Vectors are the same" << std::endl;
    }
    else
    {
        std::cout << "Vectors are not the same" << std::endl;
    }

    // Знаходимо скалярний добуток векторів
    double dotProduct = v1 * v2;
    std::cout << "Scalar product of v1 and v2: " << dotProduct << std::endl;

    return 0;
}