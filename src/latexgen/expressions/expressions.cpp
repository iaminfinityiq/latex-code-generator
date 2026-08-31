#include "expressions.hpp"

namespace latexgen {
    Expression::Expression(const ExpressionType type) : type(type) {}
    std::string Expression::to_latex() {
        return "";
    }
}