#include "expressions.hpp"

namespace latexgen {
    Expression::Expression(ExpressionType type) : type(type) {}
    std::string Expression::to_latex() const {
        return "";
    }

    ExpressionType Expression::get_type() const {
        return this->type;
    }

    bool is_primary(const std::shared_ptr<Expression> &expr) {
        ExpressionType type = expr->get_type();
        return type == ExpressionType::NUMBER || type == ExpressionType::TEXT || type == ExpressionType::UNARY;
    }
}