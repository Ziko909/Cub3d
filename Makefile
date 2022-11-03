################################# Variables ####################################
# ******************************** Colors *************************************
DFL				:= \033[0;0m
RED				:= \033[0;31m
GREEN			:= \033[0;32m
YELLOW			:= \033[0;33m
BLUE			:= \033[0;34m
PURPLE			:= \033[0;35m
CYAN			:= \033[0;36m

# Bold High Intensty :
BBlack=\033[1;90m
BRed=\033[1;91m
BGreen=\033[1;92m
BYellow=\033[1;93m
BBlue=\033[1;94m
BPurple=\033[1;95m
BCyan=\033[1;96m
BWhite=\033[1;97m

# ******************************** Library ************************************
LIB				:= lib
LIBFT			:= $(LIB)/libft/libft.a

# ******************************** Directories ********************************
OBJDIR			:= obj
SRCDIR			:= src

# *********************************** Files ***********************************
NAME			:=	cub3d

SRC				:= src/main_function/cub3D.c src/ft_parse/ft_check.c src/ft_parse/ft_check_map.c src/ft_parse/ft_check_map_utils.c \
					src/ft_parse/ft_check_textures.c src/ft_parse/ft_check_textures_utils.c src/ft_parse/ft_lists.c \
					src/ft_parse/start_processing.c src/raycasting/raycasting.c src/raycasting/raycasting2.c src/mlx/mlx.c src/rendring/mini_map.c src/rendring/rendering.c

SRC_GNL			:= get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \

OBJ_GNL			:= $(SRC_GNL:%.c=$(OBJDIR)/%.o)

OBJ				:= $(SRC:%.c=$(OBJDIR)/%.o)

# ********************************* include ***********************************
INC				:= include

# ******************************** Compiler ***********************************
CC				:= cc
CFLAGS			:= -Wall -Wextra -g -fsanitize=address

# ******************************** Shell cmd **********************************
RM				:= rm -rf
MD				:= mkdir -p

#################################################################################

all : $(NAME)

$(LIBFT) :
	@make -C lib/libft/
	@echo "$(BWhite) Library is ready to use ..$(DFL)"

$(NAME) : $(LIBFT) $(OBJ) $(OBJ_GNL)
	@echo "$(BBlue) Loading ... $(BBlue) Building The Game $(DFL)";sleep 2
	@$(CC) -I $(INC) -I -Lmlx -lmlx -framework OpenGL -framework AppKit -I $(INC)/get_next_line $(CFLAGS) $(LIBFT) $(OBJ) $(OBJ_GNL) -o $(NAME)
	@echo "$(BYellow) Enjoy $(DFL)"

$(OBJDIR)/%.o : %.c $(INC)/cub3d.h
	@$(MD) $(dir $@)
	@$(CC) -I $(INC) -Imlx -I $(INC)/get_next_line $(CFLAGS) -c $< -o $@
	@echo "$(BGreen) The Object file $(BCyan) ~ $< $(BGreen): was generated $(DFL)";

re : fclean all

clean :
	@$(RM) $(OBJDIR)
	@make clean -C lib/libft
fclean : clean
	@$(RM) $(NAME)
.PHONY : $(LIB) $(LIBFT)