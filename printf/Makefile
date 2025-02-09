# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aarcos <aarcos@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 15:28:38 by aarcos            #+#    #+#              #
#    Updated: 2025/02/09 09:31:27 by aarcos           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre de la biblioteca
NAME = libftprintf.a

# Compilador y opciones de compilación
CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIE

# Lista de archivos fuente
SRCS = ft_printf.c ft_printf_utils.c

# Lista de archivos objeto
OBJS = $(SRCS:.c=.o)

# Colores
GREEN = \033[0;32m
NC = \033[0m

# Objetivo por defecto
all: $(NAME)

test: $(OBJS)
	gcc $(CFLAGS) $(OBJS) main.c -o test
# Regla para crear la biblioteca
$(NAME): $(OBJS)
	@echo "$(GREEN)Creando la magia $(NAME)...$(NC)"
	ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)¡Listo!$(NC)"

# Regla para compilar archivos .c en .o
%.o: %.c
	@echo "$(GREEN)Compilando $<...$(NC)"
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar archivos objeto
clean:
	@echo "$(GREEN)Borrando objetos...$(NC)"
	rm -f $(OBJS)

# Limpiar todo
fclean: clean
	@echo "$(GREEN)Borrando la magia...$(NC)"
	rm -f $(NAME)

# Recompilar todo
re: fclean all
	@echo "$(GREEN)¡Recompilando todo!$(NC)"

.PHONY: all clean fclean re
