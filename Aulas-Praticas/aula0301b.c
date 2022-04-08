/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Programa que exibe o MDC entre dois numeros  
 *						se utilizando da estrutura de repeticao
 *						Do... While. 
 *
 * $Author: luiza.rosa $
 * $Date: 2021/12/14 17:57:30 $
 * $Log: aula0301b.c,v $
 * Revision 1.1  2021/12/14 17:57:30  luiza.rosa
 * Initial revision
 *
*/

#include "aula0301.h"

ull
CalcularMaximoDivisorComum (ull numero1, ull numero2)
{

	ull restoDivisao;
	
	if (!numero1 && !numero2)
		return 0;

	if (!numero1)
		return numero2;
	
	if (!numero2)	
		return numero1;
	
	do
	{

		restoDivisao = numero1 % numero2;
		numero1 = numero2;
		numero2 = restoDivisao;

	}
	while (restoDivisao);
	
	return numero1;
	
}

/* $RCSfile: aula0301b.c,v $ */
