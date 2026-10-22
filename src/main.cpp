#include "latexgen/expressions/numbers.hpp"
#include "latexgen/expressions/sets/predefined.hpp"
#include "latexgen/statements/relational_statements.hpp"
#include <iostream>

using namespace latexgen;

int main() {
    std::vector<std::variant<
        std::shared_ptr<Expression>,
        std::shared_ptr<Dots>
    >> naturals = {
        std::make_shared<Number>("1"),
        std::make_shared<Number>("2"),
        std::make_shared<Number>("3"),
        std::make_shared<Dots>()
    };

    std::shared_ptr<RelationalStatement> N = std::make_shared<RelationalStatement>(
        std::make_shared<Naturals>(),
        RelationalType::EQUALITY,
        std::make_shared<Set>(naturals)
    );

    std::cout << N->to_latex();
    return 0;
}
