#include <iostream>
#include <queue>
// BFS Jacob Lowe O(N^2)
struct Node {
  int num;
  Node *left;
  Node *right;
  Node(int num) : num(num), left(NULL), right(NULL) {}
  Node(int num, Node *left, Node *right) : num(num), left(left), right(right) {}
};

bool bfs(Node *p_head, int need) {
  std::queue<Node> *q = new std::queue<Node>;
  q->push(*p_head);
  while (q->size() != 0) {
    Node next = q->front();
    q->pop();
    if (next.num == need) {
      std::cout << next.num << "=" << need << std::endl;
      return true;
    }
    if (next.left) {
      q->push(*next.left);
    }
    if (next.right) {
      q->push(*next.right);
    }
  }
  return false;
}

int main() {
  std::cout << "Start BFS with 10 Nodes \n";
  const int need = 8;
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);
  Node *n4 = new Node(4);
  Node *n5 = new Node(5);
  Node *n6 = new Node(6, n1, n2);
  Node *n7 = new Node(7, n3, n4);
  Node *n8 = new Node(8, n5, nullptr);
  Node *n9 = new Node(9, n6, n7);
  Node *head = new Node(10, n8, n9);
  std::cout << "Found? : " << bfs(head, need);
  delete n1;
  delete n2;
  delete n3;
  delete n4;
  delete n5;
  delete n6;
  delete n7;
  delete n8;
  delete n9;
  delete head;
}
