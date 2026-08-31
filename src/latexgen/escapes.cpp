#include "escapes.hpp"

namespace latexgen {
    std::string escape(const char c) {
        if (c == '#') {
            return "\\#";
        }

        if (c == '$') {
            return "\\$";
        }

        if (c == '%') {
            return "\\%";
        }

        if (c == '&') {
            return "\\&";
        }

        if (c == '_') {
            return "\\_";
        }

        if (c == '{') {
            return "\\{";
        }

        if (c == '}') {
            return "\\}";
        }

        if (c == '~') {
            return "\\~{}";
        }

        if (c == '^') {
            return "\\^{}";
        }

        if (c == '\\') {
            return "\\textbackslash{}";
        }

        if (c == '\n') {
            return "\\\\";
        }

        return std::string(1, c);
    }

    std::string escape(const std::string text) {
        std::string result = "";
        for (const char &c : text) {
            result += escape(c);
        }

        return result;
    }
}