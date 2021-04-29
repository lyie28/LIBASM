#include <stdio.h>
#include "./libasm.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void ft_read_tests(void)
{
	int fd;
	int score;
	int x;
	int y;
	char buff[50];
	char buff2[30];
	
	buff[49] = '\0';
	score = 0;
	printf("\n--------FT_READ--------------\n");
	fd = open("testing/test.txt", O_RDONLY); 	
	printf("LEVEL 0: input: fd, buff, 50:\n");
	printf("MY function\n");
	x = ft_read(fd, buff, 49);
	printf("return val is %i\n", x);
	printf("buff is: %s\n", buff);
	printf("\nMy errno is %i :\n", errno);	
	close(fd);
	fd = open("testing/test.txt", O_RDONLY); 	
	printf("Real function:\n");
	y = read(fd, buff, 49);
	printf("return val is %i\n", y);
	printf("buff is %s\n", buff);
	printf("\nREal errno is %i :\n", errno);	
	close(fd);
	if (y == x)
		score++;
	printf("----------------------------\n");
	printf("LEVEL 1: INVALID FILE -1, buff2, 30:\n");
	printf("MY function:\n");
	x = ft_read(-1, buff2, 30);
	printf("return val is %i\n", x);
	printf("buff is %s\n", buff2);
	printf("\nMy errno is %i\n", errno);	
	printf("Real function:\n");
	y = read(-1, buff2, 30);
	printf("return val is %i\n", y);
	printf("buff is %s\n", buff2);
	printf("Real errno is %i :\n", errno);	
	if (y == x)
		score++;
	printf("----------------------------\n");
	printf("LEVEL 2: EMPTY FILE fd, buff2, 30:\n");
	fd = open("testing/test_1.txt", O_RDONLY); 	
	printf("MY function:\n");
	x = ft_read(-1, buff2, 30);
	printf("return val is %i\n", x);
	printf("buff is %s\n", buff2);
	printf("My errno is %i :\n", errno);	
	close(fd);
	fd = open("testing/test_1.txt", O_RDONLY); 	
	printf("Real function:\n");
	y = read(-1, buff2, 30);
	printf("Real errno is %i :\n", errno);	
	printf("buff is %s\n", buff2);
	printf("return val is %i\n", y);
	close(fd);
	if (y == x)
		score++;
	printf("----------------------------\n");
	printf("Was my function's output correct? (y/n)\n");
	while (buff[0] != 'y' && buff[0] != 'n')
		read(0, buff, 1);
	if (score == 3 && buff[0] == 'y')
		printf("SUCCESS: QUEST FT_READ COMPLETE\n");
}

void ft_write_tests(void)
{
	int score;
	char buff[2];
	int x = 0;
	int y;

	score = 0;
	buff[1] = '\0';
	printf("\n--------FT_WRITE--------------\n");
	printf("Level 0: SIMPLE TEST: input: >1, Hello friend, h1h2h3ashdkjashdk1823u ??, 10<\n");
	printf("My function :\n");
	x = ft_write(1, "Hello friend, h1h2h3ashdkjashdk1823u ??", 10);
	printf("\nMy errno is %i :\n", errno);	
	printf("Real function :\n");
	y = write(1, "Hello friend, h1h2h3ashdkjashdk1823u ??", 10);
	printf("\nReal errno is %i :\n", errno);
	printf("return val my function: %i vs return val real function %i\n", x, y);
	if (y == x)
		score++;
	printf("----------------------------\n");
	printf("Level 1: ERRNO TEST: input: >-1, Hello friend, 5<\n");
	printf("My function :");
	x = ft_write(-1, "Hello friend", 5);
	printf("\nErrno is %i :\n", errno);
	printf("Real function :");
	y = write(-1, "Hello", 5);
	printf("\nErrno is %i :\n", errno);
	
	printf("return val my function: %i vs return val real function %i\n", x, y);
	if (y == x)
		score++;
	/*printf("----------------------------\n");
	//output is the same but real function has segfault on this!
	printf("Level 2: NULL TEST: >1, , 5<\n");
	printf("My function :");
	x = ft_write(1, "", 5);
	printf("\nErrno is %i :\n", errno);
	printf("Real function :");
	y = write(1, "", 5);
	printf("\nErrno is %i :\n", errno);
	printf("return val my function: %i vs return val real function %i\n", x, y);
	if (y == x)
		score++;
	*/
	printf("----------------------------\n");
	printf("Level 2: READ 0: >1, ajsdhkjashdkjashd8asiuhdjk , 0<\n");
	printf("My function :");
	x = ft_write(1, "ajsdhkjashdkjashd8asiuhdjk", 0);
	printf("\nErrno is %i :\n", errno);
	printf("Real function :");
	y = write(1, "ajsdhkjashdkjashd8asiuhdjk", 0);
	printf("\nErrno is %i :\n", errno);
	printf("return val my function: %i vs return val real function %i\n", x, y);
	
	if (y == x)
		score++;
	printf("----------------------------\n");
	printf("Was my function's output correct? (y/n)\n");
	while (buff[0] != 'y' && buff[0] != 'n')
		read(0, buff, 1);
	if (score == 3 && buff[0] == 'y')
		printf("SUCCESS: QUEST FT_WRITE COMPLETE\n");
}

