#pragma once
#include "expressions.hpp"
#include <memory>

namespace latexgen {
    /**
     * Different types of a unary expression
     */
    enum struct UnaryExpressionType {
        GROUPING, // (expr)
        PLUS, // +expr
        MINUS, // -expr
        ABSOLUTE_VALUE, // |expr|
        SQUARE_ROOT, // sqrt(expr)
        CUBE_ROOT, // cbrt(expr)
        FLOOR,
        CEILING
    };

    /**
     * Represents a unary expression, which is a kind of expression that only has one input
     */
    struct UnaryExpression : public Expression {
        UnaryExpressionType unary_type;
        std::shared_ptr<Expression> value;
        /**
         * A unary expression constructor
         * @param unary_type the type of operation for the unary expression, as listed in the enum `UnaryExpressionType`
         * @param value the value to perform the unary operation on
         */
        UnaryExpression(const UnaryExpressionType unary_type, const std::shared_ptr<Expression> &value);
        /**
         * Turns the desired unary expression into LaTeX
         * @return the desired LaTeX code for the unary expression
         */
        std::string to_latex() override;
    };
}