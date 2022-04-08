/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Prototipo da funcao mostrar monitor,
 *		        gerar distribuicao inicial, limpar monitor,
 *		        desenhar reta, desenhar poligono e preencher
 *						poligono.
 *
 * $Author: luiza.rosa $
 * $Date: 2022/02/01 00:42:44 $
 * $Log: aula0701.h,v $
 * Revision 1.5  2022/02/01 00:42:44  luiza.rosa
 * Programa: Insercao do prototipo da funcao de preencher poligono.
 *
 * Revision 1.4  2022/01/31 17:53:19  luiza.rosa
 * Programa: Insercao do prototipo da funcao desenhar poligono.
 *
 * Revision 1.3  2022/01/30 20:02:59  luiza.rosa
 * Programa: Insercao do prototipo da funcao de desenhar reta.
 *
 * Revision 1.2  2022/01/29 23:59:42  luiza.rosa
 * Programa: Insercao do prototipo da funcao de limpar monitor.
 *
 * Revision 1.1  2022/01/29 22:53:04  luiza.rosa
 * Initial revision
 *
*/

#ifndef _AULA0701_
#define _AULA0701_							 "@(#)aula0701.h $Revision: 1.5 $"

#define NUMERO_MAXIMO_LINHAS										250
#define NUMERO_MAXIMO_COLUNAS				    				800
#define ACESO																		'O'
#define APAGADO																	' '
#define DEFEITUOSO															'.'

typedef enum { ok, linhaInvalida, pixelDefeituoso } tipoErros;

typedef enum { apagado, aceso, defeituoso = -1 } tipoPixel;

#include <unistd.h>

tipoErros
MostrarMonitor (useconds_t tempoEspera, /* E */
								tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* E */
								unsigned numeroMaximoLinhas, /* E */
								unsigned numeroMaximoColunas /* E */);
tipoErros
GerarDistribuicaoInicial (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* E/S */
													unsigned numeroMaximoLinhas,  /* E */
													unsigned numeroMaximoColunas, /* E */
													float percentualDefeituosos,  /* E */
													float percentualApagados /* E */);

tipoErros
LimparMonitor (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* E/S */
							 unsigned numeroMaximoLinhas, /* E */
							 unsigned numeroMaximoColunas);

tipoErros
DesenharReta (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* E/S */
							unsigned numeroMaximoLinhas, /* E */
							unsigned numeroMaximoColunas, /* E */
							unsigned linhaA,  /* E */
							unsigned colunaA, /* E */
							unsigned linhaB,  /* E */
							unsigned colunaB  /* E */);

tipoErros
DesenharPoligono (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* E/S */
									unsigned numeroMaximoLinhas,  /* E */
									unsigned numeroMaximoColunas, /* E */
									unsigned numeroVertices,      /* E */
									unsigned linhasVertices [NUMERO_MAXIMO_LINHAS],  /* E */
									unsigned colunasVertices [NUMERO_MAXIMO_COLUNAS] /* E */);								

tipoErros
PreencherPoligono (useconds_t tempoEspera, /* E */
									 tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* E/S */
									 unsigned numeroMaximoLinhas,  /* E */
									 unsigned numeroMaximoColunas, /* E */
									 unsigned linha,  /* E */
									 unsigned coluna  /* E */);								

#endif

/* $RCSfile: aula0701.h,v $ */
