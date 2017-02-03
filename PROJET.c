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
	int salaire;
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
	// 1)   fonctions saisi UN apprenti/enseignant/entreprise (marche correctement, pb de getchar parfois)
	struct Apprenti saisir_apprenti (){
		struct Apprenti apprenti;

		printf (" Entrer le prenom de l'apprenti : ");
		getchar();
		fgets (apprenti.prenom, 20, stdin);
		printf ("\n Entrer le nom de l'apprenti : ");
		fgets (apprenti.nom, 20, stdin);
		printf ("\n Entrer le salaire de l'apprenti : ");
		scanf ("%d", &apprenti.salaire );
		printf ("\n Entrer le mot de passe de l'apprenti : ");
		getchar();
		fgets (apprenti.mdp_apprenti, 20, stdin);
		return apprenti;
	}
	struct Enseignant saisir_enseignant (){
		struct Enseignant enseignant;

		printf (" Entrer le prenom de l'enseignant : ");
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

		printf (" Entrer le nom de l'entreprise :");
		getchar();
		fgets (entreprise.nom, 20, stdin);
		printf ("\n vous allez maintenant entrer l'adresse \n");
		printf (" Entrer le numero de rue de l'entreprise : ");
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



	// 2)   fonction afficher UN apprenti/enseignant/entreprise (marche pas)
	void afficher_apprenti (struct Apprenti apprenti){
		printf ("\n +----------------------------------------------------+");
		printf ("\n + %s ", apprenti.prenom);
		printf ("\n + %s ", apprenti.nom);
		printf ("\n + Salaire : %d euro", apprenti.salaire);
		printf ("\n + MDP : %s ", apprenti.mdp_apprenti);
		printf ("\n +----------------------------------------------------+\n");
	}
	void afficher_enseignant (struct Enseignant enseignant){
		printf ("\n +----------------------------------------------------+");
		printf ("\n + %s ", enseignant.prenom);
		printf ("\n + %s ", enseignant.nom);
		printf ("\n + Bureau : %s ", enseignant.bureau);
		printf ("\n + MDP : %s ", enseignant.mdp_enseignant);
		printf ("\n +----------------------------------------------------+");
	}
	void afficher_entreprise (struct Entreprise entreprise){
		printf ("\n +----------------------------------------------------+");
		printf ("\n + %s ", entreprise.nom);
		printf ("\n + %d, %s ", entreprise.adresse_entreprise.num_rue,entreprise.adresse_entreprise.nom_rue );
		printf ("\n + %d, %s  ", entreprise.adresse_entreprise.code_postal, entreprise.adresse_entreprise.ville, entreprise.adresse_entreprise.pays );
		printf ("\n + %s ", entreprise.adresse_entreprise.pays);
		printf ("\n + MDP : %s ", entreprise.mdp_entreprise);
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
			printf ("\n  + Vous avez decider d'ajouter un element a un fichier.      +");
			printf ("\n  + Choisissez ce que vous vouler ajouter :                   +");
			printf ("\n  +-----------------------------------------------------------+");
			printf ("\n  +                                                           +");
			printf ("\n  + 1. Un apprenti                                            +");
			printf ("\n  + 2. Un enseignant                                          +");
			printf ("\n  + 3. Une entreprise                                         +");
			printf ("\n  +                                                           +");
			printf ("\n  + 4. Revenir au menu principal                              +");
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
        // a)   Afficher tout les apprentis
        void afficher_tout_apprenti_fic (){ // (marche corretement)
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

        // b)   Afficher tout les enseignants
        void afficher_tout_enseignant_fic (){ // (marche correctement)
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


        //c)    Afficher toute les entreprises
        void afficher_tout_entreprise_fic (){ // (marche correctement)
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





//Fonctions menu
    // 0)   Menu principale celui qui est executer dans le main
    void menu_principal (){
        int choix;
    do{
        printf ("  +-------------------------+\n");
        printf ("  +      Qui ete vous ?     +\n");
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
                printf ("\n\n +---------------------------+");
                printf ("\n +   Au revoir, a bientot.   +");
                printf ("\n +---------------------------+\n\n\n");
                break;
            }
    }while (choix > 5);
    }

    // 1)   Fonctions pour le menu apres 1er choix
    void menu_apprenti_1 (){  // a finir
        char nom [20];
        char mdp_saisi[20];

        printf ("  +------------------------------------+\n");
        printf ("  + Vous avez choisi apprenti :        +\n");
        printf ("  +------------------------------------+\n");
        printf ("  +                                    +\n");
        printf ("  + Entrer votre nom :                 +\n");
        printf ("  + ");
        getchar();
        fgets (nom, 20, stdin);
        printf ("  + Entrer votre mot de passe :        +\n");
        printf ("  + ");
        fgets (mdp_saisi, 20, stdin);
        printf ("  +------------------------------------+\n");

        //parcourir tout le fichier apprenti et verifier si le nom saisi existe et que le mdp saisi est bien attribué a ce nom
        //si oui passer au menu suivant
        //si non recommencer
        //partie a finir

        /*if () trouver la condition
            menu_apprenti_2 ();
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
        printf ("  +------------------------------------+\n");
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
        if () trouver la condition
            menu_enseignant_2 ();
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
        printf ("  +------------------------------------+\n");
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
        if ()  trouver la condition
            menu_entreprise_2 ();
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
        printf ("  +------------------------------------+\n");
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
    printf("\n +    Vous avez bien ete connecte en tant qu'apprentie    +");
    printf("\n +            Vous pouvez maintenant acceder a :          +");
    printf("\n +--------------------------------------------------------+");
    printf("\n +                                                        +");
    printf("\n + 1. Afficher votre profil                               +");
    printf("\n +                                                        +");
    printf("\n + 2. retourner au menu principal                         +");
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
    printf("\n +    Vous avez bien ete connecte en tant qu'enseignant   +");
    printf("\n +           Vous pouvez maintenant acceder a :           +");
    printf("\n +--------------------------------------------------------+");
    printf("\n +                                                        +");
    printf("\n + 1. Afficher votre profil                               +");
    printf("\n + 2. Ajouter un element a un fichier                     +");
    printf("\n + 3. Modifier un element d'un fichier                    +");
    printf("\n + 4. Supprimer un element d'un dossier                   +");
    printf("\n +                                                        +");
    printf("\n + 5. retourner au menu principal                         +");
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

                break;

            case 4:

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
    printf("\n +    Vous avez bien ete connecte en tant qu'entreprise   +");
    printf("\n +           Vous pouvez maintenant acceder a :           +");
    printf("\n +--------------------------------------------------------+");
    printf("\n +                                                        +");
    printf("\n + 1. Afficher votre profil                               +");
    printf("\n + 2. Aficher la liste de vos apprentis                   +");
    printf("\n +                                                        +");
    printf("\n + 3. retourner au menu principal                         +");
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
    printf("\n +    Vous avez bien ete connecte en tant qu'admin        +");
    printf("\n +           Vous pouvez maintenant acceder a :           +");
    printf("\n +--------------------------------------------------------+");
    printf("\n +                                                        +");
    printf("\n + 1. ajouter un element a un fichier                     +");
    printf("\n + 2. Aficher tout les apprentis du fichier               +");
    printf("\n + 3. Afficher tout les enseignants du fichier            +");
    printf("\n + 4. Afficher toute les entreprises du fichier           +");
    printf("\n + 5. Modifier un element d'un fichier                    +");
    printf("\n + 6. Supprimer un element d'un fichier                   +");
    printf("\n +                                                        +");
    printf("\n + 7. retourner au menu principal                         +");
    printf("\n +--------------------------------------------------------+\n\n");

    scanf ("%d", &choix);
        switch  (choix)
            {
            case 1 :
                ajouter_au_fic();
                break;

            case 2 :
                afficher_tout_apprenti_fic();
                break;

            case 3 :
                afficher_tout_enseignant_fic();
                break;

            case 4 :
                afficher_tout_entreprise_fic();
                break;

            case 5 :

                break;

            case 6 :

                break;

            case 7 :
                menu_principal();
                break;
            }
    }while (choix > 7);
    }

//main
void main(){
    printf ("  +----------------------------------------------------------+\n");
	printf ("  +   Bonjour ce programme sert a la gestion des apprentis   +\n");
    printf ("  +----------------------------------------------------------+\n\n\n");
    menu_principal();

}
