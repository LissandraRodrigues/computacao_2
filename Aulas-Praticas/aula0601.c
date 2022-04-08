/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Implementacao das funcoes de multiplicar
 *			      matrizes, obter matriz transposta, menor 
 *            complementar, complemento algebrico e 
 *				    calcular determinante.
 *
 * $Author: luiza.rosa $
 * $Date: 2022/01/25 01:05:28 $
 * $Log: aula0601.c,v $
 * Revision 1.8  2022/01/25 01:05:28  luiza.rosa
 * Programa: Atualizacao da descricao.
 *
 * Revision 1.7  2022/01/25 00:58:26  luiza.rosa
 * Programa: Correcao de erros e insercao de melhores praticas de programacao.
 *
 * Revision 1.6  2022/01/24 18:47:53  luiza.rosa
 * Programa: Insercao da implementacao da funcao de complemento algebrico.
 *
 * Revision 1.5  2022/01/24 09:36:56  luiza.rosa
 * Programa: Correcao da logica da funcao de multiplicar matrizes.
 *
 * Revision 1.4  2022/01/24 00:00:48  luiza.rosa
 * Programa: Insercao da implementacao da funcao menor complementar.
 *
 * Revision 1.3  2022/01/23 19:20:08  luiza.rosa
 * Programa: Comeco da implementacao das funcoes de calcular determinante, complemento algebrico e menor complementar.
 *
 * Revision 1.2  2022/01/23 15:35:59  luiza.rosa
 * Programa: Insercao da implementacao da funcao de obter matriz transposta.
 *
 * Revision 1.1  2022/01/22 21:40:39  luiza.rosa
 * Initial revision
 *
*/

#include "aula0601.h"

tipoErros
MultiplicarMatrizes (unsigned short numeroLinhasMatriz1,  /* numero de linhas da matriz 1 (E)  */
										 unsigned short numeroColunasMatriz1, /* numero de colunas da matriz 1 (E) */
										 unsigned short numeroLinhasMatriz2,  /* numero de linhas da matriz 2 (E)  */
										 unsigned short numeroColunasMatriz2, /* numero de colunas da matriz 2 (E) */
										 double matriz1 [QUANTIDADE_MATRIZ_LINHAS][QUANTIDADE_MATRIZ_COLUNAS], /* matriz 1 (E) */									
										 double matriz2 [QUANTIDADE_MATRIZ_LINHAS][QUANTIDADE_MATRIZ_COLUNAS], /* matriz 2 (E) */									
										 double matrizProduto [QUANTIDADE_MATRIZ_LINHAS][QUANTIDADE_MATRIZ_COLUNAS] /* matriz produto (S) */)
{

	unsigned short indice,
								 linha,
								 coluna;
	
	double resultado;
	
	for (linha = 0; linha < numeroLinhasMatriz1; linha++)
		for (coluna = 0; coluna < numeroColunasMatriz2; coluna++) 
		{

			for (indice = 0; indice < numeroColunasMatriz1; indice++)
				resultado += (matriz1 [linha][indice] * matriz2 [indice][coluna]);
									
			matrizProduto [linha][coluna] = resultado;
			
			resultado = 0;
		
		}

	return ok;

}

tipoErros
ObterMatrizTransposta (unsigned short numeroLinhasMatrizOriginal,  /* numero de linhas da matriz original (E) */
											 unsigned short numeroColunasMatrizOriginal, /* numero de colunas da matriz original (E) */
											 double matrizOriginal [QUANTIDADE_MATRIZ_LINHAS][QUANTIDADE_MATRIZ_COLUNAS],  /* matriz original (E) */
											 double matrizTransposta [QUANTIDADE_MATRIZ_LINHAS][QUANTIDADE_MATRIZ_COLUNAS] /* matriz transposta (S) */)
{
	
	unsigned short linha,
								 coluna;

	for (linha = 0; linha < numeroLinhasMatrizOriginal; linha++)
		for (coluna = 0; coluna < numeroColunasMatrizOriginal; coluna++)
			matrizTransposta [coluna][linha] = matrizOriginal [linha][coluna]; 

	return ok;
		
}

