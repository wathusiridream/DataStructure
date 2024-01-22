#include <stdio.h>

int data[10] = {87, 42, 4, 8, 74, 32, 11};
int N = 0;

void insert(int POS, int VAL)
{
    int i = N;
    while (i >= POS)
    {
        data[i + 1] = data[i];
        i--;
    }
    N = N + 1;
    data[POS] = VAL;
}

void delete (int POS)
{
    int i = POS;
    while (i <= N - 1)
    {
        data[i] = data[i + 1];
        i++;
    }
    N = N - 1;
}

void showElement()
{
    int i;
    for (i = 0; i < N; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}

void setN()
{
    int i = 0;
    while (data[i] != 0)
    {
        N++;
        i++;
    }
}

void findMax()
{
    int max = 0, i;
    for (i = 0; i < N; i++)
    {
        if (data[i] > max)
            max = data[i];
    }
    printf("Max data element = %d\n", max);
}

void findmin()
{
	int min = 100,i;
	for(i = 0; i < N; i++)
	{
		if (data[i] < min) 
			min = data[i];
	}
	printf("Min data element = %d\n",min);
}

void findAVG()
{
	float avg;
	int i,sum;
	for (i=0; i<= N;i++)
	{
		sum+=data[i];
	}
	avg = sum/7;
	printf("Average = %.2f",avg);
}
int main()
{
    setN();
    
    showElement();

    //find max
    findMax();
    findmin();
	findAVG();
    return 0;
}
