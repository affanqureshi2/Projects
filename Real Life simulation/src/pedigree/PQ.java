package pedigree;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.PriorityQueue;


public class PQ{
    // Java implementation of Min Heap
//        private double[] Heap;
        PriorityQueue<Double> Heap = new PriorityQueue<Double>();
        private int size;
        private int maxsize;
        private ArrayList<Event> eQueue;
        Event temp;

        private static final int FRONT = 1;

        public PQ(int maxsize)
        {
//            Heap = null;
            this.maxsize = maxsize;
            this.size = 0;
//            Heap = new double[this.maxsize + 1];
//            Heap[0] = Integer.MIN_VALUE;
            eQueue = new ArrayList<>();
        }

        // Function to return the position of
        // the parent for the node currently
        // at pos
        private int parent(int pos)
        {
            return pos / 2;
        }

        // Function to return the position of the
        // left child for the node currently at pos
        private int leftChild(int pos)
        {
            return (2 * pos);
        }

        // Function to return the position of
        // the right child for the node currently
        // at pos
        private int rightChild(int pos)
        {
            return (2 * pos) + 1;
        }

        // Function that returns true if the passed
        // node is a leaf node
        private boolean isLeaf(int pos)
        {
            if (pos >= (size / 2) && pos <= size) {
                return true;
            }
            return false;
        }

        // Function to swap two nodes of the heap
//        private void swap(int fpos, int spos)
//        {
//            double tmp;
//            tmp = Heap[fpos];
//            Heap[fpos] = Heap[spos];
//            Heap[spos] = tmp;
//        }

        // Function to heapify the node at pos
//        private void minHeapify(int pos)
//        {
//
//            // If the node is a non-leaf node and greater
//            // than any of its child
//            if (!isLeaf(pos)) {
//                if (Heap[pos] > Heap[leftChild(pos)]
//                        || Heap[pos] > Heap[rightChild(pos)]) {
//
//                    // Swap with the left child and heapify
//                    // the left child
//                    if (Heap[leftChild(pos)] < Heap[rightChild(pos)]) {
//                        swap(pos, leftChild(pos));
//                        minHeapify(leftChild(pos));
//                    }
//
//                    // Swap with the right child and heapify
//                    // the right child
//                    else {
//                        swap(pos, rightChild(pos));
//                        minHeapify(rightChild(pos));
//                    }
//                }
//            }
//        }

    public boolean checkTimeLimit(){
        Iterator<Double> iter = Heap.iterator();
        while (iter.hasNext()) {
            if(iter.next()>maxsize){
                return true;
            }
        }
        return false;
    }
        // Function to insert a node into the heap
        public void insert(Event element)
        {
            if (checkTimeLimit()) {
                return;
            }
//            Heap[++size] = element.time;
            Heap.add(element.time);
            eQueue.add(element);
//            int current = size;
//
//            while (Heap[current] < Heap[parent(current)]) {
//                swap(current, parent(current));
//                current = parent(current);
//            }
            //System.out.println(Heap);
        }

    /*public void insert(Sim element)
    {
        if (size >= maxsize) {
            return;
        }
        Heap[++size] = element.getDeathTime();
        Population.add(element);
        int current = size;

        while (Heap[current] < Heap[parent(current)]) {
            swap(current, parent(current));
            current = parent(current);
        }

    }
*/
        // Function to print the contents of the heap
//        public void print()
//        {
//            for (int i = 1; i <= size / 2; i++) {
//                System.out.print(" PARENT : " + Heap[i]
//                        + " LEFT CHILD : " + Heap[2 * i]
//                        + " RIGHT CHILD :" + Heap[2 * i + 1]);
//                System.out.println();
//            }
//        }

        // Function to build the min heap using
        // the minHeapify
//        public void minHeap()
//        {
//            for (int pos = (size / 2); pos >= 1; pos--) {
//                minHeapify(pos);
//            }
//        }

        // Function to remove and return the minimum
        // element from the heap
        public double remove()
        {
//            double popped = Heap[FRONT];
//            Heap[FRONT] = Heap[size--];
//            minHeapify(FRONT);
            double popped = Heap.peek();
            Heap.poll();
            return popped;
        }
  /*      public void delete(double time)
        {
            double popped = Heap[FRONT];
            Heap[FRONT] = Heap[size--];
            minHeapify(FRONT);
            for(int i=0;i<=size;i++)
            {
                if(Population.get(i).getDeathTime() == time && time == Heap[FRONT]) {
                    Population.remove(Population.get(i));
                    break;
                }
            }
        }
*/
        public Event deleteMin()
        {
            double popped = Heap.poll();
//            Heap[FRONT] = Heap[size--];
//            minHeapify(FRONT);
            for(int i=0;i< eQueue.size();i++) {
                //System.out.println("EQUEUE GET ="+eQueue.get(i).time +"\t POPPED : "+popped);
                if (eQueue.get(i).time == popped)
                    {
                        temp = eQueue.get(i);
                        eQueue.remove(i);
                        return temp;
                    }

            }
            return null;
            //return eventQ.popped;
        }

        public boolean isEmpty()
        {
            if(eQueue.size() == 0)
            {
                return true;
            }
            return false;
        }
}
