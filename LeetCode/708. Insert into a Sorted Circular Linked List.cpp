// 场景 A：插入在中间 (Normal Case)
// 如果找到一个位置满足 prev->val <= insertVal <= curr->val，这就是标准的插入点。
// 例如：1 -> 3 -> 5，插入 4。

// 场景 B：插入在边界 (Edge Case - Max/Min)
// 如果 insertVal 比链表里最大的还大，或者比最小的还小，它应该插入在**“转折点”**（即从最大跳回最小的地方）。
// 特征：prev->val > curr->val（prev 是最大值，curr 是最小值）。
// 插入条件：insertVal >= prev->val 或 insertVal <= curr->val。

// 场景 C：全等或一圈走完 (Single/Identical Case)
// 如果链表里所有值都一样，或者我们绕了一圈也没找到上述两个点，那就随便找个位置（通常是起点）插进去。
// 708. 循环有序列表的插入
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        // 1. 如果链表为空
        if (head == nullptr) {
            Node* newNode = new Node(insertVal);
            newNode->next = newNode; // 自己指向自己形成循环
            return newNode;
        }

        Node *prev = head;
        Node *curr = head->next;
        bool toInsert = false;

        do {
            // 场景 A: 插入在中间 (e.g., 1 <= 2 <= 3)
            if (prev->val <= insertVal && insertVal <= curr->val) {
                toInsert = true;
            }
            // 场景 B: 碰到转折点 (最大值跳到最小值)
            else if (prev->val > curr->val) {
                // 如果 insertVal 是全场最大或全场最小
                if (insertVal >= prev->val || insertVal <= curr->val) {
                    toInsert = true;
                }
            }

            if (toInsert) {
                prev->next = new Node(insertVal, curr);
                return head;
            }

            prev = curr;
            curr = curr->next;
        } while (prev != head); // 走完一圈停止

        // 场景 C: 循环一圈没找到（全等链表），直接插在 head 后面
        prev->next = new Node(insertVal, curr);
        return head;
    }
};
