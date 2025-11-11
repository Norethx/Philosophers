NAME := philo
CC := cc
CFLAGS := -Wall -Wextra -Werror -g
PATH_BONUS := srcs/bonus
PATH_MANDATORY := srcs/philo
INCLUDES := include
CPPFLAGS :=  $(addprefix -I,$(INCLUDES))
SRCS_MANDATORY :=  clean_allocs.c  handle_sim.c  parsing_args.c  philo.c  philo_routine.c  philo_utils.c  time_conversions.c
SRCS_BONUS := handle_philos.c  handle_sem.c  parsing_args.c  philo.c  philo_utils.c  time_conversions.c  philo_routine.c
SRCS_MANDATORY := $(addprefix $(PATH_MANDATORY)/,$(SRCS_MANDATORY))
SRCS_BONUS := $(addprefix $(PATH_BONUS)/,$(SRCS_BONUS))
OBJTS             := $(SRCS_MANDATORY:.c=.o)
OBJTS_BONUS   := $(SRCS_BONUS:.c=.o)

# Cores ANSI
GREEN   = \033[0;32m
RED     = \033[0;31m
YELLOW  = \033[0;33m
BLUE    = \033[0;34m
MAGENTA = \033[0;35m
CYAN    = \033[0;36m
L_GREEN = \033[1;32m
L_RED   = \033[1;31m
GRAY    = \033[0;90m
NC      = \033[0m

all: $(NAME)

$(NAME): $(OBJTS)
		@echo ""
		@echo "$(MAGENTA)+==========================================+"
		@echo "             Github: Norethx          "
		@echo "+==========================================+\n$(NC)"
		@echo "$(GREEN)	⢀⡴⠑⡄⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣤⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
		@echo "	⠸⡇⠀⠿⡀⠀⠀⠀⣀⡴⢿⣿⣿⣿⣿⣿⣿⣿⣷⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
		@echo "	⠀⠀⠀⠀⠑⢄⣠⠾⠁⣀⣄⡈⠙⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀"
		@echo "	⠀⠀⠀⠀⢀⡀⠁⠀⠀⠈⠙⠛⠂⠈⣿⣿⣿⣿⣿⠿⡿⢿⣆⠀⠀⠀⠀⠀⠀⠀"
		@echo "	⠀⠀⠀⢀⡾⣁⣀⠀⠴⠂⠙⣗⡀⠀⢻⣿⣿⠭⢤⣴⣦⣤⣹⠀⠀⠀⢀⢴⣶⣆"
		@echo "	⠀⠀⢀⣾⣿⣿⣿⣷⣮⣽⣾⣿⣥⣴⣿⣿⡿⢂⠔⢚⡿⢿⣿⣦⣴⣾⠁⠸⣼⡿"
		@echo "	⠀⢀⡞⠁⠙⠻⠿⠟⠉⠀⠛⢹⣿⣿⣿⣿⣿⣌⢤⣼⣿⣾⣿⡟⠉⠀⠀⠀⠀⠀"
		@echo "	⠀⣾⣷⣶⠇⠀⠀⣤⣄⣀⡀⠈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀"
		@echo "	⠀⠉⠈⠉⠀⠀⢦⡈⢻⣿⣿⣿⣶⣶⣶⣶⣤⣽⡹⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀"
		@echo "	⠀⠀⠀⠀⠀⠀⠀⠉⠲⣽⡻⢿⣿⣿⣿⣿⣿⣿⣷⣜⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀"
		@echo "	⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣷⣶⣮⣭⣽⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀"
		@echo "	⠀⠀⠀⠀⠀⠀⣀⣀⣈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀"
		@echo "	⠀⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀"
		@echo "	⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀"
		@echo "	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠻⠿⠿⠿⠿⠛⠉\n\n$(NC)"
		@echo "$(YELLOW)+==========================================+"
		@echo "              Build $(NAME)          "
		@echo "+==========================================+\n$(NC)"
		@echo "$(L_GREEN)Compiling...$(NC) $(NAME)"
		@$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJTS) $(LIBFT) -o $(NAME)

TEXT:
		@echo "$(CYAN)+==========================================+"
		@echo "                Recompiling            "
		@echo "+==========================================+\n$(NC)"

%.o: %.c
		@printf "$(L_GREEN)Compiling...$(NC) %-40s\n" $<
		@sleep 0.1
		@$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

bonus: fclean
		@$(MAKE) SRCS_MANDATORY="$(SRCS_BONUS)" all

.PHONY: clean fclean re all bonus $(OBJTS_LIBFT)

clean:
		@echo "$(BLUE)+==========================================+"
		@echo "             Cleaning files            "
		@echo "+==========================================+$(NC)"
		@echo "\n$(L_RED)Removing:$(NC) $(OBJTS) $(OBJTS_BONUS) $(OBJTS_MANDATORY)"
		@rm -f $(OBJTS) $(OBJTS_BONUS) $(OBJTS_MANDATORY)

fclean:
		@echo "$(BLUE)+==========================================+"
		@echo "             Cleaning files            "
		@echo "+==========================================+$(NC)"
		@echo "\n$(L_RED)Removing:$(NC) $(OBJTS) $(OBJTS_BONUS) $(OBJTS_MANDATORY)"
		@rm -f $(OBJTS) $(OBJTS_BONUS) $(OBJTS_MANDATORY)
		@echo "\n$(L_RED)Removing:$(NC) $(NAME)\n"
		@rm -f $(NAME)

re: fclean TEXT all
