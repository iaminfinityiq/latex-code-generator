#include "binary_expressions.hpp"
#include "expressions.hpp"
#include "unary_expressions.hpp"
#include "../exceptions.hpp"
#include <memory>

namespace latexgen {
    bool is_additive(const std::shared_ptr<BinaryExpression> &binary) {
        BinaryExpressionType type = binary->get_binary_type();
        return type == BinaryExpressionType::ADDITION || type == BinaryExpressionType::SUBTRACTION;
    }

    bool is_multiplicative(const std::shared_ptr<BinaryExpression> &binary) {
        BinaryExpressionType type = binary->get_binary_type();
        return type == BinaryExpressionType::MULTIPLICATION || type == BinaryExpressionType::MULTIPLICATION_DOT || type == BinaryExpressionType::MULTIPLICATION_MUL || type == BinaryExpressionType::MULTIPLICATION_NONE
            || type == BinaryExpressionType::DIVISION || type == BinaryExpressionType::FRACTION;
    }

    bool _is_multiplicative(const std::shared_ptr<BinaryExpression> &binary) {
        BinaryExpressionType type = binary->get_binary_type();
        return type == BinaryExpressionType::MULTIPLICATION || type == BinaryExpressionType::MULTIPLICATION_DOT || type == BinaryExpressionType::MULTIPLICATION_MUL || type == BinaryExpressionType::MULTIPLICATION_NONE
            || type == BinaryExpressionType::DIVISION;
    }
    
    BinaryExpression::BinaryExpression(const ExpressionOrDots &left, const BinaryExpressionType op, const ExpressionOrDots &right) : Expression(ExpressionType::BINARY), left(left), op(op), right(right) {
        auto is_nullptr = [](auto &&ptr){
            return ptr == nullptr;
        };

        if (std::visit(is_nullptr, this->left)) {
            throw NullptrException("left parameter of BinaryExpression cannot be nullptr");
        }

        if (std::visit(is_nullptr, this->right)) {
            throw NullptrException("right parameter of BinaryExpression cannot be nullptr");
        }
    }

