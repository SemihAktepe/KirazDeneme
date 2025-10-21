/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 13 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"

#include "main.h"
#include "lexer.hpp"

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
#include <kiraz/token/Id.h>
#include <kiraz/token/KwLet.h>
#include <kiraz/token/KwImport.h>
#include <kiraz/token/KwIf.h>
#include <kiraz/token/KwElse.h>
#include <kiraz/token/KwWhile.h>
#include <kiraz/token/Return.h>
#include <kiraz/token/Func.h>
#include <kiraz/ast/Func.h>
#include <kiraz/ast/Arg.h>
#include <kiraz/ast/Module.h>
#include <kiraz/token/Operator.h>
#include <kiraz/token/KwClass.h>

#include <kiraz/token/Literal.h>

int yyerror(const char *msg);
extern std::shared_ptr<Token> curtoken;
extern int yylineno;

#line 106 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_OP_LPAREN = 3,                  /* OP_LPAREN  */
  YYSYMBOL_OP_RPAREN = 4,                  /* OP_RPAREN  */
  YYSYMBOL_OP_PLUS = 5,                    /* OP_PLUS  */
  YYSYMBOL_OP_MINUS = 6,                   /* OP_MINUS  */
  YYSYMBOL_OP_DIVF = 7,                    /* OP_DIVF  */
  YYSYMBOL_OP_MULT = 8,                    /* OP_MULT  */
  YYSYMBOL_OP_DOT = 9,                     /* OP_DOT  */
  YYSYMBOL_OP_COLON = 10,                  /* OP_COLON  */
  YYSYMBOL_OP_COMMA = 11,                  /* OP_COMMA  */
  YYSYMBOL_OP_SEMCOL = 12,                 /* OP_SEMCOL  */
  YYSYMBOL_OP_ASSIGN = 13,                 /* OP_ASSIGN  */
  YYSYMBOL_OP_LBRACE = 14,                 /* OP_LBRACE  */
  YYSYMBOL_OP_RBRACE = 15,                 /* OP_RBRACE  */
  YYSYMBOL_OP_EQUAL = 16,                  /* OP_EQUAL  */
  YYSYMBOL_OP_GT = 17,                     /* OP_GT  */
  YYSYMBOL_OP_LT = 18,                     /* OP_LT  */
  YYSYMBOL_OP_GTEQU = 19,                  /* OP_GTEQU  */
  YYSYMBOL_OP_LTEQU = 20,                  /* OP_LTEQU  */
  YYSYMBOL_KW_LET = 21,                    /* KW_LET  */
  YYSYMBOL_KW_FUNC = 22,                   /* KW_FUNC  */
  YYSYMBOL_KW_IMPORT = 23,                 /* KW_IMPORT  */
  YYSYMBOL_KW_IF = 24,                     /* KW_IF  */
  YYSYMBOL_KW_ELSE = 25,                   /* KW_ELSE  */
  YYSYMBOL_KW_CLASS = 26,                  /* KW_CLASS  */
  YYSYMBOL_KW_WHILE = 27,                  /* KW_WHILE  */
  YYSYMBOL_KW_RETURN = 28,                 /* KW_RETURN  */
  YYSYMBOL_L_STRING = 29,                  /* L_STRING  */
  YYSYMBOL_ID = 30,                        /* ID  */
  YYSYMBOL_L_INTEGER = 31,                 /* L_INTEGER  */
  YYSYMBOL_REJECTED = 32,                  /* REJECTED  */
  YYSYMBOL_YYACCEPT = 33,                  /* $accept  */
  YYSYMBOL_module = 34,                    /* module  */
  YYSYMBOL_module_stmt = 35,               /* module_stmt  */
  YYSYMBOL_stmt = 36,                      /* stmt  */
  YYSYMBOL_reg_stmt = 37,                  /* reg_stmt  */
  YYSYMBOL_call_stmt = 38,                 /* call_stmt  */
  YYSYMBOL_call_name = 39,                 /* call_name  */
  YYSYMBOL_dec_call_args = 40,             /* dec_call_args  */
  YYSYMBOL_call_args = 41,                 /* call_args  */
  YYSYMBOL_return_stmt = 42,               /* return_stmt  */
  YYSYMBOL_return_value = 43,              /* return_value  */
  YYSYMBOL_tf = 44,                        /* tf  */
  YYSYMBOL_func = 45,                      /* func  */
  YYSYMBOL_declare_arg = 46,               /* declare_arg  */
  YYSYMBOL_arg_list = 47,                  /* arg_list  */
  YYSYMBOL_arg = 48,                       /* arg  */
  YYSYMBOL_type = 49,                      /* type  */
  YYSYMBOL_return_type = 50,               /* return_type  */
  YYSYMBOL_stmt_list = 51,                 /* stmt_list  */
  YYSYMBOL_assign = 52,                    /* assign  */
  YYSYMBOL_addsub = 53,                    /* addsub  */
  YYSYMBOL_muldiv = 54,                    /* muldiv  */
  YYSYMBOL_posneg = 55,                    /* posneg  */
  YYSYMBOL_import_stmt = 56,               /* import_stmt  */
  YYSYMBOL_if_stmt = 57,                   /* if_stmt  */
  YYSYMBOL_matched_if = 58,                /* matched_if  */
  YYSYMBOL_open_if = 59,                   /* open_if  */
  YYSYMBOL_class_stmt = 60,                /* class_stmt  */
  YYSYMBOL_inherit_type = 61,              /* inherit_type  */
  YYSYMBOL_while_stmt = 62,                /* while_stmt  */
  YYSYMBOL_assign_let = 63,                /* assign_let  */
  YYSYMBOL_declare = 64                    /* declare  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  54
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   172

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  140

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   287


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    91,    91,    92,    95,    96,    99,   100,   101,   102,
     103,   104,   105,   106,   110,   111,   112,   113,   117,   118,
     119,   120,   124,   125,   129,   133,   142,   143,   147,   151,
     152,   153,   157,   158,   159,   160,   161,   166,   169,   172,
     173,   178,   181,   184,   187,   188,   191,   192,   193,   197,
     198,   202,   203,   204,   209,   210,   211,   215,   216,   217,
     218,   219,   220,   227,   228,   231,   232,   235,   236,   240,
     241,   245,   249,   250,   254,   258,   262,   263,   264,   265,
     266
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "OP_LPAREN",
  "OP_RPAREN", "OP_PLUS", "OP_MINUS", "OP_DIVF", "OP_MULT", "OP_DOT",
  "OP_COLON", "OP_COMMA", "OP_SEMCOL", "OP_ASSIGN", "OP_LBRACE",
  "OP_RBRACE", "OP_EQUAL", "OP_GT", "OP_LT", "OP_GTEQU", "OP_LTEQU",
  "KW_LET", "KW_FUNC", "KW_IMPORT", "KW_IF", "KW_ELSE", "KW_CLASS",
  "KW_WHILE", "KW_RETURN", "L_STRING", "ID", "L_INTEGER", "REJECTED",
  "$accept", "module", "module_stmt", "stmt", "reg_stmt", "call_stmt",
  "call_name", "dec_call_args", "call_args", "return_stmt", "return_value",
  "tf", "func", "declare_arg", "arg_list", "arg", "type", "return_type",
  "stmt_list", "assign", "addsub", "muldiv", "posneg", "import_stmt",
  "if_stmt", "matched_if", "open_if", "class_stmt", "inherit_type",
  "while_stmt", "assign_let", "declare", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-84)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      78,    38,    38,    38,    30,    30,    -9,    48,    32,    -9,
      42,    38,   -84,   -84,   -84,    47,   -84,    78,    44,    37,
      -1,    63,   -84,    86,    67,   -84,   152,    89,   -84,    91,
     100,   -84,   -84,   104,   106,   108,   -84,    68,   -84,   -84,
     -84,   -84,     9,    58,   -84,   -84,    38,    69,    38,   -84,
     -84,   -84,     7,   152,   -84,   -84,   -84,    38,    23,    -9,
     -84,   -84,   -84,    38,    -9,    38,   -84,    38,    38,    38,
      38,    38,    38,    38,    38,    38,   -84,   -84,   -84,   -84,
     -84,   -84,    38,   -84,   114,    -9,   119,   128,    67,    -9,
     125,   129,   -84,   -84,   123,   132,   -84,   -84,   -84,    89,
      89,   105,   105,   105,   105,   105,   -84,   -84,   -84,   -84,
     133,   130,   134,    -9,   125,   125,   -84,   125,   -84,   125,
     -84,   125,    38,   -84,   -84,    -9,    -9,   -84,   -84,   117,
     100,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   125,   -84
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,    43,    59,     0,     3,     5,     0,    16,
      21,     0,    14,     0,    57,    15,    17,    53,    56,     0,
       0,    65,    66,     0,     0,     0,    57,     0,    60,    61,
      80,    79,     0,     0,    64,    63,     0,    73,     0,    30,
      28,    31,    57,    29,     1,     4,    13,     0,     0,     0,
      19,    12,     6,    27,     0,     0,    18,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     8,     9,    10,
      11,    62,     0,    77,    76,    41,    45,     0,    57,     0,
       0,     0,    50,    20,    26,     0,    23,    22,    49,    51,
      52,    32,    33,    34,    35,    36,    55,    54,    75,    78,
       0,    39,     0,     0,     0,     0,    72,     0,    48,     0,
      71,     0,    27,    24,    38,    41,     0,    44,    37,    68,
       0,    66,    46,    47,    74,    25,    40,    42,     0,    67
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -84,   -84,   126,    49,   -45,   139,   -84,   140,    39,   -84,
     -84,   148,   -84,   -84,    40,   -84,     0,   -84,   -83,   -84,
      22,    56,    12,   138,    51,   -84,    52,   -84,   -84,   -84,
      79,    20
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    15,    16,   119,    18,    19,    20,    66,    95,    21,
      50,    22,    23,    86,   110,   111,    36,   114,   120,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    90,    34,
      83,    35
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      24,    87,    58,    91,    40,    40,    43,    44,    59,    47,
      63,    52,    92,    94,    38,    39,    64,    24,    94,     4,
      98,    13,    82,    37,    41,    42,     1,    93,     2,     3,
       5,   128,   129,    53,   132,    46,   133,   108,   134,    13,
       4,     1,    40,     2,     3,    48,    88,    54,    88,    17,
      57,     5,    12,    13,    14,   139,    56,    88,    88,    96,
      13,    85,    84,    88,    97,    88,    17,    12,    13,    14,
      63,     7,    81,    67,    68,    61,    64,    94,    13,    89,
      65,     1,    88,     2,     3,   112,   106,   107,     4,   116,
      24,   101,   102,   103,   104,   105,    74,    75,    62,     5,
       6,     7,     8,    76,     9,    10,    11,    12,    13,    14,
      67,    68,    77,   127,    24,    24,    78,    24,    79,    24,
      80,    24,    88,    99,   100,   112,   137,    82,     1,   113,
       2,     3,   115,   121,   122,     4,   123,   124,    24,   117,
     118,   125,   138,    55,   126,    45,     5,     6,     7,     8,
      49,     9,    10,    11,    12,    13,    14,    67,    68,    51,
      60,   135,     0,   109,     0,   136,   130,   131,    69,    70,
      71,    72,    73
};

static const yytype_int16 yycheck[] =
{
       0,    46,     3,    48,     4,     5,     6,     7,     9,     9,
       3,    11,    57,    58,     2,     3,     9,    17,    63,    10,
      65,    30,    13,     1,     4,     5,     3,     4,     5,     6,
      21,   114,   115,    11,   117,     3,   119,    82,   121,    30,
      10,     3,    42,     5,     6,     3,    46,     0,    48,     0,
      13,    21,    29,    30,    31,   138,    12,    57,    58,    59,
      30,     3,    42,    63,    64,    65,    17,    29,    30,    31,
       3,    23,     4,     5,     6,    12,     9,   122,    30,    10,
      13,     3,    82,     5,     6,    85,    74,    75,    10,    89,
      90,    69,    70,    71,    72,    73,     7,     8,    12,    21,
      22,    23,    24,    12,    26,    27,    28,    29,    30,    31,
       5,     6,    12,   113,   114,   115,    12,   117,    12,   119,
      12,   121,   122,    67,    68,   125,   126,    13,     3,    10,
       5,     6,     4,     4,    11,    10,     4,     4,   138,    14,
      15,    11,    25,    17,    10,     7,    21,    22,    23,    24,
      11,    26,    27,    28,    29,    30,    31,     5,     6,    11,
      20,   122,    -1,    84,    -1,   125,   115,   115,    16,    17,
      18,    19,    20
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,     6,    10,    21,    22,    23,    24,    26,
      27,    28,    29,    30,    31,    34,    35,    36,    37,    38,
      39,    42,    44,    45,    49,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    62,    64,    49,    53,    55,    55,
      49,    64,    64,    49,    49,    56,     3,    49,     3,    38,
      43,    44,    49,    53,     0,    35,    12,    13,     3,     9,
      40,    12,    12,     3,     9,    13,    40,     5,     6,    16,
      17,    18,    19,    20,     7,     8,    12,    12,    12,    12,
      12,     4,    13,    63,    64,     3,    46,    37,    49,    10,
      61,    37,    37,     4,    37,    41,    49,    49,    37,    54,
      54,    53,    53,    53,    53,    53,    55,    55,    37,    63,
      47,    48,    49,    10,    50,     4,    49,    14,    15,    36,
      51,     4,    11,     4,     4,    11,    10,    49,    51,    51,
      57,    59,    51,    51,    51,    41,    47,    49,    25,    51
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    33,    34,    34,    35,    35,    36,    36,    36,    36,
      36,    36,    36,    36,    37,    37,    37,    37,    38,    38,
      38,    38,    39,    39,    40,    41,    41,    41,    42,    43,
      43,    43,    44,    44,    44,    44,    44,    45,    46,    47,
      47,    47,    48,    49,    50,    50,    51,    51,    51,    52,
      52,    53,    53,    53,    54,    54,    54,    55,    55,    55,
      55,    55,    55,    56,    56,    57,    57,    58,    58,    59,
      59,    60,    61,    61,    62,    63,    64,    64,    64,    64,
      64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     2,     0,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     2,     2,
       3,     1,     3,     3,     3,     3,     1,     0,     2,     1,
       1,     1,     3,     3,     3,     3,     3,     5,     3,     1,
       3,     0,     3,     1,     2,     0,     2,     2,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     1,     1,     1,
       2,     2,     3,     2,     1,     1,     1,     7,     5,     5,
       5,     4,     2,     0,     5,     2,     3,     3,     4,     2,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* module: %empty  */
