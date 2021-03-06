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
		bool active = true;
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
	T& val(const int id) {
		if (id < 0 || id >= nodes.size() || !nodes[id].active) {
			throw "tree.getVal err";
		}
		return nodes[id].val;
	}


	// parent_id<0 : adds new node directly to the root
	const int emplace_child(const int parent_id, const T child_val) {
		int id;
		// check for place in deleted Nodes
		if(removedNodes.size()) {
			id = removedNodes[removedNodes.size()-1];
			auto& node = nodes[id];
			//
			removedNodes.pop_back();
			for (const auto& v : node.childs) {
				remove(v);
			}
			//replace
			node.val = child_val;
			node.childs.clear();
			node.parent = parent_id;
			node.active = true;
		}
		else {
			id = nodes.size();
			nodes.emplace_back(MemoryNode(parent_id, child_val));
		}
			//link-par
		if (parent_id>=0)
			nodes[parent_id].childs.push_back(id);
		return id;
	}

	const int emplace_childs(const int parent_id, const vector<T>& childs) {
		int id = parent_id;
		for (const auto& v : childs) {
			id = emplace_child(id, v);
		}
		return id;
	}

	void remove(const int id) {
		if (id < 0 || id >= nodes.size() || !nodes[id].active) {
			return;
		}
		removedNodes.emplace_back(id);
		nodes[id].active = false;
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

	int branchFind(const int leaf_id, const T val) const {
		int idx = leaf_id;
		int counter = 0;
		while(idx >= 0) {
			const auto& node = nodes[idx];
			if (node.val == val) {
				return counter;
			}
			//
			idx = node.parent;
			counter++;
		}
		return -1;
	}

	vector<T> get_branch(const int leaf_id) {
		int idx = leaf_id;
		vector<T> ret;
		while(idx >= 0) {
			const auto& node = nodes[idx];
			// save
			ret.emplace_back(node.val);
			//
			idx = node.parent;
		}
		return ret;
	}

	vector<T> get_branch_to(const int leaf_id, int final_val) {
		int idx = leaf_id;
		vector<T> ret;
		while(idx >= 0) {
			const auto& node = nodes[idx];
			// save
			ret.emplace_back(node.val);
			//
			if (node.val == final_val) {
				break;
			}
			idx = node.parent;
		}
		return ret;
	}

	vector<T> get_branch(const int leaf_id, int depth) {
		int idx = leaf_id;
		int counter = 0;
		vector<T> ret;
		while(idx >= 0 && counter < depth) {
			const auto& node = nodes[idx];
			// save
			ret.emplace_back(node.val);
			//
			idx = node.parent;
			counter++;
		}
		return ret;
	}
	
};


