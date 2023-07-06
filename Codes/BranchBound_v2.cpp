// 1. Import the libraries //
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;
#define N 4

const int INF = 1000; // Infinity value

// state space tree node
struct Node{
	Node* parent; // stores parent node of current node 
	int pathCost; // contains cost for ancestors nodes including current node
	int cost;
	int workerID;
	int jobID;
	bool assigned[N];
};

Node* newNode(int x, int y, bool assigned[], Node* parent){
	Node* node = new Node;
	for (int j = 0; j < N; j++)
		node->assigned[j] = assigned[j];
	node->assigned[y] = true;
	node->parent = parent;
	node->workerID = x;
	node->jobID = y;
	return node;
}

int calculateCost(int costMatrix[N][N], int x, int y, bool assigned[]) {
	int cost = 0;
	bool available[N] = {true}; // to store unavailable jobs

	for (int i = x + 1; i < N; i++){ // start from next worker
		int min = INF, minIndex = -1;
		// do for each job
		for (int j = 0; j < N; j++){
			// if job is unassigned
			if (!assigned[j] && available[j] &&
				costMatrix[i][j] < min){
				minIndex = j; // store job number
				min = costMatrix[i][j]; // store cost
			}
		}
		cost += min;
		available[minIndex] = false;
	}
	return cost;
}

// Comparison object to be used to order the heap
struct comp{
	bool operator()(const Node* lhs, const Node* rhs) const{
		return lhs->cost > rhs->cost;
	}
};

// Finds minimum cost using Branch and Bound.
int findMinCost(int costMatrix[N][N]){
	
    std::priority_queue<Node*, std::vector<Node*>, comp> pq; // Create a priority queue to store live nodes of search tree;

	bool assigned[N] = {false};
	Node* root = newNode(-1, -1, assigned, NULL);
	root->pathCost = root->cost = 0;
	root->workerID = -1;

	pq.push(root);
	while (!pq.empty()){
        Node* min = pq.top();
        pq.pop();

        int i = min->workerID + 1;

        for (int j = 0; j < N; j++){
            if (!min->assigned[j]){
            Node* child = newNode(i, j, min->assigned, min);
            child->pathCost = min->pathCost + costMatrix[i][j];
            child->cost = child->pathCost + calculateCost(costMatrix, i, j, child->assigned);
            pq.push(child);
            }
	    }
	}
}

// Driver code
int main()
{
	// x-coordinate represents a Worker
	// y-coordinate represents a Job
	int costMatrix[N][N] =
	{
		{9, 2, 7, 8},
		{6, 4, 3, 7},
		{5, 8, 1, 8},
		{7, 6, 9, 4}
	};

	cout << "\nOptimal Cost is "
		<< findMinCost(costMatrix);

	return 0;
}