#line 91 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
     { yyerror("Expected a statement"); }
#line 1259 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 3: /* module: module_stmt  */
#line 92 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                 {yyval = Node::add<ast::ModuleL>(yyvsp[0]);}
#line 1265 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 4: /* module_stmt: stmt module_stmt  */
#line 95 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                     {yyval = Node::add<ast::ModuleN>(yyvsp[-1], yyvsp[0]);}
#line 1271 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 5: /* module_stmt: %empty  */
#line 96 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
      {yyval = Node::add<ast::ModuleN>();}
#line 1277 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 6: /* stmt: func OP_SEMCOL  */
#line 99 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                   {yyval = yyvsp[-1];}
#line 1283 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 7: /* stmt: import_stmt OP_SEMCOL  */
#line 100 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                           {yyval = yyvsp[-1];}
#line 1289 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 8: /* stmt: if_stmt OP_SEMCOL  */
#line 101 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                       {yyval = yyvsp[-1];}
#line 1295 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 9: /* stmt: class_stmt OP_SEMCOL  */
#line 102 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                          {yyval = yyvsp[-1];}
#line 1301 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 10: /* stmt: while_stmt OP_SEMCOL  */
#line 103 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                          {yyval = yyvsp[-1];}
#line 1307 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 11: /* stmt: declare OP_SEMCOL  */
#line 104 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                       {yyval = yyvsp[-1];}
#line 1313 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 12: /* stmt: return_stmt OP_SEMCOL  */
#line 105 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                           {yyval = yyvsp[-1];}
#line 1319 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 13: /* stmt: reg_stmt OP_SEMCOL  */
#line 106 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                       {yyval = yyvsp[-1];}
#line 1325 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 14: /* reg_stmt: tf  */
#line 110 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
        {yyval = yyvsp[0];}
