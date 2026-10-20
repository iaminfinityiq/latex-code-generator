#include "dots.hpp"
#include "items.hpp"

namespace latexgen {
    Dots::Dots() : Item(ItemType::DOTS) {}
    std::string Dots::to_latex() const {
        return "\\dots";
    }
}
