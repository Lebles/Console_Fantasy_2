/* Primer mostruo - serpiente*/

// Aqui deberia poner los stats del mosntruo

Creatura init_Serpiente() {
	return (Creatura) {1000, random(4), 13, -1, 0};
}

void Serpiente_info() {
	printf(" Creatura (usualmente hostil). Tiene +4 al atacar, pero solo puede hacer 1 o 2 de danno\n");
}

// Acciones (mejorare despues)
int Serpiente_act(Creatura it) {
	char * mob = "La serpiente";

	if (it.vida <= 0) {
		printf(" %s murio.\n", mob); Sleep(2000);
		return 1;
	}
	
	int atk = roll20(player_ventaja);
	int damage = 0;
	
	if (atk == 20) {
		damage = 2;
		
		printf(" %s ha hecho un ataque critico (%d).\n", mob, damage);
		
	} else if (atk + 4 > player_DEF()) {
		damage = 1;
		
		printf(" %s serpiente asierta el ataque (%d).\n", mob, damage);
		
	} else {
		printf(" %s falla el ataque.\n", mob);
	}
	
	damage_player(damage);
	
	Sleep(3000);
	return 0;
}
