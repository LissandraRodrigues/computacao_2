/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Programa de testes da funcao de
 *            multiplicar matrizes.
 *
 * $Author: luiza.rosa $
 * $Date: 2022/01/25 01:07:33 $
 * $Log: aula0602.c,v $
 * Revision 1.4  2022/01/25 01:07:33  luiza.rosa
 * Programa: Insercao de tratamento de erro para o valor maximo dos elementos.
 *
 * Revision 1.3  2022/01/24 09:41:24  luiza.rosa
 * Programa: Correcao da logica do programa para insercao de elementos negativos.
 *
 * Revision 1.2  2022/01/23 19:30:17  luiza.rosa
 * Programa: Insercao de melhores praticas de programacao.
 *
 * Revision 1.1  2022/01/22 21:41:40  luiza.rosa
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
#include <float.h>
#include <errno.h> 

#include "aula0601.h"

#define SUCESSO																		0

#define NUMERO_ARGUMENTOS_INVALIDO								1
#define ARGUMENTO_INVALIDO												2
#define ARGUMENTO_CONTEM_CARACTERE_INVALIDO				3
#define MATRIZES_MEDIDAS_INVALIDAS								4
#define VALOR_MAXIMO_DOUBLE_EXCEDIDO							5

#define PARAMETROS_MEDIDAS_MATRIZES								4
#define NUMERO_MINIMO_ARGUMENTOS									7
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

	unsigned short numeroLinhasMatriz1,
								 numeroColunasMatriz1,
								 numeroLinhasMatriz2,
								 numeroColunasMatriz2;

	double matriz1 [QUANTIDADE_MATRIZ_LINHAS][QUANTIDADE_MATRIZ_COLUNAS],									
			   matriz2 [QUANTIDADE_MATRIZ_LINHAS][QUANTIDADE_MATRIZ_COLUNAS],
				 matrizProduto [QUANTIDADE_MATRIZ_LINHAS][QUANTIDADE_MATRIZ_COLUNAS];

	if (argc < NUMERO_MINIMO_ARGUMENTOS)
	{
		printf ("\nUso: %s <linhas-a> <colunas-a> <linhas-b> <colunas-b> <a11> <a12> ... <b11> <b12> ...\n\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	/* Medidas das Matrizes */
		
	for (contador = 1; contador < (PARAMETROS_MEDIDAS_MATRIZES + 1); contador++)
	{

		if ((argv [contador][0] == '-') || (argv [contador][0] == '0'))
		{
			printf ("\nAs medidas das matrizes nao podem ser negativas ou nulas.\n\n");
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
			numeroLinhasMatriz1 = medida;
		else if (contador == 2)
			numeroColunasMatriz1 = medida;
		else if (contador == 3)
			numeroLinhasMatriz2 = medida;
		else 
			numeroColunasMatriz2 = medida;
		
	}

	if (numeroColunasMatriz1 != numeroLinhasMatriz2)
	{
		printf ("\nO numero de colunas da matriz 1 deve ser igual ao numero de linhas da matriz 2.\n\n");
		exit (MATRIZES_MEDIDAS_INVALIDAS);
	}

	quantidadeTotalElementos = ((numeroLinhasMatriz1 * numeroColunasMatriz1) +
														  (numeroLinhasMatriz2 * numeroColunasMatriz2));
	
	if (quantidadeTotalElementos != (argc - (PARAMETROS_MEDIDAS_MATRIZES + 1)))
	{
		printf ("\nQuantidade de elementos incorreta.\n");
		printf ("Sao esperados (%i) elementos de acordo com as medidas das matrizes digitadas.\n\n",
					  quantidadeTotalElementos);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	/* Elementos */

	for (contador = 0; contador < quantidadeTotalElementos; contador++)
	{

		strtod (argv [contador + PARAMETROS_MEDIDAS_MATRIZES + 1], &verificacao);

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

	contador = PARAMETROS_MEDIDAS_MATRIZES + 1;

	for (linha = 0; linha < numeroLinhasMatriz1; linha++)
		for (coluna = 0; coluna < numeroColunasMatriz1; coluna++) 
		{

			elemento = strtod (argv [contador], &verificacao);		
	
			matriz1 [linha][coluna] = elemento;
		
			contador++; 
	
		}
	
	contador = PARAMETROS_MEDIDAS_MATRIZES + 1 + (numeroLinhasMatriz1 * numeroColunasMatriz1); 

	for (linha = 0; linha < numeroLinhasMatriz2; linha++)
		for (coluna = 0; coluna < numeroColunasMatriz2; coluna++) 
		{
	
			elemento = strtod (argv [contador], &verificacao);		

		  matriz2 [linha][coluna] = elemento;
		
			contador++; 
	
		}

	MultiplicarMatrizes (numeroLinhasMatriz1, numeroColunasMatriz1,
											 numeroLinhasMatriz2, numeroColunasMatriz2,
											 matriz1, matriz2, matrizProduto);

	/* Resultado */

	printf ("\nResultado da multiplicacao das matrizes:\n");

	for (linha = 0; linha < numeroLinhasMatriz1; linha++)
	{

		printf ("\n| ");

		for (coluna = 0; coluna < numeroColunasMatriz2; coluna++)
			printf ("%.05f | ", matrizProduto [linha][coluna]);	

	}	

	printf ("\n\n");

	return SUCESSO;

}

/* $RCSfile: aula0602.c,v $ */
