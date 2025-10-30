#ifndef KIRAZ_AST_CALL_H
#define KIRAZ_AST_CALL_H

#include <cassert>


#include <kiraz/Node.h>

namespace ast {
class Call : public Node {
public:
    Call(const Node::Ptr &name, const Node::Ptr &h) : Node(), nameC(name), m_value(h) {
        
    }
    Node::Ptr get_nameL(){return nameC;}
    Node::Ptr get_args(){return m_value;}
    std::string as_string() const override {
            if(m_value != nullptr){
                return fmt::format("Call(n={}, a={})",nameC->as_string(), m_value->as_string());
                }
            else{
                return fmt::format("Call(n={}, a=[])",nameC->as_string());
            }
        }
    Node::Ptr compute_stmt_type(SymbolTable &st) override;
private:
    Node::Ptr m_value = nullptr, nameC = nullptr;
};


class CallS : public Node {
public: 

    explicit CallS() : Node(){};
    
    explicit CallS(const Node::Ptr &id1) 
        : Node(), id1C(id1){
            assert(id1);
        };
    explicit CallS( const Node::Ptr &id1, const Node::Ptr &val) 
        : Node(), id1C(id1), next(val){
            assert(id1);
            assert(next);
        };
 
    Node::Ptr get_id1() const{return id1C;}
    Node::Ptr get_next() const{return next;}



    std::string as_string() const override{
        //type id controlü
        if(id1C != nullptr){
            return fmt::format("{}",get_id1()->as_string());
        }
        else {
            return fmt::format("");
        }
        
    }
Node::Ptr next = nullptr;


private:
    Node::Ptr id1C= nullptr;
};

class CallL : public Node{
public:
    CallL() : Node() {}
    CallL(const Node::Ptr &h);

    Node::Ptr get_head(){return head;};
    
    std::string as_string() const override {
        std::string output = "";
        if(std::static_pointer_cast<CallS>(head)->get_id1() != nullptr ){
            output += "FuncArgs([";
            for (size_t i = 0; i < arguments.size(); ++i) {
                output += "" + arguments[i]->as_string();
                if (i < arguments.size() - 1) {
                    output += ", ";
                    }
                }
                output += "])";
        }
        return fmt::format("{}", output);
    }
    void fill_arguments();


private:
    Node::Ptr head = nullptr ;
    std::vector<Node::Ptr> arguments;
    
};




}

#endif
