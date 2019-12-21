# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fculator <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/09 19:19:30 by fculator          #+#    #+#              #
#    Updated: 2019/11/19 16:22:57 by fculator         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= checker
NAME_PW:= push_swap
FILE_C:= checker
FILE_PW := push_swap
FILES := check_for_sorting \
        do_op_stack \
        do_op_stack_2 \
        do_op_stack_3 \
        parse_args_to_stack \
        get_next_line \
        basic_sort_process \
        big_sort_process \
        find_max_el_and_index \
        free_objects \
        from_a_to_b \
        sort_array \
        sort_list_hard \

LFTDIR := ./libft

CCHF := obj
COMPILER := gcc
LINKER := ar rc
SRCPATH := src/
HDRPATH := includes/
CCHPATH := obj/
IFLAGS := -I $(HDRPATH) -I $(LFTDIR)/includes
LFLAGS := -L $(LFTDIR) -lft
CFLAGS := -Wall -Wextra -Werror $(IFLAGS)

BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"

SRC:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILES)))
SRC_PW:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILE_PW)))
SRC_C:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILE_C)))
OBJ:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILES)))
OBJ_C:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILE_C)))
OBJ_PW:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILE_PW)))

all: $(NAME_PW) $(NAME)

$(CCHF):
	@mkdir -p $(CCHPATH)
	@touch $(CCHF)

$(NAME): $(OBJ) $(OBJ_C)
	@cd $(LFTDIR) && $(MAKE)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@$(COMPILER) $(CFLAGS) $(SRC) $(LFLAGS) $(SRCPATH)$(FILE_C).c -o $(NAME)
	@echo $(GREEN) " - OK" $(EOC)

$(NAME_PW): $(OBJ) $(OBJ_PW)
	@cd $(LFTDIR) && $(MAKE)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@$(COMPILER) $(CFLAGS) $(SRC) $(LFLAGS) $(SRC_PW) -o $(NAME_PW)
	@echo $(GREEN) " - OK" $(EOC)

$(CCHPATH)%.o: $(SRCPATH)%.c | $(CCHF)
	@echo $(PURPLE) " - Compiling $< into $@" $(EOC)
	@$(COMPILER) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(CCHPATH)
	@rm -f $(CCHF)
	@cd $(LFTDIR) && $(MAKE) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_PW)
	@rm -rf $(NAME).dSYM/
	@rm -rf $(NAME_PW).dSYM/
	@cd $(LFTDIR) && $(MAKE) fclean

re: fclean
	@$(MAKE) all