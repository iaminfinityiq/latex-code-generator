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
        FLOOR, // floor(expr)
        CEILING // ceil(expr)
    };

    /**
     * Represents a unary expression, which is a kind of expression that only has one input
     */
    struct UnaryExpression : public Expression {
    public:
        /**
         * A unary expression constructor
         * @param op the type of operation for the unary expression, as listed in the enum `UnaryExpressionType`
         * @param value the value to perform the unary operation on
         */
        UnaryExpression(const UnaryExpressionType op, const std::shared_ptr<Expression> &value);
        /**
         * Turns the desired unary expression into LaTeX
         * @return the desired LaTeX code for the unary expression
         */
        std::string to_latex() const override;
        /**
         * Gets the unary expression type
         * @return the unary expression type
         */
        UnaryExpressionType get_unary_type() const;
        /**
         * Gets the value to perform on
         * @return the value to perform on
         */
        std::shared_ptr<Expression> get_value() const;
    private:
        const UnaryExpressionType op;
        const std::shared_ptr<Expression> value;
    };

    /**
     * Checks if a unary expression is a unary additive (+expr or -expr)
     * @param unary the unary expression needed to check
     * @return `true` if the expression is unary additive, otherwise `false`
     */
    bool is_unary_additive(const std::shared_ptr<UnaryExpression> &unary);

    /**
     * Represents a unary plus expression, represented by +expr
     */
    struct UnaryPlus : public UnaryExpression {
        /**
         * A unary plus constructor
         * @param value represents the value to perform unary plus
         */
        UnaryPlus(const std::shared_ptr<Expression> &value);
    };

    /**
     * Represents a unary minus expression, also known as negation, represented by -expr
     */
    struct UnaryMinus : public UnaryExpression {
        /**
         * A unary plus constructor
         * @param value represents the value to perform unary minus
         */
        UnaryMinus(const std::shared_ptr<Expression> &value);
    };

    /**
     * Represents an absolute value expression, represented by |expr|
     */
    struct AbsoluteValue : public UnaryExpression {
        /**
         * An absolute value constructor
         * @param value represents the value to perform absolute value
         */
        AbsoluteValue(const std::shared_ptr<Expression> &value);
    };

    /**
     * Represents a square root expression
     */
    struct SquareRoot : public UnaryExpression {
        /**
         * A square root constructor
         * @param value represents the value to perform square root
         */
        SquareRoot(const std::shared_ptr<Expression> &value);
    };

    /**
     * Represents a cube root expression
     */
    struct CubeRoot : public UnaryExpression {
        /**
         * A cube root constructor
         * @param value represents the value to perform cube root
         */
        CubeRoot(const std::shared_ptr<Expression> &value);
    };

    /**
     * Represents a floor expression
     */
    struct Floor : public UnaryExpression {
        /**
         * A floor constructor
         * @param value represents the value to perform flooring
         */
        Floor(const std::shared_ptr<Expression> &value);
    };

    /**
     * Represents a ceiling expression
     */
    struct Ceiling : public UnaryExpression {
        /**
         * A ceiling constructor
         * @param value represents the value to perform ceiling
         */
        Ceiling(const std::shared_ptr<Expression> &value);
    };

    /**
     * Generates a pointer to a new instance of unary plus
     * @param value represents the value to perform unary plus
     * @return a pointer to a new instance of unary plus, this pointer has a type of UnaryExpression*
     */
    std::shared_ptr<UnaryExpression> unary_plus(const std::shared_ptr<Expression> &value);
    /**
     * Generates a pointer to a new instance of unary minus
     * @param value represents the value to perform unary minus
     * @return a pointer to a new instance of unary minus, this pointer has a type of UnaryExpression*
     */
    std::shared_ptr<UnaryExpression> unary_minus(const std::shared_ptr<Expression> &value);
    /**
     * Generates a pointer to a new instance of absolute value
     * @param value represents the value to perform absolute value
     * @return a pointer to a new instance of absolute value, this pointer has a type of UnaryExpression*
     */
    std::shared_ptr<UnaryExpression> absolute_value(const std::shared_ptr<Expression> &value);
    /**
     * Generates a pointer to a new instance of square root
     * @param value represents the value to perform square root
     * @return a pointer to a new instance of square root, this pointer has a type of UnaryExpression*
     */
    std::shared_ptr<UnaryExpression> square_root(const std::shared_ptr<Expression> &value);
    /**
     * Generates a pointer to a new instance of cube root
     * @param value represents the value to perform cube root
     * @return a pointer to a new instance of cube root, this pointer has a type of UnaryExpression*
     */
    std::shared_ptr<UnaryExpression> cube_root(const std::shared_ptr<Expression> &value);
    /**
     * Generates a pointer to a new instance of flooring
     * @param value represents the value to perform a floor operation
     * @return a pointer to a new instance of flooring, this pointer has a type of UnaryExpression*
     */
    std::shared_ptr<UnaryExpression> floor(const std::shared_ptr<Expression> &value);
    /**
     * Generates a pointer to a new instance of ceiling
     * @param value represents the value to perform a ceiling operation
     * @return a pointer to a new instance of ceiling, this pointer has a type of UnaryExpression*
     */
    std::shared_ptr<UnaryExpression> ceiling(const std::shared_ptr<Expression> &value);
}