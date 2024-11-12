 for(auto node : adj[curr])
        {
            if(visited[node] == false){
                q.push(node);
                visited[node] = true;
            }
        }