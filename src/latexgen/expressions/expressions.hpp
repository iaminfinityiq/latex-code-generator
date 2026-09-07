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
        Expression(ExpressionType type);
        virtual ~Expression() = default;
        /**
         * Turns the desired expression to LaTeX
         * @return the desired LaTeX code for the expression
         */
        virtual std::string to_latex() const;
        /**
         * Gets the expression type
         * @return the expression type
         */
        ExpressionType get_type() const;
    private:
        ExpressionType type;
    };
}