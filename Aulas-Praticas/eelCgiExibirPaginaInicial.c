/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: CGI de exibir pagina inicial.
 *
 * $Author: luiza.rosa $
 * $Date: 2022/03/11 16:06:03 $
 * $Log: eelCgiExibirPaginaInicial.c,v $
 * Revision 1.1  2022/03/11 16:06:03  luiza.rosa
 * Initial revision
 *
*/

#ifdef __linux__
#define sistemaOperacional "Linux"
#define _XOPEN_SOURCE	600
#endif

#ifdef __FreeBSD__
#define sistemaOperacional "CentOS"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Bibliotecas/mlcgi.h"

#include "eelErros.h"
#include "eelTipos.h"
#include "eelInterfaceUsuario.h"

#define AMBIENTE_INVALIDO										1

#define COMPRIMENTO_MAXIMO									50

#define SUCESSO															0

int 
main (int argc, char **argv)
{

	unsigned retorno;

	environmentType variavelAmbiente;

	char idiomaString [COMPRIMENTO_MAXIMO + 1];

	eelTipoIdiomas idioma = eelPortugues;

	if ((retorno = mlCgiInitialize (&variavelAmbiente)) != ML_CGI_OK)
	{
		printf ("\nErro na inicializacao da CGI.\n\n");
		exit (ML_CGI_OK);
	}	
	
	if (variavelAmbiente != web)
	{
		printf ("\nAmbiente de execucao invalido.\n\n");
		exit (AMBIENTE_INVALIDO);
	}
	
	mlCgiBeginHttpHeader ("text/html");
	mlCgiEndHttpHeader ();

	retorno = mlCgiGetFormStringNoNewLines ("eelIdiomas", idiomaString, COMPRIMENTO_MAXIMO + 1);

	if (!strcmp ("eelIngles", idiomaString))
		idioma = eelIngles;

	if (retorno != ML_CGI_OK)
	{
		
		printf ("<html>");
		printf ("		<head>");
		printf ("				<title>");
		printf ("						EEL270");  
		printf ("				</title>");
		printf ("		</head>");
		printf ("		<style>");
		printf ("				body {");
		printf ("						background-color: #e6c418;");
		printf ("				}");
		printf ("				p {");
		printf ("						font-weight: bold;");
		printf ("				}");
		printf ("				table, .campo {");
		printf ("						width: 500px;");
		printf ("				}");
		printf ("				#rodape {");
		printf ("						margin-top: 30px;");
		printf ("				}");
		printf ("				#botao-submeter {");
		printf ("						margin: 10px;");
		printf ("						padding: 10px;");
		printf ("				}");
		printf ("		</style>");
		printf ("		<body bgcolor=\"#e6c418\">");
		printf ("				<div align=\"center\">");
		printf ("						<h1> Computacao II - Turma 2021/2 </h1>");
		printf ("				</div>");
		printf ("				<div align=\"center\">");
		printf ("						%s - %s", sistemaOperacional, EelObterMensagemInterfaceUsuarioCli (idioma, mensagem));
		printf ("						<br>");
		printf ("				</div>");
		printf ("       <form action=\"eelAutenticarUsuario.cgi\" method=\"post\">");
		printf ("						<table align=\"center\" border=\"2\">");
		printf ("								<tr>");
		printf ("										<input type=\"hidden\" name=\"eelIdioma\" value=\"%s\">", idiomaString);
		printf ("										<td align=\"left\">");
		printf ("												<a href=\"eelExibirPaginaInicial.cgi?eelIdioma=eelPortugues\"> Pagina Inicial - PT </a>");
		printf ("										</td>");
		printf ("										<td align=\"right\">");
		printf ("												<a href=\"eelExibirPaginaInicial.cgi?eelIdioma=%s\" bgcolor=> Pagina Inicial - EN </a>", idiomaString);
		printf ("										</td>");
		printf ("								</tr>");
		printf ("						<br> <br>");
		printf ("						</table>");
		printf ("						<br>");
		printf ("						<table align=\"center\" border=\"2\">");
		printf ("								<tr>");
		printf ("										<td>");
		printf ("												<p> Nome: </p>");
		printf ("												<input class=\"campo\" type=\"text\" name=\"eelUsuario\" minlength=\"3\" maxlength=\"65\">");
		printf ("										</td>");
		printf ("								</tr>");
		printf ("								<tr>");
		printf ("										<td>");
		printf ("												<p> Senha: </p>");
		printf ("												<input class=\"campo\" type=\"password\" name=\"eelSenha\" minlength=\"8\" maxlength=\"127\">");
		printf ("										</td>");
		printf ("								</tr>");
		printf ("								<tr>");
		printf ("										<td align=\"center\">");
		printf ("												<input id=\"botao-submeter\" type=\"submit\" value=\"Submeter\" border=\"2\">");
		printf ("										</td>");
		printf ("								</tr>");	
		printf ("						</table>");
		printf ("						<br>");
		printf ("						<table align=\"center\" border=\"2\">");
		printf ("								<tr>");
		printf ("										<td align=\"left\">");
		printf ("												<a href=\"eelExibirFormularioAtivacaoContaUsuario.cgi?eelIdioma=eelPortugues\"> Registrar </a>");
		printf ("										</td>");
		printf ("										<td align=\"right\">");
		printf ("												<a href=\"eelExibirFormularioReinicializacaoSenhaUsuario.cgi?eelIdioma=eelPortugues\"> Esqueci a senha </a>");
		printf ("										</td>");
		printf ("								</tr>");
		printf ("						</table>");
		printf ("				</form>");
		printf ("				<p id=\"rodape\" align=\"center\"> &copy; Feito por Luiza Lissandra </p>");
		printf ("		</body>");
		printf ("</html>");
		
	}

	return SUCESSO;
	
}

/* $RCSfile: eelCgiExibirPaginaInicial.c,v $ */