    std::string BinaryExpression::to_latex() const {
        auto latex = [](auto &&ptr){
            return ptr->to_latex();
        };

        auto item_type = [](auto &&ptr){
            return ptr->get_item_type();
        };

        ExpressionOrDots left = this->get_left();
        ExpressionOrDots right = this->get_right();
        switch (this->get_binary_type()) {
            case BinaryExpressionType::ADDITION: {
                bool group_right = false;
                if (std::visit(item_type, right) != ItemType::DOTS) {
                    std::shared_ptr<Expression> right_ptr = std::get<std::shared_ptr<Expression>>(right);
                    if (right_ptr->get_type() == ExpressionType::UNARY) {
                        std::shared_ptr<UnaryExpression> right_unary = std::static_pointer_cast<UnaryExpression>(right_ptr);
                        if (is_unary_additive(right_unary)) {
                            group_right = true;
                        }
                    }
                }

                return std::visit(latex, left) + (group_right ? "+\\left(" : "+") + std::visit(latex, right) + (group_right ? "\\right)" : "");
            } case BinaryExpressionType::SUBTRACTION: {
                bool group_right = false;
                if (std::visit(item_type, right) != ItemType::DOTS) {
                    std::shared_ptr<Expression> right_ptr = std::get<std::shared_ptr<Expression>>(right);
                    if (right_ptr->get_type() == ExpressionType::BINARY) {
                        std::shared_ptr<BinaryExpression> right_binary = std::static_pointer_cast<BinaryExpression>(right_ptr);
                        if (is_additive(right_binary)) {
                            group_right = true;
                        }
                    } else if (right_ptr->get_type() == ExpressionType::UNARY) {
                        std::shared_ptr<UnaryExpression> right_unary = std::static_pointer_cast<UnaryExpression>(right_ptr);
                        if (is_unary_additive(right_unary)) {
                            group_right = true;
                        }
                    }
                }

                return std::visit(latex, left) + (group_right ? "-\\left(" : "-") + std::visit(latex, right) + (group_right ? "\\right)" : "");
            } case BinaryExpressionType::MULTIPLICATION: {
                bool group_left = false;
                bool group_right = false;
                bool use_cdot = false;
                bool left_is_number = true;
                if (std::visit(item_type, left) != ItemType::DOTS) {
                    std::shared_ptr<Expression> left_ptr = std::get<std::shared_ptr<Expression>>(left);
                    left_is_number = is_primary(left_ptr);
                    if (left_ptr->get_type() == ExpressionType::BINARY) {
                        std::shared_ptr<BinaryExpression> left_binary = std::static_pointer_cast<BinaryExpression>(left_ptr);
                        if (is_additive(left_binary)) {
                            group_left = true;
                        }

                        if (left_binary->get_binary_type() == BinaryExpressionType::FRACTION) {
                            left_is_number = true;
                        }
                    } else if (left_ptr->get_type() == ExpressionType::UNARY) {
                        std::shared_ptr<UnaryExpression> left_unary = std::static_pointer_cast<UnaryExpression>(left_ptr);
                        if (!is_unary_additive(left_unary)) {
                            left_is_number = false;
                        }
                    }
                }

                if (std::visit(item_type, right) != ItemType::DOTS) {
                    std::shared_ptr<Expression> right_ptr = std::get<std::shared_ptr<Expression>>(right);
                    if (right_ptr->get_type() == ExpressionType::BINARY) {
                        std::shared_ptr<BinaryExpression> right_binary = std::static_pointer_cast<BinaryExpression>(right_ptr);
                        if (is_additive(right_binary)) {
                            group_right = true;
                        }
                    } else if (right_ptr->get_type() == ExpressionType::UNARY) {
                        std::shared_ptr<UnaryExpression> right_unary = std::static_pointer_cast<UnaryExpression>(right_ptr);
                        if (is_unary_additive(right_unary)) {
                            group_right = true;
                        }
                    }

                    if (left_is_number) {
                        if (is_primary(right_ptr)) {
                            use_cdot = right_ptr->get_type() != ExpressionType::VARIABLE;
                        } else if (right_ptr->get_type() == ExpressionType::BINARY) {
                            std::shared_ptr<BinaryExpression> right_binary = std::static_pointer_cast<BinaryExpression>(right_ptr);
                            if (right_binary->get_binary_type() == BinaryExpressionType::FRACTION) {
                                use_cdot = true;
                            }
                        }
                    }
                }

                return (group_left ? "\\left(" : "") + std::visit(latex, left) + (group_left ? "\\right)" : "") + (use_cdot ? "\\cdot " : " ") + (group_right ? "\\left(" : "") + std::visit(latex, right) + (group_right ? "\\right)" : "");
            } case BinaryExpressionType::MULTIPLICATION_MUL: {
                bool group_left = false;
                bool group_right = false;

                if (std::visit(item_type, left) != ItemType::DOTS) {
                    std::shared_ptr<Expression> left_ptr = std::get<std::shared_ptr<Expression>>(left);
                    if (left_ptr->get_type() == ExpressionType::BINARY) {
                        std::shared_ptr<BinaryExpression> left_binary = std::static_pointer_cast<BinaryExpression>(left_ptr);
                        if (is_additive(left_binary)) {
                            group_left = true;
                        }
                    }
                }

                if (std::visit(item_type, right) != ItemType::DOTS) {
                    std::shared_ptr<Expression> right_ptr = std::get<std::shared_ptr<Expression>>(right);
                    if (right_ptr->get_type() == ExpressionType::BINARY) {
                        std::shared_ptr<BinaryExpression> right_binary = std::static_pointer_cast<BinaryExpression>(right_ptr);
                        if (is_additive(right_binary)) {
                            group_right = true;
                        }
                    } else if (right_ptr->get_type() == ExpressionType::UNARY) {
                        std::shared_ptr<UnaryExpression> right_unary = std::static_pointer_cast<UnaryExpression>(right_ptr);
                        if (is_unary_additive(right_unary)) {
                            group_right = true;
                        }
                    }
                }

                return (group_left ? "\\left(" : "") + std::visit(latex, left) + (group_left ? "\\right)\\times " : "\\times ") + (group_right ? "\\left(" : "") + std::visit(latex, right) + (group_right ? "\\right)" : "");
            } case BinaryExpressionType::MULTIPLICATION_DOT: {
                bool group_left = false;
                bool group_right = false;

                if (std::visit(item_type, left) != ItemType::DOTS) {
                    std::shared_ptr<Expression> left_ptr = std::get<std::shared_ptr<Expression>>(left);
                    if (left_ptr->get_type() == ExpressionType::BINARY) {
                        std::shared_ptr<BinaryExpression> left_binary = std::static_pointer_cast<BinaryExpression>(left_ptr);
                        if (is_additive(left_binary)) {
                            group_left = true;
                        }
                    }
                }

                if (std::visit(item_type, right) != ItemType::DOTS) {
                    std::shared_ptr<Expression> right_ptr = std::get<std::shared_ptr<Expression>>(right);
                    if (right_ptr->get_type() == ExpressionType::BINARY) {
                        std::shared_ptr<BinaryExpression> right_binary = std::static_pointer_cast<BinaryExpression>(right_ptr);
                        if (is_additive(right_binary)) {
                            group_right = true;
                        }
                    } else if (right_ptr->get_type() == ExpressionType::UNARY) {
                        std::shared_ptr<UnaryExpression> right_unary = std::static_pointer_cast<UnaryExpression>(right_ptr);
                        if (is_unary_additive(right_unary)) {
                            group_right = true;
                        }
                    }
                }

                return (group_left ? "\\left(" : "") + std::visit(latex, left) + (group_left ? "\\right)\\cdot " : "\\cdot ") + (group_right ? "\\left(" : "") + std::visit(latex, right) + (group_right ? "\\right)" : "");
            } case BinaryExpressionType::MULTIPLICATION_NONE: {
                bool group_left = false;
                bool group_right = false;

                if (std::visit(item_type, left) != ItemType::DOTS) {
                    std::shared_ptr<Expression> left_ptr = std::get<std::shared_ptr<Expression>>(left);
                    if (left_ptr->get_type() == ExpressionType::BINARY) {
                        std::shared_ptr<BinaryExpression> left_binary = std::static_pointer_cast<BinaryExpression>(left_ptr);
                        if (is_additive(left_binary)) {
                            group_left = true;
                        }
                    }
                }

                if (std::visit(item_type, right) != ItemType::DOTS) {
                    std::shared_ptr<Expression> right_ptr = std::get<std::shared_ptr<Expression>>(right);
                    if (right_ptr->get_type() == ExpressionType::BINARY) {
                        std::shared_ptr<BinaryExpression> right_binary = std::static_pointer_cast<BinaryExpression>(right_ptr);
                        if (is_additive(right_binary)) {
                            group_right = true;
                        }
                    } else if (right_ptr->get_type() == ExpressionType::UNARY) {
                        std::shared_ptr<UnaryExpression> right_unary = std::static_pointer_cast<UnaryExpression>(right_ptr);
                        if (is_unary_additive(right_unary)) {
                            group_right = true;
                        }
                    }
                }

                return (group_left ? "\\left(" : "") + std::visit(latex, left) + (group_left ? "\\right)" : " ") + (group_right ? "\\left(" : "") + std::visit(latex, right) + (group_right ? "\\right)" : "");
            } case BinaryExpressionType::DIVISION: {
                bool group_left = false;
                bool group_right = false;

                if (std::visit(item_type, left) != ItemType::DOTS) {
                    std::shared_ptr<Expression> left_ptr = std::get<std::shared_ptr<Expression>>(left);
                    if (left_ptr->get_type() == ExpressionType::BINARY) {
                        std::shared_ptr<BinaryExpression> left_binary = std::static_pointer_cast<BinaryExpression>(left_ptr);
                        if (is_additive(left_binary)) {
                            group_left = true;
                        }
                    }
                }

                if (std::visit(item_type, right) != ItemType::DOTS) {
                    std::shared_ptr<Expression> right_ptr = std::get<std::shared_ptr<Expression>>(right);
                    if (right_ptr->get_type() == ExpressionType::BINARY) {
                        std::shared_ptr<BinaryExpression> right_binary = std::static_pointer_cast<BinaryExpression>(right_ptr);
                        if (is_additive(right_binary) || is_multiplicative(right_binary)) {
                            group_right = true;
                        }
                    } else if (right_ptr->get_type() == ExpressionType::UNARY) {
                        std::shared_ptr<UnaryExpression> right_unary = std::static_pointer_cast<UnaryExpression>(right_ptr);
                        if (is_unary_additive(right_unary)) {
                            group_right = true;
                        }
                    }
                }

                return (group_left ? "\\left(" : "") + std::visit(latex, left) + (group_left ? "\\right)\\divisionsymbol " : "\\divisionsymbol ") + (group_right ? "\\left(" : "") + std::visit(latex, right) + (group_right ? "\\right)" : "");
            } case BinaryExpressionType::FRACTION:
                return "\\frac{" + std::visit(latex, left) + "}{" + std::visit(latex, right) + "}";
            case BinaryExpressionType::EXPONENTIATION: {
                bool group_left = false;
                if (std::visit(item_type, left) == ItemType::DOTS) {
                    group_left = true;
                } else {
                    std::shared_ptr<Expression> left_ptr = std::get<std::shared_ptr<Expression>>(left);
                    if (left_ptr->get_type() == ExpressionType::BINARY) {
                        std::shared_ptr<BinaryExpression> left_binary = std::static_pointer_cast<BinaryExpression>(left_ptr);
                        if (is_additive(left_binary) || is_multiplicative(left_binary) || left_binary->get_binary_type() == BinaryExpressionType::EXPONENTIATION) {
                            group_left = true;
                        }
                    } else if (left_ptr->get_type() == ExpressionType::UNARY) {
                        std::shared_ptr<UnaryExpression> left_unary = std::static_pointer_cast<UnaryExpression>(left_ptr);
                        if (is_unary_additive(left_unary)) {
                            group_left = true;
                        }
                    }
                }

                return (group_left ? "\\left(" : "") + std::visit(latex, left) + (group_left ? "\\right)^{" : "^{") + std::visit(latex, right) + "}";
            } case BinaryExpressionType::RADICATION:
                return "\\sqrt[" + std::visit(latex, left) + "]{" + std::visit(latex, right) + "}";
            case BinaryExpressionType::LOGARITHM: {
                bool group_right = true;
                if (std::visit(item_type, right) != ItemType::DOTS) {
                    std::shared_ptr<Expression> right_ptr = std::get<std::shared_ptr<Expression>>(right);
                    group_right = !is_primary(right_ptr);
                }

                return "\\log_{" + std::visit(latex, left) + (group_right ? "}{\\left(" : "}{") + std::visit(latex, right) + (group_right ? "\\right)}" : "}");
            } case BinaryExpressionType::PLUS_MINUS: {
                bool group_right = false;
                if (std::visit(item_type, right) != ItemType::DOTS) {
                    std::shared_ptr<Expression> right_ptr = std::get<std::shared_ptr<Expression>>(right);
                    if (right_ptr->get_type() == ExpressionType::BINARY) {
                        std::shared_ptr<BinaryExpression> right_binary = std::static_pointer_cast<BinaryExpression>(right_ptr);
                        if (is_additive(right_binary)) {
                            group_right = true;
                        }
                    } else if (right_ptr->get_type() == ExpressionType::UNARY) {
                        std::shared_ptr<UnaryExpression> right_unary = std::static_pointer_cast<UnaryExpression>(right_ptr);
                        if (is_unary_additive(right_unary)) {
                            group_right = true;
                        }
                    }
                }

                return std::visit(latex, left) + (group_right ? "\\pm\\left(" : "\\pm ") + std::visit(latex, right) + (group_right ? "\\right)" : "");
            } case BinaryExpressionType::MINUS_PLUS: {
                bool group_right = false;
                if (std::visit(item_type, right) != ItemType::DOTS) {
                    std::shared_ptr<Expression> right_ptr = std::get<std::shared_ptr<Expression>>(right);
                    if (right_ptr->get_type() == ExpressionType::BINARY) {
                        std::shared_ptr<BinaryExpression> right_binary = std::static_pointer_cast<BinaryExpression>(right_ptr);
                        if (is_additive(right_binary)) {
                            group_right = true;
                        }
                    } else if (right_ptr->get_type() == ExpressionType::UNARY) {
                        std::shared_ptr<UnaryExpression> right_unary = std::static_pointer_cast<UnaryExpression>(right_ptr);
                        if (is_unary_additive(right_unary)) {
                            group_right = true;
                        }
                    }
                }

                return std::visit(latex, left) + (group_right ? "\\mp\\left(" : "\\mp ") + (std::visit(latex, right)) + (group_right ? "\\right)" : "");
            } default:
                return "this is broken";
        }
    }

