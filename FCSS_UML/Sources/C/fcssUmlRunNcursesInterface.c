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
#include "fcssUmlRunNcursesInterface.h"

fcssUmlErrorType
FcssUmlRunNcursesInterface (fcssUmlConfigurationOptionsType *configurationOptions, 
 														char *nickName, fcssUmlLanguageType language)
{	
	WINDOW *menu;
	WINDOW *topBar;
	WINDOW *footer;
	unsigned highlight = 1;
	fcssNcursesMenuOptions choiceInterface = NOTHING_SELECTED_NCURSES;
	int keyboard;
	int heightBar = 1;
	int widthBar;
	int numberOfRows, numberOfColumns;
	boolean closeInterface = false;

  const unsigned numberOfChoices = FCSS_UML_NCURSES_NUMBER_OF_OPTIONS;
	numberOfRows = NCURSES_NUMBER_OF_ROWS;
	numberOfColumns = NCURSES_NUMBER_OF_COLUMS;
	widthBar = numberOfColumns;

	initscr();
	clear();
	noecho();
	cbreak();	/* Line buffering disabled. pass on everything */
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	FcssUmlInitializeNcursesWindows(&menu, &topBar, &footer, heightBar, widthBar, numberOfColumns, numberOfRows);

	keypad(menu, TRUE);

	while(!closeInterface)
	{	
		FcssUmlDrawNcursesMenu		(menu, highlight, numberOfChoices, language);
		FcssUmlDrawNcursesTopBar 	(topBar, numberOfColumns, language);
		FcssUmlDrawNcursesFooter 	(footer, numberOfColumns, numberOfRows, language);
		keyboard = wgetch(menu);
		switch(keyboard)
		{	
			case KEY_UP:
				if(highlight == 1)
					highlight = numberOfChoices;
				else
					--highlight;
				break;
			case KEY_DOWN:
				if(highlight == numberOfChoices)
					highlight = 1;
				else 
					++highlight;
				break;
			case ENTER_KEY_PRESSED:
				choiceInterface = (fcssNcursesMenuOptions) highlight;
				break;
			default:
				/*TODO - must print some error*/
				break;
		}
		if (choiceInterface != NOTHING_SELECTED_NCURSES)
		{
			switch (choiceInterface)
			{
				case (HELP_NCURSES):
					refresh(); /* DO NOT REMOVE THIS REFRESH - it make things work */
					FcssUmlShowNcursesHelp (configurationOptions, language, numberOfRows, numberOfColumns);
					choiceInterface = NOTHING_SELECTED_NCURSES;
				break;
				case (EXIT_NCURSES):
					closeInterface = true;
				break;
				default:
				break;
			}
		}
	}	
	FcssUmlCloseNcursesInterface(numberOfColumns, numberOfRows);
	return (OK);
}

/* $RCSfile$ */
