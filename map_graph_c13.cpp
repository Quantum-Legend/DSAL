/* Represent a given graph using adjacency matrix/list to perform DFS and using adjacency
list to perform BFS. Use the map of the area around the college as the graph. Identify the
prominent land marks as nodes and perform DFS and BFS on that. */
#include <iostream>
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
};
void Graph::matrixRep()
{
    adjacencyMatrix = new int* [noOfVertices];
    for(int i = 0; i < noOfVertices; i++)
    {
        adjacencyMatrix[i] = new int[noOfVertices];
        for(int j = 0; j < noOfVertices; j++)
        {
            adjacencyMatrix[i][j] = 0;
        }
    }
    for(int i = 0; i < noOfVertices; i++)
    {
        for(int j = i; j < noOfVertices; j++)
        {
            int edge;
            std::cout << vertex[i] << "-" << vertex[j] <<" Edge value - "; // Value of edge in the matrix, 0 if not present 1 if present
            std::cin >> edge;
            adjacencyMatrix[i][j] = edge;
            adjacencyMatrix[j][i] = edge;
        }
    }
}
void Graph::matrixDisplay()
{
    for(int i = 0; i < noOfVertices; i++)
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
    for(int i = 0; i < noOfVertices; i++)
    {
        std::cout << "Enter (" << i + 1 << ")th vertex data: ";
        std::cin >> vertex[i];
    }
}
Graph::Graph(int n)
{
    noOfVertices = n;
    vertex = new std::string[noOfVertices];
    for(int i = 0; i < noOfVertices; i++)
    {
        std::cout << "Enter (" << i + 1 << ")th vertex data: ";
        std::cin >> vertex[i];
    }
}
int main()
{
    Graph G1;
    G1.matrixRep();
    std::cout << "/nThe matrix representation is: " << std::endl;
    G1.matrixDisplay();
    return 0;
}