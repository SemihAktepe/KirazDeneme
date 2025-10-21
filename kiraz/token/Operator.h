#ifndef KIRAZ_TOKEN_OPERATOR_H
#define KIRAZ_TOKEN_OPERATOR_H

#include <kiraz/Token.h>

namespace token {
class Operator : public Token {
public:
    Operator(int type) : Token(type) {}
};

class OpPlus : public Operator {
public:
    OpPlus(): Operator(OP_PLUS) {}
    std::string as_string() const override {return "OP_PLUS";}
};

class OpMinus : public Operator{
public:
    OpMinus() : Operator(OP_MINUS){}
    std::string as_string() const override {return "OP_MINUS";}
};

class OpMult: public Operator{
public:
    OpMult() : Operator(OP_MULT){}
    std::string as_string() const override {return "OP_MULT";}
};


class OpDivF: public Operator{
public:
    OpDivF() : Operator(OP_DIVF){}
    std::string as_string() const override {return "OP_DIVF";}
};

class OpLParen: public Operator{
public:
    OpLParen() : Operator(OP_LPAREN){}
    std::string as_string() const override {return "OP_LPAREN";}
};

class OpRParen: public Operator{
public:
    OpRParen() : Operator(OP_RPAREN){}                                
    std::string as_string() const override {return "OP_RPAREN";}
};

class OpAssign: public Operator {
public:
    OpAssign() : Operator(OP_ASSIGN){}
    std::string as_string() const override {return "OP_ASSIGN";}
};

class OpSemCol: public Operator {
public:
    OpSemCol() : Operator(OP_SEMCOL){}
    std::string as_string() const override {return "OP_SEMCOL";}
};

class OpColon: public Operator {
public:
    OpColon() : Operator(OP_COLON){}
    std::string as_string() const override {return "OP_COLON";}
};

class OpRBrace: public Operator {
public:
    OpRBrace() : Operator(OP_RBRACE){}
    std::string as_string() const override {return "OP_RBRACE";}
};

class OpLBrace: public Operator {
public:
    OpLBrace() : Operator(OP_LBRACE){}
    std::string as_string() const override {return "OP_LBRACE";}
};

class OpComma: public Operator {
public:
    OpComma() : Operator(OP_COMMA){}
    std::string as_string() const override {return "OP_COMMA";}
};

class OpEqual : public Operator{
public:
    OpEqual() : Operator(OP_EQUAL){}
    std::string as_string() const override {return "OP_EQUAL";}
};

class OpGt : public Operator{
public:
    OpGt() : Operator(OP_GT){}
    std::string as_string() const override {return "OP_GT";}
};

class OpLt : public Operator{
public:
    OpLt() : Operator(OP_LT){}
    std::string as_string() const override {return "OP_LT";}
};

class OpGtEqu : public Operator{
public:
    OpGtEqu() : Operator(OP_GTEQU){}
    std::string as_string() const override {return "OP_GTEQU";}
};


class OpLtEqu : public Operator{
public:
    OpLtEqu() : Operator(OP_LTEQU){}
    std::string as_string() const override {return "OP_LTEQU";}
};

class OpDot : public Operator{
public:
    OpDot() : Operator(OP_DOT){}
    std::string as_string() const override {return "OP_DOT";}
};


}

#endif
