// Time Complexity O(logn)

// Two heaps (or priority queues):
// 1.Max-heap small has the smaller half of the numbers.
// 2.Min-heap large has the larger half of the numbers.

// This gives me direct access to the one or two middle values (they're the tops of the heaps), 
// so getting the median takes O(1) time. And adding a number takes O(log n) time.

