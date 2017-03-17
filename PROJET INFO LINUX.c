//Bibliothéques
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Structures
struct prof_responsable{
char nom_prof_respon [20];
char prenom_prof_respon [20];
};

struct Date{
	int jour;
	int mois;
	int annee;
};
struct Adresse{
	int num_rue;
	char nom_rue [80];
	int code_postal;
	char ville [20];
	char pays [20];
};
struct Apprenti {
	char prenom [20];
	char nom [20];
	int salaire;
	char mdp_apprenti [20]; // mdp unique définissant un apprenti, sert pour se connecter
	char prof_responsable [20];  // permet d'atribuer un professeur responsable a l'eleve
                                // ce champ serat saisie plus tard soit par l'admin soit par un professeur
	char entreprise_apprenti  [20];   // permet d'attribuer un eleve a une entreprise
                                     // ce champ serat saisie plus tard soit par l'admin soit par un professeur
};
struct Enseignant {
	char prenom [20];
	char nom [20];
	char bureau [20];
	char mdp_enseignant [20];
};
struct Entreprise {
	char nom [20];
	struct Adresse adresse_entreprise;
	char mdp_entreprise [20];
};


//fonctions supplémentaires
void attribuer_prof (){
char nom [20];
char prenom [20];
struct Apprenti eleve;
int trouve =0;
FILE *fichier_apprenti = fopen("apprenti_fic.dat","r+");

printf (" +-----------------------------------------------------------------+\n");
printf (" | Vous avez choisi d'ajouter un professeur responsable a un eleve |\n");
printf (" +-----------------------------------------------------------------+\n");
printf (" |                                                                 |\n");
printf (" | Entrer le nom de l'apprenti :                                   |\n");
printf (" | ");
__fpurge(stdin);
fgets (nom, 20, stdin);
printf (" | Entrer le prenom de l'apprenti :                                |\n");
printf (" | ");
__fpurge(stdin);
fgets (prenom, 20, stdin);
printf (" +-----------------------------------------------------------------+\n");

while(!feof(fichier_apprenti)&&fread(&eleve,sizeof(struct Apprenti),1,fichier_apprenti))
          {
              if((strcmp(nom,eleve.nom)==0)&&(strcmp(prenom,eleve.prenom)==0))
                {
                printf(" Voici les informations sur l'eleve: \n ");
                afficher_apprenti (eleve);
                printf(" Vous pouvez maintenant modifier le nom du professeur responsable de cet apprenti.\n");

                printf ("\n Entrer le nom du professeur responsable : ");
                __fpurge(stdin);
                fgets (eleve.prof_responsable, 20, stdin);


                trouve =1 ;

                }
          }
          if (trouve == 0)
              {
               printf("Combinaison incorrecte\n");
               attribuer_prof();
              }
          fclose(fichier_apprenti);
}





