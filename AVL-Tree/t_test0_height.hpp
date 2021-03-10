// test
#pragma once
#include<iostream>
#include"t_component0_height.hpp"
#include"../util/tree_util.hpp"
using namespace std;

namespace t_test0_height {

	string tree_str_rep =
		"1,"
		"	2,"
		"		5,"
		"		6,"
		"	3,"
		"		4,"
		"			0,"
		"		5,";
	
	
	void run() {
		//cout << "tree_str_rep: " << tree_str_rep;
		Node* root = new Node;
		create_btree_from_str<Node>(root, tree_str_rep);
		print_tree(root);
		cout << "height: " << height(root) << '\n';
	}
	
}
