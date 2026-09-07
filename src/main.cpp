#include <iostream>
#include "latexgen/expressions/numbers.hpp"
#include "latexgen/expressions/unary_expressions.hpp"
#include "latexgen/expressions/binary_expressions.hpp"

using namespace latexgen;

int main() {
    // Precendence test
    {
        const Number* const dummy1 = new Number("3.14159265358979");
        const Number* const dummy2 = new Number("2.718281828459045");
        const BinaryExpression* const dummy3 = new BinaryExpression(dummy1, BinaryExpressionType::ADDITION, dummy2);
        const UnaryExpression* const test = new UnaryExpression(UnaryExpressionType::MINUS, dummy3);
        std::cout << "Test 1: " << test->to_latex() << "\n";
        delete dummy1;
        delete dummy2;
        delete dummy3;
        delete test;
    }

    {
        const Number* const dummy1 = new Number("3.14159265358979");
        const Number* const dummy2 = new Number("2.718281828459045");
        const BinaryExpression* const dummy3 = new BinaryExpression(dummy1, BinaryExpressionType::ADDITION, dummy2);
        const UnaryExpression* const test = new UnaryExpression(UnaryExpressionType::PLUS, dummy3);
        std::cout << "Test 2: " << test->to_latex() << "\n";
        delete dummy1;
        delete dummy2;
        delete dummy3;
        delete test;
    }

    {
        const Number* const dummy1 = new Number("3.14159265358979");
        const Number* const dummy2 = new Number("2.718281828459045");
        const BinaryExpression* const dummy3 = new BinaryExpression(dummy1, BinaryExpressionType::ADDITION, dummy2);
        const BinaryExpression* const dummy4 = new BinaryExpression(dummy1, BinaryExpressionType::ADDITION, dummy2);
        const BinaryExpression* const test = new BinaryExpression(dummy3, BinaryExpressionType::PLUS_MINUS, dummy4);
        std::cout << "Test 3: " << test->to_latex() << "\n";
        delete dummy1;
        delete dummy2;
        delete dummy3;
        delete dummy4;
        delete test;
    }

    {
        const Number* const dummy1 = new Number("3.14159265358979");
        const Number* const dummy2 = new Number("2.718281828459045");
        const BinaryExpression* const dummy3 = new BinaryExpression(dummy1, BinaryExpressionType::ADDITION, dummy2);
        const BinaryExpression* const dummy4 = new BinaryExpression(dummy1, BinaryExpressionType::ADDITION, dummy2);
        const BinaryExpression* const test = new BinaryExpression(dummy3, BinaryExpressionType::MINUS_PLUS, dummy4);
        std::cout << "Test 4: " << test->to_latex() << "\n";
        delete dummy1;
        delete dummy2;
        delete dummy3;
        delete dummy4;
        delete test;
    }

    {
        const Number* const dummy1 = new Number("3.14159265358979");
        const Number* const dummy2 = new Number("2.718281828459045");
        const BinaryExpression* const dummy3 = new BinaryExpression(dummy1, BinaryExpressionType::ADDITION, dummy2);
        const BinaryExpression* const dummy4 = new BinaryExpression(dummy1, BinaryExpressionType::ADDITION, dummy2);
        const BinaryExpression* const test = new BinaryExpression(dummy3, BinaryExpressionType::ADDITION, dummy4);
        std::cout << "Test 5: " << test->to_latex() << "\n";
        delete dummy1;
        delete dummy2;
        delete dummy3;
        delete dummy4;
        delete test;
    }

    {
        const Number* const dummy1 = new Number("3.14159265358979");
        const Number* const dummy2 = new Number("2.718281828459045");
        const BinaryExpression* const dummy3 = new BinaryExpression(dummy1, BinaryExpressionType::ADDITION, dummy2);
        const BinaryExpression* const dummy4 = new BinaryExpression(dummy1, BinaryExpressionType::ADDITION, dummy2);
        const BinaryExpression* const test = new BinaryExpression(dummy3, BinaryExpressionType::SUBTRACTION, dummy4);
        std::cout << "Test 6: " << test->to_latex() << "\n";
        delete dummy1;
        delete dummy2;
        delete dummy3;
        delete dummy4;
        delete test;
    }

    {
        const Number* const dummy1 = new Number("3.14159265358979");
        const Number* const dummy2 = new Number("2.718281828459045");
        const BinaryExpression* const dummy3 = new BinaryExpression(dummy1, BinaryExpressionType::ADDITION, dummy2);
        const BinaryExpression* const dummy4 = new BinaryExpression(dummy1, BinaryExpressionType::ADDITION, dummy2);
        const BinaryExpression* const test = new BinaryExpression(dummy3, BinaryExpressionType::MULTIPLICATION_DOT, dummy4);
        std::cout << "Test 7: " << test->to_latex() << "\n";
        delete dummy1;
        delete dummy2;
        delete dummy3;
        delete dummy4;
        delete test;
    }

    {
        const Number* const dummy1 = new Number("3.14159265358979");
        const Number* const dummy2 = new Number("2.718281828459045");
        const BinaryExpression* const dummy3 = new BinaryExpression(dummy1, BinaryExpressionType::ADDITION, dummy2);
        const BinaryExpression* const dummy4 = new BinaryExpression(dummy1, BinaryExpressionType::ADDITION, dummy2);
        const BinaryExpression* const test = new BinaryExpression(dummy3, BinaryExpressionType::MULTIPLICATION_MUL, dummy4);
        std::cout << "Test 8: " << test->to_latex() << "\n";
        delete dummy1;
        delete dummy2;
        delete dummy3;
        delete dummy4;
        delete test;
    }

    {
        const Number* const dummy1 = new Number("3.14159265358979");
        const Number* const dummy2 = new Number("2.718281828459045");
        const BinaryExpression* const dummy3 = new BinaryExpression(dummy1, BinaryExpressionType::ADDITION, dummy2);
        const BinaryExpression* const dummy4 = new BinaryExpression(dummy1, BinaryExpressionType::ADDITION, dummy2);
        const BinaryExpression* const test = new BinaryExpression(dummy3, BinaryExpressionType::MULTIPLICATION_NONE, dummy4);
        std::cout << "Test 9: " << test->to_latex() << "\n";
        delete dummy1;
        delete dummy2;
        delete dummy3;
        delete dummy4;
        delete test;
    }

    {
        const Number* const dummy1 = new Number("3.14159265358979");
        const Number* const dummy2 = new Number("2.718281828459045");
        const BinaryExpression* const dummy3 = new BinaryExpression(dummy1, BinaryExpressionType::ADDITION, dummy2);
        const BinaryExpression* const dummy4 = new BinaryExpression(dummy1, BinaryExpressionType::ADDITION, dummy2);
        const BinaryExpression* const test = new BinaryExpression(dummy3, BinaryExpressionType::DIVISION, dummy4);
        std::cout << "Test 10: " << test->to_latex() << "\n";
        delete dummy1;
        delete dummy2;
        delete dummy3;
        delete dummy4;
        delete test;
    }

    {
        const Number* const dummy1 = new Number("3.14159265358979");
        const Number* const dummy2 = new Number("2.718281828459045");
        const BinaryExpression* const dummy3 = new BinaryExpression(dummy1, BinaryExpressionType::ADDITION, dummy2);
        const BinaryExpression* const dummy4 = new BinaryExpression(dummy1, BinaryExpressionType::ADDITION, dummy2);
        const BinaryExpression* const test = new BinaryExpression(dummy3, BinaryExpressionType::FRACTION, dummy4);
        std::cout << "Test 11: " << test->to_latex() << "\n";
        delete dummy1;
        delete dummy2;
        delete dummy3;
        delete dummy4;
        delete test;
    }
    
    return 0;
}