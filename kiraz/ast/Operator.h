
#ifndef KIRAZ_AST_OPERATOR_H
#define KIRAZ_AST_OPERATOR_H

#include <cassert>

#include <kiraz/Node.h>

namespace ast {
class OpBinary : public Node{
protected:
    explicit OpBinary(int op, const Node::Ptr &left, const Node::Ptr &right)
            : Node(op), m_left(left), m_right(right){
                assert(left);
                assert(right);
            }

public:
    auto get_left() const{ return m_left;}
    auto get_right() const{ return m_right;}
    
    std::string as_string() const override{
        assert(get_left());
        assert(get_right());

        std::string opstr;
        switch(get_id()){
            case OP_PLUS:
                opstr = "Add";
                break;
            case OP_MINUS:
                opstr = "Sub";
                break;
            case OP_MULT:
                opstr = "Mult";
                break;
            case OP_DIVF:
                opstr = "DivF";
                break;
            case OP_ASSIGN:
                opstr = "Assign";
                break;
            case OP_EQUAL:
                opstr = "OpEq";
                break;
            case OP_GT:
                opstr = "OpGt";
                break;
            case OP_LT:
                opstr = "OpLt";
                break;
            case OP_LTEQU:
                opstr = "OpLe";
                break;
            case OP_GTEQU:
                opstr = "OpGe";
                break;
            case OP_DOT:
                opstr = "Dot";
                break;
            default:
                break;
        }
        return fmt::format("{}(l={}, r={})",opstr, get_left()->as_string(), get_right()->as_string());
    }



private:
    Node::Ptr m_left, m_right;

};

class OpAdd : public OpBinary{
public:
    OpAdd(const Node::Ptr &left, const Node::Ptr &right) : OpBinary(OP_PLUS,left,right){}
    virtual Ptr compute_stmt_type(SymbolTable &st) override;
};

class OpSub : public OpBinary{
public:
    OpSub(const Node::Ptr &left, const Node::Ptr &right) : OpBinary(OP_MINUS,left, right){}
};

class OpMult : public OpBinary{
public:
    OpMult(const Node::Ptr &left, const Node:: Ptr & right) : OpBinary(OP_MULT,left,right){}
};

class OpDivF : public OpBinary{
public:
    OpDivF(const Node::Ptr &left, const Node::Ptr &right) : OpBinary(OP_DIVF,left,right){}
};

class OpAssign : public OpBinary{
public:
    OpAssign(const Node::Ptr &left, const Node::Ptr &right) : OpBinary(OP_ASSIGN,left,right){}
    virtual Ptr compute_stmt_type(SymbolTable &st) override;
};

class OpColon : public OpBinary{
public:
    OpColon(const Node::Ptr &left, const Node::Ptr &right) : OpBinary(OP_COLON,left,right){}
};

class OpEqual : public OpBinary{
public:
    OpEqual(const Node::Ptr &left, const Node::Ptr &right) : OpBinary(OP_EQUAL,left,right){}
    virtual Ptr compute_stmt_type(SymbolTable &st) override;
};

class OpGt : public OpBinary{
public:
    OpGt(const Node::Ptr &left, const Node::Ptr &right) : OpBinary(OP_GT,left,right){}
    virtual Ptr compute_stmt_type(SymbolTable &st) override;
};

class OpLt : public OpBinary{
public:
    OpLt(const Node::Ptr &left, const Node::Ptr &right) : OpBinary(OP_LT,left,right){}
    virtual Ptr compute_stmt_type(SymbolTable &st) override;
};

class OpGtEqu : public OpBinary{
public:
    OpGtEqu(const Node::Ptr &left, const Node::Ptr &right) : OpBinary(OP_GTEQU,left,right){}
    virtual Ptr compute_stmt_type(SymbolTable &st) override;
};

class OpDot : public OpBinary{
public:
    OpDot(const Node::Ptr &left, const Node::Ptr &right) : OpBinary(OP_DOT,left,right){}
    virtual Ptr compute_stmt_type(SymbolTable &st) override;
};


class OpLtEqu : public OpBinary{
public:
    OpLtEqu(const Node::Ptr &left, const Node::Ptr &right) : OpBinary(OP_LTEQU,left,right){}
    virtual Ptr compute_stmt_type(SymbolTable &st) override;
};


}
#endif // KIRAZ_AST_OPERATOR_H