#line 1331 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 15: /* reg_stmt: assign  */
#line 111 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
             {yyval = yyvsp[0];}
#line 1337 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 16: /* reg_stmt: call_stmt  */
#line 112 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                {yyval = yyvsp[0];}
#line 1343 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 17: /* reg_stmt: addsub  */
#line 113 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
             {yyval = yyvsp[0];}
#line 1349 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 18: /* call_stmt: type dec_call_args  */
#line 117 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                         {yyval = Node::add<ast::Call>(yyvsp[-1], yyvsp[0]);}
#line 1355 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 19: /* call_stmt: call_name dec_call_args  */
#line 118 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                               {yyval = Node::add<ast::Call>(yyvsp[-1], yyvsp[0]);}
#line 1361 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 20: /* call_stmt: call_name OP_LPAREN OP_RPAREN  */
#line 119 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                                    {yyval = Node::add<ast::Call>(yyvsp[-2], nullptr);}
#line 1367 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 21: /* call_stmt: call_name  */
#line 120 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                {yyval = Node::add<ast::Call>(yyvsp[0], nullptr);}
#line 1373 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 22: /* call_name: type OP_DOT type  */
#line 124 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                     {yyval = Node::add<ast::OpDot>(yyvsp[-2], yyvsp[0]);}
#line 1379 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 23: /* call_name: call_name OP_DOT type  */
#line 125 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                            {yyval = Node::add<ast::OpDot>(yyvsp[-2], yyvsp[0]);}
#line 1385 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 24: /* dec_call_args: OP_LPAREN call_args OP_RPAREN  */
#line 129 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                                  {yyval = Node::add<ast::CallL>(yyvsp[-1]);}
#line 1391 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 25: /* call_args: reg_stmt OP_COMMA call_args  */
#line 133 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                                {
        auto first_arg = Node::add<ast::CallS>(yyvsp[-2]);
        if (!first_arg || !yyvsp[0]) {
            yyerror("Invalid CallS chain in call_args");
            YYABORT;
        }
        auto next_args = std::dynamic_pointer_cast<ast::CallS>(yyvsp[0]);
        first_arg->next = next_args;
        yyval = first_arg; }
