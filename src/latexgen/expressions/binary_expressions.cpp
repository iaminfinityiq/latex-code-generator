#include "binary_expressions.hpp"
#include "numbers.hpp"
#include "unary_expressions.hpp"

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
    
    BinaryExpression::BinaryExpression(const std::shared_ptr<Expression> &left, const BinaryExpressionType op, const std::shared_ptr<Expression> &right) : Expression(ExpressionType::BINARY), left(left), op(op), right(right) {}
    std::string BinaryExpression::to_latex() const {
        switch (this->get_binary_type()) {
            case BinaryExpressionType::ADDITION: {
                bool group_right = false;
                if (this->get_right()->get_type() == ExpressionType::UNARY) {
                    std::shared_ptr<UnaryExpression> right_unary = std::static_pointer_cast<UnaryExpression>(this->get_right());
                    if (is_unary_additive(right_unary)) {
                        group_right = true;
                    }
                }

                return this->get_left()->to_latex() + (group_right ? "+\\left(" : "+") + this->get_right()->to_latex() + (group_right ? "\\right)" : "");
            } case BinaryExpressionType::SUBTRACTION: {
                bool group_right = false;
                if (this->get_right()->get_type() == ExpressionType::BINARY) {
                    std::shared_ptr<BinaryExpression> right_binary = std::static_pointer_cast<BinaryExpression>(this->get_right());
                    if (is_additive(right_binary)) {
                        group_right = true;
                    }
                }


                if (this->get_right()->get_type() == ExpressionType::UNARY) {
                    std::shared_ptr<UnaryExpression> right_unary = std::static_pointer_cast<UnaryExpression>(this->get_right());
                    if (is_unary_additive(right_unary)) {
                        group_right = true;
                    }
                }

                return this->get_left()->to_latex() + (group_right ? "-\\left(" : "-") + this->get_right()->to_latex() + (group_right ? "\\right)" : "");
            } case BinaryExpressionType::MULTIPLICATION: {
                if (this->get_left()->get_type() == ExpressionType::NUMBER && this->get_right()->get_type() == ExpressionType::NUMBER) {
                    return this->get_left()->to_latex() + "\\cdot" + this->get_right()->to_latex();
                }

                bool group_left = false;
                bool group_right = false;

                if (this->get_left()->get_type() == ExpressionType::BINARY) {
                    std::shared_ptr<BinaryExpression> left_binary = std::static_pointer_cast<BinaryExpression>(this->get_left());
                    if (is_additive(left_binary)) {
                        group_left = true;
                    }
                }

                if (this->get_right()->get_type() == ExpressionType::BINARY) {
                    std::shared_ptr<BinaryExpression> right_binary = std::static_pointer_cast<BinaryExpression>(this->get_right());
                    if (is_additive(right_binary)) {
                        group_right = true;
                    }
                }

                if (this->get_right()->get_type() == ExpressionType::UNARY) {
                    std::shared_ptr<UnaryExpression> right_unary = std::static_pointer_cast<UnaryExpression>(this->get_right());
                    if (is_unary_additive(right_unary)) {
                        group_right = true;
                    }
                }

                return (group_left ? "\\left(" : "") + this->get_left()->to_latex() + (group_left ? "\\right)" : "") + (group_right ? "\\left(" : "") + this->get_right()->to_latex() + (group_right ? "\\right)" : "");
            } case BinaryExpressionType::MULTIPLICATION_MUL: {
                bool group_left = false;
                bool group_right = false;

                if (this->get_left()->get_type() == ExpressionType::BINARY) {
                    std::shared_ptr<BinaryExpression> left_binary = std::static_pointer_cast<BinaryExpression>(this->get_left());
                    if (is_additive(left_binary)) {
                        group_left = true;
                    }
                }

                if (this->get_right()->get_type() == ExpressionType::BINARY) {
                    std::shared_ptr<BinaryExpression> right_binary = std::static_pointer_cast<BinaryExpression>(this->get_right());
                    if (is_additive(right_binary)) {
                        group_right = true;
                    }
                }

                if (this->get_right()->get_type() == ExpressionType::UNARY) {
                    std::shared_ptr<UnaryExpression> right_unary = std::static_pointer_cast<UnaryExpression>(this->get_right());
                    if (is_unary_additive(right_unary)) {
                        group_right = true;
                    }
                }

                return (group_left ? "\\left(" : "") + this->get_left()->to_latex() + (group_left ? "\\right)\\times " : "\\times ") + (group_right ? "\\left(" : "") + this->get_right()->to_latex() + (group_right ? "\\right)" : "");
            } case BinaryExpressionType::MULTIPLICATION_DOT: {
                bool group_left = false;
                bool group_right = false;

                if (this->get_left()->get_type() == ExpressionType::BINARY) {
                    std::shared_ptr<BinaryExpression> left_binary = std::static_pointer_cast<BinaryExpression>(this->get_left());
                    if (is_additive(left_binary)) {
                        group_left = true;
                    }
                }

                if (this->get_right()->get_type() == ExpressionType::BINARY) {
                    std::shared_ptr<BinaryExpression> right_binary = std::static_pointer_cast<BinaryExpression>(this->get_right());
                    if (is_additive(right_binary)) {
                        group_right = true;
                    }
                }

                if (this->get_right()->get_type() == ExpressionType::UNARY) {
                    std::shared_ptr<UnaryExpression> right_unary = std::static_pointer_cast<UnaryExpression>(this->get_right());
                    if (is_unary_additive(right_unary)) {
                        group_right = true;
                    }
                }

                return (group_left ? "\\left(" : "") + this->get_left()->to_latex() + (group_left ? "\\right)\\cdot" : "\\cdot ") + (group_right ? "\\left(" : "") + this->get_right()->to_latex() + (group_right ? "\\right)" : "");
            } case BinaryExpressionType::MULTIPLICATION_NONE: {
                bool group_left = false;
                bool group_right = false;

                if (this->get_left()->get_type() == ExpressionType::BINARY) {
                    std::shared_ptr<BinaryExpression> left_binary = std::static_pointer_cast<BinaryExpression>(this->get_left());
                    if (is_additive(left_binary)) {
                        group_left = true;
                    }
                }

                if (this->get_right()->get_type() == ExpressionType::BINARY) {
                    std::shared_ptr<BinaryExpression> right_binary = std::static_pointer_cast<BinaryExpression>(this->get_right());
                    if (is_additive(right_binary)) {
                        group_right = true;
                    }
                }

                return (group_left ? "\\left(" : "") + this->get_left()->to_latex() + (group_left ? "\\right)" : " ") + (group_right ? "\\left(" : "") + this->get_right()->to_latex() + (group_right ? "\\right)" : "");
            } case BinaryExpressionType::DIVISION: {
                bool group_left = false;
                bool group_right = false;

                if (this->get_left()->get_type() == ExpressionType::BINARY) {
                    std::shared_ptr<BinaryExpression> left_binary = std::static_pointer_cast<BinaryExpression>(this->get_left());
                    if (is_additive(left_binary)) {
                        group_left = true;
                    }
                }

                if (this->get_right()->get_type() == ExpressionType::BINARY) {
                    std::shared_ptr<BinaryExpression> right_binary = std::static_pointer_cast<BinaryExpression>(this->get_right());
                    if (is_additive(right_binary) || is_multiplicative(right_binary)) {
                        group_right = true;
                    }
                }

                return (group_left ? "\\left(" : "") + this->get_left()->to_latex() + (group_left ? "\\right)\\divisionsymbol " : "\\divisionsymbol ") + (group_right ? "\\left(" : "") + this->get_right()->to_latex() + (group_right ? "\\right)" : "");
            } case BinaryExpressionType::FRACTION:
                return "\\frac{" + this->get_left()->to_latex() + "}{" + this->get_right()->to_latex() + "}";
            case BinaryExpressionType::EXPONENTIATION: {
                bool group_left = false;
                if (this->get_left()->get_type() == ExpressionType::BINARY) {
                    std::shared_ptr<BinaryExpression> left_binary = std::static_pointer_cast<BinaryExpression>(this->get_left());
                    if (is_additive(left_binary) || is_multiplicative(left_binary) || left_binary->get_binary_type() == BinaryExpressionType::EXPONENTIATION) {
                        group_left = true;
                    }
                }

                if (this->get_left()->get_type() == ExpressionType::UNARY) {
                    std::shared_ptr<UnaryExpression> left_unary = std::static_pointer_cast<UnaryExpression>(this->get_left());
                    if (is_unary_additive(left_unary)) {
                        group_left = true;
                    }
                }

                return (group_left ? "\\left(" : "") + this->get_left()->to_latex() + (group_left ? "\\right)^{" : "^{") + this->get_right()->to_latex() + "}";
            } case BinaryExpressionType::RADICATION:
                return "\\sqrt[" + this->get_left()->to_latex() + "]{" + this->get_right()->to_latex() + "}";
            case BinaryExpressionType::LOGARITHM: {
                bool group_right = false;
                if (is_primary(this->get_right())) {
                    group_right = true;
                }

                return "\\log_{" + this->get_left()->to_latex() + (group_right ? "}{\\left(" : "}{") + this->get_right()->to_latex() + (group_right ? "\\right)}" : "}");
            } case BinaryExpressionType::PLUS_MINUS: {
                bool group_right = false;
                if (this->get_right()->get_type() == ExpressionType::BINARY) {
                    std::shared_ptr<BinaryExpression> right_binary = std::static_pointer_cast<BinaryExpression>(this->get_right());
                    if (is_additive(right_binary)) {
                        group_right = true;
                    }
                }

                if (this->get_right()->get_type() == ExpressionType::UNARY) {
                    std::shared_ptr<UnaryExpression> right_unary = std::static_pointer_cast<UnaryExpression>(this->get_right());
                    if (is_unary_additive(right_unary)) {
                        group_right = true;
                    }
                }

                return this->get_left()->to_latex() + (group_right ? "\\pm\\left(" : "\\pm ") + this->get_right()->to_latex() + (group_right ? "\\right)" : "");
            } case BinaryExpressionType::MINUS_PLUS: {
                bool group_right = false;
                if (this->get_right()->get_type() == ExpressionType::BINARY) {
                    std::shared_ptr<BinaryExpression> right_binary = std::static_pointer_cast<BinaryExpression>(this->get_right());
                    if (is_additive(right_binary)) {
                        group_right = true;
                    }
                }

                if (this->get_right()->get_type() == ExpressionType::UNARY) {
                    std::shared_ptr<UnaryExpression> right_unary = std::static_pointer_cast<UnaryExpression>(this->get_right());
                    if (is_unary_additive(right_unary)) {
                        group_right = true;
                    }
                }

                return this->get_left()->to_latex() + (group_right ? "\\mp\\left(" : "\\mp ") + this->get_right()->to_latex() + (group_right ? "\\right)" : "");
            } default:
                return "this is broken";
        }
    }

    BinaryExpressionType BinaryExpression::get_binary_type() const {
        return this->op;
    }

    std::shared_ptr<Expression> BinaryExpression::get_left() const {
        return this->left;
    }

    std::shared_ptr<Expression> BinaryExpression::get_right() const {
        return this->right;
    }

    Addition::Addition(const std::shared_ptr<Expression> &left, const std::shared_ptr<Expression> &right) : BinaryExpression(left, BinaryExpressionType::ADDITION, right) {}
    Subtraction::Subtraction(const std::shared_ptr<Expression> &left, const std::shared_ptr<Expression> &right) : BinaryExpression(left, BinaryExpressionType::SUBTRACTION, right) {}
    Multiplication::Multiplication(const std::shared_ptr<Expression> &left, const std::shared_ptr<Expression> &right) : BinaryExpression(left, BinaryExpressionType::MULTIPLICATION, right) {}
    Division::Division(const std::shared_ptr<Expression> &left, const std::shared_ptr<Expression> &right) : BinaryExpression(left, BinaryExpressionType::DIVISION, right) {}
    Fraction::Fraction(const std::shared_ptr<Expression> &numerator, const std::shared_ptr<Expression> &denominator, const bool full_display) : BinaryExpression(numerator, BinaryExpressionType::FRACTION, denominator), full_display(full_display) {}
    Exponentiation::Exponentiation(const std::shared_ptr<Expression> &base, const std::shared_ptr<Expression> &exponent, const bool full_display) : BinaryExpression(base, BinaryExpressionType::EXPONENTIATION, exponent), full_display(full_display) {}
    Radication::Radication(const std::shared_ptr<Expression> &radicand, const std::shared_ptr<Expression> &index, const bool full_display) : BinaryExpression(index, BinaryExpressionType::RADICATION, radicand), full_display(full_display) {}
    Logarithm::Logarithm(const std::shared_ptr<Expression> &argument, const std::shared_ptr<Expression> &base, const bool full_display) : BinaryExpression(base, BinaryExpressionType::LOGARITHM, argument), full_display(full_display) {}
    PlusMinus::PlusMinus(const std::shared_ptr<Expression> &left, const std::shared_ptr<Expression> &right) : BinaryExpression(left, BinaryExpressionType::PLUS_MINUS, right) {}
    MinusPlus::MinusPlus(const std::shared_ptr<Expression> &left, const std::shared_ptr<Expression> &right) : BinaryExpression(left, BinaryExpressionType::MINUS_PLUS, right) {}

    std::string Fraction::to_latex() const {
        if (this->full_display) {
            return "\\frac{\\displaystyle{" + this->get_left()->to_latex() + "}}{\\displaystyle{" + this->get_right()->to_latex() + "}}";
        }

        return "\\frac{" + this->get_left()->to_latex() + "}{" + this->get_right()->to_latex() + "}";
    }

    std::string Exponentiation::to_latex() const {
        bool group_left = false;
        if (this->get_left()->get_type() == ExpressionType::BINARY) {
            std::shared_ptr<BinaryExpression> left_binary = std::static_pointer_cast<BinaryExpression>(this->get_left());
            if (is_additive(left_binary) || is_multiplicative(left_binary) || left_binary->get_binary_type() == BinaryExpressionType::EXPONENTIATION) {
                group_left = true;
            }
        }

        if (this->get_left()->get_type() == ExpressionType::UNARY) {
            std::shared_ptr<UnaryExpression> left_unary = std::static_pointer_cast<UnaryExpression>(this->get_left());
            if (is_unary_additive(left_unary)) {
                group_left = true;
            }
        }

        if (this->full_display) {
            return (group_left ? "\\left(" : "") + this->get_left()->to_latex() + (group_left ? "\\right)^\\displaystyle{" : "^\\displaystyle{") + this->get_right()->to_latex() + "}";
        }

        return (group_left ? "\\left(" : "") + this->get_left()->to_latex() + (group_left ? "\\right)^{" : "^{") + this->get_right()->to_latex() + "}";
    }

    std::string Radication::to_latex() const {
        if (this->full_display) {
            return "\\sqrt[\\displaystyle{" + this->get_left()->to_latex() + "}]{" + this->get_right()->to_latex() + "}";
        }

        return "\\sqrt[" + this->get_left()->to_latex() + "]{" + this->get_right()->to_latex() + "}";
    }

    std::string Logarithm::to_latex() const {
        bool group_right = false;
        if (is_primary(this->get_right())) {
            group_right = true;
        }

        if (this->full_display) {
            return "\\log_{\\displaystyle{" + this->get_left()->to_latex() + (group_right ? "}}{\\left(" : "}}{") + this->get_right()->to_latex() + (group_right ? "\\right)}" : "}");
        }

        return "\\log_{" + this->get_left()->to_latex() + (group_right ? "}{\\left(" : "}{") + this->get_right()->to_latex() + (group_right ? "\\right)}" : "}");
    }
}
