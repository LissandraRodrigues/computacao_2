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
 *            com entrada byte e 8 argumentos.
 *
 * $Author: luiza.rosa $
 * $Date: 2022/01/17 00:51:27 $
 * $Log: aula0502a.c,v $
 * Revision 1.8  2022/01/17 00:51:27  luiza.rosa
 * Programa: Correcao da descricao.
 *
 * Revision 1.7  2022/01/17 00:38:42  luiza.rosa
 * Programa: Atualizacao da descricao.
 *
 * Revision 1.6  2022/01/16 14:18:18  luiza.rosa
 * Programa: Correcao da mensagem de numero invalido de argumentos.
 *
 * Revision 1.5  2022/01/15 01:36:35  luiza.rosa
 * Programa: Insercao de melhores praticas de programacao.
 *
 * Revision 1.4  2022/01/14 16:15:33  luiza.rosa
 * Programa: Insercao de melhores praticas de programacao e correcao do nome das macros.
 *
 * Revision 1.3  2022/01/14 01:43:21  luiza.rosa
 * Programa: Insercao de melhores praticas de programacao.
 *
 * Revision 1.2  2022/01/13 20:49:09  luiza.rosa
 * Programa: Insercao de melhores praticas de programacao.
 *
 * Revision 1.1  2022/01/13 17:58:28  luiza.rosa
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
#define NUMERO_ARGUMENTOS													9

int
main (int argc, char **argv) 
{
	
	byte rg [COMPRIMENTO_RG];
	unsigned contador;

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\nUso: %s <d1> <d2> <d3> <d4> <d5> <d6> <d7> <d8>\n\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	/* Digitos */

	for (contador = 0; contador < (COMPRIMENTO_RG - 1); contador++)
	{

		if (strlen (argv [contador + 1]) != 1)
		{
			printf ("\nQuantidade de caracteres em (%s) eh invalida.\n\n", argv [contador + 1]);
			exit (QUANTIDADE_CARACTERES_INVALIDA);
		}	

		if ((argv [contador + 1][0] < '0') || (argv [contador + 1][0] > '9'))
		{
			printf ("\nO valor inserido (%s) eh invalido.\n\n", argv [contador + 1]);
			exit (CARACTERE_INVALIDO);
		}
		
		rg [contador] = (argv [contador + 1][0] - '0');	

	}
	
	/* Resultado */ 

	GerarDigitosVerificadoresRg (rg);

	printf ("\nRG: ");

	for (contador = 0; contador < (COMPRIMENTO_RG - 1); contador++)
	{

		if ((contador == 2) || (contador == 5))
			printf (".");
		
		printf ("%hhu", rg [contador]);

	}
	
	printf ("-"); 
			
	if (rg [8] == 1)
		printf ("X\n\n");
	else if (rg [8] == 11)
		printf ("0\n\n");
	else
		printf ("%hhu\n\n", rg [8]);
	
	return SUCESSO;

}

/* $RCSfile: aula0502a.c,v $ */
