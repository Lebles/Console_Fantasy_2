/* General Stuff*/

#include "MyConsoleTextHandler.c"

typedef struct dato {
	int typo;
	int puntero;
} Dato;

// Seccion teclado
int tecla = 0;

void tecla_p() {
	tecla = (getch() - '0');
}

// Otros
void secuencia_salir() {
	printf(" Gracias por jugar a mi juego.\n");
	printf(" Autor Ronnie Miranda.\n");
	
	exit(0);
}

int random(int dice) {
	return ((rand() % dice) + 1);
}

void tecla_error() {
	printf(" La opcion escojida no es valida, intentelo de nuevo");
	paz = 1; // no he testeado si esto funciona con todo
	Sleep(2000);
}

void text_restart() {
	paz = 1;
	system("cls");
}

int math_powder(int base, int ex) {
	int res = base;
	
	int i;
	for(i = 1; i < ex; i++) {
		res *= base;
	}
	
	return res;
}

int rodar(int dados[20]) {
	int total = 0;
	
	int i = 0;
	while(dados[i] != 0) {
		total += random(dados[i]);
//		printf(" What? - %d = %d\n", dados[i], total);
		i++;
	}
	
//	printf(" What? - Continue?"); getch();
	
	return total;
}

int roll20(int ventaja) {
	int res = random(20);
	
	int i;
	if (ventaja > 0) {
		for(i = 0; i < ventaja; i++) {
			int rand = random(20);
			
			if (rand > res) {
				res = rand;
			}
		}
	} else if (ventaja < 0) {
		for(i = ventaja; i < 0; i++) {
			int rand = random(20);
			
			if (rand < res) {
//				printf(" [Dado 20=%d reemplazado con %d].", res, rand);
				res = rand;
			}
		}
	}
	
	return res;
}

void sec_tres_puntos(int salto) {
	printf("."); Sleep(800);
	printf("."); Sleep(800);
	printf("."); Sleep(1000);
	
	if (salto) {
		printf("\n\n"); Sleep(1000);
	}
}









