#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CodeObj.h"


FILE *Assembly;
int Sauv_etiquette[100];
int pos=0;

void GenerateCodeObjet(elem * tableS[]){
	int i,condition;
	Assembly=fopen("CodeObjet.asm","w+");
	
	//NOm du programme
	fprintf(Assembly,"\nTITLE : %s\n",ProgName);
	
	//Pile declaration
	fprintf(Assembly,"\nPILE SEGMENT stack\n");
	fprintf(Assembly,"\t\t100 DD dup (?)\n");
	fprintf(Assembly,"PILE ENDS\n");

    //DATA SEGMENT
	fprintf(Assembly,"\nDATA SEGMENT\n");
	
       for(i=0;i<taille;i++){
         elem * parcourt =TS[i];
       while (parcourt!=NULL )
        {
            fprintf(Assembly,"\t%s ",parcourt->NomEntite);
         switch(parcourt->type)
			{    
                case 2:{/*char*/
					fprintf(Assembly,"DB ");
                    
				} break;    
				
				case 4:{ 	/*float*/
					fprintf(Assembly,"DD ");
				} break;
				
                case 1:{	/*INT*/
					fprintf(Assembly,"DW ");
				} break;

                 case 5:{	/*boolean*/
					fprintf(Assembly,"DT ");
				} break;

                 case 3:{	/*String*/
					fprintf(Assembly,"DT ");
				} break;
				default :{} break;
			}
			fprintf(Assembly,"\n ");
         parcourt=parcourt->svt;
        }
     }
	fprintf(Assembly,"DATA ENDS\n");
	    
//CODE SEGMENT
	    fprintf(Assembly,"\nCODE SEGMENT\n");
		fprintf(Assembly,"MAIN:\n");
		fprintf(Assembly,"\t\tASSUME SS: PILE, DS: DATA, CS: CODE\n");
		
				fprintf(Assembly,"\t\t\tMov AX,DATA\n");
				fprintf(Assembly,"\t\t\tMov DX,AX\n\n");
				
				GenerateFromQuad(q);
	
	    fprintf(Assembly,"CODE ENDS\n");
	    fprintf(Assembly,"END BEGIN\n");
		
	fclose(Assembly);
}

