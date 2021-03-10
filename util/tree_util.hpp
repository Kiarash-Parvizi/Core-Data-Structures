#include"code_env.hpp"
#include<functional>

template<typename NodeType>
// expected parameters: <val: numeric, l: ptr, r: ptr>
// format: <data>,
// str type example:
// string s =
// "1,"
// "	2,"
// "		5,"
// "		6,"
// "	4,"
// "		2,"
// "		3,";
void create_btree_from_str(NodeType* root, const string& str) {
	auto lines = split(str, ',');
	auto errLam = []() {
		throw "create_btree_from_str : invalid str format";
	};
	if (lines.size() < 1) {
		errLam();
	}
	umap<int, pair<NodeType*, int>> mp;
	root->val = stoi(lines[0]);
	mp[0] = {root, 0};
	//
	try {
		for (int i = 1; i < len(lines); i++) {
			auto& line = lines[i];
			int tabCnt = charCnt(line, 0, '\t');
			string raw_val = read_between(line, '\t', ',');
			// create new node
			NodeType* nd = nullptr;
			if (raw_val[0] == 'n' || raw_val[0] == 'N') {
			} else {
				nd = new NodeType;
				mp[tabCnt] = {nd, 0};
				nd->val = stoi(raw_val);
			}
			// add as child
			if (tabCnt > 0) {
				auto& parentDat = mp[tabCnt-1];
				NodeType* parent = parentDat.first;
				if (parentDat.second == 0) {
					parent->l = nd;
					parentDat.second++;
				} else {
					parent->r = nd;
				}
			}
		}
	} catch(const exception& e) {}
}


template<typename NodeType>
// expected parameters: <val: numeric, l: ptr, r: ptr>
void print_tree(NodeType* nd, int step = 0) {
	if (step == 0) cout << '\n' << string(30, '-') << "\nTree:\n\n";
	string printVal = (nd == nullptr) ? "null" : to_string(nd->val);
	cout << string(step, '\t') << printVal << '\n';
	if (nd != nullptr) {
		print_tree(nd->l, step+1);
		print_tree(nd->r, step+1);
	}
}



