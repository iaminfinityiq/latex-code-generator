#pragma once
#include "expressions.hpp"
#include <string>
#include <memory>

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
        Number(std::string value);
        /**
         * Gets the value of the desired number
         * @return the value of the number
         */
        std::string get_value() const;
        /**
         * Turns the desired number value to LaTeX
         * @return the desired LaTeX code for the number value
         */
        std::string to_latex() const override;
    private:
        std::string value;
    };
}