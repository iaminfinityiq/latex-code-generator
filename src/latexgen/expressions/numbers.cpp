#include "numbers.hpp"
#include "../exceptions.hpp"

namespace latexgen {
    bool is_negative(const std::shared_ptr<Number> &number) {
        return number->get_value()[0] == '-';
    }

    Number::Number(std::string value) : Expression(ExpressionType::NUMBER) {
        if (value == "") {
            throw ArgumentException("value parameter of Number class must not be blank");
        }

        bool dot = false;
        for (char &c : value) {
            if (c == '.') {
                if (dot) {
                    throw ArgumentException("extra '.' in value parameter of Number struct");
                }

                dot = true;
                continue;
            }

            if (c < '0' || c > '9') {
                throw ArgumentException("non-digit character found in value parameter of Number struct");
            }
        }

        this->value = value;
    }

    std::string Number::get_value() const {
        return this->value;
    }

    std::string Number::to_latex() const {
        return this->get_value();
    }
}