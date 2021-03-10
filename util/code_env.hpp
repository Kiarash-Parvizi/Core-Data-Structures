#pragma once
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define paii pair<int,int>
#define pall pair<ll,ll>
#define umap unordered_map
#define len(x) (int) x.size()
#define lastEl(x) (int) x[x.size()-1]
#define lastIdx(x) (int) x.size()-1
#define range(a) a.begin(), a.end()
//using namespace __gnu_pbds;
#define fastIO ios::sync_with_stdio(false);cin.tie(0);
int __yo_cnt__ = 0;
#define yo cout<<"BP-> "<<__yo_cnt__++<<'\n';
#define yol cout<<"-----------------\n";
using namespace std;

//typedef tree<int,null_type,less<int>,rb_tree_tag,
//	tree_order_statistics_node_update> indexed_set;
 
const ll M = (1e9+7);
//const int M = 998244353;
 
template<class A = int, class B = int, class C = int>
struct tri {
	A a; B b; C c;
	tri() {}
	tri(const A& a, const B& b, const C& c) : a(a), b(b), c(c) {}
	//
	void set(const A& a, const B& b, const C& c) {
		this->a = a; this->b = b; this->c = c;
	}
};

template<class T>
pair<T,T> operator *(const pair<T,T>& pa, int a) {
	return {pa.first*a, pa.second*a};
}
template<class T>
void operator *=(pair<T,T>& pa, int a) {
	pa.first*=a, pa.second*=a;
}
template<class T>
pair<T,T> operator +(const pair<T,T>& pa, int a) {
	return {pa.first+a, pa.second+a};
}
template<class T>
void operator +=(pair<T,T>& pa, int a) {
	pa.first+=a, pa.second+=a;
}
template<class T>
pair<T,T> operator +(const pair<T,T>& pa, const pair<T,T>& pa2) {
	return {pa.first+pa2.first, pa.second+pa2.second};
}
template<class T>
void operator +=(pair<T,T>& pa, const pair<T,T>& pa2) {
	pa.first+=pa2.first, pa.second+=pa2.second;
}
 
template<class U, class V>
ostream& operator << (ostream& o, const pair<U,V>& pa) {
	o << "(" << pa.first << ", " << pa.second << ")";
	return o;
}
template<class T>
ostream& operator << (ostream& o, const vector<T>& vec) {
	o << "[ ";
	for (const auto& v : vec) {
		o << v << ' ';
	}
	o << "]";
	return o;
}
template<class T>
istream& operator >>(istream& in, vector<T>& vec) {
	for (auto& v: vec) in >> v;
	return in;
}
template<class T>
ostream& operator << (ostream& o, const vector<vector<T>>& mat) {
	int ic = 0;
	for (const auto& vek : mat) {
		if (!ic) { o << "["; }
		else { o << ' '; }
		o << vek << (ic == len(mat)-1 ? "]\n" : "\n");
		ic++;
	}
	return o;
}
template<class T>
ostream& operator << (ostream& o, const deque<T>& qu) {
	o << "[ ";
	for (auto it = qu.begin(); it != qu.end(); ++it) {
		o << *it << ' ';
	}
	o << "]";
	return o;
}
 
int strcmp(const char* a, const char* b, int n) {
	while(--n > -1) {
		if (a[n] != b[n]) return a[n] > b[n] ? 1 : -1;
	}
	return 0;
}
 
bool isNum(char c) {
	return c <= '9' && c >= '0';
}
 
ll _gcd(ll a, ll b) {
    while (b != 0) {
        ll t = b;
        b = a % b;
        a = t;
    }
    return a;
}
 
ll _lcm(ll a, ll b) {
    return (a / _gcd(a, b)) * b;
}
ll pow(ll a, ll b, ll m) {
	ll ans=1;
	while(b) {
		if(b&1)
			ans=(ans*a)%m;
		b>>=1; a=(a*a)%m;
	}
	return ans;
}

//Combination nCr
#define MAXN 200005
int fact[MAXN], ifact[MAXN];
void Cinit() {
	fact[0] = 1;
	for (int i = 1; i < MAXN; ++i) fact[i] = 1LL * fact[i - 1] * i % M;
	ifact[MAXN - 1] = pow(fact[MAXN - 1], M - 2, M);
	for (int i = MAXN - 2; i >= 0; --i) ifact[i] = 1LL * ifact[i + 1] * (i + 1) % M;
}
ll nCr(int n, int r) {
  if (r < 0 || r > n) return 0;
  return (1LL * fact[n] * ifact[r] % M * ifact[n - r] % M)%M;
}
 
ll C(int n, int k) {
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;
	//
    ll result = n;
    for(int i = 2; i <= k; ++i) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

int digSum(ll v) {
    int res = 0;
    ll pre = 0, p = 10;
    for (; p < 1e18; p*=10) {
        if (p > v*10) break;
        ll t = v % p;
        res += (t - pre)/(p/10);
        pre = t;
    }
    return res;
}
int ord(char c) { if (c > 'Z') return c - 'a'; if (c > '9') return c - 'A';
	return c-'0'; }
 
int dif(const string& ch, const string& par, int s) {
	int dif = 0;
	for (int i = 0; i < ch.size(); i++) {
		if (s+i >= par.size()) break;
		if (par[s+i] != ch[i]) dif++;
	}
	return dif;
}

bool isUpper(char c) {
	return (c <= 'Z' && c >= 'A');
}

// Splitter
const std::vector<std::string>& split(const std::string& str, char delim=' ') {
    static int s, e; s = 0; e = 0;
    static std::vector<std::string> vec; vec.clear();
    while(s < str.size()) {
        while(s < str.size() && str[s]==delim) { vec.pb(""); s++; } e = s;
        while(e < str.size() && str[e]!=delim) { e++; }
        vec.emplace_back(str.substr(s, e-s)); s = e+1;
    }
	if (str[e] == delim) vec.pb("");
	return vec;
}

string read_between(const string& str, char s, char e, int offset = 0) {
	int state = 0, si = len(str), ei = len(str);
	for (int i = offset; i < len(str); i++) {
		char ch = str[i];
		if (state == 0) {
			if (ch == s) {
				state++;
			}
		} else if (state == 1) {
			if (ch != s) {
				si = i;
				state++;
			}
		} else {
			if (ch == e) {
				ei = i;
				break;
			}
		}
	}
	return str.substr(si, ei-si);
}

string read_before(const string& str, char e, int offset = 0) {
	for (int i = 0; i < len(str); i++) {
		if (str[i] == e) { return str.substr(0, i); }
	}
	return str;
}

const int INF = 1e9+5;
#define vi vector<int>
#define vvi vector<vi>
#define vv(x) vector<vector<x>>
#define vpaii vector<paii>
#define print(x) cout << x << '\n';

//---------------------------------------
//

int charCnt(const string& s, int startIdx, char type) {
	int cnt = 0;
	for (int i = startIdx; i < len(s); i++) {
		if (s[i] != type) break;
		cnt++;
	}
	return cnt;
}
