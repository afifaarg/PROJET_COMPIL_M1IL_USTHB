%{
#include "syntax.tab.h"
#include <stdbool.h>
 extern nb_ligne;
 extern nb_Col;
 extern YYSTYPE yylval;
%}

lettres [a-zA-Z]+
chiffres [0-9]+
constanteE [+-]?{chiffres}+  
constanteR [+-]?{chiffres}+"."{chiffres}        
idf {lettres}({lettres}|{chiffres}|(_{lettres}|{chiffres})*)*
caractere \'(.)+\'
Chainecar \"(.)+\"
%%
 
docprogram  return mc_docpgm;
body  return mc_body;
SUB return mc_sub;
VARIABLE return mc_var;
as return mc_as;
ARRAY return mc_array;
int return mc_int;
CHR return mc_char;
STR return mc_string;
FLT return mc_float;
BOL return mc_bool; 
CONSTANTE return mc_cst;
AND return mc_and;
OR return mc_or;
NOT return mc_not;
SUP return mc_sup;
INF return mc_inf;
SUPE return mc_supe;
INFE return mc_infe;
EGA return mc_ega;
DIF return mc_dif;
AFF return mc_aff;
TRUE return mc_true;
FALSE return mc_false;
INPUT return mc_in;
OUTPUT return mc_out;
IF return mc_if;
THEN return mc_then;
ELSE return mc_else;
DO return mc_do;
WHILE return mc_while;
FOR return mc_for;
UNTIL return mc_until;

"<" {  nb_Col= nb_Col+strlen(yytext);
		return ba_ouv;}

"</" {  nb_Col= nb_Col+strlen(yytext);
		return ba_ouvavcSlach;}
		
">" {  nb_Col= nb_Col+strlen(yytext);
		return ba_fer;}

"/>" {  nb_Col= nb_Col+strlen(yytext);
		return ba_feravcSlach;}
		
"!" {  nb_Col= nb_Col+strlen(yytext);
		return point_ex;}
		
"/" {   yylval.STR=strdup(yytext);
       nb_Col= nb_Col+strlen(yytext);
	   return mc_div;}
"|"  {  nb_Col= nb_Col+strlen(yytext); 
		return mc_sep;}
"=" {  nb_Col= nb_Col+strlen(yytext);
		return egal;}
":" {  nb_Col= nb_Col+strlen(yytext);
		return deuxpoints;}
"," {  nb_Col= nb_Col+strlen(yytext);
		return virgule;}
"+" {  yylval.STR=strdup(yytext);
       nb_Col= nb_Col+strlen(yytext);
		return mc_plus;}
"-" { yylval.STR=strdup(yytext);
       nb_Col= nb_Col+strlen(yytext);
		return mc_moins;}
"*" { yylval.STR=strdup(yytext);
      nb_Col= nb_Col+strlen(yytext);
		return mc_multip;}
"(" { yylval.STR=strdup(yytext);
      nb_Col= nb_Col+strlen(yytext);
		return mc_parOuv;}	
		
")" {  yylval.STR=strdup(yytext);
      nb_Col= nb_Col+strlen(yytext);
		return mc_parFer;}
"["	{  nb_Col= nb_Col+strlen(yytext);
		return mc_bracketsO;}
"]"	{  nb_Col= nb_Col+strlen(yytext);
		return mc_bracketsC;}
"\"" { yylval.STR=strdup(yytext);
nb_Col= nb_Col+strlen(yytext);
        return mc_quotes;}
"$" {yylval.STR=strdup(yytext);
        return form_int;
        }
"%" {yylval.STR=strdup(yytext);
        return form_flt;
        }
"#" {yylval.STR=strdup(yytext);
      return form_str;
        }
"&" {yylval.STR=strdup(yytext);
        return form_char;
        }
"@" {yylval.STR=strdup(yytext);
      return form_bol;
        } 

{idf} { 	yylval.STR=strdup(yytext);
						nb_Col= nb_Col+strlen(yytext);
						
                      return idf;
					 }
		 

{constanteE} {yylval.INT=atoi(yytext);
				nb_Col= nb_Col+strlen(yytext);
              return cnstE;
			}
{constanteR} {yylval.FLT=atof(yytext);
				nb_Col= nb_Col+strlen(yytext);
              return cnstR;
			}
{Chainecar} { yylval.STR=strdup(yytext);
				nb_Col= nb_Col+strlen(yytext);
         return chaine_car;}

{caractere} { yylval.STR=strdup(yytext);
				nb_Col= nb_Col+strlen(yytext);
         return caractere;}

[ \t] {nb_Col= nb_Col+strlen(yytext);}
[ \n] { nb_ligne++; nb_Col=1;}		 
		 
. {
      printf("File :'MiniLangage.txt', line %d, character %d:lexical error \n",nb_ligne,nb_Col);

	 }
	 




