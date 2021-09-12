import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;

public class ProblemD {



    public BufferedReader scanner = new BufferedReader(new InputStreamReader(System.in));
    public PrintWriter out = new PrintWriter(System.out);
    public String[] in;
    public  int n, m;
    final int MAXN = (int) 4e5;

    void process()  throws  Exception {
        in = scanner.readLine().split(" ");
        n = Integer.parseInt(in[0]);
        m = Integer.parseInt(in[1]);
        ArrayList<ArrayList<ArrayList<Integer>>> rows = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
             rows.add(new ArrayList<>());
        }
        for (int i = 0; i < m; i++) {
             in = scanner.readLine().split(" ");
             int index = Integer.parseInt(in[0]) - 1;
             int l = Integer.parseInt(in[1]) - 1;
             int r= Integer.parseInt(in[2]) - 1;
             ArrayList<Integer> segment =  new ArrayList<>();
             segment.add(l);
             segment.add(r);
             rows.get(index).add(segment);
        }

        IntervalTree tree = new IntervalTree(4*MAXN);
        int[] trace = new int[n+1];
        int maxVal = -1;
        int maxValIndex = -1;
        IntervalTree.Node best;
        for(int i = 0; i < n; i++){
            best = null;
            for(ArrayList<Integer> segment:rows.get(i)){
                IntervalTree.Node cur = tree.getValue(segment.get(0),segment.get(1)+1,tree.root);
                if(best == null || cur.value > best.value){
                    best = cur;
                }
            }
            if(best == null) continue;
            trace[i] = best.index;
            if(best.value + 1 > maxVal || maxVal == -1){
                maxVal = best.value + 1;
                maxValIndex = i;
            }
            int bestVal = best.value;
            for(ArrayList<Integer> segment:rows.get(i)){
                tree.add(segment.get(0),segment.get(1)+1,bestVal+1,i,tree.root);
            }
        }
        out.write((n - maxVal) + "\n");
        HashSet<Integer> toRemove = new HashSet<>();
        for(int i = 0; i < n; i++){
            toRemove.add(i);
        }
        while(maxValIndex != -1){
            toRemove.remove(maxValIndex);
            maxValIndex = trace[maxValIndex];
        }
        int i = 1;
        for(Integer remove:toRemove){
            out.write((remove + 1) + "");
            if(i == toRemove.size()) continue;
            out.write(" ");
        }

        out.flush();
    }

    public static void main(String[] args) throws Exception {
        ProblemD app = new ProblemD();
        app.process();
    }

    static class IntervalTree {
        class Node{
            public int min;
            public int max;
            public int value = 0;
            public int index = -1;
            public Node left = null;
            public Node right = null;

            public Node(int min, int max){
                this.min = min;
                this.max = max;
            }
        }
        public Node root;

        public IntervalTree(int n){
            int i = 1;
            while(i < n){
                i *= 2;
            }
            root = new Node(0,i);
        }

        void populate(Node current, int lastIndex,int lastVal){
            int l = current.min;
            int r = current.max;
            if(l + 1 == r) return;
            int m = (l+r)/2;
            current.left = new Node(l,m);
            current.right = new Node(m,r);
            current.left.value = lastVal;
            current.right.value = lastVal;
            current.left.index = lastIndex;
            current.right.index = lastIndex;
        }

        public void add(int l, int r, int amount, int index, Node current){
            int lastVal = current.value;
            int lastIndex = current.index;
            if(current.value < amount){
                current.value = amount;
                current.index = index;
                if(current.min >= l && current.max <= r){
                    current.left = null;
                    current.right = null;
                    return;
                }
            } else if (current.left == null) return;
            if(current.left == null){
                populate(current,lastIndex,lastVal);
            }
            if(current.right.min > l){
                add(l,r,amount,index,current.left);
            }
            if(current.right.min < r){
                add(l,r,amount,index,current.right);
            }
        }

        public Node getValue(int l, int r, Node current){
            if((current.min >= l && current.max <= r) || current.left == null) return current;
            Node left = null;
            Node right = null;
            if(current.right.min > l){
                left = getValue(l,r,current.left);
            }
            if(current.right.min < r){
                right = getValue(l,r,current.right);
            }
            return right == null || (left != null && left.value > right.value) ? left:right;
        }

        public long getValue(int index){
            long value = 0;
            Node current = root;
            while(true){
                value += current.value;
                if(current.min + 1 == current.max) return value;
                if(current.right.min <= index){
                    current = current.right;
                    continue;
                }
                current = current.left;
            }
        }
    }
}
