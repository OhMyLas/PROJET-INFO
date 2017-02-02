//Bibliothéques
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Structures
struct Date {
	int jour;
	int mois;
	int annee;
};
struct Adresse {
	int num_rue;
	char nom_rue [80];
	int code_postal;
	char ville [20];
	char pays [20];
};
struct Apprenti {
	char prenom [20];
	char nom [20];
	float salaire;
	char mdp_apprenti [20]; // mdp unique définissant un apprenti, sert pour se connecter
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




//fonctions essentiels
	// 1)   fonctions saisi UN apprenti/enseignant/entreprise (marche correctement)
	struct Apprenti saisir_apprenti (){
		struct Apprenti apprenti;

		printf ("Entrer le prenom de l'apprenti : ");
		getchar();
		fgets (apprenti.prenom, 20, stdin);
		printf ("\n Entrer le nom de l'apprenti : ");
		fgets (apprenti.nom, 20, stdin);
		printf ("\n Entrer le salaire de l'apprenti : ");
		scanf ("%f", &apprenti.salaire );
		printf ("\n Entrer le mot de passe de l'apprenti : ");
		getchar();
		fgets (apprenti.mdp_apprenti, 20, stdin);
		return apprenti;
	}
	struct Enseignant saisir_enseignant (){
		struct Enseignant enseignant;

		printf ("Entrer le prenom de l'enseignant : ");
		getchar();
		fgets (enseignant.prenom, 20, stdin);
		printf ("\n Entrer le nom de l'enseignant : ");
		fgets (enseignant.nom, 20, stdin);
		printf ("\n Entrer le bureau de l'enseignant : ");
		fgets (enseignant.bureau, 20, stdin);
		printf ("\n Entrer le mot de passe de l'enseignant : ");
		getchar();
		fgets (enseignant.mdp_enseignant, 20, stdin);
		return enseignant;
	}
	struct Entreprise saisir_entreprise (){
		struct Entreprise entreprise;

		printf ("Entrer le nom de l'entreprise :");
		getchar();
		fgets (entreprise.nom, 20, stdin);
		printf ("\n vous allez maintenant entrer l'adresse \n");
		printf ("Entrer le numero de rue de l'entreprise : ");
		scanf("%d", &entreprise.adresse_entreprise.num_rue);
		printf ("\n Entrer le nom de rue de l'entreprise : ");
		getchar();
		fgets (entreprise.adresse_entreprise.nom_rue, 80, stdin);
		printf ("\n Entrer le code postal de l'entreprise : ");
		scanf ("%d", &entreprise.adresse_entreprise.code_postal);
		printf ("\n Entrer le nom de la ville de l'entreprise : ");
		getchar();
		fgets (entreprise.adresse_entreprise.ville, 20, stdin);
		printf ("\n Entrer le pays de l'entreprise : ");
		fgets (entreprise.adresse_entreprise.pays, 20, stdin);
		printf ("\n Entrer le mot de passe de l'entreprise : ");
		getchar();
		fgets (entreprise.mdp_entreprise, 20, stdin);
		return entreprise;
	}



	// 2)   fonction afficher UN apprenti/enseignant/entreprise (a tester)
	void afficher_apprenti (struct Apprenti apprenti){
		printf ("\n * %s ", apprenti.prenom);
		printf ("\n * %s ", apprenti.nom);
		printf ("\n * %d ", apprenti.salaire);
		printf ("\n * %s ", apprenti.mdp_apprenti);
	}
	void afficher_enseignant (struct Enseignant enseignant){
		printf ("\n * %s ", enseignant.prenom);
		printf ("\n * %s ", enseignant.nom);
		printf ("\n * %s ", enseignant.bureau);
		printf ("\n * %s ", enseignant.mdp_enseignant);
	}
	void afficher_entreprise (struct Entreprise entreprise){
		printf ("\n * %s ", entreprise.nom);
		printf ("\n * %d ", entreprise.adresse_entreprise.num_rue);
		printf ("\n * %s ", entreprise.adresse_entreprise.nom_rue);
		printf ("\n * %d ", entreprise.adresse_entreprise.code_postal);
		printf ("\n * %s ", entreprise.adresse_entreprise.ville);
		printf ("\n * %s ", entreprise.adresse_entreprise.pays);
		printf ("\n * %s ", entreprise.mdp_entreprise);
	}


