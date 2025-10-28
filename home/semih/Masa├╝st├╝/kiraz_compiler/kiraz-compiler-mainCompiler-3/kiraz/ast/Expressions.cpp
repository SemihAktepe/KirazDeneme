#include <kiraz/ast/Expressions.h>
#include <kiraz/token/Literals.h>
#include <fmt/core.h>

namespace ast {

Id::Id(std::shared_ptr<token::Token> tok) : Node(ID) {
    auto id_tok = std::dynamic_pointer_cast<token::Id>(tok);
    m_val = id_tok->get_val();
}
std::string Id::as_string() const { return fmt::format("Id({})", m_val); }


Call::Call(Node::Ptr name, Node::Ptr args)
    : Node(CALL), m_name(name), m_args(args) {}

std::string Call::as_string() const {
    return fmt::format("Call(name={}, args={})",
        m_name->as_string(),
        m_args ? m_args->as_string() : "null"
    );
}


CallL::CallL(Node::Ptr args) : Node(CALL_L), m_args(args) {}

std::string CallL::as_string() const {
    return fmt::format("CallList(args={})", m_args ? m_args->as_string() : "null");
}


CallS::CallS(Node::Ptr arg) : Node(CALL_S), m_arg(arg) {}
CallS::CallS() : Node(CALL_S), m_arg(nullptr) {}

std::string CallS::as_string() const {
    if (!m_arg) return "CallS(empty)";
    return fmt::format("CallS(arg={}, next={})",
        m_arg->as_string(),
        next ? next->as_string() : "null"
    );
}


Args::Args(Node::Ptr arg_list) : Node(ARGS), m_arg_list(arg_list) {}

std::string Args::as_string() const {
    return fmt::format("Args(list={})", m_arg_list ? m_arg_list->as_string() : "null");
}


Arg::Arg(Node::Ptr name, Node::Ptr type)
    : Node(ARG), m_name(name), m_type(type) {}
Arg::Arg() : Node(ARG), m_name(nullptr), m_type(nullptr) {}

std::string Arg::as_string() const {
    if (!m_name) return "Arg(empty)";
    return fmt::format("Arg(name={}, type={}, next={})",
        m_name->as_string(),
        m_type->as_string(),
        next ? next->as_string() : "null"
    );
}

}
