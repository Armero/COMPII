#Universidade Federal do Rio de Janeiro
#Escola Politecnica
#Departamento de Eletronica e de Computacao
#EEL270 - Computacao II - Turma 2016/2
#Prof. Marcelo Luiz Drumond Lanza
#Autor: Felipe Claudio da Silva Santos
#
#$Author$
#$Date$
#$Log$ 

#$RCSfile$

#CC = O compilador utilizado
#LD = O linkeditor utilizado
#AR = compila a biblioteca
CC = gcc
LD = gcc
AR = ar

#CFLAGS = as flags utilizadas pelo compilador
#LFLAGS = as flags utilazadas pelo linkeditor
#AFLAGS = as flags utilazadas pelo compilador de bibliotecas
CFLAGS = -Wall
LFLAGS = -Wall
AFLAGS = -lncurses

ALL = $(EXECS)
EXECS = $(FCSSUMLEXECS) $(FCSSUMLEXECSCGI)
FCSSUMLEXECS = $(FCSSUMLEXECS)
FCSSUMLOBJS = $(FCSSUMLCLINCURSESOBJS) $(FCSSUMLCGIOBJS)

FCSSUMLEXECS 	= fcssUml
FCSSUMLEXECSCGI = $(EXECMAINCGI)\
								 	$(FCSSUMLEXECLANGUAGECGI)\
								 	$(EXECFORMCGI)\
								 	$(FCSSUMLEXECHELPCGI)\
								 	$(FCSSUMLEXECLICESNSECGI)

FCSSUMLEXECMAINCGI = fcssUmlCgiMain.cgi
FCSSUMLEXECLANGUAGECGI = fcssUmlMain.cgi
FCSSUMLEXECFORMCGI = fcssUmlShowRequestRegistrationForm.cgi
FCSSUMLEXECHELPCGI = fcssUmlShowWebHelp.cgi
FCSSUMLEXECLICESNSECGI = fcssUmlShowLicense.cgi

FCSSUMLCLINCURSESOBJS 	= fcssUml.o\
													fcssUmlFunctions.o\
													fcssUmlShowCliHelp.o\
													fcssUmlRunNcursesInterface.o\
													fcssUmlShowNcursesHelp.o\
													
FCSSUMLCGIOBJS = $(FCSSUMLMAINCGIOBJS)\
								 $(FCSSUMLLANGUAGECGIOBJS)\
								 $(FCSSUMLFORMCGIOBJS)\
								 $(FCSSUMLHELPCGIOBJS)\
								 $(FCSSUMLLICENSECGIOBJS)

FCSSUMLMAINCGIOBJS = fcssUmlCgiMain.o\
										 fcssUmlCgiTexts.o									 

FCSSUMLLANGUAGECGIOBJS = 	fcssUmlMain.o\
										 			fcssUmlCgiTexts.o										 
										 
FCSSUMLFORMCGIOBJS = fcssUmlShowRequestRegistrationForm.o\
										 fcssUmlCgiTexts.o

FCSSUMLHELPCGIOBJS = fcssUmlShowWebHelp.o\
										 fcssUmlCgiTexts.o

FCSSUMLLICENSECGIOBJS = fcssUmlShowLicense.o\
										 		fcssUmlCgiTexts.o

CGITARGETS = 	fcssUmlCgiMain\
							fcssUmlCgiLanguage\
						 	fcssUmlCgiForm\
						 	fcssUmlCgiHelp\
						 	fcssUmlCgiLicense										 

FCSSUMLEXTERNLIBS = ./Libraries/$(LIBMLCGI)
LIBMLCGI = libmlcgi.a
LIBMLCGICENTOS = libmlcgi.a.CentOS.5.x
LIBMLCGIFREEBSD = libmlcgi.a.FreeBSD.7.x

FCSSUMLLIBSDIR = ./Libraries/

COMPILATIONDIR = /users/felipe.santos/private/EEL270/2016-2/FCSS_UML/Sources/C/
PUBLICHTMLDIR = /users/felipe.santos/public/html/EEL270/2016-2/FCSS_UML/
PUBLICCGIDIR = /users/felipe.santos/public/html/EEL270/2016-2/FCSS_UML/CGIs/

CREATEDIRS = mkdir ../../Binaries/;\
						 mkdir ../../Data/;\
						 mkdir ../../Cookies/;\
						 mkdir -p $(PUBLICCGIDIR);

