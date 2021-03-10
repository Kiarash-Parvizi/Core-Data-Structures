#pragma once
#include<iostream>
#include<vector>
#define ull unsigned long long
using namespace std;

template <class T>
class avl_tree {
	struct Node {
		Node *l, *r;
		T val;
	};
	Node* root;
// func
	ull height(Node* node);
public:
};


template<class T>
ull avl_tree<T>::height(Node* node) {
	// data
	ull h = 0, mxH = 0;
	bool backState = false;
	Node* popedNode = nullptr;
	vector<Node*> st = {nullptr, node};
	// lam
	auto setBack = [&]() {
		backState = true;
		popedNode = st[st.size()-1];
		st.pop_back();
		node = st[st.size()-1];
		h -= 1;
	};
	auto setForward = [&]() {
		backState = false;
		h += 1;
		if (mxH < h) mxH = h;
		st.push_back(node);
	};
	// algo
	while (node != nullptr) {
		if (backState) {
			if (popedNode == node->r || node->r == nullptr) {
				setBack();
			} else {
				node = node->r;
				setForward();
			}
		} else {
			bool cmp0 = node->l != nullptr,
				 cmp1 = node->r != nullptr;
			if (cmp0 || cmp1) {
				if (cmp0) {
					node = node->l;
				} else if (cmp1) {
					node = node->r;
				}
				setForward();
			}
			else {
				setBack();
			}
		}
	}
	return mxH;
}
