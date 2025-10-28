#ifndef KIRAZ_TOKEN_OPERATOR_H
#define KIRAZ_TOKEN_OPERATOR_H

#include <kiraz/Token.h>

namespace token {

class Operator : public Token {
public:
    Operator(int type) : Token(type) {}
// TODO:
};

// İskeletinizin ikinci kısmı dolduruldu:
class OpPlus : public Operator {
public:
    OpPlus(): Operator(OP_PLUS) {}
    std::string as_string() const override {return "OP_PLUS";}
// TODO:
};

// "etc." 


#define DEFINE_OPERATOR_TOKEN(ClassName, OpId) \
class ClassName : public Operator { \
public: \
    ClassName() : Operator(OpId) {} \
    std::string as_string() const override { return #OpId; } \
};

// Kalan tüm sınıflar burada tek satırda tanımlanıyor:
DEFINE_OPERATOR_TOKEN(OpMinus, OP_MINUS)
DEFINE_OPERATOR_TOKEN(OpMult, OP_MULT)
DEFINE_OPERATOR_TOKEN(OpDivF, OP_DIVF)
DEFINE_OPERATOR_TOKEN(OpLParen, OP_LPAREN)
DEFINE_OPERATOR_TOKEN(OpRParen, OP_RPAREN)
DEFINE_OPERATOR_TOKEN(OpAssign, OP_ASSIGN)
DEFINE_OPERATOR_TOKEN(OpSemCol, OP_SEMCOL)
DEFINE_OPERATOR_TOKEN(OpColon, OP_COLON)
DEFINE_OPERATOR_TOKEN(OpRBrace, OP_RBRACE)
DEFINE_OPERATOR_TOKEN(OpLBrace, OP_LBRACE)
DEFINE_OPERATOR_TOKEN(OpComma, OP_COMMA)
DEFINE_OPERATOR_TOKEN(OpEqual, OP_EQUAL)
DEFINE_OPERATOR_TOKEN(OpGt, OP_GT)
DEFINE_OPERATOR_TOKEN(OpLt, OP_LT)
DEFINE_OPERATOR_TOKEN(OpGtEqu, OP_GTEQU)
DEFINE_OPERATOR_TOKEN(OpLtEqu, OP_LTEQU)
DEFINE_OPERATOR_TOKEN(OpDot, OP_DOT)


#undef DEFINE_OPERATOR_TOKEN

} // namespace token

#endif // KIRAZ_TOKEN_OPERATOR_H
