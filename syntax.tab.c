
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "syntax.y"
  


 #include "CodeObj.h"

  int nb_ligne=1; // compteur de ligne
  int nb_Col=1;  // compteur de colonnes 
  
//variable utilisé lors de l'analyse semantique 

  int SauvType; // Variable pour Sauvgarder le type (semantique compatibilite de type)
  char* SauvIdfs[50]; // un tableau pour sauvgarder idfs qui ont le meme type 
  char SauvValCst[20]; // un tableau de caractere pour sauvgarder la valeur de constante
  int TypExp; //Variable pour sauvgarder le type d'expression (semantique compatibilite de type)
  int SauvSF; //Variable pour sauvgarder le signe de formatage (semantique input/output)
  int SauvTypeOp; // Variable pour sauvgarder le type de l'operand 
  char cnsE[20],  cnsF[20];

//variable utilisé lors de la generation des quadruplets 
  char* op; // variable pour sauvgarder l'operation
  char* Op1; // variable pour sauvgarder l'operand1
  char* Op2; // variable pour sauvgarder l'operand2
  char* Val; // variable pour recuperer la valeur de  l'operand
  int ParBol=0; // bolean pour controler si expression contient des parenthese
  char* SauvVal; // variable pour sauvgarder la premiere valeur de l'operand, lors d'une expression imbriqué (contient des parentheses)
  char* SauvOp; // variable pour sauvgarder la premiere valeur operation , lors d'une expression imbriqué (contient des parentheses)


  char ValTemp[5]; // variable pour gerer les resultat temporaire dans les quadruplets
  int cptTemp=1; // compteur de resultat temporaire 
  int OpL; // variable pour sauvgarder l'operation logique (selon un encodage 1,2,3..)
  int opANDoR;// variable pour sauvegarder l'operation logique (or , and)
  
  
   int SauvCondIndq; // variable pour sauvgarder l'indice de quadruplet de debut de IF
   int SauvDebutElse; // variable pour sauvgarder l'indice de quadruplet de debut de ELSE
   int SauvFinElse ; // variable pour sauvgarder l'indice de quadruplet de fin de instruction IF

   int doWhileEtiq;  // variable pour sauvgarder l'indice de quadruplet de fin de instruction boucle DO..While

   int EndForEtiq; // variable pour sauvgarder l'indice de quadruplet de fin de instruction boucle FOR
   int DebutForEtiq; // variable pour sauvgarder l'indice de quadruplet de debut de instruction boucle FOR
   char * Valeur; // variable pour sauvgarder la valeur de l'indice de la boucle for

 

/* Line 189 of yacc.c  */
#line 120 "syntax.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ba_ouv = 258,
     ba_fer = 259,
     point_ex = 260,
     mc_aff = 261,
     virgule = 262,
     mc_sep = 263,
     mc_parOuv = 264,
     mc_parFer = 265,
     mc_bracketsO = 266,
     mc_bracketsC = 267,
     deuxpoints = 268,
     mc_quotes = 269,
     ba_ouvavcSlach = 270,
     ba_feravcSlach = 271,
     mc_docpgm = 272,
     mc_cst = 273,
     mc_body = 274,
     mc_sub = 275,
     mc_var = 276,
     mc_as = 277,
     mc_in = 278,
     mc_if = 279,
     mc_then = 280,
     mc_else = 281,
     mc_do = 282,
     mc_while = 283,
     mc_for = 284,
     mc_until = 285,
     mc_out = 286,
     idf = 287,
     mc_char = 288,
     mc_int = 289,
     mc_string = 290,
     mc_float = 291,
     mc_bool = 292,
     mc_array = 293,
     mc_plus = 294,
     mc_multip = 295,
     mc_moins = 296,
     mc_div = 297,
     mc_and = 298,
     mc_or = 299,
     mc_not = 300,
     mc_sup = 301,
     mc_inf = 302,
     mc_supe = 303,
     mc_infe = 304,
     mc_ega = 305,
     mc_dif = 306,
     egal = 307,
     mc_true = 308,
     mc_false = 309,
     cnstE = 310,
     cnstR = 311,
     caractere = 312,
     chaine_car = 313,
     form_int = 314,
     form_flt = 315,
     form_str = 316,
     form_char = 317,
     form_bol = 318,
     mc_aps = 319,
     chaine_InOut = 320
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 47 "syntax.y"

  int INT;
  char* STR; 
  float FLT;
  char CHR;
  



