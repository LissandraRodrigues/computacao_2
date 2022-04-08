/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Programa de testes da funcao de
 *            exibir conteudo do arquivo.
 *
 * $Author: luiza.rosa $
 * $Date: 2022/02/25 01:06:50 $
 * $Log: aula0902.c,v $
 * Revision 1.1  2022/02/25 01:06:50  luiza.rosa
 * Initial revision
 *
*/

#include <stdio.h>
#include <stdlib.h>

#include "aula0901.h"

#define SUCESSO																		0

#define NUMERO_ARGUMENTOS_INVALIDO								1
#define ERRO_EXIBICAO_CONTEUDO										2

#define NUMERO_ARGUMENTOS													2

int
main (int argc, char **argv) 
{

	tipoErros resultado;

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\nUso: %s <nome-arquivo> \n\n", argv [0]);	
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	resultado = ExibirConteudoArquivo (argv [1]);

	if (resultado != ok)
		exit (ERRO_EXIBICAO_CONTEUDO);

	return SUCESSO;		

}
/* $RCSfile: aula0902.c,v $ */	
