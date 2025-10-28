#include <kiraz/ast/Statements.h>
#include <fmt/core.h>

namespace ast {

ModuleL::ModuleL(Node::Ptr stmt_list)
    : Node(MODULE), m_stmt_list(stmt_list) {}

std::string ModuleL::as_string() const {
    return fmt::format("ModuleL(body={})", m_stmt_list->as_string());
}

ModuleN::ModuleN(Node::Ptr stmt, Node::Ptr next)
    : Node(MODULE), m_stmt(stmt), m_next(next) {}

ModuleN::ModuleN() : Node(MODULE), m_stmt(nullptr), m_next(nullptr) {}

std::string ModuleN::as_string() const {
    if (!m_stmt) return "ModuleN(empty)";
    return fmt::format("ModuleN(stmt={}, next={})", 
        m_stmt->as_string(), 
        m_next ? m_next->as_string() : "null");
}

Func::Func(Node::Ptr name, Node::Ptr args, Node::Ptr ret_type, Node::Ptr body)
    : Node(KW_FUNC), m_name(name), m_args(args), m_ret_type(ret_type), m_body(body) {}

std::string Func::as_string() const {
    return fmt::format("Func(name={}, args={}, ret_type={}, body={})",
        m_name ? m_name->as_string() : "null",
        m_args ? m_args->as_string() : "null",
        m_ret_type ? m_ret_type->as_string() : "null",
        m_body ? m_body->as_string() : "null"
    );
}

KwImport::KwImport(Node::Ptr path)
    : Node(KW_IMPORT), m_path(path) {}

std::string KwImport::as_string() const {
    return fmt::format("Import(path={})", m_path ? m_path->as_string() : "null");
}

KwIfElse::KwIfElse(Node::Ptr cond, Node::Ptr if_body, Node::Ptr else_body)
    : Node(KW_IF), m_cond(cond), m_if_body(if_body), m_else_body(else_body) {}

std::string KwIfElse::as_string() const {
    return fmt::format("IfElse(cond={}, if_body={}, else_body={})",
        m_cond->as_string(),
        m_if_body->as_string(),
        m_else_body ? m_else_body->as_string() : "null"
    );
}

ClassDef::ClassDef(Node::Ptr name, Node::Ptr inherit, Node::Ptr body)
    : Node(KW_CLASS), m_name(name), m_inherit(inherit), m_body(body) {}

std::string ClassDef::as_string() const {
    return fmt::format("Class(name={}, inherit={}, body={})",
        m_name->as_string(),
        m_inherit ? m_inherit->as_string() : "null",
        m_body->as_string()
    );
}

KwWhile::KwWhile(Node::Ptr cond, Node::Ptr body)
    : Node(KW_WHILE), m_cond(cond), m_body(body) {}

std::string KwWhile::as_string() const {
    return fmt::format("While(cond={}, body={})",
        m_cond->as_string(),
        m_body->as_string()
    );
}

KwLet::KwLet(int op, Node::Ptr id, Node::Ptr value, int i)
    : Node(op), m_id(id), m_type(nullptr), m_value(value) {}

KwLet::KwLet(int op, Node::Ptr id, Node::Ptr type, Node::Ptr value)
    : Node(op), m_id(id), m_type(type), m_value(value) {}

std::string KwLet::as_string() const {
     return fmt::format("Let(id={}, type={}, value={})",
        m_id->as_string(),
        m_type ? m_type->as_string() : "null",
        m_value ? m_value->as_string() : "null"
    );
}

Return::Return(Node::Ptr value)
    : Node(KW_RETURN), m_value(value) {}

std::string Return::as_string() const {
    return fmt::format("Return(value={})", m_value ? m_value->as_string() : "null");
}

StmtL::StmtL(Node::Ptr stmt_list)
    : Node(STMT_L), m_stmt_list(stmt_list) {}

std::string StmtL::as_string() const {
    return fmt::format("StmtList(body={})", m_stmt_list->as_string());
}

StmtN::StmtN(Node::Ptr stmt, Node::Ptr next)
    : Node(STMT_N), m_stmt(stmt), m_next(next) {}

StmtN::StmtN() : Node(STMT_N), m_stmt(nullptr), m_next(nullptr) {}

std::string StmtN::as_string() const {
    if (!m_stmt) return "StmtN(empty)";
    return fmt::format("StmtN(stmt={}, next={})", 
        m_stmt->as_string(), 
        m_next ? m_next->as_string() : "null");
}

}
