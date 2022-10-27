flex lexical.l
bison -d syntax.y
gcc lex.yy.c syntax.tab.c Quad_Optimisation.c TS_RS.c CodeObj.c -lfl -ly -o LangMil.exe
