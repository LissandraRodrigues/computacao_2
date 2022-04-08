/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Programa de testes da funcao de Validar 
 *						RG com string e 1 argumento.
 *
 * $Author: luiza.rosa $
 * $Date: 2022/01/17 00:58:04 $
 * $Log: aula0506b.c,v $
 * Revision 1.2  2022/01/17 00:58:04  luiza.rosa
 * Programa: Atualizacao da descricao.
 *
 * Revision 1.1  2022/01/16 23:59:39  luiza.rosa
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

#include "aula0504.h"

#define SUCESSO																		0

#define NUMERO_ARGUMENTOS_INVALIDO								1
#define QUANTIDADE_CARACTERES_INVALIDA						2
#define CARACTERE_INVALIDO												3

#define COMPRIMENTO_RG														9
#define NUMERO_ARGUMENTOS													2

int
main (int argc, char **argv) 
{
	
	char rg [COMPRIMENTO_RG] = "";

	unsigned contador, indice = 0;

	tipoErros resultado;

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\nUso: %s <d1><d2>.<d3><d4><d5>.<d6><d7><d8>-<d9>\n\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	
	if (strlen (argv [1]) != (COMPRIMENTO_RG + 3))
	{
		printf ("\nQuantidade de caracteres invalida. Preencha da seguinte forma: 00.000.000-0\n\n");
		exit (QUANTIDADE_CARACTERES_INVALIDA);
	}	
	
	/* Digitos */
			
	for (contador = 0; contador < (COMPRIMENTO_RG + 3); contador++)
	{

		if (((argv [1][contador] < '0')  ||
				 (argv [1][contador] > '9')) &&
				 (argv [1][contador] != '.') &&
			   (argv [1][contador] != '-'))			   
		{
			printf ("\nO valor inserido (%c) eh invalido.\n\n", argv [1][contador]);
			exit (CARACTERE_INVALIDO);
		}
		
		if ((argv [1][contador] != '.') && (argv [1][contador] != '-'))
		{
			rg [indice] = argv [1][contador];
			indice++;
		} 

	}

	/* Resultado */ 

	resultado = ValidarRg (rg);
	
	printf ("\nRG: ");

	for (contador = 0; contador < (COMPRIMENTO_RG - 1); contador++)
	{

		if ((contador == 2) || (contador == 5))
			printf (".");
		
		printf ("%c", rg [contador]);

	}
	
	printf ("-"); 
			
	if (rg [8] == 1)
		printf ("X");
	else if (rg [8] == 11)
		printf ("0");
	else
		printf ("%c", rg [8]);

	if (resultado == 1)
		printf (" - valido\n\n");
	else
		printf (" - invalido\n\n");

	return SUCESSO;

}

/* $RCSfile: aula0506b.c,v $ */
