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

char *fcssUmlCliUserInterfaceMessages [fcssUmlLanguagesAmount][FCSS_UML_CLI_MAIN_TEXTS] = 
{
	{
		"OK"
	},
	{
		"Sucesso"
	}
};

char *fcssUmlNcursesUserInterfaceMessages [fcssUmlLanguagesAmount][FCSS_UML_NCURSES_MAIN_TEXTS] = 
{ 
    {
        "Help",
        "Add User",
        "Exit",
        "User Management Library",
        "Use UP ARROW and DOWN ARROW to select an option",
        "Use Enter to select an option",
        "Designed by: Felipe Claudio da Silva Santos"
    },
    {
        "Ajuda",
        "Adicionar Usuario",
        "Sair",
        "Biblioteca de Gerenciamento de Usarios",
        "Use as setas CIMA/BAIXO para selecionar uma opcao",
        "Use enter para selecionar uma opcao",
        "Feito por: Felipe Claudio da Silva Santos"
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
	return (fcssUmlCliUserInterfaceMessages[language][message]);
}

char *
FcssUmlGetNcursesUserInterfaceMessage (fcssUmlUserInterfaceMessageNumberType message, fcssUmlLanguageType language)
{
	return (fcssUmlNcursesUserInterfaceMessages[language][message]);
}

char *
FcssUmlGetWebUserInterfaceMessage (fcssUmlUserInterfaceMessageNumberType message, fcssUmlLanguageType language)
{
	return (fcssUmlCgiUserInterfaceMessages[language][message]);
}

/* $RCSfile$ */