/* Item Espada */

// funcion donde se ataca al monstruo

void Esapda_info(int dureza) {
	printf(" Se trata de un arma, que puedes usar para atacar. Su ataque tiene en cuenta el modificador de");
	printf(" fuerza y la proficiencia; y su danno es 1d%d mas el modificador de fuerza.\n", dureza);
}

int Espada_atacar(int dureza) {
	int mob = select_mob(0);
	if (mob == -1) {
		paz = 1;
		system("cls");
		return 0;
	}
	
	Player_atacar((int[]) { dureza }, Player_mod(player_FUE) + prof, Player_mod(player_FUE), mob);
	
	Sleep(2000);
	
	return 0;
}
