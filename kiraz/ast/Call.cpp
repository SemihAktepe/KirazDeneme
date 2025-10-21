#include "Call.h"
#include <kiraz/Compiler.h>
namespace ast{
    CallL::CallL(const Node::Ptr &h) : Node(), head(h){
        assert(head);
        fill_arguments();
    }

    void CallL::fill_arguments() {
        Node::Ptr current = get_head();
        while (current) {
            arguments.push_back(current);
            current = std::static_pointer_cast<CallS>(current)->get_next();
        }
    }
    Node::Ptr Call::compute_stmt_type(SymbolTable &st){
        set_cur_symtab(st.get_cur_symtab());
        auto probName = get_nameL()->compute_stmt_type(st);
        if(probName != nullptr)return set_error(fmt::format("{}",probName->get_error()));
        set_stmt_type(get_nameL()->get_stmt_type());
        /*
        
        printf("Call args Compute\n");
        auto probArgs = get_args()->compute_stmt_type(st);
        printf("Call args Computed\n");
        if(probArgs != nullptr)return set_error(fmt::format("{}",probArgs->get_error()));*/
        return nullptr;
    }
}