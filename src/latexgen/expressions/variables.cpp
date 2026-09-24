#include "variables.hpp"
#include "../exceptions.hpp"

namespace latexgen {
    Variable::Variable(const std::shared_ptr<Variable> &base, const std::shared_ptr<Expression> &subscript) : Expression(ExpressionType::VARIABLE), base(base), subscript(subscript) {}
    std::string Variable::to_latex() const {
        return "{" + this->base->to_latex() + "}_{" + this->subscript->to_latex() + "}";
    }

    EnglishVariable::EnglishVariable(const char variable_name) : Variable(nullptr, nullptr) {
        if (!(('a' <= variable_name && variable_name <= 'z') || ('A' <= variable_name && variable_name <= 'Z'))) {
            throw ArgumentException("expected a character from 'A' to 'Z' or 'a' to 'z' in variable_name parameter");
        }

        this->variable_name = std::string(1, variable_name);
    }

    std::string EnglishVariable::to_latex() const {
        return this->variable_name;
    }

    GreekVariable::GreekVariable(const GreekCharacter variable_name) : Variable(nullptr, nullptr), variable_name(variable_name) {}
    std::string GreekVariable::to_latex() const {
        switch (this->variable_name) {
            case GreekCharacter::ALPHA:
                return "\\alpha";
            case GreekCharacter::BETA:
                return "\\beta";
            case GreekCharacter::GAMMA:
                return "\\gamma";
            case GreekCharacter::DELTA:
                return "\\delta";
            case GreekCharacter::BAD_EPSILON:
                return "\\epsilon";
            case GreekCharacter::EPSILON:
                return "\\varepsilon";
            case GreekCharacter::ZETA:
                return "\\zeta";
            case GreekCharacter::ETA:
                return "\\eta";
            case GreekCharacter::THETA:
                return "\\theta";
            case GreekCharacter::BAD_THETA:
                return "\\vartheta";
            case GreekCharacter::IOTA:
                return "\\iota";
            case GreekCharacter::KAPPA:
                return "\\kappa";
            case GreekCharacter::LAMBDA:
                return "\\lambda";
            case GreekCharacter::MU:
                return "\\mu";
            case GreekCharacter::NU:
                return "\\nu";
            case GreekCharacter::XI:
                return "\\xi";
            case GreekCharacter::PI:
                return "\\pi";
            case GreekCharacter::BAD_PI:
                return "\\varpi";
            case GreekCharacter::SIGMA:
                return "\\sigma";
            case GreekCharacter::BAD_SIGMA:
                return "\\varsigma";
            case GreekCharacter::TAU:
                return "\\tau";
            case GreekCharacter::UPSILON:
                return "\\upsilon";
            case GreekCharacter::PHI:
                return "\\phi";
            case GreekCharacter::BETTER_PHI:
                return "\\varphi";
            case GreekCharacter::CHI:
                return "\\chi";
            case GreekCharacter::PSI:
                return "\\psi";
            case GreekCharacter::OMEGA:
                return "\\omega";
            case GreekCharacter::UPPER_GAMMA:
                return "\\Gamma";
            case GreekCharacter::UPPER_DELTA:
                return "\\Delta";
            case GreekCharacter::UPPER_THETA:
                return "\\Theta";
            case GreekCharacter::UPPER_LAMBDA:
                return "\\Lambda";
            case GreekCharacter::UPPER_XI:
                return "\\Xi";
            case GreekCharacter::UPPER_PI:
                return "\\Pi";
            case GreekCharacter::UPPER_SIGMA:
                return "\\Sigma";
            case GreekCharacter::UPPER_UPSILON:
                return "\\Upsilon";
            case GreekCharacter::UPPER_PHI:
                return "\\Phi";
            case GreekCharacter::UPPER_PSI:
                return "\\Psi";
            case GreekCharacter::UPPER_OMEGA:
                return "\\Omega";
            default:
                return "c++ sucks";
        }
    }
}
