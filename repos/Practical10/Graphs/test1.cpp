#include <iostream>

using namespace std;



int main1() {

	cout << "Enter number of vertices: ";
	int vert, edges;
	cin >> vert;
	cout << "Enter number of edges: ";
	cin >> edges;

	int matr[20][20];

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			matr[i][j] = 0;
		}
	}

	cout << "{\n";
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}
	cout << "}\n";

	bool enterEdges = true;
	int v1, v2, count;
	count = 0;
	while (enterEdges == true) {
		cout << "Enter the vertice numbers that have an edge between them in their pairs with a space between them: ";
		cin >> v1 >> v2;
		matr[v1][v2] = 1;
		matr[v2][v1] = 1;
		count++;
		if (count == edges) {
			enterEdges = false;
		}
	}

	cout << "{\n";
	for (int i = 0; i < vert; i++) {
		for (int j = 0; j < vert; j++) {
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}
	cout << "}";

	return 0;
}

int main() {




	return 0;
}