tipoErros
CalcularDeterminanteMatriz (unsigned short ordemMatriz, /* ordem da matriz (E) */
													  double matriz [QUANTIDADE_MATRIZ_LINHAS][QUANTIDADE_MATRIZ_COLUNAS], /* matriz (E) */
													  double *determinante /* determinante (S) */)
{
	
	int contador1, contador2;
	
	double somaDiagonaisPrincipais = 0,
				 somaDiagonaisSecundarias = 0,
         diagonaisPrincipais = 1,
				 diagonaisSecundarias = 1,
				 cofator [0];

	if (ordemMatriz == 1)
		*determinante = matriz [0][0];

	if (ordemMatriz == 2)
		*determinante = (matriz [0][0] * matriz [1][1]) - (matriz [1][0] * matriz [0][1]);
		
	if (ordemMatriz == 3)	/* Regra de Sarrus */
	{

		for (contador1 = 0; contador1 < ordemMatriz; contador1++)
		{

			for (contador2 = 0; contador2 < ordemMatriz; contador2++)
			{	

				diagonaisPrincipais *= matriz [(contador1 + contador2) % 3][contador2];
				diagonaisSecundarias *= matriz [(contador1 - contador2 + 2) % 3][contador2];

			}

			somaDiagonaisPrincipais += diagonaisPrincipais;
			somaDiagonaisSecundarias += diagonaisSecundarias;

			diagonaisPrincipais = 1;
			diagonaisSecundarias = 1;
				
		}
		
		*determinante = somaDiagonaisPrincipais - somaDiagonaisSecundarias; 

	}

	if (ordemMatriz > 3)  /* Teorema de Laplace */
		for (contador1 = 0; contador1 < ordemMatriz; contador1++)
		{
 
			CalcularComplementoAlgebrico (ordemMatriz, contador1, 1, matriz, cofator);
			*determinante += (cofator [0] * matriz [contador1 - 1][0]); 

		}	
				
	return ok;

}

tipoErros
CalcularMenorComplementar (unsigned short ordemMatriz, /* ordem da matriz (E)    */
													 unsigned short linhaElemento, /* linha do elemento (E)  */
													 unsigned short colunaElemento, /* coluna do elemento (E) */
													 double matriz [QUANTIDADE_MATRIZ_LINHAS][QUANTIDADE_MATRIZ_COLUNAS], /* matriz (E) */
													 double *menorComplementar /* menor complementar (S) */)
{

	double matrizAuxiliar [QUANTIDADE_MATRIZ_LINHAS][QUANTIDADE_MATRIZ_COLUNAS];

	unsigned short linha, coluna;

	/* Porque a matriz em programacao comeca em [0][0] */
	linhaElemento -= 1;
	colunaElemento -= 1;

	for (linha = 0; linha < ordemMatriz; linha++)
		for (coluna = 0; coluna < ordemMatriz; coluna++)
		{

			if (linha < linhaElemento)
			{
				if (coluna < colunaElemento)
					matrizAuxiliar [linha][coluna] = matriz [linha][coluna];
				else
					if (coluna > colunaElemento)
						matrizAuxiliar [linha][coluna - 1] = matriz [linha][coluna];
			}
			
			if (linha > linhaElemento)
			{
				if (coluna < colunaElemento)
					matrizAuxiliar [linha - 1][coluna] = matriz [linha][coluna];
				else
					if (coluna > colunaElemento)
						matrizAuxiliar [linha - 1][coluna - 1] = matriz [linha][coluna];
			}

		} 

	CalcularDeterminanteMatriz (ordemMatriz - 1, matrizAuxiliar, menorComplementar);

	return ok;

}

tipoErros
CalcularComplementoAlgebrico (unsigned short ordemMatriz, /* ordem da matriz (E)    */
													    unsigned short linhaElemento, /* linha do elemento (E)  */
													    unsigned short colunaElemento, /* coluna do elemento (E) */
													    double matriz [QUANTIDADE_MATRIZ_LINHAS][QUANTIDADE_MATRIZ_COLUNAS], /* matriz (E) */
													    double *cofator /* complemento algebrico ou cofator (S) */)
{

	double menorComplementar [1];

	CalcularMenorComplementar (ordemMatriz, linhaElemento, colunaElemento, matriz, menorComplementar);

	unsigned short expoente;

	expoente = linhaElemento + colunaElemento;

	if (expoente % 2 == 0)
		*cofator = 1;
	else
		*cofator = -1;

	*cofator = menorComplementar [0] * cofator [0];

	return ok;

}

/* $RCSfile: aula0601.c,v $ */
