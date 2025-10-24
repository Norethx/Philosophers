/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:57:31 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/10/23 21:10:38 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# define FILE_DESCRIPTORS 1024

typedef enum e_gc_type
{
	GC_DATA,
	GC_ROOT,
	GC_SYSROOT,
	GC_META
}						t_gc_type;

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
	struct s_list		*prev;
}						t_list;

typedef struct s_ext_list
{
	t_list				*head;
	t_list				*tail;
}						t_ext_list;

typedef struct s_gc_list
{
	void				*content;
	struct s_gc_list	*next;
	struct s_gc_list	*prev;
	t_gc_type			type;
	int					marked;
}						t_gc_list;

typedef struct s_gcext_list
{
	t_gc_list			*head;
	t_gc_list			*tail;
}						t_gcext_list;

typedef struct s_root_list
{
	char				*categ;
	t_ext_list			*lst;
}						t_root_list;

int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
size_t					ft_strlen(const char *str);
void					*ft_memset(void *s, int c, size_t n);
void					*ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_memmove(void *dest, const void *src, size_t n);
size_t					ft_strlcpy(char *dest, const char *src, size_t size);
size_t					ft_strlcat(char *dest, const char *src, size_t size);
int						ft_toupper(int c);
int						ft_tolower(int c);
char					*ft_strchr(char *s, int c);
char					*ft_strrchr(char *s, int c);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_strcmp(const char *s1, const char *s2);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
char					*ft_strnstr(const char *big, const char *little,
							size_t len);
int						ft_atoi(const char *nptr);
void					*ft_calloc(size_t nmemb, size_t size);
char					*ft_strdup(const char *s);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s1, char const *set);
char					**ft_split(char const *s, char c);
char					*ft_itoa(int n);
char					*ft_strmapi(char const *s, char (*f)(unsigned int,
								char));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
int						ft_putchar_fd(char c, int fd);
int						ft_putstr_fd(char *s, int fd);
int						ft_putendl_fd(char *s, int fd);
int						ft_putnbr_fd(int n, int fd);
char					*ft_uitoa_base(unsigned int n, char *base);
char					*ft_lltoa(long long n);
char					*ft_uitoa(unsigned int n);
char					*ft_ulltoa_base(unsigned long long n, char *base);
char					*ft_memtoa_base(unsigned long long n, char *base);

t_list					*ft_lstnew(void *content);
void					ft_lstadd_front(t_ext_list **lst, t_list *new);
int						ft_lstsize(t_list *lst);
t_list					*ft_lstlast(t_list *lst);
void					ft_lstadd_back(t_ext_list **lst, t_list *new);
void					ft_lstdelone(t_list **lst, void (*del)(void *));
void					ft_lstclear(t_ext_list **lst, void (*del)(void *));
int						ft_lstiter(t_list *lst, unsigned int (*f)(void *));
t_ext_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
							void (*del)(void *));
void					ft_lstsort(t_list *lst);

int						ft_printf(const char *str, ...);

char					*get_next_line(int fd);

void					*ft_cleanls(t_ext_list **lst);
int						ft_lst_content_substr(t_list **lst, int loc, char *sec);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_check_extension(const char *str, const char *ext);

t_gcext_list			*ft_gc_start(void);
void					ft_gclstadd_back(t_gcext_list **lst, t_gc_list *new);
t_gc_list				*ft_gc_calloc(size_t nmemb, size_t size,
							t_gc_type type);
t_gc_list				*ft_gc_malloc(size_t size, t_gc_type type);
t_gc_list				*ft_gcfct_register(void *content, t_gc_type type);
t_root_list				*ft_root_newlst(void);
int						ft_gc_rm(t_gc_list **lst);
void					*ft_gc_new_root(char *categ);
int						ft_gc_init(void);
void					ft_gclstdelone(t_gc_list **lst, void (*del)(void *));
void					ft_gc_mark(t_gc_list *lst);
void					ft_gc_sweep(void);
void					ft_gc_collect(void);
void					*ft_gc_register_root(t_gc_list *n_root, char *categ);
t_gc_list				*ft_to_gc_list(void *x);
t_root_list				*ft_to_root_list(void *x);
void					ft_gc_rm_root(t_ext_list **root, t_list *rm_root);
t_list					*ft_gc_clean_root(char *categ);
void					ft_gc_del_root(char *categ);
void					ft_gc_rm_meta(char *categ);
void					ft_gc_end(void);
t_gc_list				*ft_gcfct_arr_register(void **content, t_gc_type type);
t_ext_list				*ft_ext_newlst(void);
t_root_list				*ft_gc_call_root(char *categ);
int						ft_size_chrarr(char **array);
int						ft_isspace(char c);
size_t					ft_arraylen_chr(char **array);
void					*ft_gcfct_arr_register_root(void **content,
							t_gc_type type, char *root);
void					*ft_gcfct_register_root(void *content, t_gc_type type,
							char *root);
void					*ft_gc_calloc_root(size_t nmemb, size_t size,
							t_gc_type type, char *root);
void					*ft_gc_malloc_root(size_t size, t_gc_type type,
							char *root);
long long				ft_atoll(const char *nptr);
t_list					*ft_gc_content_root(char *categ);

#endif
