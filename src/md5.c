#include "ft_ssl.h"

char *conv_hex_buffer(uint32_t src, size_t size)
{
    printf("conv hex\n");
    int i;
    char *buffer;
    unsigned int n;

    if (!(buffer = (char*)malloc(sizeof(char) * size + 1)))
        return NULL;
    n = swap_bits_32(src);
    i = (int)size - 1;
    while (i >= 0)
    {
        buffer[i] = MIN_HEX[n % 16];
        n = n / 16;
        --i;
    }
    printf("buffer -> %s\n", buffer);
    return buffer;
}



t_alg_md5 *init_alg_md5()
{
    t_alg_md5 *alg_md5;

    if (!(alg_md5 = (t_alg_md5*)malloc(sizeof(t_alg_md5))))
        return NULL;


    uint32_t tmp[] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
                  5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
                  4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
                  6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};


    memcpy(alg_md5->r, tmp, 65);
    printf("aaaa %d\n", alg_md5->r[3]);
    return alg_md5;
}

void md5(t_ssl_env *env) {
    t_alg_md5 *alg_md5;

    alg_md5 = init_alg_md5();
    printf("aaaa %d\n", alg_md5->r[3]);


    uint32_t r[] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
                    5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
                    4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
                    6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};

    // Use binary integer part of the sines of integers (in radians) as constants// Initialize variables:
    // MD5 utilise des sinus d'entiers pour ses constantes :
    // pour i de 0 à 63 faire
    //        k[i] := floor(abs(sin(i + 1)) × 2^32)
    // fin pour
    uint32_t k[] = {
            0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
            0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
            0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
            0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
            0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
            0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
            0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
            0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
            0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
            0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
            0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
            0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
            0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
            0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
            0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
            0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
    };

    // //Préparation des variables :
    uint32_t h0 = 0x67452301;
    uint32_t h1 = 0xEFCDAB89;
    uint32_t h2 = 0x98BADCFE;
    uint32_t h3 = 0x10325476;


    // Preparation du message (padding)
    // taille en bits multiple de 512 (pour 16 mots de 32 bits)
    size_t padding_len = env->size * 8 + 1;

    while (padding_len % 512 != 448)
        padding_len++;
    padding_len /= 8;


    unsigned char *data = (unsigned char *) malloc(padding_len + 64);

    memcpy(data, env->data, env->size);

    // Ajout d'un bit 1 puis autant de bits 0 pour amener la longueur du message a 448 % 512
    data[env->size] = 128;
    int init_len_bits = env->size * 8;
    while (env->size <= padding_len) {
        data[env->size + 1] = 0;
        ++env->size;
    }
    // On ajoute ensuite 64 bits representant la longueur du message
    memcpy(data + padding_len, &init_len_bits, 4);

    /*
     * PRINT MSG
    int a = 0;
    while (a < 512)
    {
        printf("%d. %x | %c\n", a, data[a], data[a]);
        ++a;
    }
     */


    //Découpage en blocs de 512 bits :
    // pour chaque bloc de 512 bits du message
    // subdiviser en 16 mots de 32 bits en little-endian w[i], 0 ≤ i ≤ 15
    size_t chunk = 0;
    while (chunk < padding_len) {
        uint32_t a = h0;
        uint32_t b = h1;
        uint32_t c = h2;
        uint32_t d = h3;

        uint32_t *w = (uint32_t * )(data + chunk);
        int i = 0;
        uint32_t f;
        uint32_t g;
        while (i < 64) {
            if (i >= 0 && i <= 15) {
                f = (b & c) | ((~b) & d);
                g = i;
            } else if (i >= 16 && i <= 31) {
                f = (d & b) | ((~d) & c);
                g = (5 * i + 1) % 16;
            } else if (i >= 32 && i <= 47) {
                f = b ^ c ^ d;
                g = (3 * i + 5) % 16;
            } else if (i >= 48 && i <= 63) {
                f = c ^ (b | (~d));
                g = (7 * i) % 16;
            }

            uint32_t tmp;
            tmp = d;
            d = c;
            c = b;
            b = LEFTROTATE((a + f + k[i] + w[g]), r[i]) + b;
            a = tmp;
            ++i;
        }
        h0 = h0 + a;
        h1 = h1 + b;
        h2 = h2 + c;
        h3 = h3 + d;

        chunk += 64;
    }

    //todo: check leaks
    ft_printf("%x %x% x% x\n", swap_bits_32(h0), swap_bits_32(h1), swap_bits_32(h2), swap_bits_32(h3));

    printf("h0 -> %d\n", swap_bits_32(h0));

    char *a = conv_hex_buffer(h0, 8);
    char *b = conv_hex_buffer(h1, 8);
    char *c = conv_hex_buffer(h2, 8);
    char *d = conv_hex_buffer(h3, 8);

    ft_strcat(env->algo->hash, a);
    ft_strcat(env->algo->hash + 8, b);
    ft_strcat(env->algo->hash + 16, c);
    ft_strcat(env->algo->hash + 24, d);
    env->algo->hash[32 + 1] = '\0';
    printf("hash -> %s\n", env->algo->hash);

}
