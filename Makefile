# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/19 13:07:53 by vkovsh            #+#    #+#              #
#    Updated: 2018/03/19 15:19:23 by vkovsh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	vkovsh.filler

CC					=	gcc
CC_FLAGS			=	-Wall -Werror -Wextra

SRC_PATH			=	./srcs/
PARSER_PATH			=	$(SRC_PATH)parser/
BOT_PATH			=	$(SRC_PATH)filler_bot/

INC_PATH			=	./includes/ $(LIBFTPRINTF_PATH)includes/ $(LIBFT_PATH)includes/
OBJ_PATH			=	./obj/
LIBFTPRINTF_PATH	=	./libftprintf/
LIBFT_PATH			=	$(LIBFTPRINTF_PATH)/libft/

OBJ					=	$(addprefix $(OBJ_PATH),$(OBJ_NAME))

INC					=	$(addprefix -I, $(INC_PATH))

OBJ_NAME			=	$(SRC_NAME:.c=.o)
OBJ_NAME			+=	$(PARSER_NAME:.c=.o)
OBJ_NAME			+=	$(BOT_NAME:.c=.o)

SRC_NAME			=	main.c 			\
						new_filler.c

PARSER_NAME			=	init_filler.c 		\
						parse_output.c 		\
						read_from_output.c 	\
						read_new_field.c 	\
						read_new_piece.c

BOT_NAME			=	filler_bot.c

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFTPRINTF_PATH)
	@$(CC) -o $(NAME) $(OBJ) $(LIBFTPRINTF_PATH)libftprintf.a
	@echo "Compiling" [ $(NAME) ]

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC)
	@echo "Linking" [ $< ]

$(OBJ_PATH)%.o: $(PARSER_PATH)%.c
	mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC)
	@echo "Linking" [ $< ]

$(OBJ_PATH)%.o: $(BOT_PATH)%.c
	mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC)
	@echo "Linking" [ $< ]

clean:
	@make -C $(LIBFTPRINTF_PATH) clean
	@rm -rf $(OBJ_PATH)
	@echo "Cleaning obj [ $(NAME) ]..."

fclean: clean
	@rm -f $(NAME)
	@echo "Remove [ $(NAME) ]..."

re: fclean all
