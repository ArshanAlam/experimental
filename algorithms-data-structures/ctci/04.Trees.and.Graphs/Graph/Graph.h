/**
 * Graph
 *
 * A template for a graph.
 */

#ifndef __GRAPH_H__
#define __GRAPH_H__

using namespace std;
#include <vector>

typedef struct GraphNode {
  int data;
  vector<GraphNode *> children;
} GraphNode;

typedef bool (*searchCallback)(GraphNode *);

class Graph {
  private:
    vector<GraphNode *> vertices;

  public:
    Graph();
    ~Graph();

    /**
     * addVertex
     *
     *  Add the given graph node to this graph.
     */
    Graph & addVertex(GraphNode *);

    /**
     *  Apply BFS with the given callback function.
     *
     *  The callback function is called with each new
     *  node being searched.
     *
     *  If the callback returns 'false' the search terminates.
     */
    Graph & BFS(searchCallback);

    /**
     *  Apply DFS with the given callback function.
     *
     *  The callback function is called with each new
     *  node being searched.
     *
     *  If the callback returns 'false' the search terminates.
     */
    Graph & DFS(searchCallback);
};  // Graph
#endif
