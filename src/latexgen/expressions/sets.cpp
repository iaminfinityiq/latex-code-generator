#include "sets.hpp"
#include "../exceptions.hpp"

namespace latexgen {
    Set::Set(const std::vector<std::shared_ptr<Expression>> &elements) : Expression(ExpressionType::SET), elements(elements) {
        for (const std::shared_ptr<Expression> &el : this->elements) {
            if (el == nullptr) {
                throw NullptrException("there exists an element in the set which contains the value of nullptr, which is not allowed");
            }
        }
    }

    std::string Set::to_latex() const {
        std::string returned = "\\left\\{";
        for (size_t i = 0; i < this->elements.size(); i++) {
            returned += this->elements[i]->to_latex();
            if (i < this->elements.size()-1) {
                returned += ",";
            }
        }

        returned += "\\right\\}";
        return returned;
    }
}
