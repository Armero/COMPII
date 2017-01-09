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
/*Mudar tudo para FCSS_UML_* */

#ifndef FCSSUMLCONST_H
#define FCSSUMLCONST_H "@(#)fcssUmlConst.h $Revisions$"


#define FCSS_UML_DIRECTORY_LENGTH										1024

#define FCSS_UML_NICKNAME_LENGTH										65
#define FCSS_UML_PASSWORD_LENGTH										127
#define	FCSS_UML_FULL_NAME_LENGTH										256
#define	FCSS_UML_EMAIL_LENGTH												1024
#define FCSS_UML_FILENAME_LENGTH										1024
#define FCSS_UML_NUMBER_LENGTH											10
#define FCSS_UML_DEFAULT_LINE_LENGTH								4096
#define FCSS_UML_OPTION_NAME_LENGTH									20
#define FCSS_UML_LANGUAGE_NAME_MAX_LENGTH						20

#define FCSS_UML_SHORT_OPTIONS											"hNC"//"hh:NN:Cai" /*LEMBRAR DESTE MALDITO :*/
#define	FCSS_UML_NUMBER_OF_SHORT_OPTIONS						20
#define FCSS_UML_NUMBER_OF_LONG_OPTIONS							20					

#define FCSS_UML_CONFIGURATION_FILE									"/home/felipe/FCSS_UML/Sources/C/fcss-uml.cfg"

#define NCURSES_NUMBER_OF_ROWS											24
#define NCURSES_NUMBER_OF_COLUMS										60

#define ENTER_KEY_PRESSED														10

#define FCSS_UML_TEXT_AMOUNT												1
#define FCSS_UML_NCURSES_NUMBER_OF_OPTIONS					3
#define FCSS_UML_NCURSES_NUMBER_OF_EXTRA_TEXT				4

#define FCSS_UML_CLI_MAIN_TEXTS											1
#define FCSS_UML_CGI_MAIN_TEXTS											20
#define FCSS_UML_NCURSES_MAIN_TEXTS									7

#define FCSS_UML_MD5_LENGTH_MINIMUM_LENGTH					22
#define FCSS_UML_SHA256_LENGTH_MINIMUM_LENGTH				43
#define FCSS_UML_SHA512_LENGTH_MINIMUM_LENGTH				86
#define FCSS_UML_SALT_LENGTH 												16

#define FCSS_UML_RANDOM_STRING_VALID_CHARACTERS			"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./"

#define FCSS_UML_END_SUBOPTIONS 										"XDG"

#define EOS 																				'\0'

#endif

/* $RCSfile$ */

