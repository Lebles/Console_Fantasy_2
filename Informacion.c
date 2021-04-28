/* Informacion */

void search_info(int id, int index) {
	switch(id) {
		case 0: Esapda_info(index); break;
		case 1: Posion_roja_info(index); break;
		case 2: Posion_azul_info(index); break;
		
		case 1000: Serpiente_info(); break;
		case 1001: Esqueleto_info(); break;
		case 1002: Espiritu_N1_info(); break;
		
		case 2001: Electro_shok_info(); break;
		case 2002: Esquivar_info(); break;
		
		default: break;
	}
}

void Info_ver() {
	system("cls");
	printf(" Que informacion deseas ver?\n");
		
	printf(" 1 - Sobre objetos\n");
	printf(" 2 - Sobre habilidades\n");
	printf(" 3 - Sobre enemigos\n");
	printf(" 4 - Hoja de personaje\n");
	printf(" 5 - Sobre el sitio\n");
	printf(" 0 - Atras\n");
	
	tecla_p();
	
	switch(tecla) {
		case 0: paz = 1; system("cls"); return;
		case 1: ver_objetos(0); break;
		case 2: ver_powers(0); break;
		case 3: {
			while(1) {
				int sel = select_mob(0);
				
				if (sel != -1) {
					system("cls");
					printf(" Enemigo #%d: %s\n\n", (sel % 9) + 1, creatura_name(enemigos[sel].tipo));
					search_info(enemigos[sel].tipo, sel);
					
					printf("\n Actualmente tiene %d de vida y tienes %d de ventaja en su contra.\n\n", enemigos[sel].vida, enemigos[sel].ventaja);
					
					printf("\n [Preciona cualquier tecla para volver al menu]\n");
					getch();
				} else {
					break;
				}
			}
			
			break;
		}
		case 4: ver_stats_personaje(); break;
		case 5:{
			system("cls");
			
			printf(" Lugar: %s\n", nombre_lugar(current_place));
			
			printf("\n %s", situ);
			
			printf("\n\n [Preciona cualquier tecla para volver al menu]\n");
			getch();
			
			break;
		}
		default: tecla_error(); paz = 0; Info_ver(); break;
	}
	
	Info_ver();
}

void ver_objetos(int page) {
	system("cls");
	printf(" Sobre que objeto quieres saber?\n");
	
	// ver info
	int cita = page * 9;
	
	int i;
	for(i = 0; i + cita < inv_size; i++) {
		printf(" %d - ", i + 1);
		item_namer(i + cita);
		
		if (i + 1 < inv_size && i + 1 >= 9) {
			i = 10;
			break;
		}
	}
	
	int butonA = 0; int butonB = 0;
	if (i == 10) {
		printf("\n");
		
		if (page > 0) {
			printf(" A - Pagina aterior\n");
			butonA = 1;
		}
		if (i == 10) {
			printf(" S - Pagina siguiente\n");
			butonB = 1;
		}
	}
	
	printf(" 0 - Atras\n");
	
	// Desplegando reacciones
	tecla_p();
	
	for(i = 0; i + cita < inv_size; i++) {
		if (tecla == i + 1) {
			system("cls");
			printf(" Item: "); item_namer(i + cita); printf("\n");
			search_info(item[i + cita].typo, item[i + cita].puntero);
			printf("\n [Preciona cualquier tecla para volver al menu]\n");
			getch();
			ver_objetos(page);
			return;
		}
	}
	
	if (butonA && tecla == 'a' - '0') {
		ver_objetos(page - 1);
	} else if (butonB && tecla == 's' - '0') {
		ver_objetos(page + 1);
	} else if (tecla == 0) {
		return;
	} else {
		tecla_error(); paz = 0;
		Inv_ver(page);
	}
}

void ver_powers(int page) {
	system("cls");
	printf(" Sobre que habilidad quieres saber?\n", energia);
	
	int cita = page * 9;
	
	// Desplegando obciones
	int i;
	for(i = 0; i + cita < hab_count; i++) {
		char * var = power_name(habil[i + cita]);
		
		printf(" %d - %s\n", i + 1, var);
		
		if (i + 1 < hab_count && i + 1 >= 9) {
			i = 10;
			break;
		}
	}
	
	int butonA = 0; int butonB = 0;
	if (i == 10) {
		printf("\n");
		
		if (page > 0) {
			printf(" A - Pagina aterior\n");
			butonA = 1;
		}
		if (i == 10) {
			printf(" S - Pagina siguiente\n");
			butonB = 1;
		}
	}
	
	printf(" 0 - Atras\n");
	
	// Desplegando reacciones
	tecla_p();
	
	for(i = 0; i + cita < hab_count; i++) {
		if (tecla == i + 1) {
			system("cls");
			printf(" Habilidad: %s\n\n", power_name(habil[i + cita]));
			search_info(habil[i + cita], 0);
			printf("\n [Preciona cualquier tecla para volver al menu]\n");
			getch();
			ver_powers(page);
			return;
		}
	}
	
	if (butonA && tecla == 'a' - '0') {
		ver_powers(page - 1);
	} else if (butonB && tecla == 's' - '0') {
		ver_powers(page + 1);
	} else if (tecla == 0) {
		return;
	} else {
		tecla_error(); paz = 0;
		ver_powers(page);
	}
}

void ver_stats_personaje() {
	system("cls");
	
	FnSetColor(5, 15);
	printf(" Nombre: %s \n\n", player_nombre);
	FnSetColor(0, 15);
	
	printf(" Puntos de vida: %d/%d \n", player_vida, player_vida_t);
	printf(" Puntos de armadura: %d \n", player_armor + Player_mod(player_DES));
	printf(" Puntos de energia: %d \n", energia);
	
	printf("\n Puntos de Fuerza: %d (+%d) \n", player_FUE, Player_mod(player_FUE));
	printf(" Puntos de Destreza: %d (+%d)\n", player_DES, Player_mod(player_DES));
	printf(" Puntos de Inteligencia: %d (+%d)\n", player_INT, Player_mod(player_INT));
	
	printf("\n Proficiencia: +%d\n", prof);
	
	printf("\n\n [Preciona cualquier tecla para regrsar]\n");
	getch();
}










