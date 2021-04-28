/*
	Programa	: RPG
	Autores		: Ronnie Mirand
	Fecha		: 23 Abril 2021
	Proposito	: Programa que corre una pequeña campaña de rol.
	
	_Cosas por hacer:_
	1. Reparar errores simples
x		1. Hacer que los dados funcionen bien * Nota: parece que tendre que espesificar el tamano del array cada vez que quiera usarlo
x		2. Mostrar energina del usuario
x		3. Cambier secuencia de inicio
x		4. Definir armadura
x	2. Lograr sistema de efectos de campo
x		1. Solucionar seleccion de mosntruos
x		2. Solucionar orden de ejecucion
x		3. Implementar primer efecto
x	2.2. Programar acciones basicas [no espera, eso serian habilidades]
x	 	1. Esquivar
	 	2. Preparado
x	3. Programar sistema de informacion
	3.2. Programar sistema de movimiento de escenario
		1. Dar informacion del lugar
	>4. Programar sistema de cuenta cuentos
	4.2. Programar guardado
	5. Escribir historia
	6. Programar boss final
	7. Programar historia
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TITULO "El Bosque de los Espiritus"

#include "My_Headers.h"
#include "Game_System.c"


#include "PlaceHandler.c"
#include "Habilidades.c"
#include "Jugador.c"

#include "Mundos/Bosque.c"

#include "Informacion.c"

void main() {
	secuencia_inicio();
//	secuencia_dev();
	
	while(1) {
		get_place();
		
		system("cls");
	}
	
	// saliendo del juego
	
	secuencia_salir();
}

void combat_scene() {
	while(1) {
		printf(" Tienes %d/%d de vida, que decides hacer?\n", player_vida, player_vida_t);
		
		printf(" 1 - Usar objeto\n");
		printf(" 2 - Usar habilidad\n");
		printf(" 3 - Ver informacion\n");
		printf(" 4 - Huir\n");
		printf(" 0 - Salir del juego\n");
	
		tecla_p();
		
		switch(tecla) {
			case 1: {
				Inv_ver(0);
				break;
			}
			case 2: {
				Hab_ver(0);
				break;
			}
			case 3: {
				Info_ver();
				break;
			}
			case 4: {
				Mundo_mover(0);
				break;
			}
			case 0: {
				secuencia_salir();
				break;
			}
			default: {
				tecla_error();
				system("cls");
				break;
			}
		}
		
		if (paz) {
			paz = 0;
			continue;
		}
		
		// Accion del ambiene
		
		execute_effects();
		Place_Combate();
		
		if (player_vida <= 0) {
			printf(" Parece que has muerto.\n"); Sleep(2000);
			secuencia_salir();
		}
		
		if (enemy_count == 0) {
			printf(" El combate ha finalizado.\n"); 
//			printf(" Ganas %d de experiencia.\n", XP_loot);
//			while (comprobar_experiencia()) {
//				printf(" Subes a nivel %d!", nivel);
//			}
//			
			finish_effects();
			Sleep(4000);
			system("cls");
			break;
		}
		
		system("cls");
	}
}

void calm_scene() {
	player_vida = player_vida_t;
	recuperar_energia();
	
	int location = current_place;
	
	while(1) {
		printf(" Tienes %d/%d de vida, que decides hacer?\n", player_vida, player_vida_t);
		
		printf(" 1 - Ver informacion\n");
		printf(" 2 - Moverse de lugar\n");
		printf(" 0 - Salir del juego\n");
	
		tecla_p();
		
		switch(tecla) {
			case 1: {
				Info_ver();
				break;
			}
			case 2: {
				Mundo_mover(0);
				break;
			}
			case 0: {
				secuencia_salir();
				break;
			}
			default: {
				tecla_error();
				system("cls");
				break;
			}
		}
		
		if (paz) {
			paz = 0;
			continue;
		}
		
		if (current_place != location) {
			break;
		}
		
		// Accion del ambiene
		
		system("cls");
	}
}

void inicializacion() {
	int t = time(NULL);
//	printf(" Su numero es: %d", t);
	srand(t);
	
	// situacion
	setSitu("Llegas a una habitacion cerrada, y dentro, se encuentran un Esqueleto y una serpiente");
	Creatura set[2] = {init_Serpiente(), init_Esqueleto()};
	set_enemys(set, 2);
	
	// jugador
	add_item((Dato) {0, 6});
	add_item((Dato) {1, 1});
	add_item((Dato) {1, 2});
	add_item((Dato) {2, 1});
	
	add_habilidad(2002);
	add_habilidad(2001);
}

void secuencia_inicio() {
	printf(" Bienvenido a la campana de rol \"%s\"", TITULO); Sleep(3000);
	printf(" El juego esta por iniciar\n\n"); Sleep(2000);
	
	printf(" Recuerde que no es recomendable que precione ninguna tecla mientras se esta reproduciendo texto en la pantalla"); // aqui pondria las instrucciones iniciales para quien no sepa jugar el juego.
	Sleep(8000);
	
	srand(time(NULL));
	
	system("cls");
	
	Mundo_secuencia_intro();
	
	// final
//	inicializacion();
}

void secuencia_dev() {
	srand(time(NULL));
	
	FnSetColor(0, 15);
	int data;
	printf(" Desarrollador, teclee los estados de inicio: "); scanf("%d", &data);
	
	switch(data) {
		case 0: secuencia_inicio(); break;
		case 1: system("cls"); inicializacion(); break;
		case 2: {
			system("cls"); inicializacion();
			
			player_vida = 200;
			player_INT = 30;
			energia = 200;
			
			enemigos[1].vida += 20;
			
			break;
		}
		case 3: {
			add_item((Dato) {0, 6});
			player_vida += 3;
			player_FUE += 2;
			add_habilidad(2002);
			
			mundo[0] = 2;
			mundo[1] = 1;
			mundo[2] = 1;
			
			break;
		}
		default: secuencia_inicio(); break;
	}
}

//int comprobar_experiencia() {
//	switch(nivel) {
//		case 0: {
//			if (player_exp >= 10) {
//				level_up_stats();
//				add_habilidad(2002);
//				return 1;
//			}
//		}
//		case 1: {
//			if (player_exp >= 300) {
//				level_up_stats();
//				add_habilidad(2001);
//				return 1;
//			}
//		}
//		default printf(" Ese nivel no existe.\n"); return 0;
//	}
//}