	// 3)   fonction pour ajouter un element a un dossier donc demander lequel des trois fichier (apprentie,enseignant,entreprise) puis faire apelle a une fonction saisi
	void ajouter_au_fic (){ // (marche correctement normalement)
		int choix;
		struct Apprenti apprenti;
		struct Enseignant enseignant;
		struct Entreprise entreprise;

		do {
          //  printf ("");
			printf ("\n\nVous avez decider d'ajouter un element a un fichier.\n");
			printf ("Choisissez ce que vous vouler ajouter : \n");
			printf ("\n 1. Un apprenti\n");
			printf ("\n 2. Un enseignant\n");
			printf ("\n 3. Un entreprise\n\n\n");
			scanf("%d", &choix);

			switch (choix)
				{
				case 1 :
					apprenti = saisir_apprenti ();
					FILE *fichier_apprenti = fopen("apprenti_fic.dat", "a");
					fwrite(&apprenti, sizeof(struct Apprenti), 1, fichier_apprenti);
					fclose(fichier_apprenti);
					printf("\n\nL'apprentie a bien ete enregistre, vous aller retourner au menu principal.\n\n");
					menu_principal();
					break;

				case 2 :
					enseignant = saisir_enseignant ();
					FILE *fichier_enseignant = fopen("enseignant_fic.dat", "a");
					fwrite(&enseignant, sizeof(struct Enseignant), 1, fichier_enseignant);
					fclose(fichier_enseignant);
                    printf("\n\nL'enseignant a bien ete enregistre, vous aller retourner au menu principal.\n\n");
					menu_principal();
					break;

				case 3 :
					entreprise = saisir_entreprise ();
					FILE *fichier_entreprise = fopen("entreprise_fic.dat", "a");
					fwrite(&entreprise, sizeof(struct Entreprise), 1, fichier_entreprise);
					fclose(fichier_entreprise);
					printf("\n\nL'entreprise a bien ete enregistre, vous aller retourner au menu principal.\n\n");
					menu_principal();
					break;
				}
		}while (choix > 3);
	}



//Fonction menu

