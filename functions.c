#include "time.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
void sleep_clock(clock_t duree) 
{ 
	clock_t time_out = clock(); 
	while((time_out + duree) > clock()); 
} 

typedef struct Joueur Joueur;
struct Joueur
{
	int point_d_energie;
	float point_d_action;
	int pos_x;
	int pos_y;
	char* name;
	char nametag[6];
	int orientation; 
	int statut; 

};

typedef struct Plateau Plateau; 
struct Plateau {
	char tab[10][10];
	int etat_partie;
};

typedef struct EnergyCell EnergyCell;
struct EnergyCell
{
	unsigned int pos_energie_x;
	unsigned int pos_energie_y;
	unsigned int valeur_energie;
};

enum NotificationType
{
	cycle_info = 0,
	game_started = 1,
	game_finished = 2,
	client_dead = 3,
	client_win = 4
};

/*
char nametag(char* identifiant)
{
	
}
*/
int selfid(Joueur joueur)
{
	printf("%s", joueur.nametag);
	return 0;
}

int selfstats(Joueur joueur) 
{
	printf("%s", joueur.point_d_energie);
	return 0;
}
/*
int gather(Joueur joueur) 
{
	if tab[joueur.pos_y][joueur.pos_x] == "energy"
}

int next() 
{

}
*/



