/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Programa que calcula um numero elevado a um expoente
 *						com Recursividade.
 *
 * $Author: luiza.rosa $
 * $Date: 2022/01/06 13:05:37 $
 * $Log: aula0401a.c,v $
 * Revision 1.5  2022/01/06 13:05:37  luiza.rosa
 * Programa: Insercao de melhores praticas de programacao.
 *
 * Revision 1.4  2022/01/06 13:03:13  luiza.rosa
 * Programa: Insercao de melhores praticas de programacao.
 *
 * Revision 1.3  2022/01/06 01:47:58  luiza.rosa
 * Programa: Insercao de melhores praticas de programacao e tratamento de erros.
 *
 * Revision 1.2  2022/01/05 16:50:40  luiza.rosa
 * Programa: Insercao de melhores praticas de programacao.
 *
 * Revision 1.1  2022/01/04 21:42:47  luiza.rosa
 * Initial revision
 *
*/

#include <math.h>

#include "aula0401.h"

long double
CalcularExponencial (double base, int expoente)
{

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
			return base * CalcularExponencial (base, expoente - 1);
		}
		else
		{
			return (1 / base) * CalcularExponencial (base, expoente + 1);
		}

}

/* $RCSfile: aula0401a.c,v $ */
