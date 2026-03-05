#include "get_next_line.h"


// Función principal de get_next_line
char *get_next_line(int fd)
{
    /*
     * LÓGICA PRINCIPAL:
     * - Usar buffer estático para persistir entre llamadas
     * - Leer hasta encontrar newline completo
     * - Extraer una línea
     * - Guardar el resto para la siguiente llamada
     */
    static char *saved;
    char *ret;
     // Validar fd y BUFFER_SIZE:
     if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    // Leer hasta tener linea compl
    saved = read_until_newline(fd, saved);
    if (!saved)
        return NULL;
    // Extraer linea a devolver:
    ret = extract_line(saved);
    if (!ret)
    {
        free(saved);
        saved = NULL;
        return NULL;
    }
    // Guardar resto para siguiente call:
    saved = save_remainder(saved);
    return ret;
}

// Función para leer hasta encontrar newline o EOF
/*
     * LECTURA ACUMULATIVA:
     * - Leer chunks de BUFFER_SIZE
     * - Acumular en el buffer saved
     * - Parar cuando se encuentra '\n' o EOF
     * - Manejar errores de read()
*/
char *read_until_newline(int fd, char *saved)
{
    char *read_buf;
    int bytes_read;

    // Init saved if NULL;
    if (!saved)
    {
        saved = malloc(1);
        if (!saved)
            return NULL;
        saved[0] = '\0';
    }
    
    read_buf = malloc(BUFFER_SIZE + 1);
    if (!read_buf)
    {
        free(saved);
        return NULL;
    }

    bytes_read = 1;
    while (bytes_read > 0)
    {
        bytes_read = read(fd, read_buf, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(read_buf);
            free(saved);
            return NULL;
        }
        read_buf[bytes_read] = '\0';
        saved = join_and_free(saved, read_buf);
        if (!saved)
        {
            free(read_buf);
            return NULL;
        }
        if (ft_strchr(read_buf, '\n'))
            break;
    }
    free(read_buf);
    return saved;
}

// Función para unir buffer con datos leídos
/*
     * UNIÓN CON LIBERACIÓN AUTOMÁTICA:
     * - Crear nuevo string concatenado
     * - Liberar el string anterior (saved)
     * - Retornar el nuevo string o NULL en error
*/
char *join_and_free(char *saved, char *buffer)
{
    char *temp = ft_strjoin(saved, buffer);
    if (!temp)
    {
        free(saved);
        return NULL;
    }
    free(saved);
    return temp;
}

// Función para extraer una línea del buffer
/*
     * EXTRACCIÓN DE LÍNEA:
     * - Encontrar la posición del '\n'
     * - Alocar memoria para la línea (incluyendo '\n')
     * - Copiar caracteres hasta '\n' inclusive
     * - Terminar con '\0'
*/
char *extract_line(char *buffer)
{
    if (!buffer || buffer[0])
        return NULL;
    
    int linelen = 0;
    while (buffer[linelen] && buffer[linelen] != '\n')
        linelen++;
    
    char *line = malloc(linelen + 2); // 1 para \0 y otro para \n
    if (!line)
        return NULL;
    int j = 0;
    // Copiar caracteres
    while (j <= linelen && buffer[j])
    {
        line[j] = buffer[j];
        j++;
    }
    line[j] = '\0';
    return line;
}

// Función para guardar el resto después de la línea extraída
/*
     * GUARDAR RESTO:
     * - Encontrar posición después del '\n'
     * - Si no hay más contenido, liberar y retornar NULL
     * - Si hay contenido, alocar y copiar el resto
*/
char *save_remainder(char *buffer)
{
    if (!buffer)
        return NULL;
    int i = 0;
    // Encontrar posición del '\n'
    while (buffer[i] && buffer[i] != '\n')
        i++;
    if (buffer[i] == '\n')
        i++; // Saltar el '\n'

    // Si no hay más contenido después del '\n'
    if (!buffer[i])
    {
        free(buffer);
        return NULL;
    }

    // Alocar para el resto
    char *remainder = malloc(ft_strlen(buffer) - i + 1);
    if (!remainder)
    {
        free(buffer);
        return NULL;
    }
    
    int j = 0;
    while (buffer[i])
        remainder[j++] = buffer[i++];
    remainder[j] = '\0';
    
    free(buffer);
    return remainder;
}

