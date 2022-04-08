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
 *            do RG com entradas byte.
 *
 * $Author: luiza.rosa $
 * $Date: 2022/01/17 00:48:29 $
 * $Log: aula0501.c,v $
 * Revision 1.7  2022/01/17 00:48:29  luiza.rosa
 * Programa: Atualizacao da descricao.
 *
 * Revision 1.6  2022/01/17 00:35:41  luiza.rosa
 * Programa: Atualizacao da descricao.
 *
 * Revision 1.5  2022/01/16 15:25:12  luiza.rosa
 * Programa: Insercao de melhores praticas de programacao.
 *
 * Revision 1.4  2022/01/15 01:35:26  luiza.rosa
 * Programa: Insercao de melhores praticas de programacao.
 *
 * Revision 1.3  2022/01/14 01:44:25  luiza.rosa
 * Programa: Implementacao da funcao de validar RG.
 *
 * Revision 1.2  2022/01/13 19:01:16  luiza.rosa
 * Programa: Gera os digitos verificadores do RG.
 *
*/

#include "aula0501.h"

#define COMPRIMENTO_RG								9

tipoErros
GerarDigitosVerificadoresRg (byte rg [])
{

	unsigned contador;

	byte resultado = 0,
			 peso = 2;

	for (contador = 0; contador < 8; contador++)
	{
		resultado += (peso * (rg [contador]));
		peso++;
	}

	resultado %= 11;
	resultado = 11 - resultado;
	
	rg [8] = resultado;

	return sucesso;	
		
}

tipoErros
ValidarRg (byte rg [])
{

	byte rgAnalisado [COMPRIMENTO_RG];

	unsigned indice;

	tipoErros resultado = valido;
	
	for (indice = 0; indice < (COMPRIMENTO_RG - 1); indice++)
		rgAnalisado [indice] = rg [indice];
	
  GerarDigitosVerificadoresRg (rgAnalisado);

	if (rgAnalisado [8] != rg [8])
		resultado = invalido;
	 
	return resultado;

}

/* $RCSfile: aula0501.c,v $ */
