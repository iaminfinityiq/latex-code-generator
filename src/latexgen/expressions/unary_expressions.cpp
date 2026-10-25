#include "unary_expressions.hpp"
#include "binary_expressions.hpp"
#include "../exceptions.hpp"

namespace latexgen {
    bool is_unary_additive(const std::shared_ptr<UnaryExpression> &unary) {
        UnaryExpressionType type = unary->get_unary_type();
        return type == UnaryExpressionType::PLUS || type == UnaryExpressionType::MINUS;
    }

    UnaryExpression::UnaryExpression(const UnaryExpressionType op, const ExpressionOrDots &value) : Expression(ExpressionType::UNARY), op(op), value(value) {
        auto is_nullptr = [](auto &&ptr){
            return ptr == nullptr;
        };

        if (std::visit(is_nullptr, this->value)) {
            throw NullptrException("value parameter of UnaryExpression cannot be nullptr");
        }
    }

    std::string UnaryExpression::to_latex() const {
        ExpressionOrDots val = this->get_value();
        auto latex = [](auto &&ptr){
            return ptr->to_latex();
        };

        auto item_type = [](auto &&ptr){
            return ptr->get_item_type();
        };

        switch (this->get_unary_type()) {
            case UnaryExpressionType::GROUPING:
                return "\\left(" + std::visit(latex, val) + "\\right)";
            case UnaryExpressionType::PLUS: {
                if (std::visit(item_type, val) == ItemType::DOTS) {
                    return "+\\left(" + std::visit(latex, val) + "\\right)";
                }

                std::shared_ptr<Expression> value_ptr = std::get<std::shared_ptr<Expression>>(val);
                if (value_ptr->get_type() == ExpressionType::BINARY) {
                    std::shared_ptr<BinaryExpression> value_binary = std::static_pointer_cast<BinaryExpression>(value_ptr);
                    if (is_additive(value_binary)) {
                        return "+\\left(" + value_ptr->to_latex() + "\\right)";
                    }
                }

                return "+" + std::visit(latex, val);
            } case UnaryExpressionType::MINUS: {
                if (std::visit(item_type, val) == ItemType::DOTS) {
                    return "-\\left(" + std::visit(latex, val) + "\\right)";
                }

                std::shared_ptr<Expression> value_ptr = std::get<std::shared_ptr<Expression>>(val);
                if (value_ptr->get_type() == ExpressionType::BINARY) {
                    std::shared_ptr<BinaryExpression> value_binary = std::static_pointer_cast<BinaryExpression>(value_ptr);
                    if (is_additive(value_binary)) {
                        return "-\\left(" + value_ptr->to_latex() + "\\right)";
                    }
                }

                return "-" + std::visit(latex, val);
            } case UnaryExpressionType::ABSOLUTE_VALUE:
                return "\\left|" + std::visit(latex, val) + "\\right|";
            case UnaryExpressionType::SQUARE_ROOT:
                return "\\sqrt{" + std::visit(latex, val) + "}";
            case UnaryExpressionType::CUBE_ROOT:
                return "\\sqrt[3]{" + std::visit(latex, val) + "}";
            case UnaryExpressionType::FLOOR:
                return "\\left\\lfloor " + std::visit(latex, val) + "\\right\\rfloor";
            case UnaryExpressionType::CEILING:
                return "\\left\\lceil " + std::visit(latex, val) + "\\right\\rceil";
            default:
                return "this is broken";
        }
    }

    UnaryExpressionType UnaryExpression::get_unary_type() const {
        return this->op;
    }

    ExpressionOrDots UnaryExpression::get_value() const {
        return this->value;
    }

    UnaryPlus::UnaryPlus(const ExpressionOrDots &value) : UnaryExpression(UnaryExpressionType::PLUS, value) {}
    UnaryMinus::UnaryMinus(const ExpressionOrDots &value) : UnaryExpression(UnaryExpressionType::MINUS, value) {}
    AbsoluteValue::AbsoluteValue(const ExpressionOrDots &value) : UnaryExpression(UnaryExpressionType::ABSOLUTE_VALUE, value) {}
    SquareRoot::SquareRoot(const ExpressionOrDots &value) : UnaryExpression(UnaryExpressionType::SQUARE_ROOT, value) {}
    CubeRoot::CubeRoot(const ExpressionOrDots &value) : UnaryExpression(UnaryExpressionType::CUBE_ROOT, value) {}
    Floor::Floor(const ExpressionOrDots &value) : UnaryExpression(UnaryExpressionType::FLOOR, value) {}
    Ceiling::Ceiling(const ExpressionOrDots &value) : UnaryExpression(UnaryExpressionType::CEILING, value) {}

    std::shared_ptr<UnaryExpression> unary_plus(const ExpressionOrDots &value) {
        return std::make_shared<UnaryExpression>(UnaryExpressionType::PLUS, value);
    }

    std::shared_ptr<UnaryExpression> unary_minus(const ExpressionOrDots &value) {
        return std::make_shared<UnaryExpression>(UnaryExpressionType::MINUS, value);
    }

    std::shared_ptr<UnaryExpression> absolute_value(const ExpressionOrDots &value) {
        return std::make_shared<UnaryExpression>(UnaryExpressionType::ABSOLUTE_VALUE, value);
    }

    std::shared_ptr<UnaryExpression> square_root(const ExpressionOrDots &value) {
        return std::make_shared<UnaryExpression>(UnaryExpressionType::SQUARE_ROOT, value);
    }

    std::shared_ptr<UnaryExpression> cube_root(const ExpressionOrDots &value) {
        return std::make_shared<UnaryExpression>(UnaryExpressionType::CUBE_ROOT, value);
    }

    std::shared_ptr<UnaryExpression> floor(const ExpressionOrDots &value) {
        return std::make_shared<UnaryExpression>(UnaryExpressionType::FLOOR, value);
    }

    std::shared_ptr<UnaryExpression> ceiling(const ExpressionOrDots &value) {
        return std::make_shared<UnaryExpression>(UnaryExpressionType::CEILING, value);
    }
}
