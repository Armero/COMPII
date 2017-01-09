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

/*#define _XOPEN_SOURCE	500*/
#include <unistd.h>
/*#define _GNU_SOURCE*/
/*#include <crypt.h>*/
#include "fcssUmlTypes.h"
#include "fcssUmlConst.h"
#include "fcssUmlErrors.h"
#include "fcssUmlConfig.h"
#include "fcssUmlUserInterface.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

/*---------------------------------------------------------------------------*/
/*
 *     Return the chosen language
 *		 Default return: fcssUmlEnglish
 *                      
 * Arguments:
 *      char *language (input)
 *
 * Returned Values:
 *      fcssUmlEnglish
 *      fcssUmlPortuguese
 * 
 */

fcssUmlLanguageType
FcssUmlGetLanguageIndex 										(char *language);


/*---------------------------------------------------------------------------*/
/*
 *     Intializes the fcssUmlConfigurationOptionType variable
 *		 Default configuration: argument defined in fcssUmlconfig.h
 *                      
 * Arguments:
 *      char *filename (input)
 *
 * Returned Values:
 *      FCSS_UML_CONFIGURATION_FILE_NOT_FOUND
 *      FCSS_UML_OK
 * 
 */
fcssUmlErrorType
FcssUmlGetConfigurationOptionsValues 				(char *fileName, fcssUmlConfigurationOptionsType *options);


/*---------------------------------------------------------------------------*/
/*
 *     Search for optional argument defined by *defaultOptions[index]
 *     in the file *configurationFile
 *	                    
 * Arguments:
 *      char *filename (input)
 *			fcssUmlConfigurationOptionsType *options (output)
 *
 * Returned Values:
 *      false - if exist the string  in *defaultOptions[index]
 *      true - if exist the string in *defaultOptions[index]
 * 
 */
boolean
FcssUmlGetStringOptionFromFile							(FILE *configurationFile, char *temporaryString, unsigned index, char *defaultOptions[], int lineLength);

/*---------------------------------------------------------------------------*/
/*		Concatenates *string1 and *string2 and copies it to *outputString
 *	                    
 * Arguments:
 *      char *string1 (input)
 *			char *string2 (input)
 *      char *outputString (output)
 *
 */
void
FcssUmlGetAbsolutFileName 									(char *string1, char *string2, char *outputString);


/*---------------------------------------------------------------------------*/
/*
 *     Checks if *stringInput has only charcters present in *validChars and
 *     has length between minimumLength and maximumLength
 *
 *                       
 * Arguments:
 *      char *stringInput (input)
 *      char *validChars  (input)
 *			size_t minimumLength (input)
 *      size_t maximumLength (input)
 *
 * Returned Values:
 *      FCSS_UML_OK - if *stringInput is valid
 *      FCSS_UML_EMPTY_STRING - if *stringInput or *validChars is empty
 *			FCSS_UML_STRING_WITH_INVALID_LENGTH - if *stringInput has invalid length
 * 			FCSS_UML_STRING_WITH_INVALID_CONTENT - if *stringInput is not valid
 * 
 */
fcssUmlErrorType
FcssUmlCheckStringField 										(char *stringInput, char *validChars, size_t minimumLength, size_t maximumLegth);


/*---------------------------------------------------------------------------*/
/*
 *     Checks if *stringInput has only charcters present in *validChars and
 *     has length between minimumLength and maximumLength
 *		 Also checks if *stringInput is a valid nickname
 *                       
 * Arguments:
 *      char *stringInput (input)
 *      char *validChars  (input)
 *			size_t minimumLength (input)
 *      size_t maximumLength (input)
 *
 * Returned Values:
 *      FCSS_UML_OK - if *stringInput is valid
 *      FCSS_UML_EMPTY_STRING - if *stringInput or *validChars is empty
 *			FCSS_UML_STRING_WITH_INVALID_LENGTH - if *stringInput has invalid length
 * 			FCSS_UML_STRING_WITH_INVALID_CONTENT - if *stringInput is not valid
 * 			FCSS_UML_INVALID_NICKNAME - if *stringInput is not a valid nickname
 * 
 */
