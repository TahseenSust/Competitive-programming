class MillerRabin {
    private:
    ll prime[7] = { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 };
    int psize = 7;

    ll bigmod ( __int128 a, __int128 p, ll mod ) {
        __int128 x = a % mod, res = 1;
        while ( p ) {
            if ( p & 1 ) res = res * x % mod;
            x = x * x % mod;
            p >>= 1;
        }
        return res;
    }
    bool witness ( ll a, ll d, ll s, ll n ) {
        __int128 r = bigmod( a, d, n );
        if ( r == 1 || r == n - 1 ) return false;
        int i;
        for ( i = 0; i < s - 1; i++ ) {
            r = r * r % n;
            if ( r == 1 ) return true;
            if ( r == n - 1 ) return false;
        }
        return true;
    }

    public:
    bool isPrime ( ll n ) {
        if ( n <= 1 ) return false;
        ll p = n - 1, s = 0;
        while ( ! ( p & 1 ) ) {
            p /= 2;
            s++;
        }
        ll d = p;
        p = n - 1;

        for ( int i = 0; i < psize && prime[i] < n; i++ ) {
            if ( witness ( prime[i], d, s, n ) ) return false;
        }
        return true;
    }
} millerRabin;
