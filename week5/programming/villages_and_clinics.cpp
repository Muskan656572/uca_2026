#include<iostream>
#include<vector>
#include<queue>
#include<iomanip>
using namespace std;
class Village {
    public:
        int population;
        int clinics;
        Village(int p){
            population = p;
            clinics = 1;
        }

        double getLoad() const{
            return (double)population / clinics;
        }
};

class Compare {
    public: 
        bool operator()(const Village& v1, const Village& v2) {
            return v1.getLoad() < v2.getLoad();
        }
};

class Solution {
    public:
        double minimimMaximumLoad(vector<int>& populations, int k) {
            priority_queue<Village, vector<Village>, Compare> pq;
            for(int p : populations){
                pq.push(Village(p));
            }

            int remaining = k - populations.size();
            while(remaining > 0){
                Village village = pq.top();
                pq.pop();
                village.clinics++;
                pq.push(village);
                remaining--;
            }
            return pq.top().getLoad();
        }
};
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> populations(n);
    for(int i = 0; i < n; i++){
        cin >> populations[i];
    }
    Solution solution;
    double result = solution.minimimMaximumLoad(populations, k);
    cout << fixed << setprecision(2) << "Maximum load: " <<result << endl;
    return 0;
}