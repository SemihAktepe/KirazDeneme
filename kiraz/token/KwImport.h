#ifndef KIRAZ_TOKEN_KWIMPORT_H
#define KIRAZ_TOKEN_KWIMPORT_H

#include <kiraz/Token.h>

namespace token {

class KwImport : public Token {
public:
    KwImport() : Token(KW_IMPORT){}
    std::string as_string() const override {return "Import";}

};

}

#endif // KIRAZ_TOKEN_KWIMPORT_H
