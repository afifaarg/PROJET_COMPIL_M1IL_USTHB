
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 47 "syntax.y"

  int INT;
  char* STR; 
  float FLT;
  char CHR;
  



/* Line 1676 of yacc.c  */
#line 127 "syntax.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


