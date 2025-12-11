#include "tree.h"

#include <queue>
#include <unordered_set>

template<typename U>
Node<U>::Node(string nodeID, const U &value)
{
    id = nodeID;
    data = value;
}

template<typename T>
Tree<T>::Tree()
{
    root = nullptr;
}

template<typename T>
void Tree<T>::createRoot(const string &id, const T &value)
{
    root = new Node<T>(id, value);
}

template<typename T>
void Tree<T>::addNode(const string &parentID, const string &childID, const T &value)
{
    if (!root) createRoot(childID, value); // If no tree, then assume first thing added is the root

    Node<T>* parent = findNode(parentID);
    if (!parent) return; // If parent is not found, ignore the child and do not add

    parent->children.push_back(new Node<T>(childID, value));
}

// BFS search using a queue and some fancy replacement for vector<pair<stuff<yadayada<node>>>, bool>>
template<typename T>
Node<T>* Tree<T>::findNode(const string &id)
{
    if (!root) return nullptr;

    queue<Node<T>*> toVisit;
    unordered_set<Node<T>*> visited;

    toVisit.push(root);
    visited.insert(root);

    while (!toVisit.empty())
    {
        Node<T>* curr = toVisit.front(); toVisit.pop();

        if (curr->id == id) return curr;

        for (auto child : curr->children)
            if (child != nullptr && visited.insert(child).second) toVisit.push(child);
    }

    return nullptr;
}

template<typename T>
void Tree<T>::printAll()
{
    cout << "===== Story Tree =====" << endl;

    if (!root)
    {
        cout << "No story was generated :(" << endl;
        return;
    }

    queue<Node<T>*> toVisit;
    unordered_set<Node<T>*> visited;

    toVisit.push(root);
    visited.insert(root);

    while (!toVisit.empty())
    {
        Node<T>* curr = toVisit.front(); toVisit.pop();
        cout << "Node " << curr->id << ": " << curr->data << endl;

        if (curr->children.empty()) cout << "   Child -> (none)" << endl;
        else for (auto child : curr->children)
        {
            cout << "   Child -> " << child->data << endl;
            if (visited.insert(child).second) toVisit.push(child);
        }

        cout << endl;
    }

    cout << "======================" << endl;
}

// I'm not exactly sure how to implement this, but for now a BFS will probably do?
template<typename T>
Tree<T>::~Tree()
{
    if (!root) return;

    queue<Node<T>*> toVisit;
    unordered_set<Node<T>*> visited;

    toVisit.push(root);
    visited.insert(root);

    while (!toVisit.empty())
    {
        Node<T>* current = toVisit.front(); toVisit.pop();

        for (auto child : current->children)
            if (visited.insert(child).second) toVisit.push(child);

        delete current;
    }

    root = nullptr;
}
