#include <iostream>
#include <cmath>
double f(double x)
{
    return cos(2 / x) - 2 * sin(1 / x) + 1 / x;
}
int main()
{
    double L, R, B, eps;
    std::cout << "Variant 7" << std::endl;
    std::cout << "Left: ";
    std::cin >> L;
    std::cout << "Right: ";
    std::cin >> R;
    std::cout << "Eps: ";
    std::cin >> eps;
    int shag = 0;
    while (R - L > eps)
    {
        B = (L + R) / 2;
        if (f(B) == 0)
        {
            std::cout << B;
            return 0;
        }
        else if ((f(L) * f(B)) < 0)
        {
            R = B;
        }
        else
        {
            L = B;
        }
        shag++;
        std::cout << shag;
        std::cout << " ";
        std::cout << (L + R) / 2 << std::endl;
    }
    std::cout << (L + R) / 2 << std::endl;
    return 0;
}