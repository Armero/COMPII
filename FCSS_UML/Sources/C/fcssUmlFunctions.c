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
#include "fcssUmlFunctions.h"

fcssUmlLanguageType
FcssUmlGetLanguageIndex (char *language)
{
	if ( !(strncmp(language, "fcssUmlPortuguese", SIZE_PORTUGUESE_OPTION) ) 
		return (fcssUmlPortuguese);

	return (fcssUmlEnglish);
}

/* $RCSfile$ */