int ans;
void recurs(int ara[], int i, int j, int num, int numofele, int n)
{
    if (i+1 == numofele) return ;
    int x, y;
    for (x = i; x <numofele; x++)
    {
        y = lcm(ara[x], j);

        if ((num+1)%2==1) ans+=(n/y);
        else ans-=(n/y);
        recurs(ara, x+1, y, num+1, numofele, n);
    }
}
int main(){
    int ara[] = {2, 3, 5, 6, 7, 11, 13, 15, 17},n=1000,m=9;
    recurs(ara, 0, 1, 0, m, n);
}