    BinaryExpressionType BinaryExpression::get_binary_type() const {
        return this->op;
    }

    ExpressionOrDots BinaryExpression::get_left() const {
        return this->left;
    }

    ExpressionOrDots BinaryExpression::get_right() const {
        return this->right;
    }

    Addition::Addition(const ExpressionOrDots &left, const ExpressionOrDots &right) : BinaryExpression(left, BinaryExpressionType::ADDITION, right) {}
    Subtraction::Subtraction(const ExpressionOrDots &left, const ExpressionOrDots &right) : BinaryExpression(left, BinaryExpressionType::SUBTRACTION, right) {}
    Multiplication::Multiplication(const ExpressionOrDots &left, const ExpressionOrDots &right) : BinaryExpression(left, BinaryExpressionType::MULTIPLICATION, right) {}
    Division::Division(const ExpressionOrDots &left, const ExpressionOrDots &right) : BinaryExpression(left, BinaryExpressionType::DIVISION, right) {}
    Fraction::Fraction(const ExpressionOrDots &numerator, const ExpressionOrDots &denominator, const bool full_display) : BinaryExpression(numerator, BinaryExpressionType::FRACTION, denominator), full_display(full_display) {}
    Exponentiation::Exponentiation(const ExpressionOrDots &base, const ExpressionOrDots &exponent, const bool full_display) : BinaryExpression(base, BinaryExpressionType::EXPONENTIATION, exponent), full_display(full_display) {}
    Radication::Radication(const ExpressionOrDots &radicand, const ExpressionOrDots &index, const bool full_display) : BinaryExpression(index, BinaryExpressionType::RADICATION, radicand), full_display(full_display) {}
    Logarithm::Logarithm(const ExpressionOrDots &argument, const ExpressionOrDots &base, const bool full_display) : BinaryExpression(base, BinaryExpressionType::LOGARITHM, argument), full_display(full_display) {}
    PlusMinus::PlusMinus(const ExpressionOrDots &left, const ExpressionOrDots &right) : BinaryExpression(left, BinaryExpressionType::PLUS_MINUS, right) {}
    MinusPlus::MinusPlus(const ExpressionOrDots &left, const ExpressionOrDots &right) : BinaryExpression(left, BinaryExpressionType::MINUS_PLUS, right) {}

