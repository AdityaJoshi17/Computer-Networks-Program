#include <iostream>
#include <vector>
using namespace std;

class LSP
{
public:
    int identity, age, seqno;
    vector<pair<int, int>> links;

    LSP() : identity(0), age(0), seqno(0) {}

    void printLSP() const
    {
        cout << identity << "'s link state packet\n";
        cout << "Identity: " << identity << "\nAge: " << age << "\nSeq No.: " << seqno << "\n";
        cout << "Node\tDist\n";
        for (const auto &link : links)
        {
            cout << link.first + 1 << "\t" << link.second << "\n";
        }
        cout << "\n";
    }
};

int find(int *distance, bool *visited, int n)
{
    int minV, mindist = 1e6;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && distance[i] < mindist)
        {
            minV = i;
            mindist = distance[i];
        }
    }
    return minV;
}

void djikstra(int n, int **edges, int start, int **via)
{
    int *distance = new int[n];
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        distance[i] = 1e5;
        visited[i] = false;
    }
    distance[start] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int minV = find(distance, visited, n);
        visited[minV] = true;
        for (int j = 0; j < n; j++)
        {
            if (edges[minV][j] != -1 && !visited[j])
            {
                int dist = edges[minV][j] + distance[minV];
                if (dist < distance[j])
                {
                    distance[j] = dist;
                    via[start][j] = minV + 1;
                }
            }
        }
    }
    cout << start + 1 << "'s table\n";
    cout << "Node\tDist\tvia\n";
    for (int j = 0; j < n; j++)
    {
        cout << j + 1 << "\t" << distance[j] << "\t";
        if (via[start][j] != -1 && via[start][j] != start + 1)
        {
            if (via[start][via[start][j] - 1] == -1 || via[start][via[start][j] - 1] == start + 1)
                cout << via[start][j] << "\n";
            else
            {
                int x = via[start][j] - 1;
                while (via[start][x] != -1 && via[start][x] != start + 1)
                {
                    x = via[start][x] - 1;
                }
                via[start][j] = x + 1;
                cout << via[start][j] << "\n";
            }
        }
        else
        {
            via[start][j] = -1;
            cout << "-\n";
        }
    }
    cout << "\n";
    delete[] distance;
    delete[] visited;
}

int main()
{
    cout << "Enter no. of nodes and edges: ";
    int n, e;
    cin >> n >> e;
    LSP lsp[n];
    int **edges = new int *[n];
    int **via = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        via[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = -1;
            via[i][j] = -1;
        }
    }
    cout << "Enter edges and their weight: " << endl;
    for (int i = 0; i < e; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        edges[x - 1][y - 1] = wt;
        edges[y - 1][x - 1] = wt;
        lsp[x - 1].links.push_back(make_pair(y - 1, wt));
        lsp[y - 1].links.push_back(make_pair(x - 1, wt));
    }
    cout << endl
         << "Initial LSP" << endl
         << "***********\n";
    for (int i = 0; i < n; i++)
    {
        edges[i][i] = 0;
        lsp[i].identity = i + 1;
        lsp[i].age = (i + 2) % 3;
        lsp[i].seqno = i + 2;
        lsp[i].printLSP();
    }
    cout << endl
         << "Routing Table after link state routing" << endl
         << "**************************************\n";
    for (int i = 0; i < n; i++)
    {
        djikstra(n, edges, i, via);
    }

    return 0;
}
