#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>

using namespace std;
struct process
{
  string name;
  int arrivalTime , BurstTime ;
};
bool FCFS_Sort(process p1 , process p2)
{
  return p1.arrivalTime < p2.arrivalTime;
}
void FCFS()
{
        cout<<"\n\n\n\n\t*** FCFS ***\n";


  process p[100];
  ifstream File("Data.txt");
  int WaitingTime[100],TurnAroundTime[100],Start[100],End[100];
  int counter = 0;
  double AvgWaitingTime=0.0,AvgTurnAroundTime=0.0;
  while(File>>p[counter].name>>p[counter].arrivalTime>>p[counter].BurstTime)
  {
    ++counter;
  }
  File.close();
  sort(p,p+counter,FCFS_Sort);
  cout<<"process"<<" | "<<"Arrival Time"<<"  | "<<"Burst Time"<<"\t|\n";
  for(int i=0;i<counter;++i){
     cout<<"-----------------------------------------"<<"\n";
    cout<<p[i].name<<"\t"<<"|      "<<p[i].arrivalTime<<"\t"<<"|"<<"     "<<p[i].BurstTime<<"\t|\n";
  }
    cout<<"-----------------------------------------"<<"\n";
    cout<<" * Gant Chart * "<<"\n";

    cout<<"----------------------------------------------------------------------------"<<"\n";
    bool idel = false;
    if(p[0].arrivalTime!=0)
      idel = true;
          if(idel)
          cout<<"|"<<" "<<"id"<<" ";
    for(int i=0;i<counter;++i)
    {
      cout<<"|"<<"  "<<p[i].name<<"  ";
    }
    cout<<"| \n";
    cout<<"----------------------------------------------------------------------------"<<"\n";
    if(idel)
    {
      int idel_time = 0;
      cout<<idel_time<<"    ";
    }
    int gant_chart = p[0].arrivalTime;
    cout<<gant_chart<<"    ";

    for(int i=0;i<counter;++i)
    {
      Start[i] =gant_chart;
      WaitingTime[i] = gant_chart - p[i].arrivalTime ;
      gant_chart+=p[i].BurstTime;
      End[i] = gant_chart;
      TurnAroundTime[i] = gant_chart - p[i].arrivalTime;
      cout<<"  "<<gant_chart<<"  ";
      AvgWaitingTime +=WaitingTime[i];
      AvgTurnAroundTime+=TurnAroundTime[i];
    }

    cout<<"\n"<<"\n";
    cout<<"Avg Waiting Time = "<<AvgWaitingTime/counter<<"\n";
    cout<<"Avg Turnaround Time = "<<AvgTurnAroundTime/counter<<"\n";
    cout<<"========================================================="<<"\n";
    cout<<"Process  |"<<"Arrive |"<<"Brust  |"<<"Start  |"<<"End    |"<<"Turn   |"<<"Wait   |"<<"\n";
    for(int i=0;i<counter;++i)
    {
      cout<<"--------------------------------------------------------"<<"\n";
      cout<<p[i].name<<"\t | "<<p[i].arrivalTime<<"\t | "<<p[i].BurstTime<<"\t | "<<Start[i]<<"\t | "<<End[i]<<"\t | "<<TurnAroundTime[i]<<"\t | "<<WaitingTime[i]<<"\t | "<<"\n";
    }
}

