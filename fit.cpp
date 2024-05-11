/*    1. Write a program in C to implement the concept of variable sized partition use by the process request using Best fit, First Fit, Next Fit and Worst Fit algorithm.
Use case: 
Input: Consider six memory partition of 300 KB, 600 KB, 350 KB, 200 KB, 750 KB, and 125 KB (in order), 
Process Request: 115 KB, 500 KB, 358 KB, 200 KB, and 375 KB (in order).
Output: Allocation and rank which algorithm perform better in terms of internal fragmentation.*/


#include<iostream>
using namespace std;
//first
int firstfit(int mem,int pro,int memsize[],int processsize[])
{
	int allocate[mem] ;
	int newmem[mem];
    for (int i = 0; i < pro; i++) 
	 {
        allocate[i] = -1;  
        newmem[mem] = -1;
	 }
	for(int i = 0; i<mem ; i++)
	{
		for(int j=0 ;j<i ; j++)
		{
		if (processsize[j]<memsize[i])
		  {
			allocate[i]=processsize[i];
			
		  }
		  newmem[i] = memsize[i] - processsize[i];
	   }
    }
	cout<<"\nProcess No.\tProcess Size\tBlock no.\n"; 
    for (int i = 0; i < mem; i++) 
    { 
        cout << " " << i+1 << "\t\t"<< processsize[i] << "\t\t"<<memsize[i]<< "\t\t"<<newmem[i]; 
        
        if (allocate[i] != -1) 
            cout << allocate[i] + 1; 
        else
            cout << "Not Allocated"; 
        cout << endl; 
    } 
    
    return 0;
}
//best
int bestfit(int mem,int pro,int memsize[],int processsize[])
{
	int allocate[mem];
	int newmem[mem];
    for (int i = 0; i < mem; i++)  {
    
       allocate[i] = -1;  
       newmem[i] = -1;
}
    for (int i = 0; i < pro; i++)  
    {  
        
        int best = -1;  
        for (int j = 0; j < mem; j++)  
        {  
            if (memsize[j] >= processsize[i])  
            {  
                if (best == -1)  
                    best = j;  
                else if (memsize[best] > memsize[j])  
                    best = j;  
            }  
        }   
        if (best != -1)  
        {  
            allocate[i] = best;  
            newmem[i] = memsize[best] - processsize[i];  
        }  
    }  
  
	cout << "\nProcess No.\tProcess Size\tBlock no.\n"; 
    for (int i = 0; i < mem; i++) 
    { 
        cout << " " << i+1 << "\t\t"<< processsize[i] << "\t\t"<<memsize[i]<< "\t\t"<<newmem[i];; 
        
        if (allocate[i] != -1) 
            cout << allocate[i] + 1; 
        else
            cout << "Not Allocated"; 
        cout << endl; 
    } 
    
    return 0;
}
//worst
int worstfit(int mem,int pro,int memsize[],int processsize[])
{
	int allocate[mem];
	int newmem[mem];
    for (int i = 0; i < mem; i++)  {
    
       allocate[i] = -1;  
       newmem[i] = -1;
}
    for (int i = 0; i < pro; i++)  
    {  
        
        int worst = -1;  
        for (int j = 0; j < mem; j++)  
        {  
            if (memsize[j] >= processsize[i])  
            {  
                if (worst == -1)  
                    worst = j;  
                else if (memsize[worst] > memsize[j])  
                    worst = j;  
            }  
        }   
        if (worst != -1)  
        {  
            allocate[i] = worst;  
            newmem[i] = memsize[worst] - processsize[i];  
        }  
    }  
  
	cout << "\nProcess No.\tProcess Size\tBlock no.\n"; 
    for (int i = 0; i < mem; i++) 
    { 
        cout << " " << i+1 << "\t\t"<< processsize[i] << "\t\t"<<memsize[i]<< "\t\t"<<newmem[i];; 
        
        if (allocate[i] != -1) 
            cout << allocate[i] + 1; 
        else
            cout << "Not Allocated"; 
        cout << endl; 
    } 
    
    return 0;
}

//next


int main()
{
	int mem = 6;
	int memsize[6] = {300,600,350,200,750,125};
	int pro = 5;
	int processsize[5] = {115,500,358,200,375};
	
	
	 firstfit(mem,pro,memsize,processsize);
   	bestfit(mem,pro,memsize,processsize);
	worstfit(mem,pro,memsize,processsize);

	
	return 0;
	
}
