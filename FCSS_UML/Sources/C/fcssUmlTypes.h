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

#ifndef FCSSUMLTYPES_H
#define FCSSUMLTYPES_H "@(#)fcssUmlTypes.h $Revisions$"

#include "fcssUmlConst.h"

typedef enum name
{
	false,
	true,
} boolean;

typedef enum 
{
	fcssUmlEnglish,
	fcssUmlPortuguese,
	fcssUmlLanguagesAmount,
} fcssUmlLanguageType;

typedef unsigned long long fcssUmlUserIdentifierType;

typedef unsigned long long  fcssUmlProfileType;

typedef struct 
{
	fcssUmlUserIdentifierType identifier;
	char 													nickName [NICKNAME_LENGTH + 1];
	char 													password [PASSWORD_LENGTH + 1];
	char 													passwordConfirmation [PASSWORD_LENGTH + 1];
	fcssUmlProfileType 						profileType;
	char 													fullName [FULL_NAME_LENGTH + 1];
	char 													fullNameConfirmation [FULL_NAME_LENGTH + 1];
	char 													email [EMAIL_LENGTH + 1];
	char 													emailConfirmation [EMAIL_LENGTH + 1];
	struct 												fcssUmlUserDataType *previous, *next;
} fcssUmlUserDataType;

typedef struct
{
} fcssUmlConfigurationOptionsType;

/*
 typedef struct option 
 {
     const char *name;
     int         has_arg;
     int        *flag;
     int         val;
 }	fcssLongOptions;
*/

typedef enum 
{
	HELP,
	ADD_USER,
} fcssFunctionSelect;

#endif

/* $RCSfile$ */
