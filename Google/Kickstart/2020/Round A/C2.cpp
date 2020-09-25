#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define pu push
#define pp pop_back
#define in insert
#define MOD 1000000007
#define endl "\n"
#define sz(a) (int)((a).size())
#define all(x) (x).begin(), (x).end()
#define trace(x) cerr << #x << ": " << x << " " << endl;
#define prv(a) for(auto x : a) cout << x << ' ';cout << '\n';
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define OTP(s) cout<<s<<endl;
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
inline ll add(ll a, ll b){a += b; if(a >= MOD)a -= MOD; return a;}
inline ll sub(ll a, ll b){a -= b; if(a < 0)a += MOD; return a;}
inline ll mul(ll a, ll b){return (ll)((ll) a * b %MOD);}
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

ll min(ll a,ll b)
{
    return a>b?b:a;
}
ll max(ll a,ll b)
{
    return a>b?a:b;
}

const int ALPHABET_SIZE = 27; 
  
// trie node 
struct TrieNode 
{ 
    struct TrieNode *children[ALPHABET_SIZE]; 
  
    // isEndOfWord is true if the node represents 
    // end of a word 
    bool isEndOfWord; 
    int cnt;
}; 
  
// Returns new trie node (initialized to NULLs) 
struct TrieNode *getNode(void) 
{ 
    struct TrieNode *pNode =  new TrieNode; 
  
    pNode->isEndOfWord = false; 
  
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL; 
    pNode->cnt=0;
  
    return pNode; 
} 
  
// If not present, inserts key into trie 
// If the key is prefix of trie node, just 
// marks leaf node 
void insert(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
    root->cnt++;
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'A'; 
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
        
        pCrawl = pCrawl->children[index]; 
        pCrawl->cnt++;
    } 
  
    // mark last node as leaf 
    pCrawl->isEndOfWord = true; 
    if (!pCrawl->children[26]) 
            pCrawl->children[26] = getNode(); 
        
        pCrawl = pCrawl->children[26]; 
        pCrawl->cnt++;
} 

    vl vt;
    ll t,n,k;

void dfs(TrieNode *root, int depth)
{   
    REP(i,27)
    {
        if(root->children[i] && root->children[i]->cnt < k)
        {
            REP(j,root->children[i]->cnt)
            {
                vt.pb(depth+1);
            }
        }
        else if(root->children[i])
        {
            dfs(root->children[i],depth+1);
        }
        
    }   
}

int main()
{
    // IOS
    cin>>t;
    string s;
    REP(te,t)
    {
        vt.clear();
        TrieNode  *root=getNode();
        cin>>n>>k;
        REP(i,n)
        {
            cin>>s;
            insert(root,s);
        }
        dfs(root,0);
        // cout<<"herre\n";
        sort(all(vt), greater<ll>());
        ll ans=0;
        ll ind=0;
        // cout<<root->children['G'-'A']->children[26]->cnt<<endl;
        trace(sz(vt))
        REP(i,sz(vt))   cout<<vt[i]<<" ";
        cout<<endl;
        while(ind<sz(vt))
        {
            ans+=vt[ind];
            ind+=k;
        }
        cout<<"Case #"<<te+1<<": "<<ans<<endl;       
    }
}