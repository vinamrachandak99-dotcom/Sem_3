
#include <stdio.h>

void findMaxSubarray(int resources[], int n, int constraint) {
    int max_sum = 0;
    int start_idx = -1, end_idx = -1;
    int left = 0, right = 0, curr_sum = 0;
   
    while (right < n) {
        curr_sum += resources[right];
        // Shrink window if sum exceeds constraint
        while (curr_sum > constraint && left <= right) {
            curr_sum -= resources[left];
            left++;
        }
        // Record valid subarray
        if (curr_sum > max_sum && curr_sum <= constraint) {
            max_sum = curr_sum;
            start_idx = left;
            end_idx = right;
        }
        right++;
    }
    if (max_sum == 0) {
        printf("No feasible subarray.\n");
        return;
    }
    printf("Maximum sum subarray: [");
    for (int i = start_idx; i <= end_idx; i++) {
        printf("%d", resources[i]);
        if (i < end_idx) printf(", ");
    }
    printf("] (sum = %d)\n", max_sum);
}

int main() {
    int n;
    printf("Enter size of resources: ");
    scanf("%d",&n);
    int resource[n];

   for (int i = 0; i < n; i++)
   {
    printf("Enter resource number: %d\t",i+1);
    scanf("%d",&resource[i]);
   }
   
    printf("Enter constraint:\n");
    int c;
    scanf("%d",&c);
    findMaxSubarray(resource,n,c);
    
    
    return 0;
}