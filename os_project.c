//shortest job first non-preemptive
//p1	0	20
//p2	5	36
//p3	13	19
//p4	17	42

#include<stdio.h>
main()
{
	int process_timer=0,i=0,bt=0;  //O(3)
	int process_no[4]={1,2,3,4}; //O(4)
	int arrival_time[4]={0,5,13,17};
	int burst_time[4]={20,36,19,42};
	int burst[4]={20,36,19,42};
	int process_no_arrived[4]={1};
	double process_ar[4]={0};
	int com_ar[4]={0};
	while(1)
	{
		int k;
		for(k=0;k<4;k++)
		{
			if(process_timer>=arrival_time[k] && burst[k]!=(-1)) 
			{
				process_ar[k]=1+((process_timer-arrival_time[k])/burst[k]);
			}
		}
		int p,q;
		for(p=0;p<4;p++)
		{
			for(q=0;q<4-1-p;q++)
			{
				if(process_ar[q]<process_ar[q+1] && process_no_arrived[q]!=0 && process_no_arrived[q+1]!=0)
				{
					double t1=process_ar[q];
					process_ar[q]=process_ar[q+1];
					process_ar[q+1]=t1;
					int t2=process_no_arrived[q];
					process_no_arrived[q]=process_no_arrived[q+1];
					process_no_arrived[q+1]=t2;
				}
				else if(process_ar[q]==process_ar[q+1]  && process_no_arrived[q]!=0 && process_no_arrived[q+1]!=0)
				{
					if(burst[q]<burst[q+1])
					{
						int t=process_no_arrived[q];
						process_no_arrived[q]=process_no_arrived[q+1];
						process_no_arrived[q+1]=t;
					}
				}
			}
		}
		int y=process_no_arrived[0];
		bt=burst[y-1];
		do
		{
			printf("process_timer : %d\n ",process_timer);
			int x;
			for(x=0;x<4;x++)
			{
				if(process_timer==arrival_time[x])
				{		
					process_no_arrived[x]=x+1;
					printf("\nprocess_no %d arrived\n",x);
				}	
			}
			bt=bt-1;
			process_timer=process_timer+1;
			if(bt==0)
			{
				printf("\n***************************************\n");
				printf("process_no %d completed \n",y );
				com_ar[y-1]=process_timer;
				i=i+1;
				burst[y-1]=-1;
				//process_ar[0]=0;
				for(x=0;x<4;x++)
				{
					process_ar[x]=0;
					if(process_no_arrived[x]!=0)
					{
						process_no_arrived[x]=x+1;
					}
				}
				break;
			}
		}while(1);
		if(i==4)
			break;

	}
}

