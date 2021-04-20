/*
 *  CamadaEnlace.hpp
 *
 *  Created on: 20 de abr. de 2021
 *      Author: emanuks
 */

#ifndef _CAMADA_ENLACE_H_
#define _CAMADA_ENLACE_H_

#include <vector>

using namespace std;

void CamadaEnlaceDadosTransmissora(vector<int>);

void CamadaEnlaceDadosTransmissoraEnquadramento(vector<int>);

vector<int> CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(vector<int>);

vector<int> CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(vector<int>);

void CamadaEnlaceDadosReceptora(vector<int>);

void CamadaEnlaceDadosReceptoraEnquadramento(vector<int>);

vector<int> CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres(vector<int>);

vector<int> CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes(vector<int>);

#endif