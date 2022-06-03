#pragma once

#include <vector>

class Node
{
public:
	Node() {};
	~Node() {};

	virtual void Update() {};
	virtual void Render() {};

private:
	std::vector<Node>* children;
	Node* parent;

};

