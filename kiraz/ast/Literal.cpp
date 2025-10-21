
#include "Literal.h"
#include <cassert>
#include <kiraz/token/Literal.h>

#include <kiraz/Compiler.h>


namespace ast {
    Integer::Integer(Token::Ptr t) : Node(L_INTEGER){
        assert(t->get_id() == L_INTEGER);
        auto token_int = std::static_pointer_cast<const token::Integer>(t);
        base = token_int->get_base();
        try{
            m_value = std::stoll(std::string(token_int->get_value()),nullptr, base);
        }
        catch(std::out_of_range &e){
            //TO DO mark this node as invalid
        }
    }
    Str::Str(Token::Ptr t) : Node(L_STRING){
        assert(t->get_id() == L_STRING);
        auto token_str = std::static_pointer_cast<const token::Str>(t);
        str = token_str->get_value();
        str = get_new_st();

    }   

    Node::Ptr Integer::compute_stmt_type(SymbolTable &st){
        set_cur_symtab(st.get_cur_symtab());
        set_stmt_type(st.get_symbol("Integer64").stmt);
        
        return nullptr;
    }
    Node::Ptr Str::compute_stmt_type(SymbolTable &st){
        set_cur_symtab(st.get_cur_symtab());
        set_stmt_type(st.get_symbol("String").stmt);
        
        return nullptr;
    }
}
