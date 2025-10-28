#ifndef KIRAZ_TOKEN_KEYWORDS_H
#define KIRAZ_TOKEN_KEYWORDS_H

#include <kiraz/Token.h>

namespace token {

#define DEFINE_KEYWORD_TOKEN(ClassName, TokenId) \
class ClassName : public Token { \
public: \
    ClassName() : Token(TokenId) {} \
    std::string as_string() const override { return #TokenId; } \
};

DEFINE_KEYWORD_TOKEN(KwLet, KW_LET)
DEFINE_KEYWORD_TOKEN(KwIf, KW_IF)
DEFINE_KEYWORD_TOKEN(KwElse, KW_ELSE)
DEFINE_KEYWORD_TOKEN(KwImport, KW_IMPORT)
DEFINE_KEYWORD_TOKEN(Func, KW_FUNC)
DEFINE_KEYWORD_TOKEN(KwClass, KW_CLASS)
DEFINE_KEYWORD_TOKEN(KwWhile, KW_WHILE)
DEFINE_KEYWORD_TOKEN(KwReturn, KW_RETURN)

#undef DEFINE_KEYWORD_TOKEN
}
#endif
