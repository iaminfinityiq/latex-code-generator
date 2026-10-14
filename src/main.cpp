#include "latexgen/expressions/variables.hpp"
#include "latexgen/expressions/numbers.hpp"
#include "latexgen/expressions/unary_expressions.hpp"
#include "latexgen/expressions/binary_expressions.hpp"
#include "latexgen/statements/relational_statements.hpp"
#include <iostream>
#include <memory>

using namespace latexgen;

int main() {
    // Variables
    std::shared_ptr<EnglishVariable> a = std::make_shared<EnglishVariable>('a');
    std::shared_ptr<EnglishVariable> b = std::make_shared<EnglishVariable>('b');
    std::shared_ptr<EnglishVariable> c = std::make_shared<EnglishVariable>('c');
    std::shared_ptr<EnglishVariable> d = std::make_shared<EnglishVariable>('d');
    std::shared_ptr<EnglishVariable> x = std::make_shared<EnglishVariable>('x');

    // Numbers
    std::shared_ptr<Number> three = std::make_shared<Number>("3");
    std::shared_ptr<Number> two = std::make_shared<Number>("2");
    std::shared_ptr<Number> one = std::make_shared<Number>("1");
    std::shared_ptr<Number> zero = std::make_shared<Number>("0");
    std::shared_ptr<Number> six = std::make_shared<Number>("6");
    std::shared_ptr<Number> twenty_seven = std::make_shared<Number>("27");
    std::shared_ptr<Number> nine = std::make_shared<Number>("9");

    std::shared_ptr<RelationalStatement> original_statement = std::make_shared<RelationalStatement>(
        std::make_shared<Addition>(
            std::make_shared<Addition>(
                std::make_shared<Addition>(
                    std::make_shared<Multiplication>(
                        a,
                        std::make_shared<Exponentiation>(
                            x,
                            three
                        )
                    ),
                    std::make_shared<Multiplication>(
                        b,
                        std::make_shared<Exponentiation>(
                            x,
                            two
                        )
                    )
                ),
                std::make_shared<Multiplication>(
                    c,
                    x
                )
            ),
            d
        ),
        RelationalType::EQUALITY,
        zero
    );

    std::shared_ptr<Subtraction> section1 = std::make_shared<Subtraction>(
        std::make_shared<Subtraction>(
            std::make_shared<Fraction>(
                std::make_shared<Multiplication>(
                    b,
                    c
                ),
                std::make_shared<Multiplication>(
                    six,
                    std::make_shared<Exponentiation>(
                        a,
                        two
                    )
                )
            ),
            std::make_shared<Fraction>(
                d,
                std::make_shared<Multiplication>(
                    two,
                    a
                )
            )
        ),
        std::make_shared<Fraction>(
            std::make_shared<Exponentiation>(
                b,
                three
            ),
            std::make_shared<Multiplication>(
                twenty_seven,
                std::make_shared<Exponentiation>(
                    a,
                    three
                )
            )
        )
    );

    std::shared_ptr<Subtraction> section2 = std::make_shared<Subtraction>(
        std::make_shared<Fraction>(
            c,
            std::make_shared<Multiplication>(
                three,
                a
            )
        ),
        std::make_shared<Fraction>(
            std::make_shared<Exponentiation>(
                b,
                two
            ),
            std::make_shared<Multiplication>(
                nine,
                std::make_shared<Exponentiation>(
                    a,
                    two
                )
            )
        )
    );

    std::shared_ptr<RelationalStatement> cubic_formula = std::make_shared<RelationalStatement>(
        x,
        RelationalType::EQUALITY,
        std::make_shared<Subtraction>(
            std::make_shared<Addition>(
                std::make_shared<CubeRoot>(
                    std::make_shared<Addition>(
                        section1,
                        std::make_shared<SquareRoot>(
                            std::make_shared<Addition>(
                                std::make_shared<Exponentiation>(
                                    section1,
                                    two
                                ),
                                std::make_shared<Exponentiation>(
                                    section2,
                                    three
                                )
                            )
                        )
                    )
                ),
                std::make_shared<CubeRoot>(
                    std::make_shared<Subtraction>(
                        section1,
                        std::make_shared<SquareRoot>(
                            std::make_shared<Addition>(
                                std::make_shared<Exponentiation>(
                                    section1,
                                    two
                                ),
                                std::make_shared<Exponentiation>(
                                    section2,
                                    three
                                )
                            )
                        )
                    )

                )
            ),
            std::make_shared<Fraction>(
                b,
                std::make_shared<Multiplication>(
                    three,
                    a
                )
            )
        )
    );

    std::cout << original_statement->to_latex() << "\\\\\\Rightarrow " << cubic_formula->to_latex();
    return 0;
}
