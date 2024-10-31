#include <iostream>
#include <cmath>

// Базовий клас для призми
class TPrism
{
protected:
    double height; // Висота призми
public:
    // Конструктор, що ініціалізує висоту призми
    TPrism(double h) : height(h) {}

    // Чиста віртуальна функція для обчислення площі поверхні
    virtual double surfaceArea() const = 0;

    // Чиста віртуальна функція для обчислення об'єму
    virtual double volume() const = 0;
};

// Клас для трикутної призми, який успадковується від TPrism
class TPrism3 : public TPrism
{
private:
    double side; // Довжина сторони трикутної основи
public:
    // Конструктор для ініціалізації сторони основи і висоти
    TPrism3(double s, double h) : TPrism(h), side(s) {}

    // Метод для обчислення площі поверхні трикутної призми
    double surfaceArea() const override
    {
        double baseArea = (sqrt(3) / 4) * side * side; // Площа основи (рівностороннього трикутника)
        double lateralArea = 3 * side * height;        // Площа бічної поверхні
        return 2 * baseArea + lateralArea;             // Загальна площа поверхні
    }

    // Метод для обчислення об'єму трикутної призми
    double volume() const override
    {
        double baseArea = (sqrt(3) / 4) * side * side; // Площа основи
        return baseArea * height;                      // Об'єм = площа основи * висота
    }
};

// Клас для чотирикутної призми, який успадковується від TPrism
class TPrism4 : public TPrism
{
private:
    double side; // Довжина сторони квадратної основи
public:
    // Конструктор для ініціалізації сторони основи і висоти
    TPrism4(double s, double h) : TPrism(h), side(s) {}

    // Метод для обчислення площі поверхні чотирикутної призми
    double surfaceArea() const override
    {
        double baseArea = side * side;          // Площа основи (квадрата)
        double lateralArea = 4 * side * height; // Площа бічної поверхні
        return 2 * baseArea + lateralArea;      // Загальна площа поверхні
    }

    // Метод для обчислення об'єму чотирикутної призми
    double volume() const override
    {
        double baseArea = side * side; // Площа основи
        return baseArea * height;      // Об'єм = площа основи * висота
    }
};

int main()
{
    double side3, height3, side4, height4;
    int m;

    // Введення параметрів для трикутної призми
    std::cout << "storona trukytnuka: ";
    std::cin >> side3;
    std::cout << "vusota trukytnoi pruzmu: ";
    std::cin >> height3;

    // Введення параметрів для чотирикутної призми
    std::cout << "storona choturukytnoi osnovu: ";
    std::cin >> side4;
    std::cout << "vusota choturukytnoi pruzmu: ";
    std::cin >> height4;

    // Введення кількості призм, які потрібно створити
    std::cout << "pruzmu m: ";
    std::cin >> m;

    // Початкові значення для об'єму першої трикутної і чотирикутної призм
    double currentVolume3 = TPrism3(side3, height3).volume(); // Об'єм першої трикутної призми
    double currentVolume4 = TPrism4(side4, height4).volume(); // Об'єм першої чотирикутної призми

    double totalVolume3 = 0;      // Сумарний об'єм трикутних призм
    double totalSurfaceArea4 = 0; // Сумарна площа поверхні чотирикутних призм

    for (int i = 0; i < m; ++i)
    {
        // Додаємо об'єм для поточної трикутної призми до загального об'єму
        TPrism3 triangularPrism(side3, height3);
        totalVolume3 += currentVolume3;
        currentVolume3 += 5; // Збільшуємо об'єм на 5 для наступної призми

        // Додаємо площу поверхні для поточної чотирикутної призми до загальної площі
        TPrism4 quadrilateralPrism(side4, height4);
        totalSurfaceArea4 += quadrilateralPrism.surfaceArea();
        currentVolume4 += 5; // Збільшуємо об'єм на 5 для наступної призми
    }

    // Виведення результатів
    std::cout << "sum v 3 pruzm: " << totalVolume3 << std::endl;      // Сумарний об'єм трикутних призм
    std::cout << "sum s 4 pruzm: " << totalSurfaceArea4 << std::endl; // Сумарна площа поверхні чотирикутних призм
}