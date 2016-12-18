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
#ifndef FCSSUMLRUNCURSESINTERFACE_H
#define FCSSUMLRUNCURSESINTERFACE_H "@(#)fcssRunNcursesInterface.h $Revisions$"

#include "fcssUmlTypes.h"
#include "fcssUmlErrors.h"
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

fcssUmlErrorType
fcssUmlRunNcursesInterface (fcssUmlConfigurationOptionsType *configurationOptions, 
 														char *nickName, fcssUmlLanguageType language); 

#endif

/* $RCSfile$ */