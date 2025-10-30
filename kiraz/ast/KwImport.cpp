#include "KwImport.h"
#include <kiraz/Compiler.h>

namespace ast{
    Node::Ptr Import::compute_stmt_type(SymbolTable &st){
        set_cur_symtab(st.get_cur_symtab());
        auto name = std::static_pointer_cast<ast::Id>(std::const_pointer_cast<Node>(get_module_name()));
        if(name->get_name() == "io"){
            st.add_symbol(name->get_name(), st.get_module_io());
            st.get_module_io()->set_stmt_type(st.get_symbol("Module").stmt);
        }
        return nullptr;
    }
}