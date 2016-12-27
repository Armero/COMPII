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
#include "fcssUmlFunctions.h"
#include "fcssUmlShowNcursesHelp.h"
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


fcssUmlErrorType
FcssUmlRunNcursesInterface (fcssUmlConfigurationOptionsType *configurationOptions, 
 														char *nickName, fcssUmlLanguageType language); 

#endif

/* $RCSfile$ */
