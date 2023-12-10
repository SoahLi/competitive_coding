#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

Node* copy(Node* node, unordered_map<int, Node*>& visited){
    if(visited.find(node->val) != visited.end()) return visited[node->val];
    //create the new node
    Node* newNode = new Node(node->val);
    visited[newNode->val] = newNode;
    //for each node, recurse if it hasent been created
    for(int i=0; i<node->neighbors.size(); i++){
        if(visited.find(node->neighbors[i]->val) == visited.end()){
            copy(node->neighbors[i], visited);
        }
        newNode->neighbors.push_back(visited[node->neighbors[i]->val]);
    }
    return newNode;
}

Node* cloneGraph(Node* node) {
    if(node->neighbors.size() == 0){
        Node* clone = new Node(node->val);
        return clone;
    }
    unordered_map<int, Node*> visited;
    return copy(node, visited);
}

void printGraph(Node* node, unordered_set<Node*>& visited) {
    if (visited.find(node) != visited.end()) {
        return; // Node has already been visited
    }

    cout << "Node " << node->val << " neighbors: ";
    for (Node* neighbor : node->neighbors) {
        cout << neighbor->val << " ";
    }
    cout << endl;

    visited.insert(node);

    for (Node* neighbor : node->neighbors) {
        printGraph(neighbor, visited);
    }
}

void printGraph(Node* node) {
    unordered_set<Node*> visited;
    printGraph(node, visited);
}

int main() {
    Node* nodeOne = new Node(1);
    Node* nodeTwo = new Node(2);
    Node* nodeThree = new Node(3);
    Node* nodeFour = new Node(4);
    nodeOne->neighbors = vector<Node*>{nodeTwo, nodeFour};
    nodeTwo->neighbors = vector<Node*>{nodeOne, nodeThree};
    nodeThree->neighbors = vector<Node*>{nodeTwo, nodeFour};
    nodeFour->neighbors = vector<Node*>{nodeOne, nodeThree};
    Node* myGraph = cloneGraph(nodeOne);
    printGraph(myGraph);
}