import java.util.Iterator;
import java.util.List;
import java.util.Deque;


public class FlattenNestedIterator implements Iterator<Integer> {
  Deque<NestedInteger> stack = new ArrayDeque<>();
  public FlattenNestedIterator(List<NestedInteger> nestedList) {
    prepareStack(nestedList);
  }
}