#line 1405 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 26: /* call_args: reg_stmt  */
#line 142 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
              {yyval = Node::add<ast::CallS>(yyvsp[0]);}
#line 1411 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 27: /* call_args: %empty  */
#line 143 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
     {yyval = Node::add<ast::CallS>();}
#line 1417 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 28: /* return_stmt: KW_RETURN return_value  */
#line 147 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                           { yyval = Node::add<ast::Return>(yyvsp[0]); }
#line 1423 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 29: /* return_value: addsub  */
#line 151 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
           { yyval = yyvsp[0]; }
#line 1429 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 30: /* return_value: call_stmt  */
#line 152 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                {yyval = yyvsp[0];}
#line 1435 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 31: /* return_value: tf  */
#line 153 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
         { yyval = yyvsp[0]; }
#line 1441 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 32: /* tf: addsub OP_EQUAL addsub  */
#line 157 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                           {yyval = Node::add<ast::OpEqual>(yyvsp[-2], yyvsp[0]);}
#line 1447 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 33: /* tf: addsub OP_GT addsub  */
#line 158 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                         {yyval = Node::add<ast::OpGt>(yyvsp[-2], yyvsp[0]);}
#line 1453 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 34: /* tf: addsub OP_LT addsub  */
#line 159 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                         {yyval = Node::add<ast::OpLt>(yyvsp[-2], yyvsp[0]);}
#line 1459 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 35: /* tf: addsub OP_GTEQU addsub  */
#line 160 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                            {yyval = Node::add<ast::OpGtEqu>(yyvsp[-2], yyvsp[0]);}
#line 1465 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 36: /* tf: addsub OP_LTEQU addsub  */
#line 161 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                            {yyval = Node::add<ast::OpLtEqu>(yyvsp[-2], yyvsp[0]);}
#line 1471 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 37: /* func: KW_FUNC type declare_arg return_type stmt_list  */
#line 166 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                                                   { yyval = Node::add<ast::Func>(yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1477 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 38: /* declare_arg: OP_LPAREN arg_list OP_RPAREN  */
#line 169 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                                 { yyval = Node::add<ast::Args>(yyvsp[-1]); }
#line 1483 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 39: /* arg_list: arg  */
#line 172 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
        { yyval = yyvsp[0]; }
