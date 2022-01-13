class Solution {
    int k;
public:
    bool check(vector<int>& a,int s,int vis[]){
        int pid,i=s,cnt=0,n=a.size(),p=a[s];
        k++;
        // ith index is first visited in kth session
        vis[i]=k;
        while(1){
            pid=i;
            // going to next index
            if(a[i]<0){
                if(i>=abs(a[i]))
                    i=i-abs(a[i]);
                else{
                    int d=abs(a[i])%n;
                    i=(n-(d-i))%n;
                }
            }
            else
                i=(i+a[i])%n;
            
            // if different signs
            if(p*a[i]<0)
                return 0;
            
            // if this node has been visited in some prev session
            if(vis[i]<k and vis[i]>=0)
                return 0;
                
            // if this node has been visited prev but in current session
            if(vis[i]==k)
                return i!=pid; // cycle length > 1
            
            vis[i]=k;
        }
        return 0;
    }
    
    bool circularArrayLoop(vector<int>& a) {        
        k=0; // session number 
        int n=a.size();
        int vis[n];
        memset(vis,-1,sizeof(vis));
        for(int i=0;i<n;i++)
            if(vis[i]==-1 and check(a,i,vis))
                return 1;
        return 0;
    }
};