%{  


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

 %}
 
 %union{
  int INT;
  char* STR; 
  float FLT;
  char CHR;
  
}

%token  
/*Les symboles*/
ba_ouv ba_fer point_ex mc_aff virgule mc_sep <STR>mc_parOuv <STR>mc_parFer mc_bracketsO mc_bracketsC deuxpoints  mc_quotes ba_ouvavcSlach ba_feravcSlach

/*Les mots réservés*/
mc_docpgm  mc_cst mc_body mc_sub mc_var mc_as  mc_in mc_if mc_then mc_else mc_do mc_while mc_for  mc_until mc_out

/* Types et variables */
<STR>idf mc_char mc_int mc_string mc_float mc_bool mc_array 

/*Opérations Arithmétiques*/
<STR>mc_plus <STR>mc_multip <STR>mc_moins <STR>mc_div

/*Opération logiques*/
<STR>mc_and <STR>mc_or <STR>mc_not <STR>mc_sup <STR>mc_inf  <STR>mc_supe <STR>mc_infe <STR>mc_ega <STR>mc_dif egal <STR>mc_true <STR>mc_false 

/*Valeurs qu'un idf peut prendre */    
<INT>cnstE <FLT>cnstR <STR>caractere   <STR>chaine_car

/*Signes de formatages*/  
 <STR>form_int <STR>form_flt <STR>form_str <STR>form_char <STR>form_bol mc_aps  chaine_InOut

//Priorité entre les opérations
%left mc_or
%left mc_and
%left mc_not
%left mc_sup mc_inf mc_ega mc_dif mc_supe mc_infe
%left mc_plus mc_moins
%left mc_multip mc_div 
%left mc_parOuv mc_parFer

%%

//Axiome
 S: ba_ouv point_ex mc_docpgm idf  ba_fer Partie_Declaration  body ba_ouvavcSlach  mc_docpgm ba_fer{ printf("syntaxe correcte \n");
                                                                                                      ProgName=strdup($4);
                                                                                                      YYACCEPT;
                                                                                                    }
;

/***************************************   Partie declaration ***********************************************/

Partie_Declaration: ba_ouv mc_sub mc_var ba_fer ListeDeclarationVAR ListeDeclarationCONST
;

ListeDeclarationVAR : DEC_VAR ListeDeclarationVAR
                    | DEC_TAB ListeDeclarationVAR {insererType(SauvType);}
			              | ba_ouvavcSlach mc_sub mc_var ba_fer
;

DEC_VAR :ba_ouv ListeIdf mc_as Type ba_fer  {insererType(SauvType);}
;

ListeIdf : idf mc_sep ListeIdf { if(recherche($1)==1 ) printf ("File :'MiniLangage.txt', line %d, entite  %s :symantic error <Double Declaration > \n",nb_ligne,$1);
                                 else {
                                        inserer($1,"idf",1,"non"); 
                                        ajouter_idf($1); 
                                      }
                               }
	       | idf {if(recherche($1)==1 ) printf ("File :'MiniLangage.txt', line %d, entite  %s :symantic error <Double Declaration > \n",nb_ligne,$1);
                         else {inserer($1,"idf",1,"non");
                                ajouter_idf($1);
                              }
                }
;

DEC_TAB : ba_ouv mc_array mc_as Type ba_fer ListeDecTab {insererType(SauvType);}
;

ListeDecTab : ba_ouv idf deuxpoints cnstE ba_feravcSlach ListeDecTab { inserer($2,"idf_tab",$4,"non");
                                                                        ajouter_idf($2);
                                                                     }
            |ba_ouvavcSlach mc_array ba_fer 
;

ListeDeclarationCONST : ba_ouv mc_sub mc_cst ba_fer DEC_CONST                        
;

DEC_CONST :  ba_ouv idf egal variable ba_feravcSlach { inserer($2,"idf",1,"oui"); 
                                                       insererValeur($2,SauvValCst);
                                                       ajouter_idf($2); 
                                                       insererType(SauvType);
                                                     } DEC_CONST    
           | ba_ouv ListeCst mc_as Type ba_feravcSlach {insererType(SauvType);} DEC_CONST 
           | ba_ouvavcSlach  mc_sub mc_cst ba_fer         
;    

