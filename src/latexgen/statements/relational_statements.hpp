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
        /**
         * Constructor for a relational statement
         * @param lhs the left expression
         * @param op the relation operator
         * @param rhs the right expression
         */
        RelationalStatement(const std::shared_ptr<Expression> &lhs, const RelationalType op, const std::shared_ptr<Expression> &rhs);
        /**
         * Constructor for a relational statement
         * @param lhs the left side, which is a relational statement containing the results of `n-1` previous expressions
         * @param op the relation operator
         * @param rhs the right expression
         */
        RelationalStatement(const std::shared_ptr<RelationalStatement> &lhs, const RelationalType op, const std::shared_ptr<Expression> &rhs);
        /**
         * Returns the desired LaTeX code for the relational statement
         * @return the desired LaTeX code for the relational statement
         */
        std::string to_latex() const override;
    private:
        std::variant<
            std::shared_ptr<RelationalStatement>,
            std::shared_ptr<Expression>
        > lhs;
        RelationalType op;
        std::shared_ptr<Expression> rhs;
    };

    /**
     * Represents an equality
     */
    struct Equality : public RelationalStatement {
    public:
        /**
         * Constructor for equality
         * @param lhs the left expression
         * @param rhs the right expression
         */
        Equality(const std::shared_ptr<Expression> &lhs, const std::shared_ptr<Expression> &rhs);
        /**
         * Constructor for equality
         * @param lhs the left side, which is a relational statement containing the results of `n-1` previous expressions
         * rhs the right expression
         */
        Equality(const std::shared_ptr<RelationalStatement> &lhs, const std::shared_ptr<Expression> &rhs);
    };

    /**
     * Represents an inequality
     */
    struct Inequality : public RelationalStatement {
    public:
        /**
         * Constructor for inequality
         * @param lhs the left expression
         * @param rhs the right expression
         */
        Inequality(const std::shared_ptr<Expression> &lhs, const std::shared_ptr<Expression> &rhs);
        /**
         * Constructor for inequality
         * @param lhs the left side, which is a relational statement containing the results of `n-1` previous expressions
         * rhs the right expression
         */
        Inequality(const std::shared_ptr<RelationalStatement> &lhs, const std::shared_ptr<Expression> &rhs);
    };

    /**
     * Represents an inequality, specifically greater than something
     */
    struct GreaterThan : public RelationalStatement {
    public:
        /**
         * Constructor for greater than
         * @param lhs the left expression
         * @param rhs the right expression
         */
        GreaterThan(const std::shared_ptr<Expression> &lhs, const std::shared_ptr<Expression> &rhs);
        /**
         * Constructor for greater than
         * @param lhs the left side, which is a relational statement containing the results of `n-1` previous expressions
         * rhs the right expression
         */
        GreaterThan(const std::shared_ptr<RelationalStatement> &lhs, const std::shared_ptr<Expression> &rhs);
    };

    /**
     * Represents an inequality, specifically smaller than something
     */
    struct SmallerThan : public RelationalStatement {
    public:
        /**
         * Constructor for smaller than
         * @param lhs the left expression
         * @param rhs the right expression
         */
        SmallerThan(const std::shared_ptr<Expression> &lhs, const std::shared_ptr<Expression> &rhs);
        /**
         * Constructor for smaller than
         * @param lhs the left side, which is a relational statement containing the results of `n-1` previous expressions
         * rhs the right expression
         */
        SmallerThan(const std::shared_ptr<RelationalStatement> &lhs, const std::shared_ptr<Expression> &rhs);
    };

    /**
     * Represents an inequality, specifically greater than or equals something
     */
    struct GreaterThanOrEquals : public RelationalStatement {
    public:
        /**
         * Constructor for greater than or equals
         * @param lhs the left expression
         * @param rhs the right expression
         */
        GreaterThanOrEquals(const std::shared_ptr<Expression> &lhs, const std::shared_ptr<Expression> &rhs);
        /**
         * Constructor for greater than or equals
         * @param lhs the left side, which is a relational statement containing the results of `n-1` previous expressions
         * rhs the right expression
         */
        GreaterThanOrEquals(const std::shared_ptr<RelationalStatement> &lhs, const std::shared_ptr<Expression> &rhs);
    };

    /**
     * Represents an inequality, specifically smaller than or equals something
     */
    struct SmallerThanOrEquals : public RelationalStatement {
    public:
        /**
         * Constructor for smaller than or equals
         * @param lhs the left expression
         * @param rhs the right expression
         */
        SmallerThanOrEquals(const std::shared_ptr<Expression> &lhs, const std::shared_ptr<Expression> &rhs);
        /**
         * Constructor for smaller than or equals
         * @param lhs the left side, which is a relational statement containing the results of `n-1` previous expressions
         * rhs the right expression
         */
        SmallerThanOrEquals(const std::shared_ptr<RelationalStatement> &lhs, const std::shared_ptr<Expression> &rhs);
    };

    /**
     * Represents an in relation
     */
    struct In : public RelationalStatement {
    public:
        /**
         * Constructor for in
         * @param lhs the left expression
         * @param rhs the right expression
         */
        In(const std::shared_ptr<Expression> &lhs, const std::shared_ptr<Expression> &rhs);
        /**
         * Constructor for in
         * @param lhs the left side, which is a relational statement containing the results of `n-1` previous expressions
         * rhs the right expression
         */
        In(const std::shared_ptr<RelationalStatement> &lhs, const std::shared_ptr<Expression> &rhs);
    };

    /**
     * Represents a not in relation
     */
    struct NotIn : public RelationalStatement {
    public:
        /**
         * Constructor for not in
         * @param lhs the left expression
         * @param rhs the right expression
         */
        NotIn(const std::shared_ptr<Expression> &lhs, const std::shared_ptr<Expression> &rhs);
        /**
         * Constructor for not in
         * @param lhs the left side, which is a relational statement containing the results of `n-1` previous expressions
         * rhs the right expression
         */
        NotIn(const std::shared_ptr<RelationalStatement> &lhs, const std::shared_ptr<Expression> &rhs);
    };
}
