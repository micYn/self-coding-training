//fibonacii sequence
#include <iostream>
#include <iomanip>
using namespace std;
int fibiter(int n){
	int lofib=0,hifib=1,temp;
	if(n==0)	return 0;
	else if(n=1)	return 1;
	for(int i=2;i<=n-1;i++){
		//讓hifib更新至所求的前一個位置(hifib一開始在數列第二個位置(n=1))
		temp = lofib;
		lofib = hifib;
		hifib = temp+hifib;
	}
	return	lofib+hifib;
}
int fibrecur(int n){
	if(n==1||n==2)	return 1;
	else	return fibrecur(n-2)+fibrecur(n-1);
}	
int main(){
	for(int i=1;i<10;i++){
		cout<<setw(3)<<fibiter(i);
	}
	cout<<endl;
	for(int i=1;i<10;i++){
		cout<<setw(3)<<fibrecur(i);
	}
	cout<<endl;

	return 0;
}