fcssUmlErrorType
FcssUmlCheckNickname 												(char *stringInput, char *validChars, size_t minimumLength, size_t maximumLegth); 


/*---------------------------------------------------------------------------*/
/*
 *     Checks if *stringInput has only charcters present in *validChars and
 *     has length between minimumLength and maximumLength
 *		 Also checks if *stringInput is a valid email
 *                       
 * Arguments:
 *      char *stringInput (input)
 *      char *validChars  (input)
 *			size_t minimumLength (input)
 *      size_t maximumLength (input)
 *
 * Returned Values:
 *      FCSS_UML_OK - if *stringInput is valid
 *      FCSS_UML_EMPTY_STRING - if *stringInput or *validChars is empty
 *			FCSS_UML_STRING_WITH_INVALID_LENGTH - if *stringInput has invalid length
 * 			FCSS_UML_STRING_WITH_INVALID_CONTENT - if *stringInput is not valid
 * 			FCSS_UML_INVALID_EMAIL - if *stringInput is not a valid email
 * 
 */
fcssUmlErrorType
FcssumlCheckEmail 													(char *stringInput, char *validChars, size_t minimumLength, size_t maximumLegth);


/*---------------------------------------------------------------------------*/
/*
 *     Checks if *stringInput has only charcters present in *validChars and
 *     has length between minimumLength and maximumLength
 *		 Also checks if *stringInput is a valid email
 *                       
 * Arguments:
 *      char *validChars  (input)
 *			size_t length (input)
 *      size_t outputString (output)
 *
 * Returned Values:
 *      FCSS_UML_OK - if *stringInput if string could be generated with sucess
 *      FCSS_UML_EMPTY_STRING - if *validChars is empty
 * 
 */
fcssUmlErrorType		
FcssUmlCreateRandomString 									(char *validChars, size_t length, char *outputString);


/*---------------------------------------------------------------------------*/
/*
 *     Uses *fullName to generate nickNames
 *                       
 * Arguments:
 *      char *fullName  (input)
 *			char *firstOption (output) - firstName.Lastname
 *			char *secondOption (output) - firtaName.NameBeforLastName (if *fullName has only first and last name, *secondOption = NULL)
 *
 * Returned Values:
 *      FCSS_UML_OK - if *stringInput if string could be generated with sucess
 *      FCSS_UML_EMPTY_STRING - if *stringInput or *validChars is empty
 *      FCSS_UML_NOT_FULL_NAME - if *fullName is not a full name
 *
 */ 
fcssUmlErrorType
FcssUmlCreateNickname 											(char *fullName, char *firstOption, char *secondOption);

/*---------------------------------------------------------------------------*/
/*
 *     Detect which crypt algorithm was used to encode *passwordString
 *                       
 * Arguments:
 *      char *passwordString  (input)
 *			fcssUmlCryptAlgorithms *algorithmType (output)
 *
 * Returned Values:
 *      FCSS_UML_OK - if it was possible to detect which crypt algorithm was used
 *      FCSS_UML_EMPTY_STRING - if *passwordString is empty
 * 
 */
fcssUmlErrorType
FcssUmlGetCryptAlgorithm 										(char *passwordString, fcssUmlCryptAlgorithms *algorithmType);

/*---------------------------------------------------------------------------*/
/*
 *     Encode *plainPassword with crypt algorithm defined by algorithmType
 *                       
 * Arguments:
 *      char *plainPassword  (input)
 *			fcssUmlCryptAlgorithms *algorithmType (input)
 *      char *encodedPassword (output)
 *
 * Returned Values:
 *      FCSS_UML_OK - if it was possible to encode *plainPassword with especified crypt algorithm
 *      FCSS_UML_EMPTY_STRING - if *passwordString is empty
 * 
 */
