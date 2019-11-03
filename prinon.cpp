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
		cout<<"enter burst time: "<<i+1<<"th process : ";cin>>bt[i];cout<<"\n";tb[i]=bt[i];
		cout<<"enter  priority of "<<i+1<<"th process : ";cin>>prid[i];cout<<"\n";

	}																					//sort by ar --> prid
		for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(at[i]>at[j]){
				swap(&at[i],&at[j]);
				swap(&bt[j],&bt[i]);
				swap(&pr[i],&pr[j]);
				swap(&prid[i],&prid[j]);
			}
			else if(at[i]==at[j]){
				if(prid[i]>prid[j]){
				swap(&at[i],&at[j]);
				swap(&bt[j],&bt[i]);
				swap(&pr[i],&pr[j]);
				swap(&prid[i],&prid[j]);}
			}
		}
	}																					//print details
		cout << "processes " << " burst Time " << " arrival time "<< endl;
	for (int i = 0 ; i < n ; i++) 
	{ 
		cout << " " << pr[i] << "\t\t" << bt[i] << "\t\t"	<< at[i] << "\t\t"<< endl; 
	} 


	
for(int i=0;i<n;i++){
	int co=i;
	if(i==0){
	wt[0]=0;ct[0]=at[0]+bt[0];tat[0]=ct[0]-at[0];	
	}
	else{
	for(int j=i;j<n;j++){
		if(at[j]<=ct[i-1]){co++;
		}
	}
	for(int j=i;j<co;j++){
		
		for(int k=j+1;k<co;k++){
		if(prid[j]<prid[k]){
			swap(&at[k],&at[j]);
			swap(&bt[j],&bt[k]);
			swap(&pr[j],&pr[k]);
			swap(&prid[j],&prid[k]);
			
		}
		}
	}
	if(ct[i-1]<at[i]){
		ct[i]=at[i]+bt[i];
	}
	else{
		ct[i]=ct[i-1]+bt[i];
	}
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];	
}}



cout << "processes " << " burst Time " << " arrival time "<< " waiting time " << "   	 	  tat          "  << " completion time\n"; 
	int totalwt = 0, totaltat = 0; 
	for (int i = 0 ; i < n ; i++) 
	{ 
		totalwt = totalwt + wt[i]; 
		totaltat = totaltat + tat[i]; 
		int compltime = tat[i] + at[i]; 
		cout << " " << pr[i] << "\t\t" << tb[i] << "\t\t"	<< at[i] << "\t\t" << wt[i] << "\t\t "<< tat[i] << "\t\t " << compltime << endl; 
	} 
	cout << "avg waiting time = "<< (float)totalwt / (float)n; 
	cout << "\naverage turn around time = "	<< (float)totaltat / (float)n; 
		return 0; 
}	
