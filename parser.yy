
/*
%union defines a different return types of our parser
%start defines the starting rule

muhtemelen assign ve declare yerleri değiştirmeliyim, 
declare içinde assign kullanmalıyım ki direk initilization'da type ID'si
alabileyim.


*/

%{
#include "main.h"
#include "lexer.hpp"

#include <kiraz/ast/Operator.h>
#include <kiraz/ast/Literal.h>


#include <kiraz/token/Operator.h>
#include <kiraz/token/Literal.h>

int yyerror(const char *msg);
extern std::shared_ptr<Token> curtoken;
extern int yylineno;
%}

%token OP_LPAREN
%token OP_RPAREN
%token OP_PLUS
%token OP_MINUS
%token OP_DIVF
%token OP_MULT
%token OP_DOT
%token OP_COLON
%token OP_COMMA
%token OP_SEMCOL
%token OP_ASSIGN
%token OP_LBRACE
%token OP_RBRACE
%token OP_EQUAL
%token OP_GT
%token OP_LT
%token OP_GTEQU
%token OP_LTEQU

%token KW_LET
%token KW_FUNC
%token KW_IMPORT
%token KW_IF
%token KW_ELSE
%token KW_CLASS
%token KW_WHILE
%token KW_RETURN

%token L_STRING
%token ID

%token L_INTEGER 
%token REJECTED

%left OP_PLUS OP_MINUS
%left OP_MULT OP_DIVF
%left OP_COLON


%start module

%%
module:
     { yyerror("Expected a statement"); }
    |module_stmt {$$ = Node::add<ast::ModuleL>($1);}
    ;
module_stmt:
    stmt module_stmt {$$ = Node::add<ast::ModuleN>($1, $2);}
    | {$$ = Node::add<ast::ModuleN>();}

stmt:                  
    func OP_SEMCOL {$$ = $1;}
    |import_stmt OP_SEMCOL {$$ = $1;}
    |if_stmt OP_SEMCOL {$$ = $1;}
    |class_stmt OP_SEMCOL {$$ = $1;}
    |while_stmt OP_SEMCOL {$$ = $1;}
    |declare OP_SEMCOL {$$ = $1;}
    |return_stmt OP_SEMCOL {$$ = $1;}
    |reg_stmt OP_SEMCOL{$$ = $1;}
    ;

reg_stmt:
     tf {$$ = $1;}
    | assign {$$ = $1;}
    | call_stmt {$$ = $1;}
    | addsub {$$ = $1;}
    
;
call_stmt:
    type  dec_call_args  {$$ = Node::add<ast::Call>($1, $2);}
    |call_name  dec_call_args  {$$ = Node::add<ast::Call>($1, $2);}
    | call_name OP_LPAREN OP_RPAREN {$$ = Node::add<ast::Call>($1, nullptr);}
    | call_name {$$ = Node::add<ast::Call>($1, nullptr);}
;

call_name:
    type OP_DOT type {$$ = Node::add<ast::OpDot>($1, $3);}
    | call_name OP_DOT type {$$ = Node::add<ast::OpDot>($1, $3);}
;

dec_call_args:
    OP_LPAREN call_args OP_RPAREN {$$ = Node::add<ast::CallL>($2);}
    ;

call_args:
    reg_stmt OP_COMMA call_args {
        auto first_arg = Node::add<ast::CallS>($1);
        if (!first_arg || !$3) {
            yyerror("Invalid CallS chain in call_args");
            YYABORT;
        }
        auto next_args = std::dynamic_pointer_cast<ast::CallS>($3);
        first_arg->next = next_args;
        $$ = first_arg; }
    |reg_stmt {$$ = Node::add<ast::CallS>($1);}
    |{$$ = Node::add<ast::CallS>();}
;

return_stmt:
    KW_RETURN return_value { $$ = Node::add<ast::Return>($2); }
    ;

return_value:
    addsub { $$ = $1; }
    | call_stmt {$$ = $1;}
    | tf { $$ = $1; }
    ;

tf:
    addsub OP_EQUAL addsub {$$ = Node::add<ast::OpEqual>($1, $3);}
    |addsub OP_GT addsub {$$ = Node::add<ast::OpGt>($1, $3);}
    |addsub OP_LT addsub {$$ = Node::add<ast::OpLt>($1, $3);}
    |addsub OP_GTEQU addsub {$$ = Node::add<ast::OpGtEqu>($1, $3);}
    |addsub OP_LTEQU addsub {$$ = Node::add<ast::OpLtEqu>($1, $3);}
    ;
    

func:
    KW_FUNC type declare_arg return_type stmt_list { $$ = Node::add<ast::Func>($2, $3, $4, $5); }
    ;
