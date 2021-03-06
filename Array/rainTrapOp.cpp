// Trapping rain problem
// This is longer approach
#include<iostream>
#include<math.h>

using namespace std;

// Find max element to the left of the element
int maxLeft(int a[], int index, int n){
    int max = 0;

    while(index >= 0){
        if(a[index] > max )
            max = a[index];
        index--;
    }

    return max;
}

// Find max element to the right
int maxRight(int a[], int index, int n){
    int max = 0;
    while(index < n){
        if(a[index] > max)
            max = a[index];
        index++;
    }   
    return max;
}

int maxWater(int a[], int n){
    int total = 0;
    int lMax[n], rMax[n];
    for(int i = 0; i < n; i++){
        lMax[i] = maxLeft(a, i, n);
        rMax[i] = maxRight(a, i, n);
    }
     for(int i = 0; i < n; i++){
        int maxL, maxR, tmp, tmp2;
        maxL = lMax[i];       // Max element to left
        maxR = rMax[i];      // Max element to right
        tmp = abs(maxR - maxL);

        if(maxR > maxL)
            tmp2 = maxR - tmp;
        else
            tmp2 = maxL - tmp;

        total += tmp2 - a[i];

    }

    return total;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0; i < n; i ++) cin>>a[i];

        cout<<maxWater(a, n)<<endl;
    }

    return 0;
}

