/* Represent a given graph using adjacency matrix/list to perform DFS and using adjacency
list to perform BFS. Use the map of the area around the college as the graph. Identify the
prominent land marks as nodes and perform DFS and BFS on that. */
#include <iostream>
class Stack
{
    int *arr, top, capacity;

public:
    Stack()
    {
        capacity = 5;
        arr = new int[capacity];
        top = -1;
    }
    Stack(int n)
    {
        capacity = n;
        arr = new int[capacity];
        top = -1;
    }
    bool empty();
    void push(int p);
    int pop();
};
bool Stack::empty()
{
    if (top == -1)
        return true;
    return false;
}
void Stack::push(int p)
{
    if (top == capacity - 1)
        return;
    top++;
    arr[top] = p;
}
int Stack::pop()
{
    int t = arr[top];
    top--;
    return t;
}
class Graph
{
    int noOfVertices;
    std::string *vertex;
    int **adjacencyMatrix;

public:
    Graph();
    Graph(int n);
    void matrixRep();
    void listRep(std::string *vertex);
    void matrixDisplay();
    void matrixDFS(std::string v);
};
void Graph::matrixDFS(std::string v)
{
    int p;
    bool visited[noOfVertices];
    for (int i = 0; i < noOfVertices; i++)
    {
        visited[i] = false;
        if (vertex[i] == v)
        {
            p = i;
        }
    }
    Stack s;
    s.push(p);
    while (!(s.empty()))
    {
        p = s.pop();
        if (!(visited[p]))
        {
            std::cout << vertex[p] << "   ";
            visited[p] = true;
        }
        for (int i = 0; i < noOfVertices; i++)
        {
            if (adjacencyMatrix[p][i] == 1 && !(visited[p]))
                s.push(i);
        }
    }
}
void Graph::matrixRep()
{
    adjacencyMatrix = new int *[noOfVertices];
    for (int i = 0; i < noOfVertices; i++)
    {
        adjacencyMatrix[i] = new int[noOfVertices];
        for (int j = 0; j < noOfVertices; j++)
        {
            adjacencyMatrix[i][j] = 0;
        }
    }
    for (int i = 0; i < noOfVertices; i++)
    {
        for (int j = i; j < noOfVertices; j++)
        {
            int edge;
            std::cout << vertex[i] << "-" << vertex[j] << " Edge value - "; // Value of edge in the matrix, 0 if not present 1 if present
            std::cin >> edge;
            adjacencyMatrix[i][j] = edge;
            adjacencyMatrix[j][i] = edge;
        }
    }
}
void Graph::matrixDisplay()
{
    for (int i = 0; i < noOfVertices; i++)
    {
        for (int j = 0; j < noOfVertices; j++)
        {
            std::cout << adjacencyMatrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}
Graph::Graph()
{
    noOfVertices = 5;
    vertex = new std::string[noOfVertices];
    for (int i = 0; i < noOfVertices; i++)
    {
        std::cout << "Enter (" << i + 1 << ")th vertex data: ";
        std::cin >> vertex[i];
    }
}
Graph::Graph(int n)
{
    noOfVertices = n;
    vertex = new std::string[noOfVertices];
    for (int i = 0; i < noOfVertices; i++)
    {
        std::cout << "Enter (" << i + 1 << ")th vertex data: ";
        std::cin >> vertex[i];
    }
}
int main()
{
    Graph G1;
    G1.matrixRep();
    std::cout << "\nThe matrix representation is: " << std::endl;
    G1.matrixDisplay();
    std::string vtx;
    std::cout << "\nEnter which vertex you want to start with: " << std::endl;
    std::getline(std::cin >> std::ws, vtx);
    G1.matrixDFS(vtx);
    return 0;
}
