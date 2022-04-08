/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Programa que exibe MDC entre dois numeros  
 *						se utilizando de Recursividade. 
 *
 * $Author: luiza.rosa $
 * $Date: 2021/12/14 23:06:37 $
 * $Log: aula0301a.c,v $
 * Revision 1.2  2021/12/14 23:06:37  luiza.rosa
 * Programa: Insercao de melhores praticas de programacao.
 *
 * Revision 1.1  2021/12/14 16:49:49  luiza.rosa
 * Initial revision
 *
*/

#include "aula0301.h"

ull
CalcularMaximoDivisorComum (ull numero1, ull numero2)
{

	ull restoDivisao;

	if(!numero1 && !numero2)
		return 0;

	if (!numero1)
		return numero2;
	
	if (!numero2)
		return numero1;

	restoDivisao = numero1 % numero2;

	if (!restoDivisao)		
		return numero2;
	else 
		return CalcularMaximoDivisorComum (numero2, restoDivisao);

}

/* $RCSfile: aula0301a.c,v $ */
