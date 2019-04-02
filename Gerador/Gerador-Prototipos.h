struct carta { // caracteriristicas da carta
	char nome[30];
	unsigned atk, def, magia, estrelas;
};
void tracos(int x);

//funções 
int verificador(const char * file, carta Cards[]);
int cadastrar(carta yugioh, carta * cards, int QuantCards);
void lista(carta * cartas, int QuantCards);
void alterar(carta * YugiohCards, int NumCard);
int excluir(carta * YugiohCards, int opcao, int QuantCards);
int IMPORTAR(const char * fileTxt, carta cards[], int QuantCards);
void saveGame(const char * fileBin, carta * YugiohCards, int QuantCards);