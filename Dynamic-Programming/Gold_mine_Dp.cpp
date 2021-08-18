 int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
      vector<vector<int>>a(n,vector<int>(m,0));
      int i,j;
        
        for(i=0;i<n;i++)
        {
            a[i][0]=M[i][0];
        }
        
        for(i=1;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                int v1,v2,v3;
                
                if(i-1>=0 && j-1>=0)
                {
                    v1=a[j-1][i-1];
                }
                else
                {
                    v1=0;
                }
                
                if(i-1>=0 && j>=0)
                {
                    v2=a[j][i-1];
                }
                else
                {
                    v2=0;
                }
                
                if(i-1>=0 && j+1<n)
                {
                    v3=a[j+1][i-1];
                }
                else
                {
                    v3=0;
                }
                
                
                a[j][i]=M[j][i]+max(v1,max(v2,v3));
                
            }
        }
        
        
        int ma=0;
        
        for(i=0;i<n;i++)
        {
            if(ma<a[i][m-1])
            ma=a[i][m-1];
        }
        
        
        return ma;
        
    }