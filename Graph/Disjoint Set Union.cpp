// Disjoint Set Union 



ll parent[100];
void make_set(int v)
{
    parent[v] = v;
}

int find_set(int v)
{
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}



// Union By Size



int siz [100],parent[100];
void make_set(int v)
{
    parent[v] = v;
    siz[v] = 1;
}
int find_set(int v)
{
    if (v == parent[v])return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b)
{
    a = find_set(a); b = find_set(b);
    if (a != b)
    {
        if (siz[a] < siz[b])swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
    }
}


// Union By Rank



ll parent[100],rannk[100];
void make_set(int v)
{
    parent[v] = v;
    rannk[v] = 0;
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (rannk[a] < rannk[b])swap(a, b);
        parent[b] = a;
        if (rannk[a] == rannk[b])rannk[a]++;
    }
}



// Support distances up to representative


void make_set(int v){
    parent[v] = make_pair(v, 0);
    rannk[v] = 0;
}
pair<int, int> find_set(int v){
    if (v != parent[v].first) {
        int len = parent[v].second;
        parent[v] = find_set(parent[v].first);
        parent[v].second += len;
    }
    return parent[v];
}
void union_sets(int a, int b){
    a = find_set(a).first;
    b = find_set(b).first;
    if (a != b) {
        if (rannk[a] < rannk[b])swap(a, b);
        parent[b] = make_pair(a, 1);
        if (rannk[a] == rannk[b])rannk[a]++;
    }
}
