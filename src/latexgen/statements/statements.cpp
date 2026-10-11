#include "statements.hpp"

namespace latexgen {
    Statement::Statement(const StatementType type) : Item(ItemType::STATEMENT), type(type) {}
}
