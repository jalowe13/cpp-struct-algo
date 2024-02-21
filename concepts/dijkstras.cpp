#include <climits>
#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>

// Dijkstras
struct Node {
  int num;
  std::vector<std::pair<Node *, int>> adjacency;
  Node(int num) : num(num) {}
};
void print_vec(std::vector<int> *p_test_vector) {
  const size_t vec_len = (*p_test_vector).size();
  std::cout << "[";
  for (size_t i = 0; i < p_test_vector->size(); i++) {
    std::cout << (*p_test_vector)[i] << (i != vec_len - 1 ? "," : "]\n");
  }
}

bool has_unvisited(std::vector<bool> &seen) {
  for (size_t i = 0; i < seen.size(); i++) {
    if (!seen[i]) {
      return true;
    }
  }
  return false;
}

size_t get_lowest_unseen(std::vector<bool> &seen, std::vector<int> &dists) {
  int lowest_distance = INT_MAX;
  int idx = -1;
  for (size_t i = 0; i < seen.size(); i++) {
    if (!seen[i] && (dists[i] < lowest_distance)) {
      lowest_distance = dists[i];
      idx = i;
    }
  }
  return idx;
}

void walk_dijkstras(std::vector<Node *> &p_graph, int source, int need,
                    std::vector<int> &previous, std::vector<bool> &seen,
                    std::vector<int> &dists) {
  while (has_unvisited(seen)) {
    size_t lowest = get_lowest_unseen(seen, dists);
    seen[lowest] = true;
    std::vector<std::pair<Node *, int>> &list = p_graph[lowest]->adjacency;
    std::cout << "Current shortest distance from initial node to node "
              << lowest << " is " << dists[lowest] << std::endl;
    for (size_t i = 0; i < list.size(); i++) {     // Iterate over lowest unseen
      const std::pair<Node *, int> edge = list[i]; // Next unseen
      const int node_i = edge.first->num;          // Index position of node
      if (seen[node_i]) {
        continue;
      }
      int distance = dists[lowest] + edge.second;
      if (distance < dists[node_i]) { // shorter path found with node
        std::cout << "Updating distance for node " << node_i << " to "
                  << distance << std::endl;
        dists[node_i] = distance;
        previous[node_i] = lowest;
      }
    }
  }
}
std::vector<int> dijkstras(std::vector<Node *> &p_graph, int source, int need) {
  std::vector<int> previous(p_graph.size(), -1);
  std::vector<bool> seen(p_graph.size(), false);
  std::vector<int> dists(p_graph.size(), INT_MAX);
  std::cout << "Finding path from " << source << " to " << need << std::endl;
  // Source node instatiation for seen and distance
  dists[source] = 0;
  walk_dijkstras(p_graph, source, need, previous, seen, dists);

  // create path
  std::vector<int> path;
  int current = need;
  if (previous[current] == -1 && current != source) { // Check if a path exists
    std::cout << "No path exists from " << source << " to " << need
              << std::endl;
    return path;
  }
  while (current != -1) {
    path.push_back(current);
    std::cout << "Push " << current << std::endl;
    current = previous[current];
  }
  return path;
}

int main() {
  std::cout << "Start Dijkstras\n";
  srand(time(0)); // Seed random weights
  Node *node0 = new Node(0);
  Node *node1 = new Node(1);
  Node *node2 = new Node(2);
  Node *node3 = new Node(3);
  Node *node4 = new Node(4);
  Node *node5 = new Node(5);
  Node *node6 = new Node(6);
  Node *node7 = new Node(7);
  Node *node8 = new Node(8);
  Node *node9 = new Node(9);
  node0->adjacency = {std::make_pair(node1, rand() % 10),
                      std::make_pair(node2, rand() % 10)};
  node1->adjacency = {
      std::make_pair(node0, rand() % 10), std::make_pair(node2, rand() % 10),
      std::make_pair(node3, rand() % 10), std::make_pair(node4, rand() % 10),
      std::make_pair(node5, rand() % 10), std::make_pair(node6, rand() % 10),
      std::make_pair(node7, rand() % 10), std::make_pair(node8, rand() % 10),
      std::make_pair(node9, rand() % 10)};
  node2->adjacency = {std::make_pair(node0, rand() % 10),
                      std::make_pair(node1, rand() % 10),
                      std::make_pair(node3, rand() % 10)};
  node3->adjacency = {std::make_pair(node1, rand() % 10),
                      std::make_pair(node2, rand() % 10),
                      std::make_pair(node4, rand() % 10)};
  node4->adjacency = {std::make_pair(node1, rand() % 10),
                      std::make_pair(node3, rand() % 10)};
  std::vector<Node *> graph = {node0, node1, node2, node3, node4,
                               node5, node6, node7, node8, node9};
  // Leaf Nodes
  std::vector<int> result = dijkstras(graph, 0, 5);
  print_vec(&result);
  dijkstras(graph, 0, 6);
  dijkstras(graph, 0, 7);
  dijkstras(graph, 0, 8);
  dijkstras(graph, 0, 9);
}
