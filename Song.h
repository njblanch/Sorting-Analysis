//
// Created by Nathan Blanchard on 1/25/23.
//

#ifndef PROJECT1_SONG_H
#define PROJECT1_SONG_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using std::endl, std::ifstream, std::left, std::ostream, std::right, std::setw, std::string, std::vector;

class Song {
private:
    int index;
    string title;
    string genre;
    int bpm;
    int danceability;
    int length;


public:
    // Constructors
    Song() {
    }

    Song(int index,
             string title,
             string genre,
             int bpm,
             int danceability,
             int length) {
        this->index = index;
        this->title = title;
        this->genre = genre;
        this->bpm = bpm;
        this->danceability = danceability;
        this->length = length;
    }

    // Getters
    int getIndex() const {
        return index;
    }

    string getTitle() const {
        return title;
    }

    string getGenre() const {
        return genre;
    }

    int getBpm() const {
        return bpm;
    }

    int getDanceability() const {
        return danceability;
    }

    int getLength() const {
        return length;
    }

    // Setters
    void setIndex(int index) {
        this->index = index;
    }

    void setTitle(string title) {
        this->title = title;
    }

    void setGenre(string genre) {
        this->genre = genre;
    }

    void setBpm(int bpm) {
        this->bpm = bpm;
    }

    void setDanceability(int danceability) {
        this->danceability = danceability;
    }

    void setLength(int length) {
        this->length = length;
    }

    // Overloaded Operators
    friend ostream& operator << (ostream& outs, const Song& s) {
        outs << left << setw(5) << s.getIndex();
        outs << "Title: " << s.getTitle() << endl;
        outs << "     Genre: " << setw(15) << s.getGenre() << endl;
        outs << "     Bpm / Danceability / Length:" << right << setw(5) << s.getBpm();
        outs << right << setw(5) << s.getDanceability();
        outs << right << setw(5) << s.getLength();
        return outs;
    }
    friend bool operator == (const Song& s1, const Song & s2) {
        // Compare song index to see if they are the same song
        return s1.index == s2.index;
    }
    friend bool operator < (const Song& s1, const Song & s2) {
        // Compare song index to see if index for song 1 is less than index for song 2
        return s1.index < s2.index;
    }
    friend bool operator > (const Song& s1, const Song & s2) {
        // Compare song index to see if index for song 1 is greater than index for song 2
        return s1.index > s2.index;
    }
    friend bool operator <= (const Song& s1, const Song & s2) {
        // Compare song index to see if index for song 1 is less than or equal to index for song 2
        return s1.index <= s2.index;
    }
    friend bool operator >= (const Song& s1, const Song & s2) {
        // Compare song index to see if index for song 1 is greater than or equal to index for song 2
        return s1.index >= s2.index;
    }
};

// Function getDataFromFile extracts information from the
// given csv file and adds Song objects to vector songs
void getDataFromFile(string filename, vector<Song> &songs) {
    // Create a file handler object and open file
    ifstream inFile;
    inFile.open(filename);

    string header;
    //Check if the file can be read from
    if (inFile) {
        // Remove header from file before reading in data
        getline(inFile, header);
    }

    // Declare variables to be read in
    string title = "", genre = "", junk;
    int index = -1, bpm = -1, danceability = -1, length = -1;
    char comma, quote;

    // While the file is still in a good state to be read from
    // and we're not at the end of the file yet
    while (inFile && inFile.peek() != EOF) {
        // Index
        inFile >> index >> comma;

        // Title
        if (inFile.peek() == '"') {
            inFile >> quote;
            getline(inFile, title, '"');
            inFile >> comma;
        } else {
            getline(inFile, title, ',');
        }

        // Junk
        if (inFile.peek() == '"') {
            inFile >> quote;
            getline(inFile, junk, '"');
            inFile >> comma;
        } else {
            getline(inFile, junk, ',');
        }

        // Genre
        getline(inFile, genre, ',');

        // Junk
        getline(inFile, junk, ',');

        // BPM
        inFile >> bpm >> comma;

        // Junk
        getline(inFile, junk, ',');

        // Danceability
        inFile >> danceability >> comma;

        // Junk
        getline(inFile, junk, ',');
        getline(inFile, junk, ',');
        getline(inFile, junk, ',');

        // Length
        inFile >> length;

        // Junk
        getline(inFile, junk);

        // Create a Song object and add it to the vector
        songs.push_back(Song(index, title, genre, bpm, danceability, length));
    }
    // Close the file
    inFile.close();
}

// Function getAvgBpm calculates the average beats per
// minute across all songs in a specified genre
double getAvgBpm(vector<Song>& songs, string genre) {
    int num = 0;
    int sum = 0;
    // Loop through all songs to find songs of specified genre
    // add bpm to sum and increment num for calculation of average
    for(int i; i < songs.size(); ++i) {
        if (songs[i].getGenre() == genre) {
            sum += songs[i].getBpm();
            ++num;
        }
    }
    // Calculate and return average
    return (double) sum / num;
}

#endif //PROJECT1_SONG_H