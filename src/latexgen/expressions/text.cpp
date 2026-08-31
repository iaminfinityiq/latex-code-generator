#include "text.hpp"
#include "../escapes.hpp"

namespace latexgen {
    Text::Text(const std::string text) : Expression(ExpressionType::TEXT), text(text) {}
    std::string Text::to_latex() {
        return "\\text{" + escape(this->text) + "}";
    }
}