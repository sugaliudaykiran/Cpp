#include<bits/stdc++.h>
using namespace std;

// Maximum Sum of K Consecutive elements(Naive) :-      TC --> O((N-k) K).. --> O(N_square)..
int SWT(int ar[], int n, int k){                            // | -> Quardtic_form..
    int max_sum = 0;
    for (int i=0; i+k-1 < n; i++){
        int sum = 0;
        for (int j=0; j<k; j++){
            sum += ar[i+j];
        }
        max_sum = max(max_sum, sum);
    }
    return max_sum;
}

// Maximum Sum of K Consecutive elements(Efficient) :-   TC --> O(N)..
int SWTs(int ar[], int n, int k){
    int curr_sum = 0;
    for (int i=0; i<k; i++){    // Upto K..
        curr_sum += ar[i];
    }
    int max_sum = 0;
    for (int i=k; i<n; i++){    // K to N..
        curr_sum += (ar[i] - ar[i-k]);  // Add new one and subtracting the start element..
        max_sum = max(curr_sum, max_sum);
    }
    return max_sum;
}

// Find subarray with given sum :-     
// Here array is unsorted and containg the non-negative elements..
// we use additional Index like start_element -> s, ending_element -> e..

bool sum_is_there(int ar[], int n, int sum){   // TC --> 0(n)..
    int curr_sum = ar[0], s = 0;
    for (int e=1; e<=n; e++){
        while (curr_sum > sum && s < e-1){ // Check the Curr_sum.. is greater in earily..
            curr_sum -= ar[s];             // Clean the previous window..
            s++;
        }
        if (curr_sum == sum){
            cout << "Index of : " << s <<" to "<< e-1 << endl;
            return true;
        }
        if (e<n){
            curr_sum += ar[e];
        }
    }
    return (curr_sum == sum);
}

//  N-bonacci numbers :- similar to fibonacci series and it depends on the N...
// N is sum of N_times and M is the upto M_elements..
//                                                  TC --> O(N * M)..
void N_bonacci(long N, int M){

    // Assuming M > N...
    int ar[M] = { 0 };      // Assing the Zeroes upto the N-1..
    ar[N-1] = 1;            // And the N value is 1..and start the sliding..
    ar[N] = 1;
                                   // Using Sliding_window..
    for (int i = N +1; i<M; i++){
        ar[i] = 2 * ar[i-1] - ar[i - N - 1];
    }

    for (int j=0; j<M; j++){
        cout << ar[j] << " ";
    }

}


int32_t main(){
    // int n, k, sum;
    // //cin >> n >> k;
    // cin >> n >> sum;

    // int ar[n];
    // for (int i=0; i<n; i++){
    //     cin >> ar[i];
    // }

    int N, M;
    cin >> N >> M;

    // cout << SWT(ar, n, k);
    // cout << SWTs(ar, n, k);
    // cout << sum_is_there(ar, n, sum);
    N_bonacci(N, M);
    return 0;
}