/* Sircunstancias */

char situ[500];
int isFight = 0;

void setSitu(char * desc) {
	strcpy(situ, desc);
}

typedef struct creatura {
	int tipo;
	int vida;
	int defensa;
	int p_efectos;
	int ventaja;
} Creatura;

Creatura enemigos[20];
int enemy_count = 0;

#include "MonsterHandler.c"

void Place_Combate() {
	int v = 0;
	
	int i;
	for(i = 0; i < enemy_count; i++) {
		v += act_creatura(&enemigos[i]);
	}
	
	if (v) {
		kill_enemy();
	}
}

void set_enemys(Creatura arr[20], int count) {
	int i;
	for(i = 0; i < count; i++) {
		enemigos[i] = arr[i];
	}
	
	for(i = count; i < enemy_count; i++) {
		enemigos[i] = arr[i];
	}
	
	enemy_count = count;
}

void kill_enemy() {
	int i;
	for(i = 0; i < enemy_count; i++) {
		if (enemigos[i].vida <= 0) {
			int j;
			for(j = i + 1; j < enemy_count; j++) {
				enemigos[j - 1] = enemigos[j];
			}
			enemy_count--;
		}
	}
}
