#include<iostream> 
#include<typeinfo>
#include<bits/stdc++.h>
using namespace std;
void swap(int *p,int *q){
	int t=*p;
	*p=*q;*q=t;
}

int main() 
{ int n;
	cout<<"enter the no of process: ";
	cin>> n;
	int at[n],bt[n+1],pr[n],wt[n],ct[n],tat[n],tb[n],prid[n];
	cout<<"enter details: \n";
	for(int i=0;i<n;i++){																//read details
		cout<<"enter  id of "<<i+1<<"th process : ";cin>>pr[i];cout<<"\n";
		cout<<"enter arrival time : "<<i+1<<"th process : ";cin>>at[i];cout<<"\n";
		cout<<"enter burst time: "<<i+1<<"th process : ";cin>>bt[i];cout<<"\n";
		cout<<"enter  priority of "<<i+1<<"th process : ";cin>>prid[i];cout<<"\n";

	}																					//sort by ar --> prid
	cout << "processes " << " burst Time " << " arrival time "<< "\t prid"<< endl;
	for (int i = 0 ; i < n ; i++) 
	{ 
		cout << " " << pr[i] << "\t\t" << bt[i] << "\t\t"	<< at[i] << "\t\t"<< prid[i]<<endl; 
	} 
	int co=0,cct=0,max;
for(int i=0;i<n;i++){tb[i]=bt[i];
}
	prid[n]=INT_MIN;
while(co!=n){
	max=n;
	for(int i=0;i<n;i++){
		if(at[i]<=cct && bt[i]>0 && prid[i]>prid[max]){
			max=i;
		}
	}
	cct+=bt[max];bt[max]=0;
	co++;
		ct[max]=cct;
		tat[max]=ct[max]-at[max];
		wt[max]=tat[max]-tb[max];
}
cout << "processes " << " burst Time " << " arrival time "<< " waiting time " << "   	 	  tat          "  << " completion time"<<"\t prid\n"; 
	int totalwt = 0, totaltat = 0; 
	for (int i = 0 ; i < n ; i++) 
	{ 
		totalwt = totalwt + wt[i]; 
		totaltat = totaltat + tat[i]; 
		int compltime = tat[i] + at[i]; 
		cout << " " << pr[i] << "\t\t" << tb[i] << "\t\t"	<< at[i] << "\t\t" << wt[i] << "\t\t "<< tat[i] << "\t\t " << compltime <<"\t "<<prid[i]<< endl; 
	} 
	cout << "avg waiting time = "<< (float)totalwt / (float)n; 
	cout << "\naverage turn around time = "	<< (float)totaltat / (float)n; 
		return 0; 
}	
