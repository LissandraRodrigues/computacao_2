/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Prototipos da funcoes de codificar e decodificar
 *						com bases 16, 32 e 64, alem de definicoes e funcoes
 *						auxiliares.
 *
 * $Author: luiza.rosa $
 * $Date: 2022/02/15 17:04:15 $
 * $Log: aula0801.h,v $
 * Revision 1.6  2022/02/15 17:04:15  luiza.rosa
 * Programa: Insercao do cabecalho da funcao de decodificar na base 64.
 *
 * Revision 1.5  2022/02/15 12:21:15  luiza.rosa
 * Programa: Insercao do cabecalho da funcao de codificar em base 64.
 *
 * Revision 1.4  2022/02/14 20:59:08  luiza.rosa
 * Programa: Insercao do cabecalho da funcao de decodificar com base 32.
 *
 * Revision 1.3  2022/02/14 16:12:00  luiza.rosa
 * Programa: Insercao do cabecalho da funcao de codificar em base 32 e de funcoes auxiliares.
 *
 * Revision 1.2  2022/02/03 23:59:11  luiza.rosa
 * Programa: Insercao do prototipo da funcao de decodificar com base 16.
 *
 * Revision 1.1  2022/02/03 02:03:38  luiza.rosa
 * Initial revision
 *
*/

#ifndef _AULA08_
#define _AULA08_							 "@(#)aula08.h $Revision: 1.6 $"
#endif

#define	EOS															'\0'					

typedef enum { ok, invalido, memoriaInsuficiente } tipoErros;

typedef enum { basico, estendido } tipoAlfabetoBase32;

typedef enum { desabilitado, habilitado } tipoFinalLinha;

typedef unsigned char byte;

tipoErros 
CodificarBase16 (byte * /* (E) */,
								 unsigned long long /* (E) */,
                 char * /* (S) */);

tipoErros 
DecodificarBase16 (char * /* (E) */,
									 byte * /* (S) */,
									 unsigned long long * /* (S) */);

tipoErros 
CodificarBase32 (byte * /* (E) */,
								 unsigned long long /* (E) */,
								 tipoAlfabetoBase32 /* (E) */,
                 char * /* (S) */);

tipoErros 
DecodificarBase32 (char * /* (E) */,
									 tipoAlfabetoBase32 /* (E) */,
                   byte * /* (S) */,
								   unsigned long long * /* (S) */);

tipoErros 
CodificarBase64 (byte * /* (E) */,
								 unsigned long long /* (E) */,
								 tipoFinalLinha /* (E) */,
                 char * /* (S) */);

tipoErros 
DecodificarBase64 (char * /* (E) */,
									 tipoFinalLinha /* (E) */,
								   byte * /* (S) */,
								   unsigned long long * /* (S) */);

tipoErros
ConverterDecimalParaBinario (byte *,
														 char *);

tipoErros
ConverterBinarioParaDecimal (char *,
														 byte *);

/* $RCSfile: aula0801.h,v $ */