int	ft_strcpy_tests(void)
{
	int score;
	char *test;
	char *test2;
	score = 0;
	printf("---------FT_STRCPY----------\n");
	printf("Level 0: input: S1: Hello, S2:Laura\n");
	printf("User must not overlap strings + must send a dest with enough space for source: unprotected function\n");
	if (!(test = malloc(sizeof(char) * 6)))
		return (-1);
	if (!(test2 = malloc(sizeof(char) * 6)))
		return (-1);
	test[0] = 'H';
	test[1] = 'e';
	test[2] = 'l';
	test[3] = 'l';
	test[4] = 'o';
	test[5] = '\0';
	test2[0] = 'L';
	test2[1] = 'a';
	test2[2] = 'u';
	test2[3] = 'r';
	test2[4] = 'a';
	test2[5] = '\0';
	printf("My function:\n");
	printf("Return val is: %s\n", ft_strcpy(test, test2));
	printf("Actual dest string is: %s\n", test);
	printf("Real function:\n");
	printf("Return val is: %s\n", strcpy(test, test2));
	printf("Actual dest string is: %s\n", test);
	if (strcmp(test, test2) == 0)
		score++;
	printf("----------------------------\n");
	printf("Level 1: input: NULL SOURCE\n\n");
	printf("My function:\n");
	printf("Return val is: %s\n", ft_strcpy(test, ""));
	printf("Actual dest string is: %s\n", test);
	printf("Real function:\n");
	printf("Return val is: %s\n", strcpy(test2, ""));
	printf("Actual dest string is: %s\n", test2);
	if (strcmp(test, test2) == 0)
		score++;
	printf("----------------------------\n");
	printf("Level 2: shorter string: ep\n\n");
	printf("My function:\n");
	printf("Return val is: %s\n", ft_strcpy(test, "ep"));
	printf("Actual dest string is: %s\n", test);
	printf("Real function:\n");
	printf("Return val is: %s\n", strcpy(test2, "ep"));
	printf("Actual dest string is: %s\n", test2);
	if (strcmp(test, test2) == 0)
		score++;
	if (score == 3)
		printf("SUCCESS: QUEST FT_STRCPY COMPLETE\n");
	printf("----------------------------\n");
	free(test);
	free(test2);
	return (0);
}

void	ft_strlen_tests(void)
{
	int score;
	int x;
	int y;

	score = 0;
	printf("---------FT_STRLEN----------\n");
	printf("Level 0: input: Hello\n");
	x = ft_strlen("hello");
	y = strlen("hello");
	printf("My output: %i\n", x);
	printf("Real output: %i\n", y);
	if (x == y)
		score++;

	printf("----------------------------\n");
	printf("Level 1: input: ashd98u	pO'JjdJhwfjkh\n\n");
	x = ft_strlen("ashd98u pO'JjdJhwfjkh\n");
	y = strlen("ashd98u pO'JjdJhwfjkh\n");
	printf("My output: %i\n", x);
	printf("Real output: %i\n", y);
	if (x == y)
		score++;
	
	printf("----------------------------\n");
	printf("Level 2: input: 	\n\n	00\n\n");
	x = ft_strlen("         \n\n    00\n");
	y = strlen("         \n\n    00\n");
	printf("My output: %i\n", x);
	printf("Real output: %i\n", y);
	if (x == y)
		score++;
	printf("----------------------------\n");
	printf("Level 3: input: ");
	x = ft_strlen("");
	y = strlen("");
	printf("My output: %i\n", x);
	printf("Real output: %i\n", y);
	if (x == y)
		score++;
	if (score == 4)
		printf("SUCCESS: QUEST FT_STRLEN COMPLETE\n");
	printf("----------------------------\n");
}

