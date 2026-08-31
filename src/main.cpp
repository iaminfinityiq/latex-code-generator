#include <iostream>
#include "latexgen/expressions/numbers.hpp"
#include "latexgen/expressions/text.hpp"

using namespace latexgen;

int main() {
    // Number test
    Number zero = Number("0");
    Number one = Number("1");

    std::cout << zero.to_latex() << " " << one.to_latex() << "\n";

    // Text test
    Text hello_world = Text("Hello World! :\\, welcome to {LaTeX} & I hope you have fun in there. I have $10 in my budget rn, my_budget = 10^1 # Assigns my budget. I also have a 10% discount");
    std::cout << hello_world.to_latex() << "\n";
    hello_world = Text("Hello World! :\\, welcome to {LaTeX} & I hope you have fun in there.\nI have $10 in my budget rn, my_budget = 10^1 # Assigns my budget. I also have a 10% discount");
    std::cout << hello_world.to_latex() << "\n";
    return 0;
}