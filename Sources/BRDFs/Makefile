# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asavann <asavann@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 14:54:43 by asavann           #+#    #+#              #
#    Updated: 2018/04/22 15:37:58 by asavann          ###   ########.fr        #
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

INC = brdf.h
# Nom de la librairie
NAME = $(DIRLIB_LIB)/brdf.a

# Nom des fichiers sources C
FICSRCC = $(DIRSRC)/lambertian.c $(DIRSRC)/lambertian2.c $(DIRSRC)/glossyspecular.c \
 $(DIRSRC)/reflective.c  $(DIRSRC)/perfecttransmitter.c $(DIRSRC)/specularsampler.c
# Nom des fichiers objets correspondant aux fichiers sources
FICOBJC = $(FICSRCC:$(DIRSRC)/%.c=$(DIROBJ)/%.o)

# Options
OPTIONSC = -Wall -Wextra -Werror

# Creation de la librairie
all : $(NAME)

$(NAME): $(FICOBJC)
	@echo "\033[38;5;15mCréation de la lib BRDFs.a [OK\033[38;5;40m✓\033[38;5;15m]"
	@ar -cr $@ $(FICOBJC)

# Compilation des fichiers sources C
$(FICOBJC): $(FICSRCC) $(INC)
	$(CC) $(OPTIONSC) $(DIRINCS) -c $(DIRSRC)/$(@F:.o=.c) -o $@

clean:
	@rm -f $(FICOBJC)

fclean: clean
	@rm -f $(NAME)

re : fclean all
