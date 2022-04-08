/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Programa de testes da funcao de
 *            codificar na base16.
 *
 * $Author: luiza.rosa $
 * $Date: 2022/02/15 23:01:06 $
 * $Log: aula0802.c,v $
 * Revision 1.5  2022/02/15 23:01:06  luiza.rosa
 * Programa: Insercao de tratamento de erro para argumento negativo e melhores praticas de programacao.
 *
 * Revision 1.4  2022/02/14 20:59:38  luiza.rosa
 * Programa: Insercao de melhores praticas de programacao.
 *
 * Revision 1.3  2022/02/14 15:44:05  luiza.rosa
 * Programa: Correcao de uma mensagem de erro.
 *
 * Revision 1.2  2022/02/03 15:22:07  luiza.rosa
 * Programa: Retirada de printfs incorretos.
 *
 * Revision 1.1  2022/02/03 02:02:16  luiza.rosa
 * Initial revision
 *
*/

#include <stdio.h>
#include <stdlib.h>

#include "aula0801.h"

#define SUCESSO																		0

#define NUMERO_ARGUMENTOS_INVALIDO								1
#define ARGUMENTO_INVALIDO												2
#define ARGUMENTO_CONTEM_CARACTERE_INVALIDO				3
#define VALOR_MAXIMO_ULTRAPASSADO									4
#define MEMORIA_INSUFICIENTE											5
#define ARGUMENTO_NEGATIVO												6

#define NUMERO_ARGUMENTOS													3

int
main (int argc, char **argv) 
{

	unsigned contador;

	unsigned long argumento;
	
	unsigned long long quantidadeBytes;

	char *verificacao,
			 *resultado;

	byte *conjuntoBytes;

	if (argc < NUMERO_ARGUMENTOS)
	{
		printf ("\nUso: %s <numero-bytes> <byte-1> <byte-2> ... <byte-N>\n\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	if (argv [1][0] == '-')
	{
		printf ("\nA quantidade de bytes nao pode ser negativa.\n\n");
		exit (ARGUMENTO_NEGATIVO);
	}
	
	/* Quantidade de elementos */
	argumento = strtoul (argv [1], &verificacao, 10);
	
	if ((argc - 2) != argumento)
	{
		printf ("\nQuantidade de argumentos incorreta.\n");
		printf ("Sao esperados (%s) elementos de acordo com o numero de bytes digitado.\n\n", argv [1]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	quantidadeBytes = strtoul (argv [1], &verificacao, 10);

	/* Elementos */
	conjuntoBytes = (byte *) malloc (sizeof (byte [quantidadeBytes]));

	if (conjuntoBytes == NULL)
	{
		printf ("\nNao foi possivel alocar memoria suficiente para esta quantidade de bytes.\n\n");
		exit (MEMORIA_INSUFICIENTE);
	}

	for (contador = 2; contador < argc; contador++)
	{	

		if (argv [contador][0] == '-')
		{
			printf ("\nOs argumentos nao podem ser negativos.\n\n");
			exit (ARGUMENTO_NEGATIVO);
		}

		argumento = strtoul (argv [contador], &verificacao, 10);
		
		if (*verificacao != EOS)
		{
			printf ("\nArgumento contem caractere invalido.\n");
			printf ("Primeiro caractere invalido: \'%c\'.\n\n", *verificacao);
			exit (ARGUMENTO_CONTEM_CARACTERE_INVALIDO);
		}

		if (argumento > 255)
		{	
			printf ("\nO valor maximo para um byte (255) foi ultrapassado.\n\n");
			exit (VALOR_MAXIMO_ULTRAPASSADO);
		}

		conjuntoBytes [contador - 2] = argumento;

	}
		
	/* Resultado */
	resultado = (char *) malloc (sizeof (char [(quantidadeBytes * 2) + 1]));

	if (resultado == NULL)
	{
		printf ("\nNao foi possivel alocar memoria suficiente para o resultado.\n\n");
		exit (MEMORIA_INSUFICIENTE);
	}

	CodificarBase16 (conjuntoBytes,
								   quantidadeBytes,
                   resultado);

	printf ("\nResultado: %s\n\n", resultado);

	free (conjuntoBytes);
	free (resultado);

	return SUCESSO;	

}

/* $RCSfile: aula0802.c,v $ */
