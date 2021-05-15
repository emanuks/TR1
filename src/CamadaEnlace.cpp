/*
 *  CamadaFisica.hpp
 *
 *  Created on: 9 de maio de 2021
 *      Author: emanuks
 */

#include "CamadaEnlace.hpp"
#include "CamadaFisica.hpp"

void CamadaEnlaceDadosTransmissora(vector<int> quadro) {
	vector<int> auxQuadro;

	auxQuadro = CamadaEnlaceDadosTransmissoraEnquadramento(quadro);

	auxQuadro = CamadaEnlaceDadosTransmissoraControleDeErro(auxQuadro);

	// Chama a próxima camada
	CamadaFisicaTransmissora(auxQuadro);
} // Fim do método CamadaEnlaceDadosTransmissora

vector<int> CamadaEnlaceDadosTransmissoraEnquadramento(vector<int> quadro) {
	int tipoDeEnquadramento = 0; // Alterar de acordo com o teste
	vector<int> quadroEnquadrado;

	cout << "-----------------------" << endl;
	cout << "Mensagem Enquadrada: ";
	switch(tipoDeEnquadramento) {
		case 0: // Contagem de caracteres
			quadroEnquadrado = CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(quadro);
			break;
		case 1:	// Insercao de bytes
			quadroEnquadrado = CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(quadro);
			break;
	} // Fim do Switch/Case

	return quadroEnquadrado;
} // Fim do método CamadaEnlaceDadosTransmissoraEnquadramento

vector<int> CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(vector<int> quadro) {
	string aux = "";

	aux += bitset<8>(quadro.size()/8).to_string();

	for (int i = aux.length() - 1; i >= 0; i--) {
		quadro.insert(quadro.begin(), aux[i] - 48);
	}

	for (int i = 0; i < quadro.size(); i++) {
		cout << quadro[i];
	}
	cout << endl;

	return quadro;
} // Fim do método CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres

vector<int> CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(vector<int> quadro) {
	string flag = "00001111";

	for (int i = flag.length() - 1; i >= 0; i--) {
		quadro.insert(quadro.begin(), flag[i] - 48);
	}

	for (int i = 0; i < flag.length(); i++) {
		quadro.insert(quadro.end(), flag[i] - 48);
	}

	for (int i = 0; i < quadro.size(); i++) {
		cout << quadro[i];
	}
	cout << endl;

	return quadro;
} // Fim do método CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes

void CamadaEnlaceDadosReceptora(vector<int> quadro) {
	vector<int> auxQuadro;

	auxQuadro = CamadaEnlaceDadosReceptoraControleDeErro(quadro);

	auxQuadro = CamadaEnlaceDadosReceptoraEnquadramento(auxQuadro);

	// Chama a próxima camada
	CamadaDeAplicacaoReceptora(auxQuadro);
} // Fim do método CamadaEnlaceDadosReceptora

vector<int> CamadaEnlaceDadosReceptoraEnquadramento(vector<int> quadro) {
	int tipoDeEnquadramento = 0; // Alterar de acordo com o teste
	vector<int> quadroDesenquadrado;

	cout << "-----------------------" << endl;
	cout << "Mensagem Desenquadrada: ";
	switch(tipoDeEnquadramento) {
	case 0: // Contagem de caracteres
		quadroDesenquadrado = CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres(quadro);
		break;
	case 1: // Insercao de Bytes
		quadroDesenquadrado = CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes(quadro);
		break;
	} // Fim do Switch/Case

	return quadroDesenquadrado;
} // Fim do método CamadaEnlaceDadosReceptoraEnquadramento

vector<int> CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres(vector<int> quadro) {
	string aux;
	int counter;
	vector<int> auxQuadro;

	for(int i = 0; i < 8; i++) {
		aux += to_string(quadro[i]);
	}

	counter = stoi(aux, 0, 2);

	for(int i = 1; i <= counter; i++) {
		for(int j = i*8; j < i*8+8; j++) {
			auxQuadro.push_back(quadro[j]);
			cout << auxQuadro[j-8];
		}
	}
	cout << endl;

	return auxQuadro;
} // Fim do método CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres

vector<int> CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes(vector<int> quadro) {
	string flag, aux;
	int iterator;
	vector<int> auxQuadro;

	for(int i = 0; i < 8; i++) {
		flag += to_string(quadro[i]);
	}

	iterator = 1;
	while(true) {
		aux = "";

		for(int i = iterator*8; i < iterator*8+8; i++) {
			aux += to_string(quadro[i]);
		}

		if(aux == flag) {
			break;
		}

		for(int i = iterator*8; i < iterator*8+8; i++) {
			auxQuadro.push_back(quadro[i]);
			cout << auxQuadro.back();
		}

		iterator++;
	}
	cout << endl;

	return auxQuadro;
} // Fim do método CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes

