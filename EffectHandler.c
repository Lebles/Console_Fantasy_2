/* Gestor de efectos en el campo */

int effectos_A[30][3];
int effectos_A_size = 0;

int effectos_B[20][8];
int effectos_B_size = 0;

// int effectos_C[20][20]; // por ahora no habra de estas pronto

//int is_effect_exist(int id, char category) {
//	int i;
//	
//	if (category == 'A') {	
//		for(i = 0; i < effectos_A_size; i++) {
//			if (effectos_A[i][0] == id) {
//				return i;
//			}
//		}
//	}
//	
//	if (category == 'B') {
//		for(i = 0; i < effectos_B_size; i++) {
//			if (effectos_B[i][0] == id) {
//				return i;
//			}
//		}
//	}
//	
//	return -1;
//}

#include "Habilitys/ElectroShok.c"
#include "Habilitys/Esquivar.c"

void search_effect(int * ele) {
	switch(ele[0]) {
		case 0: break; // el efecto murio
		case 1: effect_electrocutar(ele); break; // electrocutar
		case 2: fin_esquivar(ele); break;
		default: printf(" [Error][EffectHandler]: Algun efecto no existe.\n"); break;
	}
}

void finish_effects() { // realmente esto es para las mamadas que alteran cosas
	int i;
	for(i = 0; i < effectos_A_size; i++) {
		switch(effectos_A[i][0]) {
			case 2: fin_esquivar(effectos_A[i]); break;
			default: break; // El efecto no necesita ser cerrado con cuidado o no existe
		}
	}
	effectos_A_size = 0;
	
	// tengo que hacer el mismo for para B
}

/* Inicio de la clase */

int add_effect(int effect[10], int size) {
	int i;
	
	if (size <= 3) {
		for(i = 0; i < 3; i++) {
			effectos_A[effectos_A_size][i] = effect[i];
		}
		effectos_A_size++;
		return effectos_A_size - 1;
	} else if (size <= 8) {
		for(i = 0; i < 3; i++) {
			effectos_B[effectos_B_size][i] = effect[i];
		}
		effectos_B_size++;
		return effectos_B_size - 1;
	} else {
		printf(" [Error][EffectHandler]: demaciados efectos.\n");
		
		return -1;
	}
}

void execute_effects() {
	int i;
	for(i = 0; i < effectos_A_size; i++) {
		if (effectos_A[i][0] == 0) {
			kill_effect(i, 'A'); // printf(" Matando efecto.");
			i--; continue;
		}
		
		search_effect(effectos_A[i]);
	}
	
	for(i = 0; i < effectos_B_size; i++) {
		if (effectos_B[i][0] == 0) {
			continue;
		}
		
		search_effect(effectos_B[i]);
	}
}

void kill_effect(int efe, char category) {
	int i; int j;
	
	if (category == 'A') {
		for(i = efe + 1; i < effectos_A_size; i++) {
			for(j = 0; j < 3; j++) {
				effectos_A[i - 1][j] = effectos_A[i][j];
			}
		}
		
		effectos_A_size--;
	} else if (category == 'B') {
		for(i = efe + 1; i < effectos_B_size; i++) {
			for(j = 0; j < 8; j++) {
				effectos_B[i - 1][j] = effectos_B[i][j];
			}
		}
		
		effectos_B_size--;
	}
}













