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
#include "fcssUmlShowCliHelp.h"
#include	<stdio.h>

void
FcssUmlShowCliHelp (fcssUmlConfigurationOptionsType *option, fcssUmlLanguageType language)
{
	if (language == fcssUmlEnglish)
	{
		printf("Generic help text\n");
	}

	if (language == fcssUmlPortuguese)
	{
		printf("Texto generico de ajuda\n");
	}	
	/*to complete*/
} 

/* $RCSfile$ */