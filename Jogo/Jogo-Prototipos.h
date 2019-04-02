struct carta { // caracteriristicas da carta
	char nome[30];
	unsigned atk, def, magia, estrelas;
};
struct pack {
	char nome[8];
	unsigned short Quant;
};

int verificador(const char * file, carta Cards[]);
void tracos(int quant);
int aleatorio(int sizeX);
unsigned short menu();