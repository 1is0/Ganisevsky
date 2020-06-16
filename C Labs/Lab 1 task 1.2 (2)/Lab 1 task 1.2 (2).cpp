#include <cstdlib>
#include <string.h>
#include <cstdio>
using namespace std;

int main()
{
	int i, k = 0, m;
	int const count = 32;
	char StringA[count] = "0";

	printf("Enter m: ");
	scanf_s("%d", &m);

	for (i = 1; i <= m; i++)
	{
		_itoa_s(i, StringA, 2);

		if (strlen(StringA) == 6 && StringA[0] == '1' && StringA[1] == '1' && StringA[2] == '1' && StringA[3] == '0' && StringA[4] == '0' && StringA[5] == '0')
		{
			printf("\ndecimal m = %d \nbinary m = %s \n", i, StringA);
		}


		else if (strlen(StringA) == 9 && StringA[0] == '1' && StringA[1] == '1' && StringA[2] == '1' && StringA[3] == '0' && StringA[4] == '0' && StringA[5] == '0' && StringA[6] == '1' && StringA[7] == '1' && StringA[8] == '1')
		{
			printf("\ndecimal m = %d \nbinary m = %s \n", i, StringA);
		}

		else if (strlen(StringA) == 12 && StringA[0] == '1' && StringA[1] == '1' && StringA[2] == '1' && StringA[3] == '0' && StringA[4] == '0' && StringA[5] == '0' && StringA[6] == '1' && StringA[7] == '1' && StringA[8] == '1' && StringA[9] == '0' && StringA[10] == '0' && StringA[11] == '0')
		{
			printf("\ndecimal m = %d \nbinary m = %s \n", i, StringA);
		}

		else if (strlen(StringA) == 15 && StringA[0] == '1' && StringA[1] == '1' && StringA[2] == '1' && StringA[3] == '0' && StringA[4] == '0' && StringA[5] == '0' && StringA[6] == '1' && StringA[7] == '1' && StringA[8] == '1' && StringA[9] == '0' && StringA[10] == '0' && StringA[11] == '0' && StringA[12] == '1' && StringA[13] == '1' && StringA[14] == '1')
		{
			printf("\ndecimal m = %d \nbinary m = %s \n", i, StringA);
		}
	}
}