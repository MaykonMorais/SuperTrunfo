#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Gerador-Prototipos.h"

using namespace std;

void tracos(int quant) { //  funcao para linhas
	for (int i = 0; i < quant; i++) {
		cout << "-";
	}
	cout << endl;
}

int verificador(const char * file, carta Cards[]) { // verifica a quantidade de cartas e retorna a quant cartas
	int QuantCards = 0;
	int i = 0;

	carta newCards;
	ifstream fin;
	
	fin.open(file, ios_base::in |ios_base::binary);
	while (fin.read((char*) &newCards, sizeof(carta))) {
		if (QuantCards > 32) { // caso tenha mais de 32 cartas fechara o arquivo
			fin.close();
			return QuantCards;
		}
		Cards[i] = newCards; 
		QuantCards++;  // cards na posicao do indice recebera newCards a cada laco de repeticao
		i++;
	}
	fin.close();
	return QuantCards;  // retornará  quantidade de cartas
}

int cadastrar(carta yugioh, carta * cards, int QuantCards) {
	if (QuantCards == 0) { // fará o cadastro conforme a quantidade de cartas
		cards[0] = yugioh;
		QuantCards++;
	}
	else {
		cards[QuantCards] = yugioh;
		QuantCards++;
	}
	return QuantCards;
}

void lista(carta * cartas, int QuantCards) {
	cout << "\nCartas no baralho: " << endl;
	tracos(10);
	
	for (int i = 0; i < QuantCards; i++) { 
		cout << i + 1 << "# " << cartas[i].nome << " " << cartas[i].atk << " " << cartas[i].def << " ";
		cout << cartas[i].magia << " " << cartas[i].estrelas << endl;
	}
}
void alterar(carta * YugiohCards, int NumCard) {
	// altera conforme a opcao desejada no main
	cout << "Alterando carta ";
	cout << YugiohCards[NumCard - 1].nome << endl;
	cin.get();
	cout << "Nome: ";
	cin.getline(YugiohCards[NumCard - 1].nome, 30);
	cout << "Ataque: ";
	cin >> YugiohCards[NumCard - 1].atk;
	cout << "Defesa: ";
	cin >> YugiohCards[NumCard - 1].def;
	cout << "Magia: ";
	cin >> YugiohCards[NumCard - 1].magia;
	cout << "Estrelas: ";
	cin >> YugiohCards[NumCard - 1].estrelas;
}

int excluir(carta * YugiohCards, int opcao, int QuantCards) {	
	int cont = 0;
	carta apagada;
	
	for (int i = (opcao - 1); i < QuantCards; i++) { // laco começara com a opcao desejada e removera ele
		if (cont == 0) { 
			strcpy(apagada.nome, YugiohCards[i].nome); // mostrar a carta que foi deletada
			cont++;
		}
		YugiohCards[i] = YugiohCards[i + 1];  // carta selecionada e sobrescrita com a proxima 
	}
	cout << "Carta " << apagada.nome << " foi excluida do baralho.\n";
	QuantCards--; // diminui a quantidade de cartas
	return QuantCards; // atualiza quantidade de cartas
}

void saveGame(const char * fileBin, carta * YugiohCards, int QuantCards) {
	ofstream fout	;
	ifstream fin;

	carta * NewCards = new carta[QuantCards];
	for (int i = 0; i < QuantCards; i++) { // passa as informacoes para vetor dinamico 
		NewCards[i] = YugiohCards[i];
	}
	fout.open(fileBin, ios_base::out | ios_base::app |ios_base::binary);
	
	for (int i = 0; i < QuantCards; i++) { // escrita no arquivo binario
		fout.write((char*) &NewCards[i], sizeof(carta));
	}
	fout.close();
	delete[] NewCards;
}

int IMPORTAR(const char * fileTxt, carta cards[], int QuantCards) {
	ifstream fin;

	fin.open(fileTxt, ios_base::in); // abertura do arquivo
	carta x;
	 
	int cont = 0;
	int i = QuantCards - 1;

	cout << endl;
	while (!fin.eof(), fin >> x.nome) { // ha o transporte das cartas do arquivo para o vetor de cartas
		fin >> x.atk >> x.def >> x.magia >> x.estrelas;
		// transporte para cada laco
		strcpy(cards[++i].nome, x.nome);
		cards[i].atk = x.atk;
		cards[i].def = x.def;
		cards[i].magia = x.magia;
		cards[i].estrelas = x.estrelas;

		cout << cards[i].nome << " " << cards[i].atk << " " << cards[i].def << " ";
		cout << cards[i].magia << " " << cards[i].estrelas << endl;
		cont++;
	}
	fin.close();
	QuantCards += cont; 
	return QuantCards;
}
