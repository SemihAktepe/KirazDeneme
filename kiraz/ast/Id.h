#pragma once
#ifndef KIRAZ_AST_ID_H
#define KIRAZ_AST_ID_H

#include <kiraz/Node.h>
#include <map>
namespace ast {
class Id : public Node {
public:
    Id(Token::Ptr);
    Id(std::string name);

    std::string as_string() const override {return fmt::format("Id({})",m_value);}
    std::string get_name() {return m_value;}
    std::string get_name() const { return m_value; }

    Node::Ptr compute_stmt_type(SymbolTable &st) override;

    std::map<std::string, int> builtIns ={
        {"Boolean",0},
        {"Function",0},
        {"Class",0},
        {"Integer64",0},
        {"Module",0},
        {"String",0},
        {"Void",0},
        {"true",0},
        {"false",0},
        {"and",0},
        {"or",0},
        {"not",0}
    };

private:
    std::string m_value;
};

}

#endif
