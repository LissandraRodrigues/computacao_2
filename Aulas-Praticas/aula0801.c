/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Implementacao das funcoes de codificar com bases 16, 32 e 64,
 *						além de funcoes auxiliares.
 *
 * $Author: luiza.rosa $
 * $Date: 2022/02/15 23:20:39 $
 * $Log: aula0801.c,v $
 * Revision 1.8  2022/02/15 23:20:39  luiza.rosa
 * Programa: Retirada de espaco desnecessario.
 *
 * Revision 1.7  2022/02/15 22:53:51  luiza.rosa
 * Programa: Insercao de melhores praticas de programacao.
 *
 * Revision 1.6  2022/02/15 17:06:19  luiza.rosa
 * Programa: Implementacao da funcao de decodificar na base 64.
 *
 * Revision 1.5  2022/02/15 12:20:12  luiza.rosa
 * Programa: Insercao da implementacao da funcao de codificar em base 64.
 *
 * Revision 1.4  2022/02/14 20:57:45  luiza.rosa
 * Programa: Insercao da implementacao da funcao de decodificar com base 32.
 *
 * Revision 1.3  2022/02/14 16:11:27  luiza.rosa
 * Programa: Implementacao da funcao de codificar na base 32.
 *
 * Revision 1.2  2022/02/03 23:59:50  luiza.rosa
 * Programa: Implementacao da funcao de decodificar com base 16.
 *
 * Revision 1.1  2022/02/03 02:03:12  luiza.rosa
 * Initial revision
 *
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "aula0801.h"

