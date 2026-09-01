#include <iostream>
#include "latexgen/expressions/numbers.hpp"
#include "latexgen/expressions/text.hpp"
#include "latexgen/expressions/unary_expressions.hpp"

using namespace latexgen;

int main() {
    // Number test
    std::shared_ptr<Number> zero = std::make_shared<Number>("0");
    std::shared_ptr<Number> one = std::make_shared<Number>("1");

    std::cout << zero->to_latex() << " " << one->to_latex() << "\n";

    // Text test
    std::shared_ptr<Text> hello_world = std::make_shared<Text>("Hello World! :\\, welcome to {LaTeX} & I hope you have fun in there. I have $10 in my budget rn, my_budget = 10^1 # Assigns my budget. I also have a 10% discount");
    std::cout << hello_world->to_latex() << "\n";

    // Unary expression test
    std::shared_ptr<UnaryExpression> unary = std::make_shared<UnaryExpression>(UnaryExpressionType::CUBE_ROOT, one);
    std::cout << unary->to_latex() << "\n";
    return 0;
}