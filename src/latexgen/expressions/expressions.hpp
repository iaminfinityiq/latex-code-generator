#pragma once
#include <string>
#include <memory>

namespace latexgen {
    /**
     * Different types of an expression
     */
    enum struct ExpressionType {
        NUMBER,
        TEXT,
        UNARY,
        BINARY,
        VARIABLE
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

    /**
     * Checks if an expression is a primary expression
     * @param expr the expression needed to check
     * @return `true` if the desired expression is a primary expression, otherwise `false`
     */
    bool is_primary(const std::shared_ptr<Expression> &expr);
}