#include <iostream>
#include <memory>
#include "latexgen/expressions/binary_expressions.hpp"
#include "latexgen/expressions/numbers.hpp"
#include "latexgen/statements/relational_statements.hpp"

using namespace latexgen;

int main() {
    std::shared_ptr<Number> one = std::make_shared<Number>("1");
    std::shared_ptr<Number> two = std::make_shared<Number>("2");
    std::shared_ptr<BinaryExpression> binom1 = std::make_shared<BinaryExpression>(
        one,
        BinaryExpressionType::MULTIPLICATION_MUL,
        two
    );

    std::shared_ptr<BinaryExpression> binom2 = std::make_shared<BinaryExpression>(
        two,
        BinaryExpressionType::MULTIPLICATION_MUL,
        one
    );

    std::shared_ptr<Equality> eq1 = std::make_shared<Equality>(
        binom1,
        binom2
    );

    std::shared_ptr<Equality> eq2 = std::make_shared<Equality>(
        eq1,
        two
    );

    std::cout << eq2->to_latex();
    return 0;
}