/*int leftfwd(char** tab, float point_d_action, int orientation, Joueur joueur, int i, int j) 
{
	if (orientation == 0) 
	{
		if (j - 1 >= 0)
		{
			if (tab[i][j - 1] == "joueur" )
			{
				printf("ko\n"); 
			}
			else
			{
				tab[i][j - 1] = "joueur";
				tab[i][j] = "empty";
				joueur.pos_x--;
				orientation = (orientation + 3) % 4; 
				point_d_action--;
			}
		}
		else 
		{
			printf("Mouvement impossible, vous avez atteint la limite du plateau\n");
		}
	}

	if (orientation == 1) 
	{
		if (i - 1 >= 0)
		{
			if (tab[i - 1][j] == "joueur" ) 
			{
				printf("ko\n");
			}
			else 
			{
				tab[i - 1][j] = "joueur";
				tab[i][j] = "empty";
				joueur.pos_y--;
				orientation = (orientation + 3) % 4; 
				point_d_action--;
			}
		}
		else 
		{
			printf("Mouvement impossible, vous avez atteint la limite du plateau\n");
		}
	}

	if (orientation == 2) 
	{
		if (j + 1 << 10)
		{
			if (tab[i][j + 1] == "joueur" ) 
			{
				printf("ko\n");
			}
			else 
			{
				tab[i][j + 1] = "joueur";
				tab[i][j] = "empty";
				joueur.pos_x++;
				orientation = (orientation + 3) % 4; 
				point_d_action--;
			}
		}
		else 
		{
			printf("Mouvement impossible, vous avez atteint la limite du plateau\n");
		}
	}

	if (orientation == 3) 
	{
		if (i + 1 << 10)
		{
			if (tab[i + 1][j] == "joueur") 
			{
				printf("ko\n");
			}
			else 
			{
				tab[i + 1][j] = "joueur";
				tab[i][j] = "empty";
				joueur.pos_y++;
				orientation = (orientation + 3) % 4; 
				point_d_action--;
			}
		}
		else 
		{
			printf("Mouvement impossible, vous avez atteint la limite du plateau\n");
		}
	}
	return tab[i][j];
}



int rightfwd(char** tab, float point_d_action, int orientation, Joueur joueur, int i, int j) 
{
	
	if (orientation == 0) 
	{
		if (j + 1 <= 10)
		{
			if (tab[i][j + 1] == "joueur" ) 
			{
				printf("ko\n"); 
			}
			else 
			{
				tab[i][j + 1] = "joueur";
				tab[i][j] = "empty";
				joueur.pos_x--;
				orientation = (orientation + 3) % 4; 
				point_d_action--;
			}
		}
		else 
		{
			printf("Mouvement impossible, vous avez atteint la limite du plateau\n");
		}
	}

	if (orientation == 1) 
	{
		if (i + 1 <= 10)
		{
			if (tab[i + 1][j] == "joueur" ) 
			{
				printf("ko\n");
			}
			else 
			{
				tab[i + 1][j] = "joueur";
				tab[i][j] = "empty";
				joueur.pos_y--;
				orientation = (orientation + 3) % 4; 
				point_d_action--;
			}
		}
		else 
		{
			printf("Mouvement impossible, vous avez atteint la limite du plateau\n");
		}
	}

	if (orientation == 2) 
	{
		if (j - 1 >= 0)
		{
			if (tab[i][j - 1] == "joueur" ) 
			{
				printf("ko\n");
			}
			else 
			{
				tab[i][j - 1] = "joueur";
				tab[i][j] = "empty";
				joueur.pos_x++;
				orientation = (orientation + 3) % 4; 
				point_d_action--;
			}
		}
		else 
		{
			printf("Mouvement impossible, vous avez atteint la limite du plateau\n");
		}
	}

	if (orientation == 3) 
	{
		if (i - 1 >= 0)
		{
			if (tab[i - 1][j] == "joueur") 
			{
				printf("ko\n");
			}
			else 
			{
				tab[i - 1][j] = "joueur";
				tab[i][j] = "empty";
				joueur.pos_y++;
				orientation = (orientation + 3) % 4; 
				point_d_action--;
			}
		}
		else 
		{
			printf("Mouvement impossible, vous avez atteint la limite du plateau\n");
		}
	}
	return tab[i][j];
}

int forward(char** tab, float point_d_action, int orientation, Joueur joueur, int i, int j)
{
	if (orientation == 0)
	{
		if (i - 1 << 0)
		{
			printf("ko\n");
			
		}
		else if (tab[i - 1][j] == "empty")
		{
			tab[i - 1][j] = "joueur";
			tab[i][j] = "empty";
			joueur.pos_y--;
			point_d_action = point_d_action - 0.5;/
		}
		else if (tab[i - 1][j] = "joueur")
		{
			printf("Mouvement impossible, vous ne pouvez pas prendre la place d'un adversaire\n");
		}		
		
	}

	if (orientation == 1)
	{
		if (j + 1 >>9)
		{
			printf("ko\n");
		}
		else if (tab[i][j + 1] == "empty")
		{
			tab[i][j + 1] = "joueur";
			tab[i][j] = "empty";
			joueur.pos_x++;
			point_d_action = point_d_action - 0.5;
		}
		else if (tab[i - 1][j] = "joueur")
		{
			printf("Mouvement impossible, vous ne pouvez pas prendre la place d'un adversaire\n");
		}		
	}

	if (orientation == 2)
	{
		if (i + 1 >> 9)
		{
			printf("ko\n");
		}
		else if (tab[i + 1][j] == "empty")
		{
			tab[i + 1][j] = "joueur";
			tab[i][j] = "empty";
			joueur.pos_y++;
			point_d_action = point_d_action - 0.5;
		}
		else if (tab[i + 1][j] = "joueur")
		{
			printf("Mouvement impossible, vous ne pouvez pas prendre la place d'un adversaire\n");
		}		
	}


	if (orientation == 3)
	{
		if (j - 1 << 0)
		{
			printf("ko\n");
		}
		else if (tab[i][j - 1] == "empty")
		{
			tab[i][j - 1] = "joueur";
			tab[i][j] = "empty";
			joueur.pos_x--;
			point_d_action = point_d_action - 0.5;
		}
		else if (tab[i][j - 1] = "joueur")
		{
			printf("Mouvement impossible, vous ne pouvez pas prendre la place d'un adversaire\n");
		}		
	}
	return tab[i][j];
}




int backward(int tab[i][j], float point_d_action, int orientation)
{
	if (orientation == 0)
	{
		if (i + 1 >> 9)
		{
			printf("ko\n");
		}
		else if (tab[i - 1][j] == "empty")
		{
			tab[i + 1][j] = "joueur";
			tab[i][j] = "empty";
			joueur.pos_y++;
			point_d_action = point_d_action - 0.5;/
		}
		else if (tab[i - 1][j] = "joueur")
		{
			printf("Mouvement impossible, vous ne pouvez pas prendre la place d'un adversaire\n");
		}		
		
	}

	if (orientation == 1)
	{
		if (j - 1 << 0)
		{
			printf("ko\n");
		}
		else if (tab[j - 1][j] == "empty")
		{
			tab[i][j - 1] = "joueur";
			tab[i][j] = "empty";
			joueur.pos_x--;
			point_d_action = point_d_action - 0.5;/
		}
		else if (tab[i][j - 1] = "joueur")
		{
			printf("Mouvement impossible, vous ne pouvez pas prendre la place d'un adversaire\n");
		}		
	}

	if (orientation == 2)
	{
		if (i - 1 << 0)
		{
			printf("ko\n");
			
		}
		else if (tab[i][j- 1] == "empty")
		{
			tab[i][j - 1] = "joueur";
			tab[i][j] = "empty";
			joueur.pos_y--;
			point_d_action = point_d_action - 0.5;/
		}
		else if (tab[i - 1][j] = "joueur")
		{
			printf("Mouvement impossible, vous ne pouvez pas prendre la place d'un adversaire\n");
		}				
	}


	if (orientation == 3)
	{
		if (j + 1 >> 9)
		{
			printf("ko\n");
		}
		else if (tab[i][j + 1] == "empty")
		{
			tab[i][j + 1] = "joueur";
			tab[i][j] = "empty";
			joueur.pos_x++;
			point_d_action = point_d_action - 0.5;/
		}
		else if (tab[i][j + 1] = "joueur")
		{
			printf("Mouvement impossible, vous ne pouvez pas prendre la place d'un adversaire\n");
		}		
}
*/

