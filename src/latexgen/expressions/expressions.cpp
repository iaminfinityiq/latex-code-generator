#include "expressions.hpp"

namespace latexgen {
    Expression::Expression(ExpressionType type) : type(type) {}
    std::string Expression::to_latex() const {
        return "";
    }

    ExpressionType Expression::get_type() const {
        return this->type;
    }
}