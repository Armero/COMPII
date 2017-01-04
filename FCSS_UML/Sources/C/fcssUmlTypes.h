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

typedef enum
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


typedef unsigned long long 	fcssUmlUserIdentifierType;

typedef unsigned long long  fcssUmlProfileType;

typedef struct stuctFcssUmlUserDataType
{
	fcssUmlUserIdentifierType 						identifier;
	char 																	nickName [FCSS_UML_NICKNAME_LENGTH + 1];
	char 																	password [FCSS_UML_PASSWORD_LENGTH + 1];
	char 																	passwordConfirmation [FCSS_UML_PASSWORD_LENGTH + 1];
	fcssUmlProfileType 										profileType;
	char 																	fullName [FCSS_UML_FULL_NAME_LENGTH + 1];
	char 																	fullNameConfirmation [FCSS_UML_FULL_NAME_LENGTH + 1];
	char 																	email [FCSS_UML_EMAIL_LENGTH + 1];
	char 																	emailConfirmation [FCSS_UML_EMAIL_LENGTH + 1];
	struct stuctFcssUmlUserDataType 			*previous, *next;
} fcssUmlUserDataType;

typedef struct
{
	char rootDirectory 										[FCSS_UML_DIRECTORY_LENGTH + 1];
	char dataDirectory 										[FCSS_UML_DIRECTORY_LENGTH + 1];
	char cookiesDirectory 								[FCSS_UML_DIRECTORY_LENGTH + 1];
	fcssUmlUserIdentifierType				 			administratorIdentifier;
	char administratorEmail								[FCSS_UML_EMAIL_LENGTH + 1];
	char privateRootDirectory 						[FCSS_UML_DIRECTORY_LENGTH + 1];
	char usersDataFileName 								[FCSS_UML_FILENAME_LENGTH + 1];
	char invitedUsersDataFileName 				[FCSS_UML_FILENAME_LENGTH + 1];
	char requestingUsersDataFilename 			[FCSS_UML_FILENAME_LENGTH + 1];
	char lockedUsersDataFileName 					[FCSS_UML_FILENAME_LENGTH + 1];
} fcssUmlConfigurationOptionsType;

typedef enum 
{
	HELP,
	ADD_USER,
	NCURSES,
	CONFIGURE
} fcssFunctionSelect;

typedef enum 
{
	NOTHING_SELECTED_NCURSES = 0,
	HELP_NCURSES 						 		,
	ADD_USER_NCURSES						,
	EXIT_NCURSES
} fcssNcursesMenuOptions;

typedef enum
{
	OK_INTERFACE,
	MESSAGE_AMOUNT,
}
fcssUmlUserInterfaceMessageNumberType;

typedef enum
{
	ROOT_DIRECTORY,
	DATA_DIRECTORY,
	COOKIES_DIRECTORY,
	ADMINISTRATOR_USER,
	ADMINISTRATOR_EMAIL,
	PRIVATE_ROOT_DIRECTRY,
	USERS_DATA_FILENAME,
	INVITED_USERS_DATA_FLENAME,
	REQUESTING_USERS_DATA_FILENAME,
	LOCKED_USERS_DATA_FILENAME,
} fcssUmlConfigurationsName;

typedef enum
{
	fcssUmlDes							= 0,
	fcssUmlMd5 							= 1,
	fcssUmlSha256 					= 5,
	fcssUmlSha512						= 6,	
} fcssUmlCryptAlgorithms;

#endif

/* $RCSfile$ */