    std::string Fraction::to_latex() const {
        auto latex = [](auto &&ptr){
            return ptr->to_latex();
        };

        if (this->full_display) {
            return "\\frac{\\displaystyle{" + std::visit(latex, this->get_left()) + "}}{\\displaystyle{" + std::visit(latex, this->get_right()) + "}}";
        }

        return "\\frac{" + std::visit(latex, this->get_left()) + "}{" + std::visit(latex, this->get_right()) + "}";
    }

    std::string Exponentiation::to_latex() const {
        bool group_left = false;
        auto item_type = [](auto &&ptr){
            return ptr->get_item_type();
        };

        auto latex = [](auto &&ptr){
            return ptr->to_latex();
        };

        if (std::visit(item_type, this->get_left()) == ItemType::DOTS) {
            group_left = true;
        } else {
            std::shared_ptr<Expression> left_ptr = std::get<std::shared_ptr<Expression>>(this->get_left());
            if (left_ptr->get_type() == ExpressionType::BINARY) {
                std::shared_ptr<BinaryExpression> left_binary = std::static_pointer_cast<BinaryExpression>(left_ptr);
                if (is_additive(left_binary) || is_multiplicative(left_binary) || left_binary->get_binary_type() == BinaryExpressionType::EXPONENTIATION) {
                    group_left = true;
                }
            } else if (left_ptr->get_type() == ExpressionType::UNARY) {
                std::shared_ptr<UnaryExpression> left_unary = std::static_pointer_cast<UnaryExpression>(left_ptr);
                if (is_unary_additive(left_unary)) {
                    group_left = true;
                }
            }
        }

        if (this->full_display) {
            return (group_left ? "\\left(" : "") + std::visit(latex, this->get_left()) + (group_left ? "\\right)^\\displaystyle{" : "^\\displaystyle{") + std::visit(latex, this->get_right()) + "}";
        }

        return (group_left ? "\\left(" : "") + std::visit(latex, this->get_left()) + (group_left ? "\\right)^{" : "^{") + std::visit(latex, this->get_right()) + "}";
    }

