/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Programa de testes da funcao de
 *            Validar RG com entrada byte e 9 argumentos.
 *
 * $Author: luiza.rosa $
 * $Date: 2022/01/17 00:53:34 $
 * $Log: aula0503a.c,v $
 * Revision 1.6  2022/01/17 00:53:34  luiza.rosa
 * Programa: Correcao da descricao.
 *
 * Revision 1.5  2022/01/17 00:43:04  luiza.rosa
 * Programa: Atualizacao da descricao.
 *
 * Revision 1.4  2022/01/16 14:03:14  luiza.rosa
 * Programa: Correcao do tamanho correto do array rg.
 *
 * Revision 1.3  2022/01/16 14:01:52  luiza.rosa
 * Programa: Insercao de melhores praticas de programacao.
 *
 * Revision 1.2  2022/01/14 16:14:48  luiza.rosa
 * Programa: Correcao da logica do programa e nome das macros.
 *
 * Revision 1.1  2022/01/14 01:42:23  luiza.rosa
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
#define NUMERO_ARGUMENTOS													10

int
main (int argc, char **argv) 
{
	
	byte rg [COMPRIMENTO_RG];

	unsigned contador;

	tipoErros resultado;

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\nUso: %s <d1> <d2> <d3> <d4> <d5> <d6> <d7> <d8> <d9>\n\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	
	/* Digitos */
			
	for (contador = 0; contador < COMPRIMENTO_RG; contador++)
	{

		if (strlen (argv [contador + 1]) != 1)
		{
			printf ("\nQuantidade de caracteres %s invalida.\n\n", argv [contador + 1]);
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

/* $RCSfile: aula0503a.c,v $ */
