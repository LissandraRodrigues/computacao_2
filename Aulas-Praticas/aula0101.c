/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Programa que recebe um nome que
 *			      pode conter espaços e com no
 *						maximo 50 caracteres.
 *
 * $Author: luiza.rosa $
 * $Date: 2021/12/08 13:23:38 $
 * $Log: aula0101.c,v $
 * Revision 1.3  2021/12/08 13:23:38  luiza.rosa
 * Programa: Insercao de melhores praticas de programacao
 *
 * Revision 1.2  2021/12/01 22:21:07  luiza.rosa
 * Correçcao da descricao do programa
 *
 * Revision 1.1  2021/12/01 21:42:35  luiza.rosa
 * Initial revision
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO															0

#define NUMERO_ARGUMENTOS_INVALIDO					1
#define NUMERO_CARACTERES_INVALIDO					2

#define NUMERO_MINIMO_ARGUMENTOS						2
#define NUMERO_MAXIMO_CARACTERES						50

int
main (int argc, char *argv [])
{

	if (argc != NUMERO_MINIMO_ARGUMENTOS)
	{
		printf ("\nUso: %s <nome>\n\n", argv [0]);

		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	char *nome = argv [1];
	
	unsigned int indice;
	unsigned int indice2;

	unsigned int quantidadeCaracteresNome = strlen (nome);
	
	unsigned int quantidadeEspacosEmBranco = (80 - quantidadeCaracteresNome) / 2;

	if (quantidadeCaracteresNome > NUMERO_MAXIMO_CARACTERES) 
	{
		printf ("\nO numero maximo de caracteres foi atingido.");
		printf ("\nPermitido: %i\n\n", NUMERO_MAXIMO_CARACTERES);
		
		exit (NUMERO_CARACTERES_INVALIDO);
	}

	printf ("\n");

	for (indice = 0; indice <= 7; indice++)
		for (indice2 = 0; indice2 < 10; indice2++)
			printf ("%u", indice);
	
	printf ("\n");
	
	for (indice = 0; indice <= 7; indice++) 
		for (indice2 = 0; indice2 < 10; indice2++)	
			printf ("%u", indice2);

	printf ("\n\n");

	for (indice = 0; indice < quantidadeEspacosEmBranco; indice++) 
		printf (" ");
		
	printf ("\"%s\"\n\n", nome); 		

	for (indice = 0; indice < 80; indice++) 
		printf ("-");
	
	printf ("\n\n");

	return SUCESSO;

}

/* $RCSfile: aula0101.c,v $ */
