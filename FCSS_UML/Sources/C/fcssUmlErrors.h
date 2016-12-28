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

#ifndef FCSSUMLERRORS_H
#define FCSSUMLERRORS_H "@(#)fcssUmlErrors.h $Revisions$"

#include "fcssUmlConst.h"
#include "fcssUmlTypes.h"

typedef enum
{
	FCSS_UML_OK,
	FCSS_UML_CONFIGURATION_FILE_NOT_FOUND,
	FCSS_UML_INVALID_CGI_ENVIRONMENT_TYPE,
	FCSS_UML_ERROR_AMOUNT,
} fcssUmlErrorType;

char *
FcssUmlGetCliErrorMessage (fcssUmlErrorType error, fcssUmlLanguageType language);

char *
FcssUmlGetNcursesErrorMessage (fcssUmlErrorType error, fcssUmlLanguageType language);

char *
FcssUmlGetWebErrorMessage (fcssUmlErrorType error, fcssUmlLanguageType language);

#endif

/* $RCSfile$ */
