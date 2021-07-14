/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 23:01:45 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 19:11:42 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# include <ctype.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_line
{
	char		*string;
	size_t		allocated;
	size_t		length;
}				t_line;

/*
** Создание объекта line, со стартовым выделением init_size байт
*/
t_line			*ft_line_new(size_t init_size);

/*
** Удалить объект line
*/
void			ft_line_del(t_line *line);

/*
** Удалить символ по индексу index в строке line
*/
void			ft_line_del_chr(t_line *line, size_t index);

/*
** Дополнительно добавить выделенной памяти к line, количеством size
** В случае выделения памяти, данные копируются
*/
t_line			*ft_line_mem_up(t_line *line, size_t size);

/*
** Увеличить доступную память line,
** чтобы строка размером length могла поместиться в line->string
** В случае выделения памяти, данные стираются и line становиться не безопасным!
*/
t_line			*ft_line_mem_up_to(t_line *line, size_t length);

/*
** Увеличить доступную память line,
** чтобы строка размером length могла поместиться в line->string
*/
t_line			*ft_line_mem_realloc(t_line *line, size_t length);

/*
** Создание объекта line, из символа chr
*/
t_line			*ft_line_create_chr(char chr);

/*
** Создание объекта line, из строки string
*/
t_line			*ft_line_create_str(const char *string);

/*
** Создание объекта line, из другого line
*/
t_line			*ft_line_create_line(t_line *line);

/*
** Добавить символ chr в конец line
*/
t_line			*ft_line_add_chr(t_line *line, char chr);

/*
** Добавить строку string в конец line
*/
t_line			*ft_line_add_str(t_line *line, const char *string);

/*
** Добавить линию tail в конец line
*/
t_line			*ft_line_add_line(t_line *line, t_line *tail);

/*
** Добавить отрезок из линии sub_line в конец destination,
** начиная с start_index, заканчивая stop_index
*/
t_line			*ft_line_add_sub_line(\
						t_line *destination, \
						t_line *sub_line, \
						size_t start_index, \
						size_t stop_index);

/*
** Копировать в линию destination символ sourse
*/
t_line			*ft_line_cpy_chr(t_line *destination, char sourse);

/*
** Копировать в линию destination строку sourse
*/
t_line			*ft_line_cpy_str(t_line *destination, const char *sourse);

/*
** Копировать в линию destination линию sourse
*/
t_line			*ft_line_cpy_line(t_line *destination, t_line *sourse);

/*
** Вставить в line, символ chr, по индексу index
*/
t_line			*ft_line_insert_chr(t_line *line, char chr, size_t index);

/*
** Обрезать line по определённому индексу
*/
t_line			*ft_line_cut_index(t_line *line, size_t index);

/*
** Создаёт новый t_line из line, обрезанный по индексам start_index и stop_index
*/
t_line			*ft_line_sub_line(t_line *line, \
							size_t start_index, \
							size_t stop_index);

/*
** Функция для нахождения количества байт, требуемыех для string в t_line
*/
size_t			ft_line_get_count_byte_allocate(size_t need_byte);

#endif
