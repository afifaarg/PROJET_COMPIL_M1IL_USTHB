#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "TS_RS.h"

// pour générer le code hashage
int hash(char *name){
    int lenght=strlen(name);
    int hash_value=0;
    int i=0;
    for( i; i<lenght; i++){
      hash_value+= name[i];
      hash_value=(hash_value * name[i])% taille;
    }
return hash_value;
}

//Initialisation de la table de hachage (Table des symboles)
void init_hash_table(){
    int i;
    for(i=0;i<taille;i++){
        TS[i]=NULL;

    }
  
}

//Initiisation de la table expression
void initTabExp(){
  
    int i;
    for(i=0;i<50;i++){
        TabExp[i]=NULL;
    } 
      cpTabExp=0;
}

// Recherche dans la table des symboles a partir du nom de l'idf
int recherche(char *name){
    int index = hash(name);
    elem *tmp = TS[index];
    while (tmp!=NULL && strcmp(tmp->NomEntite,name)!=0)
    {
        tmp=tmp->svt;
    }
	if(tmp==NULL) {return 0;} // 0 si n'existe pas 
	else{
		return 1; // 1 si existe
	}
     
}


// Function pour copier une chaine de charactere
char* copyString(char *s)
{
	char* s2;
	s2 = (char*)malloc(sizeof(s));
	strcpy(s2, s);
	return (char*)s2;
}

//Insertion d'un idf dans TabIdf 
void ajouter_idf(char* entite){
   Tabidf[cpTabidf] = copyString(entite);
        cpTabidf++; 
}


// Insertion du type d'un idf (dès sa déclaration)
void insererType(int Type){
    int i;
    for (i=0 ; i<cpTabidf;i++){
        int j = hash(Tabidf[i]);
        elem * p = TS[j];
    if(recherche(Tabidf[i])==1){
      if(!strcmp(p->NomEntite,Tabidf[i])) p->type=Type;
      else {
          p= p->svt; 
          while (p!=NULL && strcmp(p->NomEntite,Tabidf[i])) p=p->svt; 
          p->type=10;
      }
    }
}
 cpTabidf=0;
}


// insertion d'un idf dans la table des symboles dés sa déclaration + ça valeur si il est une constante
void inserer(char * NomEntite , char* CodeEntite, int Taille, char* SauvCst)
{
	int k= recherche(NomEntite);
	if(k==0){

	int index = hash(NomEntite);
	elem * p;
	p= (elem*) malloc( sizeof(elem));
	p->CodeEntite=CodeEntite;
	p->NomEntite=NomEntite;
    p->TailleEntite=Taille;	
    p->ConstanteEntite=SauvCst;
    p->ValeurEntite ="notSet";
	if (TS[index]==NULL) {p->svt=NULL; TS[index]=p;} // case vide donc insertion en premier  
   else {p->svt=TS[index]; TS[index]=p;}
	}

    }


//Insertion de la valeur d'une constante une foi affectée
void insererValeur(char * entite, char* ValEntite){
    elem* p= (elem*) malloc( sizeof(elem));
  if (recherche(entite)==1)
  {
   int index = hash(entite);
   p=TS[index];
   if (!strcmp(p->NomEntite,entite)){
       if(!strcmp(p->ConstanteEntite,"oui"))
       { p->ValeurEntite=copyString(ValEntite); }}
    else {
       p= p->svt; 
          while (p!=NULL && strcmp(p->NomEntite,entite)) p=p->svt; 
          p->ValeurEntite=copyString(ValEntite);
    }
  }
}

//Verrifier si le type TypExp est compatible avec entite (Gestion de la symentique)
int VerifType(char* entite, int TypExp){

    elem* p= (elem*) malloc( sizeof(elem));
  if (recherche(entite)==1)
  {
   int index = hash(entite);
   p=TS[index];
   if (!strcmp(p->NomEntite,entite)){
       if(p->type==TypExp) return 1;
       else return 0;
   }else {
       p= p->svt; 
          while (p!=NULL && strcmp(p->NomEntite,entite)) p=p->svt; 
         if(p->type==TypExp) return 1;
          else return 0;
    }

} else return -1;
}


//Verrifier si une constante est doublement initialisée
int DoubleAffectation( char * entite){
     elem* p= (elem*) malloc( sizeof(elem));
  if (recherche(entite)==1)
  {
   int index = hash(entite);
   p=TS[index];
   if (!strcmp(p->NomEntite,entite)){
       if(!strcmp(p->ConstanteEntite,"oui")){
           if(strcmp(p->ValeurEntite,"notSet")) return -1 ; // rahi set fiha une valeur 
           else return 1; // ma3endhesh une valeur 
       }
   }else {
       p= p->svt; 
          while (p!=NULL && strcmp(p->NomEntite,entite)) p=p->svt; 
       if(!strcmp(p->ConstanteEntite,"oui")){
           if(strcmp(p->ValeurEntite,"notSet")) return -1 ; // rahi set fiha une valeur 
           else return 1;
    }

}
}
}

// récuperer le type d'une entité 
int GetType(char* entite){
    elem* p= (elem*) malloc( sizeof(elem));
  if (recherche(entite)==1)
  {
   int index = hash(entite);
   p=TS[index];
   if (!strcmp(p->NomEntite,entite)){ 
      
         return p->type;
       }else {
       p= p->svt; 
          while (p!=NULL && strcmp(p->NomEntite,entite)) p=p->svt; 
      return p->type;
    }
}
}


// Verrifier la compatibilité des types dans une expression arithmetique
int VerifCompatibilite(){
    int i; int TypeExp=1;
    for(i=0;i<cpTabExp;i++){
      
        if((!strcmp(TabExp[i],"("))||(!strcmp(TabExp[i],")"))||(!strcmp(TabExp[i],"+"))||(!strcmp(TabExp[i],"-"))||(!strcmp(TabExp[i],"*")));
        else{
             if(!strcmp(TabExp[i],"/"))  { TypeExp = 4;}
                     if(GetType(TabExp[i])== 4) {TypeExp = 4;}
               }
        } 
    
    return TypeExp;
}

//Afficher la table des symboles 
void afficherTS ()
{
    printf("\n/****************** Table Des Symboles ******************/\n");
	printf("\t___________________________________________________________________________________________________________\n");
    printf("\t NomEntite        | CodeEntite  | TypeEntite    |  TailleEntitte   |    constante        |     ValeurEntite \n");
	printf("\t___________________________________________________________________________________________________________\n");
int i=0; elem*p; char * typeentite;
for (i=0;i<taille;i++)
{if (TS[i]!=NULL){p=TS[i]; 
				  while(p!=NULL) {
                      if(p->type == 1) typeentite = copyString("Entier");
                      if(p->type == 2) typeentite = copyString("Caractere");
                      if(p->type == 3) typeentite = copyString("String");
                      if(p->type == 4) typeentite = copyString("Reel");
                      if(p->type == 5) typeentite = copyString("Boolean");
                     
                  printf("\t|%14s  |%12s  |%14s |%16d  |%18s   |%20s\n",p->NomEntite,p->CodeEntite,typeentite,p->TailleEntite,p->ConstanteEntite, p->ValeurEntite);
									p=p->svt;
								 }
				 }
}
}


//Insertion d'une expression arithmetique dans la table TabExp
void InsererExp(char * elt){
  
     TabExp[cpTabExp] = copyString(elt);
        cpTabExp++; 
          
}




