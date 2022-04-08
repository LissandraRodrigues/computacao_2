/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Programa de testes das funcoes de
 *            converter arquivos formato Dos para
 *					  formato Unix e vice-versa e exibir
 *					  conteudo com opcoes longas e curtas.
 *
 * $Author: luiza.rosa $
 * $Date: 2022/03/07 22:03:54 $
 * $Log: aula0906.c,v $
 * Revision 1.1  2022/03/07 22:03:54  luiza.rosa
 * Initial revision
 *
*/

#define _XOPEN_SOURCE															500

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include "aula0901.h"

#define NUMERO_ARGUMENTOS_INVALIDO								1
#define ERRO_EXIBICAO_CONTEUDO										2
#define ERRO_CONVERSAO														3
#define ENTRADA_INVALIDA													4

#define NUMERO_ARGUMENTOS													3
#define NUMERO_HIFENS															80

#define SUCESSO																		0

int
main (int argc, char **argv) 
{
	
	tipoErros resultado;

	unsigned indice;

	int opcaoCurta,
			temOpcao = 0,
			auxiliar;

	char *opcoesCurtas = "dDhHuUsS";

	struct option opcoesLongas [5] =
	{
		{"dos",  0, NULL, 'd'},
		{"help", 0, NULL, 'h'},
		{"unix", 0, NULL, 'u'},
		{"show", 0, NULL, 's'},
		{NULL,   0, NULL,  0} 
	};

	opterr = 0;

	for (indice = 1; indice < argc; indice++)
		if (argv [indice][0] == '-')
			temOpcao = 1;

	if (argc < 2 || !temOpcao)
	{
		printf ("\nPara se utilizar este programa, eh necessario o uso de opcoes.\n");
		printf ("Maiores informacoes em: %s -h\n\n", argv [0]);
		exit (ENTRADA_INVALIDA);
	}

	printf ("\n");
	
	for (indice = 0; indice < NUMERO_HIFENS; indice++)
		printf ("-");
	
	printf ("\n");

	while ((opcaoCurta = getopt_long (argc, argv, opcoesCurtas, opcoesLongas, &auxiliar)) != -1)
		switch (opcaoCurta)
		{
			case 'd':
			case 'D':

				printf ("\nOpcao de converter de UNIX para DOS selecionada.\n");
				
				if (argc < NUMERO_ARGUMENTOS)
				{
					printf ("Uso: %s <--dos, -D ou -d> <nome-arquivo> <nome-arquivo-convertido-[opcional]>\n", argv [0]);
					exit (NUMERO_ARGUMENTOS_INVALIDO);
				}		
			
				resultado = ConverterArquivoFormatoUnixParaFormatoDos (argv [optind], argv [optind + 1]);
	
				if (resultado != ok)
					exit (ERRO_CONVERSAO);
				else
					printf ("\nArquivo (%s) convertido do formato Unix para Dos com sucesso!\n\n", argv [optind]);

			break;

			case 'u':
			case 'U':

				printf ("\nOpcao de converter de DOS para UNIX selecionada.\n");
			
				if (argc < NUMERO_ARGUMENTOS)
				{
					printf ("Uso: %s <--unix, -U ou -u> <nome-arquivo> <nome-arquivo-convertido-[opcional]>\n", argv [0]);
					exit (NUMERO_ARGUMENTOS_INVALIDO);
				}		
			
				resultado = ConverterArquivoFormatoDosParaFormatoUnix (argv [optind], argv [optind + 1]);
	
				if (resultado != ok)
					exit (ERRO_CONVERSAO);
				else
					printf ("\nArquivo (%s) convertido do formato Dos para Unix com sucesso!\n\n", argv [optind]);
				
			break;
		
			case 'h':
			case 'H':

				printf ("\nOpcao de AJUDA selecionada.\n");

				printf ("\nVeja abaixo instrucoes sobre como utilizar este software.\n");

				printf ("\nOpcao: --dos, -D ou -d\n");
				printf ("Descricao: Converter um arquivo texto do formato Unix para Dos.\n");
				printf ("Uso: %s <--dos, -D ou -d> <nome-arquivo> <nome-arquivo-convertido-[opcional]>\n", argv [0]);

				printf ("\nOpcao: --unix, -U ou -u\n");
				printf ("Descricao: Converter um arquivo texto do formato Dos para Unix.\n");
				printf ("Uso: %s <--unix, -U ou -u> <nome-arquivo> <nome-arquivo-convertido-[opcional]>\n", argv [0]);
				
				printf ("\nOpcao: --show, -S ou -s\n");
				printf ("Descricao: Exibir o conteudo de um arquivo texto.\n");
				printf ("Uso: %s <--show, -S ou -s> <nome-arquivo>\n", argv [0]);
				
				printf ("\nOpcao: --help, -H ou -h\n");
				printf ("Descricao: Obter informacoes sobre como utilizar o software.\n");
				printf ("Uso: %s <--help, -H ou -h>\n\n", argv [0]);

			break;
	
			case 's':
			case 'S':

				printf ("\nOpcao de EXIBIR CONTEUDO selecionada.\n");

				if (argc != NUMERO_ARGUMENTOS)
				{
					printf ("\nUso: %s <nome-arquivo> \n\n", argv [0]);
					exit (NUMERO_ARGUMENTOS_INVALIDO);
				}		

				resultado = ExibirConteudoArquivo (argv [optind]);			

				if (resultado != ok)
					exit (ERRO_EXIBICAO_CONTEUDO);

			break;

			default:
				printf ("\nOpcao invalida foi escolhida.\n\n");	
			break;			

		}

	for (indice = 0; indice < NUMERO_HIFENS; indice++)
		printf ("-");
	
	printf ("\n\n");

	return SUCESSO;

}

/* $RCSfile: aula0906.c,v $ */