ListeCst: idf mc_sep ListeCst { inserer($1,"idf",1, "oui");
                                ajouter_idf($1); 
                              }

	    |idf { inserer($1,"idf",1,"oui"); 
                 ajouter_idf($1);  
           }
;


Type : mc_int {SauvType=1;}
	   | mc_char {SauvType=2;}
	   | mc_string {SauvType=3;}
	   | mc_float  {SauvType=4;}
	   | mc_bool {SauvType=5;}
;

/***************************************   Partie BODY (Instructions ) ***********************************************/

body : ba_ouv mc_body ba_fer List_Inst 
;

List_Inst : instruction List_Inst
          | ba_ouvavcSlach  mc_body ba_fer 
          | ba_ouvavcSlach mc_for ba_fer {
                                          EndForEtiq=indq+1;                                    
                                          q[DebutForEtiq].op1=ToSTR(EndForEtiq);
                                          quad("BR",ToSTR(DebutForEtiq),"","");
                                          }
          | ba_ouv mc_while deuxpoints ValBol ba_feravcSlach  ba_ouvavcSlach mc_do ba_fer { quad("BZ",ToSTR(doWhileEtiq), q[indq-1].res,""); }
          | ba_ouvavcSlach mc_then ba_fer
          | ba_ouvavcSlach mc_else ba_fer        
;

instruction : affectation 
            | Output
            | input
            | InstIf 
            | BoucleDOWhile
            | BoucleFor   
;
BoucleDOWhile : ba_ouv mc_do ba_fer{quad("","","","");
                                     doWhileEtiq=indq-1; 
                                    }
                List_Inst                           
;

BoucleFor : ba_ouv mc_for idf egal indice 
                 {  quad("=",Valeur,"",$3);   } // quad d'initialisation de l'indice

             mc_until indice 
                  { sprintf(ValTemp,"T%d",cptTemp); 
                      quadA(1,q[indq-1].res,Valeur,ValTemp); 
                          cptTemp++;
                  }  // verifiction cond indice < n 
                                  
               ba_fer  {quad("BZ","",q[indq-1].res,""); 
                          DebutForEtiq=indq-1;} // la verification de  la cond boucle 
            List_Inst         
;

indice : idf {Valeur = $1;}
       | cnstE{sprintf(Valeur,"%d",$1);}
;

affectation: ba_ouv mc_aff deuxpoints idf virgule CoteDroite  {if(VerifType($4,TypExp)==-1) {printf ("File :'MiniLangage.txt', line %d , entite %s:symantic error <idf non-declare> \n",nb_ligne,$4);}
                                                          else if (VerifType($4,TypExp)==0) {printf ("File :'MiniLangage.txt', line %d :symantic error <Types non-compatibles> \n",nb_ligne);}
                                                          else{ if (DoubleAffectation($4)==-1) {printf ("File :'MiniLangage.txt', line %d :symantic error <Double Affectation ; constante deja initialise> \n",nb_ligne);}
                                                                     else {insererValeur($4,SauvValCst);
                                                                     quad("=",ValTemp,"",$4);                                                 
                                                                }
                                                         }  
                                                        }
                                                          
           | ba_ouv mc_aff deuxpoints idf mc_bracketsO cnstE mc_bracketsC virgule CoteDroite {
                                                        if(VerifType($4,TypExp)==-1) {printf ("File :'MiniLangage.txt', line %d , entite %s:symantic error <idf non-declare> \n",nb_ligne,$4);}
                                                           else if (VerifType($4,TypExp)==0) {printf ("File :'MiniLangage.txt', line %d :symantic error <Types non-compatibles> \n",nb_ligne);}
                                                                 else{ if (DoubleAffectation($4)==-1) {printf ("File :'MiniLangage.txt', line %d :symantic error <Double Affectation ; constante deja initialise> \n",nb_ligne);}
                                                                       else {insererValeur($4,SauvValCst);}
                                                                }
                                                        }   
;
        
CoteDroite: arithmetique
          |logique {TypExp=5;}
          |variable ba_feravcSlach
          |idf ba_feravcSlach {  strcpy(ValTemp,$1); TypExp=GetType($1); }
          |idf mc_bracketsO cnstE mc_bracketsC ba_feravcSlach  {  strcpy(ValTemp,$1); TypExp=GetType($1); } //idf tableau
          |mc_true ba_feravcSlach  {  strcpy(ValTemp,"1"); TypExp=5;}
          |mc_false ba_feravcSlach  {  strcpy(ValTemp,"0"); TypExp=5;}
