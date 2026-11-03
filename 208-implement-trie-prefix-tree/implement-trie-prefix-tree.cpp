class Trie {
    struct Node {
        Node* child[26] = {};
        bool end = false;
    };

    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* p = root;

        for (char c : word) {
            int i = c - 'a';
            if (!p->child[i])
                p->child[i] = new Node();
            p = p->child[i];
        }

        p->end = true;
    }

    bool search(string word) {
        Node* p = root;

        for (char c : word) {
            int i = c - 'a';
            if (!p->child[i]) return false;
            p = p->child[i];
        }

        return p->end;
    }

    bool startsWith(string prefix) {
        Node* p = root;

        for (char c : prefix) {
            int i = c - 'a';
            if (!p->child[i]) return false;
            p = p->child[i];
        }

        return true;
    }
};