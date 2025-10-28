#include <kiraz/ast/Literal.h>
#include <fmt/core.h>

namespace ast {

Integer::Integer(std::shared_ptr<token::Token> tok) : Node(L_INTEGER) {
    auto int_tok = std::dynamic_pointer_cast<token::Integer>(tok);
    m_val = int_tok->get_val();
}
std::string Integer::as_string() const {
    return fmt::format("Int({})", m_val);
}


Str::Str(std::shared_ptr<token::Token> tok) : Node(L_STRING) {
    auto str_tok = std::dynamic_pointer_cast<token::Str>(tok);
    m_val = str_tok->get_val();
}
std::string Str::as_string() const {
    return fmt::format("Str(\"{}\")", m_val);
}


SignedNode::SignedNode(int op, Node::Ptr node) : Node(op), m_node(node) {}

std::string SignedNode::as_string() const {
    std::string op_str = (get_id() == OP_PLUS) ? "+" : "-";
    return fmt::format("Signed(op={}, node={})",
        op_str,
        m_node->as_string()
    );
}

}