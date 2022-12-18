int failure[mxx];
void build_failure_function(string pattern, int m)
{
    int len = 0,i=1;
    failure[0] = 0;
    while (i < m) {
        if (pattern[i] == pattern[len])
        {
            len++;
            failure[i] = len;
            i++;
        }
        else {
            if (len != 0)len = failure[len - 1];
            else failure[i] = 0,i++;
        }
    }
}
int kmp(string txt,string pat)
{
    int N=txt.size(),M=pat.size(),res=0;
    int i=0,j=0;
    while (i < N)
    {
        if (pat[j] == txt[i])j++,i++;
        if (j == M)res++,j = failure[j - 1];
        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)j = failure[j - 1];
            else i = i + 1;
        }
    }
    return res;
}
int main()
{
    string s,p; cin>>s>>p;
    build_failure_function(p,p.size());
    int val=kmp(s,p);
    }
