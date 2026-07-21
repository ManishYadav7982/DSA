class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());

        if (st.find(endWord) == st.end()) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        st.erase(beginWord);

        int wordLen = beginWord.size();

        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            // Try changing every character position
            for (int i = 0; i < wordLen; i++) {
                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;

                    // If target found, return total steps
                    if (word == endWord) return steps + 1;

                    // If valid transformation found in set
                    if (st.find(word) != st.end()) {
                        st.erase(word); // Mark visited
                        q.push({word, steps + 1});
                    }
                }

                // Restore original character before testing next position
                word[i] = original;
            }
        }

        return 0;
        
    }
};