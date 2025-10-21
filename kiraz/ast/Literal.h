
#ifndef KIRAZ_AST_LITERAL_H
#define KIRAZ_AST_LITERAL_H

#include <kiraz/Node.h>

namespace ast {
class Integer : public Node {
public:
    Integer(Token::Ptr);
    
    std::string as_string() const override {return fmt::format("Int({})" ,m_value);}
    
   
    Node::Ptr compute_stmt_type(SymbolTable &st) override;
    
private:
    int64_t m_value;
    int64_t base;
};

class Str : public Node {
public:
    Str(Token::Ptr);

    std::string as_string() const override {return fmt::format("Str({})",str);}
    std::string get_str() {return str;}
    std::string get_new_st(){

            std::string raw_string = get_str().substr(1, get_str().size() - 2); 

            std::string processed_string;
            for (size_t i = 0; i < raw_string.size(); ++i) {
                    if (raw_string[i] == '\\' && i + 1 < raw_string.size()) {
                            switch (raw_string[i + 1]) {
                            case 'n': processed_string += '\n'; break;
                            case 't': processed_string += '\t'; break;
                            case '\\': processed_string += '\\'; break;
                            case '"': processed_string += '"'; break;
                            default: processed_string += raw_string[i + 1]; break;
                    }
                ++i;
            } 
            else {
                processed_string += raw_string[i];
            }
        }
        return processed_string;   
    }
    Node::Ptr compute_stmt_type(SymbolTable &st) override;

private:
    std::string str;
};

class SignedNode : public Node {
public:
    SignedNode(int op, Node::Cptr operand) :Node(op), m_operator(op), m_operand(operand){}

    std::string as_string() const override{
        std::string opstr;

        switch(get_id()){
            case OP_PLUS:
                opstr = "OP_PLUS";
                break;

            case OP_MINUS:
                opstr = "OP_MINUS";
                break;
            default:
                break;

        }
        return fmt::format("Signed({}, {})",opstr, m_operand-> as_string());
    }

private:
    int m_operator;
    Node::Cptr m_operand;

};
}

#endif
