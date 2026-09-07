#pragma once
#include "expressions.hpp"

namespace latexgen {
    /**
     * Different types of a binary expression
     */
    enum struct BinaryExpressionType {
        ADDITION, // left + right
        SUBTRACTION, // left - right
        MULTIPLICATION_MUL, // left * right (using the × operator)
        MULTIPLICATION_DOT, // left * right (using the dot operator)
        MULTIPLICATION_NONE, // left * right (using no operator)
        DIVISION, // left ÷ right (using the division operator)
        FRACTION, // left / right (using fraction)
        EXPONENTIATION, // left^right
        RADICATION, // left-th root of right
        LOGARITHM, // log_left(right)
        PLUS_MINUS, // a +- b
        MINUS_PLUS // a -+ b
    };

    /**
     * Represents a binary expression, which is a kind of expression that only has two inputs
     */
    struct BinaryExpression : public Expression {
    public:
        /**
         * A binary expression constructor
         */
        BinaryExpression(const Expression* const left, const BinaryExpressionType op, const Expression* const right);
        /**
         * Turns the desired unary expression into LaTeX
         * @return the desired LaTeX code for the unary expression
         */
        std::string to_latex() const override;
        /**
         * Gets the binary expression type
         * @return the binary expression type
         */
        BinaryExpressionType get_binary_type() const;
    private:
        const Expression* left;
        const BinaryExpressionType op;
        const Expression* right;
    };

    /**
     * Checks if a binary expression is additive
     * @param the binary expression needed to check
     * @return `true` if the expression is additive, otherwise `false`
     */
    bool is_additive(const BinaryExpression* const binary);
    /**
     * Checks if a binary expression is multiplicative
     * @param the binary expression needed to check
     * @return `true` if the expression is additive, otherwise `false`, note that fractions are multiplicative in this function
     */
    bool is_multiplicative(const BinaryExpression* const binary);
}