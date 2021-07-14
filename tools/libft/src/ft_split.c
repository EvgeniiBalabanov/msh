/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:11:02 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 19:01:30 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** FUNCTION NAME:
** 		ft_strlen_c
** INPUT PARAMS:
** 		src	- строка от куда будет браться инфо
** 		sep	- символ до которого будет происходить подсчёт
** RETURNS:
** 		возвращает длину записанной строки(без '\0')
** EXAMPLE:
** 		(str = "Hello World", sep = ' ')
** 		|'H''e''l''l''o'' ''W''o''l''d'|
** 		| 1  2  3  4  5  <-abort |
** 		return (5);
*/

static size_t	ft_strlen_c(const char *str, const char sep)
{
	size_t	counter;

	counter = 0;
	while (str[counter] && str[counter] != sep)
		counter++;
	return (counter);
}

/*
** FUNCTION NAME:
** 		ft_strcdup
** INPUT PARAMS:
** 		dst	- указатель для заполнения
** 		src	- строка от куда будет браться инфо
** 		sep	- символ до которого будет происходить обработка
** INFO:
** 		Перед заполнением dst происходит выделение памяти через malloc
** RETURNS:
** 		возвращает длину записанной строки(без '\0')
** 		в случае ошибки выделения памяти вернёт 0
*/

static int	ft_strcdup(char **dst, const char *src, char sep)
{
	size_t	counter;

	counter = ft_strlen_c(src, sep);
	*dst = ft_substr(src, 0, counter);
	if (*dst)
		return (counter);
	return (0);
}

/*
** FUNCTION NAME:
** 		ft_count_str
** INPUT PARAMS:
** 		str	- строка по которой ведётся итерация
** 		sep	- сокращение от separator, по которому ведётся разделение
** RETURNS:
** 		возвращает количество будующих строк после разделения сепаратором
** EXAMPLE:
** 		(str = "hello world", sep = ' ') => 2 ("hello" и "world")
** 		(str = "aaaaa", sep = 'a') => 0 (Так как нету того, что нужно разделять)
** 		(str = "test", sep = '\0') => 1
*/

static size_t	ft_count_str(const char *str, char sep)
{
	size_t	counter;

	counter = 0;
	while (*str)
	{
		if (*str != sep && (*(str + 1) == '\0' || *(str + 1) == sep))
			counter++;
		str++;
	}
	return (counter);
}

/*
** FUNCTION NAME:
** 		ft_delete_strings
** INPUT PARAMS:
** 		strings - массив указателей на строки
** INFO:
** 		Если в какой то момент при выделении памяти выделение не произошло,
** 		тогда чтобы избежать утечек памяти требуется освободить память
** 		выделеную до этого. Сначало все строки из массива указателей,
** 		потом сам массив указателей.
*/

static void	ft_delete_strings(char **strings)
{
	size_t	counter;

	counter = 0;
	while (strings && strings[counter])
	{
		free(strings[counter]);
		counter++;
	}
	free(strings);
}

/*
** FUNCTION NAME:
** 		ft_split
** INPUT PARAMS:
** 		str - строка которую нужно разбить на подстроки
** 		sep - он же separator, символ по которому нужно будет делать разделение
** INFO:
** 		Разделяет строку str, через разделитель sep
** 		Функция выделяет память под массив указателей, который после вернёт.
** 		В каждый элемент массива будет помещён адрес строки,
** 		которая была получена в результате разделения str,
** 		в качестве разделителя служит sep.
** EXAMPLE:
** 		IN:
** 			(str = "Hello World", sep = ' ')
** 		OUT:
** 			(address 100) -> result -> массив указателей
** 					|
**					V
** 			(address 100) -> [result element index 0] -> (addess !300)
** 			(address 108) -> [result element index 1] -> (addess !400)
** 			(address 116) -> [result element index 1] -> NULL
**
** 			(address !300) -> [string] -> "Hello"
** 			(address !400) -> [string] -> "World"
**
** 										NULL	- NULL-pointer который говорит,
** 													что строк больше не будет
** 										!		- обозначает абстрактный адрес
** RETURN:
** 		result - массив указателей с последним элементом NULL,
** 									обозначающим конец массива
** 		В случае неудачи (при выделении памяти) вернёт NULL
*/

char	**ft_split(const char *str, char sep)
{
	char	**result;
	int		counter_result;
	int		plus_str;

	counter_result = 0;
	if (!str)
		return ((char **)0);
	result = (char **)ft_calloc(sizeof(char *), (ft_count_str(str, sep) + 1));
	if (!result)
		return ((char **)0);
	while (*str)
	{
		while (*str && *str == sep)
			str++;
		if (!*str)
			break ;
		plus_str = ft_strcdup(result + counter_result++, str, sep);
		if (!plus_str)
		{
			ft_delete_strings(result);
			return ((char **)0);
		}
		str += plus_str;
	}
	return (result);
}
