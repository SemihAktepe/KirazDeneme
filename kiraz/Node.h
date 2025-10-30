#ifndef KIRAZ_NODE_H
#define KIRAZ_NODE_H

#include <cassert>
#include <sstream>
#include <vector>
#include <fmt/format.h>
#include <fmt/ranges.h>
#define FF fmt::format

#include <kiraz/Token.h>

extern int yylineno;

class SymbolTable;
struct Scope;
class WasmContext;

class Node : public std::enable_shared_from_this<Node> {
public:
    using Ptr = std::shared_ptr<Node>;
    using Cptr = std::shared_ptr<const Node>;

    Node();
    explicit Node(int op_token) { m_id = FF("Tok{}", op_token); }
    virtual ~Node();


    virtual std::string as_string() const = 0;
    void print() { fmt::print("{}\n", as_string()); }

    void set_pos(int l, int c) { m_line = l; m_col = c; }

    template <typename T, typename... Args>
    static auto add(Args &&...args) {
        auto root = std::make_shared<T>(std::forward<Args>(args)...);
        root->set_pos(yylineno, Token::colno);
        s_roots.back() = root;
        return root;
    }

    template <typename T>
    static auto wrap(Node::Ptr node) {
        return std::make_shared<T>(std::vector{node});
    }

    static auto &current_root() {
        assert(!s_roots.empty());
        return s_roots.back();
    }

    // ---- Özellik bayrakları ----
    virtual bool is_func() const { return false; }
    virtual bool is_class() const { return false; }
    virtual bool is_funcarg_list() const { return false; }
    virtual void set_funcarg_list() { assert(false); }
    virtual bool is_callarg_list() const { return false; }
    virtual bool is_stmt_list() const { return false; }
    virtual bool is_class_stmt_list() const { return false; }
    virtual void set_class_stmt_list() { assert(false); }

    // ---- Sembolik Tablo Girdisi ----
    struct SymTabEntry {
        std::string name;
        Cptr stmt;

        SymTabEntry() {}
        SymTabEntry(const Ptr s) : stmt(s) {}
        SymTabEntry(const Cptr s) : stmt(s) {}
        SymTabEntry(const std::string &n, const Cptr s = nullptr) : name(n), stmt(s) {}

        operator bool() const { return stmt != nullptr; }
        operator Cptr() const { return stmt; }
        bool first_letter_uppercase() { return name.front() >= 'A' && name.front() <= 'Z'; }
        bool first_letter_lowercase() { return name.front() >= 'a' && name.front() <= 'z'; }
        bool is_builtin() {
            return name == "and" || name == "or" || name == "not" || name == "Boolean"
                || name == "String" || name == "Integer64";
        }
    };

    // ---- Ana işlem fonksiyonları ----
    virtual Ptr compute_stmt_type(SymbolTable &st);
    virtual Ptr add_to_symtab_forward(SymbolTable &st);
    virtual Ptr add_to_symtab_ordered(SymbolTable &st);
    virtual SymTabEntry get_symbol(const SymbolTable &) const { return {}; }
    virtual SymTabEntry get_symbol() const { return {}; }
    virtual SymTabEntry get_subsymbol(Ptr) const { return {}; }
    virtual const SymbolTable *get_subsymbol_all() const { return {}; }

    // ---- Statik arabirim ----
    static const Ptr &get_root() { return s_roots.back(); }
    static Ptr pop_root();
    static const Ptr &get_root_before();
    static const Ptr &get_first();
    static const Ptr &get_first_before();
    static void reset_root() {
        s_roots.emplace_back();
        s_next_id = 0;
    }

    auto get_line() const { return m_line; }
    auto get_col() const { return m_col; }

    const auto &get_error() const { return m_error; }
    Node::Ptr set_error(const std::string &error) {
        m_error = error;
        return m_error.empty() ? nullptr : shared_from_this();
    }

    const auto &get_stmt_type() const { return m_type; }
    void set_stmt_type(const Cptr &type) {
        assert(type);
        m_type = type;
    }

    void set_cur_symtab(std::shared_ptr<Scope> symtab) {
        assert((!m_cur_symtab) || (m_cur_symtab == symtab));
        m_cur_symtab = symtab;
    }

    auto get_cur_symtab() { return m_cur_symtab; }
    auto get_cur_symtab() const { return m_cur_symtab; }

    virtual Node::Ptr gen_wat(WasmContext &);
    virtual Node::Ptr gen_wat(WasmContext &, const std::string &id) const;

// String ID getter (modern v2 interface)
const std::string &get_id_str() const {
    assert(!m_id.empty());
    return m_id;
}

// Integer ID getter (v1 compatibility for switch cases)
int get_id() const {
    if (m_id.rfind("Tok", 0) == 0) {
        try {
            return std::stoi(m_id.substr(3));
        } catch (...) {
            return -1;
        }
    }
    return -1;
}


    void set_id(const std::string &v) {
        assert(!v.empty());
        m_id = v;
    }

protected:
    std::shared_ptr<Scope> m_cur_symtab;

private:
    static std::vector<Node::Ptr> s_roots;
    static int64_t s_next_id;

    Cptr m_type;
    std::string m_id;
    std::string m_error;
    int m_line = 0;
    int m_col = 0;
};

// ---- Formatter’lar ----
template <>
struct fmt::formatter<Node> : fmt::formatter<std::string> {
    format_context::iterator format(const Node &stmt, format_context &ctx) const {
        return fmt::formatter<std::string>::format(stmt.as_string(), ctx);
    }
};

template <>
struct fmt::formatter<std::vector<Node::Ptr>> : fmt::formatter<std::string> {
    format_context::iterator
    format(const std::vector<Node::Ptr> &stmts, format_context &ctx) const {
        std::stringstream sstr;
        sstr << "[";
        bool first = true;
        for (const auto &stmt : stmts) {
            if (!first)
                sstr << ", ";
            first = false;
            sstr << FF("{}", *stmt);
        }
        sstr << "]";
        return fmt::formatter<std::string>::format(sstr.str(), ctx);
    }
};

#endif // KIRAZ_NODE_H
