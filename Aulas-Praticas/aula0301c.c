/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Programa que exibe o MDC entre dois numeros  
 *						se utilizando da estrutura de repeticao For. 
 *
 * $Author: luiza.rosa $
 * $Date: 2021/12/15 00:29:02 $
 * $Log: aula0301c.c,v $
 * Revision 1.1  2021/12/15 00:29:02  luiza.rosa
 * Initial revision
 *
*/

#include "aula0301.h"

ull
CalcularMaximoDivisorComum (ull numero1, ull numero2)
{

	ull restoDivisao, indice;
	
	if (!numero1 && !numero2)
		return 0;

	if (!numero1)
		return numero2;
	
	if (!numero2)	
		return numero1;
	
	for (indice = 0; indice <= numero1 && indice <= numero2; indice++)
	{

		restoDivisao = numero1 % numero2;
	
		if (restoDivisao)
		{
				
			numero1 = numero2;
			numero2 = restoDivisao;

		}
	
	}
	
	return numero2;
	
}

/* $RCSfile: aula0301c.c,v $ */