vector<int> CamadaEnlaceDadosTransmissoraControleDeErro(vector<int> quadro) {
	int tipoDeControleDeErro = 0;
	vector<int> auxQuadro;

	switch(tipoDeControleDeErro) {
	case 0: // Bit de paridade par
		auxQuadro = CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar(quadro);
		break;
	case 1: // CRC
		auxQuadro = CamadaEnlaceDadosTransmissoraControleDeErroCRC(quadro);
		break;
	case 2: // Codigo de Hamming
		auxQuadro = CamadaEnlaceDadosTransmissoraControleDeErroCodigoDeHamming(quadro);
		break;
	}// Fim do Switch/Case

	return auxQuadro;
} // Fim do método CamadaEnlaceDadosTransmissoraControleDeErro

vector<int> CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar(vector<int> quadro) {
	int counter = 0;

	for(int i = 0; i < quadro.size(); i++){
		if(quadro[i] == 1) {
			counter++;
		}
	}

	counter%2 ? quadro.push_back(1) : quadro.push_back(0);

	return quadro;
} // Fim do método CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar

vector<int> CamadaEnlaceDadosTransmissoraControleDeErroCRC(vector<int> quadro) {
	vector<int> Gerador = { 1, 0, 0, 0, 0, 0 ,1 , 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1 };
	vector<int> auxQuadro = quadro;

	for(int i = 0; i < Gerador.size() - 1; i++) {
		auxQuadro.push_back(0);
	}

	for(int i = 0; i < quadro.size(); i++){
		if (auxQuadro[i] == 1) {
			for(int j = 0; j < Gerador.size(); j++) {
				auxQuadro[j+i] ^= Gerador[j];
			}
		}
	}

	for(int i = 0; i < quadro.size(); i++) {
		auxQuadro[i] = quadro[i];
	}

	return auxQuadro;
} // Fim do método CamadaEnlaceDadosTransmissoraControleDeErroCRC

vector<int> CamadaEnlaceDadosReceptoraControleDeErro(vector<int> quadro) {
	int tipoDeControleDeErro = 0;
	vector<int> auxQuadro;

	switch(tipoDeControleDeErro) {
	case 0: // Bit de paridade par
		auxQuadro = CamadaEnlaceDadosReceptoraControleDeErroBitParidadePar(quadro);
		break;
	case 1: // CRC
		auxQuadro = CamadaEnlaceDadosReceptoraControleDeErroCRC(quadro);
		break;
	case 2: // Codigo de Hamming
		auxQuadro = CamadaEnlaceDadosReceptoraControleDeErroCodigoDeHamming(quadro);
		break;
	} // Fim do Switch/Case

	return auxQuadro;
} // Fim do método CamadaEnlaceDadosReceptoraControleDeErro

vector<int> CamadaEnlaceDadosReceptoraControleDeErroBitParidadePar(vector<int> quadro) {
	int counter = 0;

	for(int i = 0; i < quadro.size(); i++){
		if(quadro[i] == 1) {
			counter++;
		}
	}

	if(counter%2 == 1) {
		cout << "-----------------------" << endl;
		cout << "Erro Detectado!" << endl;
	}

	quadro.pop_back();

	return quadro;
} // Fim do método CamadaEnlaceDadosReceptoraControleDeErroBitParidadePar

vector<int> CamadaEnlaceDadosReceptoraControleDeErroCRC(vector<int> quadro) {
	vector<int> Gerador = { 1, 0, 0, 0, 0, 0 ,1 , 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1 };
	vector<int> auxQuadro = quadro;
	int resto;
	bool found;

	for(int i = 0; i < quadro.size() - Gerador.size() - 1; i++){
		if (auxQuadro[i] == 1) {
			for(int j = 0; j < Gerador.size(); j++) {
				auxQuadro[j+i] ^= Gerador[j];
			}
		}
	}

	for(int i = 0; i < auxQuadro.size(); i++) {
		cout << auxQuadro[i];
	}
	cout << endl;

	for(int i = 0; i < Gerador.size() - 1; i++) {
		resto = auxQuadro.back();
		auxQuadro.pop_back();
		if(resto == 1){
			found = true;
		}
	}

	for(int i = 0; i < quadro.size(); i++) {
		auxQuadro[i] = quadro[i];
	}

	if(found) {
		cout << "-----------------------" << endl;
		cout << "Erro Detectado!" << endl;
	}

	return auxQuadro;
} // Fim do método CamadaEnlaceDadosReceptoraControleDeErroCRC

vector<int> CamadaEnlaceDadosTransmissoraControleDeErroCodigoDeHamming(vector<int> quadro){
	return quadro;
}

vector<int> CamadaEnlaceDadosReceptoraControleDeErroCodigoDeHamming(vector<int> quadro){
	return quadro;
}
