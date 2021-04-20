/*
 *  CamadaFisica.cpp
 *
 *  Created on: 5 de abr. de 2021
 *      Author: emanuks
 */

#include "../include/CamadaFisica.hpp"

void AplicacaoTransmissora() {
	string mensagem;
	cout << "Digite uma mensagem: ";
	getline(cin, mensagem);

	// Chama a próxima camada
	CamadaDeAplicacaoTransmissora(mensagem);
} // Fim do método AplicacaoTransmissora

void CamadaDeAplicacaoTransmissora(string mensagem) {
	vector<int> quadro;

	string aux = "";

	for (char &_char : mensagem) {
		aux += bitset<8>(_char).to_string();
	}

	cout << "-----------------------" << endl;
	cout << "Mensagem em Bits: ";
	for (int i = 0; i < aux.length(); i++) {
		quadro.push_back(aux[i] - 48); // Subtraindo o valor de '0' em ASCII
		cout << quadro[i];
	}
	cout << endl;

	// Chama a próima camada
	CamadaFisicaTransmissora(quadro);
} // Fim do método CamadaDeAplicacaoTransmissora

void CamadaFisicaTransmissora(vector<int> quadro) {
	int tipoDeCodificacao = 2; // Alterar de acordo com o teste
	vector<int> fluxoBrutoDeBits;

	cout << "-----------------------" << endl;
	cout << "Mensagem Codificada: ";
	switch (tipoDeCodificacao) {
	case 0: // Codificação Binária
		fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBinaria(quadro);
		break;
	case 1: // Codificação Manchester
		fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoManchester(quadro);
		break;
	case 2:	// Codificação Bipolar
		fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBipolar(quadro);
		break;
	} // Fim do Switch/Case

	MeioDeComunicacao(fluxoBrutoDeBits);
} // Fim do método CamadaFisicaTransmissora

vector<int> CamadaFisicaTransmissoraCodificacaoBinaria(vector<int> quadro) {
	for (int i = 0; i < quadro.size(); i++) {
		cout << quadro[i];
	}
	cout << endl;

	return quadro;
} // Fim do método CamadaFisicaTransmissoraCodificacaoBinaria

vector<int> CamadaFisicaTransmissoraCodificacaoManchester(vector<int> quadro) {
	vector<int> encoded;

	for (int i = 0; i < quadro.size(); i++) {
		switch (quadro[i]) {
		case 0:
			encoded.push_back(0);
			encoded.push_back(1);
			break;
		case 1:
			encoded.push_back(1);
			encoded.push_back(0);
			break;
		}
	}

	for (int i = 0; i < encoded.size(); i++) {
		cout << encoded[i];
	}
	cout << endl;

	return encoded;
} // Fim do método CamadaFisicaTransmissoraCodificacaoManchester

vector<int> CamadaFisicaTransmissoraCodificacaoBipolar(vector<int> quadro) {
	vector<int> encoded;
	bool lastSignalNeg = true; // Indica se o último sinal foi negativo

	for (int i = 0; i < quadro.size(); i++) {
		switch (quadro[i]) {
		case 0:
			encoded.push_back(0);
			break;
		case 1:
			if (lastSignalNeg) {
				encoded.push_back(1);
				lastSignalNeg = false;
			} else {
				encoded.push_back(-1);
				lastSignalNeg = true;
			}
			break;
		}
		cout << encoded[i];
	}
	cout << endl;

	return encoded;
} // Fim do método CamadaFisicaTransmissoraCodificacaoBipolar

void MeioDeComunicacao(vector<int> fluxoBrutoDeBits) {
	vector<int> fluxoBrutoDeBitsPontoA;
	vector<int> fluxoBrutoDeBitsPontoB;

	fluxoBrutoDeBitsPontoA = fluxoBrutoDeBits;

	while (fluxoBrutoDeBitsPontoB.size() != fluxoBrutoDeBitsPontoA.size()) {
		fluxoBrutoDeBitsPontoB = fluxoBrutoDeBitsPontoA; // BITS! Sendo transferidos
	} // Fim do While

	// Chama próxima camada
	CamadaFisicaReceptora(fluxoBrutoDeBitsPontoB);
} // Fim do método MeioDeComunicacao

void CamadaFisicaReceptora(vector<int> quadro) {
	int tipoDeDecodificacao = 2; // Alterar de acordo com o teste
	vector<int> fluxoBrutoDeBits;

	cout << "-----------------------" << endl;
	cout << "Mensagem Decodificada: ";
	switch (tipoDeDecodificacao) {
	case 0:
		fluxoBrutoDeBits = CamadaFisicaReceptoraDecodificacaoBinaria(quadro);
		break;
	case 1:
		fluxoBrutoDeBits = CamadaFisicaReceptoraDecodificacaoManchester(quadro);
		break;
	case 2:
		fluxoBrutoDeBits = CamadaFisicaReceptoraDecodificacaoBipolar(quadro);
		break;
	} // Fim do Switch/Case

	// Chama próxima camada
	CamadaDeAplicacaoReceptora(fluxoBrutoDeBits);
} // Fim do método CamadaFisicaTransmissora

vector<int> CamadaFisicaReceptoraDecodificacaoBinaria(vector<int> quadro) {
	for (int i = 0; i < quadro.size(); i++) {
		cout << quadro[i];
	}
	cout << endl;

	return quadro;
} // Fim do método CamadaFisicaReceptoraDecodificacaoBinaria

vector<int> CamadaFisicaReceptoraDecodificacaoManchester(vector<int> quadro) {
	vector<int> decoded;
	string bits; // Armazena os pares de bits da codificação de manchester

	for (int i = 0; i < quadro.size(); i+=2) {
		bits = "";
		bits += to_string(quadro[i]);
		bits += to_string(quadro[i+1]);

		if (bits == "01") {
			decoded.push_back(0);
		} else if (bits == "10") {
			decoded.push_back(1);
		}
	}

	for (int i = 0; i < decoded.size(); i++) {
		cout << decoded[i];
	}
	cout << endl;

	return decoded;
} // Fim do método CamadaFisicaReceptoraDecodificacaoManchester

vector<int> CamadaFisicaReceptoraDecodificacaoBipolar(vector<int> quadro) {
	vector<int> decoded;

	for (int i = 0; i < quadro.size(); i++) {
		switch (quadro[i]) {
		case 0:
			decoded.push_back(0);
			break;
		default:
			decoded.push_back(1);
			break;
		}
		cout << decoded[i];
	}
	cout << endl;

	return decoded;
} // Fim do método CamadaFisicaReceptoraDecodificacaoBipolar

void CamadaDeAplicacaoReceptora(vector<int> quadro) {
	string mensagem, aux, mensagemAux;

	for (int i = 0; i < quadro.size(); i++) {
		mensagemAux += to_string(quadro[i]);
	}

	for (int i = 0; i < quadro.size()/8; i++) {
		aux = "";
		for (int j = i*8; j < i*8+8; j++) {
			aux += mensagemAux[j];
		}
		mensagem += (char)stoi(aux, 0, 2);
	}

	// Chama próxima camada
	AplicacaoReceptora(mensagem);
} // Fim do método CamadaDeAplicacaoReceptora

void AplicacaoReceptora(string mensagem) {
	cout << "-----------------------" << endl;
	cout << "A mensagem recebida foi: " <<  mensagem << endl;
} // Fim do método AplicacaoReceptora
