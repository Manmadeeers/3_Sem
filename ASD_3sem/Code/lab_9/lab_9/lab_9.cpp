//<-------------------->
//
// Implementing genetic algorithm for a graph
// 
//<-------------------->



#include <iostream>
#include <vector>
#include <random>
using namespace std;
#define INF INT_MAX
#define CITIES 9

struct Individual {
	vector<int>route;
	int fitness;
};

//<-----util functions----->
void implementGraph(vector<vector<int>>&graph,int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == j) {
				graph[i][j] = 0;
			}
			else {
				graph[i][j] = INF;
			}
		}
	}
}
void printGrph(vector<vector<int>>graph) {
	int size = graph.size();
	for (int l = 0; l < size; l++) {
		cout << l + 1 << '\t';
	}
	cout <<endl<< endl;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (graph[i][j] == INF) {
				cout << "INF"<<'\t';
			}
			else {
				cout << graph[i][j]<<'\t';
			}
			
		}
		cout<<i+1 << endl;
	}
	cout << endl << endl;
}

void addEdge(int from, int to, int weight,vector<vector<int>>&graph) {
	graph[from][to] = weight;
}

void deleteEdge(int from, int to, vector<vector<int>>& graph) {
	graph[from][to] = INF;
}


//<-----end of util functions----->


void main() {


	int graph_size;
	cout << "Enter the amount of cities: ";
	cin >> graph_size;
	/*int mutation;
	cout << "Enter the mutation rate: ";
	cin >> mutation;
	int mates_amount;
	cout << "Enter the mates amount: ";
	cin >> mates_amount;
	int offspring_after_mate;
	cout << "Enter the amount of children after each mate: ";
	cin >> offspring_after_mate;
	int evolutions;
	cout << "Enter the amount of evolutions: ";
	cin >> evolutions;*/
	system("cls");

	vector<vector<int>>graph(CITIES, vector<int>(CITIES));

	implementGraph(graph, CITIES);
	printGrph(graph);

	 
	
}