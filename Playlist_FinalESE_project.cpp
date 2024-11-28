#include <iostream>
#include <string>
using namespace std;

struct Song {
    string name;
    Song* next;
};

Song* last = nullptr; 


void addSong(const string& songName) {
    Song* newSong = new Song{songName, nullptr};
    if (!last) { 
        newSong->next = newSong;
        last = newSong;
    } else { 
        newSong->next = last->next;
        last->next = newSong;
        last = newSong;
    }
    cout << "Added song: " << songName << endl;
}


void playNext() {
    if (!last) {
        cout << "Playlist is empty!" << endl;
        return;
    }
    last = last->next;
    cout << "Playing: " << last->next->name << endl;
}


void playPrevious() {
    if (!last) {
        cout << "Playlist is empty!" << endl;
        return;
    }
    Song* temp = last->next;
    while (temp->next != last) {
        temp = temp->next;
    }
    last = temp;
    cout << "Playing: " << last->name << endl;
}

void deleteSong(const string& songName) {
    if (!last) {
        cout << "Playlist is empty!" << endl;
        return;
    }

    Song* current = last->next;
    Song* prev = last;

    do {
        if (current->name == songName) {
            if (current == last && current->next == last) { 
                last = nullptr;
            } else if (current == last) {
                prev->next = current->next;
                last = prev;
            } else {
                prev->next = current->next;
            }
            delete current;
            cout << "Deleted song: " << songName << endl;
            return;
        }
        prev = current;
        current = current->next;
    } while (current != last->next);

    cout << "Song not found: " << songName << endl;
}


void displaySongs() {
    if (!last) {
        cout << "Playlist is empty!" << endl;
        return;
    }

    Song* temp = last->next;
    cout << "Songs in the playlist:" << endl;
    do {
        cout << "- " << temp->name << endl;
        temp = temp->next;
    } while (temp != last->next);
}

void clearPlaylist() {
    if (!last) return;

    Song* current = last->next;
    Song* temp;
    while (current != last) {
        temp = current;
        current = current->next;
        delete temp;
    }
    delete last;
    last = nullptr;
}

int main() {
    addSong("DayLight");
    addSong("Golden Hour");
    addSong("Safarnama");

    displaySongs();

    playNext();
    playPrevious();

    deleteSong("Golden Hour");
    displaySongs();

    clearPlaylist();
    return 0;
}
