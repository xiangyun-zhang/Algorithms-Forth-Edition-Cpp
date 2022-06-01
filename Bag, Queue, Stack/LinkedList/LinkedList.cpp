#include <iostream>
#include <vector>

template <typename T>
class LinkedList
{
private:
	struct LinkedNode
	{
		T val;
		LinkedNode* next;

		LinkedNode(T value)
		{
			val = value;
			next = nullptr;
		}

		LinkedNode(T value, LinkedNode* nextNode)
		{
			val = value;
			next = nextNode;
		}
	};
	// 虚拟头结点
	LinkedNode* m_dummyHead;
	// 链表大小
	int m_size;

public:
	LinkedList()
	{
		m_dummyHead = new LinkedNode(0);
		m_size = 0;
	}
	int size() { return m_size; }

	// 打印链表
	void printLinkedList()
	{
		LinkedNode* temp = m_dummyHead->next;
		while (temp != nullptr)
		{
			std::cout << temp->val << " ";
			temp = temp->next;
		}
		std::cout << '\n';
	}

	// 获得索引处的值
	int getValue(int index)
	{
		if (index < 0 || index > m_size - 1) { return -1; }
		
		LinkedNode* temp = m_dummyHead->next;
		while (index != 0)
		{
			temp = temp->next;
			index--;
		}
		return temp->val;
	}

	// 在链表头部添加节点
	void addAtHead(T value)
	{
		LinkedNode* temp = new LinkedNode(value, m_dummyHead->next);
		m_dummyHead->next = temp;
		m_size++;
	}

	// 在链表末尾添加节点
	void addAtTail(T value)
	{
		LinkedNode* temp = m_dummyHead;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = new LinkedNode(value);
		m_size++;

	}

	// 在链表索引处添加节点，从0开始
	void addAtIndex(T value, int index)
	{
		// index 不合法直接返回
		if (index > m_size - 1 || index < 0){ return; }

		LinkedNode* temp = m_dummyHead->next;
		
		// 将temp移到待插入点前一个结点
		while (index > 1)
		{
			temp = temp->next;
			index--;
		}
		temp->next = new LinkedNode(value, temp->next);
		m_size++;
	}

	// 删除链表索引处结点，从0开始
	void deleteAtIndex(int index)
	{
		if (index < 0 || index > m_size - 1) { return; }

		LinkedNode* temp = m_dummyHead;

		while (index != 0)
		{
			temp = temp->next;
			index--;
		}
		LinkedNode* deletedNode = temp->next;
		temp->next = temp->next->next;
		delete deletedNode;
		m_size--;
	}

};

int main()
{
	// std::vector<int> testList{ 1,2,3,4,5,6,7,8,9 };
	std::vector<float> testFloatList{ 1.1, 2.4, 5.2, 4.5 };
	LinkedList<float> testFloat;
	for (int i = 0; i < testFloatList.size(); i++)
	{
		testFloat.addAtHead(testFloatList[i]);
	}
	std::cout << testFloat.size() << '\n';
	
	testFloat.addAtTail(55.0);
	testFloat.printLinkedList();

	testFloat.addAtIndex(13.8, 2);
	testFloat.printLinkedList();

	testFloat.deleteAtIndex(1);
	testFloat.printLinkedList();
	return 0;
}