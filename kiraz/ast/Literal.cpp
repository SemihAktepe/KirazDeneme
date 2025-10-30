#include <kiraz/ast/Literal.h>
#include <kiraz/token/Literal.h>
#include <fmt/format.h>
#include <cassert>

namespace ast {

Integer::Integer(Token::Ptr t) {
    assert(t);
    assert(t->get_id() == L_INTEGER);

    auto token_int = std::static_pointer_cast<const token::Integer>(t);
    m_val = std::stoi(token_int->m_val);

    set_id("L_INTEGER");
}

std::string Integer::as_string() const {
    return fmt::format("Int({})", m_val);
}


Node::Ptr Integer::gen_wat(WasmContext &) {
    return shared_from_this();
}

Str::Str(Token::Ptr t) {
    assert(t);
    assert(t->get_id() == L_STRING);

    auto token_str = std::static_pointer_cast<const token::Str>(t);
    const std::string &raw = token_str->m_val; // örn: "\"a\\n\\t\\\"b\""

    // 1) Dış tırnakları sök
    std::string inner = raw;
    if (!inner.empty() && inner.front() == '"' && inner.back() == '"' && inner.size() >= 2) {
        inner = inner.substr(1, inner.size() - 2);
    }

    // 2) Kaçışları çöz -> m_val gerçek karakterleri tutsun
    std::string unescaped;
    unescaped.reserve(inner.size());
    for (size_t i = 0; i < inner.size(); ++i) {
        char c = inner[i];
        if (c == '\\' && i + 1 < inner.size()) {
            char n = inner[i + 1];
            switch (n) {
                case 'n':  unescaped.push_back('\n'); break;
                case 't':  unescaped.push_back('\t'); break;
                case 'r':  unescaped.push_back('\r'); break;
                case '\\': unescaped.push_back('\\'); break;
                case '"':  unescaped.push_back('"');  break;
                default:   unescaped.push_back(n);    break;
            }
            ++i;
        } else {
            unescaped.push_back(c);
        }
    }
    m_val = std::move(unescaped);
    set_id("L_STRING");
}

std::string Str::as_string() const {
    return fmt::format("Str({})", m_val);
}





Node::Ptr Str::gen_wat(WasmContext &) {
    return shared_from_this();
}



} // namespace ast
