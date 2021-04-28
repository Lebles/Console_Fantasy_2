/* Mundo 1 - Bosque de los espiritus */

int current_place = 0;
#define Mundo_size 20
int mundo[Mundo_size]; // estados de los lugares

char * nombre_lugar(int index) {
	switch(index) {
		case 0: return "Lugar de inicio";
		case 1: return "Planicie espiritual";
		case 2: return "Profundidad del bosque"; // 0.2
		case 3: return "Direccion de los susurros"; // 0.1.1
		case 4: return "Sendero oscuro"; // 0.1.2
		default: return "Lugar?Misingno";
	}
}

#include "Lugar_inicio.c"
#include "Lugar_planicie.c"
#include "Lugar_susurros.c"
#include "Lugar_esqueleto.c"
#include "Lugar_cofre.c"

void get_place() {
	switch(current_place) {
		case 0: Bosque_lugar_1(); break;
		case 1: Bosque_planicie_1(); break;
		case 2: bosque_profundo(); break;
		case 3: lugar_susurros(); break;
		case 4: sendero_oscuro(); break;
		default: break;
	}
}

void Mundo_mover(int cita) {
	system("cls");
	printf(" A donde quieres ir?.\n");
	
	// Desplegando obciones
	int i; int numb = 1;
	for(i = 0; i + cita < Mundo_size; i++) {
		if (mundo[i + cita] == 0) { // implica que esta bloqueado
			 continue;
		}
		if (numb > 9) {
			numb = 10;
			break;
		}
		
		char * var = nombre_lugar(i);
		
		if (mundo[i + cita] == 1) {
			FnSetColor(5, 15);
			printf(" %d - %s\n", numb, var);
			FnSetColor(0, 15);
		} else {
			printf(" %d - %s\n", numb, var);
		}
		
		numb++;
	}
	
	int ret = i;
	
	int butonA = 0; int butonB = 0;
	if (numb == 10) {
		printf("\n");
		
		if (cita > 8) {
			printf(" A - Desde el inicio\n");
			butonA = 1;
		}
		if (i == 10) {
			printf(" S - Pagina siguiente\n");
			butonB = 1;
		}
	}
	
	printf(" 0 - Atras\n");
	
	label_Ron:
	// Desplegando reacciones
	tecla_p();
	
	if (tecla == current_place) { goto label_Ron; }
	
	numb = 1;
	for(i = 0; i + cita < Mundo_size; i++) {
		if (mundo[i + cita] == 0) {
			 continue;
		}
		
		if (tecla == numb) {
			current_place = i;
			return;
		}
		
		numb++;
	}
	
	if (butonA && tecla == 'a' - '0') {
		Mundo_mover(0);
	} else if (butonB && tecla == 's' - '0') {
		Mundo_mover(ret);
	} else if (tecla == 0) {
		paz = 1;
		system("cls");
		return;
	} else {
		tecla_error(); paz = 0;
		return Mundo_mover(cita);
	}
}

void Mundo_secuencia_intro() {
	system("cls");
	
	printf(" - Donde estoy? - te preguntas.\n"); Sleep(3000);
	printf(" - Que es este luegar? "); Sleep(1500); sec_tres_puntos(1);
	
	printf("\n Te despiertas en medio de lo que parece ser un bosque, pero todo esta cubierto de una espesa niebla que apenas te permite ver que hay delante tullo. No puedes recordar tu nombre ni porque estas alli, pero tienes un mal precentimiento.\n");
	Sleep(14*1000);
	
	int i; for(i = 0; i < 8; i++) { mundo[i] = 0; }
	
	mundo[0] = 1;
	current_place = 0;
}

// definicion lugar 1