    std::string Radication::to_latex() const {
        auto latex = [](auto &&ptr){
            return ptr->to_latex();
        };

        if (this->full_display) {
            return "\\sqrt[\\displaystyle{" + std::visit(latex, this->get_left()) + "}]{" + std::visit(latex, this->get_right()) + "}";
        }

        return "\\sqrt[" + std::visit(latex, this->get_left()) + "]{" + std::visit(latex, this->get_right()) + "}";
    }

    std::string Logarithm::to_latex() const {
        auto item_type = [](auto &&ptr){
            return ptr->get_item_type();
        };

        auto latex = [](auto &&ptr){
            return ptr->to_latex();
        };

        bool group_right = true;
        if (std::visit(item_type, this->get_right()) != ItemType::DOTS) {
            std::shared_ptr<Expression> right_ptr = std::get<std::shared_ptr<Expression>>(this->get_right());
            group_right = !is_primary(right_ptr);
        }

        if (this->full_display) {
            return "\\log_{\\displaystyle{" + std::visit(latex, this->get_left()) + (group_right ? "}}{\\left(" : "}}{") + std::visit(latex, this->get_right()) + (group_right ? "\\right)}" : "}");
        }

        return "\\log_{" + std::visit(latex, this->get_left()) + (group_right ? "}{\\left(" : "}{") + std::visit(latex, this->get_right()) + (group_right ? "\\right)}" : "}");
    }

