/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Programa de testes da funcao de
 *            decodificar na base 64.
 *
 * $Author: luiza.rosa $
 * $Date: 2022/02/16 00:43:45 $
 * $Log: aula0807.c,v $
 * Revision 1.2  2022/02/16 00:43:45  luiza.rosa
 * Programa: Insercao de mensagem de erro ao retorno das funcao.
 *
 * Revision 1.1  2022/02/15 17:08:33  luiza.rosa
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

#define NUMERO_ARGUMENTOS													3

int
main (int argc, char **argv) 
{

	unsigned indice = 0,
					 contador;

	unsigned long long quantidadeBytes [1];

	char *entrada,
			 *resultado;		

	byte *conjuntoBytes;

	tipoFinalLinha indicadorFinalLinha;

	tipoErros resultadoRetornado;
	
	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\nUso: %s <alfabeto-0-ou-1> <string-a-ser-decodificada> \n\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	for (contador = 1; contador < argc; contador++)
		if (argv [contador][0] == '-')
		{
			printf ("\nOs valores passados nao podem ser negativos.\n\n");
			exit (ARGUMENTO_NEGATIVO);
		}
	
	/* Final Linha */
	indicadorFinalLinha = argv [1][0] - '0';

	if ((indicadorFinalLinha != habilitado) && (indicadorFinalLinha != desabilitado))
	{
		printf ("\nEscolha de final de linha incorreta.\n");
		printf ("Digite 0 para desabilitado e 1 para habilitado.\n\n");
		exit (FINAL_LINHA_INVALIDA);
	}

	/* Entrada */
	entrada = (char *) malloc (sizeof (char [strlen (argv [1]) + 1]));

	if (entrada == NULL)
	{
		printf ("\nNao foi possivel alocar memoria suficiente para a entrada.\n\n");
		exit (MEMORIA_INSUFICIENTE);
	}

	/* Resultado */
	resultado = (char *) malloc (sizeof (char [strlen (entrada)]));

	if (resultado == NULL)
	{
		free (entrada);
		printf ("\nNao foi possivel alocar memoria suficiente para o resultado.\n\n");
		exit (MEMORIA_INSUFICIENTE);
	}

	/* Conjunto dos bytes */
	conjuntoBytes = (byte *) malloc (sizeof (byte [strlen (entrada)]));

	if (conjuntoBytes == NULL)
	{
		free (entrada);
		free (resultado);
		printf ("\nNao foi possivel alocar memoria suficiente para esta quantidade de bytes.\n\n");
		exit (MEMORIA_INSUFICIENTE);
	}

	entrada = argv [2];

	/* Decodificar */
	resultadoRetornado = DecodificarBase64 (entrada,
										                      indicadorFinalLinha,
										                      conjuntoBytes,
										                      quantidadeBytes);
	
	if (resultadoRetornado == memoriaInsuficiente)
	{
		free (resultado);
		free (conjuntoBytes);
		printf ("\nNao foi possivel decodificar o codigo inserido na base 64, memoria insuficiente.\n\n");
		exit (MEMORIA_INSUFICIENTE);
	}

	CodificarBase16 (conjuntoBytes,
									 quantidadeBytes [0],
									 resultado); 

	/* Resultado */
	printf ("\nResultado: ");

	for (contador = 0; contador < quantidadeBytes [0]; contador++)
	{
		printf ("%c%c ", resultado [indice], resultado [indice + 1]);
		indice += 2;
	}

	printf ("\n\n"); 

	free (resultado);
	free (conjuntoBytes);
	
	return SUCESSO;	

}

/* $RCSfile: aula0807.c,v $ */
