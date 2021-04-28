/* Direccion de los susurros */

void lugar_susurros() {
	if (mundo[3] == 1) {
		printf(" Los susurros que has oido antes se hacen mas fuertes, parece que vas en la direccion correcta."); Sleep(5500);
		printf("\n\n Sin embargo eres interceptado por dos serpientes."); Sleep(3000);
		
		// inicializando combate
		setSitu("Te encuentras con 2 serpientes mientras intentabas seguir los susurros");
		set_enemys((Creatura[2]) { init_Serpiente(), init_Serpiente() }, 2);
		
		combat_scene(); Sleep(2000);
		
		system("cls");
		printf(" Tras vencer a las serpientes llegas a una columna de piedra."); Sleep(3000);
		printf(" Parece que fuiste confundido por tu mente, tal vez los susurros, y la verdad, esten en otra parte."); Sleep(5000);
		printf(" Sin embargo, al menos encuentras articulos de utilidad cerca de esa pared."); Sleep(3000);
		
		add_item((Dato) {1, 1});
		add_item((Dato) {2, 1});
		add_item((Dato) {1, 2});
		
		player_vida_t += 4;
		player_DES += 4;
		
		printf("\n\n [Tus stats acaban de incrementar]"); Sleep(2000);
		
		mundo[3] = 2;
		
	} else if (mundo[3] == 2) {
		setSitu(" Solo hay una columna de piedra en este lugar. Los susurros a lo mejor fueron el eco.");
		
		calm_scene();
	}
}
