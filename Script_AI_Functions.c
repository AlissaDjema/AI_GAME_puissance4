#include <stdio.h>
#include <stdlib.h>
#define LIGNE 6
#define COLONNE 7
#define J1 1
#define J2 2
char grille[LIGNE][COLONNE];
char X='X';
char O='O';

void afficherGrille()
{
       int i,j;
       for (i=0;i<LIGNE;i++)//0 à 7
	   {
           printf("  +"); //Le coin haut de la grille, debut de chaque ligne
           for (j=1;j<=COLONNE;j++)//1 à 8
		   {
               printf("---+");//on dessine la ligne, on fait 8 bouts de ligne car il y a 8 colonnes.
		    }
            printf("\n %d",LIGNE-i ); //Pour afficher le numéro des lignes
			for(j=0;j<COLONNE;j=j+1)
			{
               printf("| %c ",grille[i][j]); // on alterne, en faisant une ligne de case
            }
            printf("|\n" );
       }
       printf("  ");
       for (i=0;i<COLONNE;i++)//0 à 8
	   {
           printf("+---" );//on trace la fin de grille, on dessine 8 bouts de lignes
       }
       printf("+\n" ); // Dernier coin du tableau
       printf("    1	2   3	4   5	6   7");
       printf("\n\n");
}

void remplissage()
{
/*Remplissage de la grille pour le debut du jeu:
chaque cellule contient un espace*/
    int i,j;
    for(i=0; i<=LIGNE; i++)
	{
	   for(j=0; j<=COLONNE; j++)
	   {
		   grille[i][j]=' ';
	   }
	}
}

void jeu(int joueur, char grille[LIGNE][COLONNE])
{//Le joueur choisi la colonne
   	int choix,p,resultat;
	printf("c'est au tour du joueur %d de jouer", joueur);
	printf("\nChoisissez une colonne => ");
	scanf("%d", &choix);
//Tant que la colonne choisie est pleine, le joueur doit en choisir une autre
	while((grille[0][choix-1]==X) || (grille[0][choix-1]==O)) //la dernière case de la ligne "choix-1" est pleine
	{
		printf("La colonne est pleine!\n\n");
		printf("Choisissez une autre colonne => ");
		scanf("%d", &choix);
	}
//Tant que le joueur n'entre pas une colonne valide, il doit en choisir une autre
	while((choix>7) || (choix<0))
	{
		printf("Entrez une colonne correct!\n\n");
		printf("Choisissez une colonne => ");
		scanf("%d", &choix);
	}
//On place le jeton du joueur sur la première case vide de la colonne en partant du bas.
	for(p=5; p>=0; p--)
	{
		if(grille[p][choix-1]==' ')//choix-1 car il y a la colonne 0
		{
			if(joueur==1)
			{
				grille[p][choix-1]=X;
				break;
			}
			else
			{
			 	grille[p][choix-1]=O;
			 	break;
			}
		}
	}

}
int test1(char grille[LIGNE][COLONNE])
{
	int x=0;
	for(int i=LIGNE;i>0;i--)
	{
		for(int j=0;j<COLONNE;j++)
		{
		 	if(grille[i][j]==X && grille[i][j+1]==X && grille[i][j+2]==X && grille[i][j+3]==X)//le cas du test les colonnes
	   			x= 1;
			else if(grille[i][j]==X && grille[i+1][j]==X && grille[i+2][j]==X && grille[i+3][j]==X)//le cas du test les lignes
				x=1;
		 	else if(grille[i][j]==X && grille[i+1][j+1]==X && grille[i+2][j+2]==X && grille[i+3][j+3]==X)//le cas du test les diagonals
				x=1;
		 	else if(grille[i][j]==X && grille[i-1][j+1]==X && grille[i-2][j+2]==X && grille[i-3][j+3]==X)//le cas du test les diagonals
		 					x=1;

	   }
   }
	return x;
}

int test2(char grille[LIGNE][COLONNE])
{
	int x=0;
	for(int i=LIGNE;i>0;i--)
	{
		for(int j=0;j<COLONNE;j++)
		{
        	if(grille[i][j]==O && grille[i][j+1]==O && grille[i][j+2]==O && grille[i][j+3]==O)
				x=1;
			else if(grille[i][j]==O && grille[i+1][j]==O && grille[i+2][j]==O && grille[i+3][j]==O)
				x=1;
			else if(grille[i][j]==O && grille[i+1][j+1]==O && grille[i+2][j+2]==O && grille[i+3][j+3]==O)
				x=1;
			else if(grille[i][j]==O && grille[i-1][j+1]==O && grille[i-2][j+2]==O && grille[i-3][j+3]==O)
							x=1;

	   }
   }
	return x;
}

int main()
{

   int compteur=0;
   int rejouer='o';
   int resultat;
   int fin=0;

     printf("Que la partie commence!\n\n\n\n");
     remplissage();
     afficherGrille();

     do
        	  {


	 			jeu(1,grille);
       			afficherGrille();
       			resultat=test1(grille);
        		if(resultat==1)
        		{
           			printf("Bien joue %d! Vous remportez la partie!\n",J1);
           			compteur=2;
         		}

	     	else
	 		{
	 			jeu(2,grille);
        		afficherGrille();
        		resultat=test2(grille);
           		if(resultat==1)
		  		{
             		printf("Bien joue %d! Vous remportez la partie!\n",J2);
             		compteur=2;
           		}
         	}
        		fin++;
        		if (fin==21)
        			break;
        }
    while(compteur<1);
    if(fin==21)
    {
       printf("Match Nul!");
    }
 }
