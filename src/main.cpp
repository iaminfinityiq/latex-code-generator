#include "latexgen/expressions/numbers.hpp"
#include "latexgen/expressions/text.hpp"
#include "latexgen/expressions/binary_expressions.hpp"
#include <iostream>
#include <memory>

using namespace latexgen;

int main() {
    std::cout << std::make_shared<Multiplication>(
        std::make_shared<Multiplication>(
            std::make_shared<Fraction>(
                std::make_shared<Multiplication>(
                    std::make_shared<Number>("7.3"),
                    std::make_shared<Text>("meters")
                ),
                std::make_shared<Multiplication>(
                    std::make_shared<Number>("1"),
                    std::make_shared<Exponentiation>(
                        std::make_shared<Text>("s"),
                        std::make_shared<Number>("2")
                    )
                )
            ),
            std::make_shared<Fraction>(
                std::make_shared<Multiplication>(
                    std::make_shared<Number>("60"),
                    std::make_shared<Text>("s")
                ),
                std::make_shared<Multiplication>(
                    std::make_shared<Number>("1"),
                    std::make_shared<Text>("min")
                )
            )
        ),
        std::make_shared<Fraction>(
            std::make_shared<Multiplication>(
                std::make_shared<Number>("1"),
                std::make_shared<Text>("mi")
            ),
            std::make_shared<Number>("1609")
        )
    )->to_latex();
    return 0;
}
