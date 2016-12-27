/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 *
 * EEL270 - Computacao II - Turma 2016/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * $Author$
 * $Date$
 * $Log$
 *
 */

#include "fcssUmlConst.h"
#include "fcssUmlTypes.h"
#include "fcssUmlErrors.h"
#include "Libraries/mlcgi.h"
#include "fcssUmlCgiTexts.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int
main (int argc, char *argv[])
{
  char stringConfigurationFileName [FCSS_UML_FILENAME_LENGTH + 1];
  char stringLanguage [FCSS_UML_LANGUAGE_NAME_MAX_LENGTH + 1];
  unsigned returnCode;
  environmentType environment;
  fcssUmlLanguageType language;

  /*error in initialization*/
  if ((mlCgiInitialize(&environment)))
  {
    exit (ML_CGI_OK);
  }

  if (environment == commandLine)
  {
    /*Shoulf print some error message*/
    return (FCSS_UML_INVALID_CGI_ENVIRONMENT_TYPE);
  }

  if ( (returnCode = mlCgiGetFormStringNoNewLines ("configurationFile", stringConfigurationFileName, FCSS_UML_FILENAME_LENGTH + 1)) )
  {
    /*Should print some error*/
    return (ML_CGI_OK);
  }

  if ( (returnCode = mlCgiGetFormStringNoNewLines ("language", stringLanguage, FCSS_UML_FILENAME_LENGTH + 1)) )
  {
    /*Should print some error*/
    return (ML_CGI_OK);
  }

  language = !strcmp(stringLanguage, "portuguese")?fcssUmlPortuguese:fcssUmlEnglish;

  mlCgiBeginHttpHeader ("text/html");
  mlCgiEndHttpHeader ();

  printf("<html>\n");
  printf("<head>\n");
  printf("  <title>%s</title>\n", cgiText[language][8]);
  printf("</head>\n");
  printf("<body>\n");
  printf("  <div align=\"center\">\n");
  printf("    <a href=\"./fcssUmlCgiMain.cgi?configurationFile=%s&language=%s\">%s</a>\n",
                                                                                  stringConfigurationFileName,
                                                                                  stringLanguage,
                                                                                  cgiText[language][19] );
  printf("    <a href=\"./fcssUmlMain.cgi?configurationFile=%s&language=%s\">%s</a>\n",
                                                                                    stringConfigurationFileName,
                                                                                    stringLanguage,
                                                                                    cgiText[language][0] );
  printf("    <a href=\"./fcssUmlShowRequestRegistrationForm.cgi?configurationFile=%s&language=%s\">%s</a>\n",
                                                                                    stringConfigurationFileName,
                                                                                    stringLanguage,
                                                                                    cgiText[language][1] );
  printf("    <a href=\"resetPassword\">%s</a>\n", cgiText[language][2]);
  printf("    <a href=\"./fcssUmlShowWebHelp.cgi?configurationFile=%s&language=%s\">%s</a>\n",
                                                                                    stringConfigurationFileName,
                                                                                    stringLanguage,
                                                                                    cgiText[language][3] );
  printf("    <a href=\"./fcssUmlShowLicense.cgi?configurationFile=%s&language=%s\">%s</a>\n",
                                                                                    stringConfigurationFileName,
                                                                                    stringLanguage,
                                                                                    cgiText[language][4] );
  printf("  </div>\n");
  printf("  <div align=\"center\">\n");
  printf("    <a href=\"./fcssUmlCgiMain.cgi?configurationFile=%s&language=%s\">%s</a><br>\n",
                                                                                    stringConfigurationFileName,
                                                                                    "english",
                                                                                    cgiText[language][17] );
  printf("    <a href=\"./fcssUmlCgiMain.cgi?configurationFile=%s&language=%s\">%s</a>\n",
                                                                                    stringConfigurationFileName,
                                                                                    "portuguese",
                                                                                    cgiText[language][18] );
  printf("  </div>\n");
  printf("  <div align=\"center\" bgcolor=\"gray\">\n");
  printf("    <br>%s<br>\n", cgiText[language][9]);
  printf("    %s<br>\n", cgiText[language][10]);
  printf("  </div>\n");
  printf("</body>\n");
  printf("</html>\n");

  mlCgiFreeResources ();
  exit (ML_CGI_OK);
}

/* $RCSfile$ */