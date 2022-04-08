/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Implementacao da funcao de mostrar monitor,
 *            gerar distribuicao aleatoria inicial, limpar
 *            monitor, desenhar reta, desenhar poligono e
 *						preencher poligono.
 *
 * $Author: luiza.rosa $
 * $Date: 2022/02/02 10:58:18 $
 * $Log: aula0701.c,v $
 * Revision 1.7  2022/02/02 10:58:18  luiza.rosa
 * Programa: Correcao da logica da funcao de desenhar reta.
 *
 * Revision 1.6  2022/02/01 00:46:41  luiza.rosa
 * Programa: Implementacao da funcao de preencher poligono.
 *
 * Revision 1.5  2022/01/31 17:53:49  luiza.rosa
 * Programa: Implementacao da funcao desenhar poligono.
 *
 * Revision 1.4  2022/01/30 20:32:24  luiza.rosa
 * Programa: Correcao do valor correspondente aos pixels defeituosos.
 *
 * Revision 1.3  2022/01/30 20:02:07  luiza.rosa
 * Programa: Implementacao da funcao de desenhar reta.
 *
 * Revision 1.2  2022/01/30 00:00:15  luiza.rosa
 * Programa: Insercao da implementacao da funcao de limpar monitor.
 *
 * Revision 1.1  2022/01/29 22:52:35  luiza.rosa
 * Initial revision
 *
*/

#ifdef __linux__
#define _XOPEN_SOURCE 500
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "aula0701.h"

tipoErros
MostrarMonitor (useconds_t tempoEspera, /* E */
								tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* E */
								unsigned numeroMaximoLinhas, /* E */
								unsigned numeroMaximoColunas /* E */)
{
		
	unsigned short linha,
								 coluna, 
					       indice;

	unsigned erro = 0;

	system ("clear");

	printf ("\n");

	for (indice = 0; indice < (numeroMaximoColunas + 4); indice++) 
		printf ("-");

	printf ("\n| ");
	
	for (indice = 0; indice < numeroMaximoColunas; indice++) 
		printf (" ");

	printf (" |\n");	

	for (linha = 0; linha < numeroMaximoLinhas; linha++)
	{
		
		printf ("| ");

		for (coluna = 0; coluna < numeroMaximoColunas; coluna++)
			(monitor [linha][coluna] == aceso)      ? printf ("%c", ACESO)      : 
			(monitor [linha][coluna] == apagado)    ? printf ("%c", APAGADO)    :
			(monitor [linha][coluna] == defeituoso) ? printf ("%c", DEFEITUOSO) :
			erro++;
			
		printf (" |\n");	

	}
	
	printf ("| ");

	for (indice = 0; indice < numeroMaximoColunas; indice++) 
		printf (" ");
	
	printf (" |\n");	

	for (indice = 0; indice < (numeroMaximoColunas + 4); indice++) 
		printf ("-");
	
	printf ("\n\n");

	if (erro != 0)
		return linhaInvalida;

	usleep (tempoEspera);

	return ok;	

}

tipoErros
GerarDistribuicaoInicial (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* E/S */
													unsigned numeroMaximoLinhas, /* E */
													unsigned numeroMaximoColunas, /* E */
													float percentualDefeituosos, /* E */
													float percentualApagados /* E */)
{
	
	unsigned linha,
					 coluna,
					 pixelAleatorio,
					 semente,
					 preenchido = 0,
					 auxiliar,
					 randomLinha,
					 randomColuna;

	unsigned quantidadeTotal = numeroMaximoLinhas * numeroMaximoColunas;

	unsigned defeituosos = quantidadeTotal * (percentualDefeituosos / 100);
	
	unsigned apagados = quantidadeTotal * (percentualApagados / 100);

	unsigned acesos = quantidadeTotal - defeituosos - apagados;
	
	semente = (unsigned) time NULL;
	srand (semente);

	for (linha = 0; linha < numeroMaximoLinhas; linha++)
		for (coluna = 0; coluna < numeroMaximoColunas; coluna++)
		{
			
			preenchido = 0;

			while (!preenchido)
			{

				pixelAleatorio = rand() % 3; 
	
				if ((pixelAleatorio == 0) && (acesos > 0))
				{
					monitor [linha][coluna] = aceso;
					acesos--;
					preenchido = 1;
				}
				else if ((pixelAleatorio == 1) && (apagados > 0))
				{	
					monitor [linha][coluna] = apagado;
					apagados--;
					preenchido = 1;
				}
				else if ((pixelAleatorio == 2) && (defeituosos > 0))
				{					
					monitor [linha][coluna] = defeituoso;
					defeituosos--;
					preenchido = 1;
				}
				else if ((defeituosos == 0) && (apagados == 0) && (acesos == 0))
					preenchido = 1;
			
			}

		}	

	for (linha = 0; linha < numeroMaximoLinhas; linha++)
		for (coluna = 0; coluna < numeroMaximoColunas; coluna++)
		{
			
			randomLinha = rand() % numeroMaximoLinhas;
			randomColuna = rand() % numeroMaximoColunas;
			
			auxiliar = monitor [linha][coluna];

			monitor [linha][coluna] = monitor [randomLinha][randomColuna];
			monitor [randomLinha][randomColuna] = auxiliar;

		}

	return ok;

}


