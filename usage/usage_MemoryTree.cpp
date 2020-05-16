// Required c++17 or above
#include"../MemoryTree/MemoryTree.hpp"

struct testStruct {
	int i, j;
	string str;
	bool operator==(const testStruct& o) const {
		return o.i == i && o.j == j && str == o.str;
	}
};

void u1() {
	MemoryTree<int> tree;
	auto child_id0 = tree.emplace_child(-1, 70);
	auto child_id1 = tree.emplace_child(child_id0, 32);
	auto child_id  = tree.emplace_child(-1, 10);
	auto child_id2 = tree.emplace_child(child_id1, 90);
	cout << "can find val in selected branch: " << tree.canBranchFind(child_id2, 70) << '\n';
}

void u2() {
	MemoryTree<testStruct> tree;
	auto child_id0 = tree.emplace_child(-1, {1,2,"first"});
	auto child_id1 = tree.emplace_child(child_id0, {1,3,"second"});
	auto child_id  = tree.emplace_child(-1, {1,4,"first"});
	auto child_id2 = tree.emplace_child(child_id1, {2,3,"first"});
	cout << "can find data in selected branch: " << tree.canBranchFind(child_id2, {1,2,"first"}) << '\n';
	cout << "can find data in selected branch: " << tree.canBranchFind(child_id2, {1,2,"second"}) << '\n';
}

int main() {
	cout << "u1:\n";
	u1();
	cout << "---------------\n";
	cout << "u2:\n";
	u2();
}
