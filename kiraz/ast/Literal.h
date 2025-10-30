#ifndef KIRAZ_AST_LITERAL_H
#define KIRAZ_AST_LITERAL_H

#include <kiraz/Node.h>
#include <kiraz/token/Literal.h>
#include <fmt/format.h>

namespace ast {

class Integer : public Node {
public:
    explicit Integer(Token::Ptr t);
    std::string as_string() const override;
    Node::Ptr gen_wat(WasmContext &) override;

private:
    int m_val = 0;
};

class Str : public Node {
public:
    explicit Str(Token::Ptr t);
    std::string as_string() const override;
    Node::Ptr gen_wat(WasmContext &) override;

private:
    std::string m_val;
};

} // namespace ast

#endif // KIRAZ_AST_LITERAL_H
