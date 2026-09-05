#pragma once
#include "expressions.hpp"

namespace latexgen {
    /**
     * Different types of a unary expression
     */
    enum struct UnaryExpressionType {
        GROUPING, // (expr)
        PLUS, // +expr
        MINUS, // -expr
        ABSOLUTE_VALUE, // |expr|
        SQUARE_ROOT,
        CUBE_ROOT,
        FLOOR,
        CEILING
    };

    /**
     * Represents a unary expression, which is a kind of expression that only has one input
     */
    struct UnaryExpression : public Expression {
    public:
        /**
         * A unary expression constructor
         * @param unary_type the type of operation for the unary expression, as listed in the enum `UnaryExpressionType`
         * @param value the value to perform the unary operation on
         */
        UnaryExpression(const UnaryExpressionType unary_type, const Expression* const value);
        /**
         * Turns the desired unary expression into LaTeX
         * @return the desired LaTeX code for the unary expression
         */
        std::string to_latex() const override;
    private:
        const UnaryExpressionType unary_type;
        const Expression* value;
    };

    /**
     * Represents a unary plus expression, represented by +expr
     */
    struct UnaryPlus : public UnaryExpression {
        /**
         * A unary plus constructor
         * @param value represents the value to perform unary plus
         */
        UnaryPlus(const Expression* const value);
    };

    /**
     * Represents a unary minus expression, also known as negation, represented by -expr
     */
    struct UnaryMinus : public UnaryExpression {
        /**
         * A unary plus constructor
         * @param value represents the value to perform unary minus
         */
        UnaryMinus(const Expression* const value);
    };

    /**
     * Represents an absolute value expression, represented by |expr|
     */
    struct AbsoluteValue : public UnaryExpression {
        /**
         * An absolute value constructor
         * @param value represents the value to perform absolute value
         */
        AbsoluteValue(const Expression* const value);
    };

    /**
     * Represents a square root expression
     */
    struct SquareRoot : public UnaryExpression {
        /**
         * A square root constructor
         * @param value represents the value to perform square root
         */
        SquareRoot(const Expression* const value);
    };

    /**
     * Represents a cube root expression
     */
    struct CubeRoot : public UnaryExpression {
        /**
         * A cube root constructor
         * @param value represents the value to perform cube root
         */
        CubeRoot(const Expression* const value);
    };

    /**
     * Represents a floor expression
     */
    struct Floor : public UnaryExpression {
        /**
         * A floor constructor
         * @param value represents the value to perform flooring
         */
        Floor(const Expression* const value);
    };

    /**
     * Represents a ceiling expression
     */
    struct Ceiling : public UnaryExpression {
        /**
         * A ceiling constructor
         * @param value represents the value to perform ceiling
         */
        Ceiling(const Expression* const value);
    };
}