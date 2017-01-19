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
	//fonctions saisi UN apprenti/enseignant/entreprise
	struct Apprenti saisir_apprenti (){
		struct Apprenti apprenti;

		printf ("\n Entrer le prenom de l'apprenti : ");
		fgets (apprenti.prenom, 20, stdin);
		printf ("\n Entrer le nom de l'apprenti : ");
		fgets (apprenti.nom, 20, stdin);
		printf ("\n Entrer le salaire de l'apprenti : ");
		scanf ("%f", &apprenti.salaire );
		printf ("\n Entrer le mot de passe de l'apprenti : ");
		fgets (apprenti.mdp_apprenti, 20, stdin);
		return apprenti;
	}
	struct Enseignant saisir_enseignant (){
		struct Enseignant enseignant;

		printf ("\n Entrer le prenom de l'enseignant : ");
		fgets (enseignant.prenom, 20, stdin);
		printf ("\n Entrer le nom de l'enseignant : ");
		fgets (enseignant.nom, 20, stdin);
		printf ("\n Entrer le bureau de l'enseignant : ");
		fgets (enseignant.bureau, 20, stdin);
		printf ("\n Entrer le mot de passe de l'enseignant : ");
		fgets (enseignant.mdp_enseignant, 20, stdin);
		return enseignant;
	}
	struct Entreprise saisir_entreprise (){
		struct Entreprise entreprise;

		printf ("\n Entrer le nom de l'entreprise :");
		fgets (entreprise.nom, 20, stdin);
		printf ("\n vous allez maintenant entrer l'adresse \n");
		printf ("Entrer le numero de rue de l'entreprise : ");
		scanf("%d", &entreprise.adresse_entreprise.num_rue);
		printf ("\n Entrer le nom de rue de l'entreprise : ");
		fgets (entreprise.adresse_entreprise.nom_rue, 80, stdin);
		printf ("\n Entrer le code postal de l'entreprise : ");
		scanf ("%d", &entreprise.adresse_entreprise.code_postal);
		printf ("\n Entrer le nom de la ville de l'entreprise : ");
		fgets (entreprise.adresse_entreprise.ville, 20, stdin);
		printf ("\n Entrer le pays de l'entreprise : ");
		fgets (entreprise.adresse_entreprise.pays, 20, stdin);
		printf ("\n Entrer le mot de passe de l'entreprise : ");
		fgets (entreprise.mdp_entreprise, 20, stdin);
		return entreprise;
	}




	//fonction afficher UN apprenti/enseignant/entreprise
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


	//fonction pour ajouter un element a un dossier donc demander lequel des trois fichier (apprentie,enseignant,entreprise) puis faire apelle a une fonction saisi
	void ajouter_au_fic (){
		int choix;
		struct Apprenti apprenti;
		struct Enseignant enseignant;
		struct Entreprise entreprise;

		do {
			printf ("Vous avez decider d'ajouter un element a un fichier.\n");
			printf ("Choisissez ce que vous vouler ajouter : \n");
			printf ("\n 1. Un apprenti\n");
			printf ("\n 2. Un enseignant\n");
			printf ("\n 3. Un entreprise\n");
			scanf("%d", &choix);

			switch (choix)
				{
				case 1 :
					apprenti = saisir_apprenti ();
					FILE *fichier_apprenti = fopen("apprenti_fic.dat", "a");
					fwrite(&apprenti, sizeof(struct Apprenti), 1, fichier_apprenti);
					fclose(fichier_apprenti);
					break;

				case 2 :
					enseignant = saisir_enseignant ();
					FILE *fichier_enseignant = fopen("enseignant_fic.dat", "a");
					fwrite(&enseignant, sizeof(struct Enseignant), 1, fichier_enseignant);
					fclose(fichier_enseignant);
					break;

				case 3 :
					entreprise = saisir_entreprise ();
					FILE *fichier_entreprise = fopen("entreprise_fic.dat", "a");
					fwrite(&entreprise, sizeof(struct Entreprise), 1, fichier_entreprise);
					fclose(fichier_entreprise);
					break;
				}
		}while (choix > 3);
	}







//fonctions pour le menu apres 1er choix
void menu_apprenti (){
	char nom [20];
	char mdp_saisi[20];

    printf ("  +------------------------------------+\n");
    printf ("  + Vous avez choisi apprenti :        +\n");
	printf ("  +                                    +\n");
	printf ("  + Entrer votre nom :                 +\n");
	fgets (nom, 20, stdin);
	printf ("  + Entrer votre mot de passe :        +\n");
	fgets (mdp_saisi, 20, stdin);
    printf ("  +------------------------------------+\n");

		//parcourir tout le fichier apprenti et verifier si le nom saisi existe et que le mdp saisi est bien attribué a ce nom
		//si oui passer au menu suivant
		//si non recommencer
}
void menu_enseignant (){
  	char nom [20];
	char mdp_saisi[20];

	printf ("  +------------------------------------+\n");
	printf ("  + Vous avez choisi enseignant :      +\n");
	printf ("  +                                    +\n");
	printf ("  + Entrer votre nom :                 +\n");
	fgets (nom, 20, stdin);
	printf ("  + Entrer votre mot de passe :        +\n");
    fgets (mdp_saisi, 20, stdin);
	printf ("  +------------------------------------+\n");
		//parcourir tout le fichier enseigant et verifier si le nom saisi existe et que le mdp saisi est bien attribué a ce nom
		//si oui passer au menu suivant
		//si non recommencer
	}
void menu_entreprise (){
 	char nom [20];
	char mdp_saisi[20];

	printf ("  +------------------------------------+\n");
	printf ("  + Vous avez choisi entreprise :      +\n");
	printf ("  +                                    +\n");
	printf ("  + Entrer votre nom :                 +\n");
	fgets (nom, 20, stdin);
	printf ("  + Entrer votre mot de passe :        +\n");
    fgets (mdp_saisi, 20, stdin);
	printf ("  +------------------------------------+\n");
		//parcourir tout le fichier enseigant et verifier si le nom saisi existe et que le mdp saisi est bien attribué a ce nom
		//si oui passer au menu suivant
		//si non recommencer
}

void menu_admin(void)
{
 	char nom [20];
	char mdp_saisi[20];

	printf ("  +------------------------------------+\n");
	printf ("  + Vous avez choisi Administrateur :      +\n");
	printf ("  +                                    +\n");
	printf ("  + Entrer votre nom :                 +\n");
	fgets (nom, 20, stdin);
	printf ("  + Entrer votre mot de passe :        +\n");
    fgets (mdp_saisi, 20, stdin);
	printf ("  +------------------------------------+\n");
	if (strcmp(nom, "admin") == 0 && strcmp(mdp_saisi, "password") == 0)
		ajouter_au_fic();
	else 
	{
		printf("Combinaison incorrecte ! ");
		menu_admin();
	}
}

//main
void main(){
	int choix;
do{
    printf ("  +-------------------------------------------------------+\n");
	printf ("  + Bonjour ce programme sert a la gestion des apprentis  +\n");
    printf ("  +-------------------------------------------------------+\n\n\n");

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
			menu_apprenti();
			break;

		case 2 :
			menu_enseignant();
			break;

		case 3 :
			menu_entreprise();
			break;

		case 4:
			menu_admin();
			break;
		case 5 :
			printf ("\nAu revoir, a bientot.\n\n");
			break;
		}
}while (choix > 4);
}