    std::shared_ptr<BinaryExpression> addition(const ExpressionOrDots &left, const ExpressionOrDots &right) {
        return std::make_shared<BinaryExpression>(left, BinaryExpressionType::ADDITION, right);
    }

    std::shared_ptr<BinaryExpression> subtraction(const ExpressionOrDots &left, const ExpressionOrDots &right) {
        return std::make_shared<BinaryExpression>(left, BinaryExpressionType::SUBTRACTION, right);
    }

    std::shared_ptr<BinaryExpression> multiplication(const ExpressionOrDots &left, const ExpressionOrDots &right) {
        return std::make_shared<BinaryExpression>(left, BinaryExpressionType::MULTIPLICATION, right);
    }

    std::shared_ptr<BinaryExpression> division(const ExpressionOrDots &left, const ExpressionOrDots &right) {
        return std::make_shared<BinaryExpression>(left, BinaryExpressionType::DIVISION, right);
    }

    std::shared_ptr<BinaryExpression> fraction(const ExpressionOrDots &numerator, const ExpressionOrDots &denominator) {
        return std::make_shared<BinaryExpression>(numerator, BinaryExpressionType::FRACTION, denominator);
    }

    std::shared_ptr<BinaryExpression> exponentiation(const ExpressionOrDots &base, const ExpressionOrDots &exponent) {
        return std::make_shared<BinaryExpression>(base, BinaryExpressionType::EXPONENTIATION, exponent);
    }

    std::shared_ptr<BinaryExpression> radication(const ExpressionOrDots &radicand, const ExpressionOrDots &index) {
        return std::make_shared<BinaryExpression>(index, BinaryExpressionType::RADICATION, radicand);
    }

    std::shared_ptr<BinaryExpression> logarithm(const ExpressionOrDots &argument, const ExpressionOrDots &base) {
        return std::make_shared<BinaryExpression>(base, BinaryExpressionType::LOGARITHM, argument);
    }

    std::shared_ptr<BinaryExpression> plus_minus(const ExpressionOrDots &left, const ExpressionOrDots &right) {
        return std::make_shared<BinaryExpression>(left, BinaryExpressionType::PLUS_MINUS, right);
    }

    std::shared_ptr<BinaryExpression> minus_plus(const ExpressionOrDots &left, const ExpressionOrDots &right) {
        return std::make_shared<BinaryExpression>(left, BinaryExpressionType::MINUS_PLUS, right);
    }
}