fcssUmlErrorType
FcssUmlEncodePasswordWithSpecificAlgorithm 	(char *plainPassword, fcssUmlCryptAlgorithms algorithmType, char *encodedPassword);


/*---------------------------------------------------------------------------*/
/*
 *     Encode *plainPassword with salt defined by *salt
 *                       
 * Arguments:
 *      char *plainPassword  (input)
 *			char *salt (input)
 *      char *encodedPassword (output)
 *
 * Returned Values:
 *      FCSS_UML_OK - if it was possible to encode *plainPassword with especified salt
 *      FCSS_UML_EMPTY_STRING - if *passwordString is empty
 * 
 */
fcssUmlErrorType
FcssUmlEncodePasswordWithSpecificSalt 			(char *plainPassword, char *salt, char *encodedPassword);

/*---------------------------------------------------------------------------*/
/*
 *     Check if *plainPassword is equal (after encoding) to *encodedPassword
 *                       
 * Arguments:
 *      char *plainPassword  (input)
 *			char *salt (input)
 *      char *encodedPassword (output)
 *
 * Returned Values:
 *      FCSS_UML_OK - if *plainPassword is equal (after encoding) to *encodedPassword
 *      FCSS_UML_EMPTY_STRING - if *plainPassword or *encodedPassword is empty
 * 			FCSS_UML_WRONG_PASSWORD - if *plainPassword is incorrect
 * 
 */
fcssUmlErrorType
FcssUmlCheckPassword 												(char *plainPassword, char *encodedPassword);

/*---------------------------------------------------------------------------*/
/*
 *     Initialize the main Ncurses windows
 *                       
 * Arguments:
 *      char **menu  (output) - main screen
 *			char **topBar (output) - top bar of menu
 *      char **footer (output) -  bottom bar of menu
 *      int heightBar (input) - height of the bar present in **topBar and **footer
 *      int widthBar (input)- width of the bar present in **topBar and **footer
 *      int numberOfColumns (input) - number of columns used in terminal
 *      int numberOfRows (input) - number of rows used in terminal
 * 
 */
void 
FcssUmlInitializeNcursesWindows				(WINDOW **menu, WINDOW **topBar, WINDOW **footer, int heightBar, int widthBar, int numberOfColumns, int numberOfRows);


/*---------------------------------------------------------------------------*/
/*
 *     Draws main menu and highlight chosen option
 *                       
 * Arguments:
 *      char *menu  (input) - main screen
 *			char *highlight (input) - option to highlight
 *      fcssUmlLangueType language (input) -  language to write the option
 *      int heightBar (input) - height of the bar present in **topBar and **footer
 * 
 */
void 
FcssUmlDrawNcursesMenu								(WINDOW *menu, int highlight, int n_choices, fcssUmlLanguageType language);


/*---------------------------------------------------------------------------*/
/*
 *     Draws top bar
 *                       
 * Arguments:
 *      char *menu  (input) - main screen
 *			int numberOfColumns (input) - number of columns used by interface
 *      fcssUmlLangueType language (input) -  language to write the option
 * 
 */
void 
FcssUmlDrawNcursesTopBar 							(WINDOW *topBar, int numberOfColumns, fcssUmlLanguageType language);

/*---------------------------------------------------------------------------*/
/*
 *     Draws top bar
 *                       
 * Arguments:
 *      char *menu  (input) - main screen
 *			int numberOfColumns (input) - number of columns used by interface
 *			int numberOfRows (input) - number of rows used by interface
 *      fcssUmlLangueType language (input) -  language to write the option
 * 
 */
void 
FcssUmlDrawNcursesFooter 							(WINDOW *footer, int numberOfColumns, int numberOfRows, fcssUmlLanguageType language);

/*---------------------------------------------------------------------------*/
/*
 *     Closes the interface
 */
void 
FcssUmlCloseNcursesInterface					();
#endif

/* $RCSfile$ */
