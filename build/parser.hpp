/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_HOME_SEMIH_MASA_ST_KIRAZ_COMPILER3_KIRAZ_COMPILER_MAINCOMPILER_3_BUILD_PARSER_HPP_INCLUDED
# define YY_YY_HOME_SEMIH_MASA_ST_KIRAZ_COMPILER3_KIRAZ_COMPILER_MAINCOMPILER_3_BUILD_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    OP_LPAREN = 258,               /* OP_LPAREN  */
    OP_RPAREN = 259,               /* OP_RPAREN  */
    OP_PLUS = 260,                 /* OP_PLUS  */
    OP_MINUS = 261,                /* OP_MINUS  */
    OP_DIVF = 262,                 /* OP_DIVF  */
    OP_MULT = 263,                 /* OP_MULT  */
    OP_DOT = 264,                  /* OP_DOT  */
    OP_COLON = 265,                /* OP_COLON  */
    OP_COMMA = 266,                /* OP_COMMA  */
    OP_SEMCOL = 267,               /* OP_SEMCOL  */
    OP_ASSIGN = 268,               /* OP_ASSIGN  */
    OP_LBRACE = 269,               /* OP_LBRACE  */
    OP_RBRACE = 270,               /* OP_RBRACE  */
    OP_EQUAL = 271,                /* OP_EQUAL  */
    OP_GT = 272,                   /* OP_GT  */
    OP_LT = 273,                   /* OP_LT  */
    OP_GTEQU = 274,                /* OP_GTEQU  */
    OP_LTEQU = 275,                /* OP_LTEQU  */
    KW_LET = 276,                  /* KW_LET  */
    KW_FUNC = 277,                 /* KW_FUNC  */
    KW_IMPORT = 278,               /* KW_IMPORT  */
    KW_IF = 279,                   /* KW_IF  */
    KW_ELSE = 280,                 /* KW_ELSE  */
    KW_CLASS = 281,                /* KW_CLASS  */
    KW_WHILE = 282,                /* KW_WHILE  */
    KW_RETURN = 283,               /* KW_RETURN  */
    L_STRING = 284,                /* L_STRING  */
    ID = 285,                      /* ID  */
    L_INTEGER = 286,               /* L_INTEGER  */
    REJECTED = 287                 /* REJECTED  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_HOME_SEMIH_MASA_ST_KIRAZ_COMPILER3_KIRAZ_COMPILER_MAINCOMPILER_3_BUILD_PARSER_HPP_INCLUDED  */
