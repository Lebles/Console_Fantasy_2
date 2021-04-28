/* Sendero oscuro */

void sendero_oscuro() {
	if(mundo[4] == 1) {
		printf(" Vas por el sendero oscuro."); Sleep(2000);
		printf(" Lo que te encuentras no es nada divertido."); Sleep(2500);
		
		Sleep(1000);
		printf(" Un esqueleto ha aparecido en frente tuyo!"); Sleep(2200);
		
		setSitu("Un muerto viviente esqueletico se encuentra frente a ti!!");
		set_enemys((Creatura[2]) { init_Esqueleto() }, 1);
		
		combat_scene(); Sleep(2000);
		
		system("cls");
		printf(" Eso estuvo serca. Pero una vez has vencido al esqueleto, has descubierto la razon por la que estas aqui"); Sleep(5000); sec_tres_puntos(1);
		
		printf(" Has sido atrapado aqui por una bruja!"); Sleep(2000);
		printf(" Jamas podras salir!!!!!"); Sleep(2000);
		
		secuencia_salir();
		
	} else if(mundo[4] == 2) {
	}
}
