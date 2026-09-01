#pragma once
#include <string>

namespace latexgen {
    /**
     * Different types of an expression
     */
    enum struct ExpressionType {
        NUMBER,
        TEXT,
        UNARY,
        BINARY
    };

    /**
     * Base class for an expression
     */
    struct Expression {
    public:
        /**
         * An expression constructor
         * @param Expression type
         */
        Expression(const ExpressionType type);
        /**
         * Turns the desired expression to LaTeX
         * @return the desired LaTeX code for the expression
         */
        virtual std::string to_latex();
    private:
        ExpressionType type;
    };
}