REMOVEDIRS = rm -r ../../Binaries/;\
						 rm -r ../../Data/;\
						 rm -r ../../Cookies/;\
						 rm -r $(PUBLICHTMLDIR);\

COPYFILESUML = cp -r ../HTML/ $(PUBLICHTMLDIR)


#Regra implicita
.c.o:
	$(CC)	$(CFLAGS)	-c	$<

#Regra geral
#O $@ chama todos os .o necessarios paraera o executavel correspondentes
all:	$(ALL)

install_CentOS: directoryCreation buildAllFilesCentOS copyFiles linkHtmlIndex

install_FreeBSD: directoryCreation buildAllFilesFreeBSD copyFiles linkHtmlIndex

directoryCreation:
	$(CREATEDIRS)

buildAllFilesCentOS: fcssUml fcssUmlCgiCentOS

buildAllFilesFreeBSD: fcssUml fcssUmlCgiFreeBSD

copyFiles:
	$(COPYFILESUML)

linkHtmlIndex:
	cd $(PUBLICHTMLDIR); ln 	-s 	index_en-us.html 	index.html; cd $(COMPILATIONDIR)

fcssUml: $(FCSSUMLCLINCURSESOBJS)
	$(LD)	$(LFLAGS)	-o	$@	$(FCSSUMLCLINCURSESOBJS)	$(AFLAGS)

fcssUmlCliNcurses: $(FCSSUMLCLINCURSESOBJS)
	$(LD)	$(LFLAGS)	-o	$(FCSSUMLEXECS)	$(FCSSUMLCLINCURSESOBJS)	$(AFLAGS)

fcssUmlCgiCentOS:	mlcgiCentOS $(CGITARGETS);

fcssUmlCgiFreeBSD: mlcgiFreeBSD $(CGITARGETS);

fcssUmlCgiMain: $(FCSSUMLCGIOBJS)
	$(LD)	$(LFLAGS)	-o 	$(FCSSUMLEXECMAINCGI)	$(FCSSUMLMAINCGIOBJS)	-L./Libraries/ 	-lmlcgi; cp $(FCSSUMLEXECMAINCGI) $(PUBLICCGIDIR);

fcssUmlCgiLanguage: $(FCSSUMLLANGUAGECGIOBJS)
	$(LD)	$(LFLAGS)	-o 	$(FCSSUMLEXECLANGUAGECGI)	$(FCSSUMLLANGUAGECGIOBJS)	-L./Libraries/ 	-lmlcgi; cp $(FCSSUMLEXECLANGUAGECGI) $(PUBLICCGIDIR);

fcssUmlCgiForm: $(FCSSUMLFORMCGIOBJS)
	$(LD)	$(LFLAGS)	-o 	$(FCSSUMLEXECFORMCGI)	$(FCSSUMLFORMCGIOBJS)	-L./Libraries/ 	-lmlcgi; cp $(FCSSUMLEXECFORMCGI) $(PUBLICCGIDIR);

fcssUmlCgiHelp: $(FCSSUMLHELPCGIOBJS)
	$(LD)	$(LFLAGS)	-o 	$(FCSSUMLEXECHELPCGI)	$(FCSSUMLHELPCGIOBJS)	-L./Libraries/ 	-lmlcgi; cp $(FCSSUMLEXECHELPCGI) $(PUBLICCGIDIR);	

fcssUmlCgiLicense: $(FCSSUMLLICENSECGIOBJS)
	$(LD)	$(LFLAGS)	-o 	$(FCSSUMLEXECLICESNSECGI)	$(FCSSUMLLICENSECGIOBJS)	-L./Libraries/ 	-lmlcgi; cp $(FCSSUMLEXECLICESNSECGI) $(PUBLICCGIDIR);	

mlcgiCentOS:
	cd 	$(LIBSDIR);	ln 	-s 	$(LIBMLCGICENTOS)	$(LIBMLCGI);	cd 	..;

mlcgiFreeBSD:
	cd 	$(FCSSUMLLIBSDIR);	ln 	-s 	$(LIBMLCGIFREEBSD)	$(LIBMLCGI);	cd 	..;

removeAll: clean
	$(REMOVEDIRS) clear;

clean:
	rm -f $(FCSSUMLEXECS) $(FCSSUMLOBJS) $(FCSSUMLEXTERNLIBS)

testeCgi: clean fcssUmlCgiFreeBSD

#$RCSfile$