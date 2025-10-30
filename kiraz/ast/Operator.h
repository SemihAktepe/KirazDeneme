#ifndef KIRAZ_AST_OPERATOR_H
#define KIRAZ_AST_OPERATOR_H

#include <cassert>
#include <kiraz/Node.h>
#include <fmt/format.h>

namespace ast {

// --- Unary (Signed) Node ---
class SignedNode : public Node {
    public:
        SignedNode(int op, const Node::Ptr &expr)
            : Node(op), m_expr(expr) {
            assert(expr);
        }
    
        std::string as_string() const override {
            std::string op_str = (get_id() == OP_MINUS) ? "OP_MINUS" : "OP_PLUS";
            return fmt::format("Signed({}, {})", op_str, m_expr->as_string());
        }
        
        
    
        Node::Ptr gen_wat(WasmContext &) override {
            return shared_from_this();
        }
    
    private:
        Node::Ptr m_expr;
    };
    
    

// --- Binary Operators ---
class OpBinary : public Node {
protected:
    explicit OpBinary(int op, const Node::Ptr &left, const Node::Ptr &right)
        : Node(op), m_left(left), m_right(right) {
        assert(left);
        assert(right);
    }

public:
    auto get_left() const { return m_left; }
    auto get_right() const { return m_right; }

    std::string as_string() const override {
        assert(get_left());
        assert(get_right());

        std::string opstr;
        switch (get_id()) {
            case OP_GT:     opstr = "OpGt"; break;
            case OP_LT:     opstr = "OpLt"; break;
            case OP_LTEQU:  opstr = "OpLe"; break;
            case OP_GTEQU:  opstr = "OpGe"; break;
            case OP_EQUAL:  opstr = "OpEq"; break;
            case OP_ASSIGN: opstr = "Assign"; break;
            case OP_DOT:    opstr = "Dot"; break;
            case OP_PLUS:   opstr = "Add"; break;
            case OP_MINUS:  opstr = "Sub"; break;
            case OP_MULT:   opstr = "Mult"; break;
            case OP_DIVF:   opstr = "DivF"; break;
            case OP_COLON:  opstr = "Colon"; break;
            default:        opstr = "UnknownOp"; break;
        }
        return fmt::format("{}(l={}, r={})",
                           opstr,
                           get_left()->as_string(),
                           get_right()->as_string());
    }

private:
    Node::Ptr m_left, m_right;
};

#define DEFINE_BINARY_OPERATOR(ClassName, OpId) \
class ClassName : public OpBinary { \
public: \
    ClassName(const Node::Ptr &left, const Node::Ptr &right) \
        : OpBinary(OpId, left, right) {} \
};

#define DEFINE_BINARY_OPERATOR_WITH_COMPUTE(ClassName, OpId) \
class ClassName : public OpBinary { \
public: \
    ClassName(const Node::Ptr &left, const Node::Ptr &right) \
        : OpBinary(OpId, left, right) {} \
    virtual Ptr compute_stmt_type(SymbolTable &st) override; \
};

DEFINE_BINARY_OPERATOR_WITH_COMPUTE(OpGt, OP_GT)
DEFINE_BINARY_OPERATOR_WITH_COMPUTE(OpLt, OP_LT)
DEFINE_BINARY_OPERATOR_WITH_COMPUTE(OpGtEqu, OP_GTEQU)
DEFINE_BINARY_OPERATOR_WITH_COMPUTE(OpLtEqu, OP_LTEQU)
DEFINE_BINARY_OPERATOR_WITH_COMPUTE(OpEqual, OP_EQUAL)
DEFINE_BINARY_OPERATOR_WITH_COMPUTE(OpAssign, OP_ASSIGN)
DEFINE_BINARY_OPERATOR_WITH_COMPUTE(OpDot, OP_DOT)
DEFINE_BINARY_OPERATOR_WITH_COMPUTE(OpAdd, OP_PLUS)
DEFINE_BINARY_OPERATOR(OpSub, OP_MINUS)
DEFINE_BINARY_OPERATOR(OpMult, OP_MULT)
DEFINE_BINARY_OPERATOR(OpDivF, OP_DIVF)
DEFINE_BINARY_OPERATOR(OpColon, OP_COLON)

#undef DEFINE_BINARY_OPERATOR
#undef DEFINE_BINARY_OPERATOR_WITH_COMPUTE

} // namespace ast

#endif // KIRAZ_AST_OPERATOR_H
