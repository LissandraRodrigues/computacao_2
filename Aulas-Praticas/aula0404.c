/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Programa de testes do programa de Calcular Serie Harmonica Alternada.
 *
 * $Author: luiza.rosa $
 * $Date: 2022/01/14 01:35:03 $
 * $Log: aula0404.c,v $
 * Revision 1.4  2022/01/14 01:35:03  luiza.rosa
 * Programa: Correcao de um erro, a variavel termo não estava sendo inicializada.
 *
 * Revision 1.3  2022/01/07 13:56:46  luiza.rosa
 * Programa: Refatoracao do codigo e insercao de melhores praticas de programacao.
 *
 * Revision 1.2  2022/01/06 19:59:46  luiza.rosa
 * Programa: Insercao e correcao de tratamento de erros.
 *
 * Revision 1.1  2022/01/06 19:07:50  luiza.rosa
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
#include <float.h>

#include "aula0401.h"

#define SUCESSO																		0

#define NUMERO_ARGUMENTOS_INVALIDO								1
#define ARGUMENTO_INVALIDO												2
#define ARGUMENTO_CONTEM_CARACTERE_INVALIDO				3
#define VALOR_FORA_DO_INTERVALO										4
 
#define NUMERO_ARGUMENTOS													2
#define EOS																				'\0'

int
main (int argc, char *argv []) 
{

	char *verificacao;
					
	unsigned short int termo = 0;

	float percentual,
				serieHarmonica1,
			  serieHarmonica2 = 0,
			  auxiliar = 0;
	
	/* Tratamento de Erros */
	
	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\nUso: %s <unsigned-short-int>.\n\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	percentual = strtof (argv [1], &verificacao);

	if (*verificacao != EOS)
	{
		printf ("\nO argumento contem caractere invalido.\n");
		printf ("Primeiro caractere invalido: \'%c\'.\n\n", *verificacao);
		exit (ARGUMENTO_CONTEM_CARACTERE_INVALIDO);
	}

	if ((percentual < 0) || (percentual > 1))  
	{
		printf ("\nEste programa só aceita valores entre 0 e 1.\n\n");
		exit (VALOR_FORA_DO_INTERVALO);
	}

	/* Calcular Serie Harmonica Alternada */ 

	printf ("\nSerie Harmonica Alternada\n\n");
	
	while (auxiliar > (percentual * serieHarmonica2) || serieHarmonica2 == 0)
	{
	
		serieHarmonica2 = serieHarmonica1;
		serieHarmonica1 = CalcularSerieHarmonicaAlternada (termo);	

		printf ("S(%hu) = %.10f\n\n", termo, serieHarmonica1);
			
		termo++;

		if ((serieHarmonica1 - serieHarmonica2) > 0)
			auxiliar = serieHarmonica1 - serieHarmonica2;
		else
			auxiliar = serieHarmonica2 - serieHarmonica1;
	}

	return SUCESSO;

}

/* $RCSfile: aula0404.c,v $ */
