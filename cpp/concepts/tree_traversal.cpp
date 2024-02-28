// Tree Traversal - Jacob Lowe
#include <iostream>
#include <vector>
struct Node {
  int num;
  Node *left;
  Node *right;
  Node(int num) : num(num), left(NULL), right(NULL) {}
  Node(int num, Node *left, Node *right) : num(num), left(left), right(right) {}
};

void print_vec(std::vector<int> *p_test_vector) {
  const size_t vec_len = (*p_test_vector).size();
  std::cout << "[";
  for (size_t i = 0; i < p_test_vector->size(); i++) {
    std::cout << (*p_test_vector)[i] << (i != vec_len - 1 ? "," : "]\n");
  }
}

// Pre Order Traversal
std::vector<int> *walk_pre_order(Node *p_current_node,
                                 std::vector<int> *p_path) {
  if (!p_current_node || !p_path) {
    return p_path;
  }
  Node &current_node = *p_current_node;
  std::vector<int> &path = *p_path;
  // recurse
  // pre
  path.push_back(current_node.num);
  print_vec(&path);
  // recurse
  walk_pre_order(current_node.left, &path);
  walk_pre_order(current_node.right, &path);
  // post
  return p_path;
}
std::vector<int> *pre_order_search(Node *head, std::vector<int> *path) {
  std::cout << "Pre Order Search Start.\n";
  return walk_pre_order(head, path);
}

// In Order Traversal
std::vector<int> *walk_in_order(Node *p_current_node,
                                std::vector<int> *p_path) {
  if (!p_current_node || !p_path) {
    return p_path;
  }
  Node &current_node = *p_current_node;
  std::vector<int> &path = *p_path;
  // recurse
  // pre
  // recurse
  walk_in_order(current_node.left, &path);
  path.push_back(current_node.num);
  print_vec(&path);
  walk_in_order(current_node.right, &path);
  // post
  return p_path;
}

std::vector<int> *in_order_search(Node *head, std::vector<int> *path) {
  std::cout << "In Order Search Start.\n";
  return walk_in_order(head, path);
}

// Post Order Traversal
std::vector<int> *walk_post_order(Node *p_current_node,
                                  std::vector<int> *p_path) {
  if (!p_current_node || !p_path) {
    return p_path;
  }
  Node &current_node = *p_current_node;
  std::vector<int> &path = *p_path;
  // recurse
  // pre
  // recurse
  walk_post_order(current_node.left, &path);
  walk_post_order(current_node.right, &path);
  // post
  path.push_back(current_node.num);
  print_vec(&path);
  return p_path;
}

std::vector<int> *post_order_search(Node *head, std::vector<int> *path) {
  std::cout << "Post Order Search Start.\n";
  return walk_post_order(head, path);
}

int main() {
  std::cout << "Tree Search DFS\n";
  std::vector<int> *prepath1 = new std::vector<int>;
  std::vector<int> *prepath2 = new std::vector<int>;
  std::vector<int> *inpath1 = new std::vector<int>;
  std::vector<int> *inpath2 = new std::vector<int>;
  std::vector<int> *postpath1 = new std::vector<int>;
  std::vector<int> *postpath2 = new std::vector<int>;
  // Tree 1
  Node *tree1 = new Node(20);
  tree1->left = new Node(10);
  tree1->left->left = new Node(5);
  tree1->left->left->right = new Node(7);
  tree1->left->right = new Node(15);
  tree1->right = new Node(50);
  tree1->right->left = new Node(30);
  tree1->right->left->left = new Node(29);
  tree1->right->left->right = new Node(45);
  tree1->right->right = new Node(100);
  // Tree 2
  Node *tree2 = new Node(20);
  tree2->left = new Node(10);
  tree2->left->left = new Node(5);
  tree2->left->left->right = new Node(7);
  tree2->left->right = new Node(15);
  tree2->right = new Node(50);
  tree2->right->left = new Node(30);
  tree2->right->left->left = new Node(29);
  tree2->right->left->left->left = new Node(21);
  tree2->right->left->right = new Node(45);
  tree2->right->left->right->right = new Node(49);

  // Tree 1 Tests
  std::vector<int> pre_order_output1 = {20, 10, 5, 7, 15, 50, 30, 29, 45, 100};
  std::vector<int> in_order_output1 = {5, 7, 10, 15, 20, 29, 30, 45, 50, 100};
  std::vector<int> post_order_output1 = {7, 5, 15, 10, 29, 45, 30, 100, 50, 20};
  bool preorder1 = *pre_order_search(tree1, prepath1) == pre_order_output1;
  bool inorder1 = *in_order_search(tree1, inpath1) == in_order_output1;
  bool postorder1 = *post_order_search(tree1, postpath1) == post_order_output1;
  // Tree 2 Tests
  std::vector<int> pre_order_output2 = {20, 10, 5,  7,  15, 50,
                                        30, 29, 21, 45, 49};
  std::vector<int> in_order_output2 = {5,  7,  10, 15, 20, 21,
                                       29, 30, 45, 49, 50};
  std::vector<int> post_order_output2 = {7,  5,  15, 10, 21, 29,
                                         49, 45, 30, 50, 20};

  bool preorder2 = *pre_order_search(tree2, prepath2) == pre_order_output2;
  bool inorder2 = *in_order_search(tree2, inpath2) == in_order_output2;
  bool postorder2 = *post_order_search(tree2, postpath2) == post_order_output2;
  // Results
  std::cout << "Pre Order Passed? " << preorder1 << "," << preorder2
            << std::endl;
  std::cout << "In Order Passed?" << inorder1 << "," << inorder2 << std::endl;
  std::cout << "Post Order Passed?" << postorder1 << "," << postorder2
            << std::endl;
}
