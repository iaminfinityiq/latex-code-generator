#pragma once
#include "statements.hpp"
#include "../expressions/expressions.hpp"
#include <memory>
#include <variant>

namespace latexgen {
    /**
     * Relational operators
     */
    enum struct RelationalType {
        EQUALITY, // =
        INEQUALITY, // ≠
        GREATER_THAN, // >
        SMALLER_THAN, // <
        GREATER_THAN_OR_EQUALS, // ≥
        SMALLER_THAN_OR_EQUALS, // ≤
        IN, // ∈
        NOT_IN // ∉
    };
    
    /**
     * Base class for a relational statement
     */
    struct RelationalStatement : public Statement {
    public:
        RelationalStatement(const std::shared_ptr<Expression> &lhs, const RelationalType op, const std::shared_ptr<Expression> &rhs);
        RelationalStatement(const std::shared_ptr<RelationalStatement> &lhs, const RelationalType op, const std::shared_ptr<Expression> &rhs);
        std::string to_latex() const override;
    private:
        std::variant<
            std::shared_ptr<RelationalStatement>,
            std::shared_ptr<Expression>
        > lhs;
        RelationalType op;
        std::shared_ptr<Expression> rhs;
    };
}
