
transform(data.begin(), data.end(), data.begin(),[](unsigned char c){ return std::tolower(c); });
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ll toint(string s){ll n=0,k=1;for(int i=s.size()-1; i>=0; i--){n += ((s[i]-'0')*k);k*=10;}return n;}
string tostring(ll x){string s="";while(x){s += (x%10)+'0';x/=10;}reverse(s.begin(),s.end());return s;}
bool sortinrev(const pair<ll,ll> &a,const pair<ll,ll> &b)return (a.first > b.first);
prime[]={2,4,2,4,6,2} //start loop from 29 to do prime factorization
auto it = lower_bound(my_multiset.begin(), my_multiset.end(), 3);
const auto pos = distance(my_multiset.begin(), it);
priority_queue< pll ,vector<pll>,greater<pll> >p;
lower_bound(all(v),r+1)-lower_bound(all(v),l);
cout<<*X.find_by_order(0)<<endl;
cout<<X.order_of_key(-5)<<endl;
set< pair<int,int> >s;
pair<int,int> p={3,2};
auto lb=lower_bound(s.begin(),s.end(),p);
cout<<(*lb).first<<" "<<(*lb).second<<endl;
