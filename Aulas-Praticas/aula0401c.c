/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Programa que calcula um numero elevado a um expoente 
 *						se utilizando da estrutura de repeticao For. 
 *
 * $Author: luiza.rosa $
 * $Date: 2022/01/06 02:49:55 $
 * $Log: aula0401c.c,v $
 * Revision 1.1  2022/01/06 02:49:55  luiza.rosa
 * Initial revision
 *
*/

#include <math.h>

#include "aula0401.h"

long double
CalcularExponencial (double base, int expoente)
{
		
	int indice;

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
		for (indice = 0; indice < expoente; indice++)
			resultado *= base;  			
	
	}
	else							
	{
		/* Expoente negativo */
		for (indice = expoente; indice < 0; indice++)
			resultado *= base; 
					
		resultado = 1 / resultado;

	}

	return resultado;
	
}

/* $RCSfile: aula0401c.c,v $ */
