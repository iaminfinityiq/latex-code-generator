#include "relational_statements.hpp"
#include "../exceptions.hpp"

namespace latexgen {
    RelationalStatement::RelationalStatement(const std::shared_ptr<Expression> &lhs, const RelationalType op, const std::shared_ptr<Expression> &rhs) : Statement(StatementType::RELATIONAL),  lhs(lhs), op(op), rhs(rhs) {
        if (lhs == nullptr) {
            throw NullptrException("lhs parameter of RelationalStatement cannot be nullptr");
        }

        if (rhs == nullptr) {
            throw NullptrException("rhs parameter of RelationalStatement cannot be nullptr");
        }
    }

    RelationalStatement::RelationalStatement(const std::shared_ptr<RelationalStatement> &lhs, const RelationalType op, const std::shared_ptr<Expression> &rhs) : Statement(StatementType::RELATIONAL), lhs(lhs), op(op), rhs(rhs) {
        if (lhs == nullptr) {
            throw NullptrException("lhs parameter of RelationalStatement cannot be nullptr");
        }

        if (rhs == nullptr) {
            throw NullptrException("rhs parameter of RelationalStatement cannot be nullptr");
        }
    }

    std::string RelationalStatement::to_latex() const {
        std::string lhs_str = std::visit([](auto &&ptr) -> std::string {
            return ptr->to_latex();
        }, this->lhs);
        switch (this->op) {
            case RelationalType::EQUALITY:
                return lhs_str + "=" + this->rhs->to_latex();
            case RelationalType::INEQUALITY:
                return lhs_str + "\\neq " + this->rhs->to_latex();
            case RelationalType::GREATER_THAN:
                return lhs_str + ">" + this->rhs->to_latex();
            case RelationalType::SMALLER_THAN:
                return lhs_str + "<" + this->rhs->to_latex();
            case RelationalType::GREATER_THAN_OR_EQUALS:
                return lhs_str + "\\geq " + this->rhs->to_latex();
            case RelationalType::SMALLER_THAN_OR_EQUALS:
                return lhs_str + "\\leq " + this->rhs->to_latex();
            case RelationalType::IN:
                return lhs_str + "\\in " + this->rhs->to_latex();
            case RelationalType::NOT_IN:
                return lhs_str + "\\not\\in " + this->rhs->to_latex();
            default:
                return "this is broken wtf";
        }
    }

    Equality::Equality(const std::shared_ptr<Expression> &lhs, const std::shared_ptr<Expression> &rhs) : RelationalStatement(lhs, RelationalType::EQUALITY, rhs) {}
    Equality::Equality(const std::shared_ptr<RelationalStatement> &lhs, const std::shared_ptr<Expression> &rhs) : RelationalStatement(lhs, RelationalType::EQUALITY, rhs) {}
    Inequality::Inequality(const std::shared_ptr<Expression> &lhs, const std::shared_ptr<Expression> &rhs) : RelationalStatement(lhs, RelationalType::INEQUALITY, rhs) {}
    Inequality::Inequality(const std::shared_ptr<RelationalStatement> &lhs, const std::shared_ptr<Expression> &rhs) : RelationalStatement(lhs, RelationalType::INEQUALITY, rhs) {}
    GreaterThan::GreaterThan(const std::shared_ptr<Expression> &lhs, const std::shared_ptr<Expression> &rhs) : RelationalStatement(lhs, RelationalType::GREATER_THAN, rhs) {}
    GreaterThan::GreaterThan(const std::shared_ptr<RelationalStatement> &lhs, const std::shared_ptr<Expression> &rhs) : RelationalStatement(lhs, RelationalType::GREATER_THAN, rhs) {}
    SmallerThan::SmallerThan(const std::shared_ptr<Expression> &lhs, const std::shared_ptr<Expression> &rhs) : RelationalStatement(lhs, RelationalType::SMALLER_THAN, rhs) {}
    SmallerThan::SmallerThan(const std::shared_ptr<RelationalStatement> &lhs, const std::shared_ptr<Expression> &rhs) : RelationalStatement(lhs, RelationalType::SMALLER_THAN, rhs) {}
    GreaterThanOrEquals::GreaterThanOrEquals(const std::shared_ptr<Expression> &lhs, const std::shared_ptr<Expression> &rhs) : RelationalStatement(lhs, RelationalType::GREATER_THAN_OR_EQUALS, rhs) {}
    GreaterThanOrEquals::GreaterThanOrEquals(const std::shared_ptr<RelationalStatement> &lhs, const std::shared_ptr<Expression> &rhs) : RelationalStatement(lhs, RelationalType::GREATER_THAN_OR_EQUALS, rhs) {}
    SmallerThanOrEquals::SmallerThanOrEquals(const std::shared_ptr<Expression> &lhs, const std::shared_ptr<Expression> &rhs) : RelationalStatement(lhs, RelationalType::SMALLER_THAN_OR_EQUALS, rhs) {}
    SmallerThanOrEquals::SmallerThanOrEquals(const std::shared_ptr<RelationalStatement> &lhs, const std::shared_ptr<Expression> &rhs) : RelationalStatement(lhs, RelationalType::SMALLER_THAN_OR_EQUALS, rhs) {}
    In::In(const std::shared_ptr<Expression> &lhs, const std::shared_ptr<Expression> &rhs) : RelationalStatement(lhs, RelationalType::IN, rhs) {}
    In::In(const std::shared_ptr<RelationalStatement> &lhs, const std::shared_ptr<Expression> &rhs) : RelationalStatement(lhs, RelationalType::IN, rhs) {}
    NotIn::NotIn(const std::shared_ptr<Expression> &lhs, const std::shared_ptr<Expression> &rhs) : RelationalStatement(lhs, RelationalType::NOT_IN, rhs) {}
    NotIn::NotIn(const std::shared_ptr<RelationalStatement> &lhs, const std::shared_ptr<Expression> &rhs) : RelationalStatement(lhs, RelationalType::NOT_IN, rhs) {}
}
