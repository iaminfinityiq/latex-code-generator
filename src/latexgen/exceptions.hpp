#pragma once
#include <exception>
#include <string>

namespace latexgen {
    struct ArgumentException : public std::exception {
    public:
        explicit ArgumentException(const std::string &message) : message(message) {}
        const char* what() const noexcept override {
            return this->message.c_str();
        }
    private:
        std::string message;
    };

    struct NullptrException : public std::exception {
    public:
        explicit NullptrException(const std::string &message) : message(message) {}
        const char* what() const noexcept override {
            return this->message.c_str();
        }
    private:
        std::string message;
    };
}
