//这个动态规划看不懂
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    while (cin >> n){
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        int k, d;
        cin >> k >> d;
        vector<vector<long long>> dp_max(n, vector<long long>(k + 1, 0));
        vector<vector<long long>> dp_min(n, vector<long long>(k + 1, 0));
        for (int i = 0; i < n; i++){
            dp_max[i][1] = a[i];
            dp_min[i][1] = a[i];
        }
        for (int i = 0; i < n; i++){
            for (int j = 2; j <= k; j++){
                for (int m = max(0, i - d); m <= i - 1; m++){
                    dp_max[i][j] = max(dp_max[i][j], max(dp_max[m][j - 1] * a[i], dp_min[m][j - 1] * a[i]));
                    dp_min[i][j] = min(dp_min[i][j], min(dp_min[m][j - 1] * a[i], dp_max[m][j - 1] * a[i]));
                }
            }
        }
        long long max_value = dp_max[k - 1][k];
        for (int i = k; i < n; i++){
            max_value = max(max_value, dp_max[i][k]);
        }
        cout << max_value << endl;
    }
    return 0;
}