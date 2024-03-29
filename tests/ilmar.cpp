#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(200001, vector<int>()); 

void dfs(int v, int e) {
 for (int u : adj[v]) {
  if (u == e) continue;
  dfs(u, v);
 }
}

void process_mem_usage(double& vm_usage, double& resident_set)
{
   using std::ios_base;
   using std::ifstream;
   using std::string;

   vm_usage     = 0.0;
   resident_set = 0.0;

   // 'file' stat seems to give the most reliable results
   //
   ifstream stat_stream("/proc/self/stat",ios_base::in);

   // dummy vars for leading entries in stat that we don't care about
   //
   string pid, comm, state, ppid, pgrp, session, tty_nr;
   string tpgid, flags, minflt, cminflt, majflt, cmajflt;
   string utime, stime, cutime, cstime, priority, nice;
   string O, itrealvalue, starttime;

   // the two fields we want
   //
   unsigned long vsize;
   long rss;

   stat_stream >> pid >> comm >> state >> ppid >> pgrp >> session >> tty_nr
               >> tpgid >> flags >> minflt >> cminflt >> majflt >> cmajflt
               >> utime >> stime >> cutime >> cstime >> priority >> nice
               >> O >> itrealvalue >> starttime >> vsize >> rss; // don't care about the rest

   stat_stream.close();

   long page_size_kb = sysconf(_SC_PAGE_SIZE) / 1024; // in case x86-64 is configured to use 2MB pages
   vm_usage     = vsize / 1024.0;
   resident_set = rss * page_size_kb;
}


int main() {
 ios::sync_with_stdio(false);
 cin.tie(0);
 cout.tie(0);

 int n;
 cin >> n;
 for (int i = 0; i < n - 1; i++) {
  int a, b;
  cin >> a >> b; 
  adj[a].push_back(b);
  adj[b].push_back(a);
 }

 dfs(1, 0);




 cout << "fim" << endl;

   double vm, rss;
   process_mem_usage(vm, rss);
   cout << "VM: " << vm << "; RSS: " << rss << endl;

 return 0;
}