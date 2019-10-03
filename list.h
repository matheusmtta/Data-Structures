#ifndef LIST_TAD_TP
#define LIST_TAD_TP

class Node{
  public:
    int element;
    int operations;
    Node *next;
};

class List{
  public:
    Node *begin;
    Node *end;
    int num_elements;

    List();
    ~List();
    int size();
    int front();
    bool empty();
    int weigth();
    bool pop_front();
    void remove(int);
    void push_back(int, int);
};

#endif