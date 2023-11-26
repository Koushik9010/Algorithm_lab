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
  for (i = 0; i < n; i++) { //iterates over each item
    for (w = 0; w <= W; w++) { //terates over each possible knapsack weight capacity
      if (i == 0 || w == 0)//if it's the first item or the knapsack has zero capacity  
        K[i][w] = 0;
      else if (w >= wt[i - 1])
        //weight of the current item is less than or equal to the current capacity
        K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
        //calculates the maximum value or by excluding the current item
      else
        // /f the weight of the current item is greater than the current capacity
        K[i][w] = K[i - 1][w];
      //simply takes the value from the cell
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