declare_arg:
    OP_LPAREN arg_list OP_RPAREN { $$ = Node::add<ast::Args>($2); }
    ;
arg_list:
    arg { $$ = $1; }
    |arg OP_COMMA arg_list{ 
        auto first_arg = std::dynamic_pointer_cast<ast::Arg>($1);
        first_arg->next = $3;
        $$ = first_arg; 
    }
    | { $$ = Node::add<ast::Arg>(); }
    ;
arg:
    type OP_COLON type { $$ = Node::add<ast::Arg>($1, $3); }
    ;
type:
    ID { $$ = Node::add<ast::Id>(curtoken); }
    ;
return_type:
    OP_COLON type { $$ = $2; }
    | { $$ = Node::add<ast::Arg>(); } 
    ;
stmt_list:
    OP_LBRACE stmt_list  {$$ = Node::add<ast::StmtL>($2);}
    |stmt stmt_list {$$ = Node::add<ast::StmtN>($1,$2);}
    |OP_RBRACE {$$ = Node::add<ast::StmtN>();}
    ;

assign:
    type OP_ASSIGN reg_stmt { $$ = Node::add<ast::OpAssign>($1, $3); }
    |call_stmt OP_ASSIGN reg_stmt { $$ = Node::add<ast::OpAssign>($1, $3); }
    ;

addsub:
    addsub OP_PLUS muldiv { $$ = Node::add<ast::OpAdd>($1, $3); }
    | addsub OP_MINUS muldiv { $$ = Node::add<ast::OpSub>($1, $3); }
    | muldiv { $$ = $1; }
    
    ;

muldiv:
    muldiv OP_MULT posneg { $$ = Node::add<ast::OpMult>($1, $3); }
    |muldiv OP_DIVF posneg { $$ = Node::add<ast::OpDivF>($1, $3); }
    |posneg { $$ = $1; }
    ;

posneg:
    type {$$ = $1; }
    | L_STRING { $$ = Node::add<ast::Str>(curtoken); }
    | L_INTEGER { $$ = Node::add<ast::Integer>(curtoken); }
    | OP_PLUS posneg { $$ = Node::add<ast::SignedNode>(OP_PLUS, $2); }
    | OP_MINUS posneg { $$ = Node::add<ast::SignedNode>(OP_MINUS, $2); }
    | OP_LPAREN addsub OP_RPAREN { $$ = $2; }
    ;
    



import_stmt:
    KW_IMPORT import_stmt {$$ = Node::add<ast::Import>($2);  }
    |type {$$ =$1;}
    ;
if_stmt:
    matched_if {$$=$1;}
    |open_if  {$$=$1;}

matched_if:
    KW_IF OP_LPAREN reg_stmt OP_RPAREN stmt_list KW_ELSE stmt_list { $$ = Node::add<ast::IfElse>($3, $5, $7); }
    | KW_IF OP_LPAREN reg_stmt OP_RPAREN stmt_list { $$ = Node::add<ast::IfElse>($3, $5); }
    ;

open_if:
    KW_IF OP_LPAREN reg_stmt OP_RPAREN if_stmt { $$ = Node::add<ast::IfElse>($3, $5); }
    | KW_IF OP_LPAREN reg_stmt OP_RPAREN open_if { $$ = Node::add<ast::IfElse>($3, $5); }
    ;

class_stmt:
    KW_CLASS type inherit_type stmt_list {$$ = Node::add<ast::ClassDef>($2, $3, $4);}
    ;

inherit_type:
    OP_COLON type {$$ = $2;}
    |
    ;

while_stmt:
    KW_WHILE OP_LPAREN reg_stmt OP_RPAREN stmt_list  {$$ = Node::add<ast::While>($3, $5);}
    ;

assign_let: 
    OP_ASSIGN reg_stmt {$$ = $2;}
    ;

declare: 
    KW_LET declare declare {$$ = Node::add<ast::KwLet>(KW_LET,$2,$3,1);}
    |KW_LET declare assign_let {$$ = Node::add<ast::KwLet>(KW_LET,$2,$3);}
    |KW_LET declare declare assign_let {$$ = Node::add<ast::KwLet>(KW_LET,$2,$3,$4);}
    |OP_COLON declare {$$ = $2;}
    |type {$$ = $1;}
    ;


%%

int yyerror(const char *s) {
    if (curtoken) {
        fmt::print("** Parser Error at {}:{} at token: {}\n",
            yylineno, Token::colno, curtoken->as_string());
    }
    else {
        fmt::print("** Parser Error at {}:{}, null token\n",
            yylineno, Token::colno);
    }

    Token::colno = 0;
    Node::reset_root();

    return 1;
}
