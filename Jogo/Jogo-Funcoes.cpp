#include <iostream>
#include <fstream>
#include <random>
#include "Jogo-Prototipos.h"

using namespace std;

int verificador(const char * file, carta Cards[]) {
	int QuantCards = 0;
	int i = 0;

	carta newCards;
	ifstream fin;
	fin.open(file, ios_base::in | ios_base::binary);

	while (fin.read((char*) &newCards, sizeof(carta))) { // ler
		if (QuantCards > 32) { // caso tenha mais de 32 cartas fechara o arquivo
			fin.close();
			break;
		}
		Cards[i] = newCards;
		QuantCards++;  // cards na posicao do indice receberá newCards a cada laco de repeticao
		i++;
	}
	fin.close();  // retornará  quantidade de cartas
	return QuantCards;
}

void tracos(int quant) { //  funcao para linhas
	for (int i = 0; i < quant; i++) {
		cout << "-";
	}
	cout << endl;
}

unsigned short menu() { // menu retorna a opcao
	cout << "1. Ataque\n"
		<< "2. Defesa\n"
		<< "3. Magia\n"
		<< "4. Estrelas\n";
	cout << "Escolha um atributo [ ]\b\b";
	unsigned short opcao; cin >> opcao;
	return opcao;
}

int aleatorio(int sizeX) { // gera um numero aleatorio
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<> dist(0, sizeX);

	return dist(mt);
}