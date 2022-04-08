/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Implementacao das funcoes de exibir conteudo
 *            de um arquivo e converter arquivo formato Unix
 *         	  para formato Dos e vice-versa.
 *
 * $Author: luiza.rosa $
 * $Date: 2022/03/08 19:04:45 $
 * $Log: aula0901.c,v $
 * Revision 1.5  2022/03/08 19:04:45  luiza.rosa
 * Programa: Correcao dos nomes temporarios.
 *
 * Revision 1.4  2022/03/02 20:40:15  luiza.rosa
 * Programa: Insercao da implementacao da funcao de converter de Dos para Unix.
 *
 * Revision 1.3  2022/02/25 23:01:50  luiza.rosa
 * Programa: Correcao para versao linux.
 *
 * Revision 1.2  2022/02/25 20:46:26  luiza.rosa
 * Programa: Implementacao da funcao de converter formato unix para dos.
 *
 * Revision 1.1  2022/02/25 01:07:57  luiza.rosa
 * Initial revision
 *
*/

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#ifdef __linux__
#include <stdio_ext.h>
#endif

#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "aula0901.h"

tipoErros 
ExibirConteudoArquivo (char *nomeArquivo /* (E) */)
{

	unsigned long long valor,
										 indice;

	byte *conjuntoBytes,
			 buffer [COMPRIMENTO_BUFFER];

	size_t leitura;

	FILE *arquivo = fopen (nomeArquivo, "r");

	if (arquivo == NULL)
	{
		printf ("\nNao foi possivel abrir o arquivo (%s) para leitura.\n\n", nomeArquivo);
		return erroLeitura;
	}

	memset (buffer, 0x00, COMPRIMENTO_BUFFER + 2);

	conjuntoBytes = (byte *) malloc (sizeof ((BUFFER * 2) + 1)); 

	if (conjuntoBytes == NULL)
	{
		fclose (arquivo);
		printf ("\nNao foi possivel alocar memoria suficiente.\n\n");
		return memoriaInsuficiente;
	}

	fseek (arquivo, 0, SEEK_SET);

	valor = strlen ((char *) conjuntoBytes);

	printf ("\n");

	while ((leitura = fread (conjuntoBytes, 1, 16, arquivo)) > 0)
	{

		printf ("%08X | ", (int) valor);

		valor += strlen ((char *) conjuntoBytes);	

		for (indice = 0; indice < strlen ((char *) conjuntoBytes); indice += 2)
			printf ("%02X %02X ", conjuntoBytes [indice], conjuntoBytes [indice + 1]);  

		if (strlen ((char *) conjuntoBytes) < 16)
			for (indice = strlen ((char *) conjuntoBytes); indice < 15; indice += 2)
					printf ("      ");  

		printf ("| ");

		for (indice = 0; indice < strlen ((char *) conjuntoBytes); indice++)
			printf ("%c", (conjuntoBytes [indice] < 0x20) ? '.' : (conjuntoBytes [indice] < 0x7F) ? conjuntoBytes [indice] : '.');  
	
		printf ("\n");

		memset (conjuntoBytes, 0, 16); 

	}

	if (ferror (arquivo))
	{
		fclose (arquivo);
		free (conjuntoBytes);
		printf ("\nNao foi possivel ler o arquivo (%s).\n\n", nomeArquivo);
		return erroLeitura;
	}
	
	printf ("\nConteudo do arquivo (%s) exibido com sucesso.\n\n", nomeArquivo);

	return ok;

}

