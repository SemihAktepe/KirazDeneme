#ifndef KIRAZ_TOKEN_KWCLASS_H
#define KIRAZ_TOKEN_KWCLASS_H

#include <kiraz/Token.h>

namespace token {

class KwClass : public Token {
public:
    KwClass() : Token(KW_CLASS) {}
    std::string as_string() const override { return "Class"; }
};

} 

#endif // KIRAZ_TOKEN_KWCLASS_H