tipoErros 
CodificarBase16 (byte *conjuntoBytes /* (E) */,
								 unsigned long long quantidadeBytes /* (E) */,
								 char *resultado /* (S) */)
{

	unsigned contador;

	char codificacao [3],
			 caracteres [16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

	byte resto,
			 auxiliar;

	resultado [0] = EOS;

	for (contador = 0; contador < quantidadeBytes; contador++)
	{
		
		auxiliar = conjuntoBytes [contador];

		resto = auxiliar % 16;
		
		auxiliar = (auxiliar - resto) / 16;		

		codificacao [0] = caracteres [auxiliar];
		codificacao [1] =	caracteres [resto];
		codificacao [2] = EOS;
	
		strcat (resultado, codificacao);

	}	 	

	return ok;

}

tipoErros 
DecodificarBase16 (char *entrada /* (E) */,
									 byte *conjuntoBytes /* (S) */,
									 unsigned long long *quantidadeBytes /* (S) */)
{

	unsigned indice = 0,
					 indiceA,
					 indiceB,
					 indiceC,					
					 validacao = 0;

	unsigned long long contador;
	
	char caracteres [16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	
	quantidadeBytes [0] = strlen (entrada) / 2;

	for (contador = 0; contador < (quantidadeBytes [0] * 2); contador += 2)
	{

		for (indiceA = 0; indiceA < 16; indiceA++)
		{

				if (entrada [contador] == caracteres [indiceA])
				{
					indiceB = indiceA;
					validacao++;
				}
		
				if (entrada [contador + 1] == caracteres [indiceA])
				{
					indiceC = indiceA;
					validacao++;
				}

		}
		
		if ((validacao % 2) != 0)
			return invalido;

		validacao = 0;
	
		conjuntoBytes [indice] = (indiceB * 16) + indiceC;
	
		indice++;

	}

	return ok;

}

tipoErros 
CodificarBase32 (byte *conjuntoBytes /* (E) */,
								 unsigned long long quantidadeBytes /* (E) */,
								 tipoAlfabetoBase32 alfabeto /* (E) */,
                 char *resultado /* (S) */)
{
	
	char alfabeto32Basico [32] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '2', '3', '4', '5', '6', '7'},
			 alfabeto32Estendido [32] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V'},
			 *binario,
			 string [5];
	
	int indice;

	byte resultadoAuxiliar = 0,
			 resto; 
	
	binario = malloc (sizeof (char [(quantidadeBytes * 8) + 1]));
	
	if (binario == NULL)
	{
			printf ("\nNao foi possivel alocar memoria suficiente.\n\n");
			return memoriaInsuficiente;
	}	

	ConverterDecimalParaBinario (conjuntoBytes, binario);

	resto = strlen (binario) % 5;

	if (resto)
	{
		
		for (indice = 0; indice < (5 - resto); indice++)
			string [indice] = '0';

		string [indice] = EOS;

		strcat (binario, string);

	}
		
	for (indice = 0; indice < strlen (binario); indice += 5)
	{
	
		resultadoAuxiliar = (binario [indice] - '0') * 16;
			
		resultadoAuxiliar += (binario [indice + 1] - '0') * 8;	
		resultadoAuxiliar += (binario [indice + 2] - '0') * 4;	
		resultadoAuxiliar += (binario [indice + 3] - '0') * 2;	
		resultadoAuxiliar += (binario [indice + 4] - '0') * 1;	
	
		if (alfabeto == basico)
			resultado [indice / 5] = alfabeto32Basico [resultadoAuxiliar];
		else
			resultado [indice / 5] = alfabeto32Estendido [resultadoAuxiliar];
	}

	resultado [indice / 5] = EOS;

	resto = strlen (resultado) % 8;

	if (resto)
	{
		
		for (indice = 0; indice < (8 - resto); indice++)
			string [indice] = '=';
		
		string [indice] = EOS;
	
		strcat (resultado, string);

	}

	free (binario);

	return ok;

}

tipoErros 
DecodificarBase32 (char *entrada /* (E) */,
									 tipoAlfabetoBase32 alfabeto/* (E) */,
                   byte *conjuntoBytes /* (S) */,
								   unsigned long long *quantidadeBytes /* (S) */)
{

	int indice,
			contador,
			resto,
			auxiliar,
			tamanhoVetor = strlen ((char *) entrada);

	char alfabeto32Basico [32] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '2', '3', '4', '5', '6', '7'},
			 alfabeto32Estendido [32] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V'},
			 *resultado,
			 *binario,
			 stringAuxiliar [tamanhoVetor][6];

	binario = malloc (sizeof (char [(tamanhoVetor * 8) + 1]));
	
	if (binario == NULL)
	{
			printf ("\nNao foi possivel alocar memoria suficiente.\n\n");
			return memoriaInsuficiente;
	}

	resultado = malloc (sizeof (char [tamanhoVetor + 1]));

	if (resultado == NULL)
	{
			free (binario);
			printf ("\nNao foi possivel alocar memoria suficiente.\n\n");
			return memoriaInsuficiente;
	}

	binario [0] = EOS; 

	for (indice = 0; indice < tamanhoVetor; indice++)
		for (contador = 0; contador < 32; contador++)
		{	

			if (alfabeto == basico)
			{
				if (entrada [indice] == alfabeto32Basico [contador])
					resultado [indice] = contador;
			}
			else
				if (entrada [indice] == alfabeto32Estendido [contador])
					resultado [indice] = contador;
				
		}
		
	for (contador = 0; contador < tamanhoVetor; contador++)
	{

		stringAuxiliar [contador][5] = EOS;
	
		if (alfabeto == basico)
			for (indice = 4; indice >= 0; indice--)
			{
				
				resto = resultado	[contador] % 2;
				auxiliar = (resultado [contador] - resto) / 2;
				resultado [contador] = auxiliar;
	
				if ((!resto) || (resto == 1))
					stringAuxiliar [contador][indice] = resto + '0'; 		

			}
		else
			for (indice = 5; indice >= 0; indice++)
			{
				
				resto = resultado	[contador] % 2;
				auxiliar = (resultado [contador] - resto) / 2;
				resultado [contador] = auxiliar;
	
				if ((!resto) || (resto == 1))
					stringAuxiliar [contador][indice] = resto + '0'; 		

			}

		strcat (binario, stringAuxiliar [contador]);
		
	}

	ConverterBinarioParaDecimal (binario, conjuntoBytes);
	
	quantidadeBytes [0] = (int) strlen ((char *) conjuntoBytes);

	free (binario);
	free (resultado);

	return ok;

}

