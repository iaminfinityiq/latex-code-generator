#include "unary_expressions.hpp"

namespace latexgen {
    UnaryExpression::UnaryExpression(const UnaryExpressionType unary_type, const std::shared_ptr<Expression> &value) : Expression(ExpressionType::UNARY), unary_type(unary_type), value(value) {}
    std::string UnaryExpression::to_latex() {
        if (this->unary_type == UnaryExpressionType::GROUPING) {
            return "\\left( " + this->value->to_latex() + " \\right)";
        }

        if (this->unary_type == UnaryExpressionType::PLUS) {
            return "+" + this->value->to_latex();
        }

        if (this->unary_type == UnaryExpressionType::MINUS) {
            return "-" + this->value->to_latex();
        }

        if (this->unary_type == UnaryExpressionType::ABSOLUTE_VALUE) {
            return "\\left| " + this->value->to_latex() + " \\right|";
        }

        if (this->unary_type == UnaryExpressionType::SQUARE_ROOT) {
            return "\\sqrt{" + this->value->to_latex() + "}";
        }

        if (this->unary_type == UnaryExpressionType::CUBE_ROOT) {
            return "\\sqrt[3]{" + this->value->to_latex() + "}";
        }

        if (this->unary_type == UnaryExpressionType::FLOOR) {
            return "\\left\\lfloor " + this->value->to_latex() + " \\right\\rfloor";
        }

        if (this->unary_type == UnaryExpressionType::CEILING) {
            return "\\left\\lceil " + this->value->to_latex() + " \\right\\rceil";
        }
    }
}