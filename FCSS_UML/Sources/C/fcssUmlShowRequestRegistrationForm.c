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
#include "fcssUmlUserInterface.h"
#include "fcssUmlFunctions.h"
#include "Libraries/mlcgi.h"
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

  language = FcssUmlGetLanguageIndex (stringLanguage);

  mlCgiBeginHttpHeader ("text/html");
  mlCgiEndHttpHeader ();

  printf("<html>\n");
  printf("<head>\n");
  printf("  <title>%s</title>\n", FcssUmlGetWebUserInterfaceMessage(8, language));
  printf("</head>\n");
  printf("<body>\n");
  printf("  <div align=\"center\">\n");
  printf("    <a href=\"./fcssUmlCgiMain.cgi?configurationFile=%s&language=%s\">%s</a>\n",
                                                                                  stringConfigurationFileName,
                                                                                  stringLanguage,
                                                                                  FcssUmlGetWebUserInterfaceMessage(19, language) );

  printf("    <a href=\"./fcssUmlMain.cgi?configurationFile=%s&language=%s\">%s</a>\n",
                                                                                    stringConfigurationFileName,
                                                                                    stringLanguage,
                                                                                    FcssUmlGetWebUserInterfaceMessage(0, language) );

  printf("    <a href=\"./fcssUmlShowRequestRegistrationForm.cgi?configurationFile=%s&language=%s\">%s</a>\n",
                                                                                    stringConfigurationFileName,
                                                                                    stringLanguage,
                                                                                    FcssUmlGetWebUserInterfaceMessage(1, language) );
                                                                                  
  printf("    <a href=\"resetPassword\">%s</a>\n", FcssUmlGetWebUserInterfaceMessage(2, language) );
  printf("    <a href=\"./fcssUmlShowWebHelp.cgi?configurationFile=%s&language=%s\">%s</a>\n",
                                                                                    stringConfigurationFileName,
                                                                                    stringLanguage,
                                                                                    FcssUmlGetWebUserInterfaceMessage(3, language) );
                                                                                    
  printf("    <a href=\"./fcssUmlShowLicense.cgi?configurationFile=%s&language=%s\">%s</a>\n",
                                                                                    stringConfigurationFileName,
                                                                                    stringLanguage,
                                                                                    FcssUmlGetWebUserInterfaceMessage(4, language) );
  printf("  </div>\n");
  printf("  <div align=\"center\">\n");
  printf("    <form action=\"userInput.cgi\" method=\"post\"> \n");
  printf("      <table border=1 style=\"width:30%%\">\n");
  printf("        <tr>\n");
  printf("          <td>\n");
  printf("            %s\n", FcssUmlGetWebUserInterfaceMessage(11, language) );
  printf("          </td>\n");
  printf("          <td align=\"center\">\n");
  printf("            <input type=\"text\" name=\"fullName\" maxlength=256 size=20> <br>\n");
  printf("          </td>\n");
  printf("        </tr>\n");
  printf("        <tr>\n");
  printf("          <td>\n");
  printf("            %s\n", FcssUmlGetWebUserInterfaceMessage(12, language) );
  printf("          </td>\n");
  printf("          <td align=\"center\">\n");
  printf("            <input type=\"text\" name=\"fullNameConfirmation\" maxlength=256 size=20> <br>\n");
  printf("          </td>\n");
  printf("        </tr>\n");
  printf("        <tr>\n");
  printf("          <td>\n");
  printf("            %s\n", FcssUmlGetWebUserInterfaceMessage(13, language) );
  printf("          </td>\n");
  printf("          <td align=\"center\">\n");
  printf("            <input type=\"text\" name=\"email\" maxlength=1024 size=20> <br>\n");
  printf("          </td>\n");
  printf("        </tr>\n");
  printf("        <tr>\n");
  printf("          <td>\n");
  printf("            %s\n", FcssUmlGetWebUserInterfaceMessage(14, language) );
  printf("          </td>\n");
  printf("          <td align=\"center\">\n");
  printf("            <input type=\"text\" name=\"emailConfirmation\" maxlength=1024 size=20> <br>\n");
  printf("          </td>\n");
  printf("        </tr>\n");
  printf("        <tr>\n");
  printf("          <input type=\"hidden\"  name=\"htmlConfigurationFileName\">\n");
  printf("        </tr>\n");
  printf("        <tr>\n");
  printf("          <input type=\"hidden\" name=\"htmlLanguage\">\n");
  printf("        </tr>\n");
  printf("      </table>\n");
  printf("      <table border=1 style=\"width:30%%\">\n");
  printf("        <tr>\n");
  printf("          <td align=\"center\">\n");
  printf("            <input type=\"submit\" value=\"%s\"> <br>\n", FcssUmlGetWebUserInterfaceMessage(7, language) );
  printf("          </td>\n");
  printf("        </tr>\n");
  printf("      </table>\n");
  printf("    </form>\n");
  printf("  </div>\n");
  printf("  <div align=\"center\" bgcolor=\"gray\">\n");
  printf("    <br>%s<br>\n", FcssUmlGetWebUserInterfaceMessage(9, language) );
  printf("    %s<br>\n", FcssUmlGetWebUserInterfaceMessage(10, language) );
  printf("  </div>\n");
  printf("</body>\n");
  printf("</html>\n");

  mlCgiFreeResources ();
  exit (ML_CGI_OK);
}

/* $RCSfile$ */
