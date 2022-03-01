package Heap;

public class MinHeap {
  // Create and complete binary tree using an arry
  // then use binary tree to construct a heap
  int[] minHeap;
  // number of elements needed when instantiating an array
  int heapSize;
  // number of elements in the heap
  int realSize = 0;

  public MinHeap(int heapSize)
  {
    this.heapSize = heapSize;
    minHeap = new int[heapSize + 1];
    //not tracking 0th element of array
    minHeap[0] = 0;
  }

  // add element
  public void add(int element)
  {
    realSize++;
    // if the number of elements in the Heap exceeds heapSize
    if (realSize > heapSize)
    {
      System.out.println("Added too many elements!");
      realSize--;
      return;
    }
    // Add the element into the array
    minHeap[realSize] = element;
    //Index of the newly added element
    int index = realSize;
    // Parent node of the newly added element
    // Note: If we use an array to represent the complete
    // binary tree and store the root note at index 1
    // index of the parent node of any node is [index of the node / 2]
    int parent = index / 2;
    // index of the left child node is [index of the node * 2]
    // index of the right child node is [index of the node * 2 + 1]
    while (minHeap[index] < minHeap[parent] && index > 1)
    {
      int temp = minHeap[index];
      minHeap[index] = minHeap[parent];
      minHeap[parent] = temp;
      index = parent;
      parent = index / 2;
    }
  }

  // Get the top element of the Heap
  public int peek()
  {
    return minHeap[1];
  }

  // Delete the top element of the Heap
  public int pop()
  {
    // if the number of elements in the current Heap is 0;
    // print "Don't have any elements" and return the default value.
    if (realSize < 1)
    {
      System.out.println("Don't have any element!");
      return Integer.MAX_VALUE;
     } else {
       // When there are still elements in the Heap
       // realSize >= 1
       int removeElement = minHeap[1];
       // Put the last element in the Heap to the top of the heap
       minHeap[1] = minHeap[realSize];
       realSize--;
       int index = 1;
       // When the deleted element is not a leaf node
       while (index <= realSize / 2)
       {
        // left child of deleted element
        int left = index * 2;
        int right = index * 2 + 1;
        // if the deleted element is larger than the left or right child
        // its value needs to be exchanged with the smaller value
        if (minHeap[index] > minHeap[left] || minHeap[index] > minHeap[right])
        {
          if (minHeap[left] < minHeap[right])
          {
            int temp = minHeap[left];
            minHeap[index] = minHeap[left];
            minHeap[index] = temp;
            index = left;
          } else {
            int temp = minHeap[right];
            minHeap[index] = minHeap[right];
            minHeap[index] = temp;
            index = right;
          }
        } else {
          break;
        }
       }
       return removeElement;
     }  
  }

  public int size() {
    return realSize;
  }

  public String toString() {
    if (realSize == 0) {
        return "No element!";
    } else {
        StringBuilder sb = new StringBuilder();
        sb.append('[');
        for (int i = 1; i <= realSize; i++) {
            sb.append(minHeap[i]);
            sb.append(',');
        }
        sb.deleteCharAt(sb.length() - 1);
        sb.append(']');
        return sb.toString();
    }
  } 
  public static void main(String[] args) {
    // Test case
    MinHeap minHeap = new MinHeap(3);
    minHeap.add(3);
    minHeap.add(1);
    minHeap.add(2);
    // [1,3,2]
    System.out.println(minHeap.toString());
    // 1
    System.out.println(minHeap.peek());
    // 1
    System.out.println(minHeap.pop());
    // [2, 3]
    System.out.println(minHeap.toString());
    minHeap.add(4);
    // Add too many elements
    minHeap.add(5);
    // [2,3,4]
    System.out.println(minHeap.toString());
}
}
