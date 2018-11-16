#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int x,a,b,c;
	const char *suit[4] = { "Heart","Diamonds","Clubs","spades" };
	const char *face[13] = { "Ace","deuce","Three","Four","Five","Six","Seven","Eight","Nine",
	"Ten","Jeck","Queen","King" };
	int deck[4][13];
	for (x = 0; x < 52; x++)
	{
		deck[x / 13][x % 13] = x+1;
	}
	srand(time(NULL));
	for (x = 0; x < 52; x++)
	{
		a = rand() % 4;
		b = rand() % 13;
		c = deck[x / 13][x % 13];
		deck[x / 13][x % 13] = deck[a][b];
		deck[a][b] = c;
	}
	for (a = 1; a <= 52; a++)
	{
		for (b = 0; b < 52; b++)
		{
			if (deck[b / 13][b % 13] == a)
			{
				printf("%5s of %-8s %c", face[b % 13], suit[b / 13], a % 2 == 0 ? '\n' : '\t');
				b = 53;
			}
		}
	}
	system("pause");
	return 0;
}