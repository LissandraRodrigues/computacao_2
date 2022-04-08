/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Programa de testes da funcao de
 *            converter arquivo formato Dos para
 *					  formato Unix.
 *
 * $Author: luiza.rosa $
 * $Date: 2022/03/07 13:42:49 $
 * $Log: aula0904.c,v $
 * Revision 1.2  2022/03/07 13:42:49  luiza.rosa
 * Programa: Correcao de macro de erro.
 *
 * Revision 1.1  2022/03/02 20:42:14  luiza.rosa
 * Initial revision
 *
*/

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#include <stdio.h>
#include <stdlib.h>

#include "aula0901.h"

#define SUCESSO																		0

#define NUMERO_ARGUMENTOS_INVALIDO								1
#define ERRO_CONVERSAO														2

#define NUMERO_ARGUMENTOS													2

int
main (int argc, char **argv) 
{
	
	tipoErros resultado;

	if (argc < NUMERO_ARGUMENTOS)
	{
		printf ("\nUso: %s <nome-arquivo> <nome-arquivo-convertido-[opcional]> \n\n", argv [0]);	
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	resultado = ConverterArquivoFormatoDosParaFormatoUnix (argv [1], argv [2]);

	if (resultado != ok)
		exit (ERRO_CONVERSAO);
	else
		printf ("\nArquivo (%s) convertido do formato Dos para Unix com sucesso!\n\n", argv [1]);

	return SUCESSO;

}

/* $RCSfile: aula0904.c,v $ */
