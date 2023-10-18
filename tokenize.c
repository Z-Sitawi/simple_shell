#include "main.h"
/**
 * tokenize - it splits the line ito single words.
 *
 * @line: the line to be tokenized.
 * Return: the tokenization.
 */

char **tokenize(char *line)
{
	char *token = NULL, *linedup = NULL, **commands = NULL;
	int count = 0, i = 0;

	if (!line)
		return (NULL);
	linedup = _strdup(line);
	token = strtok(line, DELIM);
	if (token == NULL)
	{
		free(line);
		free(linedup);
		line = NULL;
		line = NULL;
		return (NULL);
	}
	while (token)
	{
		count++;
		token = strtok(NULL, DELIM);
	}
	free(line);
	line = NULL;
	commands = malloc(sizeof(char *) * (count + 1));
	if (!commands)
	{
		free(linedup);
		linedup = NULL;
		return (NULL);
	}
	token = strtok(linedup, DELIM);
	while (token)
	{
		commands[i] = _strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}
	commands[i] = NULL;
	free(linedup);
	linedup = NULL;
	return (commands);
}
