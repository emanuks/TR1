/*
 *  CamadaEnlace.cpp
 *
 *  Created on: 20 de abr. de 2021
 *      Author: emanuks
 */

#include "../include/CamadaEnlace.hpp"
#include "../include/CamadaFisica.hpp"

void CamadaEnlaceDadosTransmissora(vector<int> quadro)
{
	CamadaEnlaceDadosTransmissoraEnquadramento(quadro);

	// Chama a próxima camada
	CamadaFisicaTransmissora(quadro);
} // Fim do método CamadaEnlaceDadosTransmissora

void CamadaEnlaceDadosTransmissoraEnquadramento(vector<int> quadro)
{
	int tipoDeEnquadramento = 0; // Alterar de acordo com o teste
	vector<int> quadroEnquadrado;

	switch (tipoDeEnquadramento)
	{
	case 0: // Contagem de caracteres
		quadroEnquadrado = CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(quadro);
		break;
	case 1: // Inserção de bytes
		quadroEnquadrado = CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(quadro);
		break;
	} // Fim do Switch/Case

} // Fim do método CamadaEnlaceDadosTransmissoraEnquadramento

vector<int> CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(vector<int> quadro)
{

} // Fim do método CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres

vector<int> CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(vector<int> quadro)
{

} // Fim do método CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes

void CamadaEnlaceDadosReceptora(vector<int> quadro)
{
	CamadaEnlaceDadosReceptoraEnquadramento(quadro);

	// Chama a próxima camada
	CamadaDeAplicacaoReceptora(quadro);
} // Fim do método CamadaEnlaceDadosReceptora

void CamadaEnlaceDadosReceptoraEnquadramento(vector<int> quadro)
{
	int tipoDeEnquadramento = 0;
	vector<int> quadroDesenquadrado;

	switch (tipoDeEnquadramento)
	{
	case 0: // Contagem de caracteres
		quadroDesenquadrado = CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres(quadro);
		break;
	case 1:
		quadroDesenquadrado = CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes(quadro);
		break;
	} // Fim do Switch/Case

} // Fim do método CamadaEnlaceDadosReceptoraEnquadramento

vector<int> CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres(vector<int> quadro)
{

} // Fim do método CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres

vector<int> CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes(vector<int> quadro)
{

} // Fim do método CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes
