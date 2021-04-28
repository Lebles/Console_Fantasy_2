/* Item Posion de vida */

void Posion_roja_info(int nivel) {
	printf(" Es una articulo que, al ser consumido, devuelve a su portador parte de su fuerza vital.");
	printf(" Este en particular puede devolverte hasta %d de vida.\n", math_powder(5, nivel));
}

int Posion_roja_consumir(int nivel) {
	nivel = math_powder(5, nivel);
	
	if (player_vida_t <= player_vida) {
		printf(" Ya tienes demaciada vida!"); Sleep(2000);
		paz = 1;
		return 0;
	} else if (player_vida_t <= nivel + player_vida) {
		player_vida = player_vida_t;
		printf(" Se te ha recuperado toda la vida."); Sleep(2000);
	} else {
		player_vida += nivel;
		printf(" Tras beber la posion, ahora tienes %d de vida.", player_vida); Sleep(2000);
	}
	
	printf("\n");
	
	return 1;
}
