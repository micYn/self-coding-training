//Permutation
#include <iostream>
#include <iomanip>
using namespace std;
void Permutation(char* arr,const int n,const int m){
	//print all permutations from arr[n] to arr[m] (using recursive algorithm)
	if(n==m){
		for(int i=0;i<=m;i++){ //從0開始印
			cout<<arr[i];
		}
		cout<<endl;
		//return;
	}
	else{
		for(int i=n;i<=m;i++){
			swap(arr[n],arr[i]);
			Permutation(arr,n+1,m);
			swap(arr[n],arr[i]);
		}
	}
}
int main(){
	char arr[5]={'a','b','c','d','e'};
	cout<<"All permutaions from a to e"<<endl;
	Permutation(arr,0,4);
	return 0;
}
