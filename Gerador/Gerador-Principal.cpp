#include <iostream>
#include <fstream>
#include "Gerador-Prototipos.h"

const int TAM = 32;
using namespace std;

int main() {
	int QuantCards = 0;
	carta cartas[TAM]; // Vetor Estático
	
	bool fechar = false;
	QuantCards = verificador("Yugioh.dat", cartas); // o  vetor cartas irá receber os dados do binario

	do {
		cout << "Gerador De Cartas\n";
		tracos(10);
		cout << "(C)adastrar\n"
			"(I)mportar\n"
			"(A)lterar\n"
			"(E)xcluir\n"
			"(L)istar\n"
			"(S)air\n";
		cout << "Escolha uma opcao: [ ]\b\b";
		char opcao; cin >> opcao;
		opcao = toupper(opcao);
		switch (opcao)
		{
		case 'C':
			cout << "Cadastrar Carta\n";
			tracos(10);
			cin.ignore();

			carta yugioh;
			cout << "Nome: ";
			cin.getline(yugioh.nome, 30)	;
			cout << "Ataque: ";
			cin >> yugioh.atk;
			cout << "Defesa: ";
			cin >> yugioh.def;
			cout << "Magia: ";
			cin >> yugioh.magia;
			cout << "Estrelas: ";
			cin >> yugioh.estrelas;
			QuantCards = cadastrar(yugioh, cartas, QuantCards); // atualiza as Quantidade De Cartas
			break;
		case 'A':
		cout << "Atualizar Cartas\n";
		tracos(10);
		
		for (int i = 0; i < QuantCards; i++) {
		cout << i + 1 << ") " << cartas[i].nome << endl;
		}
		cout << "Digite o numero da carta: [ ]\b\b";
		int opcao; cin >> opcao;
		
		//VERIFICAÇÃO
		if ((opcao > QuantCards) || (opcao < 1)) {
			break;
		}
		else {
			alterar(cartas, opcao);
			break;
		}
		
		case 'E':
			cout << "Excluir Carta\n";
			tracos(10);
			for (int i = 0; i < QuantCards; i++) {
				cout << i + 1 << ") " << cartas[i].nome << endl;
			}
			cout << "Digite o numero da carta [ ]\b\b";
			int op; cin >> op;
			if ((op > QuantCards) | (op < 1)) {
				break;
			}
			else {
				QuantCards = excluir(cartas, op, QuantCards);
				break;
			}
		case 'L': 
			lista(cartas, QuantCards);
			break;
		case 'I':
			cout << "Importar Cartas\n";
			tracos(10);

			cout << "Importando: ";
			QuantCards = IMPORTAR("maiscartas.txt", cartas, QuantCards);
			break;
		case 'S':
			fechar = true;
			break;
		default:
			cout << "Opcao Invalida!\n";
			break;
		}
	} while (fechar != true);
	
	saveGame("Yugioh.dat", cartas, QuantCards);
	system("pause");
	return 0;
}