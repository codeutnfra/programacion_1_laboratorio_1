#define CANTIDAD_CARTAS 49

typedef struct Cartas{
   char palo[50];
   int numero;
   float valor;
} Carta;

void crearMazo(Carta arrayDeCartas[]);
void mezclarMazo(Carta arrayDeCartas[]);



