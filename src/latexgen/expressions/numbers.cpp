#include "numbers.hpp"
#include "../exceptions.hpp"

namespace latexgen {
    Number::Number(std::string value) : Expression(ExpressionType::NUMBER) {
        if (value == "") {
            throw ArgumentException("value parameter of Number class must not be blank");
        }

        size_t starting_index = value[0] == '-';
        bool dot = false;
        for (size_t i = starting_index; i < value.size(); i++) {
            if (value[i] == '.') {
                if (dot) {
                    throw ArgumentException("extra '.' in value parameter of Number struct");
                }

                dot = true;
                continue;
            }

            if (value[i] < '0' || value[i] > '9') {
                throw ArgumentException("non-digit character found in value parameter of Number struct");
            }
        }

        this->value = value;
    }

    std::string Number::to_latex() const {
        return this->value;
    }
}