#include "ft_ssl.h"

t_algo* (*init_alg[ALG_COUNT])() = {init_md5, init_sha256};

void display_help()
{
    return;
}

void display_error(char *error)
{
    ft_printf("[ERROR] %s\n", error);
    exit(0);
}

t_algo *init_md5()
{
    t_algo *algo;
    algo = (t_algo*)malloc(sizeof(t_algo));

    algo->flags = (char**)MD5_FLAGS;
    algo->f = md5;
    algo->string_input = MD5_STRING_INPUT;
    algo->hash = NULL;
    if (!(algo->hash = (char*)malloc(sizeof(char) * 32 + 1)))
        return NULL;

    return algo;
}

t_algo *init_sha256()
{
    return NULL;
}

void init_env(t_ssl_env *env)
{
    env->flags = NULL_BYTE;
    env->size = 0;
    env->algo = NULL;
    env->data = NULL;
    env->to_decode = NULL;
}

uint32_t swap_bits_32(int num)
{
    return ((num>>24)&0xff) |
            ((num<<8)&0xff0000) |
            ((num>>8)&0xff00) |
            ((num<<24)&0xff000000);
}


void check_flag(t_ssl_env *env, char *flag)
{
    int i;

    i = 0;
    while (env->algo->flags[i])
    {
        if (!(strcmp(flag, env->algo->flags[i])))
        {
            env->flags |= 1 << i;
            return ;
        }
        ++i;
    }
}

t_algo *get_algo(char *algo)
{
    int i;

    i = 0;
    while (HASH[i])
    {
        if (!(strcmp(algo, HASH[i])))
            return init_alg[i]();
        ++i;
    }
    //todo: change this ugly displaying
    display_error("Allowed algos:\n\tmd5\n\tsha256");
    return NULL;
}

void parse_args(t_ssl_env *env, char **argv)
{
    int i;
    int j;

    env->algo = get_algo(argv[1]);
    i = 2;
    while (argv[i] && *argv[i] == FLAG)
    {
        j = 1;
        while (argv[i][j])
        {
            check_flag(env, &argv[i][j]);
            ++j;
        }
        ++i;
    }
    env->to_decode = (unsigned char *)argv[i];
}


void read_file(t_ssl_env *env, int fd)
{
    int len;
    char buf[BUFFER];

    env->data = (unsigned char *)ft_strnew(BUFFER);
    while ((len = read(fd, buf, BUFFER)))
    {
        memcpy(env->data + env->size, buf, len);
        env->size += len;
        bzero(buf, len);
    }
}


static unsigned int string_input(t_ssl_env *env)
{
    unsigned char mask;

    mask = NULL_BYTE;
    if (env->algo->string_input)
    {
        mask |= env->algo->string_input;
        if (env->flags & mask)
        {
            env->size = ft_strlen((char*)env->to_decode);
            env->data = env->to_decode;
            return 1;
        }
    }
    return 0;
}

void pick_input(t_ssl_env *env)
{
    int fd;

    if (!env->to_decode)
        read_file(env, STDIN);
    else if (!(string_input(env)))
    {
        if ((fd = open((const char *)env->to_decode, O_RDONLY)) != -1)
            read_file(env, fd);
    }
}


int main(int argc, char **argv)
{
    t_ssl_env   env;

    if (argc < 2)
        return 0;
    init_env(&env);
    parse_args(&env, argv);
    pick_input(&env);
    env.algo->f(&env);
    return (0);
}