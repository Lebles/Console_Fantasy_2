/* Profundidad del bosque */

void bosque_profundo() {
	if(mundo[2] == 1) {
		printf(" Te desides adentrar mas en el bosque.\n"); Sleep(2000);
		
		printf(" Tienes suerte, parece que te has encontrado de articulos utiles: una posion de vida y un peto de malla.\n"); Sleep(3500);
		
		add_item((Dato) {1, 1});
		player_armor += 4;
		
		printf(" Sin embargo las cosas nunca son tan faciles."); Sleep(2000);
		printf(" Te encuentras con un espiritu significativamente fuerte."); Sleep(3000);
		
		// inicializando combate
		setSitu(" Este espiritu tiene mucha vida, pero debe haber una manera de vencerlo!");
		Creatura esp = {1002, 16, 12, -random(2), 0};
		set_enemys((Creatura[]) { esp }, 1);
		
		combat_scene(); Sleep(2000);
		
		system("cls");
		printf(" Puedes estar orgulloso de ti mismo, acabas de vencer a un espiritu poderoso.\n"); Sleep(4000);
		printf(" Sin embargo el bosque es muy profundo y no puedes seguir abansando por ese camino.\n"); Sleep(2000);
		
		mundo[2] = 2;
		
	} else if(mundo[2] == 2) {
	}
}
