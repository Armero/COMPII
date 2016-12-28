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

#ifndef FCSSUMLFUNCTIONS_H
#define FCSSUMLFUNCTIONS_H "@(#)fcssUmlFunctions.h $Revisions$"

#include "fcssUmlTypes.h"
#include "fcssUmlConst.h"
#include "fcssUmlErrors.h"
#include "fcssUmlConfig.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

fcssUmlLanguageType
FcssUmlGetLanguageIndex (char *language);

fcssUmlErrorType
FcssUmlGetConfigurationOptionsValues 	(char *fileName, fcssUmlConfigurationOptionsType *options);

boolean
FcssUmlGetStringOptionFromFile 				(FILE *configurationFile, char *temporaryString, unsigned index, char *defaultOptions[], int lineLength);

boolean
FcssUmlGetNumericOptionFromFile 			(FILE *configurationFile, unsigned *temporaryNumber, unsigned index, char *defaultOptions[], int lineLength);

void
FcssUmlGetAbsolutFileName 						(char *string1, char *string2, char *outputString);

fcssUmlErrorType
FcssUmlCheckStringField 							(char * stringInput, char *validChars, size_t minimumLength, size_t maximumLegth);

fcssUmlErrorType
FcssUmlCheckNickname 									(char * stringInput, char *validChars, size_t minimumLength, size_t maximumLegth); 

fcssUmlErrorType
FcssumlCheckEmail 										(char *stringInput, char *validChars, size_t minimumLength, size_t maximumLegth);

fcssUmlErrorType
FcssUmlCreateRandomString 						(char *validChars, size_t length, char *outputString);

fcssUmlErrorType
FcssUmlCreateNickname 								(char *fullName, char *firstOption, char *secondOption);

#endif

/* $RCSfile$ */
