#include <iostream>

int main()
{
    const int n = 3; //input
    const int m = 14;
    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = i * (-2) + j * (-21) + 12; //std::cin if you want
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    int min = a[0][0];
    int l = 2;
    for (int i = 0; i < n; i++) {
        for (int j = n - l; j >= 0; j--) {
            if (a[i][j] < min && i + j < n) {
                min = a[i][j];
            }
        }
        l++;
    }
    std::cout << min << " -Minimal number which situate under not-main axis";
    return 0;
}