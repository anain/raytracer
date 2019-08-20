# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asavann <asavann@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/30 18:48:29 by asavann           #+#    #+#              #
#    Updated: 2018/04/06 16:48:56 by jorobin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rt

DIRSRC = Sources
DIRLIB = Lib
DIROBJ = Objets
DIRSRC_SRC = $(DIRSRC)/Utilities \
		$(DIRSRC)/GeometricObjects \
		$(DIRSRC)/World \
		$(DIRSRC)/Tracers \
		$(DIRSRC)/Minilibx \
		$(DIRSRC)/Camera \
		$(DIRSRC)/BRDFs \
		$(DIRSRC)/Lights \
		$(DIRSRC)/Material\
		$(DIRSRC)/Parser\
		$(DIRSRC)/Sampler\
		libft

OPTIONSC := -L/usr/local/lib/ -lmlx -framework OpenGL \
		-framework AppKit  -lpthread \
		 -Wall -Wextra -Werror -lxml2 

DIRINCS = -I $(DIRSRC)/Utilities \
		-I $(DIRSRC)/GeometricObjects \
		-I $(DIRSRC)/World \
		-I $(DIRSRC)/Tracers \
		-I $(DIRSRC)/Minilibx \
		-I $(DIRSRC)/Camera \
		-I $(DIRSRC)/BRDFs \
		-I $(DIRSRC)/Lights \
		-I $(DIRSRC)/Material \
		-I $(DIRSRC)/Parser \
		-I $(DIRSRC)/Sampler \
		-I libft \
		-I /usr/include/libxml2/libxml \
		-I /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.13.sdk/usr/include/libxml2

# Librairies necessaires a l'executable

LIBS = $(DIRLIB)/utilities.a $(DIRLIB)/geometricobjects.a $(DIRLIB)/world.a $(DIRLIB)/tracer.a $(DIRLIB)/minilibx.a \
		$(DIRLIB)/camera.a $(DIRLIB)/brdf.a $(DIRLIB)/lights.a $(DIRLIB)/material.a libft/libft.a \
		$(DIRLIB)/sampler.a $(DIRLIB)/worldbuild.a

FICSRCC = $(DIRSRC)/main.c
FICOBJC = $(FICSRCC:$(DIRSRC)/%.c=$(DIROBJ)/%.o)

all : $(NAME)

$(NAME): $(LIBS) libs $(DIROBJ) $(FICOBJC)
	@echo
	@echo "\033[38;5;15mCréation de $@ [OK\033[38;5;40m✓\033[38;5;15m]"
	@$(CC) $(OPTIONSC) $(FICOBJC) $(LIBS) -o $@

libs :
	@make -s -C $(DIRSRC)/Utilities
	@make -s -C	$(DIRSRC)/GeometricObjects
	@make -s -C	$(DIRSRC)/World
	@make -s -C	$(DIRSRC)/Tracers
	@make -s -C	$(DIRSRC)/Minilibx
	@make -s -C	$(DIRSRC)/Camera
	@make -s -C	$(DIRSRC)/BRDFs
	@make -s -C	$(DIRSRC)/Lights
	@make -s -C	$(DIRSRC)/Material
	@make -s -C	$(DIRSRC)/Parser
	@make -s -C	$(DIRSRC)/Sampler
	@make -s -C libft

$(LIBS): 
	@mkdir $(DIRLIB) 2> /dev/null || true
	@mkdir $(DIROBJ) 2> /dev/null || true  

# Compilation des fichiers sources C

$(DIROBJ)/%.o: $(DIRSRC)/%.c 
	@$(CC) $(DIRINCS) -c $(DIRSRC)/$(@F:.o=.c) -o $@

clean: cleanlib
	@rm -f $(FICOBJC)
	@echo "\033[38;5;15mclean [OK\033[38;5;40m✓\033[38;5;15m]"

cleanlib :
	@for dir in $(DIRSRC_SRC) ; do \
        make -s clean -C  $$dir ; \
    done 
fclean: clean fcleanlib
	@rm -f $(NAME)
	@rm -rf $(DIROBJ)
	@rm -rf $(DIRLIB)
	@echo "\033[38;5;15mfclean [OK\033[38;5;40m✓\033[38;5;15m]"

fcleanlib :
	@for dir in $(DIRSRC_SRC) ; do \
        make -s fclean -C  $$dir ; \
    done
re : fclean all
