// with help of chatgpt....

#include<bits/stdc++.h>

using namespace std;
vector<int> dijkstra2(int source, int n, const vector<vector<pair<int, int>>>& adj);


                            // Lazy Implimentation (using min heap)
vector<int> dijkstra2(int source, int n, const vector<vector<pair<int, int>>>& adj) {
  
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(n, INT_MAX);
    dist[source] = 0;

    // Insert the source node into the priority queue
    pq.push({0, source});  // {distance, node}
 
    while (!pq.empty()) {
        // Extract the node with the minimum distance as it will be on top (min-heap)....
        int u = pq.top().second;
        int u_dist = pq.top().first;
        pq.pop();

        
        if (u_dist > dist[u]) continue;   // already got minimum distance than u_dist  // here IPQ would help better

        // Looping over neighbors of u
        for (const pair<int, int>& neighbor : adj[u]) {
            int v = neighbor.first;               // Destination node
            int weight = neighbor.second;         // weightage to reach neighbors

            // Relaxation step
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});  // Push updated distance and node into the priority queue
            }
        }
    }

    return dist;
}


class IndexedPriorityQueue {
public:
    IndexedPriorityQueue(int maxSize) : size(0), n(maxSize), heap(maxSize + 1), index(maxSize, -1), keys(maxSize, numeric_limits<int>::max()) {}

    bool isEmpty() const {
        return size == 0;
    }

    bool contains(int i) const {
        return index[i] != -1;
    }

    int minIndex() const {
        return heap[1];
    }

    int minKey() const {
        return keys[heap[1]];
    }

    void insert(int i, int key) {
        keys[i] = key;
        heap[++size] = i;
        index[i] = size;
        swim(size);
    }

    void decreaseKey(int i, int key) {
        keys[i] = key;
        swim(index[i]);
    }

    int deleteMin() {
        int minIndex = heap[1];
        swap(1, size--);
        sink(1);
        index[minIndex] = -1;
        heap[size + 1] = -1;
        return minIndex;
    }

private:
    vector<int> heap;      // Binary heap
    vector<int> index;     // Inverse index to find position in heap
    vector<int> keys;      // Priority keys
    int size, n;

    void swim(int k) {
        while (k > 1 && keys[heap[k]] < keys[heap[k / 2]]) {
            swap(k, k / 2);
            k /= 2;
        }
    }

    void sink(int k) {
        while (2 * k <= size) {
            int j = 2 * k;
            if (j < size && keys[heap[j]] > keys[heap[j + 1]]) j++;
            if (keys[heap[k]] <= keys[heap[j]]) break;
            swap(k, j);
            k = j;
        }
    }

    void swap(int i, int j) {
        std::swap(heap[i], heap[j]);
        index[heap[i]] = i;
        index[heap[j]] = j;
    }
};

                                                // Dijkstra's algorithm using IPQ

vector<int> dijkstra(int source, int n, const vector<vector<pair<int, int>>> &adj) {
    vector<int> dist(n, numeric_limits<int>::max());
    IndexedPriorityQueue ipq(n);
    dist[source] = 0;
    ipq.insert(source, 0);

    while (!ipq.isEmpty()) {
        int u = ipq.deleteMin();
        for (const pair<int, int>& p : adj[u]) {
            int v = p.first;
            int weight = p.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                if (ipq.contains(v)) {
                    ipq.decreaseKey(v, dist[v]);
                } else {
                    ipq.insert(v, dist[v]);
                }
            }
        }
    }

    return dist;
}

int main() {
    FILE *infile = fopen("large_input.txt", "r");
    FILE *outfile = fopen("output.txt", "w");
    
    if (!infile) {
        cerr << "Error opening input file!" << endl;
        return 1;
    }
    if (!outfile) {
        cerr << "Error opening output file!" << endl;
        return 1;
    }
    int t;
    fscanf(infile, "%d", &t);

  
    chrono::duration<double> total_duration(0);  
    chrono::duration<double> total_duration2(0);

    int cnt1=0 , cnt2=0;   // count of how many time IPQ dijkstra perform better
                            // cnt1 for less densed cnt2 for more densed graph
                            //first half node input is less densed second half is relatively more densed


    for(int i=0;i<t;i++){
        int n, m;
        fscanf(infile, "%d %d", &n, &m);

        vector<vector<pair<int, int>>> adj(n);
   
        int u, v, w;
        for (int i = 0; i < m; ++i) {
            fscanf(infile, "%d %d %d", &u, &v, &w);
            adj[u].push_back(make_pair(v, w));       // directed graph
        }

        

        int source;
        fscanf(infile, "%d", &source);
       
        auto start = chrono::high_resolution_clock::now();
        vector<int> distances = dijkstra(source, n, adj);   // calling lazy implimentation of Dijkstra
        auto mid = chrono::high_resolution_clock::now();
        vector<int> distances2 = dijkstra2(source, n, adj);  // calling IPQ Dijkstra
        auto end = chrono::high_resolution_clock::now();


        chrono::duration<double> duration = mid - start;   // time taken by lazy implimentation
        chrono::duration<double> duration2 = end - mid;    // time taken by IPQ Dijkstra

       
        total_duration  += duration;   // total time-taken from IPQ Dijkstra
        total_duration2 += duration2;  // total time-taken from Lazy implimentation of Dijkstra

        // fprintf(outfile, "Time taken by min heap dijkstra and IPQ dijkstra : %f and %f seconds\n", duration2.count() , duration.count());
        if(duration2.count() >= duration.count()){
            if(i<t/2) cnt1++;
            else cnt2++;
        }
        

    }

    fprintf(outfile, "\nOut of %d time IPQ Dijkstra perform %d times better than normal PQ for normal graph\n", t/2,cnt1);
    fprintf(outfile, "\nOut of %d time IPQ Dijkstra perform %d times better than normal PQ forrelatively densed graph\n\n",t-t/2,cnt2);
    fprintf(outfile, "Average time taken by min heap dijkstra and IPQ dijkstra : %.9f and %.9f seconds\n", total_duration2.count()/t , total_duration.count()/t);
    fclose(infile);
    fclose(outfile);

    return 0;
}
