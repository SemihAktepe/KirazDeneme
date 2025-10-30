
#include "KwLet.h"


#include <kiraz/Compiler.h>

namespace ast{
    Node::Ptr KwLet::add_to_symtab_ordered(SymbolTable &st) {
    // Check if id1C is already declared
    auto id1 = std::static_pointer_cast<ast::Id>(std::const_pointer_cast<Node>(get_id1()));
    auto id1_name = id1->get_name();
    if (st.get_symbol(id1_name)) {
        return set_error(fmt::format("Identifier '{}' is already in symtab", id1_name));
    }
    if(id1_name.front() >= 'A' && id1_name.front() <= 'Z') {return set_error(fmt::format("Variable name '{}' can not start with an uppercase letter", id1_name));}

    // Handle cases based on id2C and mC
    if (!get_id2()) {
        // Case: let x = value;
        auto prob = get_valC()->compute_stmt_type(st);
        if(prob!=nullptr){
            return prob;
        }
        if(prob == nullptr){
            st.add_symbol(id1_name, get_id1());
            get_id1()->set_stmt_type(get_valC()->get_stmt_type());
            fmt::print("Added variable '{}' with explicit type '{}'\n", st.get_symbol(id1_name).name, st.get_symbol(id1_name).stmt->get_stmt_type()->as_string());
        }
    } 
    else if (mC == 1) {
        // Case: let x: Type;
        auto id2_name = get_id2()->as_string();
        auto id2_n = std::static_pointer_cast<ast::Id>(std::const_pointer_cast<Node>(get_id2()))->get_name();
        auto prob = get_id2()->compute_stmt_type(st);
        if ( prob != nullptr) {
            return set_error(fmt::format("Type '{}' doesn't exist", id2_name));
        }
        st.add_symbol(id1_name, get_id1());
        get_id1()->set_stmt_type(st.get_symbol(id2_n).stmt);
        fmt::print("Added variable '{}' with explicit type '{}'\n", st.get_symbol(id1_name).name, st.get_symbol(id1_name).stmt->get_stmt_type()->as_string());
            
        } 
    else {
        // Case: let x: Type = value;
        auto probVal = get_valC()->compute_stmt_type(st);
        auto probType = get_id2()->compute_stmt_type(st);
        if(probVal == nullptr && probType == nullptr){
            auto id2_type = std::static_pointer_cast<ast::Id>(std::const_pointer_cast<Node>(get_id2()->get_stmt_type()));
            auto value_type =std::static_pointer_cast<ast::Id>(std::const_pointer_cast<Node>(get_valC()->get_stmt_type()));// Compute the type of the value
            
            if (value_type != id2_type) {
                return set_error(fmt::format("Initializer type '{}' doesn't match explicit type '{}'", value_type->get_name(),id2_type->get_name()));
            }
            st.add_symbol(id1_name, get_id1());
            get_id1()->set_stmt_type(get_id2()->get_stmt_type());
        }
        else if(probVal != nullptr){
            return probVal;
        }
        else{
            return probType;
        }
    }

        return nullptr; // No errors
    }

    Node::Ptr KwLet::compute_stmt_type(SymbolTable &st) {
        set_cur_symtab(st.get_cur_symtab());
        auto prob = add_to_symtab_ordered(st);
        if(!prob){
            set_stmt_type(get_id1()->get_stmt_type());
        }
        return prob;
    }
}