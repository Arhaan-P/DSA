#include <iostream>
using namespace std;
int main() {
	int a[5];

	//Taking input to the array
	cout<<"Enter five numbers \n";
	for (int i=0;i<5;i++){
		cin>>a[i];
	}

	//Displaying the unsorted array
	cout<<"Unsorted array \n";
	for (int i=0;i<5;i++){
		cout<<a[i]<<" ";
	}

	//Swapping
	for (int i=0;i<4;i++){
		for(int j=0;j<4-i;j++){
			if (a[j]>a[j+1]){
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}

//Displaying sorted array
cout<<"\n Array in ascending order \n";
for (int n=0;n<5;n++) {
	cout<<a[n]<<" ";
	}
}