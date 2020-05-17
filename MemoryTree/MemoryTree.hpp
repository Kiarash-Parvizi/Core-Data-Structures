// MemoryTree
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
		vector<int> childs;
		int parent;
		// constructor
		MemoryNode(int parent, T val) : val(val), parent(parent) {
		}
	};
	// data vec
	vector<MemoryNode> nodes;
	vector<int> removedNodes;
	
public:
	MemoryTree(int res_size = 256) {
		nodes.reserve(res_size);
		removedNodes.reserve(64);
	}

	inline int size() {
		return nodes.size();
	}

	// parent_id<0 : adds new node directly to the root
	const int emplace_child(const int parent_id, const T child_val) {
		// check for place in deleted Nodes
		if(removedNodes.size()) {
			auto id = removedNodes[removedNodes.size()-1];
			removedNodes.pop_back();
			for (const auto& v : nodes[id].childs) {
				removedNodes.emplace_back(v);
			}
			//replace
			auto& node = nodes[id];
			node.val = child_val;
			node.childs.clear();
			node.parent = parent_id;
			//link-par
			if (parent_id>=0)
				nodes[parent_id].childs.push_back(id);
			return id;
		}
		//
		nodes.emplace_back(MemoryNode(parent_id, child_val));
		//link-par
		if (parent_id>=0)
			nodes[parent_id].childs.push_back(nodes.size()-1);
		return nodes.size()-1;
	}

	const int emplace_childs(const int parent_id, const vector<T>& childs) {
		int id = parent_id;
		for (const auto& v : childs) {
			id = emplace_child(id, v);
		}
		return id;
	}

	void remove(const int id) {
		if (id < 0 || id >= nodes.size()) {
			throw std::exception();
		}
		removedNodes.emplace_back(id);
	}

	bool canBranchFind(const int leaf_id, const T val) const {
		int idx = leaf_id;
		while(idx >= 0) {
			const auto& node = nodes[idx];
			if (node.val == val) {
				return true;
			}
			//
			idx = node.parent;
		}
		return false;
	}
};


