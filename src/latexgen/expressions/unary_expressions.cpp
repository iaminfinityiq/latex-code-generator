#include "unary_expressions.hpp"
#include "binary_expressions.hpp"

namespace latexgen {
    UnaryExpression::UnaryExpression(const UnaryExpressionType op, const Expression* const value) : Expression(ExpressionType::UNARY), op(op), value(value) {}
    std::string UnaryExpression::to_latex() const {
        switch (this->op) {
            case UnaryExpressionType::GROUPING:
                return "\\left(" + this->value->to_latex() + "\\right)";
            case UnaryExpressionType::PLUS:
                if (this->value->get_type() == ExpressionType::BINARY) {
                    const BinaryExpression* const value_binary = static_cast<const BinaryExpression*>(this->value);
                    if (is_additive(value_binary)) {
                        return "+\\left(" + this->value->to_latex() + "\\right)";
                    }
                }

                return "+" + this->value->to_latex();
            case UnaryExpressionType::MINUS:
                if (this->value->get_type() == ExpressionType::BINARY) {
                    const BinaryExpression* const value_binary = static_cast<const BinaryExpression*>(this->value);
                    if (is_additive(value_binary)) {
                        return "-\\left(" + this->value->to_latex() + "\\right)";
                    }
                }

                return "-" + this->value->to_latex();
            case UnaryExpressionType::ABSOLUTE_VALUE:
                return "\\left|" + this->value->to_latex() + "\\right|";
            case UnaryExpressionType::SQUARE_ROOT:
                return "\\sqrt{" + this->value->to_latex() + "}";
            case UnaryExpressionType::CUBE_ROOT:
                return "\\sqrt[3]{" + this->value->to_latex() + "}";
            case UnaryExpressionType::FLOOR:
                return "\\left\\lfloor " + this->value->to_latex() + "\\right\\rfloor";
            case UnaryExpressionType::CEILING:
                return "\\left\\lceil " + this->value->to_latex() + "\\right\\rceil";
            default:
                return "this is broken";
        }
    }

    UnaryExpressionType UnaryExpression::get_unary_type() const {
        return this->op;
    }

    UnaryPlus::UnaryPlus(const Expression* const value) : UnaryExpression(UnaryExpressionType::PLUS, value) {}
    UnaryMinus::UnaryMinus(const Expression* const value) : UnaryExpression(UnaryExpressionType::MINUS, value) {}
    AbsoluteValue::AbsoluteValue(const Expression* const value) : UnaryExpression(UnaryExpressionType::ABSOLUTE_VALUE, value) {}
    SquareRoot::SquareRoot(const Expression* const value) : UnaryExpression(UnaryExpressionType::SQUARE_ROOT, value) {}
    CubeRoot::CubeRoot(const Expression* const value) : UnaryExpression(UnaryExpressionType::CUBE_ROOT, value) {}
    Floor::Floor(const Expression* const value) : UnaryExpression(UnaryExpressionType::FLOOR, value) {}
    Ceiling::Ceiling(const Expression* const value) : UnaryExpression(UnaryExpressionType::CEILING, value) {}

    UnaryExpression* unary_plus(const Expression* const value) {
        return new UnaryExpression(UnaryExpressionType::PLUS, value);
    }

    UnaryExpression* unary_minus(const Expression* const value) {
        return new UnaryExpression(UnaryExpressionType::MINUS, value);
    }

    UnaryExpression* absolute_value(const Expression* const value) {
        return new UnaryExpression(UnaryExpressionType::ABSOLUTE_VALUE, value);
    }

    UnaryExpression* square_root(const Expression* const value) {
        return new UnaryExpression(UnaryExpressionType::SQUARE_ROOT, value);
    }

    UnaryExpression* cube_root(const Expression* const value) {
        return new UnaryExpression(UnaryExpressionType::CUBE_ROOT, value);
    }

    UnaryExpression* floor(const Expression* const value) {
        return new UnaryExpression(UnaryExpressionType::FLOOR, value);
    }

    UnaryExpression* ceiling(const Expression* const value) {
        return new UnaryExpression(UnaryExpressionType::CEILING, value);
    }
}