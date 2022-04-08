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
 *            de repeticao For. 	
 *
 * $Author: luiza.rosa $
 * $Date: 2021/12/08 21:13:49 $
 * $Log: aula0201c.c,v $
 * Revision 1.1  2021/12/08 21:13:49  luiza.rosa
 * Initial revision
 *
*/

#include "aula0201.h"

ull
CalcularTermoSerieFibonacci (us numero)
{
	
	ull indice;

	ull auxiliar1 = 0;
	ull auxiliar2 = 1;
	 
	ull resultado = 0;
	
	if (numero == 0)
		return resultado;

	for (indice = 1; indice <= numero; indice++)
	{
	
		auxiliar1 = resultado + auxiliar2;

		resultado = auxiliar2;		

		auxiliar2 = auxiliar1;

	}

	return resultado;	

}

/* $RCSfile: aula0201c.c,v $ */
