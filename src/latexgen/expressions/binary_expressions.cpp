#include "binary_expressions.hpp"

namespace latexgen {
    bool is_additive(const BinaryExpression* const binary) {
        BinaryExpressionType type = binary->get_binary_type();
        return type == BinaryExpressionType::ADDITION || type == BinaryExpressionType::SUBTRACTION;
    }

    bool is_multiplicative(const BinaryExpression* const binary) {
        BinaryExpressionType type = binary->get_binary_type();
        return type == BinaryExpressionType::MULTIPLICATION_DOT || type == BinaryExpressionType::MULTIPLICATION_MUL || type == BinaryExpressionType::MULTIPLICATION_NONE
            || type == BinaryExpressionType::DIVISION || type == BinaryExpressionType::FRACTION;
    }

    bool _is_multiplicative(const BinaryExpression* const binary) {
        BinaryExpressionType type = binary->get_binary_type();
        return type == BinaryExpressionType::MULTIPLICATION_DOT || type == BinaryExpressionType::MULTIPLICATION_MUL || type == BinaryExpressionType::MULTIPLICATION_NONE
            || type == BinaryExpressionType::DIVISION;
    }
    
    BinaryExpression::BinaryExpression(const Expression* const left, const BinaryExpressionType op, const Expression* const right) : Expression(ExpressionType::BINARY), left(left), op(op), right(right) {}
    std::string BinaryExpression::to_latex() const {
        switch (this->op) {
            case BinaryExpressionType::ADDITION:
                return left->to_latex() + "+" + right->to_latex();
            case BinaryExpressionType::SUBTRACTION:
                if (right->get_type() == ExpressionType::BINARY) {
                    const BinaryExpression* const right_binary = static_cast<const BinaryExpression*>(right);
                    if (is_additive(right_binary)) {
                        return left->to_latex() + "-\\left( " + right->to_latex() + " \\right)";
                    }
                }

                return left->to_latex() + "-" + right->to_latex();
            case BinaryExpressionType::MULTIPLICATION_MUL: {
                bool group_left = false;
                bool group_right = false;

                if (left->get_type() == ExpressionType::BINARY) {
                    const BinaryExpression* const left_binary = static_cast<const BinaryExpression*>(right);
                    if (is_additive(left_binary)) {
                        group_left = true;
                    }
                }

                if (right->get_type() == ExpressionType::BINARY) {
                    const BinaryExpression* const right_binary = static_cast<const BinaryExpression*>(right);
                    if (is_additive(right_binary)) {
                        group_right = true;
                    }
                }

                return (group_left ? "\\left(" : "") + left->to_latex() + (group_left ? "\\right)\\times " : "\\times ") + (group_right ? "\\left(" : "") + right->to_latex() + (group_right ? "\\right)" : "");
            } case BinaryExpressionType::MULTIPLICATION_DOT: {
                bool group_left = false;
                bool group_right = false;

                if (left->get_type() == ExpressionType::BINARY) {
                    const BinaryExpression* const left_binary = static_cast<const BinaryExpression*>(right);
                    if (is_additive(left_binary)) {
                        group_left = true;
                    }
                }

                if (right->get_type() == ExpressionType::BINARY) {
                    const BinaryExpression* const right_binary = static_cast<const BinaryExpression*>(right);
                    if (is_additive(right_binary)) {
                        group_right = true;
                    }
                }

                return (group_left ? "\\left(" : "") + left->to_latex() + (group_left ? "\\right)\\cdot " : "\\cdot ") + (group_right ? "\\left(" : "") + right->to_latex() + (group_right ? "\\right)" : "");
            } case BinaryExpressionType::MULTIPLICATION_NONE: {
                bool group_left = false;
                bool group_right = false;

                if (left->get_type() == ExpressionType::BINARY) {
                    const BinaryExpression* const left_binary = static_cast<const BinaryExpression*>(right);
                    if (is_additive(left_binary)) {
                        group_left = true;
                    }
                }

                if (right->get_type() == ExpressionType::BINARY) {
                    const BinaryExpression* const right_binary = static_cast<const BinaryExpression*>(right);
                    if (is_additive(right_binary)) {
                        group_right = true;
                    }
                }

                return (group_left ? "\\left(" : "") + left->to_latex() + (group_left ? "\\right)" : " ") + (group_right ? "\\left(" : "") + right->to_latex() + (group_right ? "\\right)" : "");
            } case BinaryExpressionType::DIVISION: {
                bool group_left = false;
                bool group_right = false;

                if (left->get_type() == ExpressionType::BINARY) {
                    const BinaryExpression* const left_binary = static_cast<const BinaryExpression*>(right);
                    if (is_additive(left_binary)) {
                        group_left = true;
                    }
                }

                if (right->get_type() == ExpressionType::BINARY) {
                    const BinaryExpression* const right_binary = static_cast<const BinaryExpression*>(right);
                    if (is_additive(right_binary)) {
                        group_right = true;
                    }
                }

                return (group_left ? "\\left(" : "") + left->to_latex() + (group_left ? "\\right)\\divisionsymbol " : "\\divisionsymbol ") + (group_right ? "\\left(" : "") + right->to_latex() + (group_right ? "\\right)" : "");
            } case BinaryExpressionType::FRACTION:
                return "\\frac{" + left->to_latex() + "}{" + right->to_latex() + "}";
            case BinaryExpressionType::EXPONENTIATION:
                return left->to_latex() + "^{" + right->to_latex() + "}";
            case BinaryExpressionType::RADICATION:
                return "\\sqrt[" + left->to_latex() + "]{" + right->to_latex() + "}";
            case BinaryExpressionType::LOGARITHM:
                return "\\log_{" + left->to_latex() + "}{" + right->to_latex() + "}";
            case BinaryExpressionType::PLUS_MINUS:
                if (right->get_type() == ExpressionType::BINARY) {
                    const BinaryExpression* const right_binary = static_cast<const BinaryExpression*>(right);
                    if (is_additive(right_binary)) {
                        return left->to_latex() + "\\pm\\left( " + right->to_latex() + " \\right)";
                    }
                }

                return left->to_latex() + "\\pm " + right->to_latex();
            case BinaryExpressionType::MINUS_PLUS:
                if (right->get_type() == ExpressionType::BINARY) {
                    const BinaryExpression* const right_binary = static_cast<const BinaryExpression*>(right);
                    if (is_additive(right_binary)) {
                        return left->to_latex() + "\\mp\\left( " + right->to_latex() + " \\right)";
                    }
                }

                return left->to_latex() + "\\mp " + right->to_latex();
            default:
                return "this is broken";
        }
    }

    BinaryExpressionType BinaryExpression::get_binary_type() const {
        return this->op;
    }
}