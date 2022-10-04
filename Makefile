################################# Variables ####################################
# ******************************** Colors *************************************
DFL				:= \033[0;0m
RED				:= \033[0;31m
GREEN			:= \033[0;32m
YELLOW			:= \033[0;33m
BLUE			:= \033[0;34m
PURPLE			:= \033[0;35m
CYAN			:= \033[0;36m
# ******************************** Library ************************************
Libft			:= lib/libft

# ******************************** Directories ********************************
OBJDIR			:= obj
SRCDIR			:= src

# *********************************** Files ***********************************
NAME			:= cub3D
SRC				:=	$(SRCDIR)/cub3D.c \
					$(SRCDIR)/parsing.c
OBJ				:= $(SRC:%.c=$(OBJDIR)/%.o)

# ********************************* include ***********************************
INC				:= include
# ******************************** Compiler ***********************************
CC				:= gcc
CFLAGS			:= -Wall -Wextra -Werror -fsanitize=address

# ******************************** Shell cmd **********************************
RM				:= rm -rf
MD				:= mkdir -p

#################################################################################
all : $(NAME)

$(NAME) : $(OBJ)
	@echo "$(GREEN) Loading ... $(PURPLE) Build The Game $(DFL)";sleep 2
	@$(CC) -I $(INC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(YELLOW) Enjoy $(DFL)"

$(OBJDIR)/%.o : %.c
	@$(MD) $(dir $@)
	@$(CC)  -I $(INC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW) the Object File of $(CYAN) $< was generated $(DFL)";

re : fclean all
clean :
	@$(RM) $(OBJDIR)
fclean : clean
	@$(RM) $(NAME)