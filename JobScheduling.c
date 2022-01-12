#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_STRING 50
#define MAX_TASKS 50

typedef struct Job Job;
struct Job
{
    char id[MAX_STRING];
    int deadline;
    int profit;
};

Job *createJob(char id[], int deadline, int profit)
{
    Job *job = (Job*) malloc(sizeof(Job));
    strcpy(job->id, id);
    job->deadline = deadline;
    job->profit = profit;
}

int compare(const void* a, const void* b) 
{
    Job *ja = *(Job**)a;
    Job *jb = *(Job**)b;

    if (ja->profit < jb->profit)
        return 1;
    else if (ja->profit > jb->profit)
        return -1;
    else
        return 0;
}

int min(int a, int b) { return (a < b) ? a : b; }

int printJobScheduling(Job *arr[], int n)
{
	qsort(arr, n, sizeof(Job*), compare);

	int result[MAX_TASKS];
	bool slot[MAX_TASKS];
    int totalProfit = 0;

	for (int i = 0; i < n; i++)
		slot[i] = false;

	for (int i = 0; i < n; i++) {
        for (int j = min(n, arr[i]->deadline)-1; j >= 0; j--) {
            if (slot[j] == false) {
                totalProfit += arr[i]->profit;
			    result[j] = i;
			    slot[j] = true;
			    break;
		    }
	    }
	}
	
	printf("Following is maximum profit sequence of jobs: ");
	for (int i=0; i < n; i++)
	    if (slot[i])
		    printf("\n\t%s, ", arr[result[i]]->id);
	return totalProfit;
}

int main()
{
	Job *arr[] = { 
        createJob("Watching Algo. Session #8", 9, 15),
		createJob("Eating Lunch", 2, 2),
		createJob("Doing Algo. Project", 5, 18),
		createJob("Surfing Instagram", 7, 1),
		createJob("Review for Algo. Final", 4, 25),
		createJob("Doing Algo. Homework", 4, 25),
		createJob("Putting + for Homework Extend", 5, 8),
		createJob("Uploading Homework to Quera", 7, 10),
		createJob("Solving CLRS problems", 4, 12),
		createJob("Watching a TV-Series", 3, 5)
    }; 
    
	int n = sizeof(arr)/sizeof(arr[0]);
	
	int totalProfit = printJobScheduling(arr, n);
	printf("\n\nMax profit: %d", totalProfit);

	return 0;
}
