#pragma once
#include "../expressions.hpp"
#include <vector>

namespace latexgen {
    /**
     * Base class for a set
     */
    struct Set : public Expression {
    public:
        /**
         * Constructor of a set
         * @param elements containing the elements of the set
         */
        Set(const std::vector<ExpressionOrDots> &elements);
        /**
         * Turns the desired set into LaTeX code
         * @return the LaTeX code for the set
         */
        std::string to_latex() const override;
    private:
        std::vector<ExpressionOrDots> elements;
    };
}
