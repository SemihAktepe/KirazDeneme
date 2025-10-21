#include <kiraz/Compiler.h>
#include "Id.h"
#include <cassert>
#include <kiraz/token/Id.h>



namespace ast {
    Id::Id(Token::Ptr t) : Node(ID){
        assert(t->get_id() == ID);
        auto token_id = std::static_pointer_cast<const token::Id>(t);
        
        m_value = token_id->get_value();
        
    }
    Id::Id(std::string name) : Node(ID){
        m_value = name;
        
    }
    Node::Ptr Id::compute_stmt_type(SymbolTable &st){
        set_cur_symtab(st.get_cur_symtab());
        if(!st.get_symbol(get_name()).stmt){
            return set_error(fmt::format("Identifier '{}' is not found",get_name()));
        }
        else{
            auto is_built = Id::builtIns.find(get_name());
            if(is_built == builtIns.end()){
                set_stmt_type(st.get_symbol(get_name()).stmt->get_stmt_type());
                
            }else{
                if(get_name() == "and" || get_name() == "or" || get_name() == "not"){
                    set_stmt_type(st.get_symbol("Boolean").stmt);
                }
                else{
                    set_stmt_type(st.get_symbol(get_name()).stmt);
                }
            }
        }
        return nullptr;
    }

}
