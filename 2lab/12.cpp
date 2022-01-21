#include <iostream>
#include <cmath>

int main()
{
    double x1, y1, x2, y2, r, R;
    std::cout << "Please, enter x1, y1, r, x2, y2, R:" << std::endl;
    std::cin >> x1 >> y1 >> r >> y2 >> x2 >> R;
    if (r <= 0 || R <= 0) {
        std::cout << "Error";
        return 0;
    }
    double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    if (d < r + R) {
        if (R > r) {
            if (d + r < R) {
                std::cout << "Yes";
            }
            else {
                std::cout << "Figures are crossed";
            }
        }
        else if (R < r) {
            if (d + R < r) {
                std::cout << "Yes, but the opposite for 2 figures";
            }
        }
        else {
            std::cout << "Figures are crossed";
        }
    }
    else {
        std::cout << "No condition is met";
    }
    return 0;
}
