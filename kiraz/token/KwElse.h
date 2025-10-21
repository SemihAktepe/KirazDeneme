#ifndef KIRAZ_TOKEN_KWELSE_H
#define KIRAZ_TOKEN_KWELSE_H

#include <kiraz/Token.h>

namespace token {

class KwElse : public Token {
public:
    KwElse() : Token(KW_ELSE) {}
    std::string as_string() const override { return "Else"; }
};

}

#endif // KIRAZ_TOKEN_KWELSE_H
