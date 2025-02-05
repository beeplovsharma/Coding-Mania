class Solution {
public:
    vector<string> result;
    int m, n;

    struct trieNode {
        bool endOfWord;
        string word;
        trieNode* children[26];
    };

    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->endOfWord = false;
        newNode->word = "";
        for (int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    void insert(trieNode* root, string word) {
        trieNode* crawler = root;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if (crawler->children[ch - 'a'] == NULL) {
                crawler->children[ch - 'a'] = getNode();
            }
            crawler = crawler->children[ch - 'a'];
        }
        crawler->endOfWord = true;
        crawler->word = word;
    }

    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void findWords(vector<vector<char>>& board, int i, int j, trieNode* root) {
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] == '$' || root->children[board[i][j] - 'a'] == NULL)
            return;

        root = root->children[board[i][j] - 'a'];

        if (root->endOfWord) {
            result.push_back(root->word);
            root->endOfWord = false;
        }

        char temp = board[i][j];
        board[i][j] = '$';

        for (auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            findWords(board, new_i, new_j, root);
        }

        board[i][j] = temp; // Restore the board
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size();
        m = board[0].size();

        trieNode* root = getNode();
        for (string& word : words) {
            insert(root, word);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char ch = board[i][j];
                if (root->children[ch - 'a'] != NULL) {
                    findWords(board, i, j, root);
                }
            }
        }

        return result;
    }
};
