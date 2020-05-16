// Note: required c++17 or above 
#pragma once
#include<iostream>
#include<vector>
using namespace std;



template<typename T>

class MemoryTree {
	// PRIVATE
	// Node struct
	struct MemoryNode {
		T val;
		vector<MemoryNode*> childs;
		MemoryNode* parent;
		// constructor
		MemoryNode(MemoryNode* parent, T val) : val(val), parent(parent) {
		}
	};
	// data vec
	vector<MemoryNode> nodes;
	
public:
	MemoryTree(int res_size = 256) {
		nodes.reserve(res_size);
	}

	// parent_id<0 : adds new node directly to the root
	const int emplace_child(const int parent_id, const T child_val) {
		auto* parent = parent_id>=0 ? &nodes[parent_id] : nullptr;
		auto* new_node = &nodes.emplace_back(MemoryNode(parent, child_val));
		if (parent_id>=0)
			parent->childs.push_back(new_node);
		return nodes.size()-1;
	}

	bool canBranchFind(const int leaf_id, const T val) const {
		MemoryNode const* leaf = &nodes[leaf_id];
		do {
			if (leaf->val == val) {
				return true;
			}
			//
			leaf = leaf->parent;
		} while(leaf);
		return false;
	}
};


