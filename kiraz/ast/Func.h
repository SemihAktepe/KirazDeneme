#ifndef KIRAZ_AST_FUNC_H
#define KIRAZ_AST_FUNC_H

#include <cassert>
#include <vector>

#include <kiraz/Node.h>
//FuncArgs[] ve NodeList[] ekle, bunlar argüman tokenlarını ve function scope elemanlarını tutsun
//FuncArgs args pointer'ından çiftleri alsın.
namespace ast {
class Func : public Node {
public: 
    explicit Func( const Node::Ptr &name, const Node::Ptr &args, const Node::Ptr &ret, const Node::Ptr &stmt) 
        : Node(KW_FUNC), nameC(name), argsC(args), retC(ret),stmtC(stmt){
            assert(name);
            assert(ret);
        };
 
    Node::Ptr get_name() const{return nameC;}
    Node::Ptr get_args() const{return argsC;}
    Node::Ptr get_ret() const{return retC;}
    Node::Ptr get_stmt() const{return stmtC;}

    std::string as_string() const override{

        return fmt::format("{}(n={}, a={}, r={}, s={})"
            ,"Func",get_name()->as_string(),get_args()->as_string(),get_ret()->as_string(),get_stmt()->as_string());
    }

    Node::Ptr compute_stmt_type(SymbolTable &st) override;
    Node::Ptr add_to_symtab_ordered(SymbolTable &st) override;
    //Call içinde forward usage

private:
    Node::Ptr nameC, argsC, retC, stmtC;
};

class StmtN : public Node{
public:
    explicit StmtN( const Node::Ptr &cur, const Node::Ptr &nextC) : Node(), current(cur), next(nextC){
        assert(cur);
        assert(nextC);
    }
    explicit StmtN() : Node(){}//empty function scope
    
    Node::Ptr get_current() const{return current;}
    Node::Ptr get_next()const{return next;}

    std::string as_string() const override{
        if(current != nullptr){
            return fmt::format("{}",current->as_string());
        }
        else{
            return fmt::format("");
        }
    }

    Node::Ptr compute_stmt_type(SymbolTable &st) override;
private:
    Node::Ptr current = nullptr, next = nullptr;

};

class StmtL : public Node{
public:
    explicit StmtL(const Node::Ptr &h);

    Node::Ptr get_head(){return head;};

    void fill_arguments();

    std::string as_string() const override {
        std::string output = "[";
        for (size_t i = 0; i < arguments.size(); ++i) {
            output += "" + arguments[i]->as_string();
            if (i < arguments.size() - 1  && i < arguments.size() - 2) {
                output += ", ";
                }
            }
            output += "]";
        return fmt::format("{}",output);
    }

    Node::Ptr compute_stmt_type(SymbolTable &st) override;
private:
    Node::Ptr head;
    std::vector<Node::Ptr> arguments;
};
}

#endif
