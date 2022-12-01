# ********************************************************************* #
#          .-.                                                          #
#    __   /   \   __                                                    #
#   (  `'.\   /.'`  )   STD-Expension - Makefile                        #
#    '-._.(;;;)._.-'                                                    #
#    .-'  ,`"`,  '-.                                                    #
#   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        #
#       //\   /         Last Updated: Thu Dec  1 13:47:42 CET 2022      #
#      ||  '-'                                                          #
# ********************************************************************* #

##		-= NOTICE =-
##	You might want to consider calling [make ac / allclean]
##	before modifying any of those settings below!



#==--------------------------------------==#
# *                                      * #
#             GLOBAL SETTINGS              #
# *                                      * #
#==--------------------------------------==#

#####   EXECUTABLE   #####
# Defines the executable's name and the arguments for 'make run/test'

# Add .a to the NAME to make a library instead of a programm
# ARGUMENTS will be used for running quick tests [make run / test]

NAME			= libstdex.a
ARGUMENTS		= 


#####   COMPILATION   #####
# Configurations for compilation

# LANGUAGE will help and add .c/.cpp accordingly to what its set
# When COMPILER is set to [default], it will choose depending on LANGUAGE aswell
# Other settings will add automatly their respectives options during compilation
# and more can be set through EXTRA_PARAMS and LINKER_PARAMS (the second will
# apply only during the last step when creating the programm)

LANGUAGE		= cpp
COMPILER		= default
LIB_FILES		= 
LIB_FOLDER		= 
INCLUDES		= include
DEFINES			= 
EXTRA_PARAMS	= -Wall -Werror -Wextra -g3
LINKER_PARAMS	= 
ifneq ($(OS), Windows_NT)
	LINKER_PARAMS	+= -fsanitize=address
endif


#####   DEPENDENCIES   #####
# Specify which subfolder to "make" and clone/pull needed repos

# EXT_FOLDER will define where the REPOSITORIES will be cloned
# Additional makefiles can be called with REQUIERD and other
# pre-compiled binaries can be added in programm compilation
# with EXT_BINARIES

EXT_FOLDER		= 
REQUIERD		= 
REPOSITORIES	= 
EXT_BINARIES	= 


#####   SILENT MODE   #####
# Wether or not you want to make it more discret [false / true]

# SILENCE_OTHER will silent dependency's makefile(s) (from REQUIERD)
# SILENCE_THIS will silent this current makefile (not recommended though..)

SILENCE_OTHER	= true
SILENCE_THIS	= false


#####   PACKAGING   #####
# Make a package containing everything needed for export
# Neccessary objects and / or folder are defined by PKG_REQUIERD
# PKG_FOLDER will define which folder will be located 

PKG_FOLDER		= package
PKG_REQUIERD	= include



#==--------------------------------------==#
# *                                      * #
#               SOURCE FILES               #
# *                                      * #
#==--------------------------------------==#

CLASSES_FOLDER	= classes
CLASSES_FILES	= 
CLASSES			= $(addprefix $(CLASSES_FOLDER)$(FOLD), $(CLASSES_FILES))

#####   MANDATORY   #####
# GENERIC_FILES will get extension applied according to LANGUAGE
# GENERIC_FOLDER is the subfolder where is located all of the files
# BIN_FOLDER will define where the objects files will be created

GENERIC_FILES	= $(CLASSES) Colors
GENERIC_FOLDER	= src
BIN_FOLDER		= bin

# Source files which doesn't has the expected extension for set
# LANGUAGE or has different subfolder can be set with SRC

SOURCES			= 
OBJECTS			= 



#==--------------------------------------==#
# *                                      * #
#             DISPLAY MESSAGES             #
# *                                      * #
#==--------------------------------------==#

# If you wish to customize the display messages,
# feel free to modify below :)

#####   SYNTAX SEQUENCES   #####
ESC			= 
ifneq ($(OS), Windows_NT)
	ICO_PROCESS	= ƒ
	ICO_SUCCESS	= √
	ICO_FAILURE	= ø
	NEWLINE	= \n
	BREAK	= \r
endif
RED			= $(ESC)[0;31m
GRN			= $(ESC)[0;32m
YLW			= $(ESC)[0;33m
BLU			= $(ESC)[0;34m
DRK			= $(ESC)[0;2m
NUL			= $(ESC)[0m
END			= $(ESC)[0m$(NEWLINE)
BACK		= $(ESC)[2K$(BREAK)

#####   GENERAL COMBINAISONS   #####
MSG_WORK	= $(BACK)$(YLW)$(ICO_PROCESS)
MSG_GOOD	= $(BACK)$(GRN)$(ICO_SUCCESS)
MSG_ERROR	= $(BACK)$(RED)$(ICO_FAILURE)

#####   COMPILING MESSAGES   #####
GET_NEEDING	= $(MSG_WORK) Fetching dependencies ... $(NUL)
CMP_NEEDING	= $(MSG_WORK) Compiling dependencies ... $(NUL)
CMP_WORKING	= $(MSG_WORK) Compiling $@ ... $(NUL)
LIB_SUCCESS	= $(MSG_GOOD) The library $(NAME) has been compiled successfully! $(END)
LIB_FAILURE	= $(MSG_ERROR) The library $(NAME) failed to compile! $(END)
CMP_SUCCESS	= $(MSG_GOOD) The programm $(NAME) has been compiled successfully! $(END)
CMP_FAILURE	= $(MSG_ERROR) The programm $(NAME) failed to compile! $(END)
PKG_SUCCESS = $(MSG_GOOD) The package is ready for export! $(END)

#####   CLEARING MESSAGES   #####
CLR_NEEDING	= $(MSG_WORK) Cleaning dependencies ... $(NUL)
CLR_WORKING	= $(MSG_WORK) Cleaning files ... $(NUL)
CLR_SUCCESS	= $(MSG_GOOD) Objects has been removed! $(END)
CLR_FAILURE	= $(MSG_ERROR) Objects couldn't be removed! $(END)
CLR_EXECUTE	= $(MSG_GOOD) Executable has been removed! $(END)
CLR_EXEFAIL	= $(MSG_ERROR) Executable couldn't be removed! $(END)
CLR_PACKAGE	= $(MSG_GOOD) Package has been removed! $(END)
CLR_PKGFAIL	= $(MSG_ERROR) Package couldn't be removed! $(END)
CLR_DEPENDS	= $(MSG_GOOD) Dependencies has been removed! $(END)
CLR_DEPFAIL	= $(MSG_ERROR) Dependencies couldn't be removed! $(END)

#####   MISC MESSAGES   #####
MISC_NOEXTF	= $(MSG_ERROR) This rule needs EXT_FOLDER to be set to be used! $(END)
MISC_NOCOMP	= $(MSG_ERROR) This rule is not compatible yet with your OS $(OS) $(END)
MISC_DRINK	= $(MSG_WORK) Preparing your order... $(NUL)
MISC_READY	= $(MSG_GOOD) Here's your drink~ UwU $(END)



#==--------------------------------------==#
# *                                      * #
#             MAKEFILE HANDLER             #
# *                                      * #
#==--------------------------------------==#

BUILD_DIR		= build
.DEFAULT_GOAL	= all

ifeq ($(OS), Windows_NT)
include $(BUILD_DIR)\WindowsNT.mk
else
include $(BUILD_DIR)/Unix.mk
endif
include $(BUILD_DIR)$(FOLD)General.mk

.PHONY: \
	all clean fullclean \
	dependencies dependclean \
	package packageclean \
	allclean trueclean \
	remake remakeall \
	drink

# Personnal free to use template
# BY Rosie ~
