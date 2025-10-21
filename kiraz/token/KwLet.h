#ifndef KIRAZ_TOKEN_KWLET_H
#define KIRAZ_TOKEN_KWLET_H

#include <kiraz/Token.h>

namespace token {

class KwLet : public Token {
public:
    KwLet() : Token(KW_LET){}
    std::string as_string() const override {return "Let";}

};

}

#endif // KIRAZ_TOKEN_KWLET_H
