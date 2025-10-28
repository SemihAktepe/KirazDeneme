#ifndef KIRAZ_AST_EXPRESSIONS_H
#define KIRAZ_AST_EXPRESSIONS_H

#include <kiraz/Node.h>

namespace ast {

class Id : public Node {
public:
    Id(std::shared_ptr<token::Token> tok);
    std::string as_string() const override;
private:
    std::string m_val;
};

class Call : public Node {
public:
    Call(Node::Ptr name, Node::Ptr args);
    std::string as_string() const override;
private:
    Node::Ptr m_name, m_args;
};

class CallL : public Node {
public:
    CallL(Node::Ptr args);
    std::string as_string() const override;
private:
    Node::Ptr m_args;
};

class CallS : public Node {
public:
    CallS(Node::Ptr arg);
    CallS();
    std::string as_string() const override;
    Node::Ptr next = nullptr;
private:
    Node::Ptr m_arg;
};

class Args : public Node {
public:
    Args(Node::Ptr arg_list);
    std::string as_string() const override;
private:
    Node::Ptr m_arg_list;
};

class Arg : public Node {
public:
    Arg(Node::Ptr name, Node::Ptr type);
    Arg();
    std::string as_string() const override;
    Node::Ptr next = nullptr;
private:
    Node::Ptr m_name, m_type;
};

}
#endif
