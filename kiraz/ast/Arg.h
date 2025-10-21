#ifndef KIRAZ_AST_ARG_H
#define KIRAZ_AST_ARG_H

#include <cassert>


#include <kiraz/Node.h>
#include "Id.h"
namespace ast {
class Arg : public Node {
public: 

    explicit Arg() : Node(){};
    
    explicit Arg(const Node::Ptr &id1, const Node::Ptr &id2) 
        : Node(), id1C(id1), id2C(id2){
            assert(id1);
            assert(id2);
        };
    explicit Arg( const Node::Ptr &id1, const Node::Ptr &id2, const Node::Ptr &val) 
        : Node(), id1C(id1), next(val), id2C(id2){
            assert(id1);
            assert(id2);
        };
 
    Node::Ptr get_id1() const{return id1C;}
    Node::Ptr get_id2() const{return id2C;}
    Node::Ptr get_next() const{return next;}

    std::string as_name_id1() {
        std::string n = std::static_pointer_cast<ast::Id>(std::const_pointer_cast<Node>(get_id1()))->get_name();
        return n;}
    std::string as_name_id2() {
        std::string n = std::static_pointer_cast<ast::Id>(std::const_pointer_cast<Node>(get_id2()))->get_name();
        return n;}

    std::string as_string() const override{
        //type id controlü
        if(id1C != nullptr){
            return fmt::format("{}(n={}, t={})","FArg",get_id1()->as_string(),get_id2()->as_string());
        }
        else {
            return fmt::format("");
        }
        
    }
    
    

    Node::Ptr next = nullptr;

    Node::Ptr compute_stmt_type(SymbolTable &st) override;
    Node::Ptr add_to_symtab_ordered(SymbolTable &st) override;
private:
    Node::Ptr id1C= nullptr, id2C= nullptr;
};

class Args : public Node{
public:
    explicit Args( const Node::Ptr &h);

    Node::Ptr get_head(){return head;};
    
    std::string as_string() const override {
        std::string output = "";
        if(std::static_pointer_cast<Arg>(head)->get_id1() != nullptr ){
            output += "FuncArgs([";
            for (size_t i = 0; i < arguments.size(); ++i) {
                output += "" + arguments[i]->as_string();
                if (i < arguments.size() - 1) {
                    output += ", ";
                    }
                }
                output += "])";
        }
        else{
            output += "[]";
        }
        return fmt::format("{}",output);
    }
    virtual bool is_funcarg_list() const override { return true; }
    void set_funcarg_list() override;
    Node::Ptr compute_stmt_type(SymbolTable &st) override;

private:
    Node::Ptr head;
    std::vector<Node::Ptr> arguments;
    
};




}

#endif
