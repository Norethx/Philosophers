# **************************************************************************** #
#                                   CONFIG                                     #
# **************************************************************************** #

NAME    := libft.a
CC      := cc
CFLAGS  := -Wall -Wextra -Werror -c
INCLUDES := ../../include
CPPFLAGS :=  $(addprefix -I,$(INCLUDES))

SRCS    := ft_isalpha.c               ft_isdigit.c         ft_isalnum.c        ft_isascii.c \
           ft_isprint.c               ft_strlen.c          ft_memset.c         ft_bzero.c \
           ft_memcpy.c                ft_memmove.c         ft_strlcpy.c        ft_strlcat.c \
           ft_toupper.c               ft_tolower.c         ft_strchr.c         ft_strrchr.c \
           ft_strncmp.c               ft_memchr.c          ft_memcmp.c         ft_strnstr.c \
           ft_atoi.c                  ft_calloc.c          ft_strdup.c         ft_substr.c \
           ft_strjoin.c               ft_strtrim.c         ft_split.c          ft_itoa.c \
           ft_strmapi.c               ft_striteri.c        ft_putchar_fd.c     ft_putstr_fd.c \
           ft_putendl_fd.c            ft_putnbr_fd.c       ft_lstnew.c         ft_lstadd_front.c \
           ft_lstsize.c               ft_lstlast.c         ft_lstadd_back.c    ft_lstdelone.c \
           ft_lstclear.c              ft_lstiter.c         ft_lstmap.c         ft_lltoa.c \
           ft_uitoa.c                 ft_uitoa_base.c      ft_ulltoa_base.c    ft_memtoa_base.c \
           ft_printf.c                ft_get_next_line.c   ft_get_next_line_utils.c \
           ft_check_extension.c       ft_ext_free_all.c    ft_lstsort.c        ft_realloc.c \
           ft_strcmp.c                ft_ext_newlst.c      ft_gc_calloc.c      ft_gc_call_root.c \
           ft_gc_cast.c               ft_gc_clean_root.c   ft_gc_collect.c     ft_gc_del_root.c \
           ft_gc_end.c                ft_gcfct_arr_register.c ft_gcfct_register.c ft_gc_init.c \
           ft_gclstadd_back.c         ft_gclstdelone.c     ft_gc_malloc.c      ft_gc_mark.c \
           ft_gc_new_root.c           ft_gc_register_root.c ft_gc_rm.c         ft_gc_rm_meta.c \
           ft_gc_rm_root.c            ft_gc_start.c        ft_gc_sweep.c       ft_root_newlst.c \
           ft_size_chrarr.c           ft_isspace.c         ft_arraylen_chr.c   ft_gcfct_arr_register_root.c \
           ft_gcfct_register_root.c   ft_gc_calloc_root.c  ft_gc_malloc_root.c ft_atoll.c \
		   ft_gc_content_root.c

OBJTS   := $(SRCS:.c=.o)

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJTS)
	ar rcs $(NAME) $(OBJTS)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

get_var:
	@echo $(OBJTS)

.PHONY: all clean fclean re get_var
