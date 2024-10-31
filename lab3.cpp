#include <iostream>
#include <cmath>

class TVector2D
{
protected:
    double x, y;

public:
    TVector2D() : x(0), y(0) {}

    TVector2D(double x, double y) : x(x), y(y) {}

    TVector2D(const TVector2D &other) : x(other.x), y(other.y) {}

    // Введення координат вектора
    void input()
    {
        std::cout << "Введіть x: ";
        std::cin >> x;
        std::cout << "Введіть y: ";
        std::cin >> y;
    }

    // Виведення координат вектора
    void output() const
    {
        std::cout << "(" << x << ", " << y << ")";
    }

    // Визначення довжини вектора
    double length() const
    {
        return sqrt(x * x + y * y);
    }

    // Нормалізація вектора
    TVector2D normalize() const
    {
        double len = length();
        return TVector2D(x / len, y / len);
    }

    // Порівняння з іншим вектором
    bool operator==(const TVector2D &other) const
    {
        return (x == other.x && y == other.y);
    }

    // Перевантаження оператора додавання
    TVector2D operator+(const TVector2D &other) const
    {
        return TVector2D(x + other.x, y + other.y);
    }

    // Перевантаження оператора віднімання
    TVector2D operator-(const TVector2D &other) const
    {
        return TVector2D(x - other.x, y - other.y);
    }

    // Скалярний добуток
    double operator*(const TVector2D &other) const
    {
        return x * other.x + y * other.y;
    }
};

// Клас-нащадок для тривимірного вектора
class TVector3D : public TVector2D
{
private:
    double z; // Координата z

public:
    // Конструктор без параметрів
    TVector3D() : TVector2D(), z(0) {}

    // Конструктор з параметрами
    TVector3D(double x, double y, double z) : TVector2D(x, y), z(z) {}

    // Конструктор копіювання
    TVector3D(const TVector3D &other) : TVector2D(other), z(other.z) {}

    // Введення координат вектора
    void input()
    {
        TVector2D::input();
        std::cout << "Введіть z: ";
        std::cin >> z;
    }

    // Виведення координат вектора
    void output() const
    {
        TVector2D::output();
        std::cout << ", " << z << ")";
    }

    // Визначення довжини вектора
    double length() const
    {
        return sqrt(x * x + y * y + z * z);
    }

    // Нормалізація вектора
    TVector3D normalize() const
    {
        double len = length();
        return TVector3D(x / len, y / len, z / len);
    }

    // Перевантаження оператора додавання
    TVector3D operator+(const TVector3D &other) const
    {
        return TVector3D(x + other.x, y + other.y, z + other.z);
    }

    // Перевантаження оператора віднімання
    TVector3D operator-(const TVector3D &other) const
    {
        return TVector3D(x - other.x, y - other.y, z - other.z);
    }

    // Скалярний добуток
    double operator*(const TVector3D &other) const
    {
        return x * other.x + y * other.y + z * other.z;
    }
};

// Програма-клієнт для тестування
int main()
{
    TVector2D v1, v2;

    std::cout << "Введення даних для вектора v1:" << std::endl;
    v1.input();
    std::cout << "Введення даних для вектора v2:" << std::endl;
    v2.input();

    std::cout << "Вектор v1: ";
    v1.output();
    std::cout << "\nДовжина v1: " << v1.length() << std::endl;

    std::cout << "Скалярний добуток v1 і v2: " << v1 * v2 << std::endl;

    TVector2D v3 = v1 + v2;
    std::cout << "v1 + v2 = ";
    v3.output();
    std::cout << std::endl;

    TVector3D v4, v5;
    std::cout << "\nВведення даних для вектора v4:" << std::endl;
    v4.input();
    std::cout << "Введення даних для вектора v5:" << std::endl;
    v5.input();

    std::cout << "Вектор v4: ";
    v4.output();
    std::cout << "\nДовжина v4: " << v4.length() << std::endl;

    TVector3D v6 = v4 + v5;
    std::cout << "v4 + v5 = ";
    v6.output();
    std::cout << std::endl;

    return 0;
}