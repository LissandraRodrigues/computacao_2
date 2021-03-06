/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Programa de testes da funcao de
 *            decodificar na base 64 que tem como
 *					  entrada o nome de um arquivo.
 *
 * $Author: luiza.rosa $
 * $Date: 2022/02/16 00:54:39 $
 * $Log: aula0809.c,v $
 * Revision 1.1  2022/02/16 00:54:39  luiza.rosa
 * Initial revision
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aula0801.h"

#define SUCESSO																		0

#define NUMERO_ARGUMENTOS_INVALIDO								1
#define MEMORIA_INSUFICIENTE											2
#define ERRO_ABRIR_LEITURA											  3
#define ERRO_ABRIR_ESCRITA											  4
#define ERRO_ESCRITA															5
#define ERRO_LEITURA															6

#define NUMERO_ARGUMENTOS													3
#define COMPRIMENTO_BUFFER												100

int
main (int argc, char **argv) 
{

	unsigned long long quantidadeBytes [1],
										 indice = 1;

	tipoFinalLinha indicadorFinalLinha = habilitado;

	tipoErros status;

	char *resultado,
			 buffer [COMPRIMENTO_BUFFER];

	byte *conjuntoBytes;

	FILE *arquivoCodificado,
			 *arquivoDecodificado;

	size_t leitura; 

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\nUso: %s <nome-arquivo-codificado> <nome-arquivo-decodificado>\n\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	arquivoCodificado = fopen (argv [1], "r");

	if (arquivoCodificado == NULL)
	{
		printf ("\nNao foi possivel abrir o arquivo (%s) para leitura.\n\n", argv [1]);
		exit (ERRO_ABRIR_LEITURA);
	}

	arquivoDecodificado = fopen (argv [2], "w");

	if (arquivoDecodificado == NULL)
	{
		fclose (arquivoCodificado);
		printf ("\nNao foi possivel abrir o arquivo (%s) para escrita.\n\n", argv [2]);
		exit (ERRO_ABRIR_ESCRITA);
	}

	memset (buffer, 0x00, COMPRIMENTO_BUFFER + 2);

	while ((leitura = fread (buffer, COMPRIMENTO_BUFFER, 1, arquivoCodificado)) > 0)
		indice++;
	
	/* Resultado */
	resultado = (char *) malloc (sizeof (char [COMPRIMENTO_BUFFER * indice]));

	if (resultado == NULL)
	{
		fclose (arquivoCodificado);
		fclose (arquivoDecodificado);
		remove (argv [2]);
		printf ("\nNao foi possivel alocar memoria suficiente.\n\n");
		exit (MEMORIA_INSUFICIENTE);
	}

	fseek (arquivoCodificado, 0, SEEK_SET);

	fread (resultado, (COMPRIMENTO_BUFFER * indice), 1, arquivoCodificado);

	if (ferror (arquivoCodificado))
	{
		free (resultado);
		fclose (arquivoCodificado);
		fclose (arquivoDecodificado);
		remove (argv [2]);
		printf ("\nErro na leitura do arquivo.\n\n");
		exit (ERRO_LEITURA);		
	}

	quantidadeBytes [0] = strlen (resultado);

	conjuntoBytes = (byte *) malloc (sizeof (byte [quantidadeBytes [0]]));

	if (conjuntoBytes == NULL)
	{
		free (resultado);
		fclose (arquivoCodificado);
		fclose (arquivoDecodificado);
		remove (argv [2]);
		printf ("\nNao foi possivel alocar memoria suficiente.\n\n");
		exit (MEMORIA_INSUFICIENTE);
	}
	
	status = DecodificarBase64 (resultado,
													    indicadorFinalLinha,
													  	conjuntoBytes,
														  quantidadeBytes);
	
	if (status == memoriaInsuficiente)
	{
		free (resultado);
		free (conjuntoBytes);
		fclose (arquivoCodificado);
		fclose (arquivoDecodificado);
		remove (argv [2]);
		printf ("\nNao foi possivel alocar memoria suficiente.\n\n");
		exit (MEMORIA_INSUFICIENTE);
	}

	fwrite (conjuntoBytes,
					1,
				  strlen ((char *) conjuntoBytes),
				  arquivoDecodificado);

	if (ferror (arquivoDecodificado))
	{
		free (conjuntoBytes);
		free (resultado);
		fclose (arquivoCodificado);
		fclose (arquivoDecodificado);
		remove (argv [2]);
		printf ("\nErro na escrita do arquivo.\n\n");
		exit (ERRO_ESCRITA);
	}

	free (conjuntoBytes);
	free (resultado);	
	fclose (arquivoCodificado);
	fclose (arquivoDecodificado);

	printf ("\nArquivo (%s) decodificado.\n", argv [1]);
	printf ("\nArquivo (%s) gerado com sucesso.\n\n", argv [2]);

	return SUCESSO;	

}

/* $RCSfile: aula0809.c,v $ */
