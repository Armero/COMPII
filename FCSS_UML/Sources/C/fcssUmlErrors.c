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
#include "fcssUmlTypes.h"

char *fcssUmlCliErrorMessages [fcssUmlLanguagesAmount][ERROR_AMOUNT] = 
{
	{
		"OK",
	},
	{
		"Sucesso",
	}
};

char *fcssUmlNcursesErrorMessages [fcssUmlLanguagesAmount][ERROR_AMOUNT] = 
{
	{
		"OK"
	},
	{
		"Sucesso"
	}
};

char *fcssUmlWebErrorMessages [fcssUmlLanguagesAmount][ERROR_AMOUNT] = 
{
	{
		"OK"
	},
	{
		"Sucesso"
	}
};

char *
FcssUmlGetCliErrorMessage (fcssUmlErrorType error, fcssUmlLanguageType language)
{
	return (fcssUmlCliErrorMessages[(unsigned)language][(unsigned)error]);
}

char *
FcssUmlGetNcursesErrorMessage (fcssUmlErrorType error, fcssUmlLanguageType language)
{
	return (fcssUmlNcursesErrorMessages[(unsigned)language][(unsigned)error]);
}

char *
FcssUmlGetWebErrorMessage (fcssUmlErrorType error, fcssUmlLanguageType language)
{
	return (fcssUmlWebErrorMessages[(unsigned)language][(unsigned)error]);
}


/* $RCSfile$ */
