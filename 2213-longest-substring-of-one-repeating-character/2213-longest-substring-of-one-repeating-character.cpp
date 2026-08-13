class Solution {
public:

    struct Node {
        int len;
        int pref;
        int suff;
        int best;

        char leftChar;
        char rightChar;

        Node() {
            len = 0;
            pref = 0;
            suff = 0;
            best = 0;
            leftChar = '#';
            rightChar = '#';
        }
    };

    vector<Node> seg;

    Node merge(Node a, Node b) {

        if (a.len == 0)
            return b;

        if (b.len == 0)
            return a;

        Node res;

        res.len = a.len + b.len;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        // Best answer is initially from either side
        res.best = max(a.best, b.best);

        // -------------------------
        // Prefix
        // -------------------------

        res.pref = a.pref;

        // Entire left segment is the same character
        // and it matches the first character of right segment
        if (a.pref == a.len && a.rightChar == b.leftChar) {
            res.pref = a.len + b.pref;
        }

        // -------------------------
        // Suffix
        // -------------------------

        res.suff = b.suff;

        // Entire right segment is the same character
        // and it matches the last character of left segment
        if (b.suff == b.len && a.rightChar == b.leftChar) {
            res.suff = b.len + a.suff;
        }

        // -------------------------
        // Best crossing the middle
        // -------------------------

        if (a.rightChar == b.leftChar) {
            res.best = max(res.best, a.suff + b.pref);
        }

        return res;
    }

    void build(int node, int l, int r, string &s) {

        if (l == r) {

            seg[node].len = 1;
            seg[node].pref = 1;
            seg[node].suff = 1;
            seg[node].best = 1;

            seg[node].leftChar = s[l];
            seg[node].rightChar = s[l];

            return;
        }

        int mid = (l + r) / 2;

        build(2 * node, l, mid, s);
        build(2 * node + 1, mid + 1, r, s);

        seg[node] = merge(
            seg[2 * node],
            seg[2 * node + 1]
        );
    }

    void update(
        int node,
        int l,
        int r,
        int index,
        char ch
    ) {

        if (l == r) {

            seg[node].len = 1;
            seg[node].pref = 1;
            seg[node].suff = 1;
            seg[node].best = 1;

            seg[node].leftChar = ch;
            seg[node].rightChar = ch;

            return;
        }

        int mid = (l + r) / 2;

        if (index <= mid) {
            update(
                2 * node,
                l,
                mid,
                index,
                ch
            );
        }
        else {
            update(
                2 * node + 1,
                mid + 1,
                r,
                index,
                ch
            );
        }

        seg[node] = merge(
            seg[2 * node],
            seg[2 * node + 1]
        );
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        int n = s.size();

        seg.resize(4 * n);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {

            int index = queryIndices[i];
            char ch = queryCharacters[i];

            update(
                1,
                0,
                n - 1,
                index,
                ch
            );

            ans.push_back(seg[1].best);
        }

        return ans;
    }
};