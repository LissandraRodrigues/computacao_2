/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Prototipo das funcoes Multiplicar Matrizes,
 *						Obter Matriz Transposta, Calcular Menor Complementar,
 *						Calcular Complemento Algebrico e Calcular Determinante,
 *						alem de definicao de tipo.
 *			       
 * $Author: luiza.rosa $
 * $Date: 2022/01/25 01:04:03 $
 * $Log: aula0601.h,v $
 * Revision 1.4  2022/01/25 01:04:03  luiza.rosa
 * Programa: Atualizacao da descricao do programa.
 *
 * Revision 1.3  2022/01/23 19:26:19  luiza.rosa
 * Programa: Insercao do prototipo das funcoes de calcular determinante, complemento algebrico e menor complementar.
 *
 * Revision 1.2  2022/01/23 15:35:16  luiza.rosa
 * Programa: Insercao do  prototipo da funcao de obter matriz transposta.
 *
 * Revision 1.1  2022/01/22 21:39:43  luiza.rosa
 * Initial revision
 *
*/

#ifndef _AULA0601_
#define _AULA0601_							 "@(#)aula0601.h $Revision: 1.4 $"

#define QUANTIDADE_MATRIZ_LINHAS								100
#define QUANTIDADE_MATRIZ_COLUNAS								100

typedef enum { ok } tipoErros;

tipoErros
MultiplicarMatrizes (unsigned short,  /* numero de linhas da matriz 1 (E)  */
										 unsigned short,  /* numero de colunas da matriz 1 (E) */
										 unsigned short,  /* numero de linhas da matriz 2 (E)  */
										 unsigned short,  /* numero de colunas da matriz 2 (E) */
										 double [QUANTIDADE_MATRIZ_LINHAS][QUANTIDADE_MATRIZ_COLUNAS], /* matriz 1 (E) */									
										 double [QUANTIDADE_MATRIZ_LINHAS][QUANTIDADE_MATRIZ_COLUNAS], /* matriz 2 (E) */									
										 double [QUANTIDADE_MATRIZ_LINHAS][QUANTIDADE_MATRIZ_COLUNAS]  /* matriz produto (S) */);

tipoErros
ObterMatrizTransposta (unsigned short, /* numero de linhas da matriz original (E)  */
											 unsigned short, /* numero de colunas da matriz original (E) */
											 double [QUANTIDADE_MATRIZ_LINHAS][QUANTIDADE_MATRIZ_COLUNAS], /* matriz original (E)   */
											 double [QUANTIDADE_MATRIZ_LINHAS][QUANTIDADE_MATRIZ_COLUNAS]  /* matriz transposta (S) */);

tipoErros
CalcularMenorComplementar (unsigned short, /* ordem da matriz (E)    */
													 unsigned short, /* linha do elemento (E)  */
													 unsigned short, /* coluna do elemento (E) */
													 double [QUANTIDADE_MATRIZ_LINHAS][QUANTIDADE_MATRIZ_COLUNAS], /* matriz (E) */
													 double * /* menor complementar (S) */);

tipoErros
CalcularComplementoAlgebrico (unsigned short, /* ordem da matriz (E)    */
													    unsigned short, /* linha do elemento (E)  */
													    unsigned short, /* coluna do elemento (E) */
													    double [QUANTIDADE_MATRIZ_LINHAS][QUANTIDADE_MATRIZ_COLUNAS], /* matriz (E) */
													    double * /* complemento algebrico ou cofator (S) */);
tipoErros
CalcularDeterminanteMatriz (unsigned short, /* ordem da matriz (E) */
													  double [QUANTIDADE_MATRIZ_LINHAS][QUANTIDADE_MATRIZ_COLUNAS], /* matriz (E) */
													  double * /* determinante (S) */);
#endif

/* $RCSfile: aula0601.h,v $ */
