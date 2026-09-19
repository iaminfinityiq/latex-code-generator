#include "variables.hpp"
#include "../exceptions.hpp"

namespace latexgen {
    Variable::Variable(const char variable_name) : Expression(ExpressionType::VARIABLE) {
        if (!(('a' <= variable_name && variable_name <= 'z') || ('A' <= variable_name && variable_name <= 'Z'))) {
            throw ArgumentException("expected a character from 'A' to 'Z' or 'a' to 'z' in variable_name parameter");
        }
        this->variable_name = std::string(1, variable_name);
    }

    std::string Variable::to_latex() const {
        return this->variable_name;
    }
}