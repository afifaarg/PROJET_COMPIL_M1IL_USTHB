#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include  "Quad_Optimisation.h"



//Création des quadruplet + insertion dans la tableau de quadruplets
void quad(char *opt, char *opd1, char *opd2, char *res){
	
	q[indq].opr=strdup(opt);
	q[indq].op1=strdup(opd1);
	q[indq].op2=strdup(opd2);
	q[indq].res=strdup(res);
	indq++;
}
char* ToSTR(int i){
	char s[15];
	sprintf(s,"%d",i);
	return strdup(s);
}

void afficherQuad()
{ int i;
quad("","","","");
printf("\n::::::::::::::::::::::::::::::: Quadruplets :::::::::::::::::::::::::::::::::::\n");
for (i=0;i<indq;i++){ 
     printf ("%d-( %s , %s , %s , %s )\n",i,q[i].opr,q[i].op1,q[i].op2,q[i].res);
}
 printf("**** le nombre des quadruplets avant l'optimisation est : %d\n",i);
}

//Verrification des conditions
void quadA(int type, char *cond1, char *cond2, char *res){
	char *TypeBR;
	switch(type){
		case 1 :{//1==> "SUPERIEUR"
			TypeBR=strdup("BG");
		}
		break;
		case 2 :{//2==> "INFERIEUR"
			TypeBR=strdup("BL");
		}
		break;
		case 3 :{//3==> ">=" higher Or Equal
			TypeBR=strdup("BGE");
		}
		break;
		case 4 :{//4==> "<=" lower Or Equal
			TypeBR=strdup("BLE");
		}
		break;
		case 5 :{//5==> "=" equal
			TypeBR=strdup("BE");
		}
		break;
		case 6 :{//6==> "!="not equal
			TypeBR=strdup("BNE");
		}
		break;
	}

	quad(TypeBR,ToSTR(indq+3),cond1,cond2);
	quad("=","1","",res);
	quad("BR",ToSTR(indq+2),"","");
	quad("=","0","",res);
	
}


//creation d'1 quad logique
void createQuadL(int type, char *cond1, char *cond2, char *res){
	switch(type){
		case 1 :{//1==> not
			quad("BNZ",ToSTR(indq+3),cond1,"");
			quad("=","","1",res);
			quad("BR",ToSTR(indq+2),"","");
			quad("=","","0",res);
		}
		break;
		case 2 :{//2==> or
			quad("BNZ",ToSTR(indq+4),cond1,"");
			quad("BNZ",ToSTR(indq+3),cond2,"");
			quad("=","","0",res);
			quad("BR",ToSTR(indq+2),"","");
			quad("=","","1",res);
		}
		break;
		case 3 :{//3==> and
			quad("BZ",ToSTR(indq+4),cond1,"");
			quad("BZ",ToSTR(indq+3),cond2,"");
			quad("=","","1",res);
			quad("BR",ToSTR(indq+2),"","");
			quad("=","","0",res);
		}
		break;
	}
}

/************************ PARTIE OPTIMISATION ********************************/

// Fonction Optimisation qui effectue les 3 optimisation sur la table des quads
void optimisationQuad()
{  
    chekPropExpression(q);
	chekRedondanteExpression(q);
	chekPropCopie(q);
}

//Progabation expression
void chekPropExpression(quadruplet* q)
{
    int i=0;
    for (i=0;i<indq;i++)
    {
         if(q[i].opr[0]=='+' || q[i].opr[0]=='*' || q[i].opr[0]=='-' || q[i].opr[0]=='/'  )
        {
            int k=0;
            for(k=i+1;k<indq;k++)
            {
                if(strcmp(q[i].op2,q[k].res)==0 || strcmp(q[i].res,q[k].res)==0)
                    break;
                if(q[k].opr[0]=='=')
                {
                
                    if(strcmp(q[i].res,q[k].op1)==0)
                    {
                        q[i].res=strdup(q[k].res);
                        q[k].opr=strdup("");
                        q[k].op2=strdup("");
                        q[k].op1=strdup("");
                        q[k].res=strdup("");
                    }
                }
            }
        }
    }
}

//Supp Redondances d’expressions redondantes
void chekRedondanteExpression(quadruplet *q){
	int i,j,k;
    for (i=0;i<indq;i++)
    { 
            int k=0;
            for(k=i+1;k<indq;k++)
            { 

                if(VerifEgQuad(q[i],q[k])==1 && q[i].opr[0]!='B')
             { 
                     for(j=k;j<indq-1;j++){
                   q[j].opr=strdup(q[j+1].opr);
                   q[j].op1=strdup(q[j+1].op1);
                   q[j].op2=strdup(q[j+1].op2);
                   q[j].res=strdup(q[j+1].res);
                  }
                  indq--;
            }
            }
        }
		
    }

   int VerifEgQuad( quadruplet  q1, quadruplet  q2){
	   

      if((strcmp(q1.opr,q2.opr)==0)  && 
        (strcmp(q1.op1,q2.op1)==0) && 
        (strcmp(q1.op2,q2.op2)==0) &&
        (strcmp(q1.res,q2.res)==0) ) 
	  {
		 return 1;
      } 
	  else {
		  return 0;}

   }



//Propagation de copie
 
void chekPropCopie(quadruplet* q){
	int i=0;
    for (i=0;i<indq;i++)
    {
        if(q[i].opr[0]=='=')
        {
            int k=0;
            for(k=i+1;k<indq;k++)
            {
               if(strcmp(q[i].op1,q[k].res)==0 || strcmp(q[i].res,q[k].res)==0)
                    break;
                if(q[k].opr[0]=='+' || q[k].opr[0]=='*' || q[k].opr[0]=='-' || q[k].opr[0]=='/' )
                {
                    if(strcmp(q[i].res,q[k].op1)==0)
                    {
                        q[k].op1=strdup(q[i].op1);
                        q[i].opr=strdup("");
                        q[i].op1=strdup("");
                        q[i].op2=strdup("");
                        q[i].res=strdup("");
                    }
                    else if(strcmp(q[i].res,q[k].op2)==0)
                    {
                        q[k].op2=strdup(q[i].op1);
                        q[i].opr=strdup("");
                        q[i].op1=strdup("");
                        q[i].op2=strdup("");
                        q[i].res=strdup("");
                    }
                }
            }

        }

          
	}
}

void afficherQuadAfterOpt()
{ int i, nbQuad=0;
quad("","","","");
printf("\n::::::::::::::::::::::::::::::: Quadruplets :::::::::::::::::::::::::::::::::::\n");
for (i=0;i<indq;i++)
{  if((strcmp(q[i].opr,"" ) !=0) ){  //Ne pas afficher les quad vide (produits apres le processus d'optimisation)
    printf ("%d-( %s , %s , %s , %s )\n",i,q[i].opr,q[i].op1,q[i].op2,q[i].res);
    nbQuad++;
    }
}
printf("**** le nombre des quadruplets apres l'optimisation est : %d",nbQuad);
}







