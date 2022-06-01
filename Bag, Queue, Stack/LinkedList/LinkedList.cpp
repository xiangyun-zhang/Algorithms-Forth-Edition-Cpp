#include <iostream>
#include <vector>

class LinkedList
{
private:
	struct LinkedNode
	{
		int val;
		LinkedNode* next;

		LinkedNode(int value)
		{
			val = value;
			next = nullptr;
		}

		LinkedNode(int value, LinkedNode* nextNode)
		{
			val = value;
			next = nextNode;
		}
	};
	// ����ͷ���
	LinkedNode* m_dummyHead;
	// �����С
	int m_size;

public:
	LinkedList()
	{
		m_dummyHead = new LinkedNode(0);
		m_size = 0;
	}
	int size() { return m_size; }

	// ��ӡ����
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

	// �����������ֵ
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

	// ������ͷ����ӽڵ�
	void addAtHead(int value)
	{
		LinkedNode* temp = new LinkedNode(value, m_dummyHead->next);
		m_dummyHead->next = temp;
		m_size++;
	}

	// ������ĩβ��ӽڵ�
	void addAtTail(int value)
	{
		LinkedNode* temp = m_dummyHead;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = new LinkedNode(value);
		m_size++;

	}

	// ��������������ӽڵ㣬��0��ʼ
	void addAtIndex(int value, int index)
	{
		// index ���Ϸ�ֱ�ӷ���
		if (index > m_size - 1 || index < 0){ return; }

		LinkedNode* temp = m_dummyHead->next;
		
		// ��temp�Ƶ��������ǰһ�����
		while (index > 1)
		{
			temp = temp->next;
			index--;
		}
		temp->next = new LinkedNode(value, temp->next);
		m_size++;
	}

	// ɾ��������������㣬��0��ʼ
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
	std::vector<int> testList{ 1,2,3,4,5,6,7,8,9 };
	LinkedList test;
	for (int i = 0; i < testList.size(); i++)
	{
		test.addAtHead(testList[i]);
	}
	std::cout << test.size() << '\n';
	test.addAtTail(55);
	test.printLinkedList();
	std::cout << test.size() << '\n';
	test.addAtIndex(13, 5);
	test.printLinkedList();
	std::cout << test.size() << '\n';
	test.deleteAtIndex(8);
	test.printLinkedList();
	std::cout << test.size() << '\n';
	return 0;
}