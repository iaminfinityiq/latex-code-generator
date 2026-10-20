#pragma once
#include "items.hpp"

namespace latexgen {
    /**
     * Dot dot dot class
     */
    struct Dots : public Item {
        /**
         * Constructor for dot dot dot
         */
        Dots();
        /**
         * Returns the desired LaTeX code for the dots
         * @return the LaTeX code for dots
         */
        std::string to_latex() const override;
    };
}
