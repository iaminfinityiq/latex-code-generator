#include <iostream>
#include "latexgen/expressions/numbers.hpp"
#include "latexgen/expressions/text.hpp"
#include "latexgen/expressions/unary_expressions.hpp"

using namespace latexgen;

int main() {
    // Number test
    const Number* const zero = new Number("0");
    const Number* const one = new Number("1");

    std::cout << zero->to_latex() << " " << one->to_latex() << "\n";

    // Text test
    const Text* const hello_world = new Text("Hello World! :\\, welcome to {LaTeX} & I hope you have fun in there. I have $10 in my budget rn, my_budget = 10^1 # Assigns my budget. I also have a 10% discount");
    std::cout << hello_world->to_latex() << "\n";

    // Unary expression test
    const UnaryExpression* const unary = new UnaryExpression(UnaryExpressionType::CUBE_ROOT, one);
    std::cout << unary->to_latex() << "\n";

    delete zero;
    delete one;
    delete hello_world;
    delete unary;
    return 0;
}