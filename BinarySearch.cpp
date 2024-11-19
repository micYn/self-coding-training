//binary search
#include <iostream>
#include <iomanip>
using namespace std;
int binarysearchiter(int* arr,int x,int n){
	//search arr[0] ... arr[n-1] for x
	int left = 0, right = n-1;
	while(left<=right){
		int middle = (left+right)/2;
		if(arr[middle]==x)	return middle;
		else if(arr[middle]<x)	left = middle+1;
		else	right = middle-1;
	}
	return -1;
}
int binarysearchrecur(int* arr,int x,int left,int right){
	//search arr[left] ... arr[right] for x
	int middle = (left+right)/2;
	if(left>right)	return -1;
	else if(x<arr[middle])	/*return*/ binarysearchrecur(arr,x,left,middle-1);
	else if(x>arr[middle])	/*return*/ binarysearchrecur(arr,x,middle+1,right);
	else	return middle;
}	
int main(){
	int arr[15]={1,3,5,6,8,12,14,16,17,19,45,56,76,123,788};
	int key;
	for(int i=0;i<15;i++){
		cout<<setw(4)<<arr[i];
	}
	cout<<endl<<"key:";
	cin>>key;
	cout<<"key is at index(iterative) "<<binarysearchiter(arr,key,15)<<endl;
	cout<<"key:";
	cin>>key;
	cout<<"key is at index(recursive) "<<binarysearchrecur(arr,key,0,14)<<endl;
	
	return 0;
}
