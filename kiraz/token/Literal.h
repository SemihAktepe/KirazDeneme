#ifndef KIRAZ_TOKEN_LITERAL_H
#define KIRAZ_TOKEN_LITERAL_H

#include <kiraz/Token.h>
#include <string>

// forward declaration for AST friend access
namespace ast {
    class Integer;
    class Str;
}

namespace token {

class Integer : public Token {
    friend class ast::Integer;
public:
    Integer(int base, const char *text)
        : Token(L_INTEGER), m_val(text), m_base(base) {}

    std::string as_string() const override {
        return "Integer(" + m_val + ")";
    }

private:
    std::string m_val;
    int m_base;
};

class Str : public Token {
    friend class ast::Str;
public:
    explicit Str(const char *text)
        : Token(L_STRING), m_val(text) {}

    std::string as_string() const override {
        return "String(\"" + m_val + "\")";
    }

private:
    std::string m_val;
};

} // namespace token

#endif // KIRAZ_TOKEN_LITERAL_H