tipoErros 
CodificarBase64 (byte *conjuntoBytes /* (E) */,
								 unsigned long long quantidadeBytes /* (E) */,
								 tipoFinalLinha finalLinha /* (E) */,
                 char *resultado /* (S) */)
{

	char alfabeto [64] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
												'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
												'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'};

	char *binario,
			 string [6];

	int indice,
		  indiceLinha,
		  contador,
		  tamanho;

	byte resultadoAuxiliar = 0,
			 resto;

	binario = malloc (sizeof (char [(quantidadeBytes * 8) + 1]));

	if (binario == NULL)
	{
		printf ("\nNao foi possivel alocar memoria suficiente.\n\n");
		return memoriaInsuficiente;
	}

	ConverterDecimalParaBinario (conjuntoBytes, binario);

	tamanho = strlen (binario) % 24;

	if (tamanho != 0)
		if ((strlen (binario) % 6) != 0)
		{

			resto = strlen (binario) % 6;

			for (indice = 0; indice < (6 - resto); indice++)
				string [indice] = '0';
		 
			string [indice] = EOS;

			strcat (binario, string);	
	
		}

	for (indice = 0; indice < strlen (binario); indice += 6)
	{
	
		resultadoAuxiliar = (binario [indice] - '0') * 32;
		
		resultadoAuxiliar += (binario [indice + 1] - '0') * 16;
		resultadoAuxiliar += (binario [indice + 2] - '0') * 8;
		resultadoAuxiliar += (binario [indice + 3] - '0') * 4;
		resultadoAuxiliar += (binario [indice + 4] - '0') * 2;
		resultadoAuxiliar += (binario [indice + 5] - '0') * 1;

		resultado [indice / 6] = alfabeto [resultadoAuxiliar];
	
	}

	resultado [indice / 6] = EOS;

	tamanho = strlen (resultado) % 4;
	
	if (tamanho != 0)
	{

		resto = strlen (resultado) % 4;

		for (indice = 0; indice < (4 - resto); indice++)
			string [indice] = '=';
		 
		string [indice] = EOS;

		strcat (resultado, string);	

	}
	
	if (finalLinha == habilitado)
	{
	
		indiceLinha = 1;
	
		for (indice = 0; indice < strlen (resultado); indice++)
		{
	
			if (indiceLinha == 77)
			{
			
				resultado [strlen (resultado) + 1] = EOS;

				for (contador = strlen (resultado); contador > indice; contador--)
					resultado [contador] = resultado [contador - 1];
	
				resultado [contador] = '\n';
			
				indiceLinha = 0;
					
			}

			indiceLinha++;

		}

	}
	
	return ok;

}