#line 1489 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 40: /* arg_list: arg OP_COMMA arg_list  */
#line 173 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                          { 
        auto first_arg = std::dynamic_pointer_cast<ast::Arg>(yyvsp[-2]);
        first_arg->next = yyvsp[0];
        yyval = first_arg; 
    }
#line 1499 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 41: /* arg_list: %empty  */
#line 178 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
      { yyval = Node::add<ast::Arg>(); }
#line 1505 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 42: /* arg: type OP_COLON type  */
#line 181 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                       { yyval = Node::add<ast::Arg>(yyvsp[-2], yyvsp[0]); }
#line 1511 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 43: /* type: ID  */
#line 184 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
       { yyval = Node::add<ast::Id>(curtoken); }
#line 1517 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 44: /* return_type: OP_COLON type  */
#line 187 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                  { yyval = yyvsp[0]; }
#line 1523 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 45: /* return_type: %empty  */
#line 188 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
      { yyval = Node::add<ast::Arg>(); }
#line 1529 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 46: /* stmt_list: OP_LBRACE stmt_list  */
#line 191 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                         {yyval = Node::add<ast::StmtL>(yyvsp[0]);}
#line 1535 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 47: /* stmt_list: stmt stmt_list  */
#line 192 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                    {yyval = Node::add<ast::StmtN>(yyvsp[-1],yyvsp[0]);}
#line 1541 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 48: /* stmt_list: OP_RBRACE  */
#line 193 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
               {yyval = Node::add<ast::StmtN>();}
