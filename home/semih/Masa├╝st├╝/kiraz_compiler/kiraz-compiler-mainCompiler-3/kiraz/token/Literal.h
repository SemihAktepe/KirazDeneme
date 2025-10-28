#ifndef KIRAZ_TOKEN_LITERALS_H
#define KIRAZ_TOKEN_LITERALS_H

#include <kiraz/Token.h>
#include <string>

namespace token {

class Id : public Token {
public:
    Id(const char *s) : Token(ID), m_val(s) {}
    std::string as_string() const override { return "ID(" + m_val + ")"; }
    const std::string &get_val() const { return m_val; }
private:
    std::string m_val;
};

class Integer : public Token {
public:
    Integer(int base, const char *text) : Token(L_INTEGER) {
        m_val = std::strtol(text, nullptr, base);
    }
    std::string as_string() const override { return "INT(" + std::to_string(m_val) + ")"; }
    long get_val() const { return m_val; }
private:
    long m_val;
};

class Str : public Token {
public:
    Str(const char *s) : Token(L_STRING), m_val(s) {
        m_val = m_val.substr(1, m_val.length() - 2);
    }
    std::string as_string() const override { return "STR(" + m_val + ")"; }
    const std::string &get_val() const { return m_val; }
private:
    std::string m_val;
};

}
#endif