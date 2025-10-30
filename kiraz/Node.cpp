#include "Node.h"
#include <kiraz/Compiler.h>
#include <string>

int64_t Node::s_next_id = 0;
std::vector<Node::Ptr> Node::s_roots;
Token::Ptr curtoken;

Node::Node() : m_id(FF("Ki{}", ++s_next_id)) {}
Node::~Node() {}

Node::Ptr Node::compute_stmt_type(SymbolTable &st) {
    set_cur_symtab(st.get_cur_symtab());
    return nullptr;
}

Node::Ptr Node::add_to_symtab_forward(SymbolTable &st) { return nullptr; }
Node::Ptr Node::add_to_symtab_ordered(SymbolTable &st) { return nullptr; }

Node::Ptr Node::pop_root() {
    assert(!s_roots.empty());
    auto retval = s_roots.back();
    s_roots.pop_back();
    return retval;
}

const Node::Ptr &Node::get_root_before() {
    assert(s_roots.size() > 1);
    return *std::next(s_roots.rbegin());
}

// V1 test uyumluluğu için ek fonksiyon
const Node::Ptr &Node::get_first_before() {
    if (s_roots.size() > 1)
        return *std::next(s_roots.rbegin());
    static Node::Ptr nullnode = nullptr;
    return nullnode;
}

const Node::Ptr &Node::get_first() {
    assert(!s_roots.empty());
    return s_roots.front();
}

Node::Ptr Node::gen_wat(WasmContext &) {
    assert(!m_id.empty());
    return nullptr;
}

Node::Ptr Node::gen_wat(WasmContext &, const std::string &id) const {
    assert(!id.empty());
    return nullptr;
}