void	ft_strcmp_tests(void)
{
	int score;
	int x;
	int y;

	x = 0;
	y = 0;
	score = 0;
	printf("---------FT_STRCMP----------\n");
	printf("Level 0: input: aaabcdeeefgh, aaabcdeeefgh\n");
	x = ft_strcmp("aaabcdeeefgh", "aaabcdeeefgh");
	y = strcmp("aaabcdeeefgh", "aaabcdeeefgh");
	printf("My output: %i\n", x);
	printf("Real output: %i\n", y);
	if (x == y)
		score++;
	printf("----------------------------\n");
	printf("Level 1: s1 longer: aaabbb, aaabb\n\n");
	x = ft_strcmp("aaabbb", "aaabb");
	y = strcmp("aaabbb", "aaabb");
	printf("My output: %i\n", x);
	printf("Real output: %i\n", y);
	if (x == y)
		score++;
	printf("----------------------------\n");
	printf("Level 2: s2 longer: aaabbb, aaabbbccddeeff\n\n");
	x = ft_strcmp("aaabbb", "aaabbbccddeeff");
	y = strcmp("aaabbb", "aaabbbccddeeff");
	printf("My output: %i\n", x);
	printf("Real output: %i\n", y);
	if (x == y)
		score++;
	printf("----------------------------\n");
	printf("Level 3: NULL s1 '', abc \n\n");
	x = ft_strcmp("", "abc");
	y = strcmp("", "abc");
	printf("My output: %i\n", x);
	printf("Real output: %i\n", y);
	if (x == y)
		score++;
	printf("----------------------------\n");
	printf("Level 4:second string higher val than first \n\n");
	x = ft_strcmp("aabbcccc", "ccbbaa");
	y = strcmp("aabbcccc", "ccbbaa");
	printf("My output: %i\n", x);
	printf("Real output: %i\n", y);
	if (x == y)
		score++;
	if (score == 5)
		printf("SUCCESS: QUEST FT_STRCMP COMPLETE\n");
	printf("----------------------------\n");
}

void	ft_strdup_tests(void)
{
	int score;
	char *mine;
	char *real;

	score = 0;
	printf("---------FT_STRDUP----------\n");
	printf("Level 0: input: Luke, I am your father... !!\n");
	mine = ft_strdup("Luke, I am your father... !!");
	real = strdup("Luke, I am your father... !!");
	printf("my function: %s\n real function: %s\n", mine, real);
	if (strcmp(mine, real) == 0)
		score++;
	free(mine);
	free(real);
	printf("----------------------------\n");
	printf("Level 1: input: empty string\n");
	mine = ft_strdup("");
	real = strdup("");
	printf("my function: %s\nReal function: %s\n", mine, real);
	if (strcmp(mine, real) == 0)
		score++;
	free(mine);
	free(real);
	printf("----------------------------\n");
	printf("Level 2: face roll\n");
	mine = ft_strdup("ahsdkjahsjkd	 kjhskjdhasdN## \n\t\v--@");
	real = strdup("ahsdkjahsjkd	 kjhskjdhasdN## \n\t\v--@");
	printf("my function: %s\nReal function: %s\n", mine, real);
	if (strcmp(mine, real) == 0)
		score++;
	if (score == 3)
		printf("SUCCESS: QUEST FT_STRDUP COMPLETE\n");
	printf("----------------------------\n");
	free(mine);
	free(real);	
}

int main(void)
{
	char buff[2];
	char buff1[2];
	char buff2[2];
	char buff3[2];
	char buff4[2];
	char buff5[2];
	
	printf("Test ft_strlen ??? (y/n)\n");
	while (buff[0] != 'y' && buff[0] != 'n')
		read(0, buff, 1);
	if (buff[0] == 'y')
		ft_strlen_tests();
	printf("Test ft_write ??? (y/n)\n");
	while (buff1[0] != 'y' && buff1[0] != 'n')
		read(0, buff1, 1);
	if (buff1[0] == 'y')
		ft_write_tests();
	printf("Ready to test ft_read?? (y/n)\n");
	while (buff2[0] != 'y' && buff2[0] != 'n')
		read(0, buff2, 1);
	if (buff2[0] == 'y')
		ft_read_tests();
	printf("Ready to test ft_strcpy?? (y/n)\n");
	while (buff3[0] != 'y' && buff3[0] != 'n')
		read(0, buff3, 1);
	if (buff3[0] == 'y')
	{
		if (ft_strcpy_tests() == -1)
			return (-1);
	}
	printf("Ready to test ft_strcmp?? (y/n)\n");
	while (buff4[0] != 'y' && buff4[0] != 'n')
		read(0, buff4, 1);
	if (buff4[0] == 'y')
		ft_strcmp_tests();
	printf("Ready to test ft_strdup?? (y/n)\n");
	while (buff5[0] != 'y' && buff5[0] != 'n')
		read(0, buff5, 1);
	if (buff5[0] == 'y')
		ft_strdup_tests();
	return (0);
}
