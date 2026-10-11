#include "items.hpp"

namespace latexgen {
    Item::Item(const ItemType item_type) : item_type(item_type) {}
    std::string Item::to_latex() const {
        return "";
    }

    ItemType Item::get_item_type() const {
        return this->item_type;
    }
}