/* Line 214 of yacc.c  */
#line 231 "syntax.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 243 "syntax.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   293

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  118
/* YYNRULES -- Number of states.  */
#define YYNSTATES  284

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   320

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    14,    21,    24,    27,    32,    38,    42,
      44,    51,    58,    62,    68,    69,    77,    78,    86,    91,
      95,    97,    99,   101,   103,   105,   107,   112,   115,   119,
     123,   132,   136,   140,   142,   144,   146,   148,   150,   152,
     153,   159,   160,   161,   162,   175,   177,   179,   186,   196,
     198,   200,   203,   206,   212,   215,   218,   219,   220,   230,
     231,   232,   242,   243,   250,   251,   252,   261,   262,   263,
     272,   277,   279,   281,   283,   285,   287,   289,   291,   293,
     295,   297,   299,   302,   304,   305,   310,   313,   315,   320,
     322,   324,   325,   330,   332,   334,   336,   338,   347,   356,
     363,   365,   367,   369,   371,   373,   375,   377,   379,   381,
     383,   385,   387,   388,   396,   397,   404,   410,   415
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      67,     0,    -1,     3,     5,    17,    32,     4,    68,    80,
      15,    17,     4,    -1,     3,    20,    21,     4,    69,    74,
      -1,    70,    69,    -1,    72,    69,    -1,    15,    20,    21,
       4,    -1,     3,    71,    22,    79,     4,    -1,    32,     8,
      71,    -1,    32,    -1,     3,    38,    22,    79,     4,    73,
      -1,     3,    32,    13,    55,    16,    73,    -1,    15,    38,
       4,    -1,     3,    20,    18,     4,    75,    -1,    -1,     3,
      32,    52,   105,    16,    76,    75,    -1,    -1,     3,    78,
      22,    79,    16,    77,    75,    -1,    15,    20,    18,     4,
      -1,    32,     8,    78,    -1,    32,    -1,    34,    -1,    33,
      -1,    35,    -1,    36,    -1,    37,    -1,     3,    19,     4,
      81,    -1,    82,    81,    -1,    15,    19,     4,    -1,    15,
      29,     4,    -1,     3,    28,    13,   103,    16,    15,    27,
       4,    -1,    15,    25,     4,    -1,    15,    26,     4,    -1,
      90,    -1,   113,    -1,   112,    -1,   117,    -1,    83,    -1,
      85,    -1,    -1,     3,    27,     4,    84,    81,    -1,    -1,
      -1,    -1,     3,    29,    32,    52,    89,    86,    30,    89,
      87,     4,    88,    81,    -1,    32,    -1,    55,    -1,     3,
       6,    13,    32,     7,    91,    -1,     3,     6,    13,    32,
      11,    55,    12,     7,    91,    -1,   106,    -1,    92,    -1,
     105,    16,    -1,    32,    16,    -1,    32,    11,    55,    12,
      16,    -1,    53,    16,    -1,    54,    16,    -1,    -1,    -1,
     104,     9,   103,    93,     7,   103,    94,    10,    16,    -1,
      -1,    -1,   116,     9,   103,    95,     7,   103,    96,    10,
      16,    -1,    -1,    45,     9,   103,    97,    10,    16,    -1,
      -1,    -1,   104,     9,   103,    99,     7,   103,   100,    10,
      -1,    -1,    -1,   116,     9,   103,   101,     7,   103,   102,
      10,    -1,    45,     9,   103,    10,    -1,    53,    -1,    54,
      -1,    32,    -1,   105,    -1,    98,    -1,    43,    -1,    44,
      -1,    55,    -1,    56,    -1,    58,    -1,    57,    -1,   107,
     106,    -1,    16,    -1,    -1,   109,   108,   111,   109,    -1,
     111,   109,    -1,    32,    -1,    32,    11,    55,    12,    -1,
      55,    -1,    56,    -1,    -1,     9,   110,   107,    10,    -1,
      39,    -1,    40,    -1,    41,    -1,    42,    -1,     3,    23,
      13,    32,    58,    13,   115,    16,    -1,     3,    31,    13,
      58,   115,    39,    32,   114,    -1,    39,    64,    58,   115,
      39,    32,    -1,    16,    -1,    63,    -1,    59,    -1,    62,
      -1,    61,    -1,    60,    -1,    46,    -1,    47,    -1,    48,
      -1,    49,    -1,    50,    -1,    51,    -1,    -1,   120,   121,
     118,   122,    15,    24,     4,    -1,    -1,   120,   121,   119,
      15,    24,     4,    -1,     3,    24,    13,    98,     4,    -1,
       3,    25,     4,    81,    -1,     3,    26,     4,    81,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    89,    89,    97,   100,   101,   102,   105,   108,   114,
     121,   124,   127,   130,   133,   133,   138,   138,   139,   142,
     146,   152,   153,   154,   155,   156,   161,   164,   165,   166,
     171,   172,   173,   176,   177,   178,   179,   180,   181,   183,
     183,   190,   193,   198,   189,   203,   204,   207,   216,   225,
     226,   227,   228,   229,   230,   231,   234,   234,   234,   240,
     240,   240,   245,   245,   252,   252,   252,   257,   257,   257,
     261,   268,   269,   270,   271,   272,   275,   276,   279,   286,
     293,   300,   310,   311,   316,   316,   330,   339,   347,   355,
     362,   368,   368,   374,   379,   384,   388,   394,   400,   406,
     409,   413,   414,   415,   416,   417,   420,   421,   422,   423,
     424,   425,   429,   429,   438,   438,   442,   448,   451
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ba_ouv", "ba_fer", "point_ex", "mc_aff",
  "virgule", "mc_sep", "mc_parOuv", "mc_parFer", "mc_bracketsO",
  "mc_bracketsC", "deuxpoints", "mc_quotes", "ba_ouvavcSlach",
  "ba_feravcSlach", "mc_docpgm", "mc_cst", "mc_body", "mc_sub", "mc_var",
  "mc_as", "mc_in", "mc_if", "mc_then", "mc_else", "mc_do", "mc_while",
  "mc_for", "mc_until", "mc_out", "idf", "mc_char", "mc_int", "mc_string",
  "mc_float", "mc_bool", "mc_array", "mc_plus", "mc_multip", "mc_moins",
  "mc_div", "mc_and", "mc_or", "mc_not", "mc_sup", "mc_inf", "mc_supe",
  "mc_infe", "mc_ega", "mc_dif", "egal", "mc_true", "mc_false", "cnstE",
  "cnstR", "caractere", "chaine_car", "form_int", "form_flt", "form_str",
  "form_char", "form_bol", "mc_aps", "chaine_InOut", "$accept", "S",
  "Partie_Declaration", "ListeDeclarationVAR", "DEC_VAR", "ListeIdf",
  "DEC_TAB", "ListeDecTab", "ListeDeclarationCONST", "DEC_CONST", "$@1",
  "$@2", "ListeCst", "Type", "body", "List_Inst", "instruction",
  "BoucleDOWhile", "$@3", "BoucleFor", "$@4", "$@5", "$@6", "indice",
  "affectation", "CoteDroite", "logique", "$@7", "$@8", "$@9", "$@10",
  "$@11", "expLogique", "$@12", "$@13", "$@14", "$@15", "ValBol",
  "operationL", "variable", "arithmetique", "ExpA", "$@16", "operandG",
  "$@17", "operation", "input", "Output", "OutputSuite", "signForm",
  "operationC", "InstIf", "$@18", "$@19", "Ifheader", "thenBod", "elseBod", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    67,    68,    69,    69,    69,    70,    71,    71,
      72,    73,    73,    74,    76,    75,    77,    75,    75,    78,
      78,    79,    79,    79,    79,    79,    80,    81,    81,    81,
      81,    81,    81,    82,    82,    82,    82,    82,    82,    84,
      83,    86,    87,    88,    85,    89,    89,    90,    90,    91,
      91,    91,    91,    91,    91,    91,    93,    94,    92,    95,
      96,    92,    97,    92,    99,   100,    98,   101,   102,    98,
      98,   103,   103,   103,   103,   103,   104,   104,   105,   105,
     105,   105,   106,   106,   108,   107,   107,   109,   109,   109,
     109,   110,   109,   111,   111,   111,   111,   112,   113,   114,
     114,   115,   115,   115,   115,   115,   116,   116,   116,   116,
     116,   116,   118,   117,   119,   117,   120,   121,   122
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    10,     6,     2,     2,     4,     5,     3,     1,
       6,     6,     3,     5,     0,     7,     0,     7,     4,     3,
       1,     1,     1,     1,     1,     1,     4,     2,     3,     3,
       8,     3,     3,     1,     1,     1,     1,     1,     1,     0,
       5,     0,     0,     0,    12,     1,     1,     6,     9,     1,
       1,     2,     2,     5,     2,     2,     0,     0,     9,     0,
       0,     9,     0,     6,     0,     0,     8,     0,     0,     8,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     0,     4,     2,     1,     4,     1,
       1,     0,     4,     1,     1,     1,     1,     8,     8,     6,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     7,     0,     6,     5,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    26,     0,    37,    38,
      33,    35,    34,    36,     0,     2,     9,     0,     0,     0,
       0,     3,     4,     5,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,     0,   112,     0,     0,
       0,     0,     0,     0,     0,     0,    39,     0,     0,     0,
      28,    31,    32,    29,     0,     0,     0,     8,    22,    21,
      23,    24,    25,     0,     0,     6,     0,     0,     0,    76,
      77,     0,   106,   107,   108,   109,   110,   111,     0,     0,
       0,     0,    73,    71,    72,    78,    79,    81,    80,    75,
       0,    74,     0,     0,     0,     0,     0,     0,     0,     7,
       0,     0,     0,     0,     0,   116,     0,     0,    40,     0,
      45,    46,    41,   102,   105,   104,   103,   101,     0,   117,
       0,     0,     0,     0,     0,    10,     0,     0,    13,    91,
      83,    87,    93,    94,    95,    96,     0,     0,     0,    89,
      90,    47,    50,     0,     0,    49,     0,    84,     0,     0,
       0,     0,     0,    64,    67,     0,     0,     0,     0,     0,
     115,     0,     0,    20,     0,     0,     0,     0,    52,     0,
      54,    55,     0,    51,    87,    89,    90,    82,     0,    86,
       0,     0,     0,    70,     0,     0,     0,     0,     0,   118,
     113,     0,    12,     0,     0,     0,     0,     0,     0,    62,
      56,     0,     0,    59,     0,    97,     0,     0,    30,    42,
     100,     0,    98,     0,    20,    19,     0,     0,    18,    92,
      88,     0,     0,     0,    85,     0,    48,    65,    68,     0,
       0,     0,    14,    16,    53,     0,     0,    88,     0,     0,
       0,    43,     0,    11,     0,     0,    63,    57,    60,    66,
      69,     0,     0,    15,    17,     0,     0,    44,     0,     0,
       0,    99,    58,    61
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    21,    22,    38,    23,   145,    41,   148,
     264,   265,   184,    83,    12,    26,    27,    28,   101,    29,
     176,   249,   271,   132,    30,   161,   162,   242,   275,   245,
     276,   241,   109,   204,   259,   205,   260,   110,    99,   111,
     165,   166,   198,   167,   186,   168,    31,    32,   232,   138,
     100,    33,    75,    76,    34,    57,   116
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -194
static const yytype_int16 yypact[] =
{
      20,    60,    73,    58,  -194,    54,    81,    85,    69,    87,
      76,    93,    96,   109,   110,   100,    10,    11,   118,   -14,
     104,   132,    10,    10,    92,     3,  -194,    11,  -194,  -194,
    -194,  -194,  -194,  -194,   134,  -194,   131,   116,   121,   119,
     124,  -194,  -194,  -194,   135,   136,   137,   141,   139,   115,
     140,   150,   151,   162,   178,  -194,   158,   169,   153,    46,
      46,   182,   170,   155,   157,   130,  -194,   114,   138,   133,
    -194,  -194,  -194,  -194,   188,   190,   179,  -194,  -194,  -194,
    -194,  -194,  -194,   191,   192,  -194,   193,    55,   142,  -194,
    -194,   189,  -194,  -194,  -194,  -194,  -194,  -194,   195,   194,
     196,    11,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,
     185,  -194,   -21,    70,    11,   176,   197,   180,    12,  -194,
      16,     1,   152,   198,   114,  -194,   114,   114,  -194,   199,
    -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,   167,  -194,
     204,   186,   205,   181,   177,  -194,   184,   200,  -194,  -194,
    -194,    53,  -194,  -194,  -194,  -194,   208,   202,   203,   206,
     207,  -194,  -194,   212,   209,  -194,    52,  -194,    21,   215,
     214,    70,   217,  -194,  -194,   201,   210,   211,    11,   225,
    -194,   218,   226,     8,   213,   216,    86,   183,  -194,   114,
    -194,  -194,   114,  -194,   221,  -194,  -194,  -194,    -3,  -194,
     114,   229,   223,  -194,   230,   234,   238,   -21,    -4,  -194,
    -194,   219,  -194,   220,    45,    46,   241,   236,   235,  -194,
    -194,   222,    21,  -194,     1,  -194,   114,   114,  -194,  -194,
    -194,   187,  -194,   232,   242,  -194,   233,   237,  -194,  -194,
     239,   244,   249,   245,  -194,   251,  -194,  -194,  -194,   255,
     175,    12,  -194,  -194,  -194,   246,   114,  -194,   114,   250,
     253,  -194,    70,  -194,    16,    16,  -194,  -194,  -194,  -194,
    -194,    11,   227,  -194,  -194,   254,   257,  -194,   240,   252,
     259,  -194,  -194,  -194
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -194,  -194,  -194,    -2,  -194,   224,  -194,    14,  -194,  -193,
    -194,  -194,    48,   -59,  -194,   -27,  -194,  -194,  -194,  -194,
    -194,  -194,  -194,    62,  -194,    47,  -194,  -194,  -194,  -194,
    -194,  -194,   228,  -194,  -194,  -194,  -194,  -122,  -115,  -118,
     107,    84,  -194,  -159,  -194,    78,  -194,  -194,  -194,  -163,
    -114,  -194,  -194,  -194,  -194,  -194,  -194
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -115
static const yytype_int16 yytable[] =
{
      55,    84,   172,   164,   173,   174,   163,   169,   202,   199,
     149,   130,   230,    19,    24,   143,   213,   150,    36,   146,
      42,    43,    51,     1,    37,    20,    25,   144,    52,    53,
     149,   147,    54,   151,   131,   231,   152,   153,   154,   155,
     152,   153,   154,   155,    89,    90,   156,    92,    93,    94,
      95,    96,    97,   194,   157,   158,   159,   160,   107,   108,
     214,   149,   121,   244,   187,     3,   122,   219,   150,   188,
     220,   273,   274,     4,   128,     5,   195,   196,   223,    78,
      79,    80,    81,    82,   194,     7,     6,   139,     8,    10,
      11,   152,   153,   154,   155,   149,   236,    13,    44,   272,
     105,   106,   107,   108,   247,   248,   164,   195,   196,   163,
     169,    15,    14,    16,    17,    45,    46,    18,   194,    47,
      48,    49,    35,    50,    39,   152,   153,   154,   155,   133,
     134,   135,   136,   137,   267,    40,   268,    56,    59,    58,
      61,   195,   196,    60,    62,    66,   102,    68,    63,    64,
      65,   209,    67,    69,    70,    71,   237,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    72,   103,   104,   105,
     106,   107,   108,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    73,    74,  -114,    36,    85,    87,    86,    88,
     112,   113,   114,   115,   117,   118,   119,   120,   124,   125,
     123,   129,   140,   126,   142,   127,   177,   170,   178,   180,
     179,   171,   141,   181,   175,   182,   183,   189,   190,   191,
     185,   192,   -78,   -79,   200,   193,   201,   203,   206,   210,
     212,   211,   221,   262,   216,   215,   224,   226,   218,   225,
     207,   227,   228,   208,   277,   238,   239,   240,   251,   252,
     213,   250,   234,   253,   255,   254,   256,   257,   258,   261,
     269,   235,   266,   270,   279,   263,   278,   280,   282,   229,
     217,   246,   281,   197,   233,   283,   222,   243,     0,     0,
       0,     0,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    98
};

static const yytype_int16 yycheck[] =
{
      27,    60,   124,   121,   126,   127,   121,   121,   171,   168,
       9,    32,    16,     3,     3,     3,     8,    16,    32,     3,
      22,    23,    19,     3,    38,    15,    15,    15,    25,    26,
       9,    15,    29,    32,    55,    39,    39,    40,    41,    42,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    32,    53,    54,    55,    56,    57,    58,
      52,     9,     7,   222,    11,     5,    11,   189,    16,    16,
     192,   264,   265,     0,   101,    17,    55,    56,   200,    33,
      34,    35,    36,    37,    32,     4,    32,   114,     3,    20,
       3,    39,    40,    41,    42,     9,   214,    21,     6,   262,
      55,    56,    57,    58,   226,   227,   224,    55,    56,   224,
     224,    15,    19,     4,     4,    23,    24,    17,    32,    27,
      28,    29,     4,    31,    20,    39,    40,    41,    42,    59,
      60,    61,    62,    63,   256,     3,   258,     3,    22,     8,
      21,    55,    56,    22,    20,     4,    32,    32,    13,    13,
      13,   178,    13,    13,     4,     4,   215,    43,    44,    45,
      46,    47,    48,    49,    50,    51,     4,    53,    54,    55,
      56,    57,    58,    43,    44,    45,    46,    47,    48,    49,
      50,    51,     4,    25,    15,    32,     4,    32,    18,    32,
      52,    58,     4,     3,    15,     4,     4,     4,     9,     4,
      58,    16,    26,     9,    24,     9,    39,    55,     4,     4,
      24,    13,    15,    32,    15,    38,    32,     9,    16,    16,
      20,     9,    16,    16,     9,    16,    12,    10,    27,     4,
       4,    13,    11,    58,    18,    22,     7,     7,    55,    16,
      30,     7,     4,    32,   271,     4,    10,    12,    16,    16,
       8,    64,    32,    16,    10,    16,     7,    12,     7,     4,
      10,   213,    16,    10,    10,   251,    39,    10,    16,   207,
     186,   224,    32,   166,    55,    16,   198,    55,    -1,    -1,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    67,     5,     0,    17,    32,     4,     3,    68,
      20,     3,    80,    21,    19,    15,     4,     4,    17,     3,
      15,    69,    70,    72,     3,    15,    81,    82,    83,    85,
      90,   112,   113,   117,   120,     4,    32,    38,    71,    20,
       3,    74,    69,    69,     6,    23,    24,    27,    28,    29,
      31,    19,    25,    26,    29,    81,     3,   121,     8,    22,
      22,    21,    20,    13,    13,    13,     4,    13,    32,    13,
       4,     4,     4,     4,    25,   118,   119,    71,    33,    34,
      35,    36,    37,    79,    79,     4,    18,    32,    32,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    98,   104,
     116,    84,    32,    53,    54,    55,    56,    57,    58,    98,
     103,   105,    52,    58,     4,     3,   122,    15,     4,     4,
       4,     7,    11,    58,     9,     4,     9,     9,    81,    16,
      32,    55,    89,    59,    60,    61,    62,    63,   115,    81,
      26,    15,    24,     3,    15,    73,     3,    15,    75,     9,
      16,    32,    39,    40,    41,    42,    45,    53,    54,    55,
      56,    91,    92,   104,   105,   106,   107,   109,   111,   116,
      55,    13,   103,   103,   103,    15,    86,    39,     4,    24,
       4,    32,    38,    32,    78,    20,   110,    11,    16,     9,
      16,    16,     9,    16,    32,    55,    56,   106,   108,   109,
       9,    12,   115,    10,    99,   101,    27,    30,    32,    81,
       4,    13,     4,     8,    52,    22,    18,   107,    55,   103,
     103,    11,   111,   103,     7,    16,     7,     7,     4,    89,
      16,    39,   114,    55,    32,    78,   105,    79,     4,    10,
      12,    97,    93,    55,   109,    95,    91,   103,   103,    87,
      64,    16,    16,    16,    16,    10,     7,    12,     7,   100,
     102,     4,    58,    73,    76,    77,    16,   103,   103,    10,
      10,    88,   115,    75,    75,    94,    96,    81,    39,    10,
      10,    32,    16,    16
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 89 "syntax.y"
    { printf("syntaxe correcte \n");
                                                                                                      ProgName=strdup((yyvsp[(4) - (10)].STR));
                                                                                                      YYACCEPT;
                                                                                                    ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 101 "syntax.y"
    {insererType(SauvType);;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 105 "syntax.y"
    {insererType(SauvType);;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 108 "syntax.y"
    { if(recherche((yyvsp[(1) - (3)].STR))==1 ) printf ("File :'MiniLangage.txt', line %d, entite  %s :symantic error <Double Declaration > \n",nb_ligne,(yyvsp[(1) - (3)].STR));
                                 else {
                                        inserer((yyvsp[(1) - (3)].STR),"idf",1,"non"); 
                                        ajouter_idf((yyvsp[(1) - (3)].STR)); 
                                      }
                               ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 114 "syntax.y"
    {if(recherche((yyvsp[(1) - (1)].STR))==1 ) printf ("File :'MiniLangage.txt', line %d, entite  %s :symantic error <Double Declaration > \n",nb_ligne,(yyvsp[(1) - (1)].STR));
                         else {inserer((yyvsp[(1) - (1)].STR),"idf",1,"non");
                                ajouter_idf((yyvsp[(1) - (1)].STR));
                              }
                ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 121 "syntax.y"
    {insererType(SauvType);;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 124 "syntax.y"
    { inserer((yyvsp[(2) - (6)].STR),"idf_tab",(yyvsp[(4) - (6)].INT),"non");
                                                                        ajouter_idf((yyvsp[(2) - (6)].STR));
                                                                     ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 133 "syntax.y"
    { inserer((yyvsp[(2) - (5)].STR),"idf",1,"oui"); 
                                                       insererValeur((yyvsp[(2) - (5)].STR),SauvValCst);
                                                       ajouter_idf((yyvsp[(2) - (5)].STR)); 
                                                       insererType(SauvType);
                                                     ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 138 "syntax.y"
    {insererType(SauvType);;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 142 "syntax.y"
    { inserer((yyvsp[(1) - (3)].STR),"idf",1, "oui");
                                ajouter_idf((yyvsp[(1) - (3)].STR)); 
                              ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 146 "syntax.y"
    { inserer((yyvsp[(1) - (1)].STR),"idf",1,"oui"); 
                 ajouter_idf((yyvsp[(1) - (1)].STR));  
           ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 152 "syntax.y"
    {SauvType=1;;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 153 "syntax.y"
    {SauvType=2;;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 154 "syntax.y"
    {SauvType=3;;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 155 "syntax.y"
    {SauvType=4;;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 156 "syntax.y"
    {SauvType=5;;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 166 "syntax.y"
    {
                                          EndForEtiq=indq+1;                                    
                                          q[DebutForEtiq].op1=ToSTR(EndForEtiq);
                                          quad("BR",ToSTR(DebutForEtiq),"","");
                                          ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 171 "syntax.y"
    { quad("BZ",ToSTR(doWhileEtiq), q[indq-1].res,""); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 183 "syntax.y"
    {quad("","","","");
                                     doWhileEtiq=indq-1; 
                                    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 190 "syntax.y"
    {  quad("=",Valeur,"",(yyvsp[(3) - (5)].STR));   ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 193 "syntax.y"
    { sprintf(ValTemp,"T%d",cptTemp); 
                      quadA(1,q[indq-1].res,Valeur,ValTemp); 
                          cptTemp++;
                  ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 198 "syntax.y"
    {quad("BZ","",q[indq-1].res,""); 
                          DebutForEtiq=indq-1;;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 203 "syntax.y"
    {Valeur = (yyvsp[(1) - (1)].STR);;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 204 "syntax.y"
    {sprintf(Valeur,"%d",(yyvsp[(1) - (1)].INT));;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 207 "syntax.y"
    {if(VerifType((yyvsp[(4) - (6)].STR),TypExp)==-1) {printf ("File :'MiniLangage.txt', line %d , entite %s:symantic error <idf non-declare> \n",nb_ligne,(yyvsp[(4) - (6)].STR));}
                                                          else if (VerifType((yyvsp[(4) - (6)].STR),TypExp)==0) {printf ("File :'MiniLangage.txt', line %d :symantic error <Types non-compatibles> \n",nb_ligne);}
                                                          else{ if (DoubleAffectation((yyvsp[(4) - (6)].STR))==-1) {printf ("File :'MiniLangage.txt', line %d :symantic error <Double Affectation ; constante deja initialise> \n",nb_ligne);}
                                                                     else {insererValeur((yyvsp[(4) - (6)].STR),SauvValCst);
                                                                     quad("=",ValTemp,"",(yyvsp[(4) - (6)].STR));                                                 
                                                                }
                                                         }  
                                                        ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 216 "syntax.y"
    {
                                                        if(VerifType((yyvsp[(4) - (9)].STR),TypExp)==-1) {printf ("File :'MiniLangage.txt', line %d , entite %s:symantic error <idf non-declare> \n",nb_ligne,(yyvsp[(4) - (9)].STR));}
                                                           else if (VerifType((yyvsp[(4) - (9)].STR),TypExp)==0) {printf ("File :'MiniLangage.txt', line %d :symantic error <Types non-compatibles> \n",nb_ligne);}
                                                                 else{ if (DoubleAffectation((yyvsp[(4) - (9)].STR))==-1) {printf ("File :'MiniLangage.txt', line %d :symantic error <Double Affectation ; constante deja initialise> \n",nb_ligne);}
                                                                       else {insererValeur((yyvsp[(4) - (9)].STR),SauvValCst);}
                                                                }
                                                        ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 226 "syntax.y"
    {TypExp=5;;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 228 "syntax.y"
    {  strcpy(ValTemp,(yyvsp[(1) - (2)].STR)); TypExp=GetType((yyvsp[(1) - (2)].STR)); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 229 "syntax.y"
    {  strcpy(ValTemp,(yyvsp[(1) - (5)].STR)); TypExp=GetType((yyvsp[(1) - (5)].STR)); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 230 "syntax.y"
    {  strcpy(ValTemp,"1"); TypExp=5;;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 231 "syntax.y"
    {  strcpy(ValTemp,"0"); TypExp=5;;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 234 "syntax.y"
    {Op1=Val;;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 234 "syntax.y"
    {Op2=Val;;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 234 "syntax.y"
    {
                                                                                                     sprintf(ValTemp,"T%d",cptTemp);
                                                                                                     createQuadL(opANDoR, Op1,Op2,ValTemp);
                                                                                                     cptTemp++;
                                                                                                    ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 240 "syntax.y"
    {Op1=Val;;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 240 "syntax.y"
    {Op2=Val;;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 240 "syntax.y"
    { sprintf(ValTemp,"T%d",cptTemp);
                                                                                                       quadA(OpL,Op1,Op2,ValTemp);
                                                                                                       cptTemp++;
                                                                                                     ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 245 "syntax.y"
    {Op1=Val;;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 245 "syntax.y"
    {
                                                                      sprintf(ValTemp,"T%d",cptTemp);
                                                                      createQuadL(1, Op1,"",ValTemp);
                                                                      cptTemp++;
                                                                    ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 252 "syntax.y"
    {Op1=Val;;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 252 "syntax.y"
    {Op2=Val;;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 252 "syntax.y"
    {
                                                                                        sprintf(ValTemp,"T%d",cptTemp);
                                                                                        createQuadL(opANDoR, Op1,Op2,ValTemp);
                                                                                        cptTemp++;
                                                                                      ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 257 "syntax.y"
    {Op1=Val;;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 257 "syntax.y"
    {Op2=Val;;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 257 "syntax.y"
    { sprintf(ValTemp,"T%d",cptTemp);
                                                                                         quadA(OpL,Op1,Op2,ValTemp);
                                                                                        cptTemp++;
                                                                                       ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 261 "syntax.y"
    {            
                                                sprintf(ValTemp,"T%d",cptTemp);
                                                createQuadL(1, q[indq-1].res,"",ValTemp);
                                                cptTemp++;
                                              ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 268 "syntax.y"
    { Val="1"; TypExp=5;;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 269 "syntax.y"
    { Val="0"; TypExp=5;;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 270 "syntax.y"
    {  Val= (yyvsp[(1) - (1)].STR);;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 275 "syntax.y"
    {opANDoR=3;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 276 "syntax.y"
    {opANDoR=2;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 279 "syntax.y"
    { sprintf(SauvValCst,"%d",(yyvsp[(1) - (1)].INT));
                     SauvType=1;
                     TypExp =1;
                     Val=strdup(SauvValCst); 
                     strcpy(ValTemp,SauvValCst);
                  ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 286 "syntax.y"
    { sprintf(SauvValCst,"%f",(yyvsp[(1) - (1)].FLT));
                     SauvType=4;
                     TypExp =4;
                     Val=strdup(SauvValCst);                
                     strcpy(ValTemp,SauvValCst);
                  ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 293 "syntax.y"
    { strcpy(SauvValCst,(yyvsp[(1) - (1)].STR));
                       strcpy(Val,(yyvsp[(1) - (1)].STR));
                        SauvType=3;
                        TypExp =3;
                        strcpy(ValTemp,SauvValCst);
                     ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 300 "syntax.y"
    { strcpy(SauvValCst,(yyvsp[(1) - (1)].STR));
                       strcpy(Val,(yyvsp[(1) - (1)].STR));
                       SauvType=2;
                       TypExp =2;
                      strcpy(ValTemp,SauvValCst);
                     ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 311 "syntax.y"
    { TypExp=VerifCompatibilite(); 
                                initTabExp(); 
                              ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 316 "syntax.y"
    {Op1=Val;;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 316 "syntax.y"
    {  if(ParBol==0){ // dans le cas ou l'expression ne contient pass des parenthese
                                                    Op2=Val;
                                                    sprintf(ValTemp,"T%d",cptTemp);
                                                    quad(op,Op1,Op2,ValTemp);                       
                                                    cptTemp++;                                                
                                                   }else{   // dans le cas ou l'expression  contient des parenthese ParBol==1.
                                                       Op1=q[indq-1].res ;
                                                       sprintf(ValTemp,"T%d",cptTemp);
                                                       quad(SauvOp,Op1,SauvVal,ValTemp);
                                                       cptTemp++;
                                                      }
                                                      ParBol=0;
                                                ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 330 "syntax.y"
    {
                            Op2=Val;
                            Op1=q[indq-1].res;
                            sprintf(ValTemp,"T%d",cptTemp);
                            quad(op,Op1,Op2,ValTemp);
                                cptTemp++;
                           ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 339 "syntax.y"
    {if(!recherche((yyvsp[(1) - (1)].STR))) {printf ("File :'MiniLangage.txt', line %d , entite %s:symantic error <idf non-declare> \n",nb_ligne,(yyvsp[(1) - (1)].STR));}
                  else{                                    
                     SauvTypeOp = GetType((yyvsp[(1) - (1)].STR)); 
                     InsererExp((yyvsp[(1) - (1)].STR));                  
                     Val= (yyvsp[(1) - (1)].STR);
                  }
              ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 347 "syntax.y"
    {if(!recherche((yyvsp[(1) - (4)].STR))) {printf ("File :'MiniLangage.txt', line %d , entite %s:symantic error <idf non-declare> \n",nb_ligne,(yyvsp[(1) - (4)].STR));}
                                                 else{                                    
                                                   SauvTypeOp = GetType((yyvsp[(1) - (4)].STR)); 
                                                   InsererExp((yyvsp[(1) - (4)].STR));
                                                   Val= (yyvsp[(1) - (4)].STR);
                                           }
                  ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 355 "syntax.y"
    { 
                    SauvTypeOp = 1;
                    sprintf(cnsE,"%d",(yyvsp[(1) - (1)].INT));
                    Val= cnsE;
                    InsererExp(cnsE);
                  ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 362 "syntax.y"
    {
                     SauvTypeOp = 1;
                     sprintf(cnsF,"%f",(yyvsp[(1) - (1)].FLT));
                     Val= cnsF;
                     InsererExp(cnsF);
                  ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 368 "syntax.y"
    {InsererExp((yyvsp[(1) - (1)].STR)); SauvVal=Op1; SauvOp=op;;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 368 "syntax.y"
    {ParBol=1; /*expression contient des parenthese */;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 374 "syntax.y"
    {   
                       op=(yyvsp[(1) - (1)].STR);
                      InsererExp((yyvsp[(1) - (1)].STR)); 
                    ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 379 "syntax.y"
    { 
                           op=(yyvsp[(1) - (1)].STR);
                          InsererExp((yyvsp[(1) - (1)].STR));
                     ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 384 "syntax.y"
    { 
                         op=(yyvsp[(1) - (1)].STR);
                         InsererExp((yyvsp[(1) - (1)].STR));
                       ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 388 "syntax.y"
    { 
                         op=(yyvsp[(1) - (1)].STR);
                       InsererExp((yyvsp[(1) - (1)].STR));     
                     ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 394 "syntax.y"
    { 
                                                                                            if(VerifType((yyvsp[(4) - (8)].STR),SauvSF)==-1) {printf ("File :'MiniLangage.txt', line %d , entite %s:symantic error <idf non-declare> \n",nb_ligne,(yyvsp[(4) - (8)].STR));}
                                                                                                          else if(VerifType((yyvsp[(4) - (8)].STR),SauvSF)==0) {printf ("File :'MiniLangage.txt', line %d :symantic error <Type/Signe Formatage non-compatibles> \n",nb_ligne);}
                                                                                      ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 400 "syntax.y"
    { 
                                                                                           if(VerifType((yyvsp[(7) - (8)].STR),SauvSF)==-1) {printf ("File :'MiniLangage.txt', line %d , entite %s:symantic error <idf non-declare> \n",nb_ligne,(yyvsp[(7) - (8)].STR));}
                                                                                                          else if(VerifType((yyvsp[(7) - (8)].STR),SauvSF)==0) {printf ("File :'MiniLangage.txt', line %d :symantic error <Type/Signe Formatage non-compatibles> \n",nb_ligne);}
                                                                                                      ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 406 "syntax.y"
    { if(VerifType((yyvsp[(6) - (6)].STR),SauvSF)==-1) {printf ("File :'MiniLangage.txt', line %d , entite %s:symantic error <idf non-declare> \n",nb_ligne,(yyvsp[(6) - (6)].STR));}
                                                                                                          else if(VerifType((yyvsp[(6) - (6)].STR),SauvSF)==0) {printf ("File :'MiniLangage.txt', line %d :symantic error <Type/Signe Formatage non-compatibles> \n",nb_ligne);}
                                                                                                      ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 413 "syntax.y"
    {SauvSF=5;;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 414 "syntax.y"
    {SauvSF=1;;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 415 "syntax.y"
    {SauvSF=2;;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 416 "syntax.y"
    {SauvSF=3;;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 417 "syntax.y"
    {SauvSF=4;;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 420 "syntax.y"
    {OpL=1;;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 421 "syntax.y"
    {OpL=2;;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 422 "syntax.y"
    {OpL=3;;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 423 "syntax.y"
    {OpL=4;;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 424 "syntax.y"
    {OpL=5;;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 425 "syntax.y"
    {OpL=6;;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 429 "syntax.y"
    {
                            quad("BR","","","");
                            SauvDebutElse=indq;
                         ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 433 "syntax.y"
    {
                                                  q[SauvCondIndq].op1= ToSTR(SauvDebutElse);
			                                            q[SauvDebutElse-1].op1= ToSTR(SauvFinElse);
                                                ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 438 "syntax.y"
    {SauvDebutElse=indq;;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 439 "syntax.y"
    { q[SauvCondIndq].op1= ToSTR(SauvDebutElse);;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 442 "syntax.y"
    {
                                                        quad("BZ","",q[indq-1].res,"");
                                                        SauvCondIndq=indq-1;
                                                      ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 452 "syntax.y"
    {SauvFinElse=indq; ;}
    break;



/* Line 1455 of yacc.c  */
#line 2469 "syntax.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 457 "syntax.y"

main()
{ 
 indq=0;
 cpTabidf=0;
 cpTabExp=0;
yyparse();

printf("\n");
if(nb_ligne==1) {printf("programme vide !!");}

afficherTS(); 
afficherQuad();
printf("\n");
optimisationQuad();
printf("\n");
GenerateCodeObjet(TS);
printf("\n::::::::::::::::::::::Quadruplets apres Optimisation ::::::::::::::::::::::::::::::::\n");
printf("\n");
afficherQuadAfterOpt();

}
yywrap()
{}
yyerror(char * msg)
{
 printf("File :'MiniLangage.txt', line %d, character %d:syntax error \n",nb_ligne,nb_Col);
}

