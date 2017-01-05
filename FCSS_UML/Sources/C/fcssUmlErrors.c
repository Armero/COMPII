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
#include "fcssUmlErrors.h"

char *fcssUmlCliErrorMessages [fcssUmlLanguagesAmount][FCSS_UML_ERROR_AMOUNT] = 
{
	{
		"OKA",
		"Couldn't find configuration file",
		"Invalid option",
		"Invalid suboption",
		"Invalid string length",
		"Empty string",
		"String with invalid content",
		"Invalid nickname",
		"Invalid email",
		"String is nota full name",
		"Wrong password"
	},
	{
		"Sucesso",
		"Arquivo de configuracao nao foi encontrado",
		"Opcao invalida",
		"Subopcao invalida",
		"Comprimento da string invalido",
		"String vazia",
		"String com conteudo invalido",
		"Apelido invalido",
		"Email invalido",
		"A string nao e um nome completo",
		"Senha incorreta"
	}
};

char *fcssUmlNcursesErrorMessages [fcssUmlLanguagesAmount][FCSS_UML_ERROR_AMOUNT] = 
{
	{
		"OKB",
	},
	{
		"Sucesso",
	}
};

char *fcssUmlWebErrorMessages [fcssUmlLanguagesAmount][FCSS_UML_ERROR_AMOUNT] = 
{
	{
		"OKC",
	},
	{
		"Sucesso",
	}
};

char *
FcssUmlGetCliErrorMessage (fcssUmlErrorType error, fcssUmlLanguageType language)
{
	return (fcssUmlCliErrorMessages[error][language]);
}

char *
FcssUmlGetNcursesErrorMessage (fcssUmlErrorType error, fcssUmlLanguageType language)
{
	return (fcssUmlNcursesErrorMessages[error][language]);
}

char *
FcssUmlGetWebErrorMessage (fcssUmlErrorType error, fcssUmlLanguageType language)
{
	return (fcssUmlWebErrorMessages[error][language]);
}


/* $RCSfile$ */
