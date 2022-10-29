cycle detection

bool dfs(Node, parent) {
  visit[node] = true;

  for (Node v : Node[v]) {
    if (visited[v]) {
      if (v != parent) {
          return true;
      }
    } else {
      if (dfs(v, node) == true)
        return true;
    }
  }

  return false;
}

// topological sort

