#include<bits/stdc++.h>
using namespace std;

struct trie
{
    struct trie *child[26];
    bool isend;
    trie()
    {
        for(int i=0;i<26;i++)
        {
            child[i]=NULL;
        }
        isend=false;
    }

};
trie *root;


void insert(string s)
{
    trie *curr=root;
    for(int i=0;i<s.size();i++)
    {
        int k=s[i]-'a';
        if(curr->child[k]==NULL)
        {
           curr->child[k]=new trie();
        }
        curr=curr->child[k];
    }
    curr->isend=true;
}

bool search(string s)
{
    trie *curr=root;
    for(int i=0;i<s.size();i++)
    {
        int k=s[i]-'a';
        if(curr->child[k]==NULL)
        {
            return false;
        }
        else{
            curr=curr->child[k];
        }
    }
    return curr->isend;
}

void dlt(trie * curr)
{
    for(int i=0;i<26;i++)
    {
        if(curr->child[i])
        {
            dlt(curr->child[i]);
        }
    }
    delete(curr);
}

void  solve()
{
    root=new trie();
    int n,i,j,k;
    cin>>n>>j;
    while(n--)
    {
        string s;
        cin>>s;
        insert(s);
    }
    while(j--)
    {
          string s;
        cin>>s;
        cout<<search(s)<<endl;
    }
    dlt(root);
}


main()
{
    int t;
   // cin>>t;
    t=1;
    while(t--)
    solve();
}
