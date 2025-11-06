#include "point.h"
#include "figure.h"
#include "triangle.h"
#include "square.h"
#include "rectangle.h"
#include "array.h"
#include <memory>
#include <iostream>
#include <sstream>
#include <utility>
#include <cmath>

void array_figures() {
    std::cout << " array figures menu " << std::endl;
    int option = -1;

    Array<Figure<double>> figures;

    while (option != 0) {
        std::cout << "1. add triangle\n";
        std::cout << "2. add square\n";
        std::cout << "3. add rectangle\n";
        std::cout << "4. remove figure\n";
        std::cout << "5. print all figures\n";
        std::cout << "6. total area\n";
        std::cout << "0. - exit\n\n";
        std::cout << "choose option: ";
        std::cin >> option;
        std::cout << "\n";

        try {
            switch (option) {
            case 1: {
                auto triangle = std::make_shared<Triangle<double>>();
                std::cout << "enter 3 points (x y):\n";
                std::cin >> *triangle;
                figures.push(triangle);
                std::cout << "triangle added\n";
                break;
            }
            case 2: {
                auto square = std::make_shared<Square<double>>();
                std::cout << "enter 4 points (x y):\n";
                std::cin >> *square;
                figures.push(square);
                std::cout << "square added\n";
                break;
            }
            case 3: {
                auto rectangle = std::make_shared<Rectangle<double>>();
                std::cout << "enter 4 points (x y):\n";
                std::cin >> *rectangle;
                figures.push(rectangle);
                std::cout << "rectangle added\n";
                break;
            }
            case 4: {
                if (figures.isEmpty()) {
                    std::cout << "array is empty\n";
                    break;
                }
                std::cout << "enter index: ";
                size_t idx;
                std::cin >> idx;
                figures.remove(idx);
                std::cout << "figure removed\n";
                break;
            }
            case 5: {
                std::cout << figures;
                break;
            }
            case 6: {
                std::cout << "total area: " << figures.totalArea() << std::endl;
                break;
            }
            case 0:
                break;
            default: 
                std::cout << "invalid option\n";
            }
        } catch (const std::exception &e) {
            std::cout << "error: " << e.what() << "\n";
        }
    }
}

