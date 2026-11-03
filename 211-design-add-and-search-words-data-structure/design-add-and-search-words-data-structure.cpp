class WordDictionary {
    struct Node {
        Node* child[26] = {};
        bool end = false;
    };

    Node* root;

    bool dfs(string& w, int i, Node* p) {
        if (i == w.size()) return p->end;

        if (w[i] == '.') {
            for (auto c : p->child)
                if (c && dfs(w, i + 1, c)) return true;
            return false;
        }

        int x = w[i] - 'a';
        return p->child[x] && dfs(w, i + 1, p->child[x]);
    }

public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* p = root;

        for (char c : word) {
            int x = c - 'a';
            if (!p->child[x]) p->child[x] = new Node();
            p = p->child[x];
        }

        p->end = true;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};