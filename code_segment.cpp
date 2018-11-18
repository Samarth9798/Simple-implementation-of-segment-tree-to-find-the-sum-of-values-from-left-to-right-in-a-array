#include<bits/stdc++.h>
using namespace std;
int tree[4000005]; //tree array change the size if required
int arr[100005];  //original array where we store scanned values change size if required

//buid function of the tree array
void build(int node,int start,int end)
{
    if(end==start)
        tree[node]=arr[start];
    else
    {
        int mid=(start+end)/2;
        build(2*node,start,mid);
        build(2*node + 1,mid + 1,end);
        
        tree[node]=tree[2*node]+tree[2*node + 1];
    }
}

//update function of the tree 
void update(int node,int start,int end,int idx,int val)
{
    if(start==end)
    {
        tree[idx]=val;
        arr[idx]=val;
    }
    else
    {
        int mid=(start+end)/2;
        if(start<=idx and idx<=mid)
        {
            update(2*node,start,mid,idx,val);
        }
        else
        {
            update(2*node + 1,mid + 1,end,idx,val);
        }
        tree[node]=tree[2*node]+tree[2*node + 1];
    }
}

//query fuction to calculate the sum from L to R
int query(int node,int start,int end,int l,int r)
{
    if(r < start or end < l)
    {
        return 1000005;
    }
    if(l<=start and end<=r)
    {
        return tree[node];
    }
    int mid=(start+end)/2;
    int p1=query(2*node,start,mid,l,r);
    int p2=query(2*node + 1,mid + 1,end,l,r);
    
    return (p1+p2);
}

//driver function
int main()
{
    int n,q;
    cin>>n>>q;
    int i;
    for(i=1;i<=n;i++) cin>>arr[i];
    char c;
    int l,r;
    build(1,1,n);
    while(q)
    {
        cin>>c>>l>>r;
        int ans;
        if(c=='q')
        {
            ans=query(1,1,n,l,r);
            cout<<ans<<endl;
        }
        else
        {
            update(1,1,n,l,r);
        }
        q-=1;
    }
}
