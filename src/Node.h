#pragma once

#include <string>
#include <vector>

namespace mj
{
	class Node
	{
	public:
		Node();

		Node findChild(std::string& name);
		std::string getName() { return name; };
		void addNode(Node node);


	private:
		std::string name;
		std::vector<Node> children;
	};
}