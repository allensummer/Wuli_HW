#include<iostream>
#include<vector>
#include<fstream>
#include<cstring>
#include<stack>
#include<unordered_map>
using namespace std;
#define MAX_EDGE_NUM    (2000 * 20)
#define MAX_NODE_NUM    1600

struct edge            //Edge Information with Node
{
	int v_next;      //Next Node
	int bandwith;   //
	int cost;        //
};

struct edgev_v            //Independent Edge Information
{
	int in;      
	int out;      
	int bandwith;   
	int cost;       
	int next=-1;       
};
struct v_net
{
	int v_id;
	bool is_consumer = false;         //Connetct With Consumer Node?
	vector<edge>  edge_list;          //Edge List
};
struct v_consum
{
	int con_id;
	int v_id;                    //Connected Net Node ID 
	int demand;                  //Consume Demand
};

class GraphLinkedTable
{
	private:
		vector<v_net> vertex;
		vector<v_consum> consume;
		int v_count;               //Net Node Num
		int e_count;               //Edge Num
		int c_count;               //Consumer Node Num
		int ServerCost;            //Server Cost
	protected:
		vector<edgev_v> vec_edge;      //All the Edge Infomation
		vector<int> headEdge;           //first Edge No of Vertex
		int gHead[MAX_NODE_NUM];
		int gEdgeCount;            //edge No increase
		unordered_map<int,vector<int>>  Ind_netNodes;//Net node ID not connected with the comsumer node
	public:
		GraphLinkedTable();
		~GraphLinkedTable(){}
		void SetGraphPara(int v_n, int e_n, int c_n,int sc);  
		void InsertEdge(int v1, int v2, int b, int c);       //insert one edge information
		void InsertEdgev_v(int v1, int v2, int b, int c);       //insert all edges infomation
		void InsertConsume(int c, int v, int dem);           //insert consumer node information
		void PrintNetListInfo();                             //print net node information
		void  PrintConNodeInfo();                             //print consumer node information
		void PrintEdgeInfo();                                 //print all edges' information
		int GetEdgebw(int v1, int v2);                       //return bandwith between two nodes,if not exist,return 0
		int GetEdgecost(int v1, int v2);                     //rreturn cost between two nodes,if not exist,return 0
		vector<int> GetNeiborNode(int v);                    //return nextNodes
		int GetConLinkNode(int cv);                          //return the net node id connected with consumer node,if the id is not exist,return infinity
		int GetNetLinkNode(int nv);                          //return the consumer node id connected with net node	,if the id is not exist,return infinity
		int GetConDemand(int cv);                            //return demand ofconsumer node,if the id is not exist,return infinity
		int GetServerCost();                                 //return  Server Cost
		int GetVNum();                                       //return the number of net node 
		int GetCNum();                                       //return the number of consumer node
		int GetVEdge(int v);                                 //Return Every node's degree
		void GraphInit(char * topo[MAX_EDGE_NUM], int line_num);
		stack<int> str_to_int(char *s);
		int ReturnEdgeNo(int in,int out);                     //return the No of net node
		void PrintHeader();                                    //Print first Edge No of One Node
		void makeInd_netNodes();                               //make unordered map of net node list of not connected with the key comsumer node
		void PrintInd_netNodes();                              //test makeInd_netNodes()
};



