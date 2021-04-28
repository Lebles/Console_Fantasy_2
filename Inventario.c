/* Inventario */

#include "Items/Espada.c"
#include "Items/Posion_roja.c"
#include "Items/Posion_azul.c"

// Inventario del jugador
Dato item[50];
int inv_size = 0;

void add_item(Dato new_item) {
	if (inv_size + 1 >= 50) {
		printf(" Tu inventario esta lleno.\n");
		return;
	}
	
	item[inv_size] = new_item;
	inv_size++;
}

void item_namer(int index) {
	switch(item[index].typo) {
		case 0: printf("Espada\n"); break;
		case 1: printf("Posion de vida [lvl %d]\n", item[index].puntero); break;
		case 2: printf("Posion de energia [lvl %d]\n", item[index].puntero); break;
		default: break;
	}
}

int item_action(Dato item) {
		switch(item.typo) {
		case 0: return Espada_atacar(item.puntero);
		case 1: return Posion_roja_consumir(item.puntero);
		case 2: return Posion_azul_consumir(item.puntero);
		default: printf(" [Error][Inventario]: No se selecciono un item.\n"); break;
	}
}

void consumir_item(int);

void Inv_ver(int page) {
	system("cls");
	printf(" Escojiste usar un objeto. Que objeto deceas usar?\n");
	
	int cita = page * 9;
	
	// Desplegando obciones
	int i;
	for(i = 0; i + cita < inv_size; i++) {
		printf(" %d - ", i + 1);
		item_namer(i + cita);
		
		if (i + 1 < inv_size && i + 1 >= 9) {
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
	
	for(i = 0; i + cita < inv_size; i++) {
		if (tecla == i + 1) {
			int con = item_action(item[i + cita]);
			
			if (con) {
				consumir_item(i + cita);
			}
			return;
		}
	}
	
	if (butonA && tecla == 'a' - '0') {
		Inv_ver(page - 1);
	} else if (butonB && tecla == 's' - '0') {
		Inv_ver(page + 1);
	} else if (tecla == 0) {
		paz = 1;
		system("cls");
		return;
	} else {
		tecla_error(); paz = 0;
		Inv_ver(page);
	}
}

void consumir_item(int index) {
	int i;
	for(i = index + 1; i < inv_size; i++) {
		item[i - 1] = item[i];
	}
	
	inv_size--;
}



















