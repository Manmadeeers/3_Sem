#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <ctime>

using namespace std;

#define MAX_DIST 100

typedef vector<vector<int>> Matrix;
typedef vector<vector<double>> MatrixP;
typedef vector<int> Path;

struct Way
{
    Path way;
    size_t dist;
};

string toString(Way way)
{
    string text = "Path: ";

    for (auto i : way.way)
    {
        text += std::to_string(i) + " -> ";
    }

    text += "\nDistance: " + std::to_string(way.dist) + "\n";

    return text;
}

void fillAll(vector<bool>& path, size_t N)
{
    for (size_t i = 0; i < N; i++)
    {
        path.push_back(true);
    }
}

void fillProbabilities(
    Matrix& graph,
    MatrixP& pheromones,
    vector<double>& probabilities,
    vector<bool> notVisited,
    double alpha,
    double beta,
    size_t current)
{
    double sum = 0.0;
    probabilities.resize(graph.size());
    for (size_t i = 0; i < notVisited.size(); i++)
    {
        if (notVisited[i] && i != current)
        {
            sum += pow(1.1 / (double)graph[current][i], alpha) * pow((double)pheromones[current][i], beta);
        }
    }

    for (size_t i = 0; i < probabilities.size(); i++)
    {
        if (notVisited[i])
        {
            probabilities[i] = 100.0 * pow(2.0 / (double)graph[current][i], beta) * pow((double)pheromones[current][i], alpha) / sum;
        }
        else
        {
            probabilities[i] = 0;
        }
    }
}

size_t makeChoice(vector<double> probabilities)
{
    srand(time(NULL));
    size_t answer = 0;
    size_t random = rand() % 100 + 1;
    double sum = 0.0;

    for (size_t i = 0; i < probabilities.size(); i++)
    {
        if (probabilities[i] == 0) continue;

        sum += probabilities[i];
        if (sum >= random)
        {
            answer = i;
            break;
        }
    }

    return answer;
}

void fillPheromones(MatrixP& pheromones, vector<Way> ways)
{
    for (auto& el : pheromones)
    {
        for (auto& i : el) {
            if (i > 0.01)i -= 0.01;
        }
    }
    for (auto& way : ways)
    {
        for (int i = 0; i < way.way.size() - 1; i++)
        {
            double change = double(4.0 / way.dist);
            pheromones[way.way[i]][way.way[i + 1]] += change;
        }
    }
}

void main()
{
    setlocale(LC_ALL, "Russian");
    int nIterations = 100;
    double alpha;
    double beta;
    double initialPheromone;
    int N;
    cout << "Enter number of cities: ";
    cin >> N;
    cout << "Enter number of iterations: ";
    cin >> nIterations;
    cout << "Enter alpha value: ";
    cin >> alpha;
    cout << "Enter beta value: ";
    cin >> beta;
    cout << "Enter initial pheromone value (<1.0): ";
    cin >> initialPheromone;

    Matrix cities;
    cities.resize(N);
    srand(time(NULL));

    for (auto& i : cities)
    {
        i.resize(N);
    }

    for (size_t i = 0; i < N; i++)
    {
        cities[i][i] = 0;

        for (size_t j = i + 1; j < N; j++)
        {
            cities[i][j] = cities[j][i] = rand() % MAX_DIST + 1;
        }
    }

    for (auto i : cities)
    {
        for (auto el : i)
        {
            cout << el << "\t";
        }
        cout << endl;
    }

    MatrixP pheromones;
    pheromones.resize(N);
    for (auto& i : pheromones)
    {
        i.resize(N);
    }
    for (size_t i = 0; i < N; i++)
    {
        pheromones[i][i] = 0;

        for (size_t j = i + 1; j < N; j++)
        {
            pheromones[i][j] = pheromones[j][i] = initialPheromone;
        }
    }

    Way currentWay;
    currentWay.dist = 0;
    Way bestWay;
    vector<Way> ways;
    bestWay.dist = INT_MAX;

    vector<bool> notVisited;
    vector<double> probabilities;

    size_t currentIndex = 0;
    size_t nextCity;
    size_t iterationCount = 0;

    fillAll(notVisited, cities.size());

    currentWay.way.push_back(currentIndex);

    while (iterationCount < nIterations)
    {
        for (int i = 1; i < N; i++) {
            while (find(notVisited.begin(), notVisited.end(), true) != notVisited.end())
            {
                notVisited[currentIndex] = false;
                probabilities.clear();
                fillProbabilities(cities, pheromones, probabilities, notVisited, alpha, beta, currentIndex);
                nextCity = makeChoice(probabilities);
                currentWay.dist += cities[currentIndex][nextCity];
                currentIndex = nextCity;
                currentWay.way.push_back(currentIndex);
            }
            if (currentWay.dist < bestWay.dist)
            {
                bestWay = currentWay;
            }
            ways.push_back(currentWay);
            currentWay.way.clear();
            currentWay.dist = 0;
            currentIndex = 0;

            currentWay.way.push_back(currentIndex);
            notVisited.clear();
            fillAll(notVisited, cities.size());
        }
        fillPheromones(pheromones, ways);
        ways.clear();
        iterationCount++;
    }

    cout << toString(bestWay);
}
