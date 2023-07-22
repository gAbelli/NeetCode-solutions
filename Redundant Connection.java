class Solution {
    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        int[] disjointSet = new int[n];
        for (int i = 0; i < n; ++i) {
            disjointSet[i] = i;
        }

        for (int[] edge : edges) {
            if (union(disjointSet, edge[0] - 1, edge[1] - 1)) {
                return edge;
            }
        }

        return new int[] {-1, -1};
    }

    private int find(int[] disjointSet, int i) {
        if (disjointSet[i] == i) {
            return i;
        }

        int parentI = find(disjointSet, disjointSet[i]);
        disjointSet[i] = parentI;

        // while (disjointSet[i] != i) {
        //     i = disjointSet[i];
        // }

        return parentI;
    }

    private boolean union(int[] disjointSet, int i, int j) {
        int parentI = find(disjointSet, i);
        int parentJ = find(disjointSet, j);
        disjointSet[parentI] = parentJ;
        return parentI == parentJ;
    }
}
