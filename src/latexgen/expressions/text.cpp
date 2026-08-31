#include "text.hpp"
#include "../escapes.hpp"
#include "../exceptions.hpp"

namespace latexgen {
    Text::Text(const std::string text) : Expression(ExpressionType::TEXT) {
        for (const char &c : text) {
            if (c == '\n') {
                throw ArgumentException("newlines are not allowed in text parameter of Text struct");
            }
        }

        this->text = text;
    }

    std::string Text::to_latex() {
        return "\\text{" + escape(this->text) + "}";
    }
}