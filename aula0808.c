/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Programa de testes da funcao de
 *            codificar na base 64 que tem como
 *					  entrada o nome de um arquivo.
 *
 * $Author: luiza.rosa $
 * $Date: 2022/02/16 00:53:04 $
 * $Log: aula0808.c,v $
 * Revision 1.2  2022/02/16 00:53:04  luiza.rosa
 * Programa: Insercao de melhores praticas de programacao.
 *
 * Revision 1.1  2022/02/15 18:22:23  luiza.rosa
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

	unsigned long long quantidadeBytes,
										 indice = 1;

	tipoFinalLinha indicadorFinalLinha = habilitado;

	tipoErros status;

	char *resultado;

	byte *conjuntoBytes,
			 buffer [COMPRIMENTO_BUFFER];

	FILE *arquivo,
			 *arquivoNovo;

	size_t leitura; 

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\nUso: %s <nome-arquivo> <nome-arquivo-codificado>\n\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	arquivo = fopen (argv [1], "r");

	if (arquivo == NULL)
	{
		printf ("\nNao foi possivel abrir o arquivo (%s) para leitura.\n\n", argv [1]);
		exit (ERRO_ABRIR_LEITURA);
	}

	arquivoNovo = fopen (argv [2], "w");

	if (arquivoNovo == NULL)
	{
		fclose (arquivo);
		printf ("\nNao foi possivel abrir o arquivo (%s) para escrita.\n\n", argv [2]);
		exit (ERRO_ABRIR_ESCRITA);
	}

	memset (buffer, 0x00, COMPRIMENTO_BUFFER + 2);

	while ((leitura = fread (buffer, COMPRIMENTO_BUFFER, 1, arquivo)) > 0)
		indice++;
	
	conjuntoBytes = (byte *) malloc (sizeof (byte [COMPRIMENTO_BUFFER * indice]));

	if (conjuntoBytes == NULL)
	{
		fclose (arquivo);
		fclose (arquivoNovo);
		remove (argv [2]);
		printf ("\nNao foi possivel alocar memoria suficiente.\n\n");
		exit (MEMORIA_INSUFICIENTE);
	}

	fseek (arquivo, 0, SEEK_SET);

	fread (conjuntoBytes, (COMPRIMENTO_BUFFER * indice), 1, arquivo);

	if (ferror (arquivo))
	{
		free (conjuntoBytes);
		fclose (arquivo);
		fclose (arquivoNovo);
		remove (argv [2]);
		printf ("\nErro na leitura do arquivo.\n\n");
		exit (ERRO_LEITURA);		
	}

	quantidadeBytes = strlen ((char *) conjuntoBytes);
	
	/* Resultado */
	resultado = (char *) malloc (sizeof (char [(quantidadeBytes * 2) + 4]));

	if (resultado == NULL)
	{
		free (conjuntoBytes);
		fclose (arquivo);
		fclose (arquivoNovo);
		remove (argv [2]);
		printf ("\nNao foi possivel alocar memoria suficiente.\n\n");
		exit (MEMORIA_INSUFICIENTE);
	}

	status = CodificarBase64 (conjuntoBytes,
													  quantidadeBytes,
														indicadorFinalLinha,
														resultado);
	
	if (status == memoriaInsuficiente)
	{
		free (resultado);
		free (conjuntoBytes);
		fclose (arquivo);
		fclose (arquivoNovo);
		remove (argv [2]);
		printf ("\nNao foi possivel alocar memoria suficiente.\n\n");
		exit (MEMORIA_INSUFICIENTE);
	}

	fwrite (resultado,
					1,
				  strlen (resultado),
				  arquivoNovo);

	if (ferror (arquivoNovo))
	{
		free (conjuntoBytes);
		free (resultado);
		fclose (arquivo);
		fclose (arquivoNovo);
		remove (argv [2]);
		printf ("\nErro na escrita do arquivo.\n\n");
		exit (ERRO_ESCRITA);
	}

	free (conjuntoBytes);
	free (resultado);	
	fclose (arquivo);
	fclose (arquivoNovo);

	printf ("\nArquivo (%s) codificado.\n", argv [1]);
	printf ("\nArquivo (%s) gerado com sucesso.\n\n", argv [2]);

	return SUCESSO;	

}

/* $RCSfile: aula0808.c,v $ */
