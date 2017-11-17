// A divide and conquer based efficient solution to find median
// of two sorted arrays of same size.
#include<bits/stdc++.h>
using namespace std;
 
bool isLess(double m1, double m2){
    return abs(m1-m2) < 1e-3;
}

double avg(int arr[], int n){
    if (n % 2 == 0){
        return (arr[n/2-1] + arr[n/2]) * 0.5;
    }
    return arr[n/2];
}

double getMedian(int ar1[], int ar2[], int n)
{

    if (n == 0) return -1;  //empty array

    if (n == 1){
        return (*ar1 + *ar2) / 2.0;
    }

    if (n == 2){
        int left = max(*ar1, *ar2);
        int rgt = min(ar1[1], ar2[1]);
        return (left + rgt) / 2.0;
    }

    double m1 = avg(ar1, n);
    double m2 = avg(ar2, n);

    int shift = (n - 1) / 2;
    if (m1 < m2){
        return getMedian(ar1 + shift, ar2, n - shift);
    }

    return getMedian(ar1, ar2 + shift, n - shift);

}
 

 
/* Driver program to test above function */
int main()
{
    int ar1[] = {1, 2, 100};
    int ar2[] = {10, 20, 30};
    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);
    if (n1 == n2)
        printf("Median is %f", getMedian(ar1, ar2, n1));
    else
        printf("Doesn't work for arrays of unequal size");
    return 0;
}