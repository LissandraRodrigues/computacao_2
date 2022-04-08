/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Programa de testes do programa de MDC.
 *
 * $Author: luiza.rosa $
 * $Date: 2021/12/15 13:38:48 $
 * $Log: aula0302.c,v $
 * Revision 1.2  2021/12/15 13:38:48  luiza.rosa
 * Programa: Insercao de melhores praticas de programacao.
 *
 * Revision 1.1  2021/12/14 16:49:25  luiza.rosa
 * Initial revision
 *
*/

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif 

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __ISO_C_VISIBLE				  1999
#define __LONG_LONG_SUPPORTED
#endif  

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

#include "aula0301.h"

#define SUCESSO																		0

#define NUMERO_ARGUMENTOS_INVALIDO								1
#define ARGUMENTO_INVALIDO												2
#define ARGUMENTO_CONTEM_CARACTERE_INVALIDO				3
#define BASE_INVALIDA															4
#define VALOR_MAXIMO_UNSIGNED_LONG_LONG_EXCEDIDO  5
#define DIVISOR_NULO															6

#define NUMERO_ARGUMENTOS													3
#define EOS																				'\0'

int
main (int argc, char *argv []) 
{

	char *verificacao;

	ull numero1;	
	ull numero2;

	ull resultado;
		
	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\nUso: %s <inteiro-positivo inteiro-positivo>\n\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	if ((argv [1][0] == '-') || (argv [2][0] == '-'))
	{
		printf ("\nEste programa nao aceita numeros negativos.\n\n");
		exit (ARGUMENTO_INVALIDO);
	}

	/* Numero 1 */

	numero1 = strtoull (argv [1], &verificacao, 10);
	
	if (*verificacao != EOS)
	{
		printf ("\nO primeiro argumento contem caractere invalido.\n");
		printf ("Primeiro caractere invalido: \'%c\'\n\n", *verificacao);
		exit (ARGUMENTO_CONTEM_CARACTERE_INVALIDO);
	}

	if (errno == EINVAL)
	{
		printf ("\nBase invalida\n\n");
		exit (BASE_INVALIDA);
	}
	
	if (errno == ERANGE)
	{	
		printf ("\nO primeiro valor fornecido ultrapassa o maximo permitido para unsigned long long (%llu)\n\n",
						ULLONG_MAX);
		exit (VALOR_MAXIMO_UNSIGNED_LONG_LONG_EXCEDIDO);
	}

	/* Numero 2 */

	numero2 = strtoull (argv [2], &verificacao, 10);

	if (*verificacao != EOS)
	{
		printf ("\nO segundo argumento contem caractere invalido.\n");
		printf ("Primeiro caractere invalido: \'%c\'\n\n", *verificacao);
		exit (ARGUMENTO_CONTEM_CARACTERE_INVALIDO);
	}

	if (errno == EINVAL)
	{
		printf ("\nBase invalida\n\n");
		exit (BASE_INVALIDA);
	}
	
	if (errno == ERANGE)
	{	
		printf ("\nO segundo valor fornecido ultrapassa o maximo permitido para unsigned long long (%llu)\n\n",
						ULLONG_MAX);
		exit (VALOR_MAXIMO_UNSIGNED_LONG_LONG_EXCEDIDO);
	}

	resultado = CalcularMaximoDivisorComum (numero1, numero2);

	if (!resultado)
	{
		printf ("\nArgumentos invalidos. Os dois valores nao podem ser nulos ao mesmo tempo.\n\n");
		exit (DIVISOR_NULO);
	} 
	else
		printf ("\nMDC(%llu, %llu) = %llu\n\n", numero1, numero2, resultado);

	return SUCESSO;

}

/* $RCSfile: aula0302.c,v $ */
