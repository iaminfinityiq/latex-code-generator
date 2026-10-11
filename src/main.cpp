#include "latexgen/expressions/variables.hpp"
#include "latexgen/expressions/numbers.hpp"
#include "latexgen/expressions/binary_expressions.hpp"
#include "latexgen/expressions/unary_expressions.hpp"
#include "latexgen/statements/relational_statements.hpp"
#include <iostream>
#include <memory>

using namespace latexgen;

int main() {
    std::shared_ptr<EnglishVariable> a = std::make_shared<EnglishVariable>('a');
    std::shared_ptr<EnglishVariable> b = std::make_shared<EnglishVariable>('b');
    std::shared_ptr<EnglishVariable> c = std::make_shared<EnglishVariable>('c');
    std::shared_ptr<EnglishVariable> x = std::make_shared<EnglishVariable>('x');
    std::shared_ptr<RelationalStatement> original_equation = std::make_shared<RelationalStatement>(
        std::make_shared<Addition>(
            std::make_shared<Addition>(
                std::make_shared<Multiplication>(
                    a,
                    std::make_shared<Exponentiation>(
                        x,
                        std::make_shared<Number>("2")
                    )
                ),
                std::make_shared<Multiplication>(
                    b,
                    x
                )
            ),
            c
        ),
        RelationalType::EQUALITY,
        std::make_shared<Number>("0")
    );

    std::shared_ptr<RelationalStatement> quadratic_formula = std::make_shared<RelationalStatement>(
        x,
        RelationalType::EQUALITY,
        std::make_shared<Fraction>(
            std::make_shared<PlusMinus>(
                std::make_shared<UnaryMinus>(
                    b
                ),
                std::make_shared<SquareRoot>(
                    std::make_shared<Subtraction>(
                        std::make_shared<Exponentiation>(
                            b,
                            std::make_shared<Number>("2")
                        ),
                        std::make_shared<Multiplication>(
                            std::make_shared<Multiplication>(
                                std::make_shared<Number>("4"),
                                a
                            ),
                            c
                        )
                    )
                )
            ),
            std::make_shared<Multiplication>(
                std::make_shared<Number>("2"),
                a
            )
        )
    );

    std::cout << original_equation->to_latex() << "\\\\\\Leftrightarrow " << quadratic_formula->to_latex();
    return 0;
}
