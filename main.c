
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 struct Tache{
    int id;
    char titre[100];
    char description[200];
    char deadline[20];
    char statut[20];
};
 struct Tache nouvelleTaches[100];
struct Tache temp;
int nbrdeTaches=0;
int afaire = 0 , encours = 0 , finalisee = 0;
int vari = 0;
int num;

// ajouter un nouvelle tache
ajouteruntache(){
   nouvelleTaches[nbrdeTaches].id=nbrdeTaches+1+vari;
    printf("ajouter une nouvelle tache %d\n",nouvelleTaches[nbrdeTaches].id);
    printf("    -titre:\n");
    scanf("%s",nouvelleTaches[nbrdeTaches].titre);
    printf("    -description:\n");
    scanf(" %[^\n]s",nouvelleTaches[nbrdeTaches].description);
    printf("    -deadline ex:(YYYY/MM/DD):\n");
    scanf("%s",nouvelleTaches[nbrdeTaches].deadline);
    printf("    -statut:\n");
    int souschoix ;
             printf("1.. A FAIRE\n");
            printf("2.. EN COURS\n");
            printf("3.. FINALISEE\n");
            scanf("%d",&souschoix);
        switch (souschoix) {
            case 1:
                printf("-->A FAIRE\n");
                strcpy(nouvelleTaches[nbrdeTaches].statut,"aFaire" );
                afaire++;
                break;
            case 2:
                printf("-->EN COURS\n");
                strcpy(nouvelleTaches[nbrdeTaches].statut,"EnCours" );
                encours++;
                break;
            case 3:
                printf("-->FINALISEE\n");
                strcpy(nouvelleTaches[nbrdeTaches].statut,"Finalisee" );
                finalisee++;
                break;
                default:
                strcpy(nouvelleTaches[nbrdeTaches].statut,"aFaire" );
                break;
        }
    nbrdeTaches++;
}
// afficher les taches
afficherTaches(){
    int i;
    for(i=1;i<=nbrdeTaches;i++){
        printf("id:%d\n",nouvelleTaches[i].id);
        printf("titre:%s\n",nouvelleTaches[i].titre);
        printf("description:%s\n",nouvelleTaches[i].description);
        printf("deadline:%s\n",nouvelleTaches[i].deadline);
        printf("statut:%s\n",nouvelleTaches[i].statut);
        printf("\n");
                    }
                 }



int rechercheparid(){
        int ide = 0;
        printf("|Trouver une tache|\n");


        printf("taper le ID de quoi vous vouler trouver: \n");
        printf("------> ");
        scanf("%d",&ide);
                    for (int x = 0 ; x <= nbrdeTaches; x++){
                    if(nouvelleTaches[x].id == ide){

                    printf("-titre       : %s\n", nouvelleTaches[x].titre);
                    printf("-status      : %s\n", nouvelleTaches[x].statut);
                    printf("-description : %s\n", nouvelleTaches[x].description);

                    return x;
    }
}
}
int bob = 100;

//recherche d'une tache par titre
int recherchepartitre(){
        char tite[20];
        printf("|Trouver une tache|\n");


        printf("taper le Titre de quoi vous vouler trouver \n");
        printf("------>");
        scanf("%s",tite);
                    for (int x = 0 ; x <= nbrdeTaches; x++){
                    if(strcmp(nouvelleTaches[x].titre,tite) == 0){

                    printf("-titre        : %s\n", nouvelleTaches[x].titre);
                    printf("-status      : %s\n", nouvelleTaches[x].statut);
                    printf("-description : %s\n", nouvelleTaches[x].description);


    }
}
}


//modification d'un description d'une tache
void modifierDescTaches(int kfc){
           char n[20];
                     printf("tu choisi de modifier la description..\n");
                     printf("entrer votre nouvelle description:\n");
                     scanf(" %[^\n]s", n);
                     strcpy(nouvelleTaches[kfc].description, n);
}

//modification de statut d'une tache
void modifierStatutTaches(int kfc){
    int minichoix ;
             do{
             printf("1 A FAIRE\n");
            printf("2 EN COURS\n");
            printf("3 FINALISEE\n");
            printf("4 menu\n");
            scanf("%d",&minichoix);
                      switch (minichoix) {
            case 1:
                printf("A FAIRE\n");
                strcpy(nouvelleTaches[kfc].statut,"aFaire" );
                break;
            case 2:
                printf("EN COURS\n");
                strcpy(nouvelleTaches[kfc].statut,"EnCours" );
                break;
            case 3:
                printf("FINALISEE\n");
                strcpy(nouvelleTaches[kfc].statut,"Finalisee" );
                break;
                default:
                printf("Choix invalide!\n");
                break;
        }
}while(minichoix!=1||minichoix!=2||minichoix!=3);
}