tipoErros
ConverterArquivoFormatoUnixParaFormatoDos (char *original, 
																					 char *convertido)
{

	unsigned indice;

	byte conjuntoBytes [BUFFER + 1];

	FILE *arquivoLeitura,
			 *arquivoEscrita;

	int arquivoTemporario;

	char temporario [31] = "backup.XXXXXXXXXXXXXXX",
			 *backup,
			 anterior;

	size_t leitura;
	time_t horario;

	struct tm *diaHorario;

	arquivoLeitura = fopen (original, "r");

	if (arquivoLeitura == NULL)
	{
		printf ("\nNao foi possivel ler o arquivo (%s).\n\n", original);
		return erroLeitura;
	}

	if (convertido == NULL)
	{
		
		arquivoTemporario = mkstemp (temporario);
	
		if (arquivoTemporario == -1)
		{
      fclose (arquivoLeitura);
		  printf ("\nNao foi possivel ler o arquivo temporario.\n\n");
			return erroLeitura;
		}

		arquivoEscrita = fdopen (arquivoTemporario, "w"); 

		backup = (char *) malloc (sizeof (char [strlen (original) + 25]));		
	
		if (backup == NULL)
		{
	    fclose (arquivoLeitura);
		  printf ("\nNao foi possivel alocar memoria suficiente.\n\n");
			return memoriaInsuficiente;
		}

	}	
	else
		arquivoEscrita = fopen (convertido, "w");

	if (arquivoEscrita == NULL)
	{
    fclose (arquivoLeitura);
		printf ("\nNao foi possivel alocar memoria suficiente.\n\n");
		return erroLeitura;
	}

	conjuntoBytes [BUFFER] = '\0';

	memset (conjuntoBytes, 0x00, BUFFER);

	while ((leitura = fread (conjuntoBytes, 1, BUFFER, arquivoLeitura)) > 0)
	{
		
		for (indice = 0; indice < strlen ((char *) conjuntoBytes); indice++)
		{

			if ((conjuntoBytes [indice] != '\n') || (anterior == '\r'))
				fwrite (&conjuntoBytes [indice], 1, 1, arquivoEscrita);
			else
				fwrite ("\r\n", 2, 1, arquivoEscrita);
		
			anterior = conjuntoBytes [indice];
				 
		}

		memset (conjuntoBytes, 0x00, BUFFER);
	
	}

	if (convertido == NULL)
	{

		horario = time (NULL);

		diaHorario = localtime (&horario);

		snprintf (backup,
						  strlen (original) + 25,
							"%s.backup-%04d%02d%02d_%02d%02d%02d",
							original,
							diaHorario -> tm_year + 1900,
						  diaHorario -> tm_mon + 1,
							diaHorario -> tm_mday,
							diaHorario -> tm_hour,
							diaHorario -> tm_min,
							diaHorario -> tm_sec);
	
		printf ("\nBackup: (%s).\n", backup);

		rename (original, backup);
		rename (temporario, original);

	}

	fclose (arquivoLeitura);
	fclose (arquivoEscrita);
	
	return ok;
	
}	

tipoErros
ConverterArquivoFormatoDosParaFormatoUnix (char *original, 
																					 char *convertido)
{

	unsigned indice;
	byte conjuntoBytes [BUFFER + 1];

	FILE *arquivoLeitura,
			 *arquivoEscrita;

	int arquivoTemporario;

	char temporario [31] = "backup.XXXXXXXXXXXXXXX",
			 *backup;

	size_t leitura;
	time_t horario;

	struct tm *diaHorario;

	arquivoLeitura = fopen (original, "r");

	if (arquivoLeitura == NULL)
	{
		printf ("\nNao foi possivel ler o arquivo (%s).\n\n", original);
		return erroLeitura;
	}

	if (convertido == NULL)
	{
		
		arquivoTemporario = mkstemp (temporario);
	
		if (arquivoTemporario == -1)
		{
      fclose (arquivoLeitura);
		  printf ("\nNao foi possivel ler o arquivo temporario.\n\n");
			return erroLeitura;
		}

		arquivoEscrita = fdopen (arquivoTemporario, "w"); 

		backup = (char *) malloc (sizeof (char [strlen (original) + 25]));		
	
		if (backup == NULL)
		{
	    fclose (arquivoLeitura);
		  printf ("\nNao foi possivel alocar memoria suficiente.\n\n");
			return memoriaInsuficiente;
		}

	}	
	else
		arquivoEscrita = fopen (convertido, "w");

	if (arquivoEscrita == NULL)
	{
    fclose (arquivoLeitura);
		printf ("\nNao foi possivel alocar memoria suficiente.\n\n");
		return erroLeitura;
	}

	conjuntoBytes [BUFFER] = '\0';

	memset (conjuntoBytes, 0x00, BUFFER);

	while ((leitura = fread (conjuntoBytes, 1, BUFFER, arquivoLeitura)) > 0)
	{
		
		for (indice = 0; indice < strlen ((char *) conjuntoBytes); indice++)
			if(conjuntoBytes [indice] != '\r')
				fwrite (&conjuntoBytes [indice], 1, 1, arquivoEscrita);

		memset (conjuntoBytes, 0x00, BUFFER);
	
	}

	if (convertido == NULL)
	{

		horario = time (NULL);

		diaHorario = localtime (&horario);

		snprintf (backup,
						  strlen (original) + 25,
							"%s.backup-%04d%02d%02d_%02d%02d%02d",
							original,
							diaHorario -> tm_year + 1900,
						  diaHorario -> tm_mon + 1,
							diaHorario -> tm_mday,
							diaHorario -> tm_hour,
							diaHorario -> tm_min,
							diaHorario -> tm_sec);

		printf ("\nBackup: (%s).\n", backup);

		rename (original, backup);
		rename (temporario, original);

	}

	fclose (arquivoLeitura);
	fclose (arquivoEscrita);
	
	return ok;

}

/* $RCSfile: aula0901.c,v $ */
