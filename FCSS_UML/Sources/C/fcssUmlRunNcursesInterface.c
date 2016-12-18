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
void fcssUmlPrintMenu  					(WINDOW *menu, int highlight, int n_choices, char *choices[]);
void fcssUmldrawTopBar 					(WINDOW *topBar, char menuName[], int numberOfRows);
void fcssUmldrawFooter 					(WINDOW *footer, char footerContent[], int numberOfRows, int numberOfColumns);
/*must normalize this part above*/

fcssUmlErrorType
fcssUmlRunNcursesInterface (fcssUmlConfigurationOptionsType *configurationOptions, 
 														char *nickName, fcssUmlLanguageType language)
{	
	WINDOW *menu;
	WINDOW *topBar;
	WINDOW *footer;
	int highlight = 1;
	int choice = 0;
	int c;
	int heightBar = 1;
	int widthBar;
	char menuName[100];
	char footerContent[100];
	int numberOfRows, numberOfColumns;
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
	fcssUmlPrintMenu(menu, highlight, n_choices, choices);
	fcssUmldrawTopBar (topBar, menuName, numberOfColumns);
	fcssUmldrawFooter (footer, footerContent, numberOfColumns, numberOfRows);
	keypad(menu, TRUE);

	while(1)
	{	c = wgetch(menu);
		switch(c)
		{	case KEY_UP:
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
			case 10:
				choice = highlight;
				break;
			default:
				/*TODO - must print some error*/
				break;
		}
		fcssUmlPrintMenu(menu, highlight, n_choices, choices);
		fcssUmldrawTopBar (topBar, menuName, numberOfColumns);
		fcssUmldrawFooter (footer, footerContent, numberOfColumns, numberOfRows);
		if(choice != 0)	/* User did a choice come out of the infinite loop */
			break;
	}	
	mvprintw(23, 0, "You chose choice %d with choice string %s\n", choice, choices[choice - 1]);
	getch();
	clrtoeol();
	refresh();
	endwin();
	return (OK);
}

void fcssUmlInitializeWindows		(WINDOW **menu, WINDOW **topBar, WINDOW **footer, int heightBar, int widthBar, int numberOfColumns, int numberOfRows, char *choices[])
{
	*topBar = newwin (heightBar, widthBar - 5, 1, 1);
	*footer = newwin (heightBar + 4, widthBar - 5, numberOfRows - 6, 1);
	*menu =   newwin (numberOfRows, numberOfColumns, 0, 0);
}

void fcssUmlPrintMenu(WINDOW *menu, int highlight, int n_choices, char *choices[])
{
	int x, y, i;	

	x = 2;
	y = 3;
	box(menu, 0, 0);
	for(i = 0; i < n_choices; ++i)
	{	if(highlight == i + 1) /* High light the present choice */
		{	wattron(menu, A_REVERSE); 
			mvwprintw(menu, y, x, "%s", choices[i]);
			wattroff(menu, A_REVERSE);
		}
		else
			mvwprintw(menu, y, x, "%s", choices[i]);
		++y;
	}
	wrefresh(menu);
}

void fcssUmldrawTopBar (WINDOW *topBar, char menuName[], int numberOfColumns)
{
	int centerX = (numberOfColumns/2) - (strlen(menuName)/2);

	printf("centerX: %d\n", centerX);
	wclear(topBar);
	wbkgd(topBar, COLOR_PAIR(1));
	mvwprintw(topBar, 0, centerX, "%s", menuName);
	wrefresh(topBar);
}

void fcssUmldrawFooter (WINDOW *footer, char footerContent[], int numberOfColumns, int numberOfRows)
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
/* $RCSfile$ */