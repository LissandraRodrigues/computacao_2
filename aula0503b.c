/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Programa de testes da funcao de
 *            Validar RG com entrada byte e 1 argumento.
 *
 * $Author: luiza.rosa $
 * $Date: 2022/01/17 00:52:50 $
 * $Log: aula0503b.c,v $
 * Revision 1.5  2022/01/17 00:52:50  luiza.rosa
 * Programa: Correcao da descricao.
 *
 * Revision 1.4  2022/01/17 00:44:14  luiza.rosa
 * Programa: Atualizacao da descricao.
 *
 * Revision 1.3  2022/01/16 23:55:55  luiza.rosa
 * Programa: Insercao de melhores praticas de programacao.
 *
 * Revision 1.2  2022/01/16 14:58:52  luiza.rosa
 * Programa: Insercao de melhores praticas de programacao.
 *
 * Revision 1.1  2022/01/14 16:16:52  luiza.rosa
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

#include "aula0501.h"

#define SUCESSO																		0

#define NUMERO_ARGUMENTOS_INVALIDO								1
#define QUANTIDADE_CARACTERES_INVALIDA						2
#define CARACTERE_INVALIDO												3

#define COMPRIMENTO_RG														9
#define NUMERO_ARGUMENTOS													2

int
main (int argc, char **argv) 
{
	
	byte rg [COMPRIMENTO_RG];
	unsigned contador, indice = 0;

	tipoErros resultado;

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\nUso: %s <d1><d2>.<d3><d4><d5>.<d6><d7><d8>-<d9>\n\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	/* Digitos */
		
	if (strlen (argv [1]) != (COMPRIMENTO_RG + 3))
	{
		printf ("\nQuantidade de caracteres invalida. Preencha da seguinte forma: 00.000.000-0\n\n");
		exit (QUANTIDADE_CARACTERES_INVALIDA);
	}	

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
			rg [indice] = (argv [1][contador] - '0');	
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
		
		printf ("%hhu", rg [contador]);

	}
	
	printf ("-"); 
			
	if (rg [8] == 1)
		printf ("X");
	else if (rg [8] == 11)
		printf ("0");
	else
		printf ("%hhu", rg [8]);

	if (resultado == 1)
		printf (" - valido\n\n");
	else
		printf (" - invalido\n\n");

	return SUCESSO;

}

/* $RCSfile: aula0503b.c,v $ */
