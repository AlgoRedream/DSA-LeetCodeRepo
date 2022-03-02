class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr) return nullptr;
        
        ListNode* odd_head = nullptr;
        ListNode* odd_tail = nullptr;
        ListNode* even_head = nullptr;
        ListNode* even_tail = nullptr;
        
        ListNode* tmp = head;
        bool is_odd = 1;
        
        while(tmp!= nullptr){
            if(is_odd){
                if(odd_head == nullptr){
                    odd_head = odd_tail = tmp;
                }else{
                    odd_tail->next = tmp;
                    odd_tail = tmp;
                }
                tmp = tmp->next;
                odd_tail->next = nullptr;
            }else{
                if(even_head == nullptr){
                    even_head = even_tail = tmp;
                }else{
                    even_tail->next = tmp;
                    even_tail = tmp;
                }
                tmp = tmp->next;
                even_tail->next = nullptr;
            }
            is_odd = !is_odd;
        }
        odd_tail->next = even_head;
        return head;
    }
};
