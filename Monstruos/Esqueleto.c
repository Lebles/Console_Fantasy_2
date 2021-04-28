/* Esqueleto */

// Aqui deberia poner los stats del mosntruo

Creatura init_Esqueleto() {
	return (Creatura) {1001, rodar((int[3]) {8, 8}) + 2, 13, -1, 0};
}

void Esqueleto_info() {
	printf(" Mostruo, con + 4 al atacar, y 1d6 + 2 de danno por ataque.\n");
}

// Acciones (mejorare despues)
int Esqueleto_act(Creatura it) {
	if (it.vida <= 0) {
		printf(" El esqueleto se deshace.\n"); Sleep(2000);
		return 1;
	}
	
	monster_atak("El esqueleto", 6, 4, 2);
	
	return 0;
}
