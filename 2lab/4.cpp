#include <iostream>
#include <cmath>

int main()
{
    double k, x, y, minimum;
    std::cout << "Enter 3 numbers(k, x, y): ";
    std::cin >> k >> x >> y;
    k = fabs(k);
    x = fabs(x);
    y = fabs(y);
    minimum = -1;
    if (x >= 0 && x <= k) {
        if (y <= k && y >= 0) {
            double d1, d2, d3, d4; //variable for distance to sides
            d1 = x;
            d2 = k - y;
            d3 = k - x;
            d4 = y;
            if (d1 < d2) {
                if (d1 < d3) {
                    if (d1 < d4) {
                        minimum = d1;
                    }  
                }
            }
            else if (d2 < d3) {
                if (d2 < d4) {
                    minimum = d2;
                }
            }
            else if( d3 < d4 ) {
                minimum = d3;
            }
            else {
                minimum = d4;
            }
            std::cout << minimum << "-smallest distance to sides";
        }
        else {
            std::cout << "Point is outside the square." << std::endl;
        }
    }
    else {
        std::cout << "Point is outside the square." <<std::endl;
    }
   
    if (minimum == -1) {
        if (y < 0) {
            if (x < 0) {
                minimum = sqrt(x * x + y * y);
            }
            else if (x > k) {
                minimum = sqrt(pow(x - k, 2) + y * y);
            }
            else {
                minimum = fabs(y);
            }
        }
        else if (y > k) {
            if (x < 0) {
                minimum = sqrt(x * x + pow(y - k, 2));
            }
            else if (x > k) {
                minimum = sqrt(pow(x - k, 2) + pow(y - k, 2));
            }
            else {
                minimum = y - k;
            }
        }
        else {
            if (x < 0) {
                minimum = fabs(x);
            }
            else {
                minimum = x - k;
            }
        }
        std::cout << minimum <<"-distance to nearest side";
    }
    return 0;
}

