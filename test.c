#include <time.h> 
#include <stdio.h>
#include <stdlib.h>

void sleep_clock(clock_t duree) 
{ 
	clock_t time_out = clock(); 
	while((time_out + duree) > clock()); 
} 

struct joueur
{
	int point_d_energie = 50;
	float point_d_action = 1;
	int pos_x;
	int pos_y;
	char* name;
	char com;
	int orientation;
};

struct Plateau {
	int tab[10][10];
	int etat_partie;
};

struct gameInfo
{
	int pos_energie_x;
	int pos_energie_y;
	int valeur_energie;
};

struct NotificationType
{
	cycle_info = 0;
	game_started = 1;
	game_finished = 2;
	client_dead = 3;
	client_win = 4;
};


int deplacer(int tab[i][j], int point_d_action, char commande, int orientation)
{
	if (orientation == 1)
	{
		if (commande == "d" || commande == "D")
		{
			if (tab[i + 1][j] == "|")
			{
				printf("Mouvement impossible, vous etes en face des limites du plateau\n");
			/* code */
			}
			else if (tab[i + 1][j] == "x")
			{
				tab[i][j] = tab[i + 1][j];
				return tab[i][j];
			/* code */
			}
			else if (tab[i + 1][j] == "1" || tab[i + 1][j] == "2" || tab[i + 1][j] == "3" || tab[i + 1][j] == "4")
			{
				printf("Mouvement impossible, vous ne pouvez pas prendre la place d'un adversaire\n");
			}

		}
		if (commande == "g" || commande == "G")
		{
			if (tab[i - 1][j] == "|")
			{
				printf("Mouvement impossible, vous etes en face des limites du plateau\n");
			/* code */
			}
			else if (tab[i - 1][j] == "x")
			{
				tab[i][j] = tab[i - 1][j];
				return tab[i][j];
			/* code */
			}
			else if (tab[i - 1][j] == "1" || tab[i - 1][j] == "2" || tab[i - 1][j] == "3" || tab[i - 1][j] == "4")
			{
				printf("Mouvement impossible, vous ne pouvez pas prendre la place d'un adversaire\n");
			}
		}

		if (commande == "b" || commande == "B")
		{
			if (tab[i][j + 1] == "-")
			{
				printf("Mouvement impossible, vous etes en face des limites du plateau\n");
			/* code */
			}
			else if (tab[i][j + 1] == "x")
			{
				tab[i][j] = tab[i][j + 1];
				return tab[i][j];
			/* code */
			}
			else if (tab[i][j + 1] == "1" || tab[i][j + 1] == "2" || tab[i][j + 1] == "3" || tab[i][j + 1] == "4")
			{
				printf("Mouvement impossible, vous ne pouvez pas prendre la place d'un adversaire\n");
			}		
		}

		if (commande == "h" || commande == "H")
		{
			if (tab[i][j - 1] == "-")
			{
				printf("Mouvement impossible, vous etes en face des limites du plateau\n");
			/* code */
			}
			else if (tab[i][j - 1] == "x")
			{
				tab[i][j] = tab[i][j - 1];
				return tab[i][j];
			/* code */
			}
			else if (tab[i][j - 1] == "1" || tab[i][j - 1] == "2" || tab[i][j - 1] == "3" || tab[i][j - 1] == "4")
			{
				printf("Mouvement impossible, vous ne pouvez pas prendre la place d'un adversaire\n");
			}		
		}
	}

	if (orientation == 2)
	{
		if (commande == "d" || commande == "D")
		{
			if (tab[i][j+1] == "|")
			{
				printf("Mouvement impossible, vous etes en face des limites du plateau\n");
			/* code */
			}
			else if (tab[i][j+1] == "x")
			{
				tab[i][j] = tab[i][j+1];
				return tab[i][j];
			/* code */
			}
			else if (tab[i][j+1] == "1" || tab[i][j+1] == "2" || tab[i][j+1] == "3" || tab[i][j+1] == "4")
			{
				printf("Mouvement impossible, vous ne pouvez pas prendre la place d'un adversaire\n");
			}
			
		}
		if (commande == "g" || commande == "G")
		{
			if (tab[i][j - 1] == "|")
			{
				printf("Mouvement impossible, vous etes en face des limites du plateau\n");
			/* code */
			}
			else if (tab[i][j - 1] == "x")
			{
				tab[i][j] = tab[i][j - 1];
				return tab[i][j];
			/* code */
			}
			else if (tab[i][j - 1] == "1" || tab[i][j - 1] == "2" || tab[i][j - 1] == "3" || tab[i][j - 1] == "4")
			{
				printf("Mouvement impossible, vous ne pouvez pas prendre la place d'un adversaire\n");
			}
		}

		if (commande == "b" || commande == "B")
		{
			if (tab[i - 1][j] == "-")
			{
				printf("Mouvement impossible, vous etes en face des limites du plateau\n");
			/* code */
			}
			else if (tab[i - 1][j] == "x")
			{
				tab[i][j] = tab[i - 1][j];
				return tab[i][j];
			/* code */
			}
			else if (tab[i - 1][j] == "1" || tab[i - 1][j] == "2" || tab[i - 1][j] == "3" || tab[i - 1][j] == "4")
			{
				printf("Mouvement impossible, vous ne pouvez pas prendre la place d'un adversaire\n");
			}		
		}

		if (commande == "h" || commande == "H")
		{
			if (tab[i + 1][j] == "-")
			{
				printf("Mouvement impossible, vous etes en face des limites du plateau\n");
			/* code */
			}
			else if (tab[i + 1][j]== "x")
			{
				tab[i][j] = tab[i + 1][j];
				return tab[i][j];
			/* code */
			}
			else if (tab[i + 1][j] == "1" || tab[i + 1][j] == "2" || tab[i + 1][j] == "3" || tab[i + 1][j] == "4")
			{
				printf("Mouvement impossible, vous ne pouvez pas prendre la place d'un adversaire\n");
			}		
		}
	}
	if (orientation == 3)
	{
		if (commande == "d" || commande == "D")
		{
			if (tab[i - 1][j] == "|")
			{
				printf("Mouvement impossible, vous etes en face des limites du plateau\n");
			/* code */
			}
			else if (tab[i - 1][j] == "x")
			{
				tab[i][j] = tab[i - 1][j];
				return tab[i][j];
			/* code */
			}
			else if (tab[i - 1][j] == "1" || tab[i - 1][j] == "2" || tab[i - 1][j] == "3" || tab[i - 1][j] == "4")
			{
				printf("Mouvement impossible, vous ne pouvez pas prendre la place d'un adversaire\n");
			}
			
		}
		if (commande == "g" || commande == "G")
		{
			if (tab[i + 1][j] == "|")
			{
				printf("Mouvement impossible, vous etes en face des limites du plateau\n");
			/* code */
			}
			else if (tab[i + 1][j] == "x")
			{
				tab[i][j] = tab[i + 1][j];
				return tab[i][j];
			/* code */
			}
			else if (tab[i + 1][j] == "1" || tab[i + 1][j] == "2" || tab[i + 1][j] == "3" || tab[i + 1][j] == "4")
			{
				printf("Mouvement impossible, vous ne pouvez pas prendre la place d'un adversaire\n");
			}
		}

		if (commande == "b" || commande == "B")
		{
			if (tab[i][j - 1] == "-")
			{
				printf("Mouvement impossible, vous etes en face des limites du plateau\n");
			/* code */
			}
			else if (tab[i][j - 1] == "x")
			{
				tab[i][j] = tab[i][j - 1];
				return tab[i][j];
			/* code */
			}
			else if (tab[i][j - 1] == "1" || tab[i][j - 1] == "2" || tab[i][j - 1] == "3" || tab[i][j - 1] == "4")
			{
				printf("Mouvement impossible, vous ne pouvez pas prendre la place d'un adversaire\n");
			}		
		}

		if (commande == "h" || commande == "H")
		{
			if (tab[i][j + 1] == "-")
			{
				printf("Mouvement impossible, vous etes en face des limites du plateau\n");
			/* code */
			}
			else if (tab[i][j + 1] == "x")
			{
				tab[i][j] = tab[i][j + 1];
				return tab[i][j];
			/* code */
			}
			else if (tab[i][j + 1] == "1" || tab[i][j + 1] == "2" || tab[i][j + 1] == "3" || tab[i][j + 1] == "4")
			{
				printf("Mouvement impossible, vous ne pouvez pas prendre la place d'un adversaire\n");
			}		
		}
	}
	if (orientation == 3)
	{
		if (commande == "d" || commande == "D")
		{
			if (tab[i + 1][j] == "|")
			{
				printf("Mouvement impossible, vous etes en face des limites du plateau\n");
			/* code */
			}
			else if (tab[i + 1][j] == "x")
			{
				tab[i][j] = tab[i + 1][j];
				return tab[i][j];
			/* code */
			}
			else if (tab[i + 1][j] == "1" || tab[i + 1][j] == "2" || tab[i + 1][j] == "3" || tab[i + 1][j] == "4")
			{
				printf("Mouvement impossible, vous ne pouvez pas prendre la place d'un adversaire\n");
			}
			
		}
		if (commande == "g" || commande == "G")
		{
			if (tab[i - 1][j] == "|")
			{
				printf("Mouvement impossible, vous etes en face des limites du plateau\n");
			/* code */
			}
			else if (tab[i - 1][j] == "x")
			{
				tab[i][j] = tab[i - 1][j];
				return tab[i][j];
			/* code */
			}
			else if (tab[i - 1][j] == "1" || tab[i - 1][j] == "2" || tab[i - 1][j] == "3" || tab[i - 1][j] == "4")
			{
				printf("Mouvement impossible, vous ne pouvez pas prendre la place d'un adversaire\n");
			}
		}

		if (commande == "b" || commande == "B")
		{
			if (tab[i][j + 1] == "-")
			{
				printf("Mouvement impossible, vous etes en face des limites du plateau\n");
			/* code */
			}
			else if (tab[i][j + 1] == "x")
			{
				tab[i][j] = tab[i][j + 1];
				return tab[i][j];
			/* code */
			}
			else if (tab[i][j + 1] == "1" || tab[i][j + 1] == "2" || tab[i][j + 1] == "3" || tab[i][j + 1] == "4")
			{
				printf("Mouvement impossible, vous ne pouvez pas prendre la place d'un adversaire\n");
			}		
		}

		if (commande == "h" || commande == "H")
		{
			if (tab[i][j - 1] == "-")
			{
				printf("Mouvement impossible, vous etes en face des limites du plateau\n");
			/* code */
			}
			else if (tab[i][j - 1] == "x")
			{
				tab[i][j] = tab[i][j + 1];
				return tab[i][j];
			/* code */
			}
			else if (tab[i][j - 1] == "1" || tab[i][j - 1] == "2" || tab[i][j - 1] == "3" || tab[i][j - 1] == "4")
			{
				printf("Mouvement impossible, vous ne pouvez pas prendre la place d'un adversaire\n");
			}		
		}
	}
	if (orientation == 0)
	{
		if (commande == "d" || commande == "D")
		{
			if (tab[i][j - 1] == "|")
			{
				printf("Mouvement impossible, vous etes en face des limites du plateau\n");
			/* code */
			}
			else if (tab[i][j - 1] == "x")
			{
				tab[i][j] = tab[i][j - 1];
				return tab[i][j];
			/* code */
			}
			else if (tab[i][j - 1] == "1" || tab[i][j - 1] == "2" || tab[i][j - 1] == "3" || tab[i][j - 1] == "4")
			{
				printf("Mouvement impossible, vous ne pouvez pas prendre la place d'un adversaire\n");
			}
			
		}
		if (commande == "g" || commande == "G")
		{
			if (tab[i][j + 1] == "|")
			{
				printf("Mouvement impossible, vous etes en face des limites du plateau\n");
			/* code */
			}
			else if (tab[i][j + 1] == "x")
			{
				tab[i][j] = tab[i][j + 1];
				return tab[i][j];
			/* code */
			}
			else if (tab[i][j + 1] == "1" || tab[i][j + 1] == "2" || tab[i][j + 1] == "3" || tab[i][j + 1] == "4")
			{
				printf("Mouvement impossible, vous ne pouvez pas prendre la place d'un adversaire\n");
			}
		}

		if (commande == "b" || commande == "B")
		{
			if (tab[i + 1][j] == "-")
			{
				printf("Mouvement impossible, vous etes en face des limites du plateau\n");
			/* code */
			}
			else if (tab[i + 1][j] == "x")
			{
				tab[i][j] = tab[i + 1][j];
				return tab[i][j];
			/* code */
			}
			else if (tab[i + 1][j] == "1" || tab[i + 1][j] == "2" || tab[i + 1][j] == "3" || tab[i + 1][j] == "4")
			{
				printf("Mouvement impossible, vous ne pouvez pas prendre la place d'un adversaire\n");
			}		
		}

		if (commande == "h" || commande == "H")
		{
			if (tab[i - 1][j] == "-")
			{
				printf("Mouvement impossible, vous etes en face des limites du plateau\n");
			/* code */
			}
			else if (tab[i - 1][j] == "x")
			{
				tab[i][j] = tab[i - 1][j];
				return tab[i][j];
			/* code */
			}
			else if (tab[i - 1][j] == "1" || tab[i - 1][j] == "2" || tab[i - 1][j] == "3" || tab[i - 1][j] == "4")
			{
				printf("Mouvement impossible, vous ne pouvez pas prendre la place d'un adversaire\n");
			}		
		}
	}
	return tab[i][j];
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

int pivoter_right(int orientation)
{
	orientation = 2;
	return orientation;
}

int pivoter_left(int orientation)
{
	orientation = 0;
	return orientation;
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

char commande(int point_d_energie, float point_d_action,  char action, int tab[i][j])
{
	if(action == "forward")
		point_d_action = point_d_action - 0.5;

	else if(action == "Backward")
		point_d_action = point_d_action - 1;

	else if(action == "leftfwd")
		point_d_action = point_d_action - 1;

	else if(action == "rightfwd")
		point_d_action = point_d_action - 1;

	else if(action == "right")
		point_d_action = point_d_action - 0.5;

	else if(action == "left")
		point_d_action = point_d_action - 0.5;

	else if(action == "looking")
		return 1;

	else if(action == "gather")
		point_d_action = point_d_action - 1;

	else if(action == "watch")
		???

	else if(action == "attack")
	{

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
		point_d_energie = point_d_energie - 2;


}

void vague_energie(float point_d_action, int point_d_energie, char commande, int orientation, bool test_point_action)
{
	
	if (orientation == 1 && test_point_action == true) //Nord
	{								//Case gauche										Case droite													Case en face										Case haut
		if ((tab[i - 1][j - 1] =< "4" || tab[i - 1][j - 1] == "x") && (tab[i + 1][j - 1] =< "4" || tab[i + 1][j - 1] == "x") && (tab[i][j - 1] =< "4" || tab[i][j - 1] == "x") && (tab[i][j - 2] =< "4" || tab[i][j - 2] == "x"))
		{
			//point_d_energie = point_d_energie - 2;
		}
		point_d_action = point_d_action - 0.5;
		point_d_energie--;
	}

	if (orientation == 2 && test_point_action == true) //Est
	{								//Case gauche										Case droite													Case en face										Case haut
		if ((tab[i + 1][j - 1] =< "4" || tab[i + 1][j - 1] == "x") && (tab[i + 1][j + 1] =< "4" || tab[i + 1][j + 1] == "x") && (tab[i + 1][j] =< "4" || tab[i + 1][j] == "x") && (tab[i + 2][j] =< "4" || tab[i + 2][j] == "x"))
		{
			//point_d_energie = point_d_energie - 2;
		}
		point_d_action = point_d_action - 0.5;
		point_d_energie--;
	}

	if (orientation == 3 && test_point_action == true) //Sud
	{
		if ((tab[i + 1][j + 1] =< "4" || tab[i + 1][j + 1] == "x") && (tab[i - 1][j + 1] =< "4" || tab[i - 1][j + 1] == "x") && (tab[i][j + 1] =< "4" || tab[i][j + 1] == "x") && (tab[i][j + 2] =< "4" || tab[i][j + 2] == "x"))
		{
			//point_d_energie = point_d_energie - 2;
		}
		point_d_action = point_d_action - 0.5;
		point_d_energie--;
	}

	if (orientation == 0 && test_point_action == true) //Ouest
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

void main(int argc, char const *argv[])
{
	FILE* fichier_map =  fopen("map.txt", "r+");
	int tab[15][15] = decla_tab(fichier_map);

	struct joueur J_1, J_2, J_3, J_4;
	int point_de_mouvement = 4 ;

	J_1.point_d_energie = 50;
	J_2.point_d_energie = 50;
	J_3.point_d_energie = 50;
	J_4.point_d_energie = 50;

	J_1.point_d_action = 1;
	J_2.point_d_action = 1;
	J_3.point_d_action = 1;
	J_4.point_d_action = 1;

	J_1.tab[1][1];
	J_2.tab[10][1];
	J_3.tab[10][10];
	J_4.tab[1][10];
	while(J_1.point_d_energie != 0 && J_2.point_d_energie != 0 && J_3.point_d_energie != 0 && J_4.point_d_energie != 0 )
	{
		sleep_clock(9000);

		//point_d_energie = point_d_energie - 2;
	}
	return 0;

}