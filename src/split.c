#include "../inc/main.h"

static int	count_words(char *s, char c)
{
	int	count;
	int	inside_word;

	if (!s)
		return (0);
	count = 0;
	while (*s)
	{
		inside_word = 0;
		while (*s == c && *s)
			++s;
		while (*s != c && *s)
		{
			if (!inside_word)
			{
				++count;
				inside_word = 1;
			}
			++s;
		}
	}
	return (count);
}

static char	*extract_word(char *s, int start, char c)
{
	char	*word;
	int		len;
	int		i;

	len = 0;
	while (s[start + len] && s[start + len] != c)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_array(char **array, int count)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (i < count)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static int	fill_array(char **result, char *s, char c, int words)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (s[j] && i <= words)
	{
		while (s[j] == c && s[j])
			j++;
		if (!s[j])
			break ;
		result[i] = extract_word(s, j, c);
		if (!result[i])
		{
			free_array(result, i);
			return (1);
		}
		while (s[j] && s[j] != c)
			j++;
		i++;
	}
	return (0);
}

char	**split(char *s, char c)
{
	int		words;
	char	**result;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	if (!words)
		exit(1);
	result = malloc(sizeof(char *) * (words + 2));
	if (!result)
		return (NULL);
	result[0] = malloc(1);
	if (!result[0])
	{
		free(result);
		return (NULL);
	}
	result[0][0] = '\0';
	if (fill_array(result, s, c, words))
		return (NULL);
	result[words + 1] = NULL;
	return (result);
}
