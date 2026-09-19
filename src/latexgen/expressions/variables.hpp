#pragma once
#include "expressions.hpp"

namespace latexgen {
    /**
     * A variable
     */
    struct Variable : public Expression {
    public:
        /**
         * A variable constructor
         * @param variable_name
         */
        Variable(const char variable_name);
        /**
         * Turns the desired variable into latex
         * @return the desired LaTeX code for the variable
         */
        std::string to_latex() const override;
    private:
        std::string variable_name;
    };
}