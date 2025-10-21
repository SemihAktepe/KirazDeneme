#include "Return.h"
#include <kiraz/Compiler.h>

namespace ast{
    Node::Ptr Return::compute_stmt_type(SymbolTable &st){
        set_cur_symtab(st.get_cur_symtab());
        auto cur_scope = st.get_scope_type();
        if(cur_scope != ScopeType::Func){
            return set_error(fmt::format("Misplaced return statement"));
        }
        else{
            auto prob = get_retN()->compute_stmt_type(st);
            auto func_stmt = std::static_pointer_cast<ast::Func>(std::const_pointer_cast<Node>(st.get_scope_stmt()));
            auto nameF_R = std::static_pointer_cast<ast::Id>(std::const_pointer_cast<Node>(func_stmt->get_ret()->get_stmt_type()));
            auto nameR_N = std::static_pointer_cast<ast::Id>(std::const_pointer_cast<Node>(get_retN()->get_stmt_type()));
            if( nameF_R->get_name() != nameR_N->get_name()){
                if((nameR_N->get_name() == "true" || nameR_N->get_name() == "false") && nameF_R->get_name() == "Boolean"){ return nullptr;}
                return set_error(fmt::format("Return statement type '{}' does not match function return type '{}'", nameR_N->get_name(), nameF_R->get_name()));
            }
        }
        return nullptr;
    }
}