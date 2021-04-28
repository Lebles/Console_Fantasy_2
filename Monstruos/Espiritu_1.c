/* Espiritu bagabunndo */

void Espiritu_N1_info() {
	printf(" Una especia de monstruo, con +2 al atacar, y 1d6 de danno por ataque. sin embargo, parece atacar en intervalos.\n");
}

int Espiritu_N1_act(Creatura * it) {
	if (it->vida <= 0) {
		printf(" El espiritu se desvanece.\n"); Sleep(2000);
		return 1;
	}
	
	if (it->p_efectos == -1) {
		monster_atak("El espiritu", 6, 2, 0);
		it->p_efectos = -2;
	} else {
		it->p_efectos = -1;
		printf(" El espiritu divaga este turno.");
		Sleep(2000);
	}
	
	return 0;
}
