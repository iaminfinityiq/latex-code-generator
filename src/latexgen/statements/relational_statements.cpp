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
}
