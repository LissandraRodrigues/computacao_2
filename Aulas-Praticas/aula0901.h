/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Prototipo das funcoes de exibir conteudo de um arquivo,
 *            converter arquivo formato Unix para formato Dos e vice-versa,
 *            alem de definicoes de tipo.
 *
 * $Author: luiza.rosa $
 * $Date: 2022/03/02 20:41:11 $
 * $Log: aula0901.h,v $
 * Revision 1.4  2022/03/02 20:41:11  luiza.rosa
 * Programa: Prototipo da funcao de converter de Dos para Unix.
 *
 * Revision 1.3  2022/02/25 23:02:14  luiza.rosa
 * Programa: Correcao para versao linux.
 *
 * Revision 1.2  2022/02/25 20:47:06  luiza.rosa
 * Programa: Insercao do prototipo da funcao de converter formato unix para dos.
 *
 * Revision 1.1  2022/02/25 01:08:22  luiza.rosa
 * Initial revision
 *
*/

#ifndef _AULA0901_
#define _AULA0901_							 "@(#)aula0901.h $Revision: 1.4 $"
#endif

#ifdef __linux__
#define _BSD_SOURCE || _XOPEN_SOURCE >= 500 || _XOPEN_SOURCE && _XOPEN_SOURCE_EXTENDED
#endif

#define	EOS															          '\0'					

#define BUFFER																	  16
#define COMPRIMENTO_BUFFER												100

typedef enum
{ 

	ok,
	invalido,
	memoriaInsuficiente,
	erroLeitura

} tipoErros;

typedef unsigned char byte;

tipoErros 
ExibirConteudoArquivo (char * /* (E) */);

tipoErros
ConverterArquivoFormatoUnixParaFormatoDos (char *original, 
																					 char *convertido);

tipoErros
ConverterArquivoFormatoDosParaFormatoUnix (char *original, 
																					 char *convertido);

/* $RCSfile: aula0901.h,v $ */
