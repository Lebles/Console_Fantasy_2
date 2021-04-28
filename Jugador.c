/* Jugador */

#include "Inventario.c"

// Stats jugador
char player_nombre[50] = "Reynal";

int player_vida_t = 10;
int player_vida = 10;
//int player_vida_temp = 0;
int player_armor = 0;

int player_FUE = 10;
int player_DES = 10;
int player_INT = 10;
int player_ventaja = 0;

int energia = 0;
int prof = 0;

// Funciones jugador
int Player_mod(int total) {
	return ((total - 10) / 2);
}

int player_DEF() {
	return player_armor + Player_mod(player_DES) + 10;
}

void damage_player(int damage) {
	player_vida -= damage;
}

int * Player_run_atk(int dados[20], int atk_mod, int mod, int mob, int CD) {
	int atk = roll20(enemigos[mob].ventaja);
	int damage = 0;
	
	if (atk == 20) {
		damage = rodar(dados) + rodar(dados) + mod;
		atk = 2;
	} else if (atk + atk_mod > CD) {
		damage = rodar(dados) + mod;
		atk = 1;
	} else {
		atk = 0;
	}
	
	enemigos[mob].vida -= damage;
	
	return (int[]) {atk, damage};
}

int Player_atacar(int dados[20], int atk_mod, int mod, int mob) {
	int * res = Player_run_atk(dados, atk_mod, mod, mob, enemigos[mob].defensa);
	
	if (res[0] == 2) {
		printf(" Haz realizado un ataque critico!, %d de danno!\n", res[1]);
	} else if (res[0] == 1) {
		printf(" Haz realizado %d de danno.\n", res[1]);
	} else {
		printf(" El ataque ha fallado.\n");
	}
	
//	Sleep(2000); // no se puede ejecutar sin resetar res
	
	return res[0];
}

// nivel

void recuperar_energia() {
	int nivel = Player_mod(player_FUE) + Player_mod(player_DES) + Player_mod(player_INT);
	
	int ene = 0;
	
	int i;
	
	for(i = 0; i < nivel; i++) {
		ene += (i + 1) * 10;
	}
	
	if (ene > energia) {
		energia = ene;
	}
}

//void level_up_stats() {
//	nivel++;
//	
//	player_vida_t += 4;
//	player_vida += 4;
//	
//	player_FUE += 4;
//	player_DES += 4;
//	player_INT += 4;
//	
//	if (nivel % 3 == 0) {
//		prof++;
//	}
//	
//	printf(" Te has hecho mas fuerte y habilidoso con esta experiencia! Revisa tus stats."); Sleep(3200);
//}







