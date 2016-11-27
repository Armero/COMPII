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

#ifndef FCSSUMLCONST_H
#define FCSSUMLCONST_H "@(#)fcssUmlConst.h $Revisions$"

#include "fcssUmlTypes.h"

fcssUmlLanguageType numberOfLanguages = 	fcssUmlLanguagesAmount;
byte languageAmount 									= 	(byte) numberOfLanguages;
const byte errorCodeAmountCli 				= 	1;
const byte errorCodeAmountNcurses 		= 	1;
const byte errorCodeAmountCgi 				= 	1;


#define SIZE_PORTUGUESE_OPTION						18

#define NICKANAME_LENGTH									65
#define PASSWORD_LENGTH										127
#define	FULL_NAME_LENGTH									512
#define	EMAIL_LENGTH											1024

#endif

/* $RCSfile$ */