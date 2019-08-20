# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asavann <asavann@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 13:21:24 by asavann           #+#    #+#              #
#    Updated: 2018/04/22 13:33:57 by anain            ###   ########.fr        #
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

INC = chess.h emissive.h material.h matte.h\
noise.h phong.h reflective.h transparence.h
# Nom de la librairie
NAME = $(DIRLIB_LIB)/material.a

# Nom des fichiers sources C
FICSRCC = $(DIRSRC)/matte.c $(DIRSRC)/phong.c \
 $(DIRSRC)/mirror.c $(DIRSRC)/transparence.c $(DIRSRC)/emissive.c \
$(DIRSRC)/get_textures.c $(DIRSRC)/obj_mapping.c \
$(DIRSRC)/transfotext.c $(DIRSRC)/chess.c $(DIRSRC)/linear_noise.c \
$(DIRSRC)/set_noise.c $(DIRSRC)/cubic_noise.c $(DIRSRC)/turbulence.c $(DIRSRC)/fbm.c \
$(DIRSRC)/fractalsum.c

# Nom des fichiers objets correspondant aux fichiers sources
FICOBJC = $(FICSRCC:$(DIRSRC)/%.c=$(DIROBJ)/%.o)

# Options
OPTIONSC = -Wall -Wextra -Werror

# Creation de la librairie
all : $(NAME)

$(NAME): $(FICOBJC)
	@echo "\033[38;5;15mCréation de la lib Material.a [OK\033[38;5;40m✓\033[38;5;15m]"
	@ar -cr $@ $(FICOBJC)

# Compilation des fichiers sources C
$(FICOBJC): $(FICSRCC) $(INC)
	$(CC) $(OPTIONSC) $(DIRINCS) -c $(DIRSRC)/$(@F:.o=.c) -o $@

clean:
	@rm -f $(FICOBJC)

fclean: clean
	@rm -f $(NAME)

re : fclean all
