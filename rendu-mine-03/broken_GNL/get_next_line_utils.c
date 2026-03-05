#include "get_next_line.h"

// Función auxiliar para calcular longitud de string
int ft_strlen(char *s)
{
    int i = 0;
    if (!s)
        return 0;
    while (s[i])
        i++;
    return i;
}

// Función auxiliar para buscar carácter en string
int ft_strchr(const char *s, char c)
{
    int i = 0;
    if (!s)
        return 0;
    while (s[i])
    {
        if (s[i] == c)
            return 1; // Encontrado
        i++;
    }
    return 0; // No encontrado
}

// Función auxiliar para concatenar dos strings
/*
     * CONCATENACIÓN DINÁMICA:
     * - Calcular longitudes de ambos strings
     * - Alocar memoria para el resultado
     * - Copiar s1 + s2 al nuevo string
     * - Liberar s1 (importante para evitar leaks)
*/
char *ft_strjoin(char *s1, char *s2)
{
    if (!s1 || !s2)
        return NULL;

    int len1 = ft_strlen(s1);
    int len2 = ft_strlen(s2);
    char *result = malloc(len1 + len2 + 1);
    if (!result)
        return NULL;

    int i = 0;
    int j = 0;
    while (s1[i]) // Copiar s1
    {
        result[i] = s1[i];
        i++;
    }
    while (s2[j]) // Copiar s2
    {
        result[i] = s2[j];
        i++;
        j++;
    }
    result[i] = '\0';
    return result;
}
