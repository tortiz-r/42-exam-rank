#define _GNU_SOURCE
#include <string.h>

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include <errno.h>
#include <fcntl.h>


char *filter(char *stream, char *ref)
{
	size_t reflen = strlen(ref);

	char *ret = malloc(strlen(stream) + 1);
	if (!ret)
		return NULL;
	memmove(ret, stream, strlen(stream) + 1);
	printf("ret pre filter: %s\n", ret);

	char *found;
	found = ret;
	char *old_found;
	while (found != NULL)
	{
		old_found = found;
		found = memmem(old_found, strlen(old_found), ref, reflen);
		if (found)
		{
			size_t i = 0;
			while (i < reflen)
			{
				*(found + i) = '*';
				i++;
			}
		}
	}

	printf("ret post filter: %s\n", ret);

	return ret;
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	if (!argv[1] || !argv[1][0])
		return 1;

	char *ref = argv[1];
	printf("ref: %s\n", ref);
	// primero leo

	// while (1)
	// {
		char *buf = NULL;
		int readret = 1;
		int fd = 0;
		char *stream;

		// init stream
		stream = malloc(1);
		if (!stream)
			return perror("Error"), 1;
		stream[0] = '\0';

		while (readret > 0)
		{
			// init buf
			buf = malloc(2);
			if (!buf)
				return perror("Error"), 1;
			// read
			readret = read(fd, buf, 1);
			if (readret > 0)
				buf[1] = '\0';
			else
				buf[0] = '\0';
			// printf("readret: %i, buf: %s\n", readret, buf);
			stream = realloc(stream, strlen(stream) + 2);
			if (!stream)
				return perror("Error"), 1;
			memmove(stream + strlen(stream), buf, readret + 1);
			free(buf);
		}
		printf("stream: %s\n", stream);
		// luego filter
		char *ret = filter(stream, ref);
		
		if (!ret && stream)
			return free(stream), perror("Error"), 1;
		if (!ret && !stream)
			return perror("Error"), 1;
		free(stream);

		// luego imprimo con fprintf
		fprintf(stdout, "OUTPUT: %s", ret);
		free(ret);
	// }
	return 0;
}
