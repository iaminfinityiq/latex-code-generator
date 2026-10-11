#pragma once
#include <string>

namespace latexgen {
    /**
     * Different types of items
     */
    enum struct ItemType {
        EXPRESSION,
        STATEMENT
    };

    /**
     * Base class for statements and expressions in latexgen
     */
    struct Item {
    public:
        /**
         * A constructor for an item
         * @param item_type the type of the item
         */
        Item(const ItemType item_type);
        /**
         * Turns the desired item to LaTeX
         * @return the desired LaTeX code for the item
         */
        virtual std::string to_latex() const;
        /**
         * Get the item type
         * @return the item type
         */
        ItemType get_item_type() const;
    private:
        ItemType item_type;
    };
}