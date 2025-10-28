#ifndef KIRAZ_AST_LITERAL_H
#define KIRAZ_AST_LITERAL_H

#include <kiraz/Node.h>
#include <kiraz/token/Literal.h>

namespace ast {

class Integer : public Node {
public:
    Integer(std::shared_ptr<token::Token> tok);
    std::string as_string() const override;
private:
    long m_val;
};

class Str : public Node {
public:
    Str(std::shared_ptr<token::Token> tok);
    std::string as_string() const override;
private:
    std::string m_val;
};

class SignedNode : public Node {
public:
    SignedNode(int op, Node::Ptr node);
    std::string as_string() const override;
private:
    Node::Ptr m_node;
};

}
#endif