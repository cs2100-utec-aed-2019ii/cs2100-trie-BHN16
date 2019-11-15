#ifndef TRIES_NODE_H
#define TRIES_NODE_H
#include <map>
class Node{
private:
    std::map<char,Node*> next;
    bool visited;
public:
    Node() {
        visited = false;
    }
    friend class Tries;
};
#endif
