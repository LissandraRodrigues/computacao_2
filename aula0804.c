/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Programa de testes da funcao de
 *            codificar na base32.
 *
 * $Author: luiza.rosa $
 * $Date: 2022/02/15 23:37:33 $
 * $Log: aula0804.c,v $
 * Revision 1.6  2022/02/15 23:37:33  luiza.rosa
 * Programa: Correcao de variavel.
 *
 * Revision 1.5  2022/02/15 23:27:52  luiza.rosa
 * Programa: Insercao de tratamento de erro para argumentos negativos e mensagens de erro de retorno das funcoes.
 *
 * Revision 1.4  2022/02/15 10:35:42  luiza.rosa
 * Programa: Correcao da mensagem de log.
 *
 * Revision 1.3  2022/02/15 10:33:58  luiza.rosa
 * Programa: Insercao de melhores praticas de programacao.
 *
 * Revision 1.2  2022/02/14 21:00:36  luiza.rosa
 * Programa: Insercao de melhores praticas de programacao.
 *
 * Revision 1.1  2022/02/14 16:11:08  luiza.rosa
 * Initial revision
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aula0801.h"

#define SUCESSO																		0

#define NUMERO_ARGUMENTOS_INVALIDO								1
#define ARGUMENTO_NEGATIVO										    2
#define MEMORIA_INSUFICIENTE											3
#define ALFABETO_INVALIDO													4
#define RESULTADO_INVALIDO												5

#define NUMERO_ARGUMENTOS													4

int
main (int argc, char **argv) 
{

	unsigned contador;

	unsigned long elementos;
	
	unsigned long long quantidadeBytes [1];

	char *entrada,
			 *verificacao,
			 *resultado;

	byte *conjuntoBytes;

	tipoAlfabetoBase32 alfabetoEscolhido;

	tipoErros resultadoRetornado;

	if (argc < NUMERO_ARGUMENTOS)
	{
		printf ("\nUso: %s <escolha-alfabeto-0-ou-1> <quantidade-bytes> <byte-1> <byte-2> ... <byte-N>\n\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	if ((argv [1][0] == '-') || (argv [2][0] == '-')) 
	{
		printf ("\nOs argumentos nao podem ser negativos.\n\n");
		exit (ARGUMENTO_NEGATIVO);
	}

	/* Alfabeto */
	alfabetoEscolhido = argv [1][0] - '0';

	if ((alfabetoEscolhido != basico) && (alfabetoEscolhido != estendido))
	{
		printf ("\nEscolha de alfabeto invalida.\n");
		printf ("Digite 0 para alfabeto basico e 1 para alfabeto estendido.\n\n");
		exit (ALFABETO_INVALIDO);
	}

	/* Quantidade de elementos */
	elementos = strtoul (argv [2], &verificacao, 10);
	
	if ((argc - 3) != elementos)
	{
		printf ("\nQuantidade de argumentos incorreta.\n");
		printf ("Sao esperados (%lu) elementos de acordo com o numero de bytes digitado.\n\n", elementos);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	quantidadeBytes [0] = strtoul (argv [2], &verificacao, 10);

	/* Elementos */
	conjuntoBytes = (byte *) malloc (sizeof (byte [quantidadeBytes [0] * 2]));

	if (conjuntoBytes == NULL)
	{
		printf ("\nNao foi possivel alocar memoria suficiente para esta quantidade de bytes.\n\n");
		exit (MEMORIA_INSUFICIENTE);
	}

	/* Entrada */
	entrada = malloc (sizeof (char [(quantidadeBytes [0] * 2) + 1]));

	if (entrada == NULL)
	{
		free (conjuntoBytes);
		printf ("\nNao foi possivel alocar memoria suficiente para a entrada.\n\n");
		exit (MEMORIA_INSUFICIENTE);
	}

	/* Resultado */
	resultado = malloc (sizeof (char [(quantidadeBytes [0] * 2) + 1]));

	if (resultado == NULL)
	{
		free (entrada);
		free (conjuntoBytes);
		printf ("\nNao foi possivel alocar memoria suficiente para o resultado.\n\n");
		exit (MEMORIA_INSUFICIENTE);
	}

	for (contador = 3; contador < argc; contador++)
	{	

		if (argv [contador][0] == '-')
		{
			printf ("\nOs argumentos nao podem ser negativos.\n\n");
			exit (ARGUMENTO_NEGATIVO);
		}

		strcat (entrada, argv [contador]);
	
	}

	resultadoRetornado = DecodificarBase16 (entrada,
																          conjuntoBytes,
																          quantidadeBytes);
	
	if (resultadoRetornado == invalido)
	{
		free (entrada);
		free (resultado);
		free (conjuntoBytes);
		printf ("\nNao foi possivel codificar o codigo inserido na base 32.\n");
		printf ("Resultado invalido ao decodificar na base 16.\n\n");
		exit (RESULTADO_INVALIDO);
	}

	resultadoRetornado = CodificarBase32 (conjuntoBytes,
																				quantidadeBytes [0],
																				alfabetoEscolhido,
																				resultado);

	if (resultadoRetornado == memoriaInsuficiente)
	{
		free (entrada);
		free (resultado);
		free (conjuntoBytes);
		printf ("\nNao foi possivel codificar o codigo inserido na base 32, memoria insuficiente.\n\n");
		exit (MEMORIA_INSUFICIENTE);
	}

	printf ("\nResultado: %s\n\n", resultado);

	free (entrada);
	free (conjuntoBytes);
	free (resultado);

	return SUCESSO;	

}

/* $RCSfile: aula0804.c,v $ */
