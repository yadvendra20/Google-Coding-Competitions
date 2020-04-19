#include <bits/stdc++.h>
#define int long long int

using namespace std;
const int sz = 26;
const int maxs = 1e5+5;

int n,k;
vector<string> vs(maxs);

struct TrieNode {
	struct TrieNode *childrens[sz];
	bool isEndOfWord;
	int cnt = 0;
};

struct TrieNode *getNode() {
	TrieNode *newNode = new TrieNode;
	for(int i=0;i<sz;i++)
		newNode->childrens[i] = NULL;
	newNode->isEndOfWord = false;
	newNode->cnt = 0;
	return newNode;
}

void insert(struct TrieNode *root, string &key) {
	struct TrieNode *pCrawl = root;
	for(int i=0;i<key.length();i++) {
		int ind = key[i]-'A';
		if(pCrawl->childrens[ind] == NULL)
			pCrawl->childrens[ind] = getNode();
		pCrawl = pCrawl->childrens[ind];
		pCrawl->cnt++;
	}
	pCrawl->isEndOfWord = true;
}

bool search(struct TrieNode *root,string &key) {
	struct TrieNode *pCrawl = root;
	for(int i=0;i<key.length();i++) {
		int ind = key[i]-'A';
		if(pCrawl->childrens[ind] == NULL)
			return false;
		pCrawl = pCrawl->childrens[ind];
	}
	return pCrawl != NULL and pCrawl->isEndOfWord == true;
}

int query(struct TrieNode *node) {
	if(node == NULL)
		return 0;
	int ans = node->cnt/k;
	for(int i=0;i<sz;i++)
		if(node->childrens[i])
			ans += query(node->childrens[i]);
	return ans;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T,TC = 1;
	cin >> T;
	for(;TC<=T;TC++) {
		cout << "Case #" << TC << ": ";
		cin >> n >> k;
		struct TrieNode *root = getNode();
		for(int i=0;i<n;i++) {
			cin >> vs[i];
			insert(root,vs[i]);
		}
		cout << query(root) << "\n";
	}
	return 0;
}

