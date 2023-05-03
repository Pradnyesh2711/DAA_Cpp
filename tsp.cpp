#include <bits/stdc++.h>
using namespace std;

const int N = 12; // maximum number of cities

int n; // number of cities
int graph[N][N]; // graph[i][j] is the distance between city i and city j
bool visited[N]; // visited[i] is true if city i has been visited
int currCost; // cost of the current tour
int bestCost; // cost of the best tour found so far
int path[N]; // path[i] is the i-th city in the current tour
int bestPath[N]; // bestPath[i] is the i-th city in the best tour found so far

void initialize() {
    // Initialize the visited array
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    // Initialize the current and best costs
    currCost = 0;
    bestCost = INT_MAX;
    // Initialize the current and best paths
    for (int i = 0; i < n; i++) {
        path[i] = -1;
        bestPath[i] = -1;
    }
}

void printPath(int path[N]) {
    for (int i = 0; i < n; i++) {
        cout << path[i] << " ";
    }
    cout << path[0]; // print the first city again to complete the tour
}

void tsp(int currCity) {
    // If all cities have been visited, update the best tour if necessary
    if (currCity == n) {
        if (currCost + graph[path[n-1]][path[0]] < bestCost) {
            bestCost = currCost + graph[path[n-1]][path[0]];
            memcpy(bestPath, path, sizeof(path));
        }
        return;
    }
    // Otherwise, try all unvisited cities as the next city in the tour
    for (int nextCity = 0; nextCity < n; nextCity++) {
        if (!visited[nextCity]) {
            // Calculate the cost of going from the current city to the next city
            int prevCity = (currCity == 0) ? path[n-1] : path[currCity-1];
            currCost += graph[prevCity][nextCity];
            // Prune the search if the current cost plus a lower bound
            // on the remaining cost is greater than the best cost so far
            if (currCost + (n-currCity)*2 < bestCost) {
                visited[nextCity] = true;
                path[currCity] = nextCity;
                tsp(currCity+1);
                visited[nextCity] = false;
                path[currCity] = -1;
            }
            // Backtrack
            currCost -= graph[prevCity][nextCity];
        }
    }
}

int main() {
    // Read the number of cities and the distances between them
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    // Solve the TSP using Branch and Bound
    initialize();
    visited[0] = true;
    path[0] = 0;
    tsp(1);
    // Print the best tour found
    cout << "Best tour: ";
    printPath(bestPath);
    cout << endl;
    cout << "Best cost: " << bestCost << endl;
    return 0;
}