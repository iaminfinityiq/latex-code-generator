#include "latexgen/expressions/variables.hpp"
#include "latexgen/expressions/numbers.hpp"
#include "latexgen/expressions/binary_expressions.hpp"
#include "latexgen/expressions/unary_expressions.hpp"
#include <iostream>
#include <memory>

using namespace latexgen;

int main() {
    std::shared_ptr<Expression> discriminant = std::make_shared<Subtraction>(
        std::make_shared<Exponentiation>(
            std::make_shared<EnglishVariable>('b'),
            std::make_shared<Number>("2")
        ),
        std::make_shared<Multiplication>(
            std::make_shared<Multiplication>(
                std::make_shared<Number>("4"),
                std::make_shared<EnglishVariable>('a')
            ),
            std::make_shared<EnglishVariable>('c')
        )
    );

    std::shared_ptr<Expression> quadratic_formula = std::make_shared<Fraction>(
        std::make_shared<PlusMinus>(
            std::make_shared<UnaryMinus>(
                std::make_shared<EnglishVariable>('b')
            ),
            std::make_shared<SquareRoot>(discriminant)
        ),
        std::make_shared<Multiplication>(
            std::make_shared<Number>("2"),
            std::make_shared<EnglishVariable>('a')
        )
    );

    std::shared_ptr<Expression> quadratic_formula2 = std::make_shared<Fraction>(
        std::make_shared<PlusMinus>(
            std::make_shared<UnaryMinus>(
                std::make_shared<EnglishVariable>('b')
            ),
            std::make_shared<SquareRoot>(
                std::make_shared<GreekVariable>(GreekCharacter::UPPER_DELTA)
            )
        ),
        std::make_shared<Multiplication>(
            std::make_shared<Number>("2"),
            std::make_shared<EnglishVariable>('a')
        )
    );


    std::cout << quadratic_formula->to_latex() << "\\\\" << quadratic_formula2->to_latex();
    return 0;
}
