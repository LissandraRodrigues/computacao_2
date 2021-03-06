/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Programa que exibe os tamanhos
 *			      das combinacoes validas entre
 *						modificadores de sinal, de
 *						largura e tipos basicos.
 *
 * $Author: luiza.rosa $
 * $Date: 2021/12/08 13:24:19 $
 * $Log: aula0103.c,v $
 * Revision 1.2  2021/12/08 13:24:19  luiza.rosa
 * Programa: Insercao de melhores praticas de programacao
 *
 * Revision 1.1  2021/12/02 15:56:06  luiza.rosa
 * Initial revision
 *
*/

#include <stdio.h>
#include <string.h>

#define SUCESSO															0

#define NUMERO_HIFENS												100
#define NUMERO_ESPACO_EM_BRANCO						  91

void
ExibirHifens (void);

void 
ExibirHifens (void) 
{

	unsigned int indice;

	printf ("\n");

	for (indice = 0; indice < NUMERO_HIFENS; indice++)
		printf ("-");
	
	printf ("\n\n");

}

void
ExibirTamanho (char *, unsigned int);

void 
ExibirTamanho (char *palavra, unsigned int quantidadeBytes)
{
	
	unsigned int indice;
	unsigned int espacoEmBranco = NUMERO_ESPACO_EM_BRANCO - strlen (palavra);
	
	printf ("%s:", palavra);

	for (indice = espacoEmBranco; indice > 0; indice--)
		printf (" ");

	printf ("%i byte%s\n", quantidadeBytes, quantidadeBytes > 1 ? "s" : "");

}

int
main (int argc, char *argv [])
{

	ExibirHifens ();

	printf ("Tamanhos dos Tipos Basicos combinados com Modificadores de Sinal\n\n");

	ExibirTamanho ("signed char", sizeof (signed char));
	ExibirTamanho ("unsigned char", sizeof (unsigned char));

	ExibirTamanho ("signed int", sizeof (signed int));
	ExibirTamanho ("unsigned int", sizeof (unsigned int));

	ExibirHifens ();

	printf ("Tamanhos dos Tipos Basicos combinados com Modificadores de Largura\n\n");

	ExibirTamanho ("short int", sizeof (short int));
	ExibirTamanho ("long int", sizeof (long int));
	ExibirTamanho ("long long int", sizeof (long long int));

	ExibirTamanho ("long double", sizeof (long double));

	ExibirHifens ();

	printf ("Tamanhos dos Modificadores de Sinal combinados com Modificadores de Largura\n\n");

	ExibirTamanho ("signed short", sizeof (signed short));
	ExibirTamanho ("signed long", sizeof (signed long));
	ExibirTamanho ("signed long long", sizeof (signed long long));

	ExibirTamanho ("unsigned short", sizeof (unsigned short));
	ExibirTamanho ("unsigned long", sizeof (unsigned long));
	ExibirTamanho ("unsigned long long", sizeof (unsigned long long));

	ExibirHifens ();

	printf ("Tamanhos dos Tipos Basicos combinados com Modificadores de Sinal e com Modificadores de Largura\n\n");
	
	ExibirTamanho ("signed short int", sizeof (signed short int));
	ExibirTamanho ("signed long int", sizeof (signed long int));	
	ExibirTamanho ("signed long long int", sizeof (signed long long int));

	ExibirTamanho ("unsigned short int", sizeof (unsigned short int));
	ExibirTamanho ("unsigned long int", sizeof (unsigned long int));
	ExibirTamanho ("unsigned long long int", sizeof (unsigned long long int));

	ExibirHifens ();

	return SUCESSO;

}

/* $RCSfile: aula0103.c,v $ */
