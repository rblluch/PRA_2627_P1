#include <iostream>
#include "Drawing.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"

int main() {
    Drawing d;

    Circle c;
    Rectangle r;
    Square s;

    d.add_front(&c);
    d.add_front(&s);
    d.add_back(&r);

    d.print_all();
    std::cout << std::endl;

    std::cout << "Area (all circles) = " << d.get_area_all_circles() << std::endl;
    std::cout << std::endl;

    std::cout << "Calling move_squares(10, 10)..." << std::endl;
    d.move_squares(10, 10);
    d.print_all();

    return 0;
}
