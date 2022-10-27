
//taille de la table des symboles
#define taille 1000003

//Structure d'un élèment de la table des symboles
typedef struct elt{
				char* NomEntite;
				int type;
                char* CodeEntite;
                char* ConstanteEntite;
                char* ValeurEntite;
                int TailleEntite;
				struct elt* svt;
				}elem;

//Déclaration de la table de symboles 
elem * TS[taille];

char * Tabidf[50];// tableau conetenant les idfs déclarés dans la meme ligne dans le language
int  cpTabidf;// Compteur pour parcourir Tabidf

char * TabExp[50]; // tableau d'expression
int cpTabExp; // Compteur pour parcourir TabExp

char* ProgName; //Le nom du programe pour le récupérer dans la phase de la génération du code objet 

int hash(char *name); //Fonction hash pour générer le code hashage

void init_hash_table(); //Initialisation de la table des symboles


void initTabExp(); ////Initiisation de la table expression

int recherche(char *name);// Recherche dans la table des symboles a partir du nom de l'idf

char* copyString(char *s);// Function pour copier une chaine de charactere

void ajouter_idf(char* entite);//Insertion d'un idf dans TabIdf 

void insererType(int Type);// Insertion du type d'un idf (dès sa déclaration)

void inserer(char * NomEntite , char* CodeEntite, int Taille, char* SauvCst); // insertion d'un idf dans la table des symboles dés sa déclaration + ça valeur si il est une constante

void insererValeur(char * entite, char* ValEntite);//Insertion de la valeur d'une constante une foi affectée

int VerifType(char* entite, int TypExp);//Verrifier si le type TypExp est compatible avec entite (Gestion de la symentique)

int DoubleAffectation( char * entite);//Verrifier si une constante est doublement initialisée

int GetType(char* entite);// récuperer le type d'une entité 

int VerifCompatibilite();// Verrifier la compatibilité des types dans une expression arithmetique

void afficherTS(); //Afficher la table des symboles 



void InsererExp(char * elt);//Insertion d'une expression arithmetique dans la table TabExp


