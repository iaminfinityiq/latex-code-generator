#include "expressions.hpp"

namespace latexgen {
    Expression::Expression(ExpressionType type) : Item(ItemType::EXPRESSION), type(type) {}
    ExpressionType Expression::get_type() const {
        return this->type;
    }

    bool is_primary(const std::shared_ptr<Expression> &expr) {
        ExpressionType type = expr->get_type();
        return type == ExpressionType::NUMBER || type == ExpressionType::TEXT || type == ExpressionType::VARIABLE || type == ExpressionType::SET;
    }
}
