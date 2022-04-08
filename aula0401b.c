/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Programa que calcula um numero elevado a um expoente 
 *						se utilizando da estrutura de repeticao Do... While. 
 *
 * $Author: luiza.rosa $
 * $Date: 2022/01/06 01:50:06 $
 * $Log: aula0401b.c,v $
 * Revision 1.2  2022/01/06 01:50:06  luiza.rosa
 * Programa: Insercao de melhores praticas de programacao e tratamento de erros.
 *
 * Revision 1.1  2022/01/05 23:57:11  luiza.rosa
 * Initial revision
 *
*/

#include <math.h>

#include "aula0401.h"

long double
CalcularExponencial (double base, int expoente)
{

	long double resultado = 1;

	if ((!base) && (expoente < 0))
	{
		#if defined (__STRICT_ANSI__) && defined (__linux__)
			return 1.0 / 0.0;
		#else
			return INFINITY;
		#endif
	}

	if (!expoente)
		return 1;
	
	if (expoente == 1)
		return base;

	if (expoente > 0)		
	{
		/* Expoente positivo */
		do
		{

			resultado *= base; 
			expoente -= 1;
		 
		}	
		while ((expoente != 0) && (expoente > 0));
 			
	}
	else							
	{
		/* Expoente negativo */
		do
		{

			resultado *= base; 
			expoente += 1; 			
		
		}
		while ((expoente != 0) && (expoente < 0));
	
		resultado = 1 / resultado;

	}

	return resultado;
	
}

/* $RCSfile: aula0401b.c,v $ */
