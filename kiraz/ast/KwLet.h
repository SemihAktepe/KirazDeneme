
#ifndef KIRAZ_AST_KWLET_H
#define KIRAZ_AST_KWLET_H

#include <cassert>

#include <kiraz/Node.h>

namespace ast {
class KwLet : public Node {
public: 
    explicit KwLet(int let, const Node::Ptr &id1, const Node::Ptr &val) 
        : Node(let), id1C(id1), valC(val){
            assert(id1);
            assert(val);
        };
    explicit KwLet(int let, const Node::Ptr &id1, const Node::Ptr &id2, int m) 
        : Node(let), id1C(id1), id2C(id2), mC(m){
            assert(id1);
            assert(id2);
        };
    explicit KwLet(int let, const Node::Ptr &id1, const Node::Ptr &id2, const Node::Ptr &val) 
        : Node(let), id1C(id1), valC(val), id2C(id2){
            assert(id1);
            assert(id2);
            assert(val);
        };
 
    Node::Ptr get_id1() const{return id1C;}
    Node::Ptr get_id2() const{return id2C;}
    Node::Ptr get_valC() const{return valC;}

    std::string as_string() const override{
        assert(get_id1());
        //type id controlü
        if(get_id2() == nullptr){
            return fmt::format("{}(n={}, i={})","Let",get_id1()->as_string(),get_valC()->as_string());
        }
        else if(mC == 1){
            return fmt::format("{}(n={}, t={})","Let",get_id1()->as_string(),get_id2()->as_string());
        }
        else{
            return fmt::format("{}(n={}, t={}, i={})","Let",get_id1()->as_string(),get_id2()->as_string(),get_valC()->as_string());
        }
    }

    Node::Ptr add_to_symtab_ordered(SymbolTable &st) override;
    Node::Ptr compute_stmt_type(SymbolTable &st) override;


private:
    Node::Ptr id1C, valC,id2C = nullptr;
    int mC = 0;
};

}

#endif
