#include <iostream>

// 노드 구조체 정의
struct Node {
    int data; // 노드에 저장될 데이터
    Node* next; // 다음 노드를 가리키는 포인터

    // 생성자
    Node(int data) {
        this->data = data; // 데이터 초기화
        this->next = nullptr; // 다음 노드가 없으므로 nullptr로 초기화
    }
};

// 링크드 리스트 클래스 정의
class LinkedList {
private:
    Node* head; // 리스트의 시작을 가리키는 헤드 포인터

public:
    // 생성자
    LinkedList() {
        head = nullptr; // 초기 헤드 포인터는 nullptr로, 즉 리스트가 비어있음을 의미
    }

    // 노드를 리스트의 맨 앞에 추가하는 함수
    void pushFront(int newData) {
        Node* newNode = new Node(newData); // 새 노드 생성
        newNode->next = head; // 새 노드의 다음 노드를 현재 헤드로 설정
        head = newNode; // 헤드를 새 노드로 변경
    }

    // 리스트의 맨 끝에 노드를 추가하는 함수
    void pushBack(int newData) {
        Node* newNode = new Node(newData); // 새 노드 생성
        if (head == nullptr) { // 리스트가 비어있는 경우
            head = newNode; // 헤드를 새 노드로 설정
        }
        else { // 리스트에 노드가 있는 경우
            Node* temp = head; // 처음부터 탐색 시작
            while (temp->next != nullptr) { // 마지막 노드까지 이동
                temp = temp->next;
            }
            temp->next = newNode; // 마지막 노드의 다음 노드를 새 노드로 설정
        }
    }

    // 리스트 출력 함수
    void printList() {
        Node* temp = head; // 처음부터 탐색 시작
        while (temp != nullptr) { // 리스트의 끝까지 이동
            std::cout << temp->data << " -> "; // 현재 노드의 데이터 출력
            temp = temp->next; // 다음 노드로 이동
        }
        std::cout << "NULL" << std::endl; // 리스트의 끝을 나타냄
    }

    // 소멸자: 생성된 모든 노드 메모리 해제
    ~LinkedList() {
        Node* temp;
        while (head != nullptr) { // 리스트의 끝까지 이동
            temp = head; // 현재 헤드를 임시 변수에 저장
            head = head->next; // 헤드를 다음 노드로 이동
            delete temp; // 임시 변수(현재 노드) 메모리 해제
        }
    }
};

int main() {
    LinkedList list; // 링크드 리스트 인스턴스 생성

    // 노드 추가
    list.pushBack(1); // 리스트 끝에 1 추가
    list.pushBack(2); // 리스트 끝에 2 추가
    list.pushFront(0); // 리스트 앞에 0 추가
    list.pushBack(3); // 리스트 끝에 3 추가
    

    std::cout << "링크드 리스트: ";
    list.printList(); // 리스트 출력

    return 0;
}
