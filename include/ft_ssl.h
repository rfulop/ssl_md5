/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 02:50:51 by rfulop            #+#    #+#             */
/*   Updated: 2017/05/30 20:52:19 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

# include "./../libft/includes/libft.h"
# include "./../libft/includes/ft_printf.h"


# define ALG_COUNT 2
# define FLAG '-'
# define BUFFER 4096
# define STDIN 0
# define NULL_BYTE 0x0
# define MIN_HEX "0123456789abcdef"

typedef struct s_ssl_env t_ssl_env;

typedef struct s_algo
{
	void (*f)(t_ssl_env *env);
	char **flags;
	unsigned char string_input;
	char *hash;
} t_algo;

typedef struct		s_ssl_env
{
	t_algo			*algo;
	size_t			size;
    unsigned char			*to_decode;
	unsigned int	flags;
	unsigned char	*data;
}					t_ssl_env;

# define HASH (const char*[ALG_COUNT + 1]){MD5_NAME, SHA256_NAME, NULL}


/*
 * MD5
 */
# define MD5_DEFAULT "p"
# define MD5_REVERSE "r"
# define MD5_QUIET "q"
# define MD5_STRING "s"

# define MD5_FLAGS (const char*[5]){MD5_DEFAULT, MD5_REVERSE, MD5_QUIET, MD5_STRING, NULL}
# define MD5_NAME "md5"

# define MD5_STRING_INPUT 1 << 3

# define LEFTROTATE(x, c) (((x) << (c)) | ((x) >> (32 - (c))))

typedef struct s_alg_md5
{
	uint32_t r[65];
}				t_alg_md5;


/*
 * SHA 256
 */

# define SHA256_NAME "sha256"

void parse_args(t_ssl_env *env, char **argv);
void check_flag(t_ssl_env *env, char *flag);
t_algo *init_md5();
t_algo *init_sha256();
void md5(t_ssl_env *env);
uint32_t swap_bits_32(int num);
void read_file(t_ssl_env *env, int fd);
void md5_loop(uint8_t *msg, size_t init_len);

#endif
