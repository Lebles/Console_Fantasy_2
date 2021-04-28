/* Planicie espiritual */

void Bosque_planicie_1() {
	if (mundo[1] == 1) {
		printf(" Ok, llegas hasta un lugar nuevo.\n"); Sleep(2000);
		printf("\n Hay mucha neblina y no puedes ver nada, pero almenos estas entrando en campo habierto."); Sleep(4500);
		
		printf("\n\n No otra vez!"); Sleep(3000);
		
		system("cls");
		printf(" De entre la niebla, ves aparecer a un espiritu ambulante."); Sleep(3100);
		
		// inicializando combate
		setSitu(" Acabas de pasar de la sarten al fuego!, te encuentras a un espiritu bagabundo con cara de pocos amigos.");
		Creatura esp = {1002, 8, 10, -random(2), 0};
		set_enemys((Creatura[]) { esp }, 1);
		
		combat_scene(); Sleep(2000);
		
		// parte final
		system("cls");
		
		printf(" Que bueno que lo venciste."); Sleep(2000);
		printf(" Sin embargo, este espiritu te resulto muy familiar, y comienzas a recordar cosas..."); Sleep(5800);
		
		add_habilidad(2001);
		printf("\n [Has adquirido la habilidad \"%s\" y mas inteligencia]", power_name(2001)); Sleep(2500); sec_tres_puntos(1);
		player_INT += 4;
		
		printf(" Se habren mas caminos delante de ti, pero en uno de ellos oyes una voz femenina que susurra clamores..."); Sleep(6000);
		
		mundo[1] = 2;
		mundo[3] = 1;
		mundo[4] = 1;
	} else if (mundo[1] == 2) {
		setSitu("Aqui te encontraste con un misterioso espiritu debil.");
		
		calm_scene();
	}
}