#line 1547 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 49: /* assign: type OP_ASSIGN reg_stmt  */
#line 197 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                            { yyval = Node::add<ast::OpAssign>(yyvsp[-2], yyvsp[0]); }
#line 1553 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 50: /* assign: call_stmt OP_ASSIGN reg_stmt  */
#line 198 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                                  { yyval = Node::add<ast::OpAssign>(yyvsp[-2], yyvsp[0]); }
#line 1559 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 51: /* addsub: addsub OP_PLUS muldiv  */
#line 202 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                          { yyval = Node::add<ast::OpAdd>(yyvsp[-2], yyvsp[0]); }
#line 1565 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 52: /* addsub: addsub OP_MINUS muldiv  */
#line 203 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                             { yyval = Node::add<ast::OpSub>(yyvsp[-2], yyvsp[0]); }
#line 1571 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 53: /* addsub: muldiv  */
#line 204 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
             { yyval = yyvsp[0]; }
#line 1577 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 54: /* muldiv: muldiv OP_MULT posneg  */
#line 209 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                          { yyval = Node::add<ast::OpMult>(yyvsp[-2], yyvsp[0]); }
#line 1583 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 55: /* muldiv: muldiv OP_DIVF posneg  */
#line 210 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                           { yyval = Node::add<ast::OpDivF>(yyvsp[-2], yyvsp[0]); }
#line 1589 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 56: /* muldiv: posneg  */
#line 211 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
            { yyval = yyvsp[0]; }
#line 1595 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 57: /* posneg: type  */
#line 215 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
         {yyval = yyvsp[0]; }
#line 1601 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 58: /* posneg: L_STRING  */
#line 216 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
               { yyval = Node::add<ast::Str>(curtoken); }
