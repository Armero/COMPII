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


#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>


/*must normalize this part below */
void fcssUmlInitializeWindows		(WINDOW **menu, WINDOW **topBar, WINDOW **footer, int heightBar, int widthBar, int numberOfColumns, int numberOfRows, char *choices[]);
void fcssUmlDrawMenu  					(WINDOW *menu, int highlight, int n_choices, char *choices[]);
void fcssUmlDrawTopBar 					(WINDOW *topBar, char menuName[], int numberOfRows);
void fcssUmlDrawFooter 					(WINDOW *footer, char footerContent[], int numberOfRows, int numberOfColumns);
void fcssUmlDrawHelp 						(int numberOfColumns, int numberOfRows);
void fcssUmlCloseInterface			();
/*must normalize this part above*/

fcssUmlErrorType
fcssUmlRunNcursesInterface (fcssUmlConfigurationOptionsType *configurationOptions, 
 														char *nickName, fcssUmlLanguageType language)
{	
	WINDOW *menu;
	WINDOW *topBar;
	WINDOW *footer;
	int highlight = 1;
	fcssNcursesMenuOptions choiceInterface = NOTHING_SELECTED_NCURSES;
	int keyboard;
	int heightBar = 1;
	int widthBar;
	char menuName[100];
	char footerContent[100];
	int numberOfRows, numberOfColumns;
	int counter= 0;
	boolean closeInterface = false;
	char *choices[] = 
	{ 
		"Help",
		"Add User",
		"Exit",
  };
	int n_choices = sizeof(choices) / sizeof(char *);

	numberOfRows = NCURSES_NUMBER_OF_ROWS;
	numberOfColumns = NCURSES_NUMBER_OF_COLUMS;
	widthBar = numberOfColumns;
	strcpy(menuName, "User Management Library"); 
	strcpy(footerContent, "Designed By: Felipe Claudio da Silva Santos"); 

	initscr();
	clear();
	noecho();
	cbreak();	/* Line buffering disabled. pass on everything */
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	fcssUmlInitializeWindows(&menu, &topBar, &footer, heightBar, widthBar, numberOfColumns, numberOfRows, choices);

	keypad(menu, TRUE);

	while(!closeInterface)
	{	
		fcssUmlDrawMenu(menu, highlight, n_choices, choices);
		fcssUmlDrawTopBar (topBar, menuName, numberOfColumns);
		fcssUmlDrawFooter (footer, footerContent, numberOfColumns, numberOfRows);
		keyboard = wgetch(menu);
		printf("Counter %d keyboard: %d\n", counter, keyboard);
		counter++;
		switch(keyboard)
		{	
			case KEY_UP:
				if(highlight == 1)
					highlight = n_choices;
				else
					--highlight;
				break;
			case KEY_DOWN:
				if(highlight == n_choices)
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
					fcssUmlDrawHelp		(numberOfColumns, numberOfRows);
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
	fcssUmlCloseInterface(numberOfColumns, numberOfRows);
	return (OK);
}

void fcssUmlInitializeWindows		(WINDOW **menu, WINDOW **topBar, WINDOW **footer, int heightBar, int widthBar, int numberOfColumns, int numberOfRows, char *choices[])
{
	*topBar = newwin (heightBar, widthBar - 5, 1, 1);
	*footer = newwin (heightBar + 4, widthBar - 5, numberOfRows - 6, 1);
	*menu =   newwin (numberOfRows, numberOfColumns, 0, 0);
}

void fcssUmlDrawMenu(WINDOW *menu, int highlight, int n_choices, char *choices[])
{
	int row, column, index;	

	row = 2;
	column = 3;
	box(menu, 0, 0);
	for(index = 0; index < n_choices; ++index)
	{	
		if(highlight == index + 1) /* Highlight the present choice */
		{	wattron(menu, A_REVERSE); 
			mvwprintw(menu, column, row, "%s", choices[index]);
			wattroff(menu, A_REVERSE);
		}
		else
			mvwprintw(menu, column, row, "%s", choices[index]);
		column++;
	}
	wrefresh(menu);
}

void fcssUmlDrawTopBar (WINDOW *topBar, char menuName[], int numberOfColumns)
{
	int centerX = (numberOfColumns/2) - (strlen(menuName)/2);

	wclear(topBar);
	wbkgd(topBar, COLOR_PAIR(1));
	mvwprintw(topBar, 0, centerX, "%s", menuName);
	wrefresh(topBar);
}

void fcssUmlDrawFooter (WINDOW *footer, char footerContent[], int numberOfColumns, int numberOfRows)
{
	int centerX = (numberOfColumns/2) - (strlen(footerContent)/2);

	wclear(footer);
	wbkgd(footer, COLOR_PAIR(1));
	mvwprintw(footer, 0, centerX, "Use UP ARROW and DOWN ARROW to move");
	mvwprintw(footer, 1, centerX, "Use Enter to select option");
	mvwprintw(footer, 4, centerX, "%s", footerContent);
	curs_set(0);
	wrefresh(footer);
}

void fcssUmlDrawHelp (int numberOfColumns, int numberOfRows)
{
	WINDOW *help;
	int row, column;	

	row = 2;
	column = 3;
	help = newwin (numberOfRows, numberOfColumns, 0, 0);
	wbkgd(help, COLOR_PAIR(1));
	box(help, 0, 0);
	mvwprintw(help, row, column, "%s", "This should help");
	wrefresh(help);
	getch();
	delwin(help);
}

void fcssUmlCloseInterface  ()
{
	clrtoeol();
	refresh();
	endwin();
}
/* $RCSfile$ */