#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "StructuresProjet.h"
#include "prototypesFonctions.h"


int main (){
system("color 60");
EnTete();
MenuPrincipal();
 return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*                                      DEFINITION DES FONCTIONS UTILISEES POUR CE PROJET                                             */
/*------------------------------------------------------------------------------------------------------------------------------------*/

void EnTete()
{
	system("cls");
	char heure[30],date[30];

    _strtime( heure );                      // cette fonction je l'ai trouvé sur le web ms j'ai essayé de la comprendre
    _strdate( date );                       // on a inclus la bibliotheque <time.h> qui nous permet de controller la date et l'heure sur
                                            // nos machines grace au fonction strtime et strdate les symoboles utilisee sont tous dechifre par le code ASCII
	printf("\xc9");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd");
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");

    printf("\xbb");

	printf("\n\xba %s \xba       AGENCE DE LOCATION DES VOITURES Hajar Oubihi 	   \xba %s \xba\n",heure,date);

    printf("\xc8");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
	printf("\xbc");

	printf("\n\n");

}
/*------------------------------------------------FONCTION DE MENU PRINCIPALE --------------------------------------------------------------------------------------*/
void MenuPrincipal()
{
	int choix;

	EnTete();

	printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                               \xb3 Menu Principale \xb3");
	printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

	printf("\n\n");

	printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n               \xba                                              \xba");
	printf("\n               \xba    Location..............................1   \xba");
	printf("\n               \xba    Gestion voitures......................2   \xba");
	printf("\n               \xba    Gestion clients.......................3   \xba");
	printf("\n               \xba    Quitter...............................4   \xba");
	printf("\n               \xba                                              \xba");
	printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	printf("\n\n                                Votre choix  :  ");

	scanf("%d",&choix);

    switch(choix){

      case 1: MenuLocation(); break;           // Cette fonction est de type void elle permet au utilisateur du choisir
      case 2: MenuGestionVoiture(); break;     // l'option au plutot le menu désirer a savoir la gestion des client,
      case 3: MenuGestionClient(); break;      // la gestion des voitures ou la location d'un voiture
      case 4: break;
      default: exit(1);
    }

}
/*--------------------------------------------------------MENU LOCATION VOITURE ET SES SOUS FONCTIONS----------------------------------------------------------------------------------------------*/

void visualiserContrat(char *fichierContrat,float numCn){
contrat *A=(contrat*)malloc(sizeof(contrat));
FILE *ouvre=fopen(fichierContrat,"r");
 if(ouvre!=NULL){
   while(!feof(ouvre)){
     fscanf(ouvre,"%f %d %d %d/%d/%d %d/%d/%d %d",&A->numContrat,&A->idVoiture,&A->idClient,&A->debut.jour,&A->debut.mois,&A->debut.annee,&A->fin.jour,&A->fin.mois,&A->fin.annee,&A->Cout);
     if(A->numContrat==numCn){
        printf("\nNUM_CONTRAT: %.4f  ID_VOITURE: %d  ID_CLIENT: %d  DEBUT: %d/%d/%d  FIN: %d/%d/%d  COUT: %d\n\n",A->numContrat,A->idVoiture,A->idClient,A->debut.jour,A->debut.mois,A->debut.annee,A->fin.jour,A->fin.mois,A->fin.annee,A->Cout);
        break;
     }
   }
  }
 free(A);               // Cette fonction est de type void prend en parametre le nom du fichier des contrats (char*) et
 fclose(ouvre);         // le numero de contrat a afficher apres elle assure l'affichage du ce contrat choisi.
 ouvre=NULL;            // elle affiche un contrat a la fois et non pas tous les contrat du fichier "listeCnt.txt"
 system("pause");
 MenuLocation();
}


int verifierClient(char *fichierClient,int Cin){

FILE *ouvre=fopen(fichierClient,"r");
client *A=(client*)malloc(sizeof(client));  // Cette fonction est de type int ( entier) elle prend en parametre le Cin
int aide;                                   // (Numero de carte national qui est unique bien sur ) apres elle se charge de
                                            // verifier si le client est deja enregistre dans l'archive ou non
 if(ouvre!=NULL){                           // Sinon en lui ajoute en fin la fonction retourne le idClient qu'on a donné au client
   while(!feof(ouvre)){
       fscanf(ouvre,"%d %s %s %d %s %d",&A->idClient,A->nom,A->prenom,&A->Cin,A->adresse,&A->telephone);
     if(A->Cin==Cin){
        printf("\n\n\t\t\t\tCLIENT DEJA ENREGISTRE VOICI SES DONNEES !!\n\n");
        printf("\nID_CLIENT:%d\tNOM:%s\tPRENOM:%s\tCIN:%d\tADRESSE:%s\t\tTELEPHONE:0%d\n\n\n",A->idClient,A->nom,A->prenom,A->Cin,A->adresse,A->telephone);
        system("pause");
        return A->idClient;
      }
     }
    }
   fclose(ouvre);

     printf("\n\n\t\t\t\tCE CLIENT EST NON ENREGISTRE VEUILLEZ LUI AJOUTER !!\n\n");

          printf("ID_CLIENT:        \t");       scanf("%d",&A->idClient);
          printf("NOM_DU_CLIENT:    \t");       scanf("%s",A->nom);
          printf("PRENOM_DU_CLIENT: \t");       scanf("%s",A->prenom);
          printf("ADRESSE_DU_CLIENT:\t");       scanf("%s",A->adresse);
          printf("TELEPHONE:        \t");       scanf("%d",&A->telephone);

    ouvre=fopen(fichierClient,"a");
    fprintf(ouvre,"\n%d %s %s %d %s %d",A->idClient,A->nom,A->prenom,Cin,A->adresse,A->telephone);
    fclose(ouvre);
    ouvre=NULL;
    aide=A->idClient;
    free(A);
    printf("\n\n\t\t\tCLIENT EST ENREGISTRE MAINTENANT !!\n\n\n");
    system("pause");
    return aide;
}


void voitureDisponile(char *fichierVoiture){
 voiture *A=(voiture*)malloc(sizeof(voiture));
 FILE *ouvre=fopen(fichierVoiture,"r");
 if(ouvre!=NULL){
   while(!feof(ouvre)){
    fscanf(ouvre,"%d %s %s %s %d %d %s",&A->idVoiture,A->marque,A->nomVoiture,A->couleur,&A->nbplaces,&A->prixJour,A->EnLocation);
    if(strcmp(A->EnLocation,"Non")==0){
      printf("\nID_VOITURE:%d\tMARQUE:%s\tNOM:%s\tCOULEUR:%s\tPLACES:%d\tPRIX:%d  EN_LOCATION?? %s\n\n",A->idVoiture,A->marque,A->nomVoiture,A->couleur,A->nbplaces,A->prixJour,A->EnLocation);
    }
   }
  }                 // Cette fonction est de type void elle prend en argument le nom du fichier de voitures et apres
   free(A);         // elle affiche tous les voitures disponible a la location (enLocation=Non) pour le nouveau client
   fclose(ouvre);
   ouvre=NULL;
}


void enLocation(char *fichierVoiture,int reservee,char *valeur){
int i=0,j;
FILE *ouvre=fopen(fichierVoiture,"r");
voiture *A=(voiture*)malloc(sizeof(voiture));

    if(ouvre!=NULL) {
      while(!feof(ouvre)){
            fscanf(ouvre,"%d %s %s %s %d %d %s",&(A+i)->idVoiture,(A+i)->marque,(A+i)->nomVoiture,(A+i)->couleur,&(A+i)->nbplaces,&(A+i)->prixJour,(A+i)->EnLocation);
            A=realloc(A,(i+2)*sizeof(voiture));
            i++;
         }
      }                                // Cette fonction est de type void elle prend en parametre le nom du fichier voitures
      fclose(ouvre);                   // et le idVoiture de la voiture dont elle cherche a modifier son attribut enLocation
     ouvre=fopen(fichierVoiture,"w+"); // soit en Oui soit en Non (determiner en argument valeur) selon le besoin
     for(j=0;j<i;j++){                 // oui en location de voiture, non en retour de voiture
        if((A+j)->idVoiture==reservee){
           strcpy((A+j)->EnLocation,valeur);
            }
         fprintf(ouvre,"\n%d %s %s %s %d %d %s",(A+j)->idVoiture,(A+j)->marque,(A+j)->nomVoiture,(A+j)->couleur,(A+j)->nbplaces,(A+j)->prixJour,(A+j)->EnLocation);
        }
        free(A);
        fclose(ouvre);
        ouvre=NULL;
 }


void louerVoiture(char *fichierContrat){

int Cin,aide;
contrat *A=(contrat*)malloc(sizeof(contrat));
FILE *ouvre=fopen(fichierContrat,"a");

 printf("\n\n\t\t\t[VERIFICATI0ON DU CLIENT]\n\n");
     printf("SAISIR LE CIN DU CLIENT  :\t");       scanf("%d",&Cin);       aide=verifierClient("listeCl.txt",Cin);
 printf("\n\n\t\t\t\tVOILA LA LISTE DES VOITURES DISPONIBLE POUR LA LOCATION \n\n");
 voitureDisponile("listeV.txt");
 printf("\nTAPER ID DE LA VOITURE DISIREE :\t");    scanf("%d",&A->idVoiture);     enLocation("listeV.txt",A->idVoiture,"Oui");
 printf("\nDATE DE DEBUT DE CONTRAT :\n");
     printf("JOUR :\t");   scanf("%d",&A->debut.jour);
     printf("MOIS :\t");    scanf("%d",&A->debut.mois);
     printf("ANNEE :\t");    scanf("%d",&A->debut.annee);
 printf("\nDATE DE FIN DE CONTRAT :\n");
     printf("JOUR :\t");   scanf("%d",&A->fin.jour);
     printf("MOIS :\t");    scanf("%d",&A->fin.mois);
     printf("ANNEE :\t");    scanf("%d",&A->fin.annee);
 printf("\nLE COUT EN DIRHAM :\t");      scanf("%d",&A->Cout);
 printf("\nDONNER UN NUMERO POUR CE CONTRAT :\t");  scanf("%f",&A->numContrat);

 fprintf(ouvre,"%f %d %d %d/%d/%d %d/%d/%d %d\n",A->numContrat,A->idVoiture,aide,A->debut.jour,A->debut.mois,A->debut.annee,A->fin.jour,A->fin.mois,A->fin.annee,A->Cout);

   fclose(ouvre); // Cette fonction est de type void elle prend en parametre le nom du fichier de contrats apres
   ouvre=NULL;    // elle permet de creer un contrat et l'enregistrer sur le fichier precedemment mentionne en modifiant
   free(A);       // l'attribus enLocation du voiture choisi de Non a Oui
   MenuLocation();
}


void retournerVoiture(char *fichierContrat,float numSup){
int i=0,j;
FILE *ouvre=fopen(fichierContrat,"r");
contrat *A=(contrat*)malloc(sizeof(contrat));

    if(ouvre!=NULL) {
      while(!feof(ouvre)){
            fscanf(ouvre,"%f %d %d %d/%d/%d %d/%d/%d %d",&(A+i)->numContrat,&(A+i)->idVoiture,&(A+i)->idClient,&(A+i)->debut.jour,&(A+i)->debut.mois,&(A+i)->debut.annee,&(A+i)->fin.jour,&(A+i)->fin.mois,&(A+i)->fin.annee,&(A+i)->Cout);
            A=realloc(A,(i+2)*sizeof(contrat));
            i++;
         }
      }                                  // cette fonction est de type void elle prend en parametre le fichier des contrats
      fclose(ouvre);                     // et le numero du contrat terminee avec but pour rechanger l'attribut de celle-ci
     ouvre=fopen(fichierContrat,"w+");   // cette fois ci en Non
     for(j=0;j<i;j++){
            if((A+j)->numContrat==numSup) {
              enLocation("listeV.txt",(A+j)->idVoiture,"Non");
            }
           else{
           fprintf(ouvre,"\n%.4f %d %d %d/%d/%d %d/%d/%d %d",(A+j)->numContrat,(A+j)->idVoiture,(A+j)->idClient,(A+j)->debut.jour,(A+j)->debut.mois,(A+j)->debut.annee,(A+j)->fin.jour,(A+j)->fin.mois,(A+j)->fin.annee,(A+j)->Cout);
          }
       }
    printf("\n\tLA VOITURE EST DISPONIBLE POUR UN NOUVEAU LOCATAIRE :)\n\n\n");
        system("pause");
        free(A);
        fclose(ouvre);
        ouvre=NULL;
        MenuLocation();

}

void modifierContrat(char *fichierContrat,float numMdf){

int i=0,j;
FILE *ouvre=fopen(fichierContrat,"r");
contrat *A=(contrat*)malloc(sizeof(contrat));

    if(ouvre!=NULL) {
      while(!feof(ouvre)){
            fscanf(ouvre,"%f %d %d %d/%d/%d %d/%d/%d %d",&(A+i)->numContrat,&(A+i)->idVoiture,&(A+i)->idClient,&(A+i)->debut.jour,&(A+i)->debut.mois,&(A+i)->debut.annee,&(A+i)->fin.jour,&(A+i)->fin.mois,&(A+i)->fin.annee,&(A+i)->Cout);
            A=realloc(A,(i+2)*sizeof(contrat));
            i++;
         }
      }                                  // cette fonction permet d'effectuer certains changements sur un contrat enregistre
      fclose(ouvre);                     // dans le fichier des contrats dont le nom est passe en parametre, en precisant
     ouvre=fopen(fichierContrat,"w+");   // a la fonction le numero du contrat cible.
     for(j=0;j<i;j++){
            if((A+j)->numContrat==numMdf){
              printf("\nMODIFICATION DE CONTRAT N^:  %.4f\n\n",numMdf);

                printf("NUM_CONTRAT: \t");        scanf("%f",&(A+j)->numContrat);
                printf("ID_VOITURE:  \t");        scanf("%d",&(A+j)->idVoiture);
                printf("ID_CLIENT:   \t");        scanf("%d",&(A+j)->idClient);
                printf("DATE_FIN:    \n");
                   printf("JOUR: \t");    scanf("%d",&(A+j)->fin.jour);
                   printf("MOIS: \t");    scanf("%d",&(A+j)->fin.mois);
                   printf("Annee:\t");    scanf("%d",&(A+j)->fin.annee);

                printf("COUT:        \t");        scanf("%d",&(A+j)->Cout);
            }
         fprintf(ouvre,"\n%.4f %d %d %d/%d/%d %d/%d/%d %d",(A+j)->numContrat,(A+j)->idVoiture,(A+j)->idClient,(A+j)->debut.jour,(A+j)->debut.mois,(A+j)->debut.annee,(A+j)->fin.jour,(A+j)->fin.mois,(A+j)->fin.annee,(A+j)->Cout);
        }
        free(A);
        fclose(ouvre);
        ouvre=NULL;
        MenuLocation();
 }


 void MenuLocation()
{
	int choix;                  // c'est un simple menu du choix d'option a effectuer dans le menu de location
	float numCn,numMdf,numSup;

	EnTete();

	printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                               \xb3 Location voiture\xb3");
	printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

	printf("\n\n");

	printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n               \xba                                              \xba");
	printf("\n               \xba    Visualiser contrat....................1   \xba");
	printf("\n               \xba    Louer voiture.........................2   \xba");
	printf("\n               \xba    Retourner voiture.....................3   \xba");
	printf("\n               \xba    Modifier contrat......................4   \xba");
	printf("\n               \xba    Retour................................5   \xba");
	printf("\n               \xba                                              \xba");
	printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	printf("\n\n                                Votre choix  :  ");


	scanf("%d",&choix);
	switch(choix){
      case 1: printf("\nNUM_CONTRAT: \t");                 scanf("%f",&numCn);           visualiserContrat("listeCnt.txt",numCn);   break;
      case 2: louerVoiture("listeCnt.txt");  break;
      case 3: printf("NUM_CONTRAT_TERMINE: \t");           scanf("%f",&numSup);          retournerVoiture("listeCnt.txt",numSup);   break;
      case 4: printf("\nNUM_CONTRAT_A_MODIFIER: \t");      scanf("%f",&numMdf);          modifierContrat("listeCnt.txt",numMdf);    break;
      case 5: MenuPrincipal(); break;
      default: exit(1);
	}

}
/*------------------------------------------------------------MENU GESTION DES VOITURES ET SES SOUS FONCTIONS------------------------------------------------------------------------------------------------------------*/

void listeDesVoitures(char *fichierVoiture){
 voiture *A=(voiture*)malloc(sizeof(voiture));
 FILE *ouvre=fopen(fichierVoiture,"r");
 if(ouvre!=NULL){
   while(!feof(ouvre)){
    fscanf(ouvre,"%d %s %s %s %d %d %s",&A->idVoiture,A->marque,A->nomVoiture,A->couleur,&A->nbplaces,&A->prixJour,A->EnLocation);
    printf("\nID_VOITURE:%d\tMARQUE:%s\tNOM:%s\tCOULEUR:%s\tPLACES:%d\tPRIX:%d  EN_LOCATION?? %s\n\n",A->idVoiture,A->marque,A->nomVoiture,A->couleur,A->nbplaces,A->prixJour,A->EnLocation);
   }
  }
   free(A);
   fclose(ouvre);              //Cette fonction est de type void elle prend en parametre le nom du fichier des voitures
   ouvre=NULL;                 // et elle l'affiche ( Afficher les voitures dedant)
   system("pause");
   MenuGestionVoiture();
}

void ajouterVoiture(char *fichierVoiture) {
 voiture *B=(voiture*)malloc(sizeof(voiture));
 FILE *ouvre=fopen(fichierVoiture,"a");

 if(ouvre!=NULL){
    printf("ID_VOITURE:      \t");      scanf("%d",&B->idVoiture);
    printf("MARQUE_VOITURE:  \t");      scanf("%s",B->marque);
    printf("NOM_VOITURE:     \t");      scanf("%s",B->nomVoiture);
    printf("COULEUR_VOITURE: \t");      scanf("%s",B->couleur);
    printf("PLACES_ASSUREES: \t");      scanf("%d",&B->nbplaces);
    printf("PRIX_DE_LOCATION:\t");      scanf("%d",&B->prixJour);

 }
  fprintf(ouvre,"\n%d %s %s %s %d %d %s",B->idVoiture,B->marque,B->nomVoiture,B->couleur,B->nbplaces,B->prixJour,"Non");
  free(B);
  fclose(ouvre);      // Tout simplement cette fonction permet d'ajouter une nouvelle voiture au fichier des voitures
  ouvre=NULL;
  MenuGestionVoiture();
}

void supprimerVoiture(char *fichierVoiture,int idSupp){
int i=0,j;
FILE *ouvre=fopen(fichierVoiture,"r");
voiture *A=(voiture*)malloc(sizeof(voiture));

    if(ouvre!=NULL) {
      while(!feof(ouvre)){
            fscanf(ouvre,"%d %s %s %s %d %d %s",&(A+i)->idVoiture,(A+i)->marque,(A+i)->nomVoiture,(A+i)->couleur,&(A+i)->nbplaces,&(A+i)->prixJour,(A+i)->EnLocation);
            A=realloc(A,(i+2)*sizeof(voiture));
            i++;
         }
      }                               // Supprimant une voiture du fichier des voiture, le principe est simple en coupe toutes
      fclose(ouvre);                  // les donnees du fichiers dans un tableau possede le meme type des donnes coupees apres en
     ouvre=fopen(fichierVoiture,"w+");// resaisir ses donnees dans le meme fichier sauf celle preCiser (fesant un test)
     for(j=0;j<i;j++){
            if((A+j)->idVoiture!=idSupp){
           fprintf(ouvre,"\n%d %s %s %s %d %d %s",(A+j)->idVoiture,(A+j)->marque,(A+j)->nomVoiture,(A+j)->couleur,(A+j)->nbplaces,(A+j)->prixJour,(A+j)->EnLocation);
         }
       }
        free(A);
        fclose(ouvre);
        ouvre=NULL;
        MenuGestionVoiture();
 }

void modifierVoiture(char *fichierVoiture,int idMdf){
int i=0,j;
FILE *ouvre=fopen(fichierVoiture,"r");
voiture *A=(voiture*)malloc(sizeof(voiture));  // Mofification d'une voiture

    if(ouvre!=NULL) {
      while(!feof(ouvre)){
            fscanf(ouvre,"%d %s %s %s %d %d %s",&(A+i)->idVoiture,(A+i)->marque,(A+i)->nomVoiture,(A+i)->couleur,&(A+i)->nbplaces,&(A+i)->prixJour,(A+i)->EnLocation);
            A=realloc(A,(i+2)*sizeof(voiture));
            i++;
         }
      }
      fclose(ouvre);

     ouvre=fopen(fichierVoiture,"w+");
     for(j=0;j<i;j++){
        if((A+j)->idVoiture==idMdf){
            printf("\nMODIFICATION DES DONNEES DE LA VOITURE_[ID:%d]_:\n\n",idMdf);

                printf("ID_VOITURE:      \t");           scanf("%d",&(A+j)->idVoiture);
                printf("COULEUR:         \t");           scanf("%s",(A+j)->couleur);
                printf("PLACES_ASSUREES: \t");           scanf("%d",&(A+j)->nbplaces);
                printf("PRIX_DE_LOCATION:\t");           scanf("%d",&(A+j)->prixJour);
                printf("EN_LOCATION??    \t");           scanf("%s",(A+j)->EnLocation);
            }
         fprintf(ouvre,"\n%d %s %s %s %d %d %s",(A+j)->idVoiture,(A+j)->marque,(A+j)->nomVoiture,(A+j)->couleur,(A+j)->nbplaces,(A+j)->prixJour,(A+j)->EnLocation);
        }
        free(A);
        fclose(ouvre);
        ouvre=NULL;
        MenuGestionVoiture();
 }

 void MenuGestionVoiture()
{
	int choix,idSupp,idMdf;

	EnTete();

	printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                               \xb3 Gestion voiture \xb3");
	printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

	printf("\n\n");

	printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n               \xba                                              \xba");
	printf("\n               \xba    Liste des voiture.....................1   \xba");
	printf("\n               \xba    Ajouter voiture.......................2   \xba");
	printf("\n               \xba    Modifier voiture......................3   \xba");
	printf("\n               \xba    Supprimer voiture.....................4   \xba");
	printf("\n               \xba    Retour................................5   \xba");
	printf("\n               \xba                                              \xba");
	printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	printf("\n\n                                Votre choix  :  ");

	scanf("%d",&choix);
    switch(choix){
        case 1: listeDesVoitures("listeV.txt"); break;
        case 2: ajouterVoiture("listeV.txt"); break;
        case 3: printf("\nID_VOITURE_A_MODIFIER: \t"); scanf("%d",&idMdf); modifierVoiture("listeV.txt",idMdf); break;
        case 4: printf("\nID_VOITURE_A_SUPPRIMER: \t"); scanf("%d",&idSupp); supprimerVoiture("listeV.txt",idSupp); break;
        case 5: MenuPrincipal(); break;
        default: exit(1);
      }

}
/*----------------------------------------------------------MENU GESTION DES CLIENTS ET SES SOUS FONCTIONS-------------------------------------------------------------------------------------------------------------*/

void listeDesClients(char *fichierClient){
 client *A=(client*)malloc(sizeof(client));
 FILE *ouvre=fopen(fichierClient,"r");
 if(ouvre!=NULL){
   while(!feof(ouvre)){
    fscanf(ouvre,"%d %s %s %d %s %d",&A->idClient,A->nom,A->prenom,&A->Cin,A->adresse,&A->telephone);
    printf("\nID_CLIENT:%d\tNOM:%s\tPRENOM:%s\tCIN:%d\tADRESSE:%s\t\tTELEPHONE:0%d\n\n",A->idClient,A->nom,A->prenom,A->Cin,A->adresse,A->telephone);
   }
  }
   free(A);
   fclose(ouvre);              // affichage des client enregistres dans le fichier des clients ( listeCl.txt ) meme principe du la fonction d'affichage
   ouvre=NULL;                 // des voiture,type void et prend en parametre le nom du fichier des clients
   system("pause");
   MenuGestionClient();
}

void ajouterClient(char *fichierClient) {
 client *B=(client*)malloc(sizeof(client));
 FILE *ouvre=fopen(fichierClient,"a");
 if(ouvre!=NULL){
    printf("ID_CLIENT:        \t");       scanf("%d",&B->idClient);
    printf("NOM_DU_CLIENT:    \t");       scanf("%s",B->nom);
    printf("PRENOM_DU_CLIENT: \t");       scanf("%s",B->prenom);
    printf("CIN_DU_CLIENT:    \t");       scanf("%d",&B->Cin);
    printf("ADRESSE_DU_CLIENT:\t");       scanf("%s",B->adresse);
    printf("TELEPHONE:        \t");       scanf("%d",&B->telephone);
 }
  fprintf(ouvre,"\n%d %s %s %d %s 0%d",B->idClient,B->nom,B->prenom,B->Cin,B->adresse,B->telephone);
  free(B);
  fclose(ouvre);
  ouvre=NULL;
  MenuGestionClient();
}

 void supprimerClient(char *fichierClient,int idSupp){

int i=0,j;
FILE *ouvre=fopen(fichierClient,"r");
client *A=(client*)malloc(sizeof(client));

    if(ouvre!=NULL) {
      while(!feof(ouvre)){
            fscanf(ouvre,"%d %s %s %d %s %d",&(A+i)->idClient,(A+i)->nom,(A+i)->prenom,&(A+i)->Cin,(A+i)->adresse,&(A+i)->telephone);
            A=realloc(A,(i+2)*sizeof(client));
            i++;
         }
      }
      fclose(ouvre);

     ouvre=fopen(fichierClient,"w+");
     for(j=0;j<i;j++){
            if((A+j)->idClient!=idSupp){
           fprintf(ouvre,"\n%d %s %s %d %s %d",(A+j)->idClient,(A+j)->nom,(A+j)->prenom,(A+j)->Cin,(A+j)->adresse,(A+j)->telephone);
         }
       }
        fclose(ouvre);
        free(A);
        ouvre=NULL;
        MenuGestionClient();
 }

void modifierClient(char *fichierClient,int idMdf){
int i=0,j;
FILE *ouvre=fopen(fichierClient,"r");
client *A=(client*)malloc(sizeof(client));

    if(ouvre!=NULL) {
      while(!feof(ouvre)){
            fscanf(ouvre,"%d %s %s %d %s %d",&(A+i)->idClient,(A+i)->nom,(A+i)->prenom,&(A+i)->Cin,(A+i)->adresse,&(A+i)->telephone);
            A=realloc(A,(i+2)*sizeof(client));
            i++;
         }
      }
      fclose(ouvre);

     ouvre=fopen(fichierClient,"w+");
     for(j=0;j<i;j++){
            if((A+j)->idClient==idMdf){
              printf("\nMODIFICATION DES DONNEES DU CLIENT_[ID:%d]_:\n\n",idMdf);

                printf("ID_CLIENT: \t");             scanf("%d",&(A+j)->idClient);
                printf("NOM:       \t");             scanf("%s",(A+j)->nom);
                printf("PRENOM:    \t");             scanf("%s",(A+j)->prenom);
                printf("CIN:       \t");             scanf("%d",&(A+j)->Cin);
                printf("ADRESSE:   \t");             scanf("%s",(A+j)->adresse);
                printf("TELEPHONE: \t");             scanf("%d",&(A+j)->telephone);
            }
         fprintf(ouvre,"\n%d %s %s %d %s 0%d",(A+j)->idClient,(A+j)->nom,(A+j)->prenom,(A+j)->Cin,(A+j)->adresse,(A+j)->telephone);
        }
        free(A);
        fclose(ouvre);
        ouvre=NULL;
        MenuGestionClient();
 }

void MenuGestionClient()
{
	int choix,idSupp,idMdf;

	EnTete();

	printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                               \xb3 Gestion client  \xb3");
	printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

	printf("\n\n");

	printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n               \xba                                              \xba");
	printf("\n               \xba    Liste des client......................1   \xba");
	printf("\n               \xba    Ajouter client........................2   \xba");
	printf("\n               \xba    Modifier client.......................3   \xba");
	printf("\n               \xba    Supprimer client......................4   \xba");
	printf("\n               \xba    Retour................................5   \xba");
	printf("\n               \xba                                              \xba");
	printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	printf("\n\n                                Votre choix  :  ");

     scanf("%d",&choix);
        switch(choix){
        case 1: listeDesClients("listeCl.txt"); break;
        case 2: ajouterClient("listeCl.txt"); break;
        case 3: printf("\nID_CLIENT_A_MODIFIER: \t"); scanf("%d",&idMdf);  modifierClient("listeCl.txt",idMdf);  break;
        case 4: printf("\nID_CLIENT_A_SUPPRIMER: \t");  scanf("%d",&idSupp); supprimerClient("listeCl.txt",idSupp); break;
        case 5: MenuPrincipal(); break;
        default: exit(1);
        }
}

/*------------------------------------------------------------------------FIN-----------------------------------------------------------------------------------*/