int bondir(int point_d_energie, char** tab, int orientation, Joueur joueur, int i, int j)
{
	if (orientation == 0)
	{
		if (tab[i][j - 2] == '|')
		{
			printf("Mouvement impossible, vous etes en face des limites du plateau\n");
			
		}
		else if (tab[i][j - 2] == 'x')
		{
			tab[i][j] = tab[i ][j - 2];
			point_d_energie = point_d_energie - 2;
			return tab[i][j];
			
		}
		else if (tab[i][j - 2] ==  '1'|| tab[i ][j - 2]== '2' || tab[i ][j - 2] == '3' || tab[i ][j - 2] == '4')
		{
			printf("Mouvement impossible, vous ne pouvez pas prendre la place d'un adversaire\n");
		}

	}
	if (orientation == 1)
	{
		if (tab[i - 2][j] == '-')
		{
			printf("Mouvement impossible, vous etes en face des limites du plateau\n");
			
		}
		else if (tab[i - 2][j] == 'x')
		{
			tab[i][j] = tab[i - 2][j] ;
			point_d_energie = point_d_energie - 2;
			return tab[i][j];
			
		}
		else if (tab[i - 2][j] == '1' || tab[i - 2][j] ==  '2' || tab[i - 2][j] == '3' || tab[i - 2][j] == '4')
		{
			printf("Mouvement impossible, vous ne pouvez pas prendre la place d'un adversaire\n");
		}
	}

	if (orientation == 2)
	{
		if (tab[i][j + 2] == '|')
		{
			printf("Mouvement impossible, vous etes en face des limites du plateau\n");
			
		}
		else if (tab[i][j + 2] == 'x')
		{
			tab[i][j] = tab[i][j + 2];
			point_d_energie = point_d_energie - 2;
			return tab[i][j];
			
		}
		else if (tab[i][j + 2] == '1' || tab[i][j + 2] == '2' || tab[i][j + 2] == '3' || tab[i][j + 2] == '4')
		{
			printf("Mouvement impossible, vous ne pouvez pas prendre la place d'un adversaire\n");
		}		
	}

	if (orientation == 3)
	{
		if (tab[i + 2][j] == '-')
		{
			printf("Mouvement impossible, vous etes en face des limites du plateau\n");
			
		}
		else if (tab[i + 2][j] == 'x')
		{
			tab[i][j] = tab[i + 2][j];
			point_d_energie = point_d_energie - 2;
			return tab[i][j];
			
		}
		else if (tab[i + 2][j] == '1' || tab[i + 2][j] == '2' || tab[i + 2][j] == '3' || tab[i + 2][j] == '4')
		{
			printf("Mouvement impossible, vous ne pouvez pas prendre la place d'un adversaire\n");
		}		
	}
	
	return tab[i][j];
}


void right(int orientation)
{
	orientation = (orientation + 1) % 3;  
}

void left(int orientation)
{
	orientation = (orientation - 1) % 3;  
}
/*
char looking(int orientation)
{
	char data = " ";
	switch (orientation)
	{
		case 0: data = "gauche"; break;
		case 1: data = "haut"; break;
		case 2: data = "droite"; break;
		case 3: data = "bas"; break;

	}
	return data;
}
*/
int mouvement_horizontal(int point_de_mouvement)
{
	int tmp_data = 0;
	for (int i = 0; i < point_de_mouvement; i++)
	{
		tmp_data = i;
	}
	return tmp_data ;
}

bool test_quantiter_point_action(int point_d_action, int commande)
{
	if (point_d_action >= commande)
	{
		return true;
	}
	return false;
}