//fonctions essentiels
	// 1)   fonctions saisi UN apprenti/enseignant/entreprise (marche correctement, pb de getchar parfois)
	struct Apprenti saisir_apprenti (){ //remplacement des getchar par des fflush(stdin);
		struct Apprenti apprenti;

		printf (" Entrer le prenom de l'apprenti : ");
        __fpurge(stdin);
		fgets (apprenti.prenom, 20, stdin);
		printf ("\n Entrer le nom de l'apprenti : ");
		fgets (apprenti.nom, 20, stdin);
		printf ("\n Entrer le salaire de l'apprenti : ");
		scanf ("%d", &apprenti.salaire );
		printf ("\n Entrer le mot de passe de l'apprenti : ");
		__fpurge(stdin);
		fgets (apprenti.mdp_apprenti, 20, stdin);
		return apprenti;
	}
	struct Enseignant saisir_enseignant (){
		struct Enseignant enseignant;

		printf (" Entrer le prenom de l'enseignant : ");
		__fpurge(stdin);
		fgets (enseignant.prenom, 20, stdin);
		printf ("\n Entrer le nom de l'enseignant : ");
		fgets (enseignant.nom, 20, stdin);
		printf ("\n Entrer le bureau de l'enseignant : ");
		fgets (enseignant.bureau, 20, stdin);
		printf ("\n Entrer le mot de passe de l'enseignant : ");
		__fpurge(stdin);
		fgets (enseignant.mdp_enseignant, 20, stdin);
		return enseignant;
	}
	struct Entreprise saisir_entreprise (){
		struct Entreprise entreprise;

		printf (" Entrer le nom de l'entreprise :");
		__fpurge(stdin);
		fgets (entreprise.nom, 20, stdin);
		printf ("\n vous allez maintenant entrer l'adresse \n");
		printf (" Entrer le numero de rue de l'entreprise : ");
		scanf("%d", &entreprise.adresse_entreprise.num_rue);
		printf ("\n Entrer le nom de rue de l'entreprise : ");
		__fpurge(stdin);
		fgets (entreprise.adresse_entreprise.nom_rue, 80, stdin);
		printf ("\n Entrer le code postal de l'entreprise : ");
		scanf ("%d", &entreprise.adresse_entreprise.code_postal);
		printf ("\n Entrer le nom de la ville de l'entreprise : ");
		__fpurge(stdin);
		fgets (entreprise.adresse_entreprise.ville, 20, stdin);
		printf ("\n Entrer le pays de l'entreprise : ");
		fgets (entreprise.adresse_entreprise.pays, 20, stdin);
		printf ("\n Entrer le mot de passe de l'entreprise : ");
		__fpurge(stdin);
		fgets (entreprise.mdp_entreprise, 20, stdin);
		return entreprise;
	}



	// 2)   fonction afficher UN apprenti/enseignant/entreprise (marche correctement)
	void afficher_apprenti (struct Apprenti apprenti){
		printf ("\n +----------------------------------------------------+"         );
		printf ("\n | %s ", apprenti.prenom                                         );
		printf ("\n | %s ", apprenti.nom                                            );
		printf ("\n | Salaire : %d euro", apprenti.salaire                          );
		printf ("\n | MDP : %s ", apprenti.mdp_apprenti                             );
		printf ("\n | Professeur responsable : %s", apprenti.prof_responsable       );
		printf ("\n | Entreprise de l'apprentie : %s", apprenti.entreprise_apprenti );
		printf ("\n +----------------------------------------------------+\n"       );
	}
	void afficher_enseignant (struct Enseignant enseignant){
		printf ("\n +----------------------------------------------------+");
		printf ("\n | %s ", enseignant.prenom);
		printf ("\n | %s ", enseignant.nom);
		printf ("\n | Bureau : %s ", enseignant.bureau);
		printf ("\n | MDP : %s ", enseignant.mdp_enseignant);
		printf ("\n +----------------------------------------------------+");
	}
	void afficher_entreprise (struct Entreprise entreprise){
		printf ("\n +----------------------------------------------------+");
		printf ("\n | %s ", entreprise.nom);
		printf ("\n | %d, %s ", entreprise.adresse_entreprise.num_rue,entreprise.adresse_entreprise.nom_rue );
		printf ("\n | %d, %s  ", entreprise.adresse_entreprise.code_postal, entreprise.adresse_entreprise.ville, entreprise.adresse_entreprise.pays );
		printf ("\n | %s ", entreprise.adresse_entreprise.pays);
		printf ("\n | MDP : %s ", entreprise.mdp_entreprise);
		printf ("\n +----------------------------------------------------+");
	}


	// 3)   fonction pour ajouter un element a un dossier donc demander lequel des trois fichier (apprentie,enseignant,entreprise) puis faire apelle a une fonction saisi
	void ajouter_au_fic (){ // (marche correctement)
		int choix;
		struct Apprenti apprenti;
		struct Enseignant enseignant;
		struct Entreprise entreprise;

		do {
            printf ("\n  +-----------------------------------------------------------+");
			printf ("\n  | Vous avez decider d'ajouter un element a un fichier.      |");
			printf ("\n  |        Choisissez ce que vous vouler ajouter :            |");
			printf ("\n  +-----------------------------------------------------------+");
			printf ("\n  |                                                           |");
			printf ("\n  | 1. Un apprenti                                            |");
			printf ("\n  | 2. Un enseignant                                          |");
			printf ("\n  | 3. Une entreprise                                         |");
			printf ("\n  |                                                           |");
			printf ("\n  | 4. Revenir au menu principal                              |");
            printf ("\n  +-----------------------------------------------------------+\n\n\n");
			scanf("%d", &choix);

			switch (choix)
				{
				case 1 :
					apprenti = saisir_apprenti ();
					FILE *fichier_apprenti = fopen("apprenti_fic.dat", "a");
					fwrite(&apprenti, sizeof(struct Apprenti), 1, fichier_apprenti);
					fclose(fichier_apprenti);
					printf("\n\n L'apprentie a bien ete enregistre, vous aller retourner au menu principal.\n\n");
					menu_principal();
					break;

				case 2 :
					enseignant = saisir_enseignant ();
					FILE *fichier_enseignant = fopen("enseignant_fic.dat", "a");
					fwrite(&enseignant, sizeof(struct Enseignant), 1, fichier_enseignant);
					fclose(fichier_enseignant);
                    printf("\n\n L'enseignant a bien ete enregistre, vous aller retourner au menu principal.\n\n");
					menu_principal();
					break;

				case 3 :
					entreprise = saisir_entreprise ();
					FILE *fichier_entreprise = fopen("entreprise_fic.dat", "a");
					fwrite(&entreprise, sizeof(struct Entreprise), 1, fichier_entreprise);
					fclose(fichier_entreprise);
					printf("\n\n L'entreprise a bien ete enregistre, vous aller retourner au menu principal.\n\n");
					menu_principal();
					break;

                case 4 :
                    menu_principal();
                    break;
				}
		}while (choix > 4);
	}


    // 4)   Fonction pour afficher tout element d'un fichier a determiner (par exemple tout afficher les apprentis du fichier)
        void afficher_tout_apprenti_fic (){
            struct Apprenti apprenti;
            int i = 0;

            printf("\n Vous avez choisi d'afficher tout les apprentis du fichier : \n\n");
            FILE * fichier_apprenti = fopen("apprenti_fic.dat", "r");

            if (fichier_apprenti == NULL)
                printf("\n Probleme a l'ouverture du fichier, le fichier est peut etre vide.");

            else
                {
                while (!feof(fichier_apprenti) && fread(&apprenti, sizeof(struct Apprenti), 1, fichier_apprenti))
                    {
                    printf(" \n\nApprenti numeros %d : ", i=i+1);
                    afficher_apprenti(apprenti);
                    }
                }
            fclose(fichier_apprenti);
            printf("\n\n Vous aller retourner au menu principal.\n\n");
            menu_principal();
        }
        void afficher_tout_enseignant_fic (){
            struct Enseignant enseignant;
            int i = 0;

            printf("\n Vous avez choisi d'afficher tout les enseigant du fichier : \n\n");
            FILE * fichier_enseignant = fopen("enseignant_fic.dat", "r");

            if (fichier_enseignant == NULL)
                printf("\n Probleme a l'ouverture du fichier, le fichier est peut etre vide.");

            else
                {
                while (!feof(fichier_enseignant) && fread(&enseignant, sizeof(struct Enseignant), 1, fichier_enseignant))
                    {
                    printf(" \n\nEnseignant numeros %d : ", i=i+1);
                    afficher_enseignant(enseignant);
                    }
                }
            fclose(fichier_enseignant);
            printf("\n\n Vous aller retourner au menu principal.\n\n");
            menu_principal();
        }
        void afficher_tout_entreprise_fic (){
            struct Entreprise entreprise;
            int i = 0;


            printf("\n Vous avez choisi d'afficher toute les entreprises du fichier : \n\n");
            FILE * fichier_entreprise = fopen("entreprise_fic.dat", "r");

            if (fichier_entreprise == NULL)
                printf("\n Probleme a l'ouverture du fichier, le fichier est peut etre vide.");

            else
                {
                while (!feof(fichier_entreprise) && fread(&entreprise, sizeof(struct Entreprise), 1, fichier_entreprise))
                    {
                    printf(" \n\nEntreprise numeros %d : ", i=i+1);
                    afficher_entreprise(entreprise);
                    }
                }
            fclose(fichier_entreprise);
            printf("\n\n Vous aller retourner au menu principal.\n\n");
            menu_principal();
        }

        void afficher_fic (){
        int choix;
        do
            {
            printf ("\n  +-----------------------------------------------------------+");
			printf ("\n  |        Vous avez decider d'afficher un fichier.           |");
			printf ("\n  |     Choisissez le fichier que vous voulez afficher:       |");
			printf ("\n  +-----------------------------------------------------------+");
			printf ("\n  |                                                           |");
			printf ("\n  | 1. Un apprenti                                            |");
			printf ("\n  | 2. Un enseignant                                          |");
			printf ("\n  | 3. Une entreprise                                         |");
			printf ("\n  |                                                           |");
			printf ("\n  | 4. Revenir au menu principal                              |");
            printf ("\n  +-----------------------------------------------------------+\n\n\n");
			scanf("%d", &choix);

			switch (choix)
				{
				case 1 :
                    afficher_tout_apprenti_fic();
				    break;

                case 2 :
                    afficher_tout_enseignant_fic();
				    break;

                case 3 :
                    afficher_tout_entreprise_fic();
				    break;

                case 4 :
                    menu_principal();
				    break;
				}
            }while (choix > 4);
        }
    // 5)   Fonction pour modifier les fichier

    //probleme pour modifier le fichier
        void modifier_apprenti(){
          struct Apprenti eleve;
          char nom[20];
          char prenom[20];
          int trouve=0;

          FILE *fichier_apprenti = fopen("apprenti_fic.dat","r+");//ouverture en lecture ecriture
          printf(" Nom de l'eleve: ");
          __fpurge(stdin);
          fgets(nom,20,stdin);
          printf(" Prenom de l'eleve: ");
          __fpurge(stdin);
          fgets(prenom,20,stdin);

          //lecture de tous les enregistrements du fichier:
          while(!feof(fichier_apprenti)&&fread(&eleve,sizeof(struct Apprenti),1,fichier_apprenti))
          {
              if((strcmp(nom,eleve.nom)==0)&&(strcmp(prenom,eleve.prenom)==0)) //si le nom et prenom sont trouvés, on affiche ses informations
              {
                  printf(" Voici les informations sur l'eleve: \n ");
                  afficher_apprenti(eleve);
                  printf(" Donnez les nouvelles informations:\n"); //Et on demande les nouvelles information
                  eleve = saisir_apprenti();
                  fseek(fichier_apprenti,-sizeof(struct Apprenti),SEEK_CUR);
                  fwrite(&eleve,sizeof(struct Apprenti),1,fichier_apprenti);
                  fseek(fichier_apprenti,sizeof(struct Apprenti),SEEK_CUR);
                 trouve=1;
                 printf(" Les informations ont ete modifie, vous allez retourner au menu principal\n\n");
                 menu_principal();
              }
          }
          if(trouve==0)
              {
                printf(" L'apprenti n'a pas ete trouve,recommencez. \n");
                modifier_apprenti();
              }
          fclose(fichier_apprenti);
        }
        void modifier_enseignant(){
          struct Enseignant prof;
          char nom[20];
          char prenom[20];
          int trouve=0;

          FILE *fichier_enseignant = fopen("enseignant_fic.dat","r+");//ouverture en lecture ecriture
          printf(" Nom de l'enseignant: ");
          __fpurge(stdin);
          fgets(nom,20,stdin);
          printf(" Prenom de l'enseignant: ");
          __fpurge(stdin);
          fgets(prenom,20,stdin);
          //lecture de tous les enregistrements du fichier:
          while(!feof(fichier_enseignant)&&fread(&prof,sizeof(struct Enseignant),1,fichier_enseignant))
          {
              if((strcmp(nom,prof.nom)==0)&&(strcmp(prenom,prof.prenom)==0))//si le nom et prenom sont trouvés, on affiche ses informations
              {
                  printf(" Voici les informations sur l'enseignant: \n ");
                  afficher_enseignant(prof);
                  printf("\n Donnez les nouvelles informations:\n");//Et on demande les nouvelles information
                  prof = saisir_enseignant();
                  fseek(fichier_enseignant,-sizeof(struct Enseignant),SEEK_CUR);
                  fwrite(&prof,sizeof(struct Enseignant),1,fichier_enseignant);
                  fseek(fichier_enseignant,sizeof(struct Enseignant),SEEK_CUR);
                  trouve=1;
                  printf(" Les informations ont ete modifie, vous allez retourner au menu principal\n\n");
                 menu_principal();
              }
          }
          if(trouve==0)
            {
            printf(" L'enseignant n'a pas ete trouve, recommencez \n");
            modifier_enseignant();
            }
          fclose(fichier_enseignant);
        }
        void modifier_entreprise(){
          struct Entreprise boite;
          char nom[20];
          int trouve=0;
          FILE *fichier_entreprise = fopen("entreprise_fic.dat","r+");//ouverture en lecture ecriture

          printf(" Nom de l'entreprise: ");
          __fpurge(stdin);
          fgets(nom,20,stdin);

          while(!feof(fichier_entreprise)&&fread(&boite,sizeof(struct Entreprise),1,fichier_entreprise))//lecture de tous les enregistrements du fichier:
          {
              if((strcmp(nom,boite.nom)==0))
              {
                  printf(" Voici les informations sur l'entreprise: \n ");//si le nom est trouvé, on affiche ses informations
                  afficher_entreprise(boite);
                  printf("\n Donnez les nouvelles informations:\n");//Et on demande les nouvelles information
                  boite = saisir_entreprise();
                  fseek(fichier_entreprise,-sizeof(struct Entreprise),SEEK_CUR);
                  fwrite(&boite,sizeof(struct Entreprise),1,fichier_entreprise);
                  fseek(fichier_entreprise,sizeof(struct Entreprise),SEEK_CUR);
                  trouve=1;
                  printf(" Les informations ont ete modifie, vous allez retourner au menu principal\n\n");
                 menu_principal();
              }
          }
          if(trouve==0)
                {
                printf(" L'entreprise n'a pas ete trouve, recommencez \n");
                modifier_entreprise();
                }
          fclose(fichier_entreprise);
        }

        void modifier_fic (){
        int choix;
        do
            {
            printf ("\n  +-----------------------------------------------------------+");
			printf ("\n  | Vous avez decider de modifier un element d'un fichier.    |");
			printf ("\n  |        Choisissez ce que vous vouler modifier :           |");
			printf ("\n  +-----------------------------------------------------------+");
			printf ("\n  |                                                           |");
			printf ("\n  | 1. Un apprenti                                            |");
			printf ("\n  | 2. Un enseignant                                          |");
			printf ("\n  | 3. Une entreprise                                         |");
			printf ("\n  |                                                           |");
			printf ("\n  | 4. Revenir au menu principal                              |");
            printf ("\n  +-----------------------------------------------------------+\n\n\n");
			scanf("%d", &choix);

			switch (choix)
				{
				case 1 :
                    modifier_apprenti();
				    break;

                case 2 :
                    modifier_enseignant();
				    break;

                case 3 :
                    modifier_entreprise();
				    break;

                case 4 :
                    menu_principal();
				    break;
				}
            }while (choix > 4);
        }

    // 6)   Fonction pour supprimer un element de fichier
