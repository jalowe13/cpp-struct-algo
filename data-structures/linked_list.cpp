#include <iostream>
// Doubly LinkedList Jacob Lowe
struct Node {
  int num;
  Node *next;
  Node *prev;
  Node(int num) : num(num), next(NULL), prev(NULL) {}
  Node(int num, Node *prev) : num(num), next(NULL), prev(prev) {}
  Node(int num, Node *prev, Node *next) : num(num), next(next), prev(prev) {}
};

struct LinkedList {
  Node *head = NULL;
  std::size_t size = 0;
  LinkedList() {}
  std::size_t get_size() { return size; }
  void append(int n) {
    std::cout << "Inserting " << n << std::endl;
    if (head == NULL) { // First node
      head = new Node(n);
      size++;
    } else { // Any other node get to end
      Node *current = head;
      // Just head node in LinkedList append
      while (current->next != NULL) { // Iterate to the end of the LinkedList
        current = current->next;
      }
      current->next = new Node(n, current);
      size++;
    }
  };
  void display_list() {
    if (head == NULL) {
      std::cout << "Current List is empty: []\n";
      return;
    }
    std::cout << "Current List [";
    Node *current = head;
    while (current->next != NULL) {
      std::cout << current->num << ",";
      current = current->next;
    }
    std::cout << current->num << "]" << std::endl;
  }
  Node *get_node(size_t i) {
    Node *current = head;
    std::cout << "Current Node at position " << i << ":\n";
    ;
    while ((i > 0)) {
      current = current->next;
      i--;
    }
    int c = current->num;
    int p = current->prev->num;
    int n = current->next->num;
    std::cout << "  [" << p << ",-->" << c << "<--," << n << "]\n";
    std::cout << "  Current Node is " << c << std::endl;
    std::cout << "  Previous Node was " << p << std::endl;
    std::cout << "  Next Node is " << n << std::endl;
    return current;
  }
  void append_mid(int i) {
    std::cout << "List size is " << size << std::endl;
    size_t idx_m = size / 2;
    std::cout << "Inserting " << i << " in the Middle " << std::endl;
    if (head == NULL) { // First node
      head = new Node(i);
      size++;
    } else { // Any other node get to end
      Node *current = head;
      // Just head node in LinkedList append
      while (idx_m > 0) { // Iterate to the end of the LinkedList
        current = current->next;
        idx_m--;
      }
      Node *inserted_node = new Node(i, current->prev, current);
      if (current->prev != NULL) {
        current->prev->next = inserted_node;
      }
      if (current != NULL) {
        current->prev = inserted_node;
      }
      current = inserted_node;
      size++;
    }
  };
};

void example() {
  LinkedList *list = new LinkedList();
  list->display_list();
  list->append(5);
  list->append(8);
  list->append(7);
  list->append(59);
  list->append(72);
  list->append(61);
  list->display_list();
  list->append_mid(2);
  list->display_list();
  list->append_mid(27);
  list->display_list();
  list->append_mid(82);
  list->display_list();
  list->append_mid(72);
  list->display_list();
  delete list;
}
int main() {
  std::cout << "Welcome to LinkedList\n";
  example();
}
