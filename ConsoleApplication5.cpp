#include <iostream>
#include <cmath>
double f(double x) {
    return cos(2 / x) - 2 * sin(1 / x) + 1 / x;
}
int main()
{
    double L, R, x0, x1, eps;
    std::cout << "Variant 7" << std::endl;
    std::cout << "Left: ";
    std::cin >> L;
    std::cout << "Right: ";
    std::cin >> R;
    std::cout << "Eps: ";
    std::cin >> eps;
    x0 = L;
    x1 = R;
    int shag = 0;
    while (abs(x0-x1) > eps) {
        x0 = x1;
        x1 = L - f(L) * (R - L) / (f(R) - f(L));
        double fx1 = f(x1);
        if (fx1==0) {
            std::cout << shag << ". " << x1 << std::endl;
            return 0;
        }
        if ((fx1 * f(R))>0) {
            R = x1;
        }
        else {
            L = x1;
        }
        std::cout << shag << ". " << x1 << std::endl;
        shag++;
    }
    std::cout << "Itog: " << x1 << " Steps: " << shag << std::endl;
    return 0;
}
