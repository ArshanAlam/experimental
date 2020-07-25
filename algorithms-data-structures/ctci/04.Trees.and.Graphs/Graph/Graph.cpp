/**
 * Graph
 *
 * A template for a graph.
 */

#include <Graph.h>
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

Graph::Graph() {}
Graph::~Graph() {}

/**
 * Add the given vertex to the given graph.
 */
Graph & Graph::addVertex(GraphNode * node) {
  this->vertices.push_back(node);
  return *this;
} // addVertex

/**
 *  Apply BFS with the given callback function.
 *
 *  The callback function is called with each new
 *  node being searched.
 *
 *  If the callback returns 'false' the search terminates.
 */
Graph & Graph::BFS(searchCallback callback) {
  if(this->vertices.size() <= 0) return *this;

  unordered_set<GraphNode *> visited;
  queue<GraphNode *> frontier;
  visited.insert(this->vertices[0]);
  frontier.push(this->vertices[0]);

  while(!frontier.empty()) {
    GraphNode * node = frontier.front();
    frontier.pop();
    if(!callback(node)) return *this;

    for(GraphNode * child : node->children) {
      /**
       * If the child has been visited then continue
       * with the next child.
       */
      if(visited.find(child) != visited.end()) {
        continue;
      }
      visited.insert(child);
      frontier.push(child);
    }
  }
  return *this;
} // BFS

Graph & Graph::DFS(searchCallback callback) {
  if(this->vertices.size() <= 0) return *this;

  unordered_set<GraphNode *> visited;
  stack<GraphNode *> frontier;
  visited.insert(this->vertices[0]);
  frontier.push(this->vertices[0]);
  
  while(!frontier.empty()) {
    GraphNode * node = frontier.top();
    frontier.pop();
    if(!callback(node)) return *this;

    for(vector<GraphNode *>::reverse_iterator rit = node->children.rbegin(); rit != node->children.rend(); rit++) {
      /**
       * If the child has been visited then continue
       * with the next child.
       */
      if(visited.find(*rit) != visited.end()) {
        continue;
      }
      visited.insert(*rit);
      frontier.push(*rit);
    }
  }
  return *this;
} // DFS
