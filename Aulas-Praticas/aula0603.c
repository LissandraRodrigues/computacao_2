/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Programa de testes da funcao de
 *            obter matriz transposta.
 *
 * $Author: luiza.rosa $
 * $Date: 2022/01/25 01:09:05 $
 * $Log: aula0603.c,v $
 * Revision 1.4  2022/01/25 01:09:05  luiza.rosa
 * Programa: Insercao de tratamento de erro para o valor maximo dos elementos.
 *
 * Revision 1.3  2022/01/24 09:46:12  luiza.rosa
 * Programa: Correcao da logica do programa para insercao de elementos negativos.
 *
 * Revision 1.2  2022/01/23 19:29:58  luiza.rosa
 * Programa: Insercao de melhores praticas de programacao.
 *
 * Revision 1.1  2022/01/23 15:36:31  luiza.rosa
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
#include <string.h>
#include <errno.h>
#include <float.h>

#include "aula0601.h"

#define SUCESSO																		0

#define NUMERO_ARGUMENTOS_INVALIDO								1
#define ARGUMENTO_INVALIDO												2
#define ARGUMENTO_CONTEM_CARACTERE_INVALIDO				3
#define MATRIZ_MEDIDAS_INVALIDAS		   						4
#define VALOR_MAXIMO_DOUBLE_EXCEDIDO							5

#define PARAMETROS_MEDIDAS_MATRIZ   							2
#define NUMERO_MINIMO_ARGUMENTOS									4
#define EOS																				'\0'

int
main (int argc, char **argv) 
{

	char *verificacao;	

	double elemento;

	unsigned medida,
					 quantidadeTotalElementos,
					 contador,
					 linha,
					 coluna;

	unsigned short numeroLinhasMatrizOriginal,
								 numeroColunasMatrizOriginal;

	double matrizOriginal [QUANTIDADE_MATRIZ_LINHAS][QUANTIDADE_MATRIZ_COLUNAS],									
				 matrizTransposta [QUANTIDADE_MATRIZ_LINHAS][QUANTIDADE_MATRIZ_COLUNAS];

	if (argc < NUMERO_MINIMO_ARGUMENTOS)
	{
		printf ("\nUso: %s <linhas> <colunas> <a11> <a12> ... \n\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
		
	/* Medidas */

	for (contador = 1; contador < (PARAMETROS_MEDIDAS_MATRIZ + 1); contador++)
	{

		if ((argv [contador][0] == '-') || (argv [contador][0] == '0'))
		{
			printf ("\nAs medidas da matriz nao podem ser negativas ou nulas.\n\n");
			exit (ARGUMENTO_INVALIDO);
		}

		medida = strtoul (argv [contador], &verificacao, 10);

		if (*verificacao != EOS)
		{
			printf ("\nArgumento contem caractere invalido.\n");
			printf ("Primeiro caractere invalido: \'%c\'.\n\n", *verificacao);
			exit (ARGUMENTO_CONTEM_CARACTERE_INVALIDO);
		}

		if (contador == 1)
			numeroLinhasMatrizOriginal = medida;
		else
			numeroColunasMatrizOriginal = medida;
	
	}

	quantidadeTotalElementos = (numeroLinhasMatrizOriginal * numeroColunasMatrizOriginal);
	
	if (quantidadeTotalElementos != (argc - (PARAMETROS_MEDIDAS_MATRIZ + 1)))
	{
		printf ("\nQuantidade de elementos incorreta.\n");
		printf ("Sao esperados (%i) elementos de acordo com as medidas da matriz digitada.\n\n",
					  quantidadeTotalElementos);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	/* Elementos */

	for (contador = 0; contador < quantidadeTotalElementos; contador++)
	{
		
		strtod (argv [contador + PARAMETROS_MEDIDAS_MATRIZ + 1], &verificacao);

		if (*verificacao != EOS)
		{
			printf ("\nArgumento contem caractere invalido.\n");
			printf ("Primeiro caractere invalido: \'%c\'.\n\n", *verificacao);
			exit (ARGUMENTO_CONTEM_CARACTERE_INVALIDO);
		}

		if (errno == ERANGE)
		{
			printf ("\nO valor de um ou mais elementos ultrapassam o maximo permitido para double (%f).\n\n",
						  DBL_MAX);
			exit (VALOR_MAXIMO_DOUBLE_EXCEDIDO);
		}

	}

	contador = PARAMETROS_MEDIDAS_MATRIZ + 1;

	for (linha = 0; linha < numeroLinhasMatrizOriginal; linha++)
		for (coluna = 0; coluna < numeroColunasMatrizOriginal; coluna++) 
		{

			elemento = strtod (argv [contador], &verificacao);		

			matrizOriginal [linha][coluna] = elemento;
		
			contador++; 
	
		}
	
	ObterMatrizTransposta (numeroLinhasMatrizOriginal, numeroColunasMatrizOriginal,
											   matrizOriginal, matrizTransposta);

	/* Resultado */

	printf ("\nMatriz Transposta:\n");

	for (linha = 0; linha < numeroColunasMatrizOriginal; linha++)
	{

		printf ("\n| ");

		for (coluna = 0; coluna < numeroLinhasMatrizOriginal; coluna++)
			printf ("%.05f | ", matrizTransposta [linha][coluna]);	

	}	

	printf ("\n\n");

	return SUCESSO;

}

/* $RCSfile: aula0603.c,v $ */
