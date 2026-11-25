#include <cstdio>
#include "Drawing.h"
#include "ListArray.h"
#include "Circle.h"
#include "Square.h"

Drawing::Drawing() {
    shapes = new ListArray<Shape*>();
}

Drawing::~Drawing() {
    delete shapes;
}

void Drawing::add_front(Shape* shape) {
    shapes->prepend(shape);
}

void Drawing::add_back(Shape* shape) {
    shapes->append(shape);
}

void Drawing::print_all() {
    std::printf("Drawing contents:\n");
    for (int i = 0; i < shapes->size(); i++) {
        shapes->get(i)->print();
        std::printf("\n");
    }
}

double Drawing::get_area_all_circles() {
    double total_area = 0.0;
    for (int i = 0; i < shapes->size(); i++) {
        Circle* c = dynamic_cast<Circle*>(shapes->get(i));
        if (c != nullptr) {
            total_area += c->area();
        }
    }
    return total_area;
}

void Drawing::move_squares(double incX, double incY) {
    for (int i = 0; i < shapes->size(); i++) {
        Square* s = dynamic_cast<Square*>(shapes->get(i));
        if (s != nullptr) {
            s->translate(incX, incY);
        }
    }
}
