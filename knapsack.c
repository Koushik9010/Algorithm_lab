#include <stdio.h>

// Function to find the maximum of two integers
int max(int a, int b) {
  return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem using dynamic programming
int knapSack(int W, int wt[], int val[], int n) {
  int i, w;
  int K[n][W + 1];

  // Build the table K[][] in a bottom-up manner
  for (i = 0; i < n; i++) {
    for (w = 0; w <= W; w++) {
      if (i == 0 || w == 0)
        K[i][w] = 0;
      else if (w >= wt[i - 1])
        K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
      else
        K[i][w] = K[i - 1][w];
    }
  }

  return K[n - 1][W];
}

int main() {
  int n;

  printf("Enter the number of items: ");
  scanf("%d", &n);

  int wt[n], val[n];

  printf("Enter the weights of the items:\n");
  for (int i = 0; i < n; i++)
    scanf("%d", &wt[i]);

  printf("Enter the profits of the items:\n");
  for (int i = 0; i < n; i++)
    scanf("%d", &val[i]);

  int W;
  printf("Enter the knapsack capacity: ");
  scanf("%d", &W);

  printf("The maximum value in the knapsack is: %d\n", knapSack(W, wt, val, n));

  return 0;
}