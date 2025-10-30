#include "KwClass.h"
#include "Id.h"
#include <kiraz/Compiler.h>
#include <set>




namespace ast{
    // Static utility function to check built-in types
        static bool is_builtin(const std::string &name) {
            static const std::set<std::string> builtins = {
                "Boolean", "Function", "Class", "Integer64", "Module", "String", "Void",
                "true", "false", "and", "or", "not"
            };
            return builtins.count(name) > 0;
        }

    Node::Ptr ClassDef::compute_stmt_type(SymbolTable &st) {
        set_cur_symtab(st.get_cur_symtab());

        auto class_name = std::dynamic_pointer_cast<ast::Id>(get_name())->get_name();
        if (st.get_symbol(class_name).stmt) {
            return set_error(fmt::format("Identifier '{}' is already in symtab", class_name));
        }

        if (!(class_name.front() >= 'A' && class_name.front() <= 'Z')) {
            return set_error(fmt::format("Class name '{}' can not start with an lowercase letter", class_name));
        }

        st.add_symbol(class_name, shared_from_this());
        shared_from_this()->set_stmt_type(st.get_symbol("Class").stmt);

         

        auto new_scope = st.enter_scope(ScopeType::Class, shared_from_this());
        
        auto prob = get_body()->compute_stmt_type(new_scope.symtab);
        m_cur_symtab = new_scope.symtab.get_cur_symtab();
        if (get_inherit()) {
            auto parent_name = std::dynamic_pointer_cast<ast::Id>(get_inherit())->get_name();
            fmt::print("Looking up parent '{}'\n", parent_name);

            auto parent_entry = st.get_symbol(parent_name);
            if (!parent_entry.stmt) {
                return set_error(fmt::format("Type '{}' is not found", parent_name));
            }

            // Ensure the parent entry's statement type is valid
            auto parent_stmt_type = parent_entry.stmt->get_stmt_type();
            if (!parent_stmt_type) {
                return set_error(fmt::format("Parent '{}' does not have a valid statement type", parent_name));
            }

            // Validate that the parent is a ClassDef
            auto parent_class = parent_entry.stmt;
            // Access the parent's symbol table
            auto parent_symtab = parent_class->get_cur_symtab();
            if (!parent_symtab) {
                return set_error(fmt::format("Parent class '{}' does not have a symbol table", parent_name));
            }

            // Check for redefinitions in the current class
            for (const auto &symbol : get_cur_symtab()->symbols) {
                if (parent_symtab->get_symbol(symbol.first)) {
                    if (!is_builtin(symbol.first) && parent_symtab->get_symbol(symbol.first).name != parent_name) {
                        return set_error(fmt::format(
                            "Identifier '{}' is already in symtab", 
                            symbol.first));
                    }
                }
            }
        }
        return prob;
    }


    
    Node::SymTabEntry ClassDef::get_subsymbol(Node::Ptr sym) const {
        fmt::print("Checking subsymbol '{}' in '{}'\n", sym->as_string(), get_class_name());
        auto curtab = get_cur_symtab();
        auto name_sym = std::dynamic_pointer_cast<ast::Id>(sym)->get_name();

        if (curtab && curtab->get_symbol(name_sym)) {
            fmt::print("Found symbol '{}' in current class '{}'\n", name_sym, get_class_name());
            return curtab->get_symbol(name_sym);
        }

        if (get_inherit()) {
            auto parent_name = std::dynamic_pointer_cast<const ast::Id>(get_inherit())->get_name();
            fmt::print("Looking up parent class '{}'\n", parent_name);

            auto parent_entry = curtab->get_symbol(parent_name);
            if (!parent_entry) {
                fmt::print("Parent class '{}' not found in symbol table\n", parent_name);
                return {};
            }
            if (!parent_entry.stmt->is_class()) {
                fmt::print("Parent '{}' is not a class\n", parent_name);
                return {};
            }

            auto parent_class = std::dynamic_pointer_cast<const ClassDef>(parent_entry.stmt);
            if (!parent_class) {
                fmt::print("Failed to cast '{}' to ClassDef\n", parent_name);
                return {};
            }

            return parent_class->get_subsymbol(sym);
        }

        fmt::print("Subsymbol '{}' not found\n", name_sym);
        return {};
    }



}