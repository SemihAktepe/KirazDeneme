#ifndef KIRAZ_AST_CLASSDEF_H
#define KIRAZ_AST_CLASSDEF_H

#include <kiraz/Node.h>
#include <string>

namespace ast {

class ClassDef : public Node {
public:

    explicit ClassDef(const Node::Ptr& className, const Node::Ptr inheritance, const Node::Ptr& body)
        : Node(KW_CLASS), classNameC(className), inheritParent(inheritance), bodyC(body) {
        assert(className);
    }
    
    std::string get_class_name() const { return classNameC->as_string(); }
    Node::Ptr get_body() const { return bodyC; }
    Node::Ptr get_name() const { return classNameC; }
    Node::Ptr get_inherit() const { return inheritParent; }
    std::string as_string() const override {
        return fmt::format("Class(n={}, s={})", get_class_name(), bodyC->as_string());
    }
    Node::Ptr compute_stmt_type(SymbolTable &st) override;
    Node::SymTabEntry get_subsymbol(Node::Ptr sym) const override;
private:
    const Node::Ptr classNameC = nullptr;
    Node::Ptr inheritParent = nullptr;
    Node::Ptr bodyC = nullptr;
};
    

} 

#endif // KIRAZ_AST_CLASSDEF_H
