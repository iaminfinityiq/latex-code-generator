#include "sets.hpp"
#include "../../exceptions.hpp"
#include <string>

namespace latexgen {
    Set::Set(const std::vector<std::variant<
        std::shared_ptr<Expression>,
        std::shared_ptr<Dots>
    >> &elements) : Expression(ExpressionType::SET), elements(elements) {
        auto is_nullptr = [](auto &&ptr) -> bool {
            return ptr == nullptr;
        };

        for (const std::variant<
            std::shared_ptr<Expression>,
            std::shared_ptr<Dots>
        > &el : this->elements) {
            if (std::visit(is_nullptr, el)) {
                throw NullptrException("there exists an element in the set which contains the value of nullptr, which is not allowed");
            }
        }
    }

    std::string Set::to_latex() const {
        std::string returned = "\\left\\{";
        auto latex = [](auto &&ptr) -> std::string {
            return ptr->to_latex();
        };

        for (size_t i = 0; i < this->elements.size(); i++) {
            returned += std::visit(latex, this->elements[i]);
            if (i < this->elements.size()-1) {
                returned += ",";
            }
        }

        returned += "\\right\\}";
        return returned;
    }
}
