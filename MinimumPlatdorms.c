#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return (a > b) ? a : b; }

int compare(const void * a, const void * b)
{
  float fa = *(const float*) a;
  float fb = *(const float*) b;
  return fa - fb;
}

int minPlatform(float arrivalTime[], float departureTime[], int size)
{
	qsort(arrivalTime, size, sizeof(float), compare);
	qsort(arrivalTime, size, sizeof(float), compare);
	
	int plat_needed = 1, result = 1;
	int i = 1, j = 0;
	while (i < size && j < size) {
	    if (arrivalTime[i] <= departureTime[j]) {
			plat_needed++;
			i++;
    	}
		else {
      		plat_needed--;
      		j++;
    	}
    	result = max(plat_needed, result);
	}
	return result;
}


int main()
{
	float arr[] = {2.00, 2.10, 3.00, 3.20, 3.50, 5.00};
	float dep[] = {2.30, 3.40, 3.20, 4.30, 4.00, 5.20};
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Minimum number of platforms required: %d", minPlatform(arr, dep, n));
	return 0;
}
