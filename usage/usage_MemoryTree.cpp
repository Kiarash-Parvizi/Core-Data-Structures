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

void u3() {
	MemoryTree<testStruct> tree;
	auto child_id0 = tree.emplace_child(-1, {1,2,"f"});
	auto child_id1 = tree.emplace_child(child_id0, {1,3,"s"});
	auto child_id  = tree.emplace_child(-1, {1,4,"f"});
	auto child_id2 = tree.emplace_childs(child_id1, {{2,3,"A"}, {2,3,"B"}, {2,3,"C"}, {2,3,"D"}});
	cout << "can find data in selected branch: " << tree.canBranchFind(child_id2, {2,3,"A"}) << '\n';
	cout << "can find data in selected branch: " << tree.canBranchFind(child_id2, {2,3,"C"}) << '\n';
}

void u4() {
	MemoryTree<int> tree;
	auto i1 = tree.emplace_child(-1, 1);
	auto i2 = tree.emplace_child(-1, 22);
	auto i3 = tree.emplace_child(i1, 3);
	auto i33 = tree.emplace_child(i1, 33);
	auto i333 = tree.emplace_child(i1, 333);
	auto i4 = tree.emplace_child(i3, 4);
	cout << "can find data in selected branch: " << tree.canBranchFind(i4, 1) << '\n';
	cout << "tree size: " << tree.size() << '\n';
	auto I2 = i2;
	tree.val(I2) *= 10;
	auto I3 = tree.emplace_child(I2, 5);
	{
		cout << "[ ";
		for (auto& v: tree.get_branch(I3)) {
			cout << v << ' ';
		}
		cout << "]\n";
	}
	tree.remove(i1);
	i1 = tree.emplace_child(-1, 1);
	i2 = tree.emplace_child(-1, 2);
	i3 = tree.emplace_child(i1, 3);
	i4 = tree.emplace_child(i3, 4);
	auto i5 = tree.emplace_child(i4, 5);
	auto i6 = tree.emplace_child(i4, 6);
	cout << "tree size: " << tree.size() << '\n';
	cout << "can find data in selected branch: " << tree.canBranchFind(I2, 22) << '\n';
	cout << "can find data in selected branch: " << tree.canBranchFind(I2, 220) << '\n';
	cout << "can find data in selected branch: " << tree.canBranchFind(i5, 22) << '\n';
	cout << "can find data in selected branch: " << tree.canBranchFind(i5, 1) << '\n';
	cout << "can find data in selected branch: " << tree.canBranchFind(i5, 2) << '\n';
	cout << "can find data in selected branch: " << tree.canBranchFind(i5, 3) << '\n';
	cout << "can find data in selected branch: " << tree.canBranchFind(i5, 4) << '\n';
	cout << "can find data in selected branch: " << tree.canBranchFind(i5, 5) << '\n';
	cout << "can find data in selected branch: " << tree.canBranchFind(i5, 6) << '\n';
	cout << "can find data in selected branch: " << tree.canBranchFind(i6, 6) << '\n';
}

int main() {
	cout << "u1:\n";
	u1();
	cout << "---------------\n";
	cout << "u2:\n";
	u2();
	cout << "---------------\n";
	cout << "u3:\n";
	u3();
	cout << "---------------\n";
	cout << "u4:\n";
	u4();
}
