#ifndef KIRAZ_AST_STATEMENTS_H
#define KIRAZ_AST_STATEMENTS_H

#include <kiraz/Node.h>

namespace ast {

class ModuleL : public Node {
public:
    ModuleL(Node::Ptr stmt_list);
    std::string as_string() const override;
private:
    Node::Ptr m_stmt_list;
};

class ModuleN : public Node {
public:
    ModuleN(Node::Ptr stmt, Node::Ptr next);
    ModuleN();
    std::string as_string() const override;
private:
    Node::Ptr m_stmt;
    Node::Ptr m_next;
};

class Func : public Node {
public:
    Func(Node::Ptr name, Node::Ptr args, Node::Ptr ret_type, Node::Ptr body);
    std::string as_string() const override;
private:
    Node::Ptr m_name, m_args, m_ret_type, m_body;
};

class KwImport : public Node {
public:
    KwImport(Node::Ptr path);
    std::string as_string() const override;
private:
    Node::Ptr m_path;
};

class KwIfElse : public Node {
public:
    KwIfElse(Node::Ptr cond, Node::Ptr if_body, Node::Ptr else_body = nullptr);
    std::string as_string() const override;
private:
    Node::Ptr m_cond, m_if_body, m_else_body;
};

class ClassDef : public Node {
public:
    ClassDef(Node::Ptr name, Node::Ptr inherit, Node::Ptr body);
    std::string as_string() const override;
private:
    Node::Ptr m_name, m_inherit, m_body;
};

class KwWhile : public Node {
public:
    KwWhile(Node::Ptr cond, Node::Ptr body);
    std::string as_string() const override;
private:
    Node::Ptr m_cond, m_body;
};

class KwLet : public Node {
public:
    KwLet(int op, Node::Ptr id, Node::Ptr value, int i = 0);
    KwLet(int op, Node::Ptr id, Node::Ptr type, Node::Ptr value);
    std::string as_string() const override;
private:
    Node::Ptr m_id, m_type, m_value;
};

class Return : public Node {
public:
    Return(Node::Ptr value);
    std::string as_string() const override;
private:
    Node::Ptr m_value;
};

class StmtL : public Node {
public:
    StmtL(Node::Ptr stmt_list);
    std::string as_string() const override;
private:
    Node::Ptr m_stmt_list;
};

class StmtN : public Node {
public:
    StmtN(Node::Ptr stmt, Node::Ptr next);
    StmtN();
    std::string as_string() const override;
private:
    Node::Ptr m_stmt;
    Node::Ptr m_next;
};

}
#endif
