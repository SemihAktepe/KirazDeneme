
#include "Operator.h"
#include <set>
#include <kiraz/Compiler.h>
//#include <Id.h>
#include "Operator.h"
#include "Id.h"
#include "KwClass.h"

namespace ast{
    static bool is_builtin(const std::string &name) {
            static const std::set<std::string> builtins = {
                "Boolean", "Function", "Class", "Integer64", "Module", "String", "Void",
                "true", "false", "and", "or", "not"
            };
            return builtins.count(name) > 0;
        }

    Node::Ptr OpAdd::compute_stmt_type(SymbolTable &st){
        set_cur_symtab(st.get_cur_symtab());
        auto probLeft = get_left()->compute_stmt_type(st);
        auto probRight = get_right()->compute_stmt_type(st);
        if(probLeft == nullptr && probRight == nullptr){
            auto left = std::static_pointer_cast<ast::Id>(std::const_pointer_cast<Node>(get_left()->get_stmt_type()));
            auto right = std::static_pointer_cast<ast::Id>(std::const_pointer_cast<Node>(get_right()->get_stmt_type()));
            if(left != right){
                return set_error(fmt::format("Operator '+' not defined for types '{}' and '{}'",left->get_name(),right->get_name()));
            }
            set_stmt_type(left);
        }
        else if(probLeft){
            return probLeft;
        }
        else{
            return probRight;
        }
        return nullptr;
    }
    Node::Ptr OpAssign::compute_stmt_type(SymbolTable &st) {
        set_cur_symtab(st.get_cur_symtab());

        // Compute the types for left and right sides
        auto probLeft = get_left()->compute_stmt_type(st);
        auto probRight = get_right()->compute_stmt_type(st);

        if (!probLeft && !probRight) {
            auto left_stmt_type = get_left()->get_stmt_type();
            auto right_stmt_type = get_right()->get_stmt_type();

            if (!left_stmt_type || !right_stmt_type) {
                return set_error("Invalid types for assignment");
            }
            
            if (auto opDot = std::dynamic_pointer_cast<ast::OpDot>(get_left())) {
                fmt::print("Resolving type for 'OpDot': '{}'\n", opDot->as_string());

                // Resolve the subsymbol in the left-hand side class
                auto dot_target = opDot->get_stmt_type();
                if (!dot_target) {
                    return set_error("Left-hand side of 'OpDot' has no type");
                }

                // Use const dynamic_pointer_cast to preserve constness
                auto field_class = std::dynamic_pointer_cast<const ast::ClassDef>(dot_target);
                if (!field_class) {
                    return set_error(fmt::format("'OpDot' does not reference a valid class: '{}'", dot_target->as_string()));
                }

                // Ensure the field exists in the class
                auto field_symbol = field_class->get_subsymbol(opDot->get_right());
                if (!field_symbol.stmt) {
                    return set_error(fmt::format("Field '{}' does not exist in '{}'",
                                                opDot->get_right()->as_string(), field_class->get_class_name()));
                }

                // Validate field type against right-hand side
                auto field_type = field_symbol.stmt->get_stmt_type();
                if (field_type != right_stmt_type) {
                    return set_error(fmt::format("Field '{}' expects type '{}' but got type '{}'",
                                                opDot->get_right()->as_string(),
                                                field_type->as_string(),
                                                right_stmt_type->as_string()));
                }

                // Set the type of this assignment
                set_stmt_type(field_type);
                return nullptr;
            }


            auto letf_n = std::dynamic_pointer_cast<const ast::Id>(get_left());
            if(letf_n && (is_builtin(letf_n->get_name()) ) ){
                return set_error(fmt::format("Overriding builtin '{}' is not allowed", letf_n->get_name()));
            }

            auto left_class = std::dynamic_pointer_cast<const ast::ClassDef>(left_stmt_type);
            auto right_class = std::dynamic_pointer_cast<const ast::ClassDef>(right_stmt_type);

            if (left_class && right_class) {
                auto current_class = right_class;
                while (current_class) {
                    if (current_class == left_class) {
                        set_stmt_type(left_stmt_type);
                        return nullptr;
                    }
                    current_class = current_class->get_inherit()
                        ? std::const_pointer_cast<ast::ClassDef>(
                            std::dynamic_pointer_cast<const ast::ClassDef>(
                                current_class->get_inherit()->get_stmt_type()))
                        : nullptr;
                }
            }

            auto left_name = std::dynamic_pointer_cast<const ast::Id>(left_stmt_type);
            auto right_name = std::dynamic_pointer_cast<const ast::Id>(right_stmt_type);
            if(left_name->get_name() != right_name->get_name()){
            return set_error(fmt::format(
                "Left type '{}' of assignment does not match the right type '{}'",
                left_name ? left_name->get_name() : "unknown",
                right_name ? right_name->get_name() : "unknown"));
            }
        }

        return probLeft ? probLeft : probRight;
    }



    Node::Ptr OpEqual::compute_stmt_type(SymbolTable &st){
        set_cur_symtab(st.get_cur_symtab());
        set_stmt_type(st.get_symbol("Boolean").stmt);
        return nullptr;
    }
    Node::Ptr OpGt::compute_stmt_type(SymbolTable &st){
        set_cur_symtab(st.get_cur_symtab());
        set_stmt_type(st.get_symbol("Boolean").stmt);
        return nullptr;
    }
    Node::Ptr OpLt::compute_stmt_type(SymbolTable &st){
        set_cur_symtab(st.get_cur_symtab());
        set_stmt_type(st.get_symbol("Boolean").stmt);
        return nullptr;
    }
    Node::Ptr OpGtEqu::compute_stmt_type(SymbolTable &st){
        set_cur_symtab(st.get_cur_symtab());
        set_stmt_type(st.get_symbol("Boolean").stmt);
        return nullptr;
    }
    Node::Ptr OpLtEqu::compute_stmt_type(SymbolTable &st){
        set_cur_symtab(st.get_cur_symtab());
        set_stmt_type(st.get_symbol("Boolean").stmt);
        return nullptr;
    }


    Node::Ptr OpDot::compute_stmt_type(SymbolTable &st) {
        set_cur_symtab(st.get_cur_symtab());
        fmt::print("Resolving left-hand side '{}'\n", get_left()->as_string());

        auto probLeft = get_left()->compute_stmt_type(st);
        if (probLeft) {
            return set_error(fmt::format("{}", probLeft->get_error()));
        }

        if (!get_left()->get_stmt_type()) {
            return set_error("Left-hand side has no type");
        }

        auto parent_class = std::dynamic_pointer_cast<const ast::ClassDef>(get_left()->get_stmt_type());
        if (!parent_class) {
            return set_error(fmt::format(
                "Cannot resolve parent class for '{}'",
                get_left()->as_string()));
        }

        auto subsymbol = parent_class->get_subsymbol(get_right());
        if (!subsymbol.stmt) {
            return set_error(fmt::format(
                "Identifier '{}.{}' is not found",
                std::dynamic_pointer_cast<ast::Id>(get_left())->get_name(), std::dynamic_pointer_cast<ast::Id>(get_right())->get_name()));
        }

        set_stmt_type(subsymbol.stmt->get_stmt_type());
        return nullptr;
    }


    

}