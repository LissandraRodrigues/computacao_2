/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Programa de testes que exibe a sequencia 
 *						Fibonacci. 
 *
 * $Author: luiza.rosa $
 * $Date: 2021/12/08 21:10:49 $
 * $Log: aula0202.c,v $
 * Revision 1.1  2021/12/08 21:10:49  luiza.rosa
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
#include <math.h>
#include <limits.h>
#include <errno.h>

#include "aula0201.h"

#define SUCESSO																		0

#define NUMERO_ARGUMENTOS_INVALIDO								1
#define ARGUMENTO_INVALIDO												2
#define ARGUMENTO_CONTEM_CARACTERE_INVALIDO				3
#define BASE_INVALIDA															4
#define VALOR_MAXIMO_UNSIGNED_LONG_EXCEDIDO				5
#define VALOR_MAXIMO_UNSIGNED_SHORT_EXCEDIDO			6
#define VALOR_MAXIMO_UNSIGNED_LONG_LONG_EXCEDIDO  7

#define NUMERO_ARGUMENTOS													2
#define EOS																				'\0'

int
main (int argc, char *argv []) 
{

	char *verificacao;

	us numero;	
	ull numeroLongo;

	ull resultado = 0;
	ull resultadoAnterior = 0;
	
	us indice;

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\nUso: %s <inteiro-nao-negativo>\n\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	if (argv [1][0] == '-')
	{
		printf ("\nEste programa nao aceita numeros negativos.\n\n");
		exit (ARGUMENTO_INVALIDO);
	}

	numeroLongo = strtoul (argv [1], &verificacao, 10);

	if (errno == EINVAL)
	{
		printf ("\nBase invalida\n\n");
		exit (BASE_INVALIDA);
	}
	
	if (errno == ERANGE)
	{	
		printf ("\nValor fornecido ultrapassa o valor maximo permitido para unsigned long (%lu)\n\n",
						ULONG_MAX);
		exit (VALOR_MAXIMO_UNSIGNED_LONG_EXCEDIDO);
	}

	if (*verificacao != EOS)
	{
		printf ("\nArgumento contem caractere invalido.\n");
		printf ("Primeiro caractere invalido: \'%c\'\n\n", *verificacao);
		exit (ARGUMENTO_CONTEM_CARACTERE_INVALIDO);
	}
  
	if (numeroLongo > USHRT_MAX)
	{	
		printf ("\nValor fornecido ultrapassa o valor maximo permitido para unsigned short (%i)\n\n",
						USHRT_MAX);
		exit (VALOR_MAXIMO_UNSIGNED_SHORT_EXCEDIDO);
	}

	numero = (unsigned short) numeroLongo;

	printf ("\n");

	for (indice = 0; indice <= numero; indice++)
	{

		resultado = CalcularTermoSerieFibonacci (indice);		

		if (resultado < resultadoAnterior)
		{
			printf ("\nValor maximo do tipo long long unsigned foi excedido\n\n");
			exit (VALOR_MAXIMO_UNSIGNED_LONG_LONG_EXCEDIDO);	
		}

		printf ("F(%d) = %llu\n", indice, resultado);

		resultadoAnterior = resultado;
	
	}

	printf ("\n");

	return SUCESSO;

}

/* $RCSfile: aula0202.c,v $ */
