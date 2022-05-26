#include <iostream>
using namespace std;
#define N (int)1e6+10

int dp[N];
int numbers[N];

int lis(int index){
    if (dp[index] != 0) return dp[index];
    int len = 1;
    for(int i = index-1;i>=0;i--){
    	if(numbers[i]<numbers[index])
        	len = max(len, lis(i)+1);
    }
    return dp[index]=len;
}


int main(void){

    int length;
    std::cin >> length;    

    for(int i=0;i<length;i++){
        std::cin >> numbers[i];
    }

    int max_length = 1;
    for(int i=0;i<length;i++){
    	max_length = max(max_length, lis(i)); 	
    } 
    
    std::cout << max_length << std::endl;

    return 0;
}
