#ifndef TRIES_TRIES_H
#define TRIES_TRIES_H
#include "Node.h"
#include <map>
#include <iostream>
#include <utility>
class Tries {
private:
    Node* root;
public:
    Tries() {
        root = new Node();
    }

    void insert(std::string insert) {
        Node** temp = &root;
        for(char i : insert) {
            temp = &(*temp)->next[i];
            if(!(*temp)) {
                (*temp) = new Node;
            }
        }
        (*temp)->visited = true;
    }

    bool search_by_prefix(std::string search) {

    }

    bool search_by_complete(std::string search) {
        Node* temp = root;
        for(char i : search) {
            temp = temp->next[i];
            if(!temp) {
                return false;
            }
        }
        return temp->visited;
    }

    void erase(std::string del) {
        Node** borrar = &root;
        int indice = 0;
        erase_helper(del,indice,borrar);
    }

    Node* erase_helper(std::string del, int indice, Node** borrar) {
        borrar = &(*borrar)->next[del[indice]];
        if(!(*borrar)) {
            int h = (*borrar)->next.erase(del[indice]);
        }
        else if((*borrar)->visited && (*borrar)->next.empty()) {
            delete (*borrar);
            delete borrar;
            borrar = nullptr;
        }
    }

    void print() {

    }
};


#endif
