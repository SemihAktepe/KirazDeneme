#ifndef KIRAZ_AST_RETURN_H
#define KIRAZ_AST_RETURN_H

#include <kiraz/Node.h>
#include <string>

namespace ast {
class Return : public Node {
public:
    explicit Return(Node::Ptr &ret)
        : Node(), retC(ret) {}

    std::string get_ret() const { return retC->as_string(); }
    Node::Ptr get_retN() {return retC;}
    std::string as_string() const override {
        return fmt::format("Return({})", get_ret());
    }
    Node::Ptr compute_stmt_type(SymbolTable &st) override;
private:
    Node::Ptr retC;
};
}
#endif
