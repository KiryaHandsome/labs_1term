#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    double x1, y1, x2, y2, h, w, H, W;
    std::cout << "Enter W and H: " << std::endl;
    std::cin >> W >> H;
    std::cout << "Enter x1, y1 and x2, y2: " << std::endl;
    std::cin >> x1 >> y1 >> x2 >> y2;
    std::cout << "Enter w and h: " << std::endl;
    std::cin >> w >> h;
    if(x2 - x1 + w > W && y2 - y1 + h > H) {
        std::cout << "-1";
        return 0;
    }
    double d1, d2, d3, d4; //distance to sides
    d1 = sqrt(pow(x1, 2) + pow(H - y2, 2));
    d2 = sqrt(pow(x1, 2) + pow(y1, 2));
    d3 = sqrt(pow(W - x2, 2) + pow(y1, 2));
    d4 = sqrt(pow(W - x2, 2) + pow(H - y2, 2));
    double max; //maximal distance to side
    if (d1 > d2) {
        if (d1 > d3) {
            if (d1 > d4) {
                max = d1;
            }
            else {
                max = d4;
            }
        }
        else if (d3 > d4) {
            max = d3;
        }
        else {
            max = d4;
        }
    }
    else if (d2 > d3) {
        if (d2 > d4) {
            max = d2;
        }
        else {
            max = d4;
        }
    }
    else if(d3 > d4) {
        max = d3;
    }
    else {
        max = d4;
    }
    double dmin1, dmin2; //minimal distance (x,y)
    if (max == d1) {
        dmin1 = w - x1;
        dmin2 = y2 - H + h;
    }
    else if (max == d2) {
        dmin1 = w - x1;
        dmin2 = h - y1;
    }
    else if (max == d3) {
        dmin1 = x2 - W + w;
        dmin2 = h - y1;
    }
    else {
        dmin1 = x2 - W + w;
        dmin2 = y2 - H + h;
    }
    double rightdistance; //search distance
    if (y2 - y1 + h > H) {
        rightdistance = dmin1;
    }
    else if (x2 - x1 + w > W) {
        rightdistance = dmin2;
    }
    else {
        if (dmin1 < dmin2) {
            rightdistance = dmin1;
        }
        else {
            rightdistance = dmin2;
        }
    }
    std::cout << std::fixed << std::setprecision(8)<< rightdistance;
    return 0;
}
