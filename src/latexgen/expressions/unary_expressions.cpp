#include "unary_expressions.hpp"

namespace latexgen {
    UnaryExpression::UnaryExpression(const UnaryExpressionType unary_type, const Expression* const value) : Expression(ExpressionType::UNARY), unary_type(unary_type), value(value) {}

    std::string UnaryExpression::to_latex() const {
        switch (this->unary_type) {
            case UnaryExpressionType::GROUPING:
                return "\\left( " + this->value->to_latex() + " \\right)";
            case UnaryExpressionType::PLUS:
                return "+" + this->value->to_latex();
            case UnaryExpressionType::MINUS:
                return "-" + this->value->to_latex();
            case UnaryExpressionType::ABSOLUTE_VALUE:
                return "\\left| " + this->value->to_latex() + " \\right|";
            case UnaryExpressionType::SQUARE_ROOT:
                return "\\sqrt{" + this->value->to_latex() + "}";
            case UnaryExpressionType::CUBE_ROOT:
                return "\\sqrt[3]{" + this->value->to_latex() + "}";
            case UnaryExpressionType::FLOOR:
                return "\\left\\lfloor " + this->value->to_latex() + " \\right\\rfloor";
            case UnaryExpressionType::CEILING:
                return "\\left\\lceil " + this->value->to_latex() + " \\right\\rceil";
            default:
                return "this is broken";
        }
    }

    UnaryPlus::UnaryPlus(const Expression* const value) : UnaryExpression(UnaryExpressionType::PLUS, value) {}
    UnaryMinus::UnaryMinus(const Expression* const value) : UnaryExpression(UnaryExpressionType::MINUS, value) {}
    AbsoluteValue::AbsoluteValue(const Expression* const value) : UnaryExpression(UnaryExpressionType::ABSOLUTE_VALUE, value) {}
    SquareRoot::SquareRoot(const Expression* const value) : UnaryExpression(UnaryExpressionType::SQUARE_ROOT, value) {}
    CubeRoot::CubeRoot(const Expression* const value) : UnaryExpression(UnaryExpressionType::CUBE_ROOT, value) {}
    Floor::Floor(const Expression* const value) : UnaryExpression(UnaryExpressionType::FLOOR, value) {}
    Ceiling::Ceiling(const Expression* const value) : UnaryExpression(UnaryExpressionType::CEILING, value) {}
}