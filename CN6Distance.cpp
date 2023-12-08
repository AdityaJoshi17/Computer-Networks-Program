//#include <stdio.h>
#include <iostream>
using namespace std;
struct node {
	unsigned dist[6];
	unsigned from[6];
}
DVR[10];
int main() {
	cout << "\n\n-------------------- Distance Vector Routing Algorithm----------- ";
	int costmat[6][6];
	int nodes, i, j, k;
	cout << "\n\n Enter the number of nodes : ";
	cin >> nodes; //Enter the nodes
	cout << "\n Enter the cost matrix : \n";
	for(i = 0; i < nodes; i++) {
		for(j = 0; j < nodes; j++) {
			cin >> costmat[i][j];
			costmat[i][i] = 0;
			DVR[i].dist[j] = costmat[i][j]; //initialise the distance equal to cost matrix
			DVR[i].from[j] = j;
		}
	}
	for(i = 0; i < nodes; i++) // iterates over all nodes in the network.
        //It represents the source node for which the DVR algorithm is currently calculating minimum distances.
		for(j = i + 1; j < nodes; j++)//The middle loop (j) iterates over all nodes starting from i + 1.
                                    //It ensures that the algorithm only considers pairs of nodes once
			for(k = 0; k < nodes; k++)//The inner loop (k) iterates over all nodes and represents a potential intermediate node between i and j.
				if(DVR[i].dist[j] > costmat[i][k] + DVR[k].dist[j]) { //i to j is greater than the sum of the distance from i to k and the distance from k to j.
					DVR[i].dist[j] = DVR[i].dist[k] + DVR[k].dist[j];//Update
					DVR[j].dist[i] = DVR[i].dist[j];//Update
					DVR[i].from[j] = k;//Update the next-hop information for the path from i to j to be through node k.
					DVR[j].from[i] = k;
				}
	for(i = 0; i < nodes; i++) {
		cout << "\n\n For router: " << i + 1;
		for(j = 0; j < nodes; j++)
            cout << "\t\n node " << j + 1 << " via " << DVR[i].from[j] + 1 << " Distance " << DVR[i].dist[j];
	}
	cout << " \n\n ";
	return 0;
}
