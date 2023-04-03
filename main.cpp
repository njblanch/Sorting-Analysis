#include "bubbleSort.h"
#include "heapSort.h"
#include "insertionSort.h"
#include "mergeSort.h"
#include "quickSort.h"
#include "selectionSort.h"
#include "Song.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    // Variables
    const int MIN_SIZE = 100;
    const int MAX_SIZE = 1000;
    const int SIZE_DIFFERENCE = 100;
    int reads;
    int writes;

    // Create Song vector
    vector<Song> songVector;
    // Get data from csv file
    getDataFromFile("../Spotify-2000.csv", songVector);

    // Open output file
    ofstream outfile;
    outfile.open("../algorithm-results.csv");
    outfile << "Size,Bubble Sort Reads,Bubble Sort Writes,Bubble Sort Time,"
               "Heap Sort Reads,Heap Sort Writes,Heap Sort Time,"
               "Insertion Sort Reads,Insertion Sort Writes,Insertion Sort Time,"
               "Merge Sort Reads,Merge Sort Writes,Merge Sort Time,"
               "Quick Sort Reads,Quick Sort Writes,Quick Sort Time,"
               "Selection Sort Reads,Selection Sort Writes,Selection Sort Time,"
               "Two-Sort Reads,Two-Sort Writes,Two-Sort Time" << endl;

    // Perform sorting algorithms on various sizes of Song vector
    for(int i = MAX_SIZE; i >= MIN_SIZE; i -= SIZE_DIFFERENCE) {
        // Resize vector
        songVector.resize(i);
        outfile << i << ",";

        // Reset values for reads and writes to zero
        reads = 0;
        writes = 0;
        // Bubble sort
        auto t1 = high_resolution_clock::now();
        bubbleSort(songVector, reads, writes);
        auto t2 = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(t2 - t1);
        // Output results to file
        outfile << reads  << "," << writes  << "," << duration.count() << ",";

        // Reset values for reads and writes to zero
        reads = 0;
        writes = 0;
        // Heap sort
        t1 = high_resolution_clock::now();
        heapSort(songVector, reads, writes);
        t2 = high_resolution_clock::now();
        duration = duration_cast<microseconds>(t2 - t1);
        // Output results to file
        outfile << reads  << "," << writes  << "," << duration.count() << ",";

        // Reset values for reads and writes to zero
        reads = 0;
        writes = 0;
        // Insertion sort
        t1 = high_resolution_clock::now();
        insertionSort(songVector, reads, writes);
        t2 = high_resolution_clock::now();
        duration = duration_cast<microseconds>(t2 - t1);
        // Output results to file
        outfile << reads  << "," << writes  << "," << duration.count() << ",";

        // Reset values for reads and writes to zero
        reads = 0;
        writes = 0;
        // Merge sort
        t1 = high_resolution_clock::now();
        mergeSort(songVector, reads, writes);
        t2 = high_resolution_clock::now();
        duration = duration_cast<microseconds>(t2 - t1);
        // Output results to file
        outfile << reads  << "," << writes  << "," << duration.count() << ",";

        // Reset values for reads and writes to zero
        reads = 0;
        writes = 0;
        // Quick sort (stable)
        t1 = high_resolution_clock::now();
        quickSortStable(songVector, reads, writes);
        t2 = high_resolution_clock::now();
        duration = duration_cast<microseconds>(t2 - t1);
        // Output results to file
        outfile << reads  << "," << writes  << "," << duration.count() << ",";

        // Reset values for reads and writes to zero
        reads = 0;
        writes = 0;
        // Selection sort
        t1 = high_resolution_clock::now();
        selectionSort(songVector, reads, writes);
        t2 = high_resolution_clock::now();
        duration = duration_cast<microseconds>(t2 - t1);
        // Output results to file
        outfile << reads  << "," << writes  << "," << duration.count() << ",";

        // Reset values for reads and writes to zero
        reads = 0;
        writes = 0;
        // Two-sort
        // Create copy of vector (found at https://www.techiedelight.com/copy-vector-cpp/)
        vector<Song> temp(songVector);
        t1 = high_resolution_clock::now();
        // First sort using heap sort
        heapSortReference(temp, reads, writes);
        // Pass sorted vector into insertion sort to sort by index
        insertionSortIndex(temp, reads, writes);
        t2 = high_resolution_clock::now();
        duration = duration_cast<microseconds>(t2 - t1);
        // Output results to file
        outfile << reads  << "," << writes  << "," << duration.count() << endl;
    }
    outfile.close();

    return 0;
}