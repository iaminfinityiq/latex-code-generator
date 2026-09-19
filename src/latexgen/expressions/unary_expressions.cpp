#include "unary_expressions.hpp"
#include "binary_expressions.hpp"

namespace latexgen {
    bool is_unary_additive(const std::shared_ptr<UnaryExpression> &unary) {
        UnaryExpressionType type = unary->get_unary_type();
        return type == UnaryExpressionType::PLUS || type == UnaryExpressionType::MINUS;
    }

    UnaryExpression::UnaryExpression(const UnaryExpressionType op, const std::shared_ptr<Expression> &value) : Expression(ExpressionType::UNARY), op(op), value(value) {}
    std::string UnaryExpression::to_latex() const {
        switch (this->get_unary_type()) {
            case UnaryExpressionType::GROUPING:
                return "\\left(" + this->get_value()->to_latex() + "\\right)";
            case UnaryExpressionType::PLUS:
                if (this->get_value()->get_type() == ExpressionType::BINARY) {
                    std::shared_ptr<BinaryExpression> value_binary = std::static_pointer_cast<BinaryExpression>(this->get_value());
                    if (is_additive(value_binary)) {
                        return "+\\left(" + this->get_value()->to_latex() + "\\right)";
                    }
                }

                return "+" + this->get_value()->to_latex();
            case UnaryExpressionType::MINUS:
                if (this->get_value()->get_type() == ExpressionType::BINARY) {
                    std::shared_ptr<BinaryExpression> value_binary = std::static_pointer_cast<BinaryExpression>(this->get_value());
                    if (is_additive(value_binary)) {
                        return "-\\left(" + this->get_value()->to_latex() + "\\right)";
                    }
                }

                return "-" + this->get_value()->to_latex();
            case UnaryExpressionType::ABSOLUTE_VALUE:
                return "\\left|" + this->get_value()->to_latex() + "\\right|";
            case UnaryExpressionType::SQUARE_ROOT:
                return "\\sqrt{" + this->get_value()->to_latex() + "}";
            case UnaryExpressionType::CUBE_ROOT:
                return "\\sqrt[3]{" + this->get_value()->to_latex() + "}";
            case UnaryExpressionType::FLOOR:
                return "\\left\\lfloor " + this->get_value()->to_latex() + "\\right\\rfloor";
            case UnaryExpressionType::CEILING:
                return "\\left\\lceil " + this->get_value()->to_latex() + "\\right\\rceil";
            default:
                return "this is broken";
        }
    }

    UnaryExpressionType UnaryExpression::get_unary_type() const {
        return this->op;
    }

    std::shared_ptr<Expression> UnaryExpression::get_value() const {
        return this->value;
    }

    UnaryPlus::UnaryPlus(const std::shared_ptr<Expression> &value) : UnaryExpression(UnaryExpressionType::PLUS, value) {}
    UnaryMinus::UnaryMinus(const std::shared_ptr<Expression> &value) : UnaryExpression(UnaryExpressionType::MINUS, value) {}
    AbsoluteValue::AbsoluteValue(const std::shared_ptr<Expression> &value) : UnaryExpression(UnaryExpressionType::ABSOLUTE_VALUE, value) {}
    SquareRoot::SquareRoot(const std::shared_ptr<Expression> &value) : UnaryExpression(UnaryExpressionType::SQUARE_ROOT, value) {}
    CubeRoot::CubeRoot(const std::shared_ptr<Expression> &value) : UnaryExpression(UnaryExpressionType::CUBE_ROOT, value) {}
    Floor::Floor(const std::shared_ptr<Expression> &value) : UnaryExpression(UnaryExpressionType::FLOOR, value) {}
    Ceiling::Ceiling(const std::shared_ptr<Expression> &value) : UnaryExpression(UnaryExpressionType::CEILING, value) {}

    std::shared_ptr<UnaryExpression> unary_plus(const std::shared_ptr<Expression> &value) {
        return std::make_shared<UnaryExpression>(UnaryExpressionType::PLUS, value);
    }

    std::shared_ptr<UnaryExpression> unary_minus(const std::shared_ptr<Expression> &value) {
        return std::make_shared<UnaryExpression>(UnaryExpressionType::MINUS, value);
    }

    std::shared_ptr<UnaryExpression> absolute_value(const std::shared_ptr<Expression> &value) {
        return std::make_shared<UnaryExpression>(UnaryExpressionType::ABSOLUTE_VALUE, value);
    }

    std::shared_ptr<UnaryExpression> square_root(const std::shared_ptr<Expression> &value) {
        return std::make_shared<UnaryExpression>(UnaryExpressionType::SQUARE_ROOT, value);
    }

    std::shared_ptr<UnaryExpression> cube_root(const std::shared_ptr<Expression> &value) {
        return std::make_shared<UnaryExpression>(UnaryExpressionType::CUBE_ROOT, value);
    }

    std::shared_ptr<UnaryExpression> floor(const std::shared_ptr<Expression> &value) {
        return std::make_shared<UnaryExpression>(UnaryExpressionType::FLOOR, value);
    }

    std::shared_ptr<UnaryExpression> ceiling(const std::shared_ptr<Expression> &value) {
        return std::make_shared<UnaryExpression>(UnaryExpressionType::CEILING, value);
    }
}