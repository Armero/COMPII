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

#include <string.h>
#include <stdio.h>
#include "fcssUmlTypes.h"
#include "fcssUmlConst.h"
#include "fcssUmlErrors.h"
#include "fcssUmlConfig.h"

fcssUmlLanguageType
FcssUmlGetLanguageIndex (char *language);

fcssUmlErrorType
FcssUmlGetConfigurationOptionsValues (char * fileName, fcssUmlConfigurationOptionsType *options);

#endif

/* $RCSfile$ */
