#include "KwIfElse.h"
#include <kiraz/Compiler.h>

namespace ast{
    Node::Ptr IfElse::compute_stmt_type(SymbolTable &st){
        set_cur_symtab(st.get_cur_symtab());
        if(st.get_scope_type() != ScopeType::Func){
            return set_error(fmt::format("Misplaced if statement"));
        }
        auto prob = get_condition()->compute_stmt_type(st);
        if(prob) return prob;

        auto con_type = get_condition()->get_stmt_type();
        if((con_type == st.get_symbol("true").stmt || con_type == st.get_symbol("false").stmt) || con_type == st.get_symbol("Boolean").stmt){

        }
        else if(con_type == st.get_symbol("Function").stmt){
                con_type = std::static_pointer_cast<ast::Func>(std::const_pointer_cast<Node>(con_type));
            }
        else{
            return set_error(fmt::format("If only accepts tests of type 'Boolean'"));
        }

        if(!get_else_block()){
            prob = get_if_block()->compute_stmt_type(st);
        }
        else{
            prob = get_if_block()->compute_stmt_type(st);
            prob = get_else_block()->compute_stmt_type(st);
        }
        return prob;
    }
}