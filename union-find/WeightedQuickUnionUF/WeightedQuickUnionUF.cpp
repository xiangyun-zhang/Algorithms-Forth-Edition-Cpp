#include <iostream>
#include <vector>
#include <string>

class WeightedUnionFindUF
{
private:
    // 分量id（以触点作为索引）
    std::vector<int> m_id;
    // 以各个触点为根节点对应的分量大小
    std::vector<int> m_size;
    // 分量数量
    int m_count;

public:
    WeightedUnionFindUF(int N)
    {
        // 初始化分量id数组
        m_count = N;
        for (int i = 0; i < N; i++)
        {
            m_id.push_back(i);
            m_size.push_back(1);
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

    /*----------weighted quick-union algorithm begin----------*/
    int find(int p)
    {
        while (m_id[p] != p)
        {
            p = m_id[p];
        }
        return p;
    }

    void Union(int p, int q)
    {
        int rootP{ find(p) };
        int rootQ{ find(q) };

        if (rootP != rootQ)
        {
            if (m_size[rootP] < m_size[rootQ])
            {
                m_id[rootP] = rootQ;
                m_size[rootQ] += m_size[rootP];
            }
            else
            {
                m_id[rootQ] = rootP;
                m_size[rootP] += m_size[rootQ];
            }
            m_count--;
        }
    }
    /*----------weighted quick-union algorithm end----------*/
};

int main()
{
    std::vector<int> Ps{ 4,3,6,9,2,8,5,7,6,1,6 };
    std::vector<int> Qs{ 3,8,5,4,1,9,0,2,1,0,7 };

    int N = 10;
    WeightedUnionFindUF uf{ N };
    uf.printUF();

    for (int i = 0; i < Ps.size(); i++)
    {
        int p = Ps[i];
        int q = Qs[i];

        if (uf.connected(p, q))
        {
            continue;
        }

        uf.Union(p, q);
        std::cout << std::to_string(p) + " " + std::to_string(q) << '\n';
        uf.printUF();
        std::cout << '\n';
    }
    std::cout << uf.count();
    std::cout << " components." << '\n';
    return 0;
}