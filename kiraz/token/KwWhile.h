#ifndef KIRAZ_TOKEN_KWWHILE_H
#define KIRAZ_TOKEN_KWWHILE_H

#include <kiraz/Token.h>

namespace token {

class KwWhile : public Token {
public:
    KwWhile() : Token(KW_WHILE){}
    std::string as_string() const override {return "While";}

};

}

#endif // KIRAZ_TOKEN_KWIMPORT_H