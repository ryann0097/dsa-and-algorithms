#include <iostream>
/**
 * @brief Struct representing a node (ADT).
 */
struct node {
    int num;      ///< The value stored in the node.
    node *next;   ///< Pointer to the next node in the list.
    node *prev;   ///< Pointer to the previous node in the list.
};

/**
 * @brief Inserts a new node with a user-provided value at the end of the list.
 * 
 * @param init Reference to the pointer to the initial node of the list.
 * @param end Reference to the pointer to the last node of the list.
 */
void insert(node *&init, node *&end){
    node *new_node = new node;
    std::cout << "\tInsert the number that you want in the list > ";
    std::cin >> new_node->num;
    if(init == nullptr){
        new_node->next = nullptr;
        new_node->prev = nullptr;
        init = new_node;
        end = new_node;
    }
    else{
        new_node->next = nullptr;
        new_node->prev = end;
        end->next = new_node;
        end = new_node;
    }
    std::cout << "\t[Insertion Mode] The number " << new_node->num << " has been added.\n";
}

/**
 * @brief Removes the last node from the list.
 * 
 * @param init Reference to the pointer to the initial node of the list.
 * @param end Reference to the pointer to the last node of the list.
 */
void remove(node *init, node *end){
    if(end == nullptr) return;
    if(init == end){
        delete end;
        init = nullptr;
        end = nullptr;
    } else {
        node *temp = end;
        end = end->prev;
        end->next = nullptr;
        delete temp;
    }
}

/**
 * @brief Displays the list from the start to the end.
 * 
 * @param init Pointer to the initial node of the list.
 */
void show_start_end(node *init) {
    node *index = init;
    int idx = 0;
    while (index != nullptr) {
        std::cout << idx << ": " << index->num << "\n";
        index = index->next;
        idx++;
    }
}

/**
 * @brief Displays the list from the end to the start.
 * 
 * @param end Pointer to the last node of the list.
 */
void show_end_start(node *end) {
    node *index = end;
    int idx = 0;
    while (index != nullptr) {
        std::cout << idx << ": " << index->num << "\n";
        index = index->prev;
        idx++;
    }
}

/**
 * @brief Clears the entire list.
 * 
 * @param init Reference to the pointer to the initial node of the list.
 * @param end Reference to the pointer to the last node of the list.
 */
void clear(node *init, node *end){
    node *index = init;
    while(init != end){
        node *temp = init;
        init = init->next;
        delete temp;
    }
    end = nullptr;
}
/*
   A main. Any questions about it?
*/
int main(){
    node *init = nullptr;
    node *end = nullptr;
    node *aux;

    int op, count, find;

    do{
        std::cout << "\n+=====[ Simple-Linked List ]=====+\n";
        std::cout << "\t 1. Insert\n\t 2. Show (start-2-end)\n\t 3. Show (end-2-start)\n\t 4. Remove\n\t 5. Clear list\n\t 6. Exit\n\n";
        std::cout << "[ Insert your option ] > ";
        std::cin >> op;
        if(op > 6 || op < 1){std::cout << "\t [Invalid entry] Try options from 1 to 6. > ";}
        if(op == 1){insert(init, end);}
        if(op == 2){show_start_end(init);}
        if(op == 3){show_end_start(end);}
        if(op == 4){remove(init, end);}
        if(op == 5){clear(init, end);}
    } while (op != 6);

    std::cout << "\t [Farewell] See ya later.\n";
}
