#include <iostream>
#include <cmath>
#include <string>

// Клас Quadrilateral представляє опуклий чотирикутник
class Quadrilateral
{
private:
    double a, b, c, d;                     // Довжини сторін чотирикутника
    double x1, y1, x2, y2, x3, y3, x4, y4; // Координати вершин чотирикутника
    bool definedBySides;                   // Визначає спосіб задання чотирикутника: за сторонами чи за координатами

public:
    // Конструктор для чотирикутника, заданого довжинами сторін
    Quadrilateral(double a, double b, double c, double d)
        : a(a), b(b), c(c), d(d), definedBySides(true) {}

    // Конструктор для чотирикутника, заданого координатами вершин
    Quadrilateral(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
        : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3), x4(x4), y4(y4), definedBySides(false) {}

    // Метод для обчислення периметра чотирикутника
    double perimeter() const
    {
        if (definedBySides)
        {                         // Якщо чотирикутник задано сторонами
            return a + b + c + d; // Повертає суму довжин сторін
        }
        else
        { // Якщо чотирикутник задано координатами
            // Обчислює довжини сторін на основі координат вершин
            double ab = distance(x1, y1, x2, y2);
            double bc = distance(x2, y2, x3, y3);
            double cd = distance(x3, y3, x4, y4);
            double da = distance(x4, y4, x1, y1);
            return ab + bc + cd + da; // Повертає суму довжин сторін
        }
    }

    // Метод для обчислення площі за формулою Брахмагупти (якщо відомі сторони)
    double area() const
    {
        if (definedBySides)
        {                                 // Якщо чотирикутник заданий сторонами
            double s = perimeter() / 2.0; // Напівпериметр
            // Формула Брахмагупти для обчислення площі
            return sqrt((s - a) * (s - b) * (s - c) * (s - d));
        }
        else
        { // Якщо чотирикутник заданий координатами
            // Формула для обчислення площі багатокутника за координатами вершин
            return 0.5 * std::abs(x1 * y2 + x2 * y3 + x3 * y4 + x4 * y1 - (y1 * x2 + y2 * x3 + y3 * x4 + y4 * x1));
        }
    }

    // Метод для визначення типу чотирикутника
    std::string type() const
    {
        if (definedBySides)
        { // Якщо чотирикутник заданий сторонами
            if (a == c && b == d)
            { // Перевіряє, чи протилежні сторони рівні
                if (a == b)
                    return "Square"; // Якщо всі сторони рівні, то це квадрат
                return "Rectangle";  // Якщо лише протилежні рівні, то прямокутник
            }
            // Якщо протилежні сторони рівні попарно, то це паралелограм
            if ((a == b && c == d)(a == d && b == c))
                return "Parallelogram";
            return "Irregular Quadrilateral"; // Інакше це нерегулярний чотирикутник
        }
        else
        { // Якщо чотирикутник заданий координатами
            // Обчислює довжини сторін за координатами
            double ab = distance(x1, y1, x2, y2);
            double bc = distance(x2, y2, x3, y3);
            double cd = distance(x3, y3, x4, y4);
            double da = distance(x4, y4, x1, y1);
            if (ab == cd && bc == da)
            { // Перевірка на рівність протилежних сторін
                if (ab == bc)
                    return "Square"; // Якщо всі сторони рівні, то квадрат
                return "Rectangle";  // Якщо лише протилежні рівні, то прямокутник
            }
            // Якщо протилежні сторони рівні попарно, то це паралелограм
            if ((ab == bc && cd == da)(ab == da && bc == cd))
                return "Parallelogram";
            return "Irregular Quadrilateral"; // Інакше це нерегулярний чотирикутник
        }
    }

private:
    // Допоміжний метод для обчислення відстані між двома точками
    double distance(double x1, double y1, double x2, double y2) const
    {
        // Використовує теорему Піфагора для обчислення відстані
        return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    }
};
int main()
{
    // Створення чотирикутника, заданого сторонами
    Quadrilateral quad1(5, 5, 5, 5);
    // Вивід периметра, площі та типу чотирикутника, заданого сторонами
    std::cout << "Perimeter (by sides): " << quad1.perimeter() << std::endl;
    std::cout << "Area (by sides): " << quad1.area() << std::endl;
    std::cout << "Type (by sides): " << quad1.type() << std::endl;

    // Створення чотирикутника, заданого координатами
    Quadrilateral quad2(0, 0, 5, 0, 5, 5, 0, 5);
    // Вивід периметра, площі та типу чотирикутника, заданого координатами
    std::cout << "Perimeter (by coordinates): " << quad2.perimeter() << std::endl;
    std::cout << "Area (by coordinates): " << quad2.area() << std::endl;
    std::cout << "Type (by coordinates): " << quad2.type() << std::endl;

    return 0;
}