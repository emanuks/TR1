/*
 *  CamadaFisica.hpp
 *
 *  Created on: 9 de maio de 2021
 *      Author: emanuks
 */

#ifndef _CAMADA_ENLACE_HPP_
#define _CAMADA_ENLACE_HPP_

#include <string>
#include <iostream>
#include <vector>
#include <bitset>
#include <math.h>

using namespace std;

void CamadaEnlaceDadosTransmissora(vector<int>);

vector<int> CamadaEnlaceDadosTransmissoraEnquadramento(vector<int>);

vector<int> CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(vector <int>);

vector<int> CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(vector<int>);

void CamadaEnlaceDadosReceptora(vector<int>);

vector<int> CamadaEnlaceDadosReceptoraEnquadramento(vector<int>);

vector<int> CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres(vector<int>);

vector<int> CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes(vector<int>);

vector<int> CamadaEnlaceDadosTransmissoraControleDeErro(vector<int>);

vector<int> CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar(vector<int>);

vector<int> CamadaEnlaceDadosTransmissoraControleDeErroCRC(vector<int>);

vector<int> CamadaEnlaceDadosReceptoraControleDeErro(vector<int>);

vector<int> CamadaEnlaceDadosReceptoraControleDeErroBitParidadePar(vector<int>);

vector<int> CamadaEnlaceDadosReceptoraControleDeErroCRC(vector<int>);

vector<int> CamadaEnlaceDadosTransmissoraControleDeErroCodigoDeHamming(vector<int>);

vector<int> CamadaEnlaceDadosReceptoraControleDeErroCodigoDeHamming(vector<int>);

#endif