void array_derived() {
    std::cout << "\n array derived menu" << std::endl;
    int fig = -1;

    while (fig != 0) {
        std::cout << "1. triangle\n";
        std::cout << "2. square\n";
        std::cout << "3. rectangle\n";
        std::cout << "0. - exit\n\n";
        std::cout << "enter figure:\n";
        std::cin >> fig;
        std::cout << "\n";

        try {
            switch (fig) {
            case 1: {
                Array<Triangle<double>> triangles;
                int option = -1;

                while (option != 0) {
                    std::cout << "1. add triangle\n";
                    std::cout << "2. remove triangle\n";
                    std::cout << "3. print all triangles\n";
                    std::cout << "4. total area\n";
                    std::cout << "0. - exit\n\n";
                    std::cout << "choose option: ";
                    std::cin >> option;
                    std::cout << "\n";

                    try {
                        switch (option) {
                        case 1: {
                            auto triangle = std::make_shared<Triangle<double>>();
                            std::cout << "enter 3 points (x y):\n";
                            std::cin >> *triangle;
                            triangles.push(triangle);
                            std::cout << "triangle added\n";
                            break;
                        }
                        case 2: {
                            if (triangles.isEmpty()) {
                                std::cout << "array is empty\n";
                                break;
                            }
                            std::cout << "enter index: ";
                            size_t idx;
                            std::cin >> idx;
                            triangles.remove(idx);
                            std::cout << "figure removed\n";
                            break;
                        }
                        case 3: {
                            std::cout << triangles;
                            break;
                        }
                        case 4: {
                            std::cout << "total area: " << triangles.totalArea() << std::endl;
                            break;
                        }
                        case 0:
                            break;
                        default: 
                            std::cout << "invalid option\n";
                        }
                    } catch (const std::exception &e) {
                        std::cout << "error: " << e.what() << "\n";
                    }
                }
                break;
            }
            case 2: {
                Array<Square<double>> squares;
                int option = -1;

                while (option != 0) {
                    std::cout << "1. add square\n";
                    std::cout << "2. remove square\n";
                    std::cout << "3. print all squares\n";
                    std::cout << "4. total area\n";
                    std::cout << "0. - exit\n\n";
                    std::cout << "choose option: ";
                    std::cin >> option;
                    std::cout << "\n";

                    try {
                        switch (option) {
                        case 1: {
                            auto square = std::make_shared<Square<double>>();
                            std::cout << "enter 4 points (x y):\n";
                            std::cin >> *square;
                            squares.push(square);
                            std::cout << "square added\n";
                            break;
                        }
                        case 2: {
                            if (squares.isEmpty()) {
                                std::cout << "array is empty\n";
                                break;
                            }
                            std::cout << "enter index: ";
                            size_t idx;
                            std::cin >> idx;
                            squares.remove(idx);
                            std::cout << "figure removed\n";
                            break;
                        }
                        case 3: {
                            std::cout << squares;
                            break;
                        }
                        case 4: {
                            std::cout << "total area: " << squares.totalArea() << std::endl;
                            break;
                        }
                        case 0:
                            break;
                        default: 
                            std::cout << "invalid option\n";
                        }
                    } catch (const std::exception &e) {
                        std::cout << "error: " << e.what() << "\n";
                    }
                }
                break;
            }
            case 3: {
                Array<Rectangle<double>> rectangles;
                int option = -1;

                while (option != 0) {
                    std::cout << "1. add rectangle\n";
                    std::cout << "2. remove rectangle\n";
                    std::cout << "3. print all rectangles\n";
                    std::cout << "4. total area\n";
                    std::cout << "0. - exit\n\n";
                    std::cout << "choose option: ";
                    std::cin >> option;
                    std::cout << "\n";

                    try {
                        switch (option) {
                        case 1: {
                            auto rectangle = std::make_shared<Rectangle<double>>();
                            std::cout << "enter 4 points (x y):\n";
                            std::cin >> *rectangle;
                            rectangles.push(rectangle);
                            std::cout << "rectangle added\n";
                            break;
                        }
                        case 2: {
                            if (rectangles.isEmpty()) {
                                std::cout << "array is empty\n";
                                break;
                            }
                            std::cout << "enter index: ";
                            size_t idx;
                            std::cin >> idx;
                            rectangles.remove(idx);
                            std::cout << "figure removed\n";
                            break;
                        }
                        case 3: {
                            std::cout << rectangles;
                            break;
                        }
                        case 4: {
                            std::cout << "total area: " << rectangles.totalArea() << std::endl;
                            break;
                        }
                        case 0:
                            break;
                        default: 
                            std::cout << "invalid option\n";
                        }
                    } catch (const std::exception &e) {
                        std::cout << "error: " << e.what() << "\n";
                    }
                }
                break;
            }
            case 0:
                break;
            default: 
                std::cout << "invalid figure\n";
            }
        } catch (const std::exception &e) {
            std::cout << "error: " << e.what() << "\n";
        }
    }
}

int main() {
    int choose = -1;

    while (choose != 0) {
        std::cout << "1. demo figures array\n";
        std::cout << "2. demo derived array\n";
        std::cout << "0. - exit\n\n";
        std::cout << "choose option: ";
        std::cin >> choose;
        std::cout << "\n";
        try {
            switch (choose) {
            case 1: {
                array_figures();
                break;
            }
            case 2: {
                array_derived();
                break;
            }
            case 0:
                break;
            default: 
                std::cout << "invalid option\n";
            }
            std::cout << "\n program completed " << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return 1;
        }
    }

    return 0;
}