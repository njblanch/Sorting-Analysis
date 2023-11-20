# Sorting Algorithm Analysis

This is a project from the class `Data Structures and Algorithms` at UVM. Starting code for `bubbleSort.h`, `heapSort.h`, `insertionSort.h`, `mergeSort.h`, `quickSort.h`, `radixSort.h`, and `selectionSort.h` was provided by the professor, and this code was modified to record the number of reads/writes.

For this project, you will sort the 1000 objects from your data set. You will modify each sorting algorithm to collect data. You will analyze the results from the different sorting algorithms.

## Implement
You should have your 1000+ objects stored in a vector, initially unsorted.
Use these five sorting algorithms:
1. Bubble Sort
2. Choose either Selection Sort or Insertion Sort
3. Choose either Merge Sort or Quick Sort
4. Heap Sort
5. Two-sort: sort by any algorithm (except Bubble Sort), then sort on a different field using a stable sorting algorithm (again, except Bubble Sort).
   * Hint for implementing two-sort: for the second stable algorithm, make a copy of the stable sorting function and take out the template part. That way you will be able to call a getter on your custom-type objects to compare a second field of your class.

Modify each sorting algorithm to record the number of reads. This is the number of times you use a Comparable object. This could be using it to store somewhere else, using it to compare to another object, etc. Temporary Comparable objects count towards the reads. 
* Example code:
  ```cpp
  if (vec[i] > vec[i+1]) // This counts as two reads, which should
      // be counted whether the if statements evaluates to true or false.
  Comparable temp = vec[i]; // This is one read.
  smaller.push_back(vec[i]); // This is one read.
  ```
Modify each sorting algorithm to record the number of writes. This is the number of times you assign into a Comparable object. This could be to store a temporary Comparable, to overwrite an item in a Comparable vector, to push_back onto a Comparable vector, etc.
* Example code:
  ```cpp
  Comparable temp = vec[i]; // This is one write (and one read).
  smaller.push_back(vec[i]); // This is one write (and one read).
  vec[i] = vec[i+1]; // This is one write (and one read).
  ```
Use a loop to record the number of reads and writes needed to sort a vector of size 100, 200, 300, 400, 500, 600, 700, 800, 900, and 1000.
* Hint: start with 1000 and then use the resize method to make it smaller. 

Each of the five sorting algorithms should be given identical unsorted vectors to begin with. 
* If your data is naturally sorted by the attribute you use to overload your operators, change how you overload your operators.

## Extra Credit
* Setting timers to record how long it takes you to sort the objects with each algorithm.\
  I completed this section of the extra credit. I felt as if it made the most sense to include the results from this in the `Analyze the data` section of the report, so the results can be found there.
* Performing the same experiment, except double the size of the data set each time (instead of having it grow linearly).
* Using more sorting algorithms.\
  I completed this section of the extra credit. This has also been included in the `Analyze the data` section of the report.

Note that if you add this logic to your code but do not analyze it in your report, it will not count towards extra credit. If you complete extra credit, analyze it in this section of your README.md file.

