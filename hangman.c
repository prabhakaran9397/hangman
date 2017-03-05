#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define SIZE	258

int getLine(char S[], FILE *fp)
{
	int  x, i = 0;
	while((x = getc(fp)) != '\n' && x != -1)
		if(isalpha(x) || x == ' ') 
			S[i++] = x;
	S[i] = 0;
	return strlen(S);
}

void getQuest(char S[], int *T, FILE *fp)
{
	if(fp == stdin) {
		do {
			printf("Allowed tries: ");
			scanf("%d", T);
		} while(*T<1);
		getc(stdin);
		printf("Word(s) to be guessed: ");
	}
	else {
		srand(time(NULL));
		*T = rand()%6 + 5;
	}
	getLine(S, fp);
	system("clear");
	printf("[Tries: %d]\n", *T);
}

int in(int x)
{
	if(islower(x))
		return x - 'a';
	else if(isupper(x))
		return x - 'A';
	else
		return 26;
}

void printQuest(int chars[], char S[])
{
	for(; *S; *S++)
		printf("%c", chars[in(*S)]==2 ? *S : '*' );
	puts("");
}

int isWin(int chars[], char S[])
{
	int f = 1;
	for(; f && *S; *S++)
		f = chars[in(*S)]==2 ? 1 : 0;
	return f;
}

void hashIt(int chars[], char S[])
{

	for(; *S; *S++)
		chars[in(*S)] = 1;
}

int main(int argc, char *argv[])
{
	char	Question[SIZE];
	int 	chars[27] = {0};
	int	Tries;
	char 	x;
	FILE	*fp = stdin;

	if(argc == 2) {
		char command[SIZE] = "shuf -n 1 ";
		strcat(command, argv[1]);
		fp = popen(command, "r");
	}

	getQuest(Question, &Tries, fp);
	hashIt(chars, Question);

	while(x = getc(stdin)) {
		if(isalpha(x) || x == ' ') {
			x = in(x);
			if(chars[x] == 1) {
				chars[x] = 2;
				printf("[Right]\t\t\t");
			}
			else if(chars[x] == 2) {
				printf("[Already Guessed]\t");
			}
			else {
				system("clear");
				printf("[Wrong] [Tries: %d]\t", --Tries);
			}
			printQuest(chars, Question);

			if(isWin(chars, Question)) {
				printf("You win!\n");
				return 0;
			}
			if(Tries <= 0) {
				printf("You lose!\n");
				printf("Answer: %s\n", Question);
				return 0;
			}
		}
	}
	return 0;
}
