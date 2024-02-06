class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i<lists.size(); i++){
            ListNode* head = lists[i];
            while(head){
                pq.push(head->val);
                head = head->next;
            }
        }
        ListNode* head = new ListNode(-1), *curr = head;
        while(!pq.empty()){
            curr->next = new ListNode(pq.top());
            pq.pop();
            curr = curr->next;
        }
        return head->next;

    }
};