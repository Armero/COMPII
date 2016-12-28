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

#include "fcssUmlTypes.h"
#include "fcssUmlConst.h"
#include "fcssUmlErrors.h"
#include "fcssUmlConfig.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

void 
FcssUmlInitializeNcursesWindows				(WINDOW **menu, WINDOW **topBar, WINDOW **footer, int heightBar, int widthBar, int numberOfColumns, int numberOfRows);

void 
FcssUmlDrawNcursesMenu								(WINDOW *menu, int highlight, int n_choices, fcssUmlLanguageType language, char *choices[fcssUmlLanguagesAmount][FCSS_UML_NCURSES_NUMBER_OF_OPTIONS]);

void 
FcssUmlDrawNcursesTopBar 							(WINDOW *topBar, int numberOfColumns, fcssUmlLanguageType language, char *extraText[fcssUmlLanguagesAmount][FCSS_UML_NCURSES_NUMBER_OF_EXTRA_TEXT]);

void 
FcssUmlDrawNcursesFooter 							(WINDOW *footer, int numberOfColumns, int numberOfRows, fcssUmlLanguageType language, char *extraText[fcssUmlLanguagesAmount][FCSS_UML_NCURSES_NUMBER_OF_EXTRA_TEXT]);

void 
FcssUmlCloseNcursesInterface					();

#endif

/* $RCSfile$ */
