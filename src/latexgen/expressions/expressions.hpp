#pragma once
#include "../items.hpp"
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
        VARIABLE,
        SET
    };

    /**
     * Base class for an expression
     */
    struct Expression : public Item {
    public:
        /**
         * An expression constructor
         * @param type the type of the expression
         */
        Expression(ExpressionType type);
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
