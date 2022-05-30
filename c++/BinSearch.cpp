#include <bits/stdc++.h>
using namespace std;
int main(){
	//Taking Input: 
	cout << "Enter the number of elements in the array:";
	int n;
	cin >> n;
	vector<int>v(n);
	cout << "Enter the elements:\n";
	for(auto &i:v)
		cin >> i;
	sort(v.begin(),v.end());
	int target;
	cout << "Enter the number you want to search";
	cin >> target;
	//Binary Search to find wheter element is present in the list
	int l=0,r=v.size()-1;
	int mid=(l+r)/2;
	while(l+1<r){
		//element found
		if(v[mid]==target){
		cout << "Given element is present int the array.\n";
		break;
		}
		//element present at left of mid
		else if(v[mid]>target){
			r=mid;
			mid=(l+r)/2;
		
		}
		//element present at right of mid
		else {
			l=mid;
			mid=(l+r)/2;
		}
	}
	//Element not present
	if(v[mid]!=target){
		cout << "Given element is not present\n";
	}
	return 0;
}

