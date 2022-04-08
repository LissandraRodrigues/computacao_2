/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Implementacao das funcoes de gerar
 *			      o digito verificador do RG e validacao
 *            do RG com entradas string.
 *
 * $Author: luiza.rosa $
 * $Date: 2022/01/17 00:48:00 $
 * $Log: aula0504.c,v $
 * Revision 1.5  2022/01/17 00:48:00  luiza.rosa
 * Programa: Atualizacao da descricao.
 *
 * Revision 1.4  2022/01/16 23:25:28  luiza.rosa
 * Programa: Atualizacao da descricao do programa.[
 *
 * Revision 1.3  2022/01/16 23:21:26  luiza.rosa
 * Programa: Insercao da implementacao da funcao Validar RG.
 *
 * Revision 1.2  2022/01/16 13:54:54  luiza.rosa
 * Programa: Correcao do programa e insercao de melhores praticas de programacao.
 *
 * Revision 1.1  2022/01/15 01:29:18  luiza.rosa
 * Initial revision
 *
*/

#include "aula0504.h"

#define COMPRIMENTO_RG														9

tipoErros
GerarDigitosVerificadoresRg (char *rg, char *digito)
{

	unsigned contador,
					 resultado = 0,
					 peso = 2;

	for (contador = 0; contador < (COMPRIMENTO_RG - 1); contador++)
	{
		resultado += (peso * (rg [contador] - '0'));
		peso++;
	}
	
	resultado %= 11;
	resultado = 11 - resultado;

	*digito = resultado + '0'; 	

	return sucesso;
	
}

tipoErros
ValidarRg (char *rg)
{
	
	char rgAnalisado [COMPRIMENTO_RG];

	unsigned indice;

	char digito;

	tipoErros resultado = valido;

	for (indice = 0; indice < (COMPRIMENTO_RG - 1); indice++)
		rgAnalisado [indice] = rg [indice];

	GerarDigitosVerificadoresRg (rgAnalisado, &digito);

	if (digito != rg [8])
		resultado = invalido;
	
	return resultado;
}

/* $RCSfile: aula0504.c,v $ */
