//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
#include <ctime>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};  //it is must

Node* createLL() {  //O(n)
    Node * head = NULL;
    Node * tail = NULL;

    while (true) {
        int x;
        cin >> x;
        if (x == -1) break;

        Node * tmp = new Node(x);
        if (head == NULL) {
            //we are inserting the very first node
            head = tail = tmp;
        }
        else {
            //this node is NOT the starting node
            (*tail).next = tmp;
            //tail ->next = tmp
            tail = tmp;
        }
    }
    return head;
}

void printLL(Node* head) {
    Node * curNode = head;
    while (curNode != NULL) {
        cout << curNode->data << "-->";
        curNode = curNode->next;
    }
    cout << endl;
}

int lengthLL(Node * head) {
    int cnt = 0;
    Node* curNode = head;
    while (curNode) {
        ++cnt;
        curNode = curNode->next;
    }
    return cnt;
}

Node* bubbleSort(Node* head) {

    int len = lengthLL(head);
    bool doesSwap = true;

    for (int i = 0; doesSwap && i < len ; ++i) {
        int eleToCheck = len - i;
        doesSwap = false;

        Node * curNode = head;
        Node * prevNode = NULL;
        while (eleToCheck && curNode && curNode->next) {
            Node * ahead = curNode->next;
            if (curNode->data > ahead->data) {
                //if curNode is head
                if (curNode == head) {
                    curNode->next = ahead->next;
                    ahead->next = curNode;
                    head = ahead;
                    prevNode = ahead;
                }
                //if not head
                else {
                    curNode->next = ahead->next;
                    ahead->next = curNode;
                    prevNode->next = ahead;
                    prevNode = ahead;
                }
                doesSwap = true;
            }
            else {
                prevNode = curNode;
                curNode = curNode->next;
            }
            --eleToCheck;
        }
    }
    return head;
}

Node * reverseLL(Node * head) {
    //recursive

    if (head == NULL || head->next == NULL) return head;

    Node * smallerRev = reverseLL(head->next);
    head->next->next = head;
    head->next = NULL;
    return smallerRev;
}

Node * reverseLLIter(Node * head) {
    Node * cur = head;
    Node * prevNode = NULL;

    while (cur) {
        Node * ahead = cur->next;
        cur->next = prevNode;
        prevNode = cur;
        cur = ahead;
    }

    return prevNode;
}


Node* detectCycle(Node * head) {
    Node * slow = head;
    Node * fast = head;
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return slow;
        //cant check in the beginning of loop since it is always true
        //slow and fast are head initialised
    }
    return NULL;
}


void setCycle(Node * head) {
    srand(time(NULL));
    int r_num = rand();

    int len = lengthLL(head);
    // cout << r_num << endl;
    r_num = r_num % len;
    // cout << r_num << endl;

    Node * tail = head;
    while (tail->next) tail = tail->next;

    Node * loopNode = head;
    while (r_num > 0) {
        loopNode = loopNode->next;
        r_num--;
    }

    tail->next = loopNode;
}

void removeCycle(Node * head) {
    Node * meetingPoint = detectCycle(head);

    while (head->next != meetingPoint->next) {
        head = head->next;
        meetingPoint = meetingPoint->next;
    }
    meetingPoint->next = NULL;
}

void addOneLL(Node * head){
    //last non-nine number

    Node * lastNonNine = head;

    while(head){
        if (head->data != 9) lastNonNine = head;
        head = head->next;
    }

    lastNonNine->data += 1;
    lastNonNine = lastNonNine->next;
    while(lastNonNine){
        lastNonNine->data = 0;
        lastNonNine = lastNonNine->next;
    }
}

Node * addNumLL(Node * a, Node * b){
    //Homework
}



int main() {
    Node * head = createLL();
    printLL(head);

    // printLL(head);
    // head = bubbleSort(head);

    // head = reverseLLIter(head);
    // printLL(head);

    // setCycle(head);
    // auto hasCycle = detectCycle(head);
    // cout << hasCycle << " " << hasCycle->data << endl;
    // removeCycle(head);
    // printLL(head);

    addOneLL(head);
    printLL(head);



}
