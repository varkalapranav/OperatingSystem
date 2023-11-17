#include<stdio.h>
struct point{
	int at;
	int bt;
};
 struct point sort(struct point p[],int k,int n,char c){
 	int val1,val2;
	for(int i=k;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(c=='a'){
				val1=p[i].at;
				val2=p[j].at;
			}
			else{
				val1=p[i].bt;
				val2=p[j].bt;
			}
				
			if(val1>val2){
				struct point t=p[i];
				p[i]=p[j];
				p[j]=t;
			}
		}
	}
}
int max(int a,int b){	
	if(a>b)
		return a;
	else
		return b;
}
int main(){
	struct point p[100];
	int n;
	printf("enter the number of processes :");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d",&p[i].at,&p[i].bt);
	sort(p,0,n,'a');
	for(int i=0;i<n;i++)
		printf("%d %d\n",p[i].at,p[i].bt);
	int ct[100],wt[100],tat[100],atat=0,awt=0;
	ct[0]=p[0].at+p[0].bt;
	sort(p,1,n,'b');
	for(int i=1;i<n;i++){
		
		ct[i]=ct[i-1]+p[i].bt;
	}
	for(int i=0;i<n;i++){
		tat[i]=ct[i]-p[i].at;
		wt[i]=tat[i]-p[i].bt;
		atat+=tat[i];
		awt+=wt[i];
	}
	printf("AT\t BT\t CT\t WT\t TAT\n");
	for(int i=0;i<n;i++)
		printf("%d\t %d\t %d\t %d\t %d\n",p[i].at,p[i].bt,ct[i],wt[i],tat[i]);
	printf("the average waiting time is %f",(float)awt/n);
	printf("\nthe average turn around time is %f",(float)atat/n);
	
}
