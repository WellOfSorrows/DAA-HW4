#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b)
{
    int fa = *(const int*) a;
    int fb = *(const int*) b;
    return fa - fb;
}

int findMaxPersons(int p[], const int n, const int W)
{
    qsort(p, n, sizeof(int), compare);

    int maxPersons = 0;
    int i = 0, j = n-1;
    while (i < j) {
        if (p[i] + p[j] <= W) {
            maxPersons += 2;
            i++; j--;
        }
        else {
            j--;
        }
    }
    return maxPersons;

}
int main(int argc, char const *argv[])
{
    int weights[7] = {10, 1, 2, 5, 5, 11, 4};
    int size = sizeof(weights) / sizeof(weights[0]);
    int limit = 10;
    printf("Max number of people: %d", findMaxPersons(weights, size, limit));
    return 0;
}
