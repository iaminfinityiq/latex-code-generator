#pragma once
#include "expressions.hpp"
#include <memory>

namespace latexgen {
    /**
     * Different types of a binary expression
     */
    enum struct BinaryExpressionType {
        ADDITION, // left + right
        SUBTRACTION, // left - right
        MULTIPLICATION, // left * right (generalized form)
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
         * @param left left node
         * @param op binary expression type
         * @param right right node
         */
        BinaryExpression(const ExpressionOrDots &left, const BinaryExpressionType op, const ExpressionOrDots &right);
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
        /**
         * Gets the left side of the binary expression
         * @return the left side of the binary expression
         */
        ExpressionOrDots get_left() const;
        /**
         * Gets the right side of the binary expression
         * @return the right side of the binary expression
         */
        ExpressionOrDots get_right() const;
    private:
        ExpressionOrDots left;
        BinaryExpressionType op;
        ExpressionOrDots right;
    };

    /**
     * Checks if a binary expression is additive
     * @param binary the binary expression needed to check
     * @return `true` if the expression is additive, otherwise `false`
     */
    bool is_additive(const std::shared_ptr<BinaryExpression> &binary);
    /**
     * Checks if a binary expression is multiplicative
     * @param binary the binary expression needed to check
     * @return `true` if the expression is additive, otherwise `false`, note that fractions are multiplicative in this function
     */
    bool is_multiplicative(const std::shared_ptr<BinaryExpression> &binary);

    /**
     * Represents an addition operation
     */
    struct Addition : public BinaryExpression {
        /**
         * An addition constructor
         * @param left the left side of the expression
         * @param right the right side of the expression
         */
        Addition(const ExpressionOrDots &left, const ExpressionOrDots &right);
    };
    
    /**
     * Represents a subtraction operation
     */
    struct Subtraction : public BinaryExpression {
        /**
         * A subtraction constructor
         * @param left the left side of the expression
         * @param right the right side of the expression
         */
        Subtraction(const ExpressionOrDots &left, const ExpressionOrDots &right);
    };

    /**
     * Represents a multiplication operation
     */
    struct Multiplication : public BinaryExpression {
        /**
         * A multiplication constructor
         * @param left the left side of the expression
         * @param right the right side of the expression
         */
        Multiplication(const ExpressionOrDots &left, const ExpressionOrDots &right);
    };
    
    /**
     * Represents a division operation
     */
    struct Division : public BinaryExpression {
        /**
         * A division constructor
         * @param left the left side of the expression
         * @param right the right side of the expression
         */
        Division(const ExpressionOrDots &left, const ExpressionOrDots &right);
    };

    /**
     * Represents a fraction
     */
    struct Fraction : public BinaryExpression {
    public:
        /**
         * A fraction constructor
         * @param numerator the numerator
         * @param denominator the denominator
         * @param full_display decides if the numerator and denominator would stay in their original size
         */
        Fraction(const ExpressionOrDots &numerator, const ExpressionOrDots &denominator, const bool full_display = true);
        /**
         * Turns the desired fraction into LaTeX. Numerators/denominators may be smaller or not, which depends on the `full_display` parameter
         * @return the desired LaTeX code for the fraction
         */
        std::string to_latex() const override;
    private:
        bool full_display;
    };

    /**
     * Represents an exponent operation
     */
    struct Exponentiation : public BinaryExpression {
    public:
        /**
         * An exponentiation constructor
         * @param base the base
         * @param exponent the exponent
         * @param full_display decides if the exponent would stay in their original size
         */
        Exponentiation(const ExpressionOrDots &base, const ExpressionOrDots &exponent, const bool full_display = false);
        /**
         * Turns the desired exponentation expression into LaTeX. The exponent may be smaller or not, which depends on the `full_display` parameter
         * @return the desired LaTeX code for the exponentiation expression
         */
        std::string to_latex() const override;
    private:
        bool full_display;
    };

    /**
     * Represents a radication operation
     */
    struct Radication : public BinaryExpression {
    public:
        /**
         * A radication constructor
         * @param radicand the number to be applied
         * @param index the degree of the root
         * @param full_display decides if the index would stay in their original size
         */
        Radication(const ExpressionOrDots &radicand, const ExpressionOrDots &index, const bool full_display = false);
        /**
         * Turns the desired radication expression into LaTeX. The index may be smaller or not, which depends on the `full_display` parameter
         * @return the desired LaTeX code for the radication expression
         */
        std::string to_latex() const override;
    private:
        bool full_display;
    };

