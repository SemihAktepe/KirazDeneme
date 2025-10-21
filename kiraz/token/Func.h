#ifndef KIRAZ_TOKEN_FUNC_H
#define KIRAZ_TOKEN_FUNC_H

#include <kiraz/Token.h>

namespace token {

class Func : public Token {
public:
    Func() : Token(KW_FUNC){}
    std::string as_string() const override {return "Func";}

};

}

#endif // KIRAZ_TOKEN_FUNC_H
