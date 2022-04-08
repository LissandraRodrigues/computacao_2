/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Programa de testes da funcao de
 *            calcular menor complementar.
 *
 * $Author: luiza.rosa $
 * $Date: 2022/01/25 01:12:25 $
 * $Log: aula0605.c,v $
 * Revision 1.4  2022/01/25 01:12:25  luiza.rosa
 * Programa: Insercao de tratamento de erro para o valor maximo dos elementos.
 *
 * Revision 1.3  2022/01/24 18:49:27  luiza.rosa
 * Programa: Insercao de melhores praticas de programacao.
 *
 * Revision 1.2  2022/01/24 15:55:17  luiza.rosa
 * Programa: Correcao da logica do programa para insercao de elementos negativos.
 *
 * Revision 1.1  2022/01/24 00:01:34  luiza.rosa
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

#define NUMERO_MINIMO_ARGUMENTOS									5
#define EOS																				'\0'

int
main (int argc, char **argv) 
{

	char *verificacao;	

	double elemento;

	unsigned ordemMatriz,
					 medida,
					 quantidadeTotalElementos,
					 contador,
					 linha,
					 coluna,
					 linhaElemento,
					 colunaElemento;

	double matriz [QUANTIDADE_MATRIZ_LINHAS][QUANTIDADE_MATRIZ_COLUNAS],
				 menorComplementar [1];

	if (argc < NUMERO_MINIMO_ARGUMENTOS)
	{
		printf ("\nUso: %s <ordem-da-matriz> <posicao-linha> <posicao-coluna> <a11> <a12> ... \n\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	/* Ordem da matriz */

	if ((argv [1][0] == '-') || (argv [1][0] == '0'))
	{
		printf ("\nA ordem da matriz nao pode ser negativa ou nula.\n\n");
		exit (ARGUMENTO_INVALIDO);
	}

	medida = strtoul (argv [1], &verificacao, 10);

	if (*verificacao != EOS)
	{
		printf ("\nArgumento contem caractere invalido.\n");
		printf ("Primeiro caractere invalido: \'%c\'.\n\n", *verificacao);
		exit (ARGUMENTO_CONTEM_CARACTERE_INVALIDO);
	}

	ordemMatriz = medida;

	quantidadeTotalElementos = (ordemMatriz * ordemMatriz);
	
	if (quantidadeTotalElementos != (argc - 4))
	{
		printf ("\nQuantidade de elementos incorreta.\n");
		printf ("Sao esperados (%i) elementos de acordo com as medidas da matriz digitada.\n",
					  quantidadeTotalElementos);
		printf ("\nE tambem sao esperados 2 valores correspondentes a localizacao do elemento na matriz.\n\n");	
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

  /* Localizacao do elemento */
		
	for (contador = 0; contador < 2; contador++)
	{
				
		if ((argv [contador +  2][0] == '-') || (argv [contador + 2][0] == '0')) 
		{
			printf ("\nOs valores da localizacao do elemento nao podem ser negativos ou nulos.\n\n");
			exit (ARGUMENTO_INVALIDO);
		}
	
		elemento = strtod (argv [contador + 2], &verificacao);

		if (*verificacao != EOS)
		{
			printf ("\nArgumento contem caractere invalido.\n");
			printf ("Primeiro caractere invalido: \'%c\'.\n\n", *verificacao);
			exit (ARGUMENTO_CONTEM_CARACTERE_INVALIDO);
		}

		if (!contador)
			linhaElemento = elemento;
		else
			colunaElemento = elemento;

	}

	/* Elementos */

	for (contador = 0; contador < quantidadeTotalElementos; contador++)
	{
		
		strtod (argv [contador + 4], &verificacao);

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

	contador = 4;

	for (linha = 0; linha < ordemMatriz; linha++)
		for (coluna = 0; coluna < ordemMatriz; coluna++) 
		{

			elemento = strtod (argv [contador], &verificacao);		

			matriz [linha][coluna] = elemento;
		
			contador++; 
	
		}

	/* Resultado */
	
	printf ("\nMatriz:\n");

	for (linha = 0; linha < ordemMatriz; linha++)
	{

		printf ("\n| ");

		for (coluna = 0; coluna < ordemMatriz; coluna++)
			printf ("%.05f | ", matriz [linha][coluna]);	

	}

	printf ("\n\nElemento [%d][%d]: %.05f\n", linhaElemento, colunaElemento, matriz [linhaElemento - 1][colunaElemento - 1]);
	
	CalcularMenorComplementar (ordemMatriz, linhaElemento, colunaElemento, matriz, menorComplementar);

	printf ("\nMenor complementar = %.05f\n\n", menorComplementar [0]);

	return SUCESSO;

}

/* $RCSfile: aula0605.c,v $ */
