/* Item - Posion de Mana  energia */

void Posion_azul_info(int nivel) {
	printf(" Es una articulo que, al ser consumido, devuelve a su portador parte de su poder vital.");
	printf(" Este en particular puede devolverte hasta %d de energia.\n", nivel * 10);
}

int Posion_azul_consumir(int nivel) {
	nivel *= 10;
	
	energia += nivel;
	printf(" Has recuperado %d de energia! [Energia actual: %d].\n", nivel, energia); Sleep(2000);
	
	return 1;
}
