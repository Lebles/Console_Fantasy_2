/* Headers? */

// Jugador.c
int player_vida_t;
int player_vida;
int player_armor;

int player_FUE;
int player_DES;
int player_INT; 
int player_ventaja;

int energia;
int prof;

void damage_player(int);
int player_DEF();
int * Player_run_atk(int[20], int, int, int, int);

// Main.c
int paz;

void inicializacion();
void secuencia_inicio();
void combat_scene();

// PlaceHandler.c
void kill_enemy();

// monster
void monster_atak(char*,int,int,int);
