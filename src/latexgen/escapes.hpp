#pragma once
#include <string>

namespace latexgen {
    /**
     * Escapes a character for LaTeX purposes
     * @param c character that is needed to try to escape
     * @return the escaped character in string form, if a character cannot be escaped, it remains in its original form but in a string
     */
    std::string escape(const char c);

    /**
     * Escapes a string by iterating each character from the string
     * @param text text that is needed to try to escape
     * @return the new text that can be used in LaTeX
     */
    std::string escape(const std::string text);
}