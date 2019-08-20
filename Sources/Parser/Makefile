# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asavann <asavann@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/30 18:48:29 by asavann           #+#    #+#              #
#    Updated: 2018/04/20 20:47:37 by anain            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Repertoires

DIRLIB_LIB = ../../Lib/
DIRSRC = ./
DIROBJ = ../../Objets
DIRINCS += -I ../World \
		-I ../GeometricObjects \
		-I ../Utilities \
		-I ../Tracers \
		-I ../Camera \
		-I ../Lights \
		-I ../Material \
		-I ../BRDFs \
		-I ../Sampler \
		-I ../World \
		-I ../Minilibx\
		-I ../../Libft \
		-I /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.13.sdk/usr/include/libxml2

INC = parsing.h
# Nom de la librairie
NAME = $(DIRLIB_LIB)/worldbuild.a

# Nom des fichiers sources C
FICSRCC = $(DIRSRC)/parser.c $(DIRSRC)/worldbuild.c  $(DIRSRC)/parse_cam.c \
 $(DIRSRC)/parse_lights.c  $(DIRSRC)/parse_vp.c  $(DIRSRC)/parse_objects.c \
 $(DIRSRC)/check.c  $(DIRSRC)/parser_set.c $(DIRSRC)/parse_sphere.c \
 $(DIRSRC)/parse_cone.c $(DIRSRC)/parse_cylinder.c $(DIRSRC)/parse_plane.c \
 $(DIRSRC)/parse_box.c $(DIRSRC)/parse_disk.c $(DIRSRC)/parse_partocylinder.c \
 $(DIRSRC)/parse_partsphere.c $(DIRSRC)/parse_rectangle.c \
 $(DIRSRC)/parse_triangle.c $(DIRSRC)/parse_torus.c $(DIRSRC)/parse_paraboloid.c \
 $(DIRSRC)/parser_objects_generic.c  $(DIRSRC)/parser_objects_material.c \
 $(DIRSRC)/parser_objects_materialbase.c\
 $(DIRSRC)/parser_objects_materialtext.c $(DIRSRC)/parse_byname.c \
 $(DIRSRC)/parser_objects_materialtypes.c $(DIRSRC)/parse_transfo.c \
 $(DIRSRC)/parse_transfo2.c $(DIRSRC)/parser_set2.c \
 $(DIRSRC)/parser_objects_material_usage.c \
 $(DIRSRC)/parser_objects_materialnoise.c \
 $(DIRSRC)/parse_env.c $(DIRSRC)/parse_dlight.c $(DIRSRC)/parse_spot.c \
 $(DIRSRC)/parse_ao.c $(DIRSRC)/parse_area.c \
 $(DIRSRC)/parse_areaobj.c $(DIRSRC)/parse_areaobj2.c \
 $(DIRSRC)/parse_mickey.c $(DIRSRC)/parser_objects_materialchess.c \
 $(DIRSRC)/parse_cylinder2.c \
 $(DIRSRC)/parse_partocylinder2.c $(DIRSRC)/parse_partsphere2.c \
 $(DIRSRC)/parser_objects_materialtext2.c $(DIRSRC)/parser_set3.c \
 $(DIRSRC)/parser_set4.c $(DIRSRC)/parse_pathtracer.c  \
 $(DIRSRC)/parse_mickey2.c $(DIRSRC)/parse_limcone.c $(DIRSRC)/parse_limcone2.c \
 $(DIRSRC)/parse_skybox.c  $(DIRSRC)/parse_triangle2.c
# Nom des fichiers objets correspondant aux fichiers sources
FICOBJC = $(FICSRCC:$(DIRSRC)/%.c=$(DIROBJ)/%.o)

# Options
OPTIONSC = -Wall -Wextra -Werror


# Creation de la librairie
all : $(NAME)

$(NAME): $(FICOBJC)
	@echo "\033[38;5;15mCréation de la lib Worldbuild.a [OK\033[38;5;40m✓\033[38;5;15m]"
	@ar -cr $@ $(FICOBJC)

# Compilation des fichiers sources C
$(FICOBJC): $(FICSRCC) $(INC)
	@$(CC) $(OPTIONSC) $(DIRINCS) -c $(DIRSRC)/$(@F:.o=.c) -o $@

clean:
	@rm -f $(FICOBJC)

fclean: clean
	@rm -f $(NAME)

re : fclean all