;

logique: operationL mc_parOuv ValBol {Op1=Val;} virgule ValBol {Op2=Val;} mc_parFer ba_feravcSlach  {
                                                                                                     sprintf(ValTemp,"T%d",cptTemp);
                                                                                                     createQuadL(opANDoR, Op1,Op2,ValTemp);
                                                                                                     cptTemp++;
                                                                                                    }

        |operationC  mc_parOuv ValBol {Op1=Val;} virgule ValBol  {Op2=Val;} mc_parFer ba_feravcSlach { sprintf(ValTemp,"T%d",cptTemp);
                                                                                                       quadA(OpL,Op1,Op2,ValTemp);
                                                                                                       cptTemp++;
                                                                                                     } 

        |mc_not mc_parOuv ValBol{Op1=Val;} mc_parFer ba_feravcSlach {
                                                                      sprintf(ValTemp,"T%d",cptTemp);
                                                                      createQuadL(1, Op1,"",ValTemp);
                                                                      cptTemp++;
                                                                    }
; 

expLogique:operationL mc_parOuv ValBol {Op1=Val;}  virgule ValBol{Op2=Val;} mc_parFer {
                                                                                        sprintf(ValTemp,"T%d",cptTemp);
                                                                                        createQuadL(opANDoR, Op1,Op2,ValTemp);
                                                                                        cptTemp++;
                                                                                      }
          |operationC  mc_parOuv ValBol {Op1=Val;} virgule ValBol {Op2=Val;} mc_parFer { sprintf(ValTemp,"T%d",cptTemp);
                                                                                         quadA(OpL,Op1,Op2,ValTemp);
                                                                                        cptTemp++;
                                                                                       } 
          |mc_not mc_parOuv ValBol mc_parFer  {            
                                                sprintf(ValTemp,"T%d",cptTemp);
                                                createQuadL(1, q[indq-1].res,"",ValTemp);
                                                cptTemp++;
                                              }
;

ValBol:mc_true   { Val="1"; TypExp=5;}
      |mc_false  { Val="0"; TypExp=5;}
      |idf {  Val= $1;}
      |variable
      |expLogique
;

operationL:mc_and{opANDoR=3}
          |mc_or{opANDoR=2}
; 

variable : cnstE  { sprintf(SauvValCst,"%d",$1);
                     SauvType=1;
                     TypExp =1;
                     Val=strdup(SauvValCst); 
                     strcpy(ValTemp,SauvValCst);
                  }

          |cnstR  { sprintf(SauvValCst,"%f",$1);
                     SauvType=4;
                     TypExp =4;
                     Val=strdup(SauvValCst);                
                     strcpy(ValTemp,SauvValCst);
                  }

          |chaine_car{ strcpy(SauvValCst,$1);
                       strcpy(Val,$1);
                        SauvType=3;
                        TypExp =3;
                        strcpy(ValTemp,SauvValCst);
                     }

          |caractere { strcpy(SauvValCst,$1);
                       strcpy(Val,$1);
                       SauvType=2;
                       TypExp =2;
                      strcpy(ValTemp,SauvValCst);
                     }
          
; 


arithmetique:  ExpA arithmetique
             | ba_feravcSlach { TypExp=VerifCompatibilite(); 
                                initTabExp(); 
                              }
;