//fonction de supprimer d'un élève

        void supprimer_apprenti(){
          struct Apprenti eleve;
          char nom[20];
          char prenom[20];

          FILE *fichier_apprenti=fopen("apprenti_fic.dat","r+");//ouverture en lecture ecriture
          printf(" Nom de l'eleve: ");
          __fpurge(stdin);
          fgets(nom,20,stdin);
          printf(" Prenom de l'eleve: ");
          __fpurge(stdin);
          fgets(prenom,20,stdin);

/*
    fic1: apprenti_fic.dat
    fic2: apprenti_fic2.dat

    on veut supprimer un élément du fic1, donc on creer un second fichier fic2 et on copie tout les element du fic1
    qu'on veut garder on ne copie pas l'element qu'on veut supprimer
    apres on supprime le fic1
    puis on rename apprenti_fic2.dat en apprenti_fic.dat
*/


          while(!feof(fichier_apprenti)&&fread(&eleve,sizeof(struct Apprenti),1,fichier_apprenti))//lecture de tous les enregistrements du fichier
          {
              if((strcmp(nom,eleve.nom)==0)&&(strcmp(prenom,eleve.prenom)==0))//si le nom et prenom sont trouvés
              {
              fseek(fichier_apprenti,-sizeof(eleve),SEEK_CUR);
              fwrite(&eleve,sizeof(struct Apprenti),1,fichier_apprenti);


              fclose(fichier_apprenti);
               printf(" L'eleve a correctement ete supprimer, vous allez revenir au menu principal \n\n");
               menu_principal();
              }
          }
        }


        void supprimer_fic(){
        int choix;
        do
            {
            printf ("\n  +-----------------------------------------------------------+");
			printf ("\n  |   Vous avez decider de supprimer un element d'un fichier. |");
			printf ("\n  |         Choisissez ce que vous vouler supprimer :         |");
			printf ("\n  +-----------------------------------------------------------+");
			printf ("\n  |                                                           |");
			printf ("\n  | 1. Un apprenti                                            |");
			printf ("\n  | 2. Un enseignant                                          |");
			printf ("\n  | 3. Une entreprise                                         |");
			printf ("\n  |                                                           |");
			printf ("\n  | 4. Revenir au menu principal                              |");
            printf ("\n  +-----------------------------------------------------------+\n\n\n");
			scanf("%d", &choix);

			switch (choix)
				{
				case 1 :
                    supprimer_apprenti();
				    break;

                case 2 :
                    supprimer_enseignant();
				    break;

                case 3 :
                    supprimer_entreprise();
				    break;

                case 4 :
                    menu_principal();
				    break;
				}
            }while (choix > 4);
        }