    /**
     * Represents a logarithm operation
     */
    struct Logarithm : public BinaryExpression {
    public:
        /**
         * A logarithm constructor
         * @param argument the argument of the logarithm
         * @param base the base of the logarithm
         * @param full_display decides if the base would stay in their original size
         */
        Logarithm(const ExpressionOrDots &argument, const ExpressionOrDots &base, const bool full_display = false);
        /**
         * Turns the desired radication expression into LaTeX. The base may be smaller or not, which depends on the `full_display` parameter
         * @return the desired LaTeX code for the logarithm expression
         */
        std::string to_latex() const override;
    private:
        bool full_display;
    };

    /**
     * Represents a plus or minus operation
     */
    struct PlusMinus : public BinaryExpression {
        /**
         * A plus or minus constructor
         * @param left the left side of the expression
         * @param right the right side of the expression
         */
        PlusMinus(const ExpressionOrDots &left, const ExpressionOrDots &right);
    };
    
    /**
     * Represents a minus or plus operation
     */
    struct MinusPlus : public BinaryExpression {
        /**
         * A minus or plus constructor
         * @param left the left side of the expression
         * @param right the right side of the expression
         */
        MinusPlus(const ExpressionOrDots &left, const ExpressionOrDots &right);
    };

    /**
     * Generates a pointer points to an addition expression
     * @param left the left side of the expression
     * @param right the right side of the expression
     * @return a pointer points to an addition expression, this pointer has a type of BinaryExpression*
     */
    std::shared_ptr<BinaryExpression> addition(const ExpressionOrDots &left, const ExpressionOrDots &right);

    /**
     * Generates a pointer points to a subtraction expression
     * @param left the left side of the expression
     * @param right the right side of the expression
     * @return a pointer points to a subtraction expression, this pointer has a type of BinaryExpression*
     */
    std::shared_ptr<BinaryExpression> subtraction(const ExpressionOrDots &left, const ExpressionOrDots &right);

    /**
     * Generates a pointer points to a multiplication expression
     * @param left the left side of the expression
     * @param right the right side of the expression
     * @return a pointer points to a multiplication expression, this pointer has a type of BinaryExpression*
     */
    std::shared_ptr<BinaryExpression> multiplication(const ExpressionOrDots &left, const ExpressionOrDots &right);

    /**
     * Generates a pointer points to a division expression
     * @param left the left side of the expression
     * @param right the right side of the expression
     * @return a pointer points to a division expression, this pointer has a type of BinaryExpression*
     */
    std::shared_ptr<BinaryExpression> division(const ExpressionOrDots &left, const ExpressionOrDots &right);

    /**
     * Generates a pointer points to a fraction
     * @param numerator the numerator
     * @param denominator the denominator
     * @return a pointer points to a fraction, this pointer has a type of BinaryExpression*
     */
    std::shared_ptr<BinaryExpression> fraction(const ExpressionOrDots &numerator, const ExpressionOrDots &denominator);

    /**
     * Generates a pointer points to an exponentiatino expression
     * @param base the base
     * @param exponent the exponent
     * @return a pointer points to an exponentiation expression, this pointer has a type of BinaryExpression*
     */
    std::shared_ptr<BinaryExpression> exponentiation(const ExpressionOrDots &base, const ExpressionOrDots &exponent);

    /**
     * Generates a pointer points to a radication expression
     * @param radicand the radicand
     * @param index the index
     * @return a pointer points to a radication expression, this pointer has a type of BinaryExpression*
     */
    std::shared_ptr<BinaryExpression> radication(const ExpressionOrDots &radicand, const ExpressionOrDots &index);

    /**
     * Generates a pointer points to an addition expression
     * @param argument the argument
     * @param base the base
     * @return a pointer points to a logarithm expression, this pointer has a type of BinaryExpression*
     */
    std::shared_ptr<BinaryExpression> logarithm(const ExpressionOrDots &argument, const ExpressionOrDots &base);

    /**
     * Generates a pointer points to a plus or minus expression
     * @param left the left side of the expression
     * @param right the right side of the expression
     * @return a pointer points to an addition expression, this pointer has a type of BinaryExpression*
     */
    std::shared_ptr<BinaryExpression> plus_minus(const ExpressionOrDots &left, const ExpressionOrDots &right);

    /**
     * Generates a pointer points to a minus or plus expression
     * @param left the left side of the expression
     * @param right the right side of the expression
     * @return a pointer points to an addition expression, this pointer has a type of BinaryExpression*
     */
    std::shared_ptr<BinaryExpression> minus_plus(const ExpressionOrDots &left, const ExpressionOrDots &right);
}
