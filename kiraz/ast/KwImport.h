#ifndef KIRAZ_AST_IMPORT_H
#define KIRAZ_AST_IMPORT_H

#include <kiraz/Node.h>
#include <string>

namespace ast {
class Import : public Node {
public:
    explicit Import(Node::Ptr &moduleName)
        : Node(), moduleNameC(moduleName) {}

    Node::Ptr get_module_name() const { return moduleNameC; }

    std::string as_string() const override {
        return fmt::format("Import({})", get_module_name()->as_string());
    }
    Node::Ptr compute_stmt_type(SymbolTable &st) override;
private:
    Node::Ptr moduleNameC;
};
}
#endif
