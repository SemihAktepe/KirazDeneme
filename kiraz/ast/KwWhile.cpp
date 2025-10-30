#include "KwWhile.h"
#include <kiraz/Compiler.h>

namespace ast {
    Node::Ptr While::compute_stmt_type(SymbolTable &st) {
        set_cur_symtab(st.get_cur_symtab());
        if(st.get_scope_type() != ScopeType::Func){
            return set_error(fmt::format("Misplaced while statement"));
        }
        auto prob = get_condition()->compute_stmt_type(st);
        auto con_type = get_condition()->get_stmt_type();
        if((con_type == st.get_symbol("true").stmt || con_type == st.get_symbol("false").stmt) || con_type == st.get_symbol("Boolean").stmt){
            return nullptr;
        }
        else{
            return set_error(fmt::format("While only accepts tests of type 'Boolean'"));
        }
    }
}