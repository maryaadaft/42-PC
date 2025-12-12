#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//count the words
int	inner_space(char l)
{
	if (l == ' ' || l == '\t' || l == '\n')
	{
		return (1);
	}
	return (0);
}

//counting the words
int	count_dracula(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while(str[i] != '\0')
	{
		while(str[i] != '\0' && (inner_space(str[i]) == 1))
		{
			i++;
		}
		if (str[i] != '\0' && (inner_space(str[i]) == 0))
		{
			count++; 

			while(str[i] != '\0' && (inner_space(str[i]) == 0)) //go to the end of the word and find the white space
			{
				i++;
			}
		}
	}
	return(count); //give me the number of words
}

//malloc the thing at the start of every word
char *mallocating(char *str,int start)
{
	int i;
	int j;
	char *zawarudo;

	i = 0;
	while(str[i + start] != '\0' && inner_space(str[i + start]) == 0)
	{
		i++;
	}
	zawarudo = malloc(sizeof(char) * i) + 1;
	if(zawarudo == NULL)
		return (NULL);

	j = 0;
	while(j < i)
	{
		zawarudo[j] = str[j + start];
		j++;
	}
	zawarudo[j] = '\0';
	return (zawarudo);
}

char    **ft_split(char *str)
{
	int i; ///enta
	int w; //letters in the word
	int size; //count words fn
	char **array;
	int start;
	
	i = 0;
	w = 0;

	size = count_dracula(str);

	array = malloc(sizeof(char) * (size + 1));
	if(array == NULL)
	{
		return (NULL);
	}

	while(str[i] != '\0')
	{
		while(str[i] != '\0' && (inner_space(str[i]) == 1)) //there is space, ignore it
		{
			i++;
		}
		if (str[i] != '\0' && (inner_space(str[i]) == 0)) //there is no space, 
		{
			start = i;
			while(str[i] != '\0' && (inner_space(str[i]) == 0)) //go to the end of the word and find the white space
			{
				i++;
			}
			array[w] = mallocating(str, start); 
			w++;
		}
	}
	array[w] = NULL;
	return (array);
}


int	main(void)
{
	char str[] = "why does this even exist ya jama3a";
	char **words = ft_split(str);

	for(int i = 0; words[i]; i++)
	{
		printf("%d, %s\n",i, words[i]);
	}
	free(words);
	return 0;
}