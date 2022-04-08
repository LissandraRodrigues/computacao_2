/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Programa que retorna a sequencia 
 *						Fibonacci se utilizando da estrutura
 *            de repeticao While. 
 *
 * $Author: luiza.rosa $
 * $Date: 2021/12/08 21:14:41 $
 * $Log: aula0201d.c,v $
 * Revision 1.1  2021/12/08 21:14:41  luiza.rosa
 * Initial revision
 *
*/

#include "aula0201.h"

ull
CalcularTermoSerieFibonacci (us numero)
{

	ull indice = 1;

	ull auxiliar1 = 0;	
	ull auxiliar2 = 1;

	ull resultado = 0;

	if (numero <= 1)
		return numero;

	while (indice <= numero)
	{

		auxiliar1 = resultado + auxiliar2;
		
		resultado = auxiliar2;

		auxiliar2 = auxiliar1;		
	
		indice++;

	}
	
	return resultado;

}
/* RCSfile$ */
