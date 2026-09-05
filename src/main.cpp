#include <iostream>
#include "latexgen/expressions/unary_expressions.hpp"
#include "latexgen/expressions/numbers.hpp"

using namespace latexgen;

int main() {
    // Unary expression tests
    Expression* dummy = new Number("3.141592");
    UnaryPlus* unary_plus = new UnaryPlus(dummy);
    UnaryMinus* unary_minus = new UnaryMinus(dummy);
    AbsoluteValue* absolute_value = new AbsoluteValue(dummy);
    SquareRoot* square_root = new SquareRoot(dummy);
    CubeRoot* cube_root = new CubeRoot(dummy);
    Floor* floor = new Floor(dummy);
    Ceiling* ceiling = new Ceiling(dummy);

    std::cout << dummy->to_latex() << "\n"
        << unary_plus->to_latex() << "\n"
        << unary_minus->to_latex() << "\n"
        << absolute_value->to_latex() << "\n"
        << square_root->to_latex() << "\n"
        << cube_root->to_latex() << "\n"
        << floor->to_latex() << "\n"
        << ceiling->to_latex() << "\n";

    // Free the memory
    delete dummy;
    delete unary_plus;
    delete unary_minus;
    delete absolute_value;
    delete square_root;
    delete cube_root;
    delete floor;
    delete ceiling;
    return 0;
}