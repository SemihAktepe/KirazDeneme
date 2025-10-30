
#ifndef KIRAZ_AST_MODULE_H
#define KIRAZ_AST_MODULE_H

#include <kiraz/Node.h>

#include <kiraz/ast/Operator.h>
#include <kiraz/ast/Literal.h>
#include <kiraz/ast/KwLet.h>
#include <kiraz/ast/KwImport.h>
#include <kiraz/ast/KwIfElse.h>
#include <kiraz/ast/KwClass.h>
#include <kiraz/ast/Id.h>
#include <kiraz/ast/KwWhile.h>
#include <kiraz/ast/Call.h>
#include <kiraz/ast/Return.h>
#include <kiraz/ast/Func.h>
#include <kiraz/ast/Arg.h>
#include <kiraz/ast/Module.h>

namespace ast {
class Module : public Node {
public:
    Module(Node::Ptr &h) : Node(), m_value(h){};

    std::string as_string() const override {
            return fmt::format("Module([{}])",m_value->as_string());
        }
    
private:
    Node::Ptr m_value;
};

class ModuleN : public Node{
public:
    explicit ModuleN( const Node::Ptr &cur, const Node::Ptr &nextC) : Node(), current(cur), next(nextC){
        assert(cur);
        assert(nextC);
    }
    explicit ModuleN() : Node(){}//empty function scope
    
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

class ModuleL : public Node{
public:
    explicit ModuleL(const Node::Ptr &h);

    Node::Ptr get_head(){return head;};

    void fill_arguments();

    std::string as_string() const override {
        std::string output = "Module([";
        for (size_t i = 0; i < arguments.size(); ++i) {
            output += "" + arguments[i]->as_string();
            if (i < arguments.size() - 1  && i < arguments.size() - 2) {
                output += ", ";
                }
            }
            output += "])";
        return fmt::format("{}",output);
    }
    
    virtual Ptr compute_stmt_type(SymbolTable &st) override;
private:
    Node::Ptr head;
    std::vector<Node::Ptr> arguments;
};

}

#endif
