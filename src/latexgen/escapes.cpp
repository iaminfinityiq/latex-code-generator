#include "escapes.hpp"

namespace latexgen {
    std::string escape(const char c) {
        switch (c) {
            case '#':
                return "\\#";
            case '$':
                return "\\$";
            case '%':
                return "\\%";
            case '&':
                return "\\&";
            case '_':
                return "\\_";
            case '{':
                return "\\{";
            case '}':
                return "\\}";
            case '~':
                return "\\~{}";
            case '^':
                return "\\^{}";
            case '\\':
                return "\\textbackslash{}";
            case '\n':
                return "\\\\";
            default:
                return std::string(1, c);
        }
    }

    std::string escape(const std::string text) {
        std::string result = "";
        for (const char &c : text) {
            result += escape(c);
        }

        return result;
    }
}