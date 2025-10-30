
#include "Module.h"

#include <kiraz/Compiler.h>
namespace ast {
    ModuleL::ModuleL(const Node::Ptr &h) : Node(), head(h){
        assert(head);
        fill_arguments();
    }

    void ModuleL::fill_arguments() {
        Node::Ptr current = get_head();
        while (current) {
            arguments.push_back(current);
            current = std::static_pointer_cast<ModuleN>(current)->get_next();
        }
    }

    Node::Ptr ModuleL::compute_stmt_type(SymbolTable &st){
        set_cur_symtab(st.get_cur_symtab());
        Node::Ptr prob = nullptr;
        for(int i = 0; i < arguments.size(); i++){
            prob = arguments[i]->compute_stmt_type(st);
            if(prob != nullptr) {
                return prob;
            }
        }
        return nullptr;
    }

    Node::Ptr ModuleN::compute_stmt_type(SymbolTable &st){
        set_cur_symtab(st.get_cur_symtab());
        if(get_current() != nullptr){
            return get_current()->compute_stmt_type(st);
        }
        return nullptr;
    }


}