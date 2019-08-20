# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asavann <asavann@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 13:21:24 by asavann           #+#    #+#              #
#    Updated: 2018/04/24 19:52:21 by asavann          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Repertoires

DIRLIB_LIB = ../../Lib/
DIRSRC = ./
DIROBJ = ../../Objets
DIRINCS = -I ../GeometricObjects \
		-I ../Tracers \
		-I ../Utilities \
		-I ../Minilibx \
		-I ../Camera \
		-I ../World \
		-I ../Lights \
		-I ../Material \
		-I ../BRDFs \
		-I ../../libft \
		-I ../Sampler \
		-I ../Parser \
		-I /usr/include/libxml2/libxml

INC = box.h compound.h disk.h geometricobjects.h infcone.h\
opencylinder.h paraboloid.h partopencylinder.h partsphere.h\
plane.h rectangle.h sphere.h triangle.h
# Nom de la librairie
NAME = $(DIRLIB_LIB)/geometricobjects.a

# Nom des fichiers sources C
FICSRCC = $(DIRSRC)/plane.c $(DIRSRC)/sphere.c $(DIRSRC)/sphere2.c $(DIRSRC)/opencylinder.c \
$(DIRSRC)/infcone.c $(DIRSRC)/geometricobjects.c $(DIRSRC)/geometricobjects2.c $(DIRSRC)/disk.c \
$(DIRSRC)/disk2.c $(DIRSRC)/rectangle.c $(DIRSRC)/rectangle2.c \
$(DIRSRC)/partsphere.c $(DIRSRC)/partsphere2.c $(DIRSRC)/partopencylinder.c $(DIRSRC)/triangle.c \
$(DIRSRC)/torus.c $(DIRSRC)/torus2.c $(DIRSRC)/torus3.c $(DIRSRC)/torus4.c $(DIRSRC)/torus5.c \
$(DIRSRC)/paraboloid.c $(DIRSRC)/boxes.c $(DIRSRC)/boxes2.c $(DIRSRC)/concavesphere.c \
$(DIRSRC)/compound.c $(DIRSRC)/objtransfo.c $(DIRSRC)/limcone.c $(DIRSRC)/partopencylinder2.c

# Nom des fichiers objets correspondant aux fichiers sources
FICOBJC = $(FICSRCC:$(DIRSRC)/%.c=$(DIROBJ)/%.o)

# Options
OPTIONSC = -Wall -Wextra -Werror

# Creation de la librairie
all : $(NAME)

$(NAME): $(FICOBJC)
	@echo "\033[38;5;15mCréation de la lib GeometricObjects.a [OK\033[38;5;40m✓\033[38;5;15m]"
	@ar -cr $@ $(FICOBJC)

# Compilation des fichiers sources C
$(FICOBJC): $(FICSRCC) $(INC)
	$(CC) $(OPTIONSC) $(DIRINCS) -c $(DIRSRC)/$(@F:.o=.c) -o $@

clean:
	@rm -f $(FICOBJC)

fclean: clean
	@rm -f $(NAME)

re : fclean all
