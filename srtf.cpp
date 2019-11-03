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
	int at[n],bt[n+1],pr[n],wt[n],ct[n],tat[n],tb[n];
	cout<<"enter details: \n";
	for(int i=0;i<n;i++){																//read details
		cout<<"enter  id of "<<i+1<<"th process : ";cin>>pr[i];cout<<"\n";
		cout<<"enter arrival time : "<<i+1<<"th process : ";cin>>at[i];cout<<"\n";
		cout<<"enter burst time: "<<i+1<<"th process : ";cin>>bt[i];cout<<"\n";
	}																					//sort by ar --> prid
		for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(at[i]>at[j]){
				swap(&at[i],&at[j]);
				swap(&bt[j],&bt[i]);
				swap(&pr[i],&pr[j]);
			}
			else if(at[i]==at[j]){
				if(pr[i]>pr[j]){
				swap(&at[i],&at[j]);
				swap(&bt[j],&bt[i]);
				swap(&pr[i],&pr[j]);}
			}
		}
	}																					//print details
		cout << "processes " << " burst Time " << " arrival time "<< endl;
	for (int i = 0 ; i < n ; i++) 
	{ 
		cout << " " << pr[i] << "\t\t" << bt[i] << "\t\t"	<< at[i] << "\t\t"<< endl; 
	} 
	int co=0,cct=0,min;
 for(int i=0;i<n;i++){tb[i]=bt[i];}
	bt[n]=INT_MAX;				//in this scheduling we need to select min burst time process so to compare burst times we take a max value and to be stored in the burst time aray at the place n so that we just use the values for comarison
while(co!=n){
	min=n;				
	for(int i=0;i<n;i++){								//every time we need to select min burst time process to schedule to the cpu 
		if(at[i]<=cct && bt[i]>0 && bt[i]<bt[min]){		//so here we select the min burst time process which are in the ready que
			min=i;						//i.e the arrival times of process are less than the current time cct
		}
	}
	bt[min]--;cct++;						//for now we execute on 1 unit,bcoz we cant predicted when to preempt so evry second we check the processes 
	if(bt[min]==0){						
		co++;
		ct[min]=cct;
		tat[min]=ct[min]-at[min];
		wt[min]=tat[min]-tb[min];
	}
}
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
