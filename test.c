//#include <time.h> 
//#include <stdio.h>
//#include <stdlib.h>

void sleep_clock(clock_t duree) 
{ 
	clock_t time_out = clock(); 
	while((time_out + duree) > clock()); 
} 

typedef struct joueur joueur; /* Permet d'appeler joueur sans rappeler que c'est un struct à chaque fois */
struct joueur
{
	int point_d_energie;
	float point_d_action;
	int pos_x;
	int pos_y;
	char* name; /* Dans quoi est utilisé name ? J'ai créé nametag pour générer un nom de joueur en règle, il faudrait faire une vérification à la création d'un nametag pour voir s'il n'est pas déjà attribué, sinon relancer la fonction pour générer un nouveau nom */
	char nametag[6];
	//char com;
	int orientation; // Orientation pren les valeurs de 0 à 3 ( 0 -> gauche, 1 -> haut, 2 -> droite et 4 -> bas)
	int statut; /* Le statut indique si le joueur peut jouer ou pas, à chaque cycle on vérifie le statut et on fait -1 s'il est supérieur à 0 pour signifier qu'un cyle a été passé */

};
typedef struct Plateau Plateau; /* Il faut encore initialiser le tableau à "empty " et implémenter les cases surcharge en "energy", puis installer les joueurs */
struct Plateau {
	char tab[10][10];
	int etat_partie;
};

typedef struct EnergyCell EnergyCell;
struct EnergyCell
	unsigned int pos_energie_x;
	unsigned int pos_energie_y;
	unsigned int valeur_energie;
};

enum NotificationType
{
	cycle_info = 0;
	game_started = 1;
	game_finished = 2;
	client_dead = 3;
	client_win = 4;
};


char nametag(char* identifiant) /* Renvoie une chaine de charactère aléatoire selon les règles (deux derniers chiffres au hasard) du jeu qui sera l'identifiant du joueur */
{
	/* A implémenter */
}

int selfid() /* Affiche l'identifiant du joueur */
{
	printf("%s", joueur.nametag);
	return 0;
}

int selfstats() /* Affiche le nombre de points d'énergie restant au joueur */
{
	printf("%s", joueur.point_d_energie);
	return 0;
}

int gather() /* Récolte de l'énergie sur une cellule qui en contient si le joueur est dessus, pas fait */
{
	if tab[joueur.pos_y][joueur.pos_x] == "energy"
	}
}
int next() /* A faire : passer son tour */
{

}

