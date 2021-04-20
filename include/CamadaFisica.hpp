/*
 *  CamadaFisica.hpp
 *
 *  Created on: 5 de abr. de 2021
 *      Author: emanuks
 */

#ifndef _CAMADA_FISICA_HPP_
#define _CAMADA_FISICA_HPP_

#include <string>
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;


void AplicacaoTransmissora();

void CamadaDeAplicacaoTransmissora(string);

void CamadaFisicaTransmissora(vector<int>);

/*
 * Recebe como parâmetro um vetor de bits e retorna o mesmo valor
 */
vector<int> CamadaFisicaTransmissoraCodificacaoBinaria(vector<int>);

/*
 * Recebe como parâmetro um vetor de bits
 * Se o bit atual for 0 codifica em 01
 * Se o bit atual for 1 codifica em 10
 * Retorna um vetor com os bits codificados
 */
vector<int> CamadaFisicaTransmissoraCodificacaoManchester(vector<int>);

/*
 * Recebe como parâmetro um vetor de bits
 * Se o bit atual for 0 codifica em 0
 * Se o bit atual for 1 codifica alternadamente entre + e -
 * Retorna um vetor com os bits codificados
 */
vector<int> CamadaFisicaTransmissoraCodificacaoBipolar(vector<int>);

/* Este método simula a transmissão da informação no meio de
 * comunicação, passando de um pontoA (transmissor) para um
 * pontoB (receptor)
 */
void MeioDeComunicacao(vector<int>);

void CamadaFisicaReceptora(vector<int>);

/*
 * Recebe como parâmetro um vetor de bits e retorna o mesmo valor
 */
vector<int> CamadaFisicaReceptoraDecodificacaoBinaria(vector<int>);

/*
 * Recebe como parâmetro um vetor de bits
 * Separa o vetor em pares de bits
 * Se o par atual for 01 decodifica em 0
 * Se o par atual for 10 decodifica em 1
 * Retorna um vetor com os bits decodificados
 */
vector<int> CamadaFisicaReceptoraDecodificacaoManchester(vector<int>);

/*
 * Recebe como parâmetro um vetor de bits
 * Se o valor atual for 0 decodifica em 0
 * Se o valor atual for + ou - decodifica em 1
 * Retorna um vetor com os bits decodificados
 */
vector<int> CamadaFisicaReceptoraDecodificacaoBipolar(vector<int>);

void CamadaDeAplicacaoReceptora(vector<int>);

void AplicacaoReceptora(string);

#endif
