


// Lambda Function
auto pairs_sort = [](pair<int, float> a, pair<int, float> b) {return (a.second > b.second);  };
vector<pair<int, float>> test_vector = { {0,0.3}, {1, 0.2}, {3, 0.9}, {4, 1.5}, {5, 0.15} };
sort(test_vector.begin(), test_vector.end(), pairs_sort);


// Convert To Lower Case Latter
transform(data.begin(), data.end(), data.begin(),[](unsigned char c){ return std::tolower(c); });


// Ordered Set
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
cout<<*X.find_by_order(0)<<endl;
cout<<X.order_of_key(-5)<<endl;


// To Integer
ll toint(string s){ll n=0,k=1;for(int i=s.size()-1; i>=0; i--){n += ((s[i]-'0')*k);k*=10;}return n;}


// To String
string tostring(ll x){string s="";while(x){s += (x%10)+'0';x/=10;}reverse(s.begin(),s.end());return s;}


// Sort In Reverse
bool sortinrev(const pair<ll,ll> &a,const pair<ll,ll> &b)return (a.first > b.first);


// Prime Factorization
prime[]={2,4,2,4,6,2} //start loop from 29 to do prime factorization


// Multiset Lower Bound
auto it = lower_bound(my_multiset.begin(), my_multiset.end(), 3);
const auto pos = distance(my_multiset.begin(), it);


// Priority Queue Lower Bound
priority_queue< pll ,vector<pll>,greater<pll> >p;
lower_bound(all(v),r+1)-lower_bound(all(v),l);


// Lower Bound in Set with Pair
set< pair<int,int> >s;
pair<int,int> p={3,2};
auto lb=lower_bound(s.begin(),s.end(),p);
cout<<(*lb).first<<" "<<(*lb).second<<endl;


// BitWise Operations
int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}


// Grids
const int fx[] = {+1,-1,+0,+0};
const int fy[] = {+0,+0,+1,-1};
const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move













