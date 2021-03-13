ool chk(ll x, ll y)
{
    if(x==0) return 1;
    ll nd = nod(x); 
    // trace(nd)
    ll tm = 1;
    ll t2 = 1;
    REP(p,nd-1)
    {
        tm*=10;
        t2*=5;
    }
    if((x/tm)%2 == (y%2))
    {
        return chk(x%tm, y+1);
    }
    return 0;
}