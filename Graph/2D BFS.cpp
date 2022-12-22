ll fx[]= {1,-1,0,0},fy[]= {0,0,1,-1},row,col;
ll cell[100][100],d[100][100],vis[100][100];
void bfs(ll sx,ll sy)
{
    memset(vis,0,sizeof vis);
    vis[sx][sy]=1;
    queue< pll >q;
    q.push(MP(sx,sy));
    while(!q.empty()) {
        pll top=q.front();
        q.pop();
        for(ll k=0; k<4; k++) {
            ll tx=top.ff+fx[k],ty=top.ss+fy[k];
            if(tx>=0 && tx<row && ty>=0 && ty<col && cell[tx][ty]!=-1 && vis[tx][ty]==0)
            {
                vis[tx][ty]=1;
                d[tx][ty]=d[top.ff][top.ss]+1;
                q.push(MP(tx,ty));
            }
        }
    }
}
