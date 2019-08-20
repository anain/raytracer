# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asavann <asavann@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/30 18:48:29 by asavann           #+#    #+#              #
#    Updated: 2018/04/22 15:24:12 by anain            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# **************************************************************************** #

# Repertoires

DIRLIB_LIB = ../../Lib/
DIRSRC = ./
DIROBJ = ../../Objets
DIRINCS = -I ../World \
		-I ../GeometricObjects \
		-I ../Utilities \
		-I ../Tracers \
		-I ../Camera \
		-I ../Lights \
		-I ../Material \
		-I ../BRDFs \
		-I ../Sampler \
		-I ../Parser \
		-I /usr/include/libxml2/libxml

INC = tracer.h
# Nom de la librairie
NAME = $(DIRLIB_LIB)/tracer.a

# Nom des fichiers sources C
FICSRCC = $(DIRSRC)/multipleobjects.c

# Nom des fichiers objets correspondant aux fichiers sources
FICOBJC = $(FICSRCC:$(DIRSRC)/%.c=$(DIROBJ)/%.o)

# Options
OPTIONSC = -Wall -Wextra -Werror

# Creation de la librairie
all : $(NAME)

$(NAME): $(FICOBJC)
	@echo "\033[38;5;15mCréation de la lib Tracers.a [OK\033[38;5;40m✓\033[38;5;15m]"
	@ar -cr $@ $(FICOBJC)

# Compilation des fichiers sources C
$(FICOBJC): $(FICSRCC) $(INC)
	$(CC) $(OPTIONSC) $(DIRINCS) -c $(DIRSRC)/$(@F:.o=.c) -o $@

clean:
	@rm -f $(FICOBJC)

fclean: clean
	@rm -f $(NAME)

re : fclean all