tipoErros 
DecodificarBase64 (char *entrada /* (E) */,
									 tipoFinalLinha indicadorFinalLinha /* (E) */,
								   byte *conjuntoBytes /* (S) */,
								   unsigned long long *quantidadeBytes /* (S) */)
{

	int indice,
		  contador,
			resto,
			auxiliar,
			tamanhoVetor = strlen ((char *) entrada);

	char *binario,
			 *resultado,
			 stringAuxiliar [tamanhoVetor][7],
			 alfabeto [64] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
												'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
												'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'};

	binario = malloc (sizeof (char [(tamanhoVetor * 8) + 1]));

	if (binario == NULL)
	{
		printf ("\nNao foi possivel alocar memoria suficiente.\n\n");
		return memoriaInsuficiente;
	}

	resultado = malloc (sizeof (char [tamanhoVetor + 1]));

	if (resultado == NULL)
	{
		free (binario);
		printf ("\nNao foi possivel alocar memoria suficiente.\n\n");
		return memoriaInsuficiente;
	}
	
	binario [0] = EOS;

	for (indice = 0; indice < strlen (entrada); indice++)
		if (entrada [indice] == '\n')
			for (contador = indice; contador < strlen (entrada); contador++)
				entrada [contador] = entrada [contador + 1];
	
	for (indice = 0; indice < tamanhoVetor; indice++)
		for (contador = 0; contador < 64; contador++)
			if (entrada [indice] == alfabeto [contador])
				resultado [indice] = contador;

	for (contador = 0; contador < tamanhoVetor; contador++)
	{
	
		stringAuxiliar [contador][6] = EOS;

		for (indice = 5; indice >= 0; indice--)
		{
	
			resto = resultado [contador] % 2;
			auxiliar = (resultado [contador] - resto) / 2; 
			resultado [contador] = auxiliar;

			if ((!resto) || (resto == 1))
				stringAuxiliar [contador][indice] = resto + '0';

		} 
	
		strcat (binario, stringAuxiliar [contador]);
	
	}

	ConverterBinarioParaDecimal (binario, conjuntoBytes);

	quantidadeBytes [0] = (int) strlen ((char *) conjuntoBytes);

	free (binario);
	free (resultado);

	return ok;

}

tipoErros
ConverterDecimalParaBinario (byte *conjuntoBytes,
														 char *binario)
{

	int indice1,
		  indice2 = 0,
		  contador,
			auxiliar,
			resto;

	char stringAuxiliar [strlen ((char *) conjuntoBytes)][8],
			 stringBinario [strlen ((char *) conjuntoBytes)][8];

	unsigned tamanhoConjunto = strlen ((char *) conjuntoBytes);

	for (contador = 0 ; contador < tamanhoConjunto; contador++) 
		for (indice1 = 0; indice1 < 8; indice1++)
		{

			resto = conjuntoBytes [contador] % 2;
			auxiliar = (conjuntoBytes [contador] - resto) / 2;
			conjuntoBytes [contador] = auxiliar;

			if ((!resto) || (resto == 1))
				stringAuxiliar [contador][indice1] = resto + '0';

		}
	
	for (contador = 0 ; contador < tamanhoConjunto; contador++) 
	{

		for (indice1 = 7; indice1 >= 0; indice1--)
		{

			stringBinario [contador][indice2] = stringAuxiliar [contador][indice1];
			indice2++;
	
		}

		stringBinario [contador][indice2] = '\0';
		indice2 = 0;	
		strcat (binario, stringBinario [contador]);
		
	}

	return ok;

}

tipoErros
ConverterBinarioParaDecimal (char *binario,
														 byte *conjuntoBytes)
{

	byte resultado = 0;

	int indice,
			resto = 0,
			tamanhoBinario;

	char string [2];

	tamanhoBinario = strlen (binario);
	
	string [0] = '0';
	string [1] = EOS;
	
	if (tamanhoBinario % 8)
		resto = tamanhoBinario % 8;

	for (indice = 0; indice < (8 - resto); indice++)
		strcat (binario, string);

	for (indice = 0; indice < strlen (binario); indice += 8)
	{

		resultado = (binario [indice] - '0') * 128;

		resultado += (binario [indice + 1] - '0') * 64;
		resultado += (binario [indice + 2] - '0') * 32;
		resultado += (binario [indice + 3] - '0') * 16;
		resultado += (binario [indice + 4] - '0') * 8;
		resultado += (binario [indice + 5] - '0') * 4;
		resultado += (binario [indice + 6] - '0') * 2;
		resultado += (binario [indice + 7] - '0');

		conjuntoBytes [indice / 8] = resultado;

	}

	conjuntoBytes [indice / 8] = EOS;

	return ok;

}

/* $RCSfile: aula0801.c,v $ */