bool FCFS_Sort_Burst(process p1 , process p2)
{
  return p1.BurstTime < p2.BurstTime;
}
void SJF_Non_Premetive()
{
          cout<<"\n\n\n\n\t*** SJF_Non_Premetive ***\n";

  process p[100];
ifstream File("Data.txt");
int counter = 0;
while(File>>p[counter].name>>p[counter].arrivalTime>>p[counter].BurstTime)
  {
    ++counter;
  }
  File.close();
    sort(p,p+counter,FCFS_Sort_Burst);
    sort(p,p+counter,FCFS_Sort);
    cout<<"process"<<" | "<<"Arrival Time"<<"  | "<<"Burst Time"<<"\t|\n";
  for(int i=0;i<counter;++i){
     cout<<"-----------------------------------------"<<"\n";
    cout<<p[i].name<<"\t"<<"|      "<<p[i].arrivalTime<<"\t"<<"|"<<"     "<<p[i].BurstTime<<"\t|\n";
  }
  bool idel = false;
    if(p[0].arrivalTime!=0)
      idel = true;
      int ttime =0;
      if(idel)
          {
              ttime = p[0].arrivalTime;
          }
    int i;
    int j,tArray[100];
    for(i=0;i<counter;i++){
        j=i;
        while(p[j].arrivalTime<=ttime&&j!=counter){
            j++;
        }
        sort(p+i,p+j,FCFS_Sort_Burst);
        tArray[i]=ttime;
        ttime+=p[i].BurstTime;
    }
    tArray[i] = ttime;
    float averageWaitingTime=0;
    float averageTAT=0;
    cout<<"\n";
   cout<<"-----------------------------------------"<<"\n";

    cout<<" * Gant Chart * "<<"\n";
     cout<<"----------------------------------------------------------------------------"<<"\n";
if(idel)
          cout<<"|"<<" "<<"id"<<" ";
    for (i=0; i<counter; i++){
        cout<<"|"<<"  "<<p[i].name<<"  ";
    }
    cout<<"| \n";
     cout<<"----------------------------------------------------------------------------"<<"\n";
     if(idel)
    {
      int idel_time = 0;
      cout<<idel_time<<"    ";
    }
    int gant_chart = p[0].arrivalTime;
    for (i=0; i<counter+1; i++){
        cout<<tArray[i] <<"    ";
    }
    int start[100],End[100],Turn[100],Wait[100];

    for(int i=0;i<counter;++i)
    {
        start[i] = gant_chart;
        End[i] = tArray[i+1];
        Turn[i] = tArray[i]-p[i].arrivalTime+p[i].BurstTime;
        Wait[i] = tArray[i]-p[i].arrivalTime;
        averageTAT+=tArray[i]-p[i].arrivalTime+p[i].BurstTime;
        averageWaitingTime+=tArray[i]-p[i].arrivalTime;
    }
    cout<<"\n"<<"\n";
    cout<<"Average Waiting time: "<<(float)averageWaitingTime/(float)counter<<endl;
    cout<<"Average TA time: "<<(float)averageTAT/(float)counter<<endl;
    cout<<"========================================================="<<"\n";
    cout<<"Process  |"<<"Arrive |"<<"Brust  |"<<"Start  |"<<"End    |"<<"Turn   |"<<"Wait   |"<<"\n";
    for(int i=0;i<counter;++i)
    {
    cout<<"--------------------------------------------------------\n";
    cout<<p[i].name<<"\t | "<<p[i].arrivalTime<<"\t | "<<p[i].BurstTime<<"\t | "<<start[i]<<"\t | "<<End[i]<<"\t | "<<Turn[i]<<"\t | "<<Wait[i]<<"\t | "<<"\n";
    }
}
void SJF_Premetive()
{
      cout<<"\n\n\n\n\t*** SJF_Premetive ***\n";
  process p[100];
ifstream File("Data.txt");
int counter = 0;
int WaitingTime[100],TurnaroundTime[100],Start[100]={0},End[100]={0};
while(File>>p[counter].name>>p[counter].arrivalTime>>p[counter].BurstTime)
{
    ++counter;
}
File.close();
sort(p,p+counter,FCFS_Sort);

   int rt[100];
   for (int i = 0; i < counter; i++)
   rt[i] = p[i].BurstTime;
   int complete = 0, t = 0, minm = INT_MAX;
   int shortest = 0, finish_time;
   bool check = false;
   while (complete != counter) {
      for (int j = 0; j < counter; j++) {
      if ((p[j].arrivalTime <= t) && (rt[j] < minm) && rt[j] > 0) {
            minm = rt[j];
            shortest = j;
            check = true;
         }
      }
      if (check == false) {
         t++;
         continue;
      }
      rt[shortest]--;
      minm = rt[shortest];
      if (minm == 0)
         minm = INT_MAX;

         if (rt[shortest] == 0) {
            complete++;
            check = false;
            finish_time = t + 1;
            WaitingTime[shortest] = finish_time - p[shortest].BurstTime -p[shortest].arrivalTime;
            if (WaitingTime[shortest] < 0)
               WaitingTime[shortest] = 0;
         }
         t++;
}
   for (int i = 0; i < counter; i++){
   TurnaroundTime[i] = p[i].BurstTime + WaitingTime[i];
   End[i] = TurnaroundTime[i]+p[i].arrivalTime;
   }
   int total_wt = 0,total_tat = 0;

   cout<<"Process  |"<<"Arrive |"<<"Burst  |"<<"Start  |"<<"End    |"<<"Turn   |"<<"Wait   |"<<"\n";
   for (int i = 0; i < counter; i++) {
      total_wt = total_wt + WaitingTime[i];
      total_tat = total_tat + TurnaroundTime[i];
    cout<<"-------------------------------------------------------------\n";
    cout <<p[i].name << "\t | " <<p[i].arrivalTime<<"\t | "<< p[i].BurstTime <<"\t | "<<Start[i]<<"\t | "<<End[i]<<"\t | "<< TurnaroundTime[i]<<"\t | "<< WaitingTime[i]<<"\t | "<< endl;
   }
   cout<<"-------------------------------------------------------------\n";
   cout << "\n"<<"Average waiting time = " << (float)total_wt / (float)counter<<"\n";
   cout << "Average turn around time = " << (float)total_tat / (float)counter<<"\n";
 }
