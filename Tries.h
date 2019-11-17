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
        if(!(*borrar)) {
            (*borrar) = new Node;
        }
    }
    
    void print() {
        Node* imprimir = root;
        std::string pal;
        for(auto it = imprimir->next.begin(); it != imprimir->next.end(); ++it) {
            pal.push_back(it->first);
            print_helper(pal, it->second);
            pal.clear();
        }
    }
    
private:
    void erase_helper(std::string del, int indice, Node** borrar) {
        if(indice == del.size()) {
            if((*borrar)->visited && (*borrar)->next.empty())  {
                delete (*borrar);
                (*borrar) = nullptr;
                return;
            } else if((*borrar)->visited && !(*borrar)->next.empty()) {
                (*borrar)->visited = false;
                return;
            }
        }
        erase_helper(del, indice+1,&(*borrar)->next[del[indice]]);
        if(!(*borrar)->next[del[indice]]) {
            int h = (*borrar)->next.erase(del[indice]);
        }
        if(!(*borrar)->visited && (*borrar)->next.empty())  {
            delete (*borrar);
            (*borrar) = nullptr;
        }
    }
    
    void print_helper(std::string p, Node* r) {
        if(r->visited && r->next.empty()) {
            std::cout << p << std::endl;
            return;
        }
        if(r->visited) {
            std::cout << p << std::endl;
        }
        for(auto it = r->next.begin(); it != r->next.end(); ++it) {
            p.push_back(it->first);
            print_helper(p, it->second);
            p.pop_back();
        }
    }
};


#endif
