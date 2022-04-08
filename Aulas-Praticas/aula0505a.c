/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Programa de testes da funcao de
 *            Gerar Digito Verificador de RG
 *            com entrada string e 8 argumentos.
 *
 * $Author: luiza.rosa $
 * $Date: 2022/01/17 00:50:45 $
 * $Log: aula0505a.c,v $
 * Revision 1.3  2022/01/17 00:50:45  luiza.rosa
 * Programa: Atualizacao da descricao.
 *
 * Revision 1.2  2022/01/16 14:15:02  luiza.rosa
 * Programa: Correcao do tamanho da macro do RG e insercao de melhores praticas de programacao.
 *
 * Revision 1.1  2022/01/15 01:31:34  luiza.rosa
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
#define NUMERO_ARGUMENTOS													9

int
main (int argc, char **argv) 
{

	unsigned contador;

	char digito;

	char rg [COMPRIMENTO_RG] = "";

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\nUso: %s <d1> <d2> <d3> <d4> <d5> <d6> <d7> <d8>\n\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	/* Digitos */
	
	for (contador = 1; contador <= (COMPRIMENTO_RG - 1); contador++)
	{

		if (strlen (argv [contador]) != 1) 
		{
			printf ("\nQuantidade de caracteres em (%s) eh invalida.\n\n", argv [contador]);
			exit (QUANTIDADE_CARACTERES_INVALIDA);
		}

		if ((argv [contador][0] < '0') || (argv [contador][0] > '9'))
		{
			printf ("\nO valor inserido (%s) eh invalido.\n\n", argv [contador]);
			exit (CARACTERE_INVALIDO);
		}
		
		strcat (rg, argv [contador]);
	
	}

	/* Resultado */

	GerarDigitosVerificadoresRg (rg, &digito);

	printf ("\nRG: ");

	for (contador = 0; contador < (COMPRIMENTO_RG - 1); contador++)
	{

		if ((contador == 2) || (contador == 5))
			printf (".");
		
		printf ("%i", rg [contador] - '0');	
		
	}
	
	printf ("-%c\n\n", digito);

	return SUCESSO;

}

/* $RCSfile: aula0505a.c,v $ */
