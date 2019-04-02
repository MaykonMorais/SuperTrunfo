#include <iostream>
#include <Windows.h>
#include <cstdlib> 
#include <iomanip>  
#include "Jogo-Prototipos.h"
#include <random>

const int TAM = 32; // irao existir espacos vazios se fizer isso
using namespace std;
int main() {
	carta * cartas = new carta[TAM];
	int QuantCards = verificador("../Gerador/Yugioh.dat", cartas); // armazena as cartas no vetor dinamico
	
	
	char jogador1[30], jogador2[30]; //jogadores nomes
	carta CardsJogador1[4];
	carta CardsJogador2[4];
	int PtsJogador1 = 0, PtsJogador2 = 0; // pontuacao dos jogadores 

	carta teste1 = {0};
	carta teste2 = {0};

	bool fechar = false;
	do {
		cout << "SUPER TRUNFO YU-GI-OH\n";
		tracos(10);
		cout << "Iniciar Nova Partida[S/N]: "; // colocar no final
		char escolha; cin >> escolha;
		escolha = toupper(escolha);  // a escolha sera maiuscula

		cin.get();
		unsigned short AlternaJogador = 1;
		switch (escolha)
		{

		case 'S':
			cout << "Jogador 1: ";
			cin.getline(jogador1, 30);
			cout << "Jogador 2: ";
			cin.getline(jogador2, 30);
			tracos(10);
						
			// distribuicao das cartas para cada jogador
			for (int i = 0; i <= 3; i++) {
				CardsJogador1[i] = cartas[aleatorio(QuantCards-1)];
				CardsJogador2[i] = cartas[aleatorio(QuantCards-1)];
			}
			
			for (int i = 0; i < 4; i++) { // jogadas
				int PosRandom = aleatorio(3);
				
				if(AlternaJogador == 1){
				cout << "[ " << jogador1 << "]" << endl;
				cout << "Carta: " << CardsJogador1[PosRandom].nome << endl;
				} 
				else if (AlternaJogador == 2) {
					cout << "[ " << jogador2 << "]" << endl;
					cout << "Carta: " << CardsJogador2[PosRandom].nome << endl;
				}
				switch (menu())
				{
				case 1: // Ataque
					cout << "[" << jogador1 << "] "<< CardsJogador1[PosRandom].nome << left << setw(2) <<" | " << CardsJogador1[PosRandom].atk <<endl;
					cout << "[" << jogador2 << "] "<< CardsJogador2[PosRandom].nome << left << setw(2) <<" | " << CardsJogador2[PosRandom].atk << endl << endl;

					if (CardsJogador1[PosRandom].atk > CardsJogador2[PosRandom].atk) {
						PtsJogador1 += 2;
						cout << "Placar : " << jogador1 << " " << PtsJogador1 << " x "
							<< PtsJogador2 << jogador2 << endl;
					}
					else if (CardsJogador1[PosRandom].atk == CardsJogador2[PosRandom].atk) {
						PtsJogador1 += 0;
						PtsJogador2 += 0;
						cout << "Placar : " << jogador1 << " " << PtsJogador1 << " x "
							<< PtsJogador2 << jogador2 << endl;
					}
					
					else {
						PtsJogador2 += 2;
						cout << "Placar : " << jogador1 << " " << PtsJogador1 << " x "
							<< PtsJogador2 << jogador2 << endl;
					}
					tracos(25);
					break;
				case 2: // Defesa
					cout << "[" << jogador1 << "] " << CardsJogador1[PosRandom].nome << " | " << CardsJogador1[PosRandom].def << endl;
					cout << "[" << jogador2 << "] " << CardsJogador2[PosRandom].nome << " | " << CardsJogador2[PosRandom].def << endl << endl;

					if (CardsJogador1[PosRandom].def > CardsJogador2[PosRandom].def) {
						PtsJogador1 += 2;
						cout << "Placar : " << jogador1 << " " << PtsJogador1 << " x "
							<< PtsJogador2 << jogador2 << endl;
					}
					else if (CardsJogador1[PosRandom].def == CardsJogador2[PosRandom].def) {
						PtsJogador1 += 0;
						PtsJogador2 += 0;
						cout << "Placar : " << jogador1 << " " << PtsJogador1 << " x "
							<< PtsJogador2 << jogador2 << endl;
					}
					else {
						PtsJogador2 += 2;
						cout << "Placar : " << jogador1 << " " << PtsJogador1 << " x "
							<< PtsJogador2 << jogador2 << endl;
					}
					tracos(25);
					break;
				case 3: // magia
					cout << "[" << jogador1 << "] " << CardsJogador1[PosRandom].nome << " | " << CardsJogador1[PosRandom].magia << endl;
					cout << "[" << jogador2 << "] " << CardsJogador2[PosRandom].nome << " | " << CardsJogador2[PosRandom].magia << endl << endl;

					if (CardsJogador1[PosRandom].magia > CardsJogador2[PosRandom].magia) {
						PtsJogador1 += 2;
						cout << "Placar : " << jogador1 << " " << PtsJogador1 << " x "
							<< PtsJogador2 << jogador2 << endl;
					}
					else if (CardsJogador1[PosRandom].magia == CardsJogador2[PosRandom].magia) {
						PtsJogador1 += 0;
						PtsJogador2 += 0;
						cout << "Placar : " << jogador1 << " " << PtsJogador1 << " x "
							<< PtsJogador2 << jogador2 << endl;
					}
					else {
						PtsJogador2 += 2;
						cout << "Placar : " << jogador1 << " " << PtsJogador1 << " x "
							<< PtsJogador2 << jogador2 << endl;
					}
					tracos(25);
					break;
				case 4: // estrelas
					cout << "[" << jogador1 << "] " << CardsJogador1[PosRandom].nome << " | " << CardsJogador1[PosRandom].estrelas << endl;
					cout << "[" << jogador2 << "] " << CardsJogador2[PosRandom].nome << " | " << CardsJogador2[PosRandom].estrelas << endl << endl;

					if (CardsJogador1[PosRandom].estrelas > CardsJogador2[PosRandom].estrelas) {
						PtsJogador1 += 2;
						cout << "Placar : " << jogador1 << " " << PtsJogador1 << " x "
							<< PtsJogador2 << jogador2 << endl;
					}
					else if (CardsJogador1[PosRandom].estrelas == CardsJogador2[PosRandom].estrelas) {
						PtsJogador1 += 0;
						PtsJogador2 += 0;
						cout << "Placar : " << jogador1 << " " << PtsJogador1 << " x "
							<< PtsJogador2 << jogador2 << endl;
					}
					else {
						PtsJogador2 += 2;
						cout << "Placar : " << jogador1 << " " << PtsJogador1 << " x "
							<< PtsJogador2 << jogador2 << endl;
					}
					tracos(25);
					break;
				default:
					cout << "Atributo Inválido!" << endl;
					Sleep(1200);
					system("cls");
					continue;
				}
				if (AlternaJogador == 1) {
					AlternaJogador = 2;
				}
				else if (AlternaJogador == 2) {
					AlternaJogador = 1;
				}

				if (i == 3) {
					cout << "Final: " << jogador1 << ": " << PtsJogador1 << " x ";
					cout << PtsJogador2 << " " << jogador2 << endl;
					tracos(25);
					PtsJogador1 = 0;
					PtsJogador2 = 0;
					Sleep(4000);
					system("cls");
				}
			}
			break;
		case 'N':
			cout << "Obrigado Por Jogar!\n";
			fechar = true;	
			break;
		default:
			cout << "Opcao Incorreta" << endl;
			Sleep(700);
			system("cls");
			break;
		}
	} while (fechar != true);

	system("pause");
	return 0;
}