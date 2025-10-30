#ifndef KIRAZ_AST_IFELSE_H
#define KIRAZ_AST_IFELSE_H

#include <kiraz/Node.h>

namespace ast {
class IfElse : public Node {
public:
    IfElse(const Node::Ptr &condition, const Node::Ptr &if_block, const Node::Ptr &else_block)
        : Node(), conditionC(condition), ifBlockC(if_block), elseBlockC(else_block) {}
    IfElse(const Node::Ptr &condition, const Node::Ptr &if_block)
        : Node(), conditionC(condition), ifBlockC(if_block){} 

    std::string as_string() const override {
        if(get_else_block() != nullptr){
            return fmt::format("If(?={}, then={}, else={})", 
                            conditionC->as_string(), 
                            ifBlockC->as_string(), 
                            elseBlockC->as_string());
        }
        else{
            return fmt::format("If(?={}, then={}, else=[])", 
                            conditionC->as_string(), 
                            ifBlockC->as_string());
        }
    }

    Node::Ptr get_condition() const { return conditionC; }
    Node::Ptr get_if_block() const { return ifBlockC; }
    Node::Ptr get_else_block() const { return elseBlockC; }

    Node::Ptr compute_stmt_type(SymbolTable &st) override;

private:
    Node::Ptr conditionC = nullptr, ifBlockC = nullptr, elseBlockC = nullptr;
};
}

#endif
