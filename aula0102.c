/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Programa que exibe os tamanhos
 *			      dos 5 tipos basicos, dos 2 
 *						modificadores de sinal e dos 3
 *						modificadores de largura.
 *
 * $Author: luiza.rosa $
 * $Date: 2021/12/08 13:24:00 $
 * $Log: aula0102.c,v $
 * Revision 1.2  2021/12/08 13:24:00  luiza.rosa
 * Programa: Insercao de melhores praticas de programacao
 *
 * Revision 1.1  2021/12/02 15:27:56  luiza.rosa
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

	printf ("Tamanhos dos Tipos Basicos\n\n");

	ExibirTamanho ("void", sizeof (void));
	
	ExibirTamanho ("char", sizeof (char));

	ExibirTamanho ("int", sizeof (int));

	ExibirTamanho ("float", sizeof (float));

	ExibirTamanho ("double", sizeof (double));

	ExibirHifens ();

	printf ("Tamanhos dos Modificadores de Sinal\n\n");

	ExibirTamanho ("signed", sizeof (signed));

	ExibirTamanho ("unsigned", sizeof (unsigned));

	ExibirHifens ();

	printf ("Tamanhos dos Modificadores de Largura\n\n");
	
	ExibirTamanho ("short", sizeof (short));

	ExibirTamanho ("long", sizeof (long));	

	ExibirTamanho ("long long", sizeof (long long));

	ExibirHifens ();

	return SUCESSO;

}

/* $RCSfile: aula0102.c,v $ */
