//.......................................................................................................
//.......................................................................................................
// IMPLEMENTATION OF " BELLMAN FORD ALGORITHM "
//  TO FIND SHORTEST DISTANCE FROM ROOT
//  AND IDENTIFY NEGATIVE WEIGHT CYCLE
//.......................................................................................................
//.......................................................................................................

#include<iostream>
#include<stdio.h>
#include<vector>
#include<utility>
#include<map>
#include<set>
#include<algorithm>
#include<limits.h>
#include<iomanip>
#include<ctime>
using namespace std;
const int maxx=INT_MAX-20;

//.......................................................................................................
// Class Graph
//.......................................................................................................
class Graph
{
	public:
		int N,V,root;
		int *distance,*parent;
		map < pair < int,int >, int > Edge_W;
		vector < pair <int,int> > Edge;
		vector< pair <int,int> >::iterator it;
		
//.......................................................................................................
// Initialising graph	
//.......................................................................................................			
		Graph(int x)						
		{
				N=x; V=x; 
				distance=new int[V+10];
				parent=new int[V+10];
				for(int i=0;i<=V+1;i++)
					{	distance[i]=maxx; parent[i]=i;	}
		}	
		
//.......................................................................................................
//Function to insert Edges
//.......................................................................................................
		void insert_edge(int a,int b,int weight)
			{		
					Edge.push_back(make_pair(a,b));
					Edge_W.insert(make_pair(make_pair(a,b),weight));
					
			}	

//.......................................................................................................
// Function to relax edges as per shostest distance till now
//.......................................................................................................		
		void relax(int a,int b)
		{
			if(distance[a]!=maxx)
				{
					if(distance[b]>=distance[a]+Edge_W[make_pair(a,b)])
					{	distance[b]=distance[a]+Edge_W[make_pair(a,b)];		parent[b]=a;	}	
				}	
		}
			
//.......................................................................................................
// Apply Bellman Ford Algorithm
//.......................................................................................................			
		void apply_BFA(int start)
		{		
				bool negative_cycle=false;	root=start;
				int a,b;
				distance[start]=0;
				
				for(int i=0;i<V-1;i++)
				{
					 
					
					for(it=Edge.begin();it!=Edge.end();it++)
						{
							a=(*it).first; b=(*it).second;
							relax(a,b);
						}
				}
				
				for(it=Edge.begin();it!=Edge.end();it++)
				{
						a=(*it).first; b=(*it).second;
						if(distance[b]>distance[a]+Edge_W[make_pair(a,b)])
							{	negative_cycle=true;break;		}
				}
				
				if(negative_cycle)
					{
						cout<<"Graph Contain Negative Cycle\n";
					}
				else
					{
						cout<<"Graph does not contain negative Cycle\nMinimum Distance of Each Vertex from "<<root<<endl;
						for(int i=1;i<=V;i++)
						{
							cout<<i<<" -> "<<distance[i]<<endl;
						}
					}	
		}	
			
	
};





//.......................................................................................................
// Main Driver Function
//.......................................................................................................


int main()
{		
//.......................................................................................................
	cout<<"\nTEST CASE 1\n";				//TEST CASE 1
		Graph g(8);

		g.insert_edge(1,3,8);
		g.insert_edge(1,2,4);
		g.insert_edge(2,8,5);
		g.insert_edge(2,7,-3);
		g.insert_edge(3,8,4);
		g.insert_edge(4,5,2);
		g.insert_edge(5,6,1);
		g.insert_edge(5,7,4);
		g.insert_edge(3,4,8);
		g.insert_edge(8,5,1);
	
    
    	 	clock_t tStart = clock();			//TIME ANALYSIS
		g.apply_BFA(1);
		cout<<"Time taken: "<<(double)(((double)(clock()) - (double)(tStart))/CLOCKS_PER_SEC)<<endl;
	
//.......................................................................................................	
		cout<<"\nTEST CASE 2\n";			//TEST CASE 2
		Graph g1(8);

		g1.insert_edge(1,3,8);
		g1.insert_edge(1,2,4);
		g1.insert_edge(2,8,5);
		g1.insert_edge(2,7,-3);
		g1.insert_edge(3,8,4);
		g1.insert_edge(4,5,2);
		g1.insert_edge(5,6,1);
		g1.insert_edge(5,7,4);
		g1.insert_edge(3,4,8);
		g1.insert_edge(8,5,1);	
		g1.insert_edge(7,8,-9);
    
    		 clock_t tStart1 = clock();			//TIME ANALYSIS
		g1.apply_BFA(1);
		cout<<"Time taken: "<<(double)(((double)(clock()) - (double)(tStart1))/CLOCKS_PER_SEC)<<endl;

//.......................................................................................................
		cout<<"\nTEST CASE 3\n";			//TEST CASE 3
		Graph g2(5);

		g.insert_edge(1,4,8);
		g.insert_edge(1,2,4);
		g.insert_edge(1,3,5);
		g.insert_edge(2,3,-3);
		g.insert_edge(3,5,4);
		g.insert_edge(4,5,2);
		g.insert_edge(5,3,1);

    
    		 clock_t tStart2 = clock();			//TIME ANALYSIS
		g.apply_BFA(1);
		cout<<"Time taken: "<<(double)(((double)(clock()) - (double)(tStart2))/CLOCKS_PER_SEC)<<endl;
		
//.......................................................................................................		
		cout<<"\nTEST CASE 4\n";			//TEST CASE 4
		Graph g3(4);

		g3.insert_edge(1,2,2);
		g3.insert_edge(2,3,2);
		g3.insert_edge(3,4,3);
		g3.insert_edge(4,2,-8);
		
    
    	 	clock_t tStart3 = clock();			//TIME ANALYSIS
		g3.apply_BFA(1);
		cout<<"Time taken: "<<(double)(((double)(clock()) - (double)(tStart3))/CLOCKS_PER_SEC)<<endl;


return 0;
		
}
