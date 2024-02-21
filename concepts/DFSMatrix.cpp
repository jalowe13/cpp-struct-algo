#include <cstddef>
#include <iostream>
#include <vector>

// Adjacency Matrix BFS
struct Node {
  int num;
  std::vector<Node *> adjacency;
  Node(int num) : num(num) {}
  Node(int num, std::vector<Node *> *adjacency)
      : num(num), adjacency(*adjacency) {
    for (size_t i = 0; i < (*adjacency).size(); i++) {
      std::cout << (*adjacency)[i]->num << std::endl;
    }
  }
};
void print_vec(std::vector<int> *p_test_vector) {
  const size_t vec_len = (*p_test_vector).size();
  std::cout << "[";
  for (size_t i = 0; i < p_test_vector->size(); i++) {
    std::cout << (*p_test_vector)[i] << (i != vec_len - 1 ? "," : "]\n");
  }
}

// adjacency: Graph
// current_num: number currently on
// needed: number that needs to be reached
// seen: vector of node positions that were seen
// path: current overall path
bool walk_dfs(std::vector<Node *> &adjacency, int current_num, int needed,
              std::vector<bool> &seen, std::vector<int> &path) {

  if (seen[current_num]) {
    return false;
  }
  seen[current_num] = true;
  path.push_back(current_num);

  if (current_num == needed) {
    return true;
  }

  const std::vector<Node *> list = adjacency[current_num]->adjacency;
  for (size_t i = 0; i < list.size(); i++) {
    const Node *edge = list[i];
    if (walk_dfs(adjacency, edge->num, needed, seen, path)) {
      return true;
    }
  }

  seen[current_num] = false;
  path.pop_back();
  return false;
}

std::vector<int> dfs(std::vector<Node *> &p_graph, int source, int need) {
  std::cout << "Finding path from " << source << " to " << need << std::endl;
  std::vector<int> empty;
  std::vector<bool> seen(p_graph.size(), false);
  std::vector<int> path;
  walk_dfs(p_graph, source, need, seen, path);
  if (path.size() == 0) {
    std::cout << "There is no path to " << need << std::endl;
    return empty;
  }
  return path;
}

int main() {
  std::cout << "Start DFS\n";
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
  node0->adjacency = {node1};
  node1->adjacency = {node2, node3, node4};
  node2->adjacency = {node5, node6, node7};
  node3->adjacency = {node8};
  node4->adjacency = {node9};
  std::vector<Node *> graph = {node0, node1, node2, node3, node4,
                               node5, node6, node7, node8, node9};
  std::vector<int> result = dfs(graph, 1, 9);
  print_vec(&result);
  result = dfs(graph, 1, 8);
  print_vec(&result);
  result = dfs(graph, 1, 7);
  print_vec(&result);
  result = dfs(graph, 1, 6);
  print_vec(&result);
  result = dfs(graph, 1, 5);
  print_vec(&result);
}
