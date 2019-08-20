# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asavann <asavann@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 16:53:01 by asavann           #+#    #+#              #
#    Updated: 2018/04/09 16:02:35 by asavann          ###   ########.fr        #
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

INC = ambient.h ambientoccluder.h arealight.h directional.h\
environmentlight.h light.h spot.h
# Nom de la librairie
NAME = $(DIRLIB_LIB)/lights.a

# Nom des fichiers sources C
FICSRCC = $(DIRSRC)/directional.c $(DIRSRC)/directional2.c $(DIRSRC)/ambient.c \
$(DIRSRC)/ambient2.c $(DIRSRC)/spot.c $(DIRSRC)/spot2.c \
$(DIRSRC)/ambientoccluder.c $(DIRSRC)/arealight.c $(DIRSRC)/directional3.c \
$(DIRSRC)/environmentlight.c

# Nom des fichiers objets correspondant aux fichiers sources
FICOBJC = $(FICSRCC:$(DIRSRC)/%.c=$(DIROBJ)/%.o)

# Options
OPTIONSC = -Wall -Wextra -Werror

# Creation de la librairie
all : $(NAME)

$(NAME): $(FICOBJC)
	@echo "\033[38;5;15mCréation de la lib Lights.a [OK\033[38;5;40m✓\033[38;5;15m]"
	@ar -cr $@ $(FICOBJC)

# Compilation des fichiers sources C
$(FICOBJC): $(FICSRCC) $(INC)
	$(CC) $(OPTIONSC) $(DIRINCS) -c $(DIRSRC)/$(@F:.o=.c) -o $@

clean:
	@rm -f $(FICOBJC)

fclean: clean
	@rm -f $(NAME)

re : fclean all