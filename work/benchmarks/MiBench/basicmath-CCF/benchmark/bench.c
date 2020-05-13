

int main()
{
	printf("Starting Addition Benchmark\n");
	int i;
	for(i = 0; i < 3; i++)
	{
		int val = 0;
		#pragma CGRA
		for(int j = 0; j < 256; j++)
		{
			val = val + j + i;
		}
		printf("Result = %d\n", val);
	}
	printf("Addition Benchmark Complete\n");
	printf("Starting Multiplicaiton Benchmark\n");
	for(i = 0; i < 3; i++)
	{
		int val = 0;
		#pragma CGRA
		for(int j = 0; j < 256; j++)
		{
			val = j * i;
		}
		printf("Result = %d\n", val);
	}
	printf("Multiplicaiton Benchmark Complete\n");
	printf("Starting Complex Branching Benchmark\n");
	for(i = 0; i < 3; i++)
	{
		int val = 0;
		int k = 0;
		#pragma CGRA
		for(int j = 0; k < 16; j++)
		{
			val = val + j*k;
			if(j == 16)
			{
				j = 0;
				k++;
			}
		}
		printf("Result = %d\n", val);
	}
	printf("Complex Branching Benchmark Complete\n");
	return 0;
}
