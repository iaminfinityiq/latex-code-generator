#pragma once
#include "expressions.hpp"

namespace latexgen {
    /**
     * A full variable base class
     */
    struct Variable : public Expression {
    public:
        /**
         * A variable constructor
         * @param base base variable
         * @param subscript the subscript of the variable
         */
        Variable(const std::shared_ptr<Variable> &base, const std::shared_ptr<Expression> &subscript);
        std::string to_latex() const override;
    private:
        std::shared_ptr<Variable> base;
        std::shared_ptr<Expression> subscript;
    };

    /**
     * An English Variable
     */
    struct EnglishVariable : public Variable {
    public:
        /**
         * An English variable constructor
         * @param variable_name
         */
        EnglishVariable(const char variable_name);
        /**
         * Turns the desired variable into LaTeX
         * @return the desired LaTeX code for the variable
         */
        std::string to_latex() const override;
    private:
        std::string variable_name;
    };

    /**
     * An enum of all Greek characters
     */
    enum struct GreekCharacter {
        ALPHA, // \alpha
        BETA, // \beta
        GAMMA, // \gamma
        DELTA, // \delta
        BAD_EPSILON, // \epsilon
        EPSILON, // \varepsilon
        ZETA, // \zeta
        ETA, // \eta
        THETA, // \theta
        BAD_THETA, // \vartheta
        IOTA, // \iota
        KAPPA, // \kappa
        LAMBDA, // \lambda
        MU, // \mu
        NU, // \nu
        XI, // \xi
        PI, // \pi
        BAD_PI, // \varpi
        SIGMA, // \sigma
        BAD_SIGMA, // \varsigma
        TAU, // \tau
        UPSILON, // \upsilon
        PHI, // \phi
        BETTER_PHI, // \varphi
        CHI, // \chi
        PSI, // \psi
        OMEGA, // \omega
        UPPER_GAMMA, // \Gamma
        UPPER_DELTA, // \Delta
        UPPER_THETA, // \Theta
        UPPER_LAMBDA, // \Lambda
        UPPER_XI, // \Xi
        UPPER_PI, // \Pi
        UPPER_SIGMA, // \Sigma
        UPPER_UPSILON, // \Upsilon
        UPPER_PHI, // \Phi
        UPPER_PSI, // \Psi
        UPPER_OMEGA // \Omega
    };

    /**
     * A variable but with Greek characters
     */
    struct GreekVariable : public Variable {
    public:
        /**
         * A Greek variable constructor
         */
        GreekVariable(const GreekCharacter variable_name);
        /**
         * Generates the LaTeX code for the desired variable
         * @return the LaTeX code for the variable
         */
        std::string to_latex() const override;
    private:
        GreekCharacter variable_name;
    };
}