tipoErros
LimparMonitor (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* E/S */
							 unsigned numeroMaximoLinhas, /* E */
							 unsigned numeroMaximoColunas)
{
	
	unsigned linha,
					 coluna;

	for (linha = 0; linha < numeroMaximoLinhas; linha++)
		for (coluna = 0; coluna < numeroMaximoColunas; coluna++)
			if (monitor [linha][coluna] == 1)
				monitor [linha][coluna] = 0;

	return ok;	

}

tipoErros
DesenharReta (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* E/S */
							unsigned numeroMaximoLinhas, /* E */
							unsigned numeroMaximoColunas,
							unsigned linhaA,  /* E */
							unsigned colunaA, /* E */
							unsigned linhaB,  /* E */
							unsigned colunaB  /* E */)
{

	unsigned valorAbsolutoX,
					 valorAbsolutoY;

	signed linha,
				 coluna,
				 deltaLinha,
			 	 deltaColuna;

	tipoPixel monitorAuxiliar [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS];

	for (linha = 0; linha < numeroMaximoLinhas; linha++)
		for (coluna = 0; coluna < numeroMaximoColunas; coluna++)
			monitorAuxiliar [linha][coluna] = monitor [linha][coluna];

	deltaLinha = linhaB - linhaA;
	deltaColuna = colunaB - colunaA;

	valorAbsolutoX = abs (deltaLinha);
	valorAbsolutoY = abs (deltaColuna);
	
	linhaA--;
	linhaB--;
	
	colunaA--;
	colunaB--;

	if (valorAbsolutoX >= valorAbsolutoY)	
		if (deltaLinha > 0)
			for (linha = 0; linha <= deltaLinha; linha++)
			{

				coluna = ((linha * deltaColuna) / deltaLinha); 

				if (monitorAuxiliar [linhaA + linha][colunaA + coluna] == defeituoso)
					return linhaInvalida;
				else
					monitorAuxiliar [linhaA + linha][colunaA + coluna] = aceso;
				
			}
		
		else 
			for (linha = 0; linha >= deltaLinha; linha--)		
			{

				coluna = ((linha * deltaColuna) / deltaLinha); 

				if (monitorAuxiliar [linhaA + linha][colunaA + coluna] == defeituoso)
					return linhaInvalida;
				else
					monitorAuxiliar [linhaA + linha][colunaA + coluna] = aceso;

			}

	else
		if (deltaColuna > 0)
			for (coluna = 0; coluna <= deltaColuna; coluna++)
			{
			
				linha = ((coluna * deltaLinha) / deltaColuna); 

				if (monitorAuxiliar [linhaA + linha][colunaA + coluna] == defeituoso)
					return linhaInvalida;
				else
					monitorAuxiliar [linhaA + linha][colunaA + coluna] = aceso;

			}
	
		else
			for (coluna = 0; coluna <= deltaColuna; coluna--)	
			{
				
				linha = ((coluna * deltaLinha) / deltaColuna); 

				if (monitorAuxiliar [linhaA + linha][colunaA + coluna] == defeituoso)
					return linhaInvalida;
				else
					monitorAuxiliar [linhaA + linha][colunaA + coluna] = aceso;
	
			}

	for (linha = 0; linha < numeroMaximoLinhas; linha++)
		for (coluna = 0; coluna < numeroMaximoColunas; coluna++)
			monitor [linha][coluna] = monitorAuxiliar [linha][coluna];
		
	return ok;
	
}

