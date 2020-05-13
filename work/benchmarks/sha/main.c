#include "sha1.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"

#define STR_SIZE 20
#define HASHES 100
// max of 300000 with 20

int main()
{
	char const string[] = "abc";
	char const expect[] = "a9993e364706816aba3e25717850c26c9cd0d89d";
	char result[21];
	char hexresult[41];
	size_t offset;
	
	SHA1(result, string, strlen(string));
	
	for(offset = 0; offset < 20; offset++)
	{
		sprintf((hexresult + (2*offset)), "%02x", result[offset]&0xff);
	}
	if(strncmp(hexresult, expect, 40) != 0)
	{
		printf("Error with hash function!\n");
		return 0;
	}
	
	time_t t;
	
	srand((unsigned) time(&t));
	
	char st[HASHES][STR_SIZE+1];
	int i, j;
	for (i = 0; i < HASHES; i++)
	{
		for(j = 0; j < STR_SIZE; j++)
		{
			st[i][j] = (char)((rand()%26)+97);
		}
		st[i][STR_SIZE] = '\0';
	}

	for(i = 0; i < HASHES; i++)
	{
		SHA1(result, st[i], strlen(st[i]));
		
		for(offset = 0; offset < 20; offset++)
		{
			sprintf((hexresult + (2*offset)), "%02x", result[offset]&0xff);
		}
		printf("%s\n", hexresult);
	}
	printf("Completed %d hash funcitons\n", i);
	return 0;
}


