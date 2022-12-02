int s[505][505];
long long m[505][505];
int size=0;
void Print(int i,int j,int out[]){
    if(i==j){
        out[size++]=i;
        return;
    }
    else{
        out[size++]=-1;
        Print(i,s[i][j],out);
        Print(s[i][j]+1,j,out);
        out[size++]=-2;
    }
}
void solve(int n,int p[],int out[]){
    for(int i=1;i<=n;i++){
        m[i][i]=0;
    }
    for(int l=2;l<=n;l++){
        for(int i=1;i<=n-l+1;i++){
            int j=i+l-1;
            m[i][j]=0x3f3f3f3f3f3f3f3f;
            for(int k=i;k<=j-1;k++){
                long long q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j]){
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
    out[size++]=m[1][n]%1000000007;
    Print(1,n,out);
}
