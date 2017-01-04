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

#define _XOPEN_SOURCE	500
#include <unistd.h>
#define _GNU_SOURCE
#include <crypt.h>
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
FcssUmlGetLanguageIndex 										(char *language);

fcssUmlErrorType
FcssUmlGetConfigurationOptionsValues 				(char *fileName, fcssUmlConfigurationOptionsType *options);

boolean
FcssUmlGetStringOptionFromFile							(FILE *configurationFile, char *temporaryString, unsigned index, char *defaultOptions[], int lineLength);

void
FcssUmlGetAbsolutFileName 									(char *string1, char *string2, char *outputString);

fcssUmlErrorType
FcssUmlCheckStringField 										(char * stringInput, char *validChars, size_t minimumLength, size_t maximumLegth);

fcssUmlErrorType
FcssUmlCheckNickname 												(char * stringInput, char *validChars, size_t minimumLength, size_t maximumLegth); 

fcssUmlErrorType
FcssumlCheckEmail 													(char *stringInput, char *validChars, size_t minimumLength, size_t maximumLegth);

fcssUmlErrorType		
FcssUmlCreateRandomString 									(char *validChars, size_t length, char *outputString);

fcssUmlErrorType
FcssUmlCreateNickname 											(char *fullName, char *firstOption, char *secondOption);

fcssUmlErrorType
FcssUmlGetCryptAlgorithm 										(char *passwordString, fcssUmlCryptAlgorithms *algorithmType);

fcssUmlErrorType
FcssUmlEncodePasswordWithSpecificAlgorithm 	(char *plainPassword, fcssUmlCryptAlgorithms algorithmType, char *encodedPassword);

fcssUmlErrorType
FcssUmlEncodePasswordWithSpecificSalt 			(char *plainPassword, char *salt, char *encodedPassword);

fcssUmlErrorType
FcssUmlCheckPassword 												(char *plainPassword, char *encodedPassword);
#endif

/* $RCSfile$ */