/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> temp;
        ListNode* pre = head;
        ListNode* curr = head->next;
        bool forward = true;

        if (head->next->next == NULL) {
           return {-1 ,-1} ;
        }
        ListNode* forw = head ->next->next ;



        int ind = 2;
        // cout << forward ;

        while (forward) {
            // cout << ind << ' ' ;
            if (curr->val < pre->val && curr->val < forw->val ||
                curr->val > pre->val && curr->val > forw->val) {
                temp.push_back(ind);
            }

            pre = curr;
            curr = forw;
            if (forw->next != NULL) {
                forw = forw->next;
            } else
                forward = false;
            ind++;
        }

        // cout <<endl ;

        // for (auto i : temp) {
        //     cout << i << ' ';
        // }

        // cout << endl <<endl ;

        int min =-1 ,max=-1 ;

        if(temp.size() < 2){
            return {-1 ,-1} ;
        }

         max = temp[temp.size() -1 ] - temp[0];
        // cout << max << "   " ;

        vector<int> store ;
        for(int i=1 ;i< temp.size() ;i++){
            store.push_back(temp[i] - temp[i-1]) ;
        }

         min = *min_element(store.begin() , store.end());
        // cout << min ; 

        return {min,max};
    }
};