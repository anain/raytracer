# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asavann <asavann@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/30 18:48:29 by asavann           #+#    #+#              #
#    Updated: 2018/04/22 15:41:32 by anain            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# **************************************************************************** #

# Repertoires

DIRLIB_LIB = ../../Lib/
DIRSRC = ./
DIROBJ = ../../Objets
DIRINCS = -I ../World \
		-I ../Utilities \
		-I ../Tracers \
		-I ../GeometricObjects \
		-I ../Material \
		-I ../Lights \
		-I ../BRDFs \
		-I ../Sampler \
		-I ../Parser \
		-I /usr/include/libxml2/libxml

INC = matrix.h maths.h constants.h normal.h\
point2d.h point3d.h ray.h rgbcolor.h shaderec.h vector3d.h
# Nom de la librairie
NAME = $(DIRLIB_LIB)/utilities.a

# Nom des fichiers sources C
FICSRCC = $(DIRSRC)/matrix.c $(DIRSRC)/matrix2.c $(DIRSRC)/point3d.c \
$(DIRSRC)/point3d2.c $(DIRSRC)/point3d3.c $(DIRSRC)/vector3d.c \
$(DIRSRC)/vector3d2.c $(DIRSRC)/vector3d3.c $(DIRSRC)/vector3d4.c \
$(DIRSRC)/vector3d5.c $(DIRSRC)/normal.c $(DIRSRC)/normal2.c \
$(DIRSRC)/normal3.c $(DIRSRC)/normal4.c $(DIRSRC)/ray.c $(DIRSRC)/rgbcolor.c \
$(DIRSRC)/rgbcolor2.c $(DIRSRC)/rgbcolor3.c $(DIRSRC)/shaderec.c \
$(DIRSRC)/maths.c $(DIRSRC)/point2d.c $(DIRSRC)/matrix3.c

# Nom des fichiers objets correspondant aux fichiers sources
FICOBJC = $(FICSRCC:$(DIRSRC)/%.c=$(DIROBJ)/%.o)

# Options
OPTIONSC = -Wall -Wextra -Werror

# Creation de la librairie
all : $(NAME)

$(NAME): $(FICOBJC)
	@echo "\033[38;5;15mCréation de la lib Utilities.a [OK\033[38;5;40m✓\033[38;5;15m]"
	@ar -cr $@ $(FICOBJC)

# Compilation des fichiers sources C
$(FICOBJC): $(FICSRCC) $(INC)
	$(CC) $(OPTIONSC) $(DIRINCS) -c $(DIRSRC)/$(@F:.o=.c) -o $@

clean:
	@rm -f $(FICOBJC)

fclean: clean
	@rm -f $(NAME)

re : fclean all
