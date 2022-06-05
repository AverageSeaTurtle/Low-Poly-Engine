#include "Node.h"

Node::Node() : parent(nullptr)
{

}

Node::~Node()
{
	parent = nullptr;
	delete[] parent;
}

void Node::Update()
{
	for (auto& n : children)
		n->Update();
}

void Node::Render()
{
	for (auto& n : children)
		n->Render();
}

void Node::AddChildNode(Node& node)
{
	children.push_back(&node);
	node.SetParentNode(*this);
}

Node& Node::GetChildNode(int index)
{
	return *children[index];
}

Node& Node::GetParentNode()
{
	return *parent;
}

void Node::SetParentNode(Node& node)
{
	parent = &node;
}
