
%option noyywrap

%{
// https://stackoverflow.com/questions/9611682/flexlexer-support-for-unicode/9617585#9617585
#include "parser.hpp"
#include "main.h"
#include <kiraz/token/Literal.h>
#include <kiraz/token/Operator.h>
#include <kiraz/token/Id.h>
#include <kiraz/token/KwLet.h>
#include <kiraz/token/Func.h>
#include <kiraz/token/KwImport.h>
#include <kiraz/token/KwIf.h>
#include <kiraz/token/KwElse.h>
#include <kiraz/token/KwClass.h>
#include <kiraz/token/KwWhile.h>
#include <kiraz/token/Return.h>
#include <algorithm>
#include <string>
static auto &colno = Token::colno;
using namespace token;
extern std::shared_ptr<Token> curtoken;

%}

%option yylineno

%%


\< {colno +=yyleng; curtoken = Token::New<OpLt>(); return OP_LT;}
\> {colno +=yyleng; curtoken = Token::New<OpGt>(); return OP_GT;}
\<= {colno +=yyleng; curtoken = Token::New<OpLtEqu>(); return OP_LTEQU;}
\>= {colno +=yyleng; curtoken = Token::New<OpGtEqu>(); return OP_GTEQU;}
let {colno +=yyleng; curtoken = Token::New<KwLet>(); return KW_LET;}
func {colno +=yyleng; curtoken = Token::New<Func>(); return KW_FUNC;}
import {colno +=yyleng; curtoken = Token::New<KwImport>(); return KW_IMPORT;}
if {colno +=yyleng; curtoken = Token::New<KwIf>(); return KW_IF;}
else {colno += yyleng; curtoken = Token::New<KwElse>(); return KW_ELSE;}
class { colno += yyleng; curtoken = Token::New<KwClass>(); return KW_CLASS; }
while { colno += yyleng; curtoken = Token::New<KwWhile>(); return KW_WHILE; }
return { colno += yyleng; curtoken = Token::New<KwReturn>(); return KW_RETURN; }

"==" {colno +=yyleng; curtoken = Token::New<OpEqual>(); return OP_EQUAL;}

[\+\+|\-\-][\+|\-]+ {colno+=yyleng; curtoken=Token::New<Rejected>(yytext); return YYUNDEF;}
\"(\\.|[^"\\])*\"  {colno += yyleng; curtoken = Token::New<Str>(yytext); return L_STRING;}



[0-9]+ {colno +=yyleng; curtoken = Token::New<Integer>(10,yytext); return L_INTEGER;}
[a-z|_|A-Z][a-z|_|A-Z|0-9]* {colno += yyleng; curtoken = Token::New<Id>(yytext); return ID;}
"=" {colno +=yyleng; curtoken = Token::New<OpAssign>(); return OP_ASSIGN;}

\. {colno +=yyleng;curtoken = Token::New<OpDot>(); return OP_DOT;}
\+ {colno +=yyleng; curtoken = Token::New<OpPlus>(); return OP_PLUS;}
\- {colno +=yyleng; curtoken = Token::New<OpMinus>(); return OP_MINUS;}
\* {colno +=yyleng; curtoken = Token::New<OpMult>(); return OP_MULT;}
\/ {colno +=yyleng; curtoken = Token::New<OpDivF>(); return OP_DIVF;}
\( {colno +=yyleng; curtoken = Token::New<OpLParen>(); return OP_LPAREN;}
\) {colno +=yyleng; curtoken = Token::New<OpRParen>(); return OP_RPAREN;}
\, {colno +=yyleng; curtoken = Token::New<OpComma>(); return OP_COMMA;}
\; {colno +=yyleng; curtoken = Token::New<OpSemCol>(); return OP_SEMCOL;}
\: {colno +=yyleng; curtoken = Token::New<OpColon>(); return OP_COLON;}
\{ {colno +=yyleng; curtoken = Token::New<OpLBrace>(); return OP_LBRACE;}
\} {colno +=yyleng; curtoken = Token::New<OpRBrace>(); return OP_RBRACE;}
\[ {colno +=yyleng;}
\] {colno +=yyleng;}

[ \n\t]+ {colno +=yyleng;}

. { printf("Token: %s, Text: %s\n", yytext, yytext); colno += yyleng; curtoken = Token::New<Rejected>(yytext); return YYUNDEF; }

