#include <iostream>
#include <vector>
#include <string>

class UF
{
private:
    // 分量id（以触点作为索引）
    std::vector<int> m_id;
    // 分量数量
    int m_count;

public:
    UF(int N)
    {
        // 初始化分量id数组
        m_count = N;
        for (int i = 0; i < N; i++)
        {
            m_id.push_back(i);
        }
    }

    int count() { return m_count; }

    bool connected(int p, int q) { return find(p) == find(q); }

    void printUF()
    {
        for (int j = 0; j < m_id.size(); j++)
        {
            std::cout << j;
            std::cout << ' ';
        }
        std::cout << '\n';
        for (int j = 0; j < m_id.size(); j++)
        {
            std::cout << m_id[j];
            std::cout << ' ';
        }
        std::cout << '\n';
    }

    /*----------quick-find algorithm begin----------*/
    int find(int p){ return m_id[p]; }

    void Union(int p, int q)
    {
        // 将p和q归并到相同的分量中
        int pId = find(p);
        int qId = find(q);

        // 将p的分量重命名为q的分量
        m_id[p] = qId;
        for (int i = 0; i < m_id.size(); i++)
        {
            if (m_id[i] == pId)
            {
                m_id[i] = qId;
            }
        }
        m_count--;
    }
    /*----------quick-find algorithm end----------*/
};

int main()
{
    std::vector<int> Ps{ 4,3,6,9,2,5,7,6,1,6 };
    std::vector<int> Qs{ 3,8,5,4,1,0,2,1,0,7 };

    int N = Ps.size();
    UF uf{ N };
    uf.printUF();

    for (int i = 0; i < Ps.size(); i++)
    {
        int p = Ps[i];
        int q = Qs[i];
        std::cout << std::to_string(p) + " " + std::to_string(q) << '\n';
        if (uf.connected(p, q))
        {
            continue;
        }

        std::cout << std::to_string(p) + " " + std::to_string(q) << '\n';
        uf.printUF();
        std::cout << '\n';
    }
    std::cout << uf.count();
    std::cout << " components." << '\n';
    return 0;
}