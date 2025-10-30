#ifndef KIRAZ_TOKEN_RETURN_H
#define KIRAZ_TOKEN_RETURN_H

#include <kiraz/Token.h>

namespace token {

class KwReturn : public Token {
public:
    KwReturn() : Token(KW_RETURN){}
    std::string as_string() const override {return "KW_RETURN";}

};

}

#endif // KIRAZ_TOKEN_KWLET_H
