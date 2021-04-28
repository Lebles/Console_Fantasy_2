/* Accion basica - esquivar */

void Esquivar_info() {
	printf(" Por el resto del turno, te concentras en esquivar los ataques de los enemigos. Esto hace que ellos adquieran");
	printf(" un nivel de desventaja en todo ataque realizado en tu contra por el siguiente turno.");
	printf(" Nota: la desventaja solo hace un poco menos probable que se acierten los ataques, no los imposibilita.\n");
}

int basic_esquivar() {
	printf(" Te concentras en esquivar ataques el resto del turno.\n"); Sleep (2300);
	
	player_ventaja--;
	
	add_effect((int[2]) {2, 1}, 2);
	
	return 1;
}

// efecto de campo
void fin_esquivar(int * ele) {
	if (ele[1] == 0) {
		player_ventaja++;
		ele[0] = 0;
	} else {
		ele[1] = 0;
	}
}
