#include"tree_util.hpp"

void t0() {
	struct Node {
		Node *l = nullptr, *r = nullptr;
		int val = -1;
	};
	string s =
	"1,"
	"	2,"
	"		5,"
	"			7,"
	"			77,"
	"		n,"
	"	4,"
	"		2,"
	"		3,";
	Node* root = new Node;
	create_btree_from_str<Node>(root, s);
	print_tree(root);
}

int main() {
	t0();
}
