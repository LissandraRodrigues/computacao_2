/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Programa de testes da funcao de
 *            decodificar na base16.
 *
 * $Author: luiza.rosa $
 * $Date: 2022/02/15 23:09:09 $
 * $Log: aula0803.c,v $
 * Revision 1.3  2022/02/15 23:09:09  luiza.rosa
 * Programa: Insercao de tratamento de erro para argumento negativo.
 *
 * Revision 1.2  2022/02/14 21:00:15  luiza.rosa
 * Programa: Insercao de melhores praticas de programacao.
 *
 * Revision 1.1  2022/02/03 23:58:40  luiza.rosa
 * Initial revision
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aula0801.h"

#define SUCESSO																		0

#define NUMERO_ARGUMENTOS_INVALIDO								1
#define MEMORIA_INSUFICIENTE											2
#define RESULTADO_INVALIDO												3
#define ARGUMENTO_NEGATIVO												4

#define NUMERO_ARGUMENTOS													2

int
main (int argc, char **argv) 
{

	unsigned contador;

	unsigned long long quantidadeBytes [1];

	char *codigo;		

	byte *conjuntoBytes;

	tipoErros resultado;

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\nUso: %s <codigo-base-16> \n\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	if (argv [1][0] == '-')
	{
		printf ("\nO argumento nao pode ser negativo.\n\n");
		exit (ARGUMENTO_NEGATIVO);
	}

	/* Codigo */
	codigo = (char *) malloc (sizeof (char [strlen (argv [1]) + 1]));

	if (codigo == NULL)
	{
		printf ("\nNao foi possivel alocar memoria suficiente.\n\n");
		exit (MEMORIA_INSUFICIENTE);
	}

	strcpy (codigo, argv [1]);

	/* Conjunto dos bytes */
	conjuntoBytes = (byte *) malloc (sizeof (byte [strlen (codigo)]));

	if (conjuntoBytes == NULL)
	{
		free (codigo);
		printf ("\nNao foi possivel alocar memoria suficiente para esta quantidade de bytes.\n\n");
		exit (MEMORIA_INSUFICIENTE);
	}

	/* Decodificar */
	resultado = DecodificarBase16 (codigo,
																 conjuntoBytes,
																 quantidadeBytes);
	
	if (resultado == invalido)
	{
		free (codigo);
		free (conjuntoBytes);
		printf ("\nNao foi possivel decodificar o codigo inserido.\n\n");
		exit (RESULTADO_INVALIDO);
	}

	/* Resultado */
	printf ("\nResultado: ");

	for (contador = 0; contador < quantidadeBytes [0]; contador++)
		printf ("%d ", conjuntoBytes [contador]);

	printf ("\n\n"); 

	free (codigo);
	free (conjuntoBytes);
	
	return SUCESSO;	

}

/* $RCSfile: aula0803.c,v $ */
