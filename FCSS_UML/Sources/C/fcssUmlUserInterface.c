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

char *fcssUmlCliUserInterfaceMessages [languageAmount][errorCodeAmountCli] = 
{
	{
		"OK",
	}
	{
		"Sucesso",
	}
};

char *fcssUmlNcursesUserInterfaceMessages [languageAmount][errorCodeAmountCli] = 
{
	{
		"OK",
	}
	{
		"Sucesso",
	}
};

char *fcssUmlCgiUserInterfaceMessages [languageAmount][errorCodeAmountCli] = 
{
	{
		"OK",
	}
	{
		"Sucesso",
	}
};

char *
fcssUmlGetCliUserInterfaceMessage (fcssUmlUserInterfaceMessageNumberType message, fcssUmlLanguageType language)
{
	return (fcssUmlCliUserInterfaceMessages[(unsigned) language][message]);
}

char *
fcssUmlGetNcursesUserInterfaceMessage (fcssUmlUserInterfaceMessageNumberType message, fcssUmlLanguageType language)
{
	return (fcssUmlNcursesUserInterfaceMessages[(unsigned) language][message]);
}

char *
fcssUmlGetWebUserInterfaceMessage (fcssUmlUserInterfaceMessageNumberType message, fcssUmlLanguageType language)
{
	return (fcssUmlCgiUserInterfaceMessages[(unsigned) language][message]);
}

/* $RCSfile$ */