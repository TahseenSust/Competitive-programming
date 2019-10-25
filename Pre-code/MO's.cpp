//O((N+Q)(√N)P(N))

void remove(idx);  // TODO: remove value at idx from data structure
void add(idx);     // TODO: add value at idx from data structure
int get_answer();  // TODO: extract the current answer of the data structure

int block_size;

struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) < make_pair(other.l / block_size, other.r);
    }
    /* for better runtime
    bool cmp(pair<int, int> p, pair<int, int> q) {
    if (p.first / BLOCK_SIZE != q.first / BLOCK_SIZE)
            return p < q;
        return (p.first / BLOCK_SIZE & 1) ? (p.second < q.second) : (p.second > q.second);
    }    
    */
};

/*
We know it can be optimized a little if for even blocks we use the reverse order for the right boundary:


struct Query {
	int l, r, idx;
	
	inline pair<int, int> toPair() const {
		return make_pair(l / block, ((l / block) & 1) ? -r : +r);
	}
};

inline bool operator<(const Query &a, const Query &b) {
	return a.toPair() < b.toPair();
}

*/

vector<int> mo_s_algorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure

    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }
    return answers;
}

// MOs with update

struct query {
  int l, r, t, id; // t is number of updates before, id is this query's id
} q[maxn];

struct update {
  int x, pre, now;
} u[maxn];

void apply(int x, int t) {
  if(l <= x && x <= r) {  // l, r is the l, r from MO's algo
    remove(x);
    a[x] = y;
    add(x);
  } else a[x] = y;
}

bool cmp(query &a, query &b) {
  int l1 = a.l / k, l2 = b.l / k,
    r1 = a.r / k, r2 = b.r / k;
  // Left blocks differ, they aren't in same group,
  // first comes who have smaller left block.
  if(l1 != l2) return l1 < l2;  
  // So here we have same Left Block, but if Right Blocks aren't equal,
  // then who have right block smaller comes first.
  if(r1 != r2) return r1 < r2;
  // Now we have l1 == l2 and r1 == r2,
  // So both a and b query is in same group,
  // sort them based on time.
  return a.t < b.t;
}

int l = 0, r = -1, t = 0; // Note that these values may change
                          // Depending on your implementation of other part
for(int i = 0; i < Q; i++) {
  while(t < q[i].t) t++, apply(u[t].x, u[t].now); // Forward Update
  while(t > q[i].t) apply(u[t].x, u[y].pre), t--; // Reverse Update

  while(l > q[i].l) add(--l);
  while(r < q[i].r) add(++r);
  while(l < q[i].l) remove(l++);
  while(r > q[i].r) remove(r--);

  ans[q[i].id] = some_variable;
}
