//<-------------------->
//
// Implementing genetic algorithm for a graph
// 
//<-------------------->



#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
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
	graph[from-1][to-1] = weight;
}

void deleteEdge(int from, int to, vector<vector<int>>& graph) {
	graph[from-1][to-1] = INF;
}

int calculateDistance(vector<int>& path,vector<vector<int>>graph) {
	int distance = 0;
	for (int i = 0; i < path.size()-1; ++i) {
		int from = path[i];
		int to = path[i + 1];
		distance += graph[from][to];
	}
	return distance;
}
vector<int>generateRandomPath(std::mt19937 rdm) {
	vector<int>random_path(CITIES);
	for (int i = 0; i < CITIES; i++) {
		random_path[i] = i;
	}
	shuffle(random_path.begin(), random_path.end(), rdm);
	return random_path;
}

vector<int> corssover(vector<int>parent1, vector<int>parent2,int crossover_num) {
	vector<int>child(CITIES);

	int crossover_point = rand() % (CITIES - 1) + 1;
	for (int i = 0; i < crossover_point; ++i) {
		child[i] = parent1[i];
	}
	for (int i = crossover_point + 1; i < CITIES; ++i) {
		child[i] = parent2[i];
	}

	return child;
}

void mutate(vector<int>& individual,std::mt19937 rnd,int mutation_rate) {
	if (rand() % 100< mutation_rate) {
		int index1 = rnd() % CITIES;
		int index2 = rnd() % CITIES;
		swap(individual[index1], individual[index2]);
	}
}


	//<-----end of util functions----->


void main() {
	srand(time(nullptr));

	int population_size;
	cout << "Enter the population size: ";
	cin >> population_size;
	float mutation;
	cout << "Enter the mutation rate(between 0 and 1): ";
	cin >> mutation;
	int crossovers_amount;
	cout << "Enter the crossovers amount: ";
	cin >> crossovers_amount;
	int evolutions;
	cout << "Enter the amount of evolutions(not less then 50): ";
	cin >> evolutions;
	system("cls");

	vector<vector<int>>graph(CITIES, vector<int>(CITIES));

	implementGraph(graph, CITIES);
	printGrph(graph);

	addEdge(1, 2, 10, graph);
	addEdge(2, 1, 8, graph);
	addEdge(1, 3, 15, graph);
	addEdge(3, 1, 7, graph);
	addEdge(1, 4, 32, graph);
	addEdge(4, 1, 16, graph);
	addEdge(1, 5, 16, graph);
	addEdge(5, 1, 10, graph);
	addEdge(1, 6, 31, graph);
	addEdge(6, 1, 32, graph);
	addEdge(1, 7, 5, graph);
	addEdge(7, 1, 13, graph);
	addEdge(1, 8, 6, graph);
	addEdge(8, 1, 11, graph);
	addEdge(1, 9, 4, graph);
	addEdge(9, 1, 12, graph);

	addEdge(2, 3, 4, graph);
	addEdge(3, 2, 6, graph);
	addEdge(2, 4, 21, graph);
	addEdge(4, 2, 17, graph);
	addEdge(2, 5, 16, graph);
	addEdge(5, 2, 19, graph);
	addEdge(2, 6, 36, graph);
	addEdge(6, 2, 40, graph);
	addEdge(2, 7, 8, graph);
	addEdge(7, 2, 17, graph);
	addEdge(2, 8, 12, graph);
	addEdge(8, 2, 8, graph);
	addEdge(2, 9, 9, graph);
	addEdge(9, 2, 3, graph);

	addEdge(3, 4, 4, graph);
	addEdge(4, 3, 6, graph);
	addEdge(3, 5, 11, graph);
	addEdge(5, 3, 8, graph);
	addEdge(3, 6, 20, graph);
	addEdge(6, 3, 17,graph);
	addEdge(3, 7, 12, graph);
	addEdge(7, 3, 10, graph);
	addEdge(3, 8, 41, graph);
	addEdge(8, 3, 40, graph);
	addEdge(3, 9, 30, graph);
	addEdge(9, 3, 33, graph);

	addEdge(4, 5, 8, graph);
	addEdge(5, 4, 11, graph);
	addEdge(4, 6, 21, graph);
	addEdge(6, 4, 7, graph);
	addEdge(4, 7, 42, graph);
	addEdge(7, 4, 36, graph);
	addEdge(4, 8, 12, graph);
	addEdge(8, 4, 20, graph);
	addEdge(4, 9, 11, graph);
	addEdge(9, 4, 5, graph);

	addEdge(5, 6, 3, graph);
	addEdge(6, 5, 11, graph);
	addEdge(5, 7, 16, graph);
	addEdge(7, 5, 10, graph);
	addEdge(5, 8, 31, graph);
	addEdge(8, 5, 20, graph);
	addEdge(5, 9, 10, graph);
	addEdge(9, 5, 11, graph);

	addEdge(6, 7, 10, graph);
	addEdge(7, 6, 4, graph);
	addEdge(6, 8, 21, graph);
	addEdge(8, 6, 15, graph);
	addEdge(6, 9, 18, graph);
	addEdge(9, 6, 10, graph);

	addEdge(7, 8, 2, graph);
	addEdge(8, 7, 10, graph);
	addEdge(7, 9, 31, graph);
	addEdge(9, 7, 20, graph);

	addEdge(8, 9, 9, graph);
	addEdge(9, 8, 18, graph);

	printGrph(graph);


	
}