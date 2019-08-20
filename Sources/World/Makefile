# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asavann <asavann@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 13:21:24 by asavann           #+#    #+#              #
#    Updated: 2018/04/06 16:49:04 by jorobin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Repertoires

DIRLIB_LIB = ../../Lib/
DIRSRC = ./
DIROBJ = ../../Objets
DIRINCS += -I ../GeometricObjects \
		-I ../Tracers \
		-I ../Utilities \
		-I ../Minilibx \
		-I ../Camera \
		-I ../World \
		-I ../Lights \
		-I ../Material \
		-I ../BRDFs \
		-I ../Sampler \
		-I ../Parser \
		-I /usr/include/libxml2/libxml

# Nom de la librairie
NAME = $(DIRLIB_LIB)/world.a

# Nom des fichiers sources C
FICSRCC = $(DIRSRC)/viewplane.c $(DIRSRC)/viewplane2.c \
			$(DIRSRC)/world.c

INC = viewplane.h world.h
# Nom des fichiers objets correspondant aux fichiers sources
FICOBJC = $(FICSRCC:$(DIRSRC)/%.c=$(DIROBJ)/%.o)

# Options
OPTIONSC = -Wall -Wextra -Werror

# Creation de la librairie
all : $(NAME)

$(NAME): $(FICOBJC)
	@echo "\033[38;5;15mCréation de la lib World.a [OK\033[38;5;40m✓\033[38;5;15m]"
	@ar -cr $@ $(FICOBJC)

# Compilation des fichiers sources C
$(FICOBJC): $(FICSRCC) $(INC)
	$(CC) $(OPTIONSC) $(DIRINCS) -c $(DIRSRC)/$(@F:.o=.c) -o $@

clean:
	@rm -f $(FICOBJC)

fclean: clean
	@rm -f $(NAME)

re : fclean all