void GenerateFromQuad(quadruplet q[]){
	int k=0;
	for(k=0;k<indq;k++)
	{
		if(q[k].opr[0]=='B' ) {Sauv_etiquette[pos]=atoi(q[k].op1); pos++;}  
	}
	char * Operation = malloc(sizeof(char*));
    int i=0;
	for(i=0;i<indq;i++)
    {
		int j=0;
		for(j=0;j<pos;j++)
		{
			if(i==Sauv_etiquette[j]){ fprintf(Assembly,"etiq [ %d ] : \n",i);}
		}
		
        if(strcmp(q[i].opr,"+")==0 || strcmp(q[i].opr,"-")==0 || strcmp(q[i].opr,"*")==0 || strcmp(q[i].opr,"/")==0)
		{
			switch(q[i].opr[0])
			{
				case '+' : strcpy(Operation,"ADD"); 
						   break; 
				case '-' : strcpy(Operation,"SUB"); 
						   break;
				case '*' : strcpy(Operation,"MUL"); 
						   break;
				case '/' : strcpy(Operation,"DIV"); 
						   break;
			}
			if((q[i].op1[0]=='T') && (q[i].op2[0]=='T'))
			{
				fprintf(Assembly,"\t\t\tPOP AX\n");
				fprintf(Assembly,"\t\t\tPOP BX\n");
				fprintf(Assembly,"\t\t\t%s AX,BX\n",Operation);
				fprintf(Assembly,"\t\t\tPUSH AX\n");
			}
			else if(q[i].op1[0]=='T')
			{
				fprintf(Assembly,"\t\t\tPOP AX\n");
				fprintf(Assembly,"\t\t\t%s AX,%s\n",Operation,q[i].op2);
				fprintf(Assembly,"\t\t\tPUSH AX\n");
			}
			else if(q[i].op2[0]=='T')
			{
				fprintf(Assembly,"\t\t\tPOP AX\n");
				fprintf(Assembly,"\t\t\t%s AX,%s\n",Operation,q[i].op1);
				fprintf(Assembly,"\t\t\tPUSH AX\n");
			}
			else
			{
				fprintf(Assembly,"\t\t\tMOV AX,%s\n",q[i].op1);
				fprintf(Assembly,"\t\t\t%s AX,%s\n",Operation,q[i].op2);
				fprintf(Assembly,"\t\t\tPUSH AX\n");
			}
		}
		
		else if(q[i].opr[0]=='=')
			{
				if(q[i].op1[0]=='T')
				{
					fprintf(Assembly,"\t\t\tPOP AX\n");
					fprintf(Assembly,"\t\t\tMOV %s,AX\n",q[i].res);
				}
				else if(q[i].res[0]=='T')
				{
					fprintf(Assembly,"\t\t\tMOV AX,%s\n",q[i].op1);
					fprintf(Assembly,"\t\t\tPUSH AX\n");
				}
				else 
				{
					fprintf(Assembly,"\t\t\tMOV AX,%s\n",q[i].op1);
					fprintf(Assembly,"\t\t\tMOV %s,AX\n",q[i].res);
				}
			}
			else if( q[i].opr[0]=='B' && q[i].opr[1] != 'O') 
			{
				
				if(strcmp(q[i].opr,"BNE")==0 || strcmp(q[i].opr,"BNZ")==0)
				{
					strcpy(Operation,"JNE");
				} 
				else if (strcmp(q[i].opr,"BLE")==0)
				{
					strcpy(Operation,"JLE");
				}
				else if (strcmp(q[i].opr,"BGE")==0)
				{
					strcpy(Operation,"JGE");
				}
				else if(strcmp(q[i].opr,"BG")==0)
				{
					strcpy(Operation,"JG");
				}
				else if(strcmp(q[i].opr,"BL")==0)
				{
					strcpy(Operation,"JL");
				}
				else if(strcmp(q[i].opr,"BE")==0 || strcmp(q[i].opr,"BZ")==0 )
				{
					strcpy(Operation,"JE");
				}
				
				if(q[i].opr[1] != 'R')
				{
					if(strcmp(q[i].opr,"BZ")==0)
					{
						if(q[i].op2[0]=='T') fprintf(Assembly,"\t\t\tPOP AX\n");
						else fprintf(Assembly,"\t\t\tMOV AX,%s\n",q[i].op2);
						
						fprintf(Assembly,"\t\t\t CMP AX,0\n"); // compare  AX to 0
						fprintf(Assembly,"\t\t\t %s etiq[ %s ]\n",Operation,q[i].op1);
					}
					else if(strcmp(q[i].opr,"BNZ")==0)
					{
						if(q[i].op2[0]=='T') fprintf(Assembly,"\t\t\tPOP AX\n");
						else fprintf(Assembly,"\t\t\tMOV AX,%s\n",q[i].op2);
						
						fprintf(Assembly,"\t\t\tCMP AX,0\n");
						fprintf(Assembly,"\t\t\t%s etiq[ %s ]\n",Operation,q[i].op1);
					}
					else 
					{
						if(q[i].op2[0]=='T') fprintf(Assembly,"\t\t\tPOP AX\n");
						else fprintf(Assembly,"\t\t\tMOV AX,%s\n",q[i].op2);

						if(q[i].res[0]=='T') fprintf(Assembly,"\t\t\tPOP BX\n");
						else fprintf(Assembly,"\t\t\tMOV BX,%s\n",q[i].res);

						
						fprintf(Assembly,"\t\t\tCMP AX,BX\n");
						fprintf(Assembly,"\t\t\t%s etiq[ %s ]\n",Operation,q[i].op1);
					}
					

				}
				else 
				{
					fprintf(Assembly,"\t\t\tJMP etiq[ %s ]\n",q[i].op1);
				}
			}
	}

}