int leftfwd(int tab[i][j], float point_d_action, int orientation) 
{
	if (orientation == 0) /*l'action à suivre si le joueur regarde vers le haut*/
	{
		if (j - 1 >= 0)
		{
			if (tab[i][j - 1] == "joueur" ) /*On vérifie si la case de gauche contient un joueur*/
			{
				printf("ko\n"); /* Selon les règles deux processus ne peuvent pas rentrer en collision et on renvoie "ko" */
			}
			else /*On met à jour la position du joueur sur le tableau et ses coordonnées, on modifie son orientation et on lui retire un point d'action*/
			{
				tab[i][j - 1] = "joueur";
				tab[i][j] = "empty";
				joueur.pos_x--;
				orientation = (orientation + 3) % 4; 
				point_d_action--;
			}
		}
		else /*Sinon on est hors plateau*/
		{
			printf("Mouvement impossible, vous avez atteint la limite du plateau\n");
		}
	}

	if (orientation == 1) /*l'action à suivre si le joueur regarde vers la droite*/
	{
		if (i - 1 >= 0)
		{
			if (tab[i - 1][j] == "joueur" ) /*On vérifie si la case de gauche contient un joueur*/
			{
				printf("ko\n");
			}
			else /*On met à jour la position du joueur sur le tableau et ses coordonnées, on modifie son orientation et on lui retire un point d'action*/
			{
				tab[i - 1][j] = "joueur";
				tab[i][j] = "empty";
				joueur.pos_y--;
				orientation = (orientation + 3) % 4; 
				point_d_action--;
			}
		}
		else /*Sinon on est hors plateau*/
		{
			printf("Mouvement impossible, vous avez atteint la limite du plateau\n");
		}
	}

	if (orientation == 2) /*l'action à suivre si le joueur regarde vers le bas*/
	{
		if (j + 1 << 10)
		{
			if (tab[i][j + 1] == "joueur" ) /*On vérifie si la case de droite contient un joueur*/
			{
				printf("ko\n");
			}
			else /*On met à jour la position du joueur sur le tableau et ses coordonnées, on modifie son orientation et on lui retire un point d'action*/
			{
				tab[i][j + 1] = "joueur";
				tab[i][j] = "empty";
				joueur.pos_x++;
				orientation = (orientation + 3) % 4; 
				point_d_action--;
			}
		}
		else /*Sinon on est hors plateau*/
		{
			printf("Mouvement impossible, vous avez atteint la limite du plateau\n");
		}
	}

	if (orientation == 3) /*l'action à suivre si le joueur regarde vers la gauche*/
	{
		if (i + 1 << 10)
		{
			if (tab[i + 1][j] == "joueur") /*On vérifie si la case du bas contient un joueur*/
			{
				printf("ko\n");
			}
			else /*On met à jour la position du joueur sur le tableau et ses coordonnées, on modifie son orientation et on lui retire un point d'action*/
			{
				tab[i + 1][j] = "joueur";
				tab[i][j] = "empty";
				joueur.pos_y++;
				orientation = (orientation + 3) % 4; 
				point_d_action--;
			}
		}
		else /*Sinon on est hors plateau*/
		{
			printf("Mouvement impossible, vous avez atteint la limite du plateau\n");
		}
	}
	return tab[i][j];
}

int rightfwd(int tab[i][j], float point_d_action, int orientation) 
{
	
	if (orientation == 0) /*l'action à suivre si le joueur regarde vers le haut*/
	{
		if (j + 1 <= 10)
		{
			if (tab[i][j + 1] == "joueur" ) /*On vérifie si la case de droite contient un joueur*/
			{
				printf("ko\n"); /* Selon les règles deux processus ne peuvent pas rentrer en collision et on renvoie "ko" */
			}
			else /*On met à jour la position du joueur sur le tableau et ses coordonnées, on modifie son orientation et on lui retire un point d'action*/
			{
				tab[i][j + 1] = "joueur";
				tab[i][j] = "empty";
				joueur.pos_x--;
				orientation = (orientation + 3) % 4; 
				point_d_action--;
			}
		}
		else /*Sinon on est hors plateau*/
		{
			printf("Mouvement impossible, vous avez atteint la limite du plateau\n");
		}
	}

	if (orientation == 1) /*l'action à suivre si le joueur regarde vers la droite*/
	{
		if (i + 1 <= 10)
		{
			if (tab[i + 1][j] == "joueur" ) /*On vérifie si la case de gauche contient un joueur*/
			{
				printf("ko\n");
			}
			else /*On met à jour la position du joueur sur le tableau et ses coordonnées, on modifie son orientation et on lui retire un point d'action*/
			{
				tab[i + 1][j] = "joueur";
				tab[i][j] = "empty";
				joueur.pos_y--;
				orientation = (orientation + 3) % 4; 
				point_d_action--;
			}
		}
		else /*Sinon on est hors plateau*/
		{
			printf("Mouvement impossible, vous avez atteint la limite du plateau\n");
		}
	}

	if (orientation == 2) /*l'action à suivre si le joueur regarde vers le bas*/
	{
		if (j - 1 >= 0)
		{
			if (tab[i][j - 1] == "joueur" ) /*On vérifie si la case de droite contient un joueur*/
			{
				printf("ko\n");
			}
			else /*On met à jour la position du joueur sur le tableau et ses coordonnées, on modifie son orientation et on lui retire un point d'action*/
			{
				tab[i][j - 1] = "joueur";
				tab[i][j] = "empty";
				joueur.pos_x++;
				orientation = (orientation + 3) % 4; 
				point_d_action--;
			}
		}
		else /*Sinon on est hors plateau*/
		{
			printf("Mouvement impossible, vous avez atteint la limite du plateau\n");
		}
	}

	if (orientation == 3) /*l'action à suivre si le joueur regarde vers la gauche*/
	{
		if (i - 1 >= 0)
		{
			if (tab[i - 1][j] == "joueur") /*On vérifie si la case du bas contient un joueur*/
			{
				printf("ko\n");
			}
			else /*On met à jour la position du joueur sur le tableau et ses coordonnées, on modifie son orientation et on lui retire un point d'action*/
			{
				tab[i - 1][j] = "joueur";
				tab[i][j] = "empty";
				joueur.pos_y++;
				orientation = (orientation + 3) % 4; 
				point_d_action--;
			}
		}
		else /*Sinon on est hors plateau*/
		{
			printf("Mouvement impossible, vous avez atteint la limite du plateau\n");
		}
	}
	return tab[i][j];
}

