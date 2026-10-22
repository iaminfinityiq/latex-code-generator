#pragma once
#include "sets.hpp"

namespace latexgen {
    struct Naturals : public Set {
        Naturals();
        std::string to_latex() const override;
    };

    struct Integers : public Set {
        Integers();
        std::string to_latex() const override;
    };

    struct Rationals : public Set {
        Rationals();
        std::string to_latex() const override;
    };

    struct Reals : public Set {
        Reals();
        std::string to_latex() const override;
    };

    struct ComplexNumbers : public Set {
        ComplexNumbers();
        std::string to_latex() const override;
    };

    struct Primes : public Set {
        Primes();
        std::string to_latex() const override;
    };
};
