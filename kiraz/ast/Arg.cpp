#include "Arg.h"

#include <kiraz/Compiler.h>
namespace ast{
    Args::Args(const Node::Ptr &h) : Node(), head(h){
        assert(head);
        set_funcarg_list();
    }

    void Args::set_funcarg_list() {
        Node::Ptr current = get_head();
        while (current) {
            arguments.push_back(current);
            current = std::static_pointer_cast<Arg>(current)->get_next();
        }
    }
    Node::Ptr Args::compute_stmt_type(SymbolTable &st){
        set_cur_symtab(st.get_cur_symtab());
        Node::Ptr prob = nullptr;
        for(int i = 0; i < arguments.size(); i++){
            prob = arguments[i]->compute_stmt_type(st);
            if(prob) {
                prob = std::static_pointer_cast<ast::Arg>(std::const_pointer_cast<Node>(prob));
                if(prob->get_error() == "ArgName"){
                    for(int j = 0; j < i; j++){
                        if(arguments[j]->as_string() == prob->as_string()){
                            return prob;
                        }
                    }
                    return nullptr;
                }
                return prob;
            }
        }
        return prob;
    }

    Node::Ptr Arg::compute_stmt_type(SymbolTable &st){
        set_cur_symtab(st.get_cur_symtab());
        auto prob = add_to_symtab_ordered(st);
        return prob;
    }
    Node::Ptr Arg::add_to_symtab_ordered(SymbolTable &st) {
        Node::Ptr probType = nullptr;
        if(get_id1() != nullptr && get_id2() != nullptr ){
            auto name_type = std::static_pointer_cast<ast::Id>(std::const_pointer_cast<Node>(get_id1()));
            auto same = st.get_symbol(name_type->get_name()).stmt;
            if(same){
                if(same->is_class() || same->is_func()){
                    return set_error("ArgNameSameW_Class_or_Func");
                }
                
                return set_error("ArgName");
            }
            else{
                probType = get_id2()->compute_stmt_type(st);
                auto type_name = std::static_pointer_cast<ast::Id>(std::const_pointer_cast<Node>(get_id2()));
                if(probType){
                    return set_error("ArgType");
                }
            }
            get_id1()->set_stmt_type(get_id2());
            st.add_symbol(name_type->get_name(), get_id1());
            //fmt::println("...added {}... ",get_id1()->as_string());
        }
        return nullptr;
    }
}