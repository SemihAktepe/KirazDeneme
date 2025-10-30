#ifndef KIRAZ_AST_WHILE_H
#define KIRAZ_AST_WHILE_H

#include <kiraz/Node.h>

namespace ast {

class While : public Node {
public:
    While(const Node::Ptr& condition, const Node::Ptr& body)
        : Node(), conditionC(condition), bodyC(body) {
        assert(condition);
        assert(body);
    }

    Node::Ptr get_condition() const { return conditionC; }
    Node::Ptr get_body() const { return bodyC; }

    std::string as_string() const override {
        return fmt::format("While(?={}, repeat={})",
                           conditionC->as_string(), bodyC->as_string());
    }
    Node::Ptr compute_stmt_type(SymbolTable &st) override;
private:
    Node::Ptr conditionC = nullptr, bodyC = nullptr;
};

} 

#endif // KIRAZ_AST_WHILE_H
