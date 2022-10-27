

// t la taille de la table contenant les quadruplets
#define t 200

//indice pour parcourir la table des quadruplets

int indq;
// la structure d'un element de la table
typedef struct {char*opr;
				 char* op1;
				 char* op2;
				 char* res;}quadruplet;

//Structure d'une pile
typedef struct element_pile{
	char *donnee;
	struct element_pile *prc;
}pile;

pile *pile1,*pile2;
//declaration de la table				 
quadruplet q[t];

//Création des quadruplet + insertion dans la tableau de quadruplets
void quad(char *opt, char *opd1, char *opd2, char *res);

char* ToSTR(int i);

void afficherQuad();

//Verrification des conditions
void quadA(int type, char *cond1, char *cond2, char *res);


//creation d'1 quad logique
void createQuadL(int type, char *cond1, char *cond2, char *res);

//Creation quadruplet pour traitement conditionnel
void QuadIf(int SauvCondIndq, int SauvDebutElse, int SauvFinElse );


//empiler integer
void empiler_Int(pile **p,int donne);

//get first ele on the  pile
char* first(pile*p);

//depiler
char* depiler(pile**p);


//Progabation expression
void chekPropExpression(quadruplet* q);


//Supp Redondances d’expressions redondantes
void chekRedondanteExpression(quadruplet *q);


int VerifEgQuad( quadruplet  q1, quadruplet  q2);



//Propagation de copie
void chekPropCopie(quadruplet* q);


void optimisationQuad();