## Report
Include the following in this section of your README.md file:
* Information about your data set.\
  This dataset is titled [Spotify - All Time Top 2000s Mega Dataset](https://www.kaggle.com/datasets/iamsumat/spotify-top-2000s-mega-dataset?resource=download&select=Spotify-2000.csv) and contains information on 1994 unique tracks on spotify that was obtained using Spotify's API. This dataset can be found on the website Kaggle. I chose this data set because I found it very interesting that an algorithm could be used to give songs "scores" in areas such as danceability.
* Analyze the data. Graph the number of reads and writes for each sorting algorithm and look at how the number of reads and writes grows when the size of the data set grows. Compare and contrast the different sorting algorithms and draw conclusions about which sorting algorithms are more efficient. Discuss complexities and their effects.\
  I decided to have these sorting algorithms sort the data based on song duration. The two-sort algorithm I used first sorted the data by song duration and then by song index. The following graphs display the number of reads, the number of writes, and the amount of time for each of the sorting algorithms:
  ![Reads vs Vector Size](graphs/graph-reads.png)
  ![Writes vs Vector Size](graphs/graph-writes.png)
* ![Time vs Vector Size](graphs/graph-time.png)
  * `Bubble Sort`: It is evident from the included graphs that, for these data, bubble sort is the least efficient of the algorithms used. In terms of reads and writes, bubble sort had the greatest number for each when compared to the other sorting algorithms. As the size of the vector increased, the number of reads and writes increased by greater amounts for each additional 100 items added to the vector. Bubble sort also took the longest out of any algorithm used, and it has a time complexity of O(n^2). The graph of the time that it took shows a similar pattern to the read and write graphs, with the amount of time increasing by greater amounts for each additional 100 items added to the vector. A couple redeeming qualities of bubble sort, however, are that it has a constant auxiliary complexity and it is stable.
  * `Heap Sort`: Heap sort is a non-stable sorting algorithm with time complexity O(n log n) and auxiliary complexity O(1). When we look at the graphs, it can be seen that heap sort was approximately middle of the pack for reads, writes, and time. The number of reads and writes both followed a similar trend to that of bubble, with the number of reads and writes increased by greater amounts each additional 100 items added to the vector. This increase as by a smaller amount, however. The amount of time that this sorting algorithm took to run was significantly less than bubble sort and two-sort, but it took much longer than selection sort, another non-stable sorting algorithm that interestingly has a greater time complexity of O(n^2).
  * `Insertion Sort`: Insertion sort is a stable sorting algorithm with time complexity O(n^2) and auxiliary complexity O(1). Interestingly, this sorting algorithm had fewer reads, fewer writes, and took less time to run than heap sort. This is especially interesting because insertion sort is stable while heap sort is unstable, and insertion sort has a greater time complexity than heap sort. When we look at the graphs for reads and writes, we find that the number of reads is very similar to the number of writes, and this is a trend that is followed for all vector sizes. These graphs are also a lot flatter than those of bubble sort and two sort.
  * `Merge Sort`: Merge sort is a stable sorting algorithm with time complexity O(n log n) and auxiliary complexity O(n). When we look at the number of reads, writes, and the amount of time it takes to run this sorting algorithm, merge sort seems like an exceptional choice for a sorting algorithm. For reads, writes, and time, this algorithm consistently has amongst the lowest values when compared to the other sorting algorithms. Even as the number of items in the dataset increases, the number of reads, the number of writes, and the time changes by very little. This, however, does not come without drawbacks. With an auxiliary complexity of O(n), running this algorithm takes up more space than sorting algorithms such as heap, bubble, selection, etc. which have auxiliary complexity O(1), so it is important to consider this when using this sorting algorithm.
  * `Stable Quick Sort`: Stable quick sort is a stable sorting algorithm with time complexity between O(n log n) and O(n^2) and auxiliary complexity between O(n log n) and O(n^2). This sorting algorithm performed surprisingly similarly to merge sort. For reads, writes, and time, this algorithm also consistently results in low values when compared to the other sorting algorithms, and these values also do not change by very much as the number of items to sort increase. Like merge, though, it has the drawback of taking up more space. With an auxiliary complexity of O(n log n) - O(n^2), this sorting algorithm would not be a good choice if space was a concern.
  * `Selection Sort`: Selection sort is an unstable sorting algorithm with time complexity O(n^2) and auxiliary complexity O(1). Looking at the graphs for the reads and writes for this algorithm, we see that there are significantly more reads than writes. The only sorting algorithms with more reads are bubble and two sort, and we see that selection sort consistently has the fewest number of writes for all vector sizes. Looking at the data, we also see that the number of writes increases linearly. As for the time that this algorithm takes, it is even faster than quick sort and heap sort when there are fewer values, though due to the time complexity of O(n^2) it becomes slower than these algorithms as more items are added to the vector. This means that this sorting algorithm could be good for smaller datasets, though it does have the drawback of being unstable.
  * `Two-Sort`: For the two-sort algorithm, I first sorted the data by song duration using heap sort and then sorted the data by song index using insertion sort. As expected, we can somewhat accurately predict the number of reads, the number of writes, and the amount of time that this algorithm takes to run by adding the values from heap and insertion sort. Because of this, two-sort took longer to run than all other sorting algorithms we used except for bubble sort. Because this sorting algorithm was heap sort, with time complexity of O(n log n) and auxiliary complexity of O(1), and insertion sort, with time complexity of O(n^2) and auxiliary complexity of O(1), this algorithm had an overall time complexity of O(n^2) and auxiliary complexity of O(1).
* Answers to the following questions: 
  * If you need to sort a contacts list on a mobile app, which sorting algorithm(s) would you use and why? 
    * For sorting a contacts list on a mobile app, you would need to use a two-sort algorithm. The first part of this algorithm would need to sort by some attribute like phone number (to distinguish between two people if they have the same name), and the second sorting algorithm would need to be stable and sort by name. Because this list of contacts would likely not be very large, this algorithm should prioritize stability and speed. For this, I would recommend first sorting using selection sort. This algorithm is an unstable algorithm that is fast for smaller dataset sizes. For the next sort, I would recommend using either merge sort or stable quick sort (if space was not an issue).
  * What about if you need to sort a database of 20 million client files that are stored in a datacenter in the cloud?
    * For sorting a database of 20 million client fields that are stored in a datacenter in the cloud, it would be important to use a sorting algorithm that prioritizes speed and little memory usage. I would recommend using an unstable quick sort algorithm. This has a time complexity between O(n log n) and O(n^2) and an auxiliary complexity of O(1), and it would have fewer reads and writes than most other sorting algorithms we have studied. Another possible sorting algorithm, and a good choice for a sorting algorithm if stability is indeed a requirement for sorting this, would be insertion sort. This is slower than quick sort, but it also maintains an auxiliary complexity of O(1) and is stable.

**Note: Any code that was not authored by yourself or the instructor must be cited in your report. This includes the use of concepts not taught in lecture.**
* Measure execution time of a function in C++. GeeksforGeeks. (2022, February 14). Retrieved April 3, 2023, from https://www.geeksforgeeks.org/measure-execution-time-function-cpp/
* Copy a vector in C++. Techie Delight. (2021, April 29). Retrieved April 3, 2023, from https://www.techiedelight.com/copy-vector-cpp/
