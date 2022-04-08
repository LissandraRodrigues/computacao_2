/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Programa de testes das funcoes de
 *            mostrar monitor e gerar distribuicao
 *				    inicial.
 *
 * $Author: luiza.rosa $
 * $Date: 2022/02/01 00:47:40 $
 * $Log: aula0702.c,v $
 * Revision 1.4  2022/02/01 00:47:40  luiza.rosa
 * Programa: Correcao do tratamento de erros.
 *
 * Revision 1.3  2022/01/31 22:24:59  luiza.rosa
 * Programa: Correcao da verificacao da quantidade de argumentos.
 *
 * Revision 1.2  2022/01/30 19:25:42  luiza.rosa
 * Programa: Correcao de defines.
 *
 * Revision 1.1  2022/01/29 22:51:05  luiza.rosa
 * Initial revision
 *
*/

#ifdef __linux__
#define _XOPEN_SOURCE 500
#endif

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <errno.h> 
#include <limits.h>

#include "aula0701.h"

#define SUCESSO																		0

#define NUMERO_ARGUMENTOS_INVALIDO								1
#define ARGUMENTO_INVALIDO												2
#define ARGUMENTO_CONTEM_CARACTERE_INVALIDO				3
#define PERCENTUAL_TOTAL_INVALIDO									4
#define VALOR_MAXIMO_DOUBLE_EXCEDIDO							5
#define VALOR_MAXIMO_INT_EXCEDIDO									6
#define NUMERO_MAXIMO_LINHAS_ULTRAPASSADO					7
#define NUMERO_MAXIMO_COLUNAS_ULTRAPASSADO				8
#define ERRO_EXIBICAO															9

#define NUMERO_ARGUMENTOS													6
#define EOS																				'\0'

int
main (int argc, char **argv) 
{

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\nUso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\n\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	char *verificacao;	

	unsigned tempoCongelamento,
					 quantidadeLinhas,
					 quantidadeColunas,
					 contador,
					 argumentoInt;

	float percentualPixelsApagados,
				percentualPixelsDefeituosos,
				argumentoFloat;

	tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS];

	tipoErros resultado;

	for (contador = 1; contador < NUMERO_ARGUMENTOS; contador++)
	{
	
		if (argv [contador][0] == '-')
		{
			printf ("\nOs valores passados nao podem ser negativos.\n\n");
			exit (ARGUMENTO_INVALIDO);
		}

		if (contador < 4)
		{

			argumentoInt = strtoul (argv [contador], &verificacao, 10);
	
			if (errno == ERANGE)
			{	
				printf ("\nO valor (%i) fornecido ultrapassa o maximo permitido para int (%i).\n\n", argumentoInt,
								INT_MAX);
				exit (VALOR_MAXIMO_INT_EXCEDIDO);
			}
			
			if (contador == 1)
				tempoCongelamento = argumentoInt;
			else if (contador == 2)
				quantidadeLinhas = argumentoInt;
			else if (contador == 3)
				quantidadeColunas = argumentoInt;

		}
		else 
		{
			
			argumentoFloat = strtod (argv [contador], &verificacao);

			if (errno == ERANGE)
			{
				printf ("\nO valor (%f) fornecido ultrapassa o maximo permitido para double (%f).\n\n", argumentoFloat,
								DBL_MAX);
				exit (VALOR_MAXIMO_DOUBLE_EXCEDIDO);
			}

			if (contador == 4)
				percentualPixelsApagados = argumentoFloat;
			else
				percentualPixelsDefeituosos = argumentoFloat;
					
		}

		if (*verificacao != EOS)
		{
			printf ("\nArgumento contem caractere invalido.\n");
			printf ("Primeiro caractere invalido: \'%c\'.\n\n", *verificacao);
			exit (ARGUMENTO_CONTEM_CARACTERE_INVALIDO);
		}
	
	}

	if (quantidadeLinhas > NUMERO_MAXIMO_LINHAS)
	{
		printf ("\nO numero maximo (250) de linhas permtido foi ultrapassado.\n\n");
		exit (NUMERO_MAXIMO_LINHAS_ULTRAPASSADO);
	}

	if (quantidadeColunas > NUMERO_MAXIMO_COLUNAS)
	{
		printf ("\nO numero maximo (800) de colunas permtido foi ultrapassado.\n\n");
		exit (NUMERO_MAXIMO_COLUNAS_ULTRAPASSADO);
	}

	if ((percentualPixelsApagados + percentualPixelsDefeituosos) > 100)
	{
		printf ("\nA soma dos percentuais de pixels apagados e defeituosos deve ser menor ou igual a 100.\n\n");
		exit (PERCENTUAL_TOTAL_INVALIDO);
	}

	GerarDistribuicaoInicial (monitor,
													  quantidadeLinhas,
													  quantidadeColunas,
												    percentualPixelsApagados,
													  percentualPixelsDefeituosos);

	resultado = MostrarMonitor (tempoCongelamento,
															monitor,
														  quantidadeLinhas,
													    quantidadeColunas);
	
	if (resultado == linhaInvalida)
	{
		system ("clear");
		printf ("\nOcorreu um erro na exibicao do monitor.\n\n");
		exit (ERRO_EXIBICAO);
	}
	
	return SUCESSO;

}

/* $RCSfile: aula0702.c,v $ */
