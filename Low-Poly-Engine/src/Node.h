#pragma once

#include <vector>
#include "Vector3D.h"

class Node
{
public:
	Node();
	~Node();

	virtual void Update();
	virtual void Render();

	Vector3D position;
	Vector3D rotation;

	void AddChildNode(Node& node);
	
	Node& GetChildNode(int index);
	Node& GetParentNode();

protected:

	void SetParentNode(Node& node);

private:
	std::vector<Node*> children;
	Node* parent;

};

