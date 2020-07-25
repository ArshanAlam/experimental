#include <Graph.h>
#include <iostream>

using namespace std;

bool callback(GraphNode * node) {
  cout << node->data << endl;
  return true;
}

int main() {
  Graph G;
  GraphNode * gn_0 = new GraphNode;
  GraphNode * gn_1 = new GraphNode;
  GraphNode * gn_2 = new GraphNode;
  GraphNode * gn_3 = new GraphNode;
  GraphNode * gn_4 = new GraphNode;
  GraphNode * gn_5 = new GraphNode;
  gn_0->data = 0;
  gn_1->data = 1;
  gn_2->data = 2;
  gn_3->data = 3;
  gn_4->data = 4;
  gn_5->data = 5;
  
  gn_0->children.push_back(gn_1);
  gn_0->children.push_back(gn_4);
  gn_0->children.push_back(gn_5);

  gn_1->children.push_back(gn_3);
  gn_1->children.push_back(gn_4);
  
  gn_2->children.push_back(gn_1);
  
  gn_3->children.push_back(gn_2);
  gn_3->children.push_back(gn_4);

  G.addVertex(gn_0);
  G.addVertex(gn_1);
  G.addVertex(gn_2);
  G.addVertex(gn_3);
  G.addVertex(gn_4);
  G.addVertex(gn_5);

  cout << "BFS" << endl;
  G.BFS(callback);
  cout << endl;

  cout << "DFS" << endl;
  G.DFS(callback);
  cout << endl;

  delete gn_0;
  delete gn_1;
  delete gn_2;
  delete gn_3;
  delete gn_4;
  delete gn_5;
  return 0;
}
