/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:44:10 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 18:45:11 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

/*
** ________________
** PART_1_FUNCTIONS
** ________________
*/

/*
** Функции из библиотеки <strings.h>
*/

/*
** Изменяет каждый байт по адресу destination
** в количестве size байт на значение value
*/
void				*ft_memset(void *destination, int value, size_t size);

/*
** Обнуляет данные по адресу destination, в количестве size байт
*/
void				*ft_bzero(void *destination, size_t size);

/*
** Копирует данные из source в destination размером size
*/
void				*ft_memcpy(\
						void *destination, \
						const void *source, \
						size_t size);

/*
** Копирует данные из source в destination до value символа, не более size байт
*/
void				*ft_memccpy(\
						void *destination, \
						const void *source, \
						int value, \
						size_t size);

/*
** Производит поиск байта value по адресу pointer, не более size байт
*/
void				*ft_memchr(const void *pointer, int value, size_t size);

/*
** Сравнивает 2 участка пямяти mem_first и mem_second на протяжении size байт
*/
int					ft_memcmp(\
						const void *mem_first, \
						const void *mem_second, \
						size_t size);

/*
** Копирует данные из source в destination размером size,
** с защитой от перекрытия
*/
void				*ft_memmove(\
						void *destination, \
						const void *source, \
						size_t size);

/*
** Функция считает количество символов в строке
*/
size_t				ft_strlen(const char *string);

/*
** Копирует строку из source в destination,
** вместе с нулль-терминатором
*/
char				*ft_strcpy(char *destination, const char *source);

/*
** Копирует строку из src в dst не более size байт,
** последный байт гарантированно закрывается нуль терминатором
*/
size_t				ft_strlcpy(char *dst, const char *src, size_t size);

/*
** Производит поиск символа c_pattern по строке string,
** поиск идёт слево направо, до первого вхождения
*/
char				*ft_strchr(const char *string, int c_pattern);

/*
** Производит поиск символа c_pattern в строке string,
** поиск идёт справо налево, до первого вхождения
*/
char				*ft_strrchr(const char *str, int argument);

/*
** Функция находит первое вхождение pattern в string с диапазоном
** поиска не более чем size и возвращает указатель
** на первый элемент данного вхождения
*/
char				*ft_strnstr(\
						const char *string, \
						const char *pattern, \
						size_t count);

/*
** Берёт string и конвертирует её в тип int,
** предварительно убирая символы isspace в начале
*/
int					ft_atoi(const char *string);

/*
** Сравнивает строки str1 и str2
*/
int					ft_strcmp(const char *str1, const char *str2);

/*
** Сравнивает строки str1 и str2, игнорируя регистры (upper/lower case)
*/
int					ft_strcmp_i(const char *str1, const char *str2);

/*
** Сравнивает строки str1 и str2, не более size символов
*/
int					ft_strncmp(\
						const char *str1, \
						const char *str2, \
						size_t size);

/*
** Копирует src по адресу dst + len(dst),
** общая длина состовляет не более size символов
*/
size_t				ft_strlcat(char *dst, const char *src, size_t size);

/*
** Создаёт копию строки, с выделением памяти из кучи
*/
char				*ft_strdup(const char *str);

/*
** Функции из библиотеки <ctype.h>
*/

/*
** Если argument является числом из таблице ASCII обозначающим букву латинского
** алфавита [ABCDEFGHIJKLMNOPQRSTUVWXYZ] или [abcdefghijklmnopqrstuvwxyz]
** вернётся 1, иначе 0
*/
int					ft_isalpha(int argument);

/*
** Если argument является числом из таблицы ASCII в пределах от 48 до 57
** включительно, обозначающим числа [0123456789], тогда возвращается 1, иначе 0
*/
int					ft_isdigit(int argument);

/*
** 		Если argument является числом в пределах от 0 до 127 включительно,
** 		которое можно итерпретировать по таблице ASCII,
** 		тогда возвращается 1, иначе 0
*/
int					ft_isascii(int argument);

/*
** Если argument удовлетворяет требованиям
** ft_isalpha или ft_isdigit вернётся 1, иначе 0
*/
int					ft_isalnum(int argument);

/*
** 		Если argument является числом из таблицы ASCII в пределах от 32 до 126
** 		включительно, обозначающим символ из видимого диапазона
** 		тогда возвращается 1, иначе 0
*/
int					ft_isprint(int argument);

/*
** Переводит все символы из lowercase в uppercase
*/
int					ft_toupper(int argument);

/*
** Переводит все символы из uppercase в lowercase
*/
int					ft_tolower(int argument);

/*
** Функции из библиотеки <stdlib.h>
*/

/*
** Выделяет память из кучи для nitems объектов, размера size,
** инициализируя память нулями
*/
void				*ft_calloc(size_t nitems, size_t size);

/*
** Возвращает адрес на выделеную память размером size, заполненый из content
*/
void				*ft_malloc_content(void *content, size_t size);

/*
** PART_2_FUNCTIONS
*/

/*
** Создаёт новую строку из строки str,
** начиная с индекса start, размером size (длина строки без 0-терминатора)
*/
char				*ft_substr(\
						char const *str, \
						unsigned int start, \
						size_t size);

/*
** Создаёт новую строку, путём объединения строки str_1 и str_2
*/
char				*ft_strjoin(char const *str_1, char const *str_2);

/*
** Разделяет строку str, через разделитель sep
*/
char				**ft_split(const char *str, char sep);

/*
** Конвертирует из num типа int в строку
*/
char				*ft_itoa(int num);

/*
** Создаётся новая строка из str, каждый элемент проходит через функцию f
*/
char				*ft_strmapi(char const *str, char (*f)(unsigned int, char));

/*
** Создаёт новую строку на основе str,
** но обрезаную слево и справо по символам из pattern.
*/
char				*ft_strtrim(char const *str, char const *pattern);

/*
** Вывести символ c по дескриптору fd
*/
void				ft_putchar_fd(const char c, int fd);

/*
** Вывести строку str по дескриптору fd
*/
void				ft_putstr_fd(const char *str, int fd);

/*
** Вывести строку str с '\n' по дескриптору fd
*/
void				ft_putendl_fd(const char *str, int fd);

/*
** Вывести число num по дескриптору fd
*/
void				ft_putnbr_fd(int num, int fd);

#endif
