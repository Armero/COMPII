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

typedef unsigned char fcssUmlErrorType;


char *
FcssUmlGetCliErrorMessage (fcssUmlErrortype error, fcssUmlLanguageType language);

char *
FcssUmlGetNcursesErrorMessage (fcssUmlErrortype error, fcssUmlLanguageType language);

char *
FcssUmlGetWebErrorMessage (fcssUmlErrortype error, fcssUmlLanguageType language);

#endif

/* $RCSfile$ */