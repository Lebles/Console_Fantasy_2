/* Controlador de habilidades */

#include "EffectHandler.c"

int habil[30];
int hab_count = 0;

void add_habilidad(int hab) {
	if (hab_count + 1 >= 60) {
		printf(" No puedes colocarte mas habilidades.");
		return;
	}
	
	habil[hab_count] = hab;
	
	hab_count++;
}

char * power_name(int id) {
	switch(id) {
		case 2001: return "Electro-Shok (10)";
		case 2002: return "Esquivar";
		default: return NULL;
	}
}

int activate_effect(int pow) {
	switch(pow) {
	case 2001: return act_Electro_shok();
	case 2002: return basic_esquivar();
	default: printf(" [Error][Habilidades]: No se selecciono una habilidad.\n"); return -1;
	}
}

void Hab_ver(int page) {
	system("cls");
	printf(" Escojiste usar una habilidad. Que habilidad deceas usar? [Energia: %d]\n", energia);
	
	int cita = page * 9;
	
	// Desplegando obciones
	int i;
	for(i = 0; i + cita < hab_count; i++) {
		char * var = power_name(habil[i + cita]);
		
		printf(" %d - %s\n", i + 1, var);
		
		if (i + 1 < hab_count && i + 1 >= 9) {
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
	
	for(i = 0; i + cita < hab_count; i++) {
		if (tecla == i + 1) {
			int v = activate_effect(habil[i]);
			
			if (v == 0) {
				printf(" No tienes suficiente energia!"); Sleep(1000);
				Hab_ver(page);
			} else if (v == -1) {
				Hab_ver(page);
			}
			return;
		}
	}
	
	if (butonA && tecla == 'a' - '0') {
		Hab_ver(page - 1);
	} else if (butonB && tecla == 's' - '0') {
		Hab_ver(page + 1);
	} else if (tecla == 0) {
		paz = 1;
		system("cls");
		return;
	} else {
		tecla_error(); paz = 0;
		Hab_ver(page);
	}
}
