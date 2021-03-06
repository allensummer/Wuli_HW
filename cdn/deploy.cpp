#include "deploy.h"
#include "geneticAL.h"
#include <stdio.h>

char* vec_to_int(vector<vector<int >> path)
{
	char* in=(char*)malloc(sizeof(int)+1);
	string str;	
	int pi = path.size();
	sprintf(in, "%d", pi);
	str += in;
	str += "\n\n";
	for (size_t i = 0; i< path.size() ;i++)
	{
		for (size_t j = 0; j < path[i].size(); j++)
		{
			pi = path[i][j];
			sprintf(in, "%d", pi);
			str += in;
			if (j != path[i].size() - 1) {
				str += " ";
			}
		}
		if (i != path.size() - 1) {
			str += "\n";
		}
	}
	int len = str.length();
	char *topo = (char *)malloc((len + 1)*sizeof(char));
	strcpy(topo, str.c_str());
	free(in);
	return topo;
};


void deploy_server(char * topo[MAX_EDGE_NUM], int line_num,char * filename)
{
	Topology T;
	T.GraphInit(topo, line_num);
	T.init();

	GA ga(T, 10000);
	vector<vector<int>> route = ga.getBestServersPos(60);
	
	
	char * topo_file = vec_to_int(route);//(char *)"17\n\n0 8 0 20\n21 8 0 20\n9 11 1 13\n21 22 2 20\n23 22 2 8\n1 3 3 11\n24 3 3 17\n27 3 3 26\n24 3 3 10\n18 17 4 11\n1 19 5 26\n1 16 6 15\n15 13 7 13\n4 5 8 18\n2 25 9 15\n0 7 10 10\n23 24 11 23";
	

	write_result(topo_file, filename);
}