//modification de deadline
void modificationDeadTaches(int kfc){
    char n[20];
    printf("tu choisi de modifier le deadline..\n");
    printf("entrer votre nouvelle deadline ex:(YYYY/MM/DD):\n");
    scanf(" %[^\n]s", n);
    strcpy(nouvelleTaches[kfc].deadline, n);


}

// fonction du modification
void modificationGlobal(){
     int soustestt=0;
                do{
              printf("1. Modifier description d'une tache.\n");
              printf("2. Modifier statut d'une tache.\n");
              printf("3. Modifier deadline d'une tache.\n");
              printf("4. menu.\n");
              printf("          Entrer:");
              scanf("%d", &num);
             switch(num){
                 case 1:
                modifierDescTaches(rechercheparid());
                 break;
                 case 2:
                 modifierStatutTaches(rechercheparid());
                 break;

                 case 3:
                  modificationDeadTaches(rechercheparid());
                 break;
                   case 4:
                soustestt=1;
                 break;

             }

                }while(soustestt==0);
}


int supp(int x){

    if (strcmp(nouvelleTaches[x].statut,"aFaire") == 0){
            afaire--;
        }
    else if(strcmp(nouvelleTaches[x].statut,"EnCours") == 0){
            encours--;
        }
    else if(strcmp(nouvelleTaches[x].statut,"Finalisee") == 0){
            finalisee--;
    }
    for (x; x <= nbrdeTaches-1;x++){
    nouvelleTaches [x] = nouvelleTaches[x+1];
    }

    printf("__________l'element a ete suprimer__________\n");
    nbrdeTaches--;
    vari++;

}
int stats(){

            printf("***********************************\n");
            printf("il y on a %d tache  \n",nbrdeTaches);
            printf("les tache pour a faire      :  %d \n",afaire);
            printf("les tache pour en cours     :  %d \n",encours);
            printf("les tache pour finalisee  :  %d \n",finalisee);


            printf("***********************************\n");



    }
int main()
{

        int choix;
        int test=0;
         int soustestt=1;
             do {
        printf("\nMenu :\n");
        printf("1. Ajouter une nouvelle tache\n");
        printf("2. Ajouter plusieurs tache\n");
        printf("3. Afficher la liste :\n");
        printf("4. Modifier une tache\n");
        printf("5. Rechercher une tache\n");
        printf("6. Afficher des statistiques\n");
        printf("7. Supprimer une tache\n");
        printf("0. Quitter\n");
        printf("Choisissez une option : ");
        scanf("%d", &choix);
        switch (choix){


            case 1:
                ajouteruntache();
                printf("la tache est ajoutee avec sucee!!\n");
            break;


            case 2:

                     do{

                    ajouteruntache();
                    printf("la tache est ajoutee avec sucee!!");
                    printf("pour continuer taper 1 pour terminer  taper 0: \n");
                    scanf("%d",&soustestt);
                    }while(soustestt==1);
                    break;


            case 3:
              printf("1.pour ordre alphabetique: \n");
              printf("2.pour ordre deadline: \n");

              printf("entrer votre choix: \n");
              scanf("%d", &num);
              switch(num){
                case 1:
                 for (int i=0;i<choix;i++){
                    for(int j=i+1;j<choix;j++){
                        if(strcmp(nouvelleTaches[i].titre,nouvelleTaches[j].titre)>0){
                            temp=nouvelleTaches[j];
                            nouvelleTaches[j]=nouvelleTaches[i];
                            nouvelleTaches[i]=temp;
                        }
                    }
                 }
                 afficherTaches();
                 break;
                case 2:
                 for (int i=0;i<choix;i++){
                    for(int j=i+1;j<choix;j++){
                        if(strcmp(nouvelleTaches[i].deadline,nouvelleTaches[j].deadline)>0){
                            temp=nouvelleTaches[j];
                            nouvelleTaches[j]=nouvelleTaches[i];
                            nouvelleTaches[i]=temp;
                        }
                    }
                 }
                 afficherTaches();
              }
                break;


            case 4:
            modificationGlobal();
            break;

            case 5:

                printf("1-Chercher par ID:");
                printf("2-Chercher par titre:");
                scanf("%d",&bob);
                do{
                   switch(bob){
               case 1:
                   rechercheparid();
                   bob = 0;
                break;
               case 2:
                   recherchepartitre();
                   bob = 0;
                break;



                   }

                }while(bob);

                break;
            case 6:
                stats();
            break;
            case 7:
                supp(rechercheparid());
            break;
            case 0:
            printf("fin");
            test=1;
            break;
            default:
            printf("Choix invalide\n");
            break;
        }
    } while( test==0);

    return 0;
}

