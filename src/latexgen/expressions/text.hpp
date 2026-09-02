#pragma once
#include "expressions.hpp"

namespace latexgen {
    /**
     * Text
     */
    struct Text : public Expression {
    public:
        /**
         * A constructor for text
         * @param text the desired text
         */
        Text(std::string text);
        std::string to_latex() const override;
    private:
        std::string text;
    };
}