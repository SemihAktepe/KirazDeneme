#ifndef KIRAZ_TOKEN_KWIF_H
#define KIRAZ_TOKEN_KWIF_H

#include <kiraz/Token.h>

namespace token {

class KwIf : public Token {
public:
    KwIf() : Token(KW_IF) {}
    std::string as_string() const override { return "If"; }
};

}

#endif // KIRAZ_TOKEN_KWIF_H
