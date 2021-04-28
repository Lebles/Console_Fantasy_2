/* Monster handler */

#include "Monstruos/Serpiente.c"
#include "Monstruos/Esqueleto.c"
#include "Monstruos/Espiritu_1.c"

char * creatura_name(int mob) {
	switch(mob) {
		case 1000: return "Serpiente";
		case 1001: return "Esqueleto";
		case 1002: return "Espiritu debil";
		default: return NULL;
	}
}

int act_creatura(Creatura * mob) {
	switch(mob->tipo) {
		case 1000: return Serpiente_act(*mob);
		case 1001: return Esqueleto_act(*mob);
		case 1002: return Espiritu_N1_act(mob);
		default: {
			printf("[Error] Datos erroneos en PlaceHandler - 1");
			secuencia_salir();
		}
	}
}

int select_mob(int page) {
	system("cls");
	printf(" Selecciona una creatura.\n");
	
	int cita = page * 9;
	
	// Desplegando obciones
	int i;
	for(i = 0; i + cita < enemy_count; i++) {
		char * var = creatura_name(enemigos[i + cita].tipo);
		
		printf(" %d - %s (LF:%d)\n", i + 1, var, enemigos[i + cita].vida);
		
		if (i + 1 < enemy_count && i + 1 >= 9) {
			i = 10;
			break;
		}
	}
	
	int butonA = 0; int butonB = 0;
	if (i == 10) {
		printf("\n");
		
		if (page > 0) {
			printf(" A - Pagina aterior\n");
			butonA = 1;
		}
		if (i == 10) {
			printf(" S - Pagina siguiente\n");
			butonB = 1;
		}
	}
	
	printf(" 0 - Atras\n");
	
	// Desplegando reacciones
	tecla_p();
	
	for(i = 0; i + cita < enemy_count; i++) {
		if (tecla == i + 1) {
			return (i + cita);
		}
	}
	
	if (butonA && tecla == 'a' - '0') {
		return select_mob(page - 1);
	} else if (butonB && tecla == 's' - '0') {
		return select_mob(page + 1);
	} else if (tecla == 0) {
		return -1;
	} else {
		tecla_error(); paz = 0;
		return select_mob(page);
	}
}

void monster_atak(char * name, int dice, int atk_mod, int mod) {
	int atk = roll20(player_ventaja);
	int damage = 0;
	
	if (atk == 20) {
		damage = random(dice) + random(dice) + mod;
		
		printf(" %s ha hecho un ataque critico (%d).\n", name, damage);
		
	} else if (atk + atk_mod > player_DEF()) {
		damage = random(dice) + mod;
		
		printf(" %s asierta el ataque (%d).\n", name, damage);
		
	} else {
		printf(" %s falla el ataque.\n", name);
	}
	
	damage_player(damage);
	
	Sleep(2300);
}








