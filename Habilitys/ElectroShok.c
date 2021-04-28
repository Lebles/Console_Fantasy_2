/* Habilidad de electroshok*/

void Electro_shok_info() {
	printf(" Lanza una descarga electrica contra un objetivo, y luego el objetivo puede seguir sufiriendo descargas electricas");
	printf(" de la electricidad remananete si no es lo suficientemente resistente.\n");
}

int act_Electro_shok() {
	// inicializar efecto
	if (energia < 10) {
		return 0;
	}
	
	int mob = select_mob(0);
	if (mob == -1) {
		paz = 1;
		system("cls");
		return -1;
	}
	
	// efecto como tal
	energia -= 10;
	
	int dados[2] = { 6 };
	int v = Player_atacar(dados, Player_mod(player_INT) + prof, Player_mod(player_INT), mob);
	
	if (v > 0) {
		int i;
		for(i = 0; i < effectos_A_size; i++) {
			if (effectos_A[i][0] == 1 && effectos_A[i][1] == mob) {	
				effectos_A[i][2] += 3;
				break;
			}
		}
		
		if (i == effectos_A_size) {
			add_effect((int[]) {1, mob, 3}, 3);
		}
	}
	
	Sleep(2000);
	
	return 1;
}

// efecto de campo
void effect_electrocutar(int * ele){
	if (ele[2] > 0) {
		int * v = Player_run_atk((int[2]) { 6 }, Player_mod(player_INT), 0, ele[1], enemigos[ele[1]].defensa);
		
		if (v[0] == 2) {
			printf(" La electrocucion a sido un critica. %s (%d) resive %d de danno.", creatura_name(enemigos[ele[1]].tipo), ele[1] + 1, v[1]);
		} else if (v[0] == 1) {
			printf(" %s (%d) es electrocutado y resive %d de danno.", creatura_name(enemigos[ele[1]].tipo), ele[1] + 1, v[1]);
		} else {
			printf(" La electrocucion ha fallado.");
		}
		
		ele[2]--;
		
		if (ele[2] > 0) {
			printf(" [Turnos restantes: %d].\n", ele[2]);
		} else {
			printf(" El efecto ha terminado.\n");
			ele[0] = 0;
		}
		
		if (v[0] == 2) {
			Sleep(4300);
		} else if (v[0] == 1) {
			Sleep(3500);
		} else {
			Sleep(3000);
		}
	} else {
		ele[0] = 0; printf("wtf??, esto deberia estar terminado\n"); Sleep(2300);
	}
	
	if (enemigos[ele[1]].vida <= 0) {
		ele[0] = 0;
	}
}













