/// Job (without tasks) Assignment problem using Branch and Bound ///
// Import libraries //
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstdint>
#include <map>
#include <numeric>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;
#define N 5

// state space tree node
struct Node{
	Node* parent; // stores parent node of current node helps in tracing path when answer is found
	int pathTravelCost; // contains cost for ancestors nodes including current node
	int cost; // contains least cost
	int machineID; // contain machine ID
	int jobID; // contains Job ID
	bool assigned[N]; // contains info about available jobs
};

// Function to allocate a new search tree node by assigning machine x to job y
Node* newNode(int x, int y, bool assigned[], Node* parent){
	Node* node = new Node;
	for (int j = 0; j < N; j++){
		node->assigned[j] = assigned[j];
	}
	node->assigned[y] = true;
	node->parent = parent;
	node->machineID = x;
	node->jobID = y;
	return node;
}

// compute the least cost of node after machine x is assigned to job y.
int calculateCost(int costMatrix[N][N], int x, int y, bool assigned[]) {
	int cost = 0;
	bool available[N] = {true}; // to store unavailable jobs
	for (int i = x + 1; i < N; i++) { // start from next machine
		int min = INT_MAX, minIndex = -1; // INT_MAX = 2147483647  (for 32-bit Integers)
		for (int j = 0; j < N; j++) { // iterate for each job
			if (!assigned[j] && available[j] && costMatrix[i][j] < min){ // if job is unassigned
				minIndex = j; // store job number with a lower cost 
				min = costMatrix[i][j]; // store lower cost as new minimum value
			}
		}
		cost += min; // add cost of next machine
		available[minIndex] = false; // job becomes unavailable
	}
	return cost;
}

// to maintain the minimum heap
struct comp{
	bool operator()(const Node* lhs, const Node* rhs) const{
		return lhs->cost > rhs->cost;
	}
};

void printAssignments(Node *min){
	if(min->parent==NULL) return;
	printAssignments(min->parent);
	cout << "Assign Machine " << char(min->machineID + 'A') << " to Job " << min->jobID << endl;
}

// Finds minimum cost using Branch and Bound.
Node* findMinCost(int costMatrix[N][N]){

	priority_queue<Node*, std::vector<Node*>, comp> pq; // Create a priority queue to store live nodes of space search tree

	// initialize heap to dummy node (root) with cost 0
	bool assigned[N] = {false};
	Node* root = newNode(-1, -1, assigned, NULL);
	root->pathTravelCost = root->cost = 0;

	pq.push(root); // Add root node to list of live nodes;

	// (1) finds a live node with least cost, (2) add its childrens to list of live nodes, and (3) finally deletes it from the list.
	while (!pq.empty()) {
		Node* min = pq.top(); // Find a live node with least estimated cost
		pq.pop(); // The found node is deleted from the list of live nodes
		int i = min->machineID + 1; // i stores next machine

		// BASE CASE: if all machines are assigned a job
		if (i == N) return min;

		// iterate for each job
		for (int j = 0; j < N; j++) {
			if (!min->assigned[j]) { // If job is still unassigned
				Node* child = newNode(i, j, min->assigned, min); // create a new tree node
				child->pathTravelCost = min->pathTravelCost + costMatrix[i][j]; // cost for ancestors nodes including current node
				child->cost = child->pathTravelCost + calculateCost(costMatrix, i, j, child->assigned); // calculate its lower bound
				pq.push(child); // Add child to list of live nodes;
			}
		}
	}
}

// main code
int main(){
	int costMatrix[N][N] ={
		{9, 2, 7, 8, 5}, // row represents machine, column represents job
		{6, 4, 3, 7, 2},
		{5, 8, 1, 8, 7},
		{7, 6, 9, 4, 6},
		{7, 6, 9, 4, 8}
	};
	Node* min = findMinCost(costMatrix);
	printAssignments(min);
	cout << "Minimum makespan = " << min->cost << endl;
	return 0;
}