int forward(int tab[i][j], float point_d_action, int orientation)
{
	if (orientation == 0)
	{
		if (i - 1 << 0)
		{
			printf("ko\n");
			/* code */
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
			/* code */
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

int bondir(int point_d_energie, int tab[i][j], int orientation)
{
	if (orientation == 0)
	{
		if (tab[i - 2][j] == "|")
		{
			printf("Mouvement impossible, vous etes en face des limites du plateau\n");
			/* code */
		}
		else if (tab[i - 2][j] == "x")
		{
			tab[i][j] = tab[i - 2][j];
			point_d_energie = point_d_energie - 2;
			return tab[i][j];
			/* code */
		}
		else if (tab[i - 2][j] == "1" || tab[i - 2][j] == "2" || tab[i - 2][j] == "3" || tab[i - 2][j] == "4")
		{
			printf("Mouvement impossible, vous ne pouvez pas prendre la place d'un adversaire\n");
		}

	}
	if (orientation == 1)
	{
		if (tab[i][j + 2] == "-")
		{
			printf("Mouvement impossible, vous etes en face des limites du plateau\n");
			/* code */
		}
		else if (tab[i][j + 2]  == "x")
		{
			tab[i][j] = tab[i][j + 2] ;
			point_d_energie = point_d_energie - 2;
			return tab[i][j];
			/* code */
		}
		else if (tab[i][j + 2]  == "1" || tab[i][j + 2] == "2" || tab[i][j + 2] == "3" || tab[i][j + 2] == "4")
		{
			printf("Mouvement impossible, vous ne pouvez pas prendre la place d'un adversaire\n");
		}
	}

	if (orientation == 2)
	{
		if (tab[i + 2][j] == "|")
		{
			printf("Mouvement impossible, vous etes en face des limites du plateau\n");
			/* code */
		}
		else if (tab[i + 2][j] == "x")
		{
			tab[i][j] = tab[i + 2][j];
			point_d_energie = point_d_energie - 2;
			return tab[i][j];
			/* code */
		}
		else if (tab[i + 2][j] == "1" || tab[i + 2][j] == "2" || tab[i + 2][j] == "3" || tab[i + 2][j] == "4")
		{
			printf("Mouvement impossible, vous ne pouvez pas prendre la place d'un adversaire\n");
		}		
	}

	if (orientation == 3)
	{
		if (tab[i][j+ 2] == "-")
		{
			printf("Mouvement impossible, vous etes en face des limites du plateau\n");
			/* code */
		}
		else if (tab[i][j+ 2] == "x")
		{
			tab[i][j] = tab[i][j+ 2];
			point_d_energie = point_d_energie - 2;
			return tab[i][j];
			/* code */
		}
		else if (tab[i][j+ 2] == "1" || tab[i][j+ 2] == "2" || tab[i][j+ 2] == "3" || tab[i][j+ 2] == "4")
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

char looking(int joueur.orientation, int joueur.pos_x, int joueur.pos_y)
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
/*int mouvement_horizontal(int point_de_mouvement)
{
	int tmp_data = 0;
	for (int i = 0; i < point_de_mouvement; ++i)
	{
		tmp_data = i;
		i++
	}
	return tmp_data ;
}

int mouvement_vertical(int point_de_mouvement)
{
	int tmp_data = 0;
	for (int i = 0; i < point_de_mouvement; ++i)
	{
		tmp_data = i;
		i++
	}
	return tmp_data ;
}*/
bool test_quantiter_point_action(int point_d_action, int commande)
{
	if (point_d_action >= commande)
	{
		return true;
	}
	return false;
}

char commande(int point_d_energie, float point_d_action,  char action, int tab[i][j], int orientation, char action_joueur)
{
	if(action == "forward")
		deplacer_haut(tab[i][j], point_d_action, orientation);

	else if(action == "backward")
		deplacer_bas(tab[i][j], point_d_action, orientation);

	else if(action == "leftfwd")
		deplacer_gauche(tab[i][j], point_d_action, orientation);

	else if(action == "rightfwd")
		deplacer_droite(tab[i][j], point_d_action, orientation);

	else if(action == "right")
	{
		point_d_action = point_d_action - 0.5;
		pivoter_right(orientation);
	}

	else if(action == "left")
	{
		point_d_action = point_d_action - 0.5;
		pivoter_left(orientation);
	}

	else if(action == "looking")
		return 1;

	else if(action == "gather")
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

void vague_energie(float point_d_action, int point_d_energie, int orientation, int tab[i][j])
{
	
	if (orientation == 1) //Nord
	{								//Case gauche										Case droite													Case en face										Case haut
		if ((tab[i - 1][j - 1] =< "4" || tab[i - 1][j - 1] == "x") && (tab[i + 1][j - 1] =< "4" || tab[i + 1][j - 1] == "x") && (tab[i][j - 1] =< "4" || tab[i][j - 1] == "x") && (tab[i][j - 2] =< "4" || tab[i][j - 2] == "x"))
		{
			
		}
		point_d_action = point_d_action - 0.5;
		point_d_energie--;
	}

	if (orientation == 2 ) //Est
	{								//Case gauche										Case droite													Case en face										Case haut
		if ((tab[i + 1][j - 1] =< "4" || tab[i + 1][j - 1] == "x") && (tab[i + 1][j + 1] =< "4" || tab[i + 1][j + 1] == "x") && (tab[i + 1][j] =< "4" || tab[i + 1][j] == "x") && (tab[i + 2][j] =< "4" || tab[i + 2][j] == "x"))
		{
			//point_d_energie = point_d_energie - 2;
		}
		point_d_action = point_d_action - 0.5;
		point_d_energie--;
	}

	if (orientation == 3 ) //Sud
	{
		if ((tab[i + 1][j + 1] =< "4" || tab[i + 1][j + 1] == "x") && (tab[i - 1][j + 1] =< "4" || tab[i - 1][j + 1] == "x") && (tab[i][j + 1] =< "4" || tab[i][j + 1] == "x") && (tab[i][j + 2] =< "4" || tab[i][j + 2] == "x"))
		{
			//point_d_energie = point_d_energie - 2;
		}
		point_d_action = point_d_action - 0.5;
		point_d_energie--;
	}

	if (orientation == 0 ) //Ouest
	{
		if ((tab[i - 1][j + 1] =< "4" || tab[i - 1][j + 1] == "x") && (tab[i - 1][j - 1] =< "4" || tab[i - 1][j - 1] == "x") && (tab[i - 1][j] =< "4" || tab[i - 1][j] == "x") && (tab[i - 2][j] =< "4" || tab[i - 2][j] == "x"))
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