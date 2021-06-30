#include "dijkstra.h"
using namespace std;

int inf =numeric_limits<int>::max();





bool operator <(const Pairs& x, const Pairs& y) {
	// overload operator
    return x.w>y.w;
}





double path(vector< vector<Pairs> > G,vector<int>& predecesor, int s, int d,vector<int>& p){
	//function path given a graph and a predecesor and nodes s-d array returns a path from s to d and weight of this path
	
	if(s==d){
		p.push_back(d);
		return 0;
	}
	else{
		int b=predecesor[d];
		
		if(b==-1){
			return -1;
		}
		double w;
		for( int i =0;i<G[b].size();i++){
			if(G[b][i].v==d){
				w=G[b][i].w;
				break;
			}
		}
		double a=w+ path(G,predecesor,s,b,p);
		p.push_back(d);
		
		return a;
	}

}



bool dijsktra(vector< vector<Pairs> > G,int s,int d,int flag,vector<int>& predecesor,vector<bool>& visited){
	// modified dijktra algorithm, given a graph and two vertex s d returns a predecesors array
	
	Pairs sour ={s,0};
	vector<Pairs> queue={sour};
	vector<double> ans;

	for(int i=0;i<G.size();i++){
		ans.push_back(inf);
	}
	ans[s]=0;
	if(flag){
		cout
		<<"Insert vertex "
		<<s
		<<", key="
		<<setprecision(4)
		<<setw(12)
		
		<<0.0 

		<<endl;
	}
	make_heap(queue.begin(),queue.end());

	while(queue.size()!=0){
		//cout<<queue.size()<<endl;
		Pairs U=queue.front();

		pop_heap(queue.begin(), queue.end());
    	queue.pop_back();

    	
    	if(flag &&!visited[U.v]){

    		cout
    		<<"Delete vertex "
    		<<U.v
    		<<", key="
    		<<setprecision(4)
    		<<setw(12)
    	    <<fixed	
    		<<ans[U.v]

    		<<endl;
    	}

    	if(!visited[U.v]&&U.v==d){
    			visited[U.v]=true;
    			return true;
    	}
    	
    	if(!visited[U.v]){
    		
    		for(int i=G[U.v].size()-1;i>=0;i--){
    			if(U.w+G[U.v][i].w< ans[G[U.v][i].v]){
    				if(flag){
    					if(!(ans[G[U.v][i].v]<inf)){
    						cout
    						<<"Insert vertex "
    						<<G[U.v][i].v<<", key="
    						<<setprecision(4)
    						<<setw(12)
    						<<fixed	
    						<<U.w+G[U.v][i].w <<endl;
    					}
    					else{
    						cout
    						<<"Decrease key of vertex "
    						<< G[U.v][i].v
    						<<", from"
    						<<setw(13)
    						<<fixed	
    						<<ans[G[U.v][i].v]
    						<<" to"
    					
    						<<setprecision(4)
    						<<setw(13)
    						<<fixed	
    						<<U.w+G[U.v][i].w <<endl;
    					}
    				}
    				
    				ans[G[U.v][i].v]=U.w+G[U.v][i].w;
    				Pairs temp={G[U.v][i].v, ans[G[U.v][i].v]};
    				queue.push_back(temp);
    				push_heap(queue.begin(), queue.end());
    				predecesor[G[U.v][i].v]=U.v;
    				
    			}
    		}
    	}
    	
    	visited[U.v]=true;
	}

	return false;
}




bool isdigit2(char ch){
	// is digit  this auxiliar function for a part of a number
	return ch=='-' or isdigit(ch);
}


bool is_number(const string &s) {
	//return true if s is a number
  return !s.empty() && std::all_of(s.begin(), s.end(), isdigit2);
}

void makeGraph(char* name,char* direct, vector<vector<Pairs> >& G){
	//given a name of if is directed return a graph G
	ifstream myfile (name);

		if (myfile.is_open()){

		  	
		  	int u,v,id,n,m;
		  	myfile>>n>>m;
		  	double w;
		  	for(int i =0;i<n+1;i++){
		  		vector<Pairs> t;
		      	G.push_back(t);
		    }
		    for(int i =0;i<m;i++){
		      
		      if (myfile.eof())
						break;

			  myfile>>id>>u>>v>>w;	

		  
		      if(strcmp(direct, "undirected") == 0){
		      	Pairs t={u,w};
		      	G[v].push_back(t);
		      }

		      Pairs t={v,w};

		 
		      G[u].push_back(t);


		  }
		  myfile.close();
		}
}



