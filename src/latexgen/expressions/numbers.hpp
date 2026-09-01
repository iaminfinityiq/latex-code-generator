#pragma once
#include "expressions.hpp"
#include <string>

namespace latexgen {
    /**
     * A number
     */
    struct Number : public Expression {
    public:
        /**
         * A number constructor
         * @param value the value to input in (as a string)
         */
        Number(const std::string value);
        /**
         * Turns the desired number value to LaTeX
         * @return the desired LaTeX code for the number value
         */
        std::string to_latex() override;
    private:
        std::string value;
    };
}