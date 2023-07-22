import java.util.ArrayList;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;

class Pair {
    public String word;
    public int depth;

    public Pair(String word, int depth) {
        this.word = word;
        this.depth = depth;
    }
}

class Solution {
    public int ladderLength(String beginWord, String endWord,
                            List<String> wordList) {
        boolean found = false;
        for (String s : wordList) {
            if (s.equals(beginWord)) {
                found = true;
                break;
            }
        }
        if (!found) {
            wordList.add(beginWord);
        }

        HashMap<String, List<String>> neighbors = new HashMap<>();
        for (String s : wordList) {
            neighbors.put(s, new ArrayList<>());
        }

        for (int i = 0; i < wordList.size(); ++i) {
            for (int j = i + 1; j < wordList.size(); ++j) {
                if (similar(wordList.get(i), wordList.get(j))) {
                    neighbors.get(wordList.get(i)).add(wordList.get(j));
                    neighbors.get(wordList.get(j)).add(wordList.get(i));
                }
            }
        }

        Deque<Pair> queue = new LinkedList<>();
        HashSet<String> visited = new HashSet<>();
        queue.add(new Pair(beginWord, 0));
        visited.add(beginWord);

        while (!queue.isEmpty()) {
            Pair front = queue.poll();
            if (front.word.equals(endWord)) {
                return front.depth + 1;
            }
            for (String neighbor : neighbors.get(front.word)) {
                if (!visited.contains(neighbor)) {
                    queue.add(new Pair(neighbor, front.depth + 1));
                    visited.add(neighbor);
                }
            }
        }

        return 0;
    }

    private boolean similar(String s1, String s2) {
        boolean found = false;

        for (int i = 0; i < s1.length(); ++i) {
            if (s1.charAt(i) != s2.charAt(i)) {
                if (found) {
                    return false;
                }
                found = true;
            }
        }

        return true;
    }
}