double DFS(vector<vector<Pairs> > G,vector<bool>& visited,int u){
	//DFS function
	visited[u]=true;
	float ans=0;
	for(int i=0;i<G[u].size();i++){
		if(!visited[G[u][i].v]){
			ans+=DFS(G,visited,G[u][i].v);
		}
	}
	return ans;
}



void INPUTOUPUT(vector<vector<Pairs> > G){
		//INPUTOUPUT this function read input in STDIN and return in STDOUT 
		string f;
		vector<bool> visited(G.size(),false);
		int source,destination,flag;
		string ssource,sdestination,sflag;
		cin>>f;
		bool broke=false;
		vector<int> predecesor(G.size(),-1);
		while (f!="stop"){
		  
		  	if(f=="find"){ //find <s> <d> <flag>
		  		
		  			cin>>ssource>>sdestination>>sflag;
		  			//error cases
		  			if(!is_number(ssource)){
		  				f=ssource;
		  				continue;
		  			}
		  			else{
		  				source=atoi(ssource.c_str());
		  			}

		  			if(!is_number(sdestination)){
		  				f=sdestination;
		  				continue;
		  			}
		  			else{
		  				destination=atoi(sdestination.c_str());
		  			}

		  			if(!is_number(sflag)){
		  				f=sflag;
		  				continue;
		  			}
		  			else{
		  				flag=atoi(sflag.c_str());
		  			}

		  			cout<<"Query: "<<f<<" "<<source<<" "<<destination<<" "<<flag<<endl;
		  			if(source>=G.size()){
		  				cin>>f;
		  				continue;
		  			}
		  			vector<bool> visited(G.size(),false);
		  			broke=dijsktra(G,source,destination,flag,predecesor,visited);	
		  	}
		  	else if(f=="write"){ //write path <s> <d>
		  		
		  		int s,d;
		  		string g;
		  		cin>>g;
		  		cin>>s>>d;
		  		cout<<"Query: "<<f<<" "<<g<<" "<<s<<" "<<d<<endl;
		  		vector<int> p;


		  		if(s!=source || d>=G.size()){ //error case
					cout<<"Error: invalid source destination pair"<<endl;
		  		}
		  		else{
			  		double x=path(G,predecesor,s,d,p); //call path punction
			  	
			  		if(visited[d] || !broke || d==destination){ //if was computed the solution
			  		
				  		if(x==-1.000){ //there is not path
				  			cout<<"No "<<s<<"-"<<d<<" path exists."<<endl;
				  		}
				  		else{
				  			cout<<"Shortest path: <";
				  			for(int i=0;i<p.size()-1;i++)
				  				cout<<p[i]<<", ";
				  			cout<<p[p.size()-1];
				  			cout<<">"<<endl;
				  			cout<<"The path weight is:"
				  			<<setw(13)
		    				<<fixed	
		    				<<setprecision(4)
				  			<<x
				  			<<endl;
				  		}
				  	}
				  	else{
				  		if(x==-1.000){ //path not computed
				  			cout<<"No "<<s<<"-"<<d<<" path has been computed."<<endl;
				  		}
				  		else{ 
				  			//not sure shortest
				  			cout<<"Path not known to be shortest: <";
				  			for(int i=0;i<p.size()-1;i++)
				  				cout<<p[i]<<", ";
				  			cout<<p[p.size()-1];
				  			cout<<">"<<endl;
				  			cout<<"The path weight is:"
				  			<<setw(13)
		    				<<fixed	
		    				<<setprecision(4)
				  			<<x
				  			<<endl;
				  		}
				  	}
		  		}

		  	}
		  	cin>>f;
		  }
		  cout<<"Query: "<<f<<endl;
		  		
}


int main(int argc, char *argv[]){
	if (argc>1){
		cout<<fixed;
		vector< vector<Pairs> > G;
		makeGraph(argv[1],argv[2],G);
		INPUTOUPUT(G);  	  
	}	  
	else{
		cout<<"invalid parameters"<<endl;

	
	}
}