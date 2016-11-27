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

char *fcssUmlCliErrorMessages [languageAmount][errorCodeAmountCli] = 
{
	{
		"OK",
	}
	{
		"Sucesso",
	}
};

char *fcssUmlNcursesErrorMessages [languageAmount][errorCodeAmountNcurses] = 
{
	{
		"OK"
	}
	{
		"Sucesso"
	}
};

char *fcssUmlWebErrorMessages [languageAmount][errorCodeAmountCgi] = 
{
	{
		"OK"
	}
	{
		"Sucesso"
	}
};

char *
FcssUmlGetCliErrorMessage (fcssUmlErrortype error, fcssUmlLanguageType language)
{
	return (fcssUmlCliErrorMessages[(unsigned)language][(unsigned)error]);
}

char *
FcssUmlGetNcursesErrorMessage (fcssUmlErrortype error, fcssUmlLanguageType language)
{
	return (fcssUmlNcursesErrorMessages[(unsigned)language][(unsigned)error]);
}

char *
FcssUmlGetWebErrorMessage (fcssUmlErrortype error, fcssUmlLanguageType language)
{
	return (fcssUmlWebErrorMessages[(unsigned)language][(unsigned)error]);
}


/* $RCSfile$ */