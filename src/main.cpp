#include "latexgen/expressions/variables.hpp"
#include "latexgen/expressions/numbers.hpp"
#include "latexgen/expressions/binary_expressions.hpp"
#include "latexgen/expressions/unary_expressions.hpp"
#include <iostream>
#include <memory>

using namespace latexgen;

int main() {
    std::cout << "Test 1: " << std::make_shared<Addition>(
        std::make_shared<Number>("3"),
        std::make_shared<Number>("4")
    )->to_latex() << "\\\\";
    std::cout << "Test 2: " << std::make_shared<Subtraction>(
        std::make_shared<Number>("3"),
        std::make_shared<Number>("4")
    )->to_latex() << "\\\\";
    std::cout << "Test 3: " << std::make_shared<Multiplication>(
        std::make_shared<Number>("3"),
        std::make_shared<Number>("4")
    )->to_latex() << "\\\\";
    std::cout << "Test 4: " << std::make_shared<Division>(
        std::make_shared<Number>("3"),
        std::make_shared<Number>("4")
    )->to_latex() << "\\\\";
    std::cout << "Test 5: " << std::make_shared<Fraction>(
        std::make_shared<Number>("3"),
        std::make_shared<Number>("4")
    )->to_latex() << "\\\\";
    std::cout << "Test 6: " << std::make_shared<Addition>(
        std::make_shared<Variable>('a'),
        std::make_shared<Addition>(
            std::make_shared<Variable>('b'),
            std::make_shared<Variable>('c')
        )
    )->to_latex() << "\\\\";
    std::cout << "Test 7: " << std::make_shared<Addition>(
        std::make_shared<Variable>('a'),
        std::make_shared<Subtraction>(
            std::make_shared<Variable>('b'),
            std::make_shared<Variable>('c')
        )
    )->to_latex() << "\\\\";
    std::cout << "Test 8: " << std::make_shared<Subtraction>(
        std::make_shared<Variable>('a'),
        std::make_shared<Addition>(
            std::make_shared<Variable>('b'),
            std::make_shared<Variable>('c')
        )
    )->to_latex() << "\\\\";
    std::cout << "Test 9: " << std::make_shared<Subtraction>(
        std::make_shared<Variable>('a'),
        std::make_shared<Subtraction>(
            std::make_shared<Variable>('b'),
            std::make_shared<Variable>('c')
        )
    )->to_latex() << "\\\\";
    std::cout << "Test 10: " << std::make_shared<Addition>(
        std::make_shared<Variable>('a'),
        std::make_shared<Addition>(
            std::make_shared<Variable>('b'),
            std::make_shared<Variable>('c')
        )
    )->to_latex() << "\\\\";
    std::cout << "Test 11: " << std::make_shared<Addition>(
        std::make_shared<Variable>('a'),
        std::make_shared<Addition>(
            std::make_shared<Variable>('b'),
            std::make_shared<Subtraction>(
                std::make_shared<Variable>('c'),
                std::make_shared<Variable>('d')
            )
        )
    )->to_latex() << "\\\\";
    std::cout << "Test 12: " << std::make_shared<Multiplication>(
        std::make_shared<Variable>('a'),
        std::make_shared<Addition>(
            std::make_shared<Variable>('b'),
            std::make_shared<Variable>('c')
        )
    )->to_latex() << "\\\\";
    std::cout << "Test 13: " << std::make_shared<Multiplication>(
        std::make_shared<Addition>(
            std::make_shared<Variable>('a'),
            std::make_shared<Variable>('b')
        ),
        std::make_shared<Variable>('c')
    )->to_latex() << "\\\\";
    std::cout << "Test 14: " << std::make_shared<Multiplication>(
        std::make_shared<Variable>('a'),
        std::make_shared<Subtraction>(
            std::make_shared<Variable>('b'),
            std::make_shared<Variable>('c')
        )
    )->to_latex() << "\\\\";
    std::cout << "Test 15: " << std::make_shared<Multiplication>(
        std::make_shared<Subtraction>(
            std::make_shared<Variable>('a'),
            std::make_shared<Variable>('b')
        ),
        std::make_shared<Variable>('c')
    )->to_latex() << "\\\\";
    std::cout << "Test 16: " << std::make_shared<UnaryMinus>(
        std::make_shared<Number>("3")
    )->to_latex() << "\\\\";
    std::cout << "Test 17: " << std::make_shared<UnaryMinus>(
        std::make_shared<Variable>('x')
    )->to_latex() << "\\\\";
    std::cout << "Test 18: " << std::make_shared<Addition>(
        std::make_shared<UnaryMinus>(
            std::make_shared<Number>("3")
        ),
        std::make_shared<Number>("4")
    )->to_latex() << "\\\\";
    std::cout << "Test 19: " << std::make_shared<Addition>(
        std::make_shared<Number>("3"),
        std::make_shared<UnaryMinus>(
            std::make_shared<Number>("4")
        )
    )->to_latex() << "\\\\";
    std::cout << "Test 20: " << std::make_shared<Subtraction>(
        std::make_shared<Number>("3"),
        std::make_shared<UnaryMinus>(
            std::make_shared<Number>("4")
        )
    )->to_latex() << "\\\\";
    std::cout << "Test 21: " << std::make_shared<Subtraction>(
        std::make_shared<UnaryMinus>(
            std::make_shared<Number>("3")
        ),
        std::make_shared<Number>("4")
    )->to_latex() << "\\\\";
    std::cout << "Test 22: " << std::make_shared<Multiplication>(
        std::make_shared<UnaryMinus>(
            std::make_shared<Number>("3")
        ),
        std::make_shared<UnaryMinus>(
            std::make_shared<Number>("4")
        )
    )->to_latex() << "\\\\";
    std::cout << "Test 23: " << std::make_shared<Multiplication>(
        std::make_shared<UnaryMinus>(
            std::make_shared<Variable>('x')
        ),
        std::make_shared<Variable>('y')
    )->to_latex() << "\\\\";
    std::cout << "Test 24: " << std::make_shared<Multiplication>(
        std::make_shared<Variable>('x'),
        std::make_shared<UnaryMinus>(
            std::make_shared<Variable>('y')
        )
    )->to_latex() << "\\\\";
    std::cout << "Test 25: " << std::make_shared<Multiplication>(
        std::make_shared<UnaryMinus>(
            std::make_shared<Variable>('x')
        ),
        std::make_shared<UnaryMinus>(
            std::make_shared<Variable>('y')
        )
    )->to_latex() << "\\\\";
    std::cout << "Test 26: " << std::make_shared<Division>(
        std::make_shared<Variable>('a'),
        std::make_shared<Addition>(
            std::make_shared<Variable>('b'),
            std::make_shared<Variable>('c')
        )
    )->to_latex() << "\\\\";
    std::cout << "Test 27: " << std::make_shared<Division>(
        std::make_shared<Addition>(
            std::make_shared<Variable>('a'),
            std::make_shared<Variable>('b')
        ),
        std::make_shared<Variable>('c')
    )->to_latex() << "\\\\";
    std::cout << "Test 28: " << std::make_shared<Division>(
        std::make_shared<Multiplication>(
            std::make_shared<Variable>('a'),
            std::make_shared<Variable>('b')
        ),
        std::make_shared<Variable>('c')
    )->to_latex() << "\\\\";
    std::cout << "Test 29: " << std::make_shared<Division>(
        std::make_shared<Variable>('a'),
        std::make_shared<Multiplication>(
            std::make_shared<Variable>('b'),
            std::make_shared<Variable>('c')
        )
    )->to_latex() << "\\\\";
    std::cout << "Test 30: " << std::make_shared<Division>(
        std::make_shared<Variable>('a'),
        std::make_shared<Subtraction>(
            std::make_shared<Variable>('b'),
            std::make_shared<Variable>('c')
        )
    )->to_latex() << "\\\\";
    std::cout << "Test 31: " << std::make_shared<Division>(
        std::make_shared<Subtraction>(
            std::make_shared<Variable>('a'),
            std::make_shared<Variable>('b')
        ),
        std::make_shared<Variable>('c')
    )->to_latex() << "\\\\";
    std::cout << "Test 32: " << std::make_shared<Fraction>(
        std::make_shared<Variable>('a'),
        std::make_shared<Variable>('b')
    )->to_latex() << "\\\\";
    std::cout << "Test 33: " << std::make_shared<Fraction>(
        std::make_shared<Addition>(
            std::make_shared<Variable>('a'),
            std::make_shared<Variable>('b')
        ),
        std::make_shared<Addition>(
            std::make_shared<Variable>('c'),
            std::make_shared<Variable>('d')
        )
    )->to_latex() << "\\\\";
    std::cout << "Test 34: " << std::make_shared<Fraction>(
        std::make_shared<Multiplication>(
            std::make_shared<Variable>('a'),
            std::make_shared<Variable>('b')
        ),
        std::make_shared<Multiplication>(
            std::make_shared<Variable>('c'),
            std::make_shared<Variable>('d')
        )
    )->to_latex() << "\\\\";
    std::cout << "Test 35: " << std::make_shared<Fraction>(
        std::make_shared<Fraction>(
            std::make_shared<Variable>('a'),
            std::make_shared<Variable>('b')
        ),
        std::make_shared<Fraction>(
            std::make_shared<Variable>('c'),
            std::make_shared<Variable>('d')
        )
    )->to_latex() << "\\\\";
    std::cout << "Test 36: " << std::make_shared<Fraction>(
        std::make_shared<Fraction>(
            std::make_shared<Variable>('a'),
            std::make_shared<Variable>('b')
        ),
        std::make_shared<Fraction>(
            std::make_shared<Variable>('c'),
            std::make_shared<Variable>('d')
        ),
        false
    )->to_latex() << "\\\\";
    std::cout << "Test 37: " << std::make_shared<Exponentiation>(
        std::make_shared<Variable>('a'),
        std::make_shared<Variable>('b')
    )->to_latex() << "\\\\";
    std::cout << "Test 38: " << std::make_shared<Exponentiation>(
        std::make_shared<Variable>('a'),
        std::make_shared<Addition>(
            std::make_shared<Variable>('b'),
            std::make_shared<Variable>('c')
        )
    )->to_latex() << "\\\\";
    std::cout << "Test 39: " << std::make_shared<Exponentiation>(
        std::make_shared<Variable>('a'),
        std::make_shared<Multiplication>(
            std::make_shared<Variable>('b'),
            std::make_shared<Variable>('c')
        )
    )->to_latex() << "\\\\";
    std::cout << "Test 40: " << std::make_shared<Exponentiation>(
        std::make_shared<Addition>(
            std::make_shared<Variable>('a'),
            std::make_shared<Variable>('b')
        ),
        std::make_shared<Variable>('c')
    )->to_latex() << "\\\\";
    std::cout << "Test 41: " << std::make_shared<Exponentiation>(
        std::make_shared<Multiplication>(
            std::make_shared<Variable>('a'),
            std::make_shared<Variable>('b')
        ),
        std::make_shared<Variable>('c')
    )->to_latex() << "\\\\";
    std::cout << "Test 42: " << std::make_shared<Exponentiation>(
        std::make_shared<Exponentiation>(
            std::make_shared<Variable>('a'),
            std::make_shared<Variable>('b')
        ),
        std::make_shared<Variable>('c')
    )->to_latex() << "\\\\";
    std::cout << "Test 43: " << std::make_shared<Exponentiation>(
        std::make_shared<Variable>('a'),
        std::make_shared<Exponentiation>(
            std::make_shared<Variable>('b'),
            std::make_shared<Variable>('c')
        )
    )->to_latex() << "\\\\";
    std::cout << "Test 44: " << std::make_shared<Exponentiation>(
        std::make_shared<UnaryMinus>(
            std::make_shared<Variable>('a')
        ),
        std::make_shared<Variable>('b')
    )->to_latex() << "\\\\";
    std::cout << "Test 45: " << std::make_shared<Exponentiation>(
        std::make_shared<UnaryMinus>(
            std::make_shared<Variable>('a')
        ),
        std::make_shared<Number>("2")
    )->to_latex() << "\\\\";
    std::cout << "Test 46: " << std::make_shared<Exponentiation>(
        std::make_shared<Variable>('a'),
        std::make_shared<UnaryMinus>(
            std::make_shared<Variable>('b')
        )
    )->to_latex() << "\\\\";
    std::cout << "Test 47: " << std::make_shared<Exponentiation>(
        std::make_shared<Variable>('a'),
        std::make_shared<Addition>(
            std::make_shared<UnaryMinus>(
                std::make_shared<Variable>('b')
            ),
            std::make_shared<Variable>('c')
        )
    )->to_latex() << "\\\\";
    std::cout << "Test 48: " << std::make_shared<Exponentiation>(
        std::make_shared<UnaryMinus>(
            std::make_shared<Variable>('a')
        ),
        std::make_shared<UnaryMinus>(
            std::make_shared<Variable>('b')
        )
    )->to_latex() << "\\\\";
    std::cout << "Test 49: " << std::make_shared<Logarithm>(
        std::make_shared<UnaryMinus>(
            std::make_shared<Variable>('a')
        ),
        std::make_shared<Variable>('b')
    )->to_latex() << "\\\\";
    std::cout << "Test 50: " << std::make_shared<Logarithm>(
        std::make_shared<Variable>('a'),
        std::make_shared<Variable>('b')
    )->to_latex() << "\\\\";
    return 0;
}