char commande(int point_d_energie, float point_d_action,  char *action, int **tab, int orientation, char *action_joueur, int i, int j)
{
	if(strcmp(action,"forward") == 0)
		deplacer_haut(tab[i][j], point_d_action, orientation);

	else if(strcmp(action, "backward") == 0)
		deplacer_bas(tab[i][j], point_d_action, orientation);

	else if(strcmp(action == "leftfwd")==0)
		deplacer_gauche(tab[i][j], point_d_action, orientation);

	else if(strcmp(action, "rightfwd")==0)
		deplacer_droite(tab[i][j], point_d_action, orientation);

	else if(strcmpt(action, "right")==0)
	{
		point_d_action = point_d_action - 0.5;
		pivoter_right(orientation);
	}

	else if(strcmp(action, "left") == 0)
	{
		point_d_action = point_d_action - 0.5;
		pivoter_left(orientation);
	}

	else if(strcmp(action, "looking") == 0) 
		return 1;

	else if(strcmp(action, "gather") == 0 )
		point_d_action = point_d_action - 1;

	else if(action == "watch")
		???

	else if(action == "attack")
	{
		vague_energie(point_d_action, point_d_energie, orientation);
	}

	else if(action == "selfid")
		point_d_action = point_d_action - 1;

	else if(action == "selfstats")
		return 42;

	else if(action == "inspect")
		point_d_action = point_d_action - 0.5;

	else if(action == "next")
		return point_d_action;

	else if(action == "jump")
		bondir(point_d_energie, tab[i][j], orientation);
}
/*
void vague_energie(float point_d_action, int point_d_energie, int orientation, int tab[i][j])
{
	
	if (orientation == 1) //Nord
	{								//Case gauche										Case droite													Case en face										Case haut
		if ((tab[i - 1][j - 1] =< '4' || tab[i - 1][j - 1] == "empty") && (tab[i - 1][j + 1] =< '4' || tab[i - 1][j + 1] == "empty") && (tab[i - 1][j] =< '4' || tab[i - 1][j] == "empty") && (tab[i - 2][j] =< '4' || tab[i - 2][j] == "empty"))
		{
			
		}
		point_d_action = point_d_action - 0.5;
		point_d_energie--;
	}

	if (orientation == 2 ) //Est
	{								//Case gauche										Case droite													Case en face										Case haut
		if ((tab[i - 1][j + 1] =< '4' || tab[i - 1][j + 1] == "empty") && (tab[i + 1][j + 1] =< '4' || tab[i + 1][j + 1] == "empty") && (tab[i][j + 1] =< '4' || tab[i][j + 1] == "empty") && (tab[i][j + 2] =< '4' || tab[i][j + 2] == "empty"))
		{
			//point_d_energie = point_d_energie - 2;
		}
		point_d_action = point_d_action - 0.5;
		point_d_energie--;
	}

	if (orientation == 3 ) //Sud
	{
		if ((tab[i + 1][j + 1] =< '4' || tab[i + 1][j + 1] == "empty") && (tab[i + 1][j - 1] =< '4' || tab[i + 1][j - 1] == "empty") && (tab[i + 1][j] =< '4' || tab[i + 1][j] == "empty") && (tab[i + 2][j] =< '4' || tab[i + 2][j] == "empty"))
		{
			//point_d_energie = point_d_energie - 2;
		}
		point_d_action = point_d_action - 0.5;
		point_d_energie--;
	}

	if (orientation == 0 ) //Ouest
	{
		if ((tab[i + 1][j - 1] =< '4' || tab[i + 1][j - 1] == "empty") && (tab[i - 1][j + 1] =< '4' || tab[i - 1][j - 1] == "empty") && (tab[i][j - 1] =< '4' || tab[i][j - 1] == "empty") && (tab[i][j - 2] =< '4' || tab[i][j - 2] == "empty"))
		{
			//point_d_energie = point_d_energie - 2;
		}
		point_d_action = point_d_action - 0.5;
		point_d_energie--;
	}
}

char decla_tab(FILE* fichier_tab)
{
	
	int i = 0;
	while(!feof(fichier_tab) && i < 20)
	{
		
		int j = 0;

		// On récupere la ligne courante du fichier
		fgets(szbuff,20,fichier_tab);
		
		// On decoupe la ligne selon le charactere de séparation SEP (" ")
		token = strtok(szbuff,SEP);

		// On lit les éléments découpés un à un et on les stocke dans le tableau Tab
		while(token != NULL && j < CMAX)
		{
			// On stocke la valeur lue dans le tableau
			Tab[i][j] = atoi(token);
			// On incremente le compteur des ordonnées
			j++;
		}
		
		// On incrémente le compteur des abscisses
		i++;
	}
	fclose(fichier_tab);
	return Tab[i][j];
}

char nom_rand()
{
	if 
}

void main(int argc, char const *argv[])
{
	struct Plateau plat;
	struct joueur J_1, J_2, J_3, J_4;

	//FILE* fichier_map =  fopen("map.txt", "r+");
	//int tab[15][15] = decla_tab(fichier_map);

	int map[12][12] = plat.tab[12][12];
	J_1.map[1][1];
	J_2.map[10][1];
	J_3.map[10][10];
	J_4.map[1][10];

	while(J_1.point_d_energie != 0 && J_2.point_d_energie != 0 && J_3.point_d_energie != 0 && J_4.point_d_energie != 0 )
	{
		sleep_clock(9000);

		//point_d_energie = point_d_energie - 2;
	}
	return 0;
}
*/
