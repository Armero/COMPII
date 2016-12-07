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
	if ( !(strncmp(language, "portuguese", SIZE_PORTUGUESE_OPTION) ) ) 
		return (fcssUmlPortuguese);

	return (fcssUmlEnglish);
}

fcssUmlErrorType
FcssUmlGetConfigurationOptionsValues (char * fileName, fcssUmlConfigurationOptionsType *options)
{
	FILE *configurationFile;

  

	/*Ler as opcoes do arquivo - nao foi definido ainda como fazer*/
	/*fclose(configurationFile);*/
	return (OK);
}

/* $RCSfile$ */
