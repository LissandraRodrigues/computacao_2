/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Programa que exibe a sequencia 
 *						Fibonacci se utilizando de Recursividade. 
 *
 * $Author: luiza.rosa $
 * $Date: 2021/12/08 21:11:50 $
 * $Log: aula0201a.c,v $
 * Revision 1.1  2021/12/08 21:11:50  luiza.rosa
 * Initial revision
 *
*/

#include "aula0201.h"

ull
CalcularTermoSerieFibonacci (us numero)
{

	if (numero <= 1)
		return numero;

	return CalcularTermoSerieFibonacci (numero - 1) + CalcularTermoSerieFibonacci (numero - 2);

}

/* $RCSfile: aula0201a.c,v $ */
