/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Programa de testes da funcao de
 *            codificar na base64.
 *
 * $Author: luiza.rosa $
 * $Date: 2022/02/16 00:37:22 $
 * $Log: aula0806.c,v $
 * Revision 1.2  2022/02/16 00:37:22  luiza.rosa
 * Programa: Insercao de mensagem de erro ao retorno das funcoes.
 *
 * Revision 1.1  2022/02/15 10:33:35  luiza.rosa
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
#define FINAL_LINHA_INVALIDA											4
#define RESULTADO_INVALIDO												5

#define NUMERO_ARGUMENTOS													4

int
main (int argc, char **argv) 
{

	int contador;
	
	unsigned long elementos;

	unsigned long long quantidadeBytes [1];

	tipoFinalLinha indicadorFinalLinha;

	char *entrada,
			 *verificacao,
			 *resultado;

	byte *conjuntoBytes;

	tipoErros resultadoRetornado;

	if (argc < NUMERO_ARGUMENTOS)
	{
		printf ("\nUso: %s <indicador-final-linha> <quantidade-bytes> <byte-1> <byte-2> ... <byte-N>\n\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	if ((argv [1][0] == '-') || (argv [2][0] == '-'))
	{
		printf ("\nOs valores passados nao podem ser negativos.\n\n");
		exit (ARGUMENTO_NEGATIVO);
	}

	/* Indicador final linha */
	indicadorFinalLinha = argv [1][0] - '0';

	if ((indicadorFinalLinha != habilitado) && (indicadorFinalLinha != desabilitado))
	{
		printf ("\nEscolha de final de linha incorreta.\n");
		printf ("Digite 0 para desabilitado e 1 para habilitado.\n\n");
		exit (FINAL_LINHA_INVALIDA);
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
	conjuntoBytes = malloc (sizeof (byte [quantidadeBytes [0] * 2]));

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
			free (entrada);
			free (resultado);
			free (conjuntoBytes);
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
		printf ("\nNao foi possivel codificar o codigo inserido na base 64.\n");
		printf ("Resultado invalido ao decodificar na base 16.\n\n");
		exit (RESULTADO_INVALIDO);
	}
	
	resultadoRetornado = CodificarBase64 (conjuntoBytes,
																			  quantidadeBytes [0],
									                      indicadorFinalLinha,
                                        resultado);

	if (resultadoRetornado == memoriaInsuficiente)
	{
		free (entrada);
		free (resultado);
		free (conjuntoBytes);
		printf ("\nNao foi possivel decodificar o codigo inserido na base 64, memoria insuficiente.\n\n");
		exit (MEMORIA_INSUFICIENTE);
	}

	printf ("\nResultado: %s\n\n", resultado);

	free (entrada);
	free (conjuntoBytes);
	free (resultado);

	return SUCESSO;	

}

/* $RCSfile: aula0806.c,v $ */
