#include <iostream>
#include <vector>

template <typename T>
class Graph {

protected:
	class Node {
	public:
		constexpr Node(const T value) : value(value){};

		constexpr T getValue() { return value; }
		T setValue(const T value) { this->value = value; }

		std::vector<Node *> neighbours;

		// void operator+(Node& neighbour){
		// 	this->neighbours.push_back(neighbour);
		// 	neighbour.addNeighbour(this);
		// }

		void addNeighbour(Node *neighbour)
		{
			neighbours.push_back(neighbour);
		}

		void printNeighbours()
		{
			std::cout << "(";
			for (int i = 0; i < neighbours.size(); ++i)
			{

				std::cout << *neighbours[i];
				if (i != neighbours.size() - 1)
				{
					std::cout << ", ";
				}
			}
			std::cout << ")";
		}

	private:
		friend std::ostream &operator<<(std::ostream &os, Node node)
		{
			os << "Node(" << node.getValue() << ")";
			return os;
		}

		T value;
	};

	Node *root;
	std::vector<Node *> nodes;

public:
	Graph(T rootValue)
	{
		Node *newRoot = new Node(rootValue);
		this->root = newRoot;
		nodes.push_back(root);
	};

	Node getRoot() { return *root; }

	void printNodes()
	{
		for (int i = 0; i < nodes.size(); ++i)
		{
			std::cout << *nodes[i];
			nodes[i]->printNeighbours();
			std::cout << std::endl;
		}
	}

	// void addNode(T parent,T child){

	// 	Node * newNode = new Node(child);
	// 	nodes.push_back(newNode);

	// 	newNode.addNeighbour()
	// }

	void addNode(const T newNodeValue)
	{
		Node *newNode = new Node(newNodeValue);
		nodes.push_back(newNode);
		root->addNeighbour(newNode);
		newNode->addNeighbour(root);
	}

	void addNode(const T parentNodeValue, const T newNodeValue)
	{

		if (Node *parentNode = findNode(parentNodeValue))
		{
			Node *newNode = new Node(newNodeValue);
			parentNode->addNeighbour(newNode);
			newNode->addNeighbour(parentNode);
		}

		else
		{
			std::cout << "Cannot add Node(" << newNodeValue << ") to the given parent - Node(" << parentNodeValue << ") doesn't exist." << std::endl;
		}
	}

private:

	Node *findNode(T nodeValue)
	{
		for (int i = 0; i < nodes.size(); ++i)
		{
			if (nodes[i]->getValue() == nodeValue)
			{
				return nodes[i];
			}
		}
		return nullptr;
	}
	
};

int main()
{

	Graph<char> myGraph('A');

	myGraph.addNode('B');
	myGraph.addNode('D', 'C');

	myGraph.printNodes();
}