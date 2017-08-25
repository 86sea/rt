/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 13:47:42 by syoung            #+#    #+#             */
/*   Updated: 2017/07/17 11:51:15 by syoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <math.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_vec3f
{
	float		vec[3];
}				t_vec3f;

typedef struct	s_vec2f
{
	float		vec[2];
}				t_vec2f;

typedef struct	s_matrix
{
	int		h;
	int		w;
	double	*x;
}				t_matrix;

typedef t_matrix *matrix;

typedef struct s_quad
{
	float		a;
	float		b;
	float		c;
	float		delta;
	float		x0;
	float		x1;
}				t_quad;

int				ft_strlen(const char *str);
char			*ft_strdup(const char *str);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strstr(char *big, const char *little);
size_t			ft_strlcat(const char *dst, char *src, size_t size);
char			*ft_strnstr(char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strchr(const char *s, int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memmove(void *s1, const void *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
int				ft_atoi(const char *str);
void			ft_bzero(void *b, size_t n);
char			*ft_strcpy(char *dest, const char *src);
int				ft_isprint(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strncpy(char *dest, const char *src, unsigned int n);
int				ft_memcmp(void *s1, void *s2, size_t n);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int i, char *));
char			*ft_strmap(char const *s, char (*f)(char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
void			ft_putchar(char c);
char			*ft_itoa(int n);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(const char *c, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_abs(int num);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstadd(t_list **alst, t_list *new);
char			*ft_strmerge(char *a, char *b);

t_vec3f			ft_add_vectors(t_vec3f v0, t_vec3f v1);
t_vec3f			ft_subtract_vectors(t_vec3f v0, t_vec3f v1);
t_vec3f			ft_multi_vector(t_vec3f v, float t);
float			ft_magnitude(t_vec3f v);
float			ft_dot_prod(t_vec3f v0, t_vec3f v1);
t_vec3f			ft_unit_vector(t_vec3f v);
t_vec3f			ft_vec_to_point(t_vec3f p, t_vec3f v, float m);
float			ft_vector_angle(t_vec3f a, t_vec3f b);
t_vec3f			ft_vec_to_point(t_vec3f p, t_vec3f v, float m);
float			ft_vector_dist(t_vec3f v0, t_vec3f a);
matrix			mat_mul(matrix a, matrix b);
matrix			mat_new(int h, int w);
void			multi_vec_matrix(t_vec3f *src, t_vec3f *dst, float x[4][4]);
void			multi_point_matrix(t_vec3f *src, t_vec3f *dst, float x[4][4]);
float			deg_to_rad(float theta);
void			init_vec(t_vec3f *v);
t_vec3f			vec_change_sign(t_vec3f v);
void			ft_solve_quad(t_quad *q);


#endif