tipoErros
DesenharPoligono (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* E/S */
									unsigned numeroMaximoLinhas,  /* E */
									unsigned numeroMaximoColunas, /* E */
									unsigned numeroVertices,      /* E */
									unsigned linhasVertices [NUMERO_MAXIMO_LINHAS],  /* E */
									unsigned colunasVertices [NUMERO_MAXIMO_COLUNAS] /* E */)							
{

	unsigned contador;

	tipoErros resultado;

	for (contador = 0; contador < (numeroVertices - 1); contador++)
	{
		
		resultado = DesenharReta (monitor,
															numeroMaximoLinhas,
															numeroMaximoColunas,
															linhasVertices [contador],
															colunasVertices [contador],
															linhasVertices [contador + 1],
															colunasVertices [contador + 1]);

		if (resultado == linhaInvalida)
			return linhaInvalida;
	
	}

	resultado = DesenharReta (monitor,
														numeroMaximoLinhas,
														numeroMaximoColunas,
														linhasVertices [numeroVertices - 1],
														colunasVertices [numeroVertices - 1],
														linhasVertices [0],
														colunasVertices [0]);

	if (resultado == linhaInvalida)
		return linhaInvalida;
	
	return ok;

}

tipoErros
PreencherPoligono (useconds_t tempoEspera, /* E */
									 tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* E/S */
									 unsigned numeroMaximoLinhas,  /* E */
									 unsigned numeroMaximoColunas, /* E */
									 unsigned linha,  /* E */
									 unsigned coluna  /* E */)								
{

	unsigned coordenadas [NUMERO_MAXIMO_LINHAS * NUMERO_MAXIMO_COLUNAS * 2],
					 contador = 1,
					 indice,
					 indiceFronteira = 0;

	signed indiceLinha,
				 indiceColuna;

	linha--;
	coluna--;

	coordenadas [0] = linha;	
	coordenadas [1] = coluna;

	for (indice = 0; indice < contador; indice++)
	{
			
		indiceLinha = coordenadas [indice + indiceFronteira];
		indiceColuna = coordenadas [indice + 1 + indiceFronteira];
		
		indiceFronteira++;

		if (monitor [linha][coluna] == -1)
			return linhaInvalida; 
	
		monitor [indiceLinha][indiceColuna] = 1;

		MostrarMonitor (tempoEspera,
										monitor,
										numeroMaximoLinhas,
										numeroMaximoColunas);

		if (monitor [indiceLinha][indiceColuna] == -1)
			return linhaInvalida; 

		if ((monitor [indiceLinha + 1][indiceColuna] == 0) &&
				((indiceLinha + 1) < numeroMaximoLinhas)			 && 
				((indiceLinha + 1) >= 0))
		{

			coordenadas [contador * 2] = indiceLinha + 1;
			coordenadas [(contador * 2) + 1] = indiceColuna;

			contador++;

			monitor [indiceLinha + 1][indiceColuna] = 1;

			MostrarMonitor (tempoEspera,
											monitor,
											numeroMaximoLinhas,
											numeroMaximoColunas);

		}

		if ((monitor [indiceLinha][indiceColuna + 1] == 0) &&
				((indiceColuna + 1) < numeroMaximoLinhas)			 && 
				((indiceColuna + 1) >= 0))
		{

			coordenadas [contador * 2] = indiceLinha;
			coordenadas [(contador * 2) + 1] = indiceColuna + 1;

			contador++;

			monitor [indiceLinha][indiceColuna + 1] = 1;

			MostrarMonitor (tempoEspera,
											monitor,
											numeroMaximoLinhas,
											numeroMaximoColunas);
		
		}

		if ((monitor [indiceLinha - 1][indiceColuna] == 0) &&
				((indiceLinha - 1) < numeroMaximoLinhas)			 && 
				((indiceLinha - 1) >= 0))
		{

			coordenadas [contador * 2] = indiceLinha - 1;
			coordenadas [(contador * 2) + 1] = indiceColuna;

			contador++;

			monitor [indiceLinha - 1][indiceColuna] = 1;

			MostrarMonitor (tempoEspera,
											monitor,
											numeroMaximoLinhas,
											numeroMaximoColunas);
		
		}

		if ((monitor [indiceLinha][indiceColuna - 1] == 0) &&
				((indiceColuna - 1) < numeroMaximoLinhas)			 && 
				((indiceColuna - 1) >= 0))
		{

			coordenadas [contador * 2] = indiceLinha;
			coordenadas [(contador * 2) + 1] = indiceColuna - 1;

			contador++;

			monitor [indiceLinha][indiceColuna - 1] = 1;

			MostrarMonitor (tempoEspera,
										  monitor,
											numeroMaximoLinhas,
											numeroMaximoColunas);
		
		}

	}
	
	return ok;

}

/* $RCSfile: aula0701.c,v $ */
