/*Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2016/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Felipe Claudio da Silva Santos

$Author$
$Date$
$Log$
*/ 

#include "fcssUmlUserInterface.h"

char *fcssUmlCliUserInterfaceMessages [fcssUmlLanguagesAmount][1] = 
{
	{
		"OK",
	},
	{
		"Sucesso",
	}
};

char *fcssUmlNcursesUserInterfaceMessages [fcssUmlLanguagesAmount][1] = 
{
	{
		"OK",
	},
	{
		"Sucesso",
	}
};

char *fcssUmlCgiUserInterfaceMessages [fcssUmlLanguagesAmount][FCSS_UML_CGI_MAIN_TEXTS] = 
{
  {
    "Change Language",
    "Sign In",
    "Reset Password",
    "Help",
    "License",
    "Username",
    "Password",
    "Send",
    "Uml - Initial Page",
    "Designed by: Felipe Claudio da Silva Santos",
    "Email: felipesantos956ATpoli.ufrj.br",
    "Full Name",
    "Full Name Confirmation",
    "Email",
    "Email Confirmation",
    "Generic help text",
    "License text",
    "English",
    "Portuguese",
    "Main Page"
  },
  {
    "Mudar Linguagem",
    "Cadastrar",
    "Resetar Senha",
    "Ajuda",
    "Licen&ccedila",
    "Nome do Usuario",
    "Senha",
    "Enviar",
    "P&aacutegina Inicial - BGU",
    "Feito por: Felipe Claudio da Silva Santos",
    "Email: felipesantos956ARROBApoli.ufrj.br",
    "Nome Completo",
    "Confirma&ccedil&atildeo do Nome Completo",
    "Email",
    "Confirma&ccedil&atildeo do Email",
    "Texto gen&eacuterico de ajuda",
    "Texto da Licen&ccedila",
    "Ingl&ecircs",
    "Portugu&ecircs",
    "P&aacutegina Principal"
  }
};

char *
FcssUmlGetCliUserInterfaceMessage (fcssUmlUserInterfaceMessageNumberType message, fcssUmlLanguageType language)
{
	return (fcssUmlCliUserInterfaceMessages[message][language]);
}

char *
FcssUmlGetNcursesUserInterfaceMessage (fcssUmlUserInterfaceMessageNumberType message, fcssUmlLanguageType language)
{
	return (fcssUmlNcursesUserInterfaceMessages[message][language]);
}

char *
FcssUmlGetWebUserInterfaceMessage (fcssUmlUserInterfaceMessageNumberType message, fcssUmlLanguageType language)
{
	return (fcssUmlCgiUserInterfaceMessages[message][language]);
}

/* $RCSfile$ */