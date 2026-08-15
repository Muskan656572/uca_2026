#include<iostream>
#include<vector>
using namespace std;
int find(vector<int>&arr){
    int count = 0;
    int ans = 0;
    for(int bit = 0; bit<32; bit++){
        count = 0;
        for(int num : arr){
            if((num >> bit) & 1){
                count++;
            }
        }
        if(count % 3 != 0){
            ans = ans | (1<< bit);
        }
        else{
            ans = ans | (0<< bit);
        }
        
    }
    return ans;
}
int main(){
    int number;
    cout << "Enter a number: ";
    cin >> number;

    vector<int>arr(number);
    for(int i = 0; i<number; i++){
        cin >> arr[i];
    }
    int search = find(arr);
    cout << "The number whose frequency is 4 is: " << search;
    return 0;

}