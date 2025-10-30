#include "Compiler.h"
#include <cassert>
#include <cstring>
#include <fmt/format.h>
#include <resource/FILE_io_ki.h>

// v1’in sembol başlangıçları için AST başlıkları:
#include <kiraz/ast/Operator.h>
#include <kiraz/ast/Literal.h>
#include <kiraz/ast/KwLet.h>
#include <kiraz/ast/KwImport.h>
#include <kiraz/ast/KwIfElse.h>
#include <kiraz/ast/KwClass.h>
#include <kiraz/ast/Id.h>
#include <kiraz/ast/KwWhile.h>
#include <kiraz/ast/Call.h>
#include <kiraz/ast/Return.h>
#include <kiraz/ast/Func.h>
#include <kiraz/ast/Arg.h>
#include <kiraz/ast/Module.h>

Node::Ptr SymbolTable::s_module_ki;
Node::Ptr SymbolTable::s_module_io;

SymbolTable::~SymbolTable() {}

Compiler *Compiler::s_current;

extern Token::Ptr curtoken;

Compiler::Compiler() {
    assert(! s_current);
    s_current = this;
    Node::reset_root();
}

Compiler::~Compiler() {
    if (buffer) {
        yy_delete_buffer(buffer);
        buffer = nullptr;
    }
    reset_parser();
    s_current = nullptr;
}

int Compiler::compile_file(const std::string &file_name) {
    yyin = fopen(file_name.data(), "rb");
    if (! yyin) {
        perror(file_name.data());
        return 2;
    }

    yyparse();
    auto root = Node::get_root();
    reset();

    return compile(root);
}

int Compiler::compile_string(const std::string &code) {
    buffer = yy_scan_string(code.data());
    yyparse();
    auto root = Node::get_root();
    reset();

    return compile(root);
}

Node::Ptr Compiler::compile_module(const std::string &str) {
    buffer = yy_scan_string(str.data());
    yyparse();
    auto retval = Node::pop_root();
    reset();
    assert(retval);
    return retval;
}

void Compiler::reset_parser() {
    curtoken.reset();
    Node::reset_root();
    Token::colno = 0;
    yylex_destroy();
}

void Compiler::reset() {
    if (buffer) {
        yy_delete_buffer(buffer);
        buffer = nullptr;
    }
    reset_parser();
}

int Compiler::compile(Node::Ptr root) {
    if (! root) {
        return 1;
    }

    SymbolTable st(ScopeType::Module);

    if (auto ret = root->compute_stmt_type(st)) {
        set_error(fmt::format("Error at {}:{}: {}\n",
                              ret->get_line(),
                              ret->get_col(),
                              ret->get_error()));
        Node::reset_root();
        return 1;
    }

    // v1 sisteminde WAT üretimi yok → devre dışı bırakıldı
    /*
    if (auto ret = root->gen_wat(m_ctx)) {
        return 2;
    }
    */

    return 0;
}

SymbolTable::SymbolTable()
    : m_symbols({
          std::make_shared<Scope>(
              Scope::SymTab{
                  {"Boolean", std::make_shared<ast::Id>("Boolean")},
                  {"Function", std::make_shared<ast::Id>("Function")},
                  {"Class", std::make_shared<ast::Id>("Class")},
                  {"Integer64", std::make_shared<ast::Id>("Integer64")},
                  {"Module", std::make_shared<ast::Id>("Module")},
                  {"String", std::make_shared<ast::Id>("String")},
                  {"Void", std::make_shared<ast::Id>("Void")},

                  {"true", std::make_shared<ast::Id>("true")},
                  {"false", std::make_shared<ast::Id>("false")},

                  {"and",
                   std::make_shared<ast::Func>(
                       std::make_shared<ast::Id>("and"),
                       std::make_shared<ast::Args>(
                           std::make_shared<ast::Arg>(
                               std::make_shared<ast::Id>("l"),
                               std::make_shared<ast::Id>("Boolean"),
                               std::make_shared<ast::Arg>(
                                   std::make_shared<ast::Id>("r"),
                                   std::make_shared<ast::Id>("Boolean"),
                                   nullptr))),
                       std::make_shared<ast::Id>("Boolean"),
                       nullptr)},
                  {"or",
                   std::make_shared<ast::Func>(
                       std::make_shared<ast::Id>("or"),
                       std::make_shared<ast::Args>(
                           std::make_shared<ast::Arg>(
                               std::make_shared<ast::Id>("l"),
                               std::make_shared<ast::Id>("Boolean"),
                               std::make_shared<ast::Arg>(
                                   std::make_shared<ast::Id>("r"),
                                   std::make_shared<ast::Id>("Boolean"),
                                   nullptr))),
                       std::make_shared<ast::Id>("Boolean"),
                       nullptr)},
                  {"not",
                   std::make_shared<ast::Func>(
                       std::make_shared<ast::Id>("not"),
                       std::make_shared<ast::Args>(
                           std::make_shared<ast::Arg>(
                               std::make_shared<ast::Id>("l"),
                               std::make_shared<ast::Id>("Boolean"),
                               std::make_shared<ast::Arg>(
                                   std::make_shared<ast::Id>("r"),
                                   std::make_shared<ast::Id>("Boolean"),
                                   nullptr))),
                       std::make_shared<ast::Id>("Boolean"),
                       nullptr)}},
              ScopeType::Module, nullptr),
      }) {
    if (! s_module_io) {
        s_module_io = Compiler::current()->compile_module(FILE_io_ki);
    }
}

SymbolTable::SymbolTable(ScopeType scope_type) : SymbolTable() {
    m_symbols.back()->scope_type = scope_type;
}