#line 1607 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 59: /* posneg: L_INTEGER  */
#line 217 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                { yyval = Node::add<ast::Integer>(curtoken); }
#line 1613 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 60: /* posneg: OP_PLUS posneg  */
#line 218 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                     { yyval = Node::add<ast::SignedNode>(OP_PLUS, yyvsp[0]); }
#line 1619 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 61: /* posneg: OP_MINUS posneg  */
#line 219 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                      { yyval = Node::add<ast::SignedNode>(OP_MINUS, yyvsp[0]); }
#line 1625 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 62: /* posneg: OP_LPAREN addsub OP_RPAREN  */
#line 220 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                                 { yyval = yyvsp[-1]; }
#line 1631 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 63: /* import_stmt: KW_IMPORT import_stmt  */
#line 227 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                          {yyval = Node::add<ast::Import>(yyvsp[0]);  }
#line 1637 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 64: /* import_stmt: type  */
#line 228 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
          {yyval =yyvsp[0];}
#line 1643 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 65: /* if_stmt: matched_if  */
#line 231 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
               {yyval=yyvsp[0];}
#line 1649 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 66: /* if_stmt: open_if  */
#line 232 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
              {yyval=yyvsp[0];}
#line 1655 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 67: /* matched_if: KW_IF OP_LPAREN reg_stmt OP_RPAREN stmt_list KW_ELSE stmt_list  */
#line 235 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                                                                   { yyval = Node::add<ast::IfElse>(yyvsp[-4], yyvsp[-2], yyvsp[0]); }
#line 1661 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 68: /* matched_if: KW_IF OP_LPAREN reg_stmt OP_RPAREN stmt_list  */
#line 236 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                                                   { yyval = Node::add<ast::IfElse>(yyvsp[-2], yyvsp[0]); }
#line 1667 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 69: /* open_if: KW_IF OP_LPAREN reg_stmt OP_RPAREN if_stmt  */
#line 240 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                                               { yyval = Node::add<ast::IfElse>(yyvsp[-2], yyvsp[0]); }
#line 1673 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 70: /* open_if: KW_IF OP_LPAREN reg_stmt OP_RPAREN open_if  */
#line 241 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                                                 { yyval = Node::add<ast::IfElse>(yyvsp[-2], yyvsp[0]); }
#line 1679 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 71: /* class_stmt: KW_CLASS type inherit_type stmt_list  */
#line 245 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                                         {yyval = Node::add<ast::ClassDef>(yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1685 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 72: /* inherit_type: OP_COLON type  */
#line 249 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                  {yyval = yyvsp[0];}
#line 1691 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 74: /* while_stmt: KW_WHILE OP_LPAREN reg_stmt OP_RPAREN stmt_list  */
#line 254 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                                                     {yyval = Node::add<ast::While>(yyvsp[-2], yyvsp[0]);}
#line 1697 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 75: /* assign_let: OP_ASSIGN reg_stmt  */
#line 258 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                       {yyval = yyvsp[0];}
#line 1703 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 76: /* declare: KW_LET declare declare  */
#line 262 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                           {yyval = Node::add<ast::KwLet>(KW_LET,yyvsp[-1],yyvsp[0],1);}
#line 1709 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 77: /* declare: KW_LET declare assign_let  */
#line 263 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                               {yyval = Node::add<ast::KwLet>(KW_LET,yyvsp[-1],yyvsp[0]);}
#line 1715 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 78: /* declare: KW_LET declare declare assign_let  */
#line 264 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                                       {yyval = Node::add<ast::KwLet>(KW_LET,yyvsp[-2],yyvsp[-1],yyvsp[0]);}
#line 1721 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 79: /* declare: OP_COLON declare  */
#line 265 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
                      {yyval = yyvsp[0];}
#line 1727 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;

  case 80: /* declare: type  */
#line 266 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"
          {yyval = yyvsp[0];}
#line 1733 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"
    break;


#line 1737 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/build/parser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 270 "/home/semih/Masaüstü/kiraz_compiler3/kiraz-compiler-mainCompiler-3/parser.yy"


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