ExpA:  operandG  {Op1=Val;} operation operandG {  if(ParBol==0){ // dans le cas ou l'expression ne contient pass des parenthese
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
                                                }
                                                                                                        
     |operation operandG {
                            Op2=Val;
                            Op1=q[indq-1].res;
                            sprintf(ValTemp,"T%d",cptTemp);
                            quad(op,Op1,Op2,ValTemp);
                                cptTemp++;
                           }
;

operandG :idf {if(!recherche($1)) {printf ("File :'MiniLangage.txt', line %d , entite %s:symantic error <idf non-declare> \n",nb_ligne,$1);}
                  else{                                    
                     SauvTypeOp = GetType($1); 
                     InsererExp($1);                  
                     Val= $1;
                  }
              } 

          |idf mc_bracketsO cnstE mc_bracketsC {if(!recherche($1)) {printf ("File :'MiniLangage.txt', line %d , entite %s:symantic error <idf non-declare> \n",nb_ligne,$1);}
                                                 else{                                    
                                                   SauvTypeOp = GetType($1); 
                                                   InsererExp($1);
                                                   Val= $1;
                                           }
                  }

          |cnstE  { 
                    SauvTypeOp = 1;
                    sprintf(cnsE,"%d",$1);
                    Val= cnsE;
                    InsererExp(cnsE);
                  }

          |cnstR {
                     SauvTypeOp = 1;
                     sprintf(cnsF,"%f",$1);
                     Val= cnsF;
                     InsererExp(cnsF);
                  }  
          | mc_parOuv {InsererExp($1); SauvVal=Op1; SauvOp=op;} ExpA  mc_parFer {ParBol=1; /*expression contient des parenthese */}    
          
       
     
;

operation : mc_plus {   
                       op=$1;
                      InsererExp($1); 
                    }

            |mc_multip { 
                           op=$1;
                          InsererExp($1);
                     }

            |mc_moins  { 
                         op=$1;
                         InsererExp($1);
                       }
            |mc_div   { 
                         op=$1;
                       InsererExp($1);     
                     }
;  

input : ba_ouv mc_in deuxpoints idf   chaine_car deuxpoints signForm  ba_feravcSlach { 
                                                                                            if(VerifType($4,SauvSF)==-1) {printf ("File :'MiniLangage.txt', line %d , entite %s:symantic error <idf non-declare> \n",nb_ligne,$4);}
                                                                                                          else if(VerifType($4,SauvSF)==0) {printf ("File :'MiniLangage.txt', line %d :symantic error <Type/Signe Formatage non-compatibles> \n",nb_ligne);}
                                                                                      }
;

Output: ba_ouv mc_out deuxpoints chaine_car  signForm mc_plus idf  OutputSuite  { 
                                                                                           if(VerifType($7,SauvSF)==-1) {printf ("File :'MiniLangage.txt', line %d , entite %s:symantic error <idf non-declare> \n",nb_ligne,$7);}
                                                                                                          else if(VerifType($7,SauvSF)==0) {printf ("File :'MiniLangage.txt', line %d :symantic error <Type/Signe Formatage non-compatibles> \n",nb_ligne);}
                                                                                                      }
;

OutputSuite : mc_plus  mc_aps  chaine_car  signForm  mc_plus idf  { if(VerifType($6,SauvSF)==-1) {printf ("File :'MiniLangage.txt', line %d , entite %s:symantic error <idf non-declare> \n",nb_ligne,$6);}
                                                                                                          else if(VerifType($6,SauvSF)==0) {printf ("File :'MiniLangage.txt', line %d :symantic error <Type/Signe Formatage non-compatibles> \n",nb_ligne);}
                                                                                                      }
            | ba_feravcSlach 
 ;           


signForm: form_bol  {SauvSF=5;}
         |form_int  {SauvSF=1;}
         |form_char {SauvSF=2;}
         |form_str  {SauvSF=3;}
         |form_flt  {SauvSF=4;}
;

operationC:mc_sup  {OpL=1;}  //BG  
          |mc_inf  {OpL=2;}  //BL
          |mc_supe {OpL=3;}  //BGE
          |mc_infe {OpL=4;} // BLE
          |mc_ega  {OpL=5;} // BE
          |mc_dif  {OpL=6;}  //BNE
;

/******************** INSTRUCTION IF****************    */       
InstIf: Ifheader thenBod {
                            quad("BR","","","");
                            SauvDebutElse=indq;
                         } 
           elseBod ba_ouvavcSlach mc_if ba_fer {
                                                  q[SauvCondIndq].op1= ToSTR(SauvDebutElse);
			                                            q[SauvDebutElse-1].op1= ToSTR(SauvFinElse);
                                                }

      |Ifheader  thenBod {SauvDebutElse=indq;} 
        ba_ouvavcSlach mc_if ba_fer { q[SauvCondIndq].op1= ToSTR(SauvDebutElse);}
;

Ifheader:  ba_ouv mc_if deuxpoints expLogique ba_fer  {
                                                        quad("BZ","",q[indq-1].res,"");
                                                        SauvCondIndq=indq-1;
                                                      }
;

thenBod : ba_ouv mc_then ba_fer
         List_Inst 
;
elseBod: ba_ouv mc_else ba_fer 
         List_Inst {SauvFinElse=indq; }
;

/********************* THE END ******************************/

%%
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
