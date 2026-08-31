#include <iostream>
#include "latexgen/expressions/numbers.hpp"

using namespace latexgen;

int main() {
    Number zero = Number("0");
    Number one = Number("1");

    std::cout << zero.to_latex() << " " << one.to_latex();
    return 0;
}