    // 0) menu principale celui qui est executer dans le main
    void menu_principal (){
        int choix;
    do{
        printf ("  +-------------------------+\n");
        printf ("  + Qui ete vous ?          +\n");
        printf ("  +                         +\n");
        printf ("  + 1. Un apprenti          +\n");
        printf ("  + 2. Un enseignant        +\n");
        printf ("  + 3. Une entreprise       +\n");
        printf ("  + 4. Un Administrateur    +\n");
        printf ("  +                         +\n");
        printf ("  + 5. Quitter le programme +\n");
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
                printf ("\nAu revoir, a bientot.\n\n");
                break;
            }
    }while (choix > 5);

    }

    // 1)   fonctions pour le menu apres 1er choix
    void menu_apprenti_1 (){  // a finir
        char nom [20];
        char mdp_saisi[20];

        printf ("  +------------------------------------+\n");
        printf ("  + Vous avez choisi apprenti :        +\n");
        printf ("  +                                    +\n");
        printf ("  + Entrer votre nom :                 +\n");
        printf ("  + ");
        getchar();
        fgets (nom, 20, stdin);
        printf ("  + Entrer votre mot de passe :        +\n");
        printf ("  + ");
        fgets (mdp_saisi, 20, stdin);
        printf ("  +------------------------------------+\n");

        //partie a finir
        /*
        if (strncmp(nom, ) == 0 && strncmp(mdp_saisi, ) == 0)

        else
        {
            printf("Combinaison incorrecte ! \n\n");
            menu_apprenti_1();
        }*/
    }
    void menu_enseignant_1 (){ // a finir
        char nom [20];
        char mdp_saisi[20];

        printf ("  +------------------------------------+\n");
        printf ("  + Vous avez choisi enseignant :      +\n");
        printf ("  +                                    +\n");
        printf ("  + Entrer votre nom :                 +\n");
        printf ("  + ");
        getchar();
        fgets (nom, 20, stdin);
        printf ("  + Entrer votre mot de passe :        +\n");
        printf ("  + ");
        fgets (mdp_saisi, 20, stdin);
        printf ("  +------------------------------------+\n");
            //parcourir tout le fichier enseigant et verifier si le nom saisi existe et que le mdp saisi est bien attribué a ce nom
            //si oui passer au menu suivant
            //si non recommencer


        //partie a finir
        /*
        if (strncmp(nom, ) == 0 && strncmp(mdp_saisi, ) == 0) // comparais le nom saisie au nom present dans le fichier et regarder si le mdp correspond

        else
        {
            printf("Combinaison incorrecte ! \n\n");
            menu_enseignant_1 ();
        }*/
    }
    void menu_entreprise_1 (){  //a finir
        char nom [20];
        char mdp_saisi[20];

        printf ("  +------------------------------------+\n");
        printf ("  + Vous avez choisi entreprise :      +\n");
        printf ("  +                                    +\n");
        printf ("  + Entrer votre nom :                 +\n");
        printf ("  + ");
        getchar();
        fgets (nom, 20, stdin);
        printf ("  + Entrer votre mot de passe :        +\n");
        printf ("  + ");
        fgets (mdp_saisi, 20, stdin);
        printf ("  +------------------------------------+\n");


        //partie a finir
        /*
        if (strncmp(nom, ) == 0 && strncmp(mdp_saisi, ) == 0) // comparais le nom saisie au nom present dans le fichier et regarder si le mdp correspond

        else
        {
            printf("Combinaison incorrecte ! \n\n");
            menu_entreprise_1 ();
        }*/
    }
    void menu_admin_1 (){  //marche correctement
        char nom [20];
        char mdp_saisi[20];

        printf ("  +------------------------------------+\n");
        printf ("  + Vous avez choisi Administrateur :  +\n");
        printf ("  +                                    +\n");
        printf ("  + Entrer votre nom :                 +\n");
        printf ("  + ");
        getchar ();
        fgets (nom, 20, stdin);
        printf ("  + Entrer votre mot de passe :        +\n");
        printf ("  + ");
        fgets (mdp_saisi, 20, stdin);
        printf ("  +------------------------------------+\n");

        if (strncmp(nom, "admin", 5) == 0 && strncmp(mdp_saisi, "password", 8) == 0)
            ajouter_au_fic();
        else
        {
            printf("Combinaison incorrecte ! \n\n");
            menu_admin_1 ();
        }
    }


    // 2)   fonction pour le menu apres verification des noms et mdp
    void menu_apprentie_2 (){ // a finir
    int choix;

    printf("\n\nVous avez bien ete connecte en tant qu'apprentie\n");
    printf("Vous pouvez maintenant acceder a : \n\n");

    printf("\n1. Afficher votre profil      ");
    printf("\n2.                            ");
    printf("\n3.                            ");
    printf("\n4. retourner au menu principal  ");

    scanf ("%d", &choix);
        switch  (choix)
            {
            case 1 :

                break;

            case 2 :

                break;

            case 3 :

                break;

            case 4:
                menu_principal();
                break;
            }
    }
    void menu_enseignant_2 (){ // a finir
    int choix;

    printf("\n\nVous avez bien ete connecte en tant qu'apprentie\n");
    printf("Vous pouvez maintenant acceder a : \n\n");

    printf("\n1. Afficher votre profil      ");
    printf("\n2.                            ");
    printf("\n3.                            ");
    printf("\n4. retourner au menu principal  ");

    scanf ("%d", &choix);
        switch  (choix)
            {
            case 1 :

                break;

            case 2 :

                break;

            case 3 :

                break;

            case 4:
                menu_principal();
                break;
            }
    }
    void menu_entreprise_2 (){ // a finir
    int choix;

    printf("\n\nVous avez bien ete connecte en tant qu'apprentie\n");
    printf("Vous pouvez maintenant acceder a : \n\n");

    printf("\n1. Afficher votre profil      ");
    printf("\n2.                            ");
    printf("\n3.                            ");
    printf("\n4. retourner au menu principal  ");

    scanf ("%d", &choix);
        switch  (choix)
            {
            case 1 :

                break;

            case 2 :

                break;

            case 3 :

                break;

            case 4:
                menu_principal();
                break;
            }
    }



//main
void main(){
    printf ("  +-------------------------------------------------------+\n");
	printf ("  + Bonjour ce programme sert a la gestion des apprentis  +\n");
    printf ("  +-------------------------------------------------------+\n\n\n");
    menu_principal();
}
