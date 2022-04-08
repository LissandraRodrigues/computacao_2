/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Programa de testes do programa de Calcular Exponencial.
 *
 * $Author: luiza.rosa $
 * $Date: 2022/01/06 12:54:38 $
 * $Log: aula0402.c,v $
 * Revision 1.4  2022/01/06 12:54:38  luiza.rosa
 * Programa: Insercao de mais tratamentos de erros.
 *
 * Revision 1.3  2022/01/06 01:49:35  luiza.rosa
 * Programa: Insercao de melhores praticas de programacao e tratamento de erros.
 *
 * Revision 1.2  2022/01/05 23:58:53  luiza.rosa
 * Programa: Correcao de um detalhe relacionado ao resultado INFINITY.
 *
 * Revision 1.1  2022/01/04 21:48:26  luiza.rosa
 * Initial revision
 *
*/

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __ISO_C_VISIBLE 1999
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <errno.h>

#include "aula0401.h"

#define SUCESSO																		0

#define NUMERO_ARGUMENTOS_INVALIDO								1
#define ARGUMENTO_INVALIDO												2
#define ARGUMENTO_CONTEM_CARACTERE_INVALIDO				3
#define BASE_INVALIDA															4
#define VALOR_MAXIMO_DOUBLE_EXCEDIDO							5
#define VALOR_MAXIMO_INT_EXCEDIDO									6
#define VALOR_MAXIMO_LONG_DOUBLE_EXCEDIDO					7
#define BASE_ZERO_EXPOENTE_NEGATIVO								8
 
#define NUMERO_ARGUMENTOS													3
#define EOS																				'\0'

int
main (int argc, char *argv []) 
{

	char *verificacao;

	double base;	
	int expoente;

	long double resultado;
		
	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\nUso: %s <double-base inteiro-expoente>.\n\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	/* Base */

	base = strtod (argv [1], &verificacao);
	
	if (*verificacao != EOS)
	{
		printf ("\nO primeiro argumento contem caractere invalido.\n");
		printf ("Primeiro caractere invalido: \'%c\'.\n\n", *verificacao);
		exit (ARGUMENTO_CONTEM_CARACTERE_INVALIDO);
	}

	if (errno == ERANGE)
	{
		printf ("\nO valor de base fornecido ultrapassa o maximo permitido para double (%f).\n\n",
						DBL_MAX);
		exit (VALOR_MAXIMO_DOUBLE_EXCEDIDO);
	}

	/* Expoente */

	expoente = strtol (argv [2], &verificacao, 10);

	if (*verificacao != EOS)
	{
		printf ("\nO segundo argumento contem caractere invalido.\n");
		printf ("Primeiro caractere invalido: \'%c\'.\n\n", *verificacao);
		exit (ARGUMENTO_CONTEM_CARACTERE_INVALIDO);
	}

	if (errno == EINVAL)
	{
		printf ("\nBase invalida.\n\n");
		exit (BASE_INVALIDA);
	}

	if (errno == ERANGE)
	{	
		printf ("\nO valor de expoente fornecido ultrapassa o maximo permitido para int (%i).\n\n",
						INT_MAX);
		exit (VALOR_MAXIMO_INT_EXCEDIDO);
	}
	
	/* Resultado */ 

	resultado = CalcularExponencial (base, expoente);
	
	if ((resultado >= LDBL_MAX) && (base != 0) && (expoente > 0))
	{
		printf ("\nO valor maximo do long double foi excedido.\n\n");
		exit (VALOR_MAXIMO_LONG_DOUBLE_EXCEDIDO); 
	}
	else if	(resultado == INFINITY)
	{
		printf ("\n(%.2f)^(%i) = Infinito\n\n", base, expoente);
		exit (BASE_ZERO_EXPOENTE_NEGATIVO);
	}
	
	printf ("\n(%.2f)^(%i) = %.10Lf\n\n", base, expoente, resultado);

	return SUCESSO;

}

/* $RCSfile: aula0402.c,v $ */