void Round_Robin()
{

    cout<<"\n\n\n\n\t*** Round Robin ***\n";

  int quantum;
  process p[100];
int End[100],Start[100],WaitingTime[100],TurnaroundTime[100];
  float avg_turnaround_time, avg_waiting_time;
  int total_turnaround_time = 0, total_waiting_time = 0, burst_remaining[100];
  ifstream File("Data.txt");
  int counter = 0;
  while(File>>p[counter].name>>p[counter].arrivalTime>>p[counter].BurstTime)
  {
    counter++;
  }
  File.close();
cout<<"process"<<" | "<<"Arrival Time"<<"  | "<<"Burst Time"<<"\t|\n";
  sort(p,p+counter,FCFS_Sort);
  for(int i=0;i<counter;++i)
  {
    burst_remaining[i] = p[i].BurstTime;
cout<<"-----------------------------------------"<<"\n";
    cout<<p[i].name<<"\t"<<"|      "<<p[i].arrivalTime<<"\t"<<"|"<<"     "<<p[i].BurstTime<<"\t|\n";
  }
  cout<<"-----------------------------------------"<<"\n";
  cout<<"Enter time quantum: ";
  cin>>quantum;
  if(quantum<=0)
  {
    cout<<"you enter wrong quantum num quantum num must be >0 !!\n\n";
  }
  else
  {
    int current_time = 0, completed = 0;
    while(completed != counter) {
      for(int c=0;c<counter;c++){
        if(burst_remaining[c] > 0) {
          if(burst_remaining[c] == p[c].BurstTime) {

            Start[c] = max(current_time,p[c].arrivalTime);

            current_time = Start[c];
          }

          if(burst_remaining[c]-quantum > 0) {
            burst_remaining[c] -= quantum;
            current_time += quantum;
          }
          else {
            current_time += burst_remaining[c];
            burst_remaining[c] = 0;
            completed++;

            End[c] = current_time;
            TurnaroundTime[c] = End[c] - p[c].arrivalTime;
            WaitingTime[c] = TurnaroundTime[c] - p[c].BurstTime;


            total_turnaround_time += TurnaroundTime[c];
            total_waiting_time += WaitingTime[c];

          }
        }
      }

    }
    avg_turnaround_time = (float) total_turnaround_time / counter;
    avg_waiting_time = (float) total_waiting_time / counter;
        cout<<"\n"<<"\n";
        cout<<"\n"<<"\n";
    cout<<"Avg Waiting Time = "<<avg_waiting_time<<"\n";
    cout<<"Avg Turnaround Time = "<<avg_turnaround_time<<"\n";
    cout<<"========================================================="<<"\n";
    cout<<"Process  |"<<"Arrive |"<<"Brust  |"<<"Start  |"<<"End    |"<<"Turn   |"<<"Wait   |"<<"\n";
    for(int i = 0; i < counter; i++) {
               cout<<"--------------------------------------------------------"<<"\n";
      cout<<p[i].name<<"\t | "<<p[i].arrivalTime<<"\t | "<<p[i].BurstTime<<"\t | "<<Start[i]<<"\t | "<<End[i]<<"\t | "<<TurnaroundTime[i]<<"\t | "<<WaitingTime[i]<<"\t | "<<"\n";
    }
  }
}

int main()
{
  int n;
  do
  {
      cout<<"=================================================\n\n";
        cout<<"\t*****CPU Scheduling Algorithms*****\n\n2";
        cout<<"=================================================\n\n";


  cout<<"\t 1. First Come First Served (FCFS)\n\t 2. Shortest Job First non-preemptive (SJFnp)\n\t 3. Shortset Job First preemptive (SJFnp) scheduler\n\t 4.Round-Robin (RR) scheduler\n\t 5.All algorithms \n\t 6. Exit\n";
        cout<<"\n\t Enter your choice [0-5] : ";


  cin>>n;
  cout<<"your choice = "<<n<<"\n";
  if(n==1)
    FCFS();
  else if(n==2)
    SJF_Non_Premetive();
  else if(n==3)
    SJF_Premetive();
  else if(n==4)
    Round_Robin();
    else if (n==5)
    {
         FCFS();
         SJF_Non_Premetive();
         SJF_Premetive();
          Round_Robin();

    }
  else
    return 0;
  }
  while(n>0&&n<7);
}
