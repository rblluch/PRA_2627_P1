#include <iostream>
#include <stdexcept>
#include "Square.h"
#include "Point2D.h"

int main() {
    Square r1;
    std::cout << "r1 = " << r1 << std::endl;
    std::cout << "r1.area() => " << r1.area() << "; r1.perimeter() => " << r1.perimeter() << std::endl;
    std::cout << std::endl;

    Point2D* vs2 = new Point2D[4]{
        Point2D(-2, 2), Point2D(2, 2), Point2D(2, -2), Point2D(-2, -2)
    };
    Square r2("green", vs2);
    std::cout << "r2 = " << r2 << std::endl;
    std::cout << "r2.area() => " << r2.area() << "; r2.perimeter() => " << r2.perimeter() << std::endl;
    std::cout << std::endl;

    Point2D* vs_bad = new Point2D[4]{
        Point2D(-1, 0.5), Point2D(1, 0.5), Point2D(1, -0.5), Point2D(-1, -0.5)
    };
    try {
        r2.set_vertices(vs_bad);
    } catch (std::invalid_argument &e) {
        std::cout << "r2.set_vertices(...) => std::invalid_argument: " << e.what() << std::endl;
    }

    delete[] vs2;
    delete[] vs_bad;
    return 0;
}
