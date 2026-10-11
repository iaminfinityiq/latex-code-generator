#pragma once
#include "../items.hpp"

namespace latexgen {
    /**
     * Different types of a statement
     */
    enum struct StatementType {
        RELATIONAL
    };

    /**
     * Base class for an expression
     */
    struct Statement : public Item {
    public:
        /**
         * Base constructor for a statement
         */
        Statement(const StatementType type);
    private:
        StatementType type;
    };
}
