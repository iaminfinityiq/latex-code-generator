#include "latexgen/dots.hpp"
#include "latexgen/expressions/sets.hpp"
#include "latexgen/expressions/numbers.hpp"
#include "latexgen/expressions/variables.hpp"
#include "latexgen/statements/relational_statements.hpp"
#include <iostream>
#include <memory>
#include <variant>

using namespace latexgen;

int main() {
    std::vector<std::variant<
        std::shared_ptr<Expression>,
        std::shared_ptr<Dots>
    >> natural_numbers = {
        std::make_shared<Number>("1"),
        std::make_shared<Number>("2"),
        std::make_shared<Number>("3"),
        std::make_shared<Dots>()
    };
    std::shared_ptr<RelationalStatement> relational = std::make_shared<RelationalStatement>(
        std::make_shared<EnglishVariable>('N'),
        RelationalType::EQUALITY,
        std::make_shared<Set>(natural_numbers)
    );

    std::cout << relational->to_latex();
    return 0;
}