//Fonctions menu
    // 0)   Menu principale celui qui est executer dans le main
    void menu_principal (){
        int choix;
    do{
        printf ("  +-------------------------+\n");
        printf ("  |      Qui ete vous ?     |\n");
        printf ("  +-------------------------+\n");
        printf ("  |                         |\n");
        printf ("  | 1. Un apprenti          |\n");
        printf ("  | 2. Un enseignant        |\n");
        printf ("  | 3. Une entreprise       |\n");
        printf ("  | 4. Un Administrateur    |\n");
        printf ("  |                         |\n");
        printf ("  | 5. Quitter le programme |\n");
        printf ("  +-------------------------+\n");
        printf ("\n\n");
        scanf ("%d", &choix);
        switch  (choix)
            {
            case 1 :
                menu_apprenti_1 ();
                break;

            case 2 :
                menu_enseignant_1 ();
                break;

            case 3 :
                menu_entreprise_1 ();
                break;

            case 4:
                menu_admin_1 ();
                break;
            case 5 :
                printf ("\n +---------------------------+");
                printf ("\n |   Au revoir, a bientot.   |");
                printf ("\n +---------------------------+\n\n\n");
                break;
            }
    }while (choix > 5);
    }

    // 1)   Fonctions pour le menu apres 1er choix
    void menu_apprenti_1 (){  // a finir (modification des getchar par fflush(stdin);)
        char nom [20];
        char mdp_saisi[20];
        struct Apprenti eleve;
        int trouve =0;
        FILE *fichier_apprenti = fopen("apprenti_fic.dat","r+");

        printf ("  +------------------------------------+\n");
        printf ("  | Vous avez choisi apprenti :        |\n");
        printf ("  +------------------------------------+\n");
        printf ("  |                                    |\n");
        printf ("  | Entrer votre nom :                 |\n");
        printf ("  | ");
        __fpurge(stdin);
        fgets (nom, 20, stdin);
        printf ("  | Entrer votre mot de passe :        |\n");
        printf ("  | ");
        fgets (mdp_saisi, 20, stdin);
        printf ("  +------------------------------------+\n");

        while(!feof(fichier_apprenti)&&fread(&eleve,sizeof(struct Apprenti),1,fichier_apprenti))
          {
              if((strcmp(nom,eleve.nom)==0)&&(strcmp(mdp_saisi,eleve.mdp_apprenti)==0))
                {
                 menu_apprentie_2();
                 trouve =1 ;
                }
          }
          if (trouve == 0)
              {
               printf("Combinaison incorrecte\n");
               menu_apprenti_1();
              }
          fclose(fichier_apprenti);
    }
    void menu_enseignant_1 (){ // a finir
        char nom [20];
        char mdp_saisi[20];
        struct Enseignant enseignant;
        int trouve = 0;
        FILE *fichier_enseignant = fopen("enseignant_fic.dat","r+");

        printf ("  +------------------------------------+\n");
        printf ("  | Vous avez choisi enseignant :      |\n");
        printf ("  +------------------------------------+\n");
        printf ("  |                                    |\n");
        printf ("  | Entrer votre nom :                 |\n");
        printf ("  | ");
        __fpurge(stdin);
        fgets (nom, 20, stdin);
        printf ("  | Entrer votre mot de passe :        |\n");
        printf ("  | ");
        fgets (mdp_saisi, 20, stdin);
        printf ("  +------------------------------------+\n");

      while(!feof(fichier_enseignant)&&fread(&enseignant,sizeof(struct Enseignant),1,fichier_enseignant))
          {
              if((strcmp(nom,enseignant.nom)==0)&&(strcmp(mdp_saisi,enseignant.mdp_enseignant)==0))
                {
                 menu_enseignant_2();
                 trouve =1 ;
                }
          }
          if (trouve == 0)
              {
               printf("Combinaison incorrecte\n");
               menu_enseignant_1();
              }
          fclose(fichier_enseignant);
    }
    void menu_entreprise_1 (){  //a finir
        char nom [20];
        char mdp_saisi[20];
        struct Entreprise entreprise;
        int trouve = 0;
        FILE *fichier_entreprise = fopen("entreprise_fic.dat","r+");

        printf ("  +------------------------------------+\n");
        printf ("  | Vous avez choisi entreprise :      |\n");
        printf ("  +------------------------------------+\n");
        printf ("  |                                    |\n");
        printf ("  | Entrer votre nom :                 |\n");
        printf ("  | ");
        __fpurge(stdin);
        fgets (nom, 20, stdin);
        printf ("  | Entrer votre mot de passe :        |\n");
        printf ("  | ");
        fgets (mdp_saisi, 20, stdin);
        printf ("  +------------------------------------+\n");

         while(!feof(fichier_entreprise)&&fread(&entreprise,sizeof(struct Entreprise),1,fichier_entreprise))
          {
              if((strcmp(nom,entreprise.nom)==0)&&(strcmp(mdp_saisi,entreprise.mdp_entreprise)==0))
                {
                 menu_entreprise_2();
                 trouve =1 ;
                }
          }
          if (trouve == 0)
              {
               printf("Combinaison incorrecte\n");
               menu_entreprise_1();
              }

          fclose(fichier_entreprise);
    }
    void menu_admin_1 (){  //marche correctement
        char nom [20];
        char mdp_saisi[20];

        printf ("  +------------------------------------+\n");
        printf ("  | Vous avez choisi Administrateur :  |\n");
        printf ("  +------------------------------------+\n");
        printf ("  |                                    |\n");
        printf ("  | Entrer votre nom :                 |\n");
        printf ("  | ");
        __fpurge(stdin);
        fgets (nom, 20, stdin);
        printf ("  | Entrer votre mot de passe :        |\n");
        printf ("  | ");
        fgets (mdp_saisi, 20, stdin);
        printf ("  +------------------------------------+\n");

        if (strncmp(nom, "admin", 5) == 0 && strncmp(mdp_saisi, "password", 8) == 0)
            menu_admin_2();
        else
        {
            printf("Combinaison incorrecte ! \n\n");
            menu_admin_1 ();
        }
    }

    // 2)   Fonctions pour le menu apres verification des noms et mdp
    void menu_apprentie_2 (){ // a finir
    int choix;
    struct Apprenti apprenti;

    do{
    printf("\n +--------------------------------------------------------+");
    printf("\n |    Vous avez bien ete connecte en tant qu'apprentie    |");
    printf("\n |            Vous pouvez maintenant acceder a :          |");
    printf("\n +--------------------------------------------------------+");
    printf("\n |                                                        |");
    printf("\n | 1. Afficher votre profil                               |");
    printf("\n |                                                        |");
    printf("\n | 2. retourner au menu principal                         |");
    printf("\n +--------------------------------------------------------+\n\n");

    scanf ("%d", &choix);
        switch  (choix)
            {
            case 1 :

                break;

            case 2 :
                menu_principal();
                break;
            }
    }while (choix > 2);
    }
    void menu_enseignant_2 (){ // a finir
    int choix;

    do{
    printf("\n +--------------------------------------------------------+");
    printf("\n |    Vous avez bien ete connecte en tant qu'enseignant   |");
    printf("\n |           Vous pouvez maintenant acceder a :           |");
    printf("\n +--------------------------------------------------------+");
    printf("\n |                                                        |");
    printf("\n | 1. Afficher votre profil                               |");
    printf("\n | 2. Ajouter un element a un fichier                     |");
    printf("\n | 3. Modifier un element d'un fichier                    |");
    printf("\n | 4. Supprimer un element d'un dossier                   |");
    printf("\n |                                                        |");
    printf("\n | 5. retourner au menu principal                         |");
    printf("\n +--------------------------------------------------------+\n\n");

    scanf ("%d", &choix);
        switch  (choix)
            {
            case 1 :

                break;

            case 2 :
                ajouter_au_fic();
                break;

            case 3 :
                modifier_fic();
                break;

            case 4:
                supprimer_fic();
                break;

            case 5:
                menu_principal();
                break;
            }
    }while (choix > 5);
    }
    void menu_entreprise_2 (){ // a finir
    int choix;

    do{
    printf("\n +--------------------------------------------------------+");
    printf("\n |    Vous avez bien ete connecte en tant qu'entreprise   |");
    printf("\n |           Vous pouvez maintenant acceder a :           |");
    printf("\n +--------------------------------------------------------+");
    printf("\n |                                                        |");
    printf("\n | 1. Afficher votre profil                               |");
    printf("\n | 2. Aficher la liste de vos apprentis                   |");
    printf("\n |                                                        |");
    printf("\n | 3. retourner au menu principal                         |");
    printf("\n +--------------------------------------------------------+\n\n");

    scanf ("%d", &choix);
        switch  (choix)
            {
            case 1 :

                break;

            case 2 :

                break;

            case 3 :
                menu_principal();
                break;
            }
    }while (choix > 3);
    }
    void menu_admin_2 (){ // a finir
    int choix;

    do{
    printf("\n +--------------------------------------------------------+");
    printf("\n |    Vous avez bien ete connecte en tant qu'admin        |");
    printf("\n |           Vous pouvez maintenant acceder a :           |");
    printf("\n +--------------------------------------------------------+");
    printf("\n |                                                        |");
    printf("\n | 1. Ajouter un element a un fichier                     |");
    printf("\n | 2. Aficher tout les element d'un fichier               |");
    printf("\n | 3. Modifier un element d'un fichier                    |");
    printf("\n | 4. Supprimer un element d'un fichier                   |");
    printf("\n |                                                        |");
    printf("\n | 5. retourner au menu principal                         |");
    printf("\n +--------------------------------------------------------+\n\n");

    scanf ("%d", &choix);
        switch  (choix)
            {
            case 1 :
                ajouter_au_fic();
                break;

            case 2 :
                afficher_fic();
                break;
            case 3 :
                modifier_fic();
                break;

            case 4 :
                supprimer_fic();
                break;

            case 5 :
                menu_principal();
                break;
            }
    }while (choix > 5);
    }

//main
void main(){
    printf ("  +----------------------------------------------------------+\n");
    printf ("  |   Bonjour ce programme sert a la gestion des apprentis   |\n");
    printf ("  +----------------------------------------------------------+\n\n\n");
    menu_principal();
}
