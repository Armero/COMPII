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

#ifndef FCSSUMLUSERINTERFACE_H
#define FCSSUMLUSERINTERFACE_H "@(#)fcssUmlUserInterface.h $Revisions$"
#include "fcssUmlErrors.h"
#include "fcssUmlTypes.h"


char *
FcssUmlGetCliUserInterfaceMessage (fcssUmlUserInterfaceMessageNumberType message, fcssUmlLanguageType language);

char *
FcssUmlGetNcursesUserInterfaceMessage (fcssUmlUserInterfaceMessageNumberType message, fcssUmlLanguageType language);

char *
FcssUmlGetWebUserInterfaceMessage (fcssUmlUserInterfaceMessageNumberType message, fcssUmlLanguageType language); 

#endif

/* $RCSfile$ */