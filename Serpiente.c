/* Primer mostruo - serpiente*/

// Aqui deberia poner los stats del mosntruo

Creatura init_Serpiente() {
	return {1000, random(4)};
}

// Acciones (mejorare despues)
void Serpiente_act() {
	if (monstruo_vida <= 0) {
		printf(" La serpiente murio.\n");
		secuencia_salir();
	}
	
	if (random(2) == 2) {
		printf(" La serpiente acierta el ataque el ataque.\n");
		player_vida--;
		printf(" Resives 1 de danno.\n");
	} else {
		printf(" La serpiente falla el ataque.\n");
	}
	
	Sleep(3000);
}
