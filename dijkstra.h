#ifndef _DIJ_
#define _DIJ_
#include <vector>
#include <iostream>
#include "stdc++.h"
#include <limits>
#include <fstream>
#include <string>
#include <iomanip>
#include <string.h>
using namespace std;
struct Pairs{
	//Struct pair node weight
	int v;
	double w;

};

bool operator <(const Pairs& x, const Pairs& y);
double path(vector< vector<Pairs> > G,vector<int>& predecesor, int s, int d,vector<int>& p);
bool dijsktra(vector< vector<Pairs> > G,int s,int d,int flag,vector<int>& predecesor,vector<bool>& visited);
bool isdigit2(char ch);
bool is_number(const string &s) ;
void makeGraph(char* name,char* direct, vector<vector<Pairs> >& G);
double DFS(vector<vector<Pairs> > G,vector<bool>& visited,int u);
void INPUTOUPUT(vector<vector<Pairs> > G);

#endif