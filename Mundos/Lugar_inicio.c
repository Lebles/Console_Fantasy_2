/* Lugar 1 */

void Bosque_lugar_1() {
	if (mundo[0] == 1) {
		system("cls");
				
		Sleep(2000);
		printf(" Una serpiente!\n"); Sleep(1100);
		printf(" Saltas hacia un lado instintivamente, y convenientemente, te encuentras una espada.\n"); Sleep(5000);
		
		// inicializacion lugar
		setSitu("No sabes en lo mas minimo que esta pasando, pero no puedes dejar que la confuncion te distraiga de la serpiente que te esta amenazando. Que combeniente que te encontraras una espada...");
		set_enemys((Creatura[]) {init_Serpiente()}, 1);
		add_item((Dato) {0, 6});
		
		printf(" Tienes que luchar!");
		
		combat_scene(); Sleep(2000); // Si sale del bucle, es porque gano el combate
		
		// Parte 2 de la historia
		printf(" Que susto! - dices"); Sleep(1400);
		printf(", cuando te das cuenta de que el cadaver muerto de la serpiente desaparece, cual si fuese nibla"); Sleep(7000); sec_tres_puntos(1);
		printf(" Espera!,"); Sleep(500);
		printf(" hay un nombre grabado en la espada!"); Sleep(2200);
		printf(" El nombre te suena familiar... cual es este nombre?"); Sleep(1400);
		
		printf(" [Escribe una respuesta de una sola palabra]: "); scanf("%s", player_nombre);
		
		printf(" Si..."); Sleep(1500);
		printf(" Conoces ese nombre..."); Sleep(1500);
		printf(" Es tu nombre!, tu eres %s!\n", player_nombre); Sleep(3000);
		
		printf("\n\n Espera, eso tambien es raro."); Sleep(2500);
		printf(" Porque tienes una espada? Quien eres tu?"); Sleep(3000); sec_tres_puntos(1);
		printf(" Parece que la unica forma de averiguarlo es adentrandoce en..."); Sleep(4000);
		FnSetColor(5, 15); printf(" %s \n", TITULO); FnSetColor(0, 15); Sleep(3500);
		
		// final
		player_vida += 3;
		player_FUE += 2;
		add_habilidad(2002);
		printf("\n Te has hecho mas fuerte y habilidoso con esta experiencia! Revisa tus stats."); Sleep(3200);
		
		mundo[0] = 2;
		mundo[1] = 1;
		mundo[2] = 1;
	} else if (mundo[0] == 2) {
		setSitu(" Aqui peleaste con tu primer enemigo, una serpiente.");
		
		calm_scene();
	}
}
