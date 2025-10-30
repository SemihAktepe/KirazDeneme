
#include "Func.h"
#include <kiraz/Compiler.h>
#include "Id.h"
#include "Arg.h"
#include <fmt/format.h>

namespace ast {
    Node::Ptr Func::compute_stmt_type(SymbolTable &st){
        set_cur_symtab(st.get_cur_symtab());
        auto prob = add_to_symtab_ordered(st);
        return prob;
    }
    Node::Ptr Func::add_to_symtab_ordered(SymbolTable &st){
        auto idName = std::static_pointer_cast<ast::Id>(std::const_pointer_cast<Node>(get_name()));
        auto name = idName->get_name();
        if(st.get_symbol(name).stmt){
            return set_error(fmt::format("Identifier '{}' is already in symtab", name));
            }
        //func f(args) : Ret {}
        //add the name symbol if return type is valid and the name hasn't been used
        auto prob = get_ret()->compute_stmt_type(st);
        if(prob == nullptr){
            st.add_symbol(name,shared_from_this());
            shared_from_this()->set_stmt_type(st.get_symbol("Function").stmt);
            //arg'ları koy!!!!!
            prob = get_args()->compute_stmt_type(st);
            if(!prob){
                //enter function scope
                auto new_scope = st.enter_scope(ScopeType::Func, shared_from_this());
                prob = get_stmt()->compute_stmt_type(new_scope.symtab);
                }
            else{
                auto prob_w_args = std::static_pointer_cast<ast::Arg>(std::const_pointer_cast<Node>(prob));
                if(prob_w_args->get_error() == "ArgName"){
                    return set_error(fmt::format("Identifier '{}' in argument list of function '{}' is already in symtab",prob_w_args->as_name_id1(),name));
                    }
                else if(prob_w_args->get_error() == "ArgNameSameW_Class_or_Func"){
                    return set_error(fmt::format("Identifier '{}' in argument list of function '{}' is already in symtab",prob_w_args->as_name_id1(),name));
                }
                else{
                    return set_error(fmt::format("Identifier '{}' in type of argument '{}' in function '{}' is not found",prob_w_args->as_name_id2(),prob_w_args->as_name_id1(),name));
                    }
                }
            }
        else{
            auto name_type = std::static_pointer_cast<ast::Id>(std::const_pointer_cast<Node>(get_name()));
            auto ret_type =std::static_pointer_cast<ast::Id>(std::const_pointer_cast<Node>(get_ret()));
            return set_error(fmt::format("Return type '{}' of function '{}' is not found",ret_type->get_name(), name_type->get_name()));
        }
        return prob;
    }

    StmtL::StmtL(const Node::Ptr &h) :Node(), head(h){
        assert(head);
        fill_arguments();
    }

    void StmtL::fill_arguments() {
        Node::Ptr current = get_head();
        while (current) {
            arguments.push_back(current);
            current = std::static_pointer_cast<StmtN>(current)->get_next();
        }
    }
    Node::Ptr StmtL::compute_stmt_type(SymbolTable &st){
        set_cur_symtab(st.get_cur_symtab());
        Node::Ptr prob = nullptr;
        for(int i = 0; i < arguments.size(); i++){
            prob = arguments[i]->compute_stmt_type(st);
            if(prob != nullptr) {
                return prob;
            }
        }
        return prob;
    }

    Node::Ptr StmtN::compute_stmt_type(SymbolTable &st){
        set_cur_symtab(st.get_cur_symtab());
        if(get_current() != nullptr){
            auto prob = get_current()->compute_stmt_type(st);
            return prob;
        }
        return nullptr;
    }
}