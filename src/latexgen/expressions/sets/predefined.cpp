#include "predefined.hpp"

namespace latexgen {
    Naturals::Naturals() : Set({}) {}
    std::string Naturals::to_latex() const {
        return "\\mathbb N";
    }

    Integers::Integers() : Set({}) {}
    std::string Integers::to_latex() const {
        return "\\mathbb Z";
    }

    Rationals::Rationals() : Set({}) {}
    std::string Rationals::to_latex() const {
        return "\\mathbb Q";
    }

    Reals::Reals() : Set({}) {}
    std::string Reals::to_latex() const {
        return "\\mathbb R";
    }

    ComplexNumbers::ComplexNumbers() : Set({}) {}
    std::string ComplexNumbers::to_latex() const {
        return "\\mathbb C";
    }

    Primes::Primes() : Set({}) {}
    std::string Primes::to_latex() const {
        return "\\mathbb P";
    }
}
