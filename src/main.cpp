#include "latexgen/expressions/sets.hpp"
#include "latexgen/expressions/numbers.hpp"
#include "latexgen/expressions/binary_expressions.hpp"
#include <iostream>

using namespace latexgen;

int main() {
    std::vector<std::shared_ptr<Expression>> normal_elements = {
        std::make_shared<Number>("1"),
        std::make_shared<Number>("2"),
        std::make_shared<Number>("3"),
        std::make_shared<Number>("4"),
        std::make_shared<Fraction>(
            std::make_shared<Number>("5"),
            std::make_shared<Number>("6")
        )
    };
    std::shared_ptr<Set> normal_set = std::make_shared<Set>(normal_elements);
    std::cout << normal_set->to_latex();
    return